#include <key_multi.h>

unsigned char keyscan()
{
	unsigned char keynumber;
	if(!KEY1) keynumber = 1;								//�������޸Ĵ˴�����������/���ٰ�������
	else if(!KEY2) keynumber = 2;							//�������޸Ĵ˴�����������/���ٰ�������
	else if(!KEY3) keynumber = 3;							//�������޸Ĵ˴�����������/���ٰ�������
	else if(!KEY4) keynumber = 4;							//�������޸Ĵ˴�����������/���ٰ�������
	else keynumber = 0;
	return keynumber;
}

unsigned char key_multi(void)
{
	static uchar key_state; 									//����״̬����
	static uint key_time; 										//������ʱ����
	static uchar key_press_nums;							//������������		
	static uint key_time_double;							//����˫��ʱ��
	static uchar keynum;											//��ֵ
	static uchar new_keynum;									//�µļ�ֵ
	uchar key_press, key_return;							//��ֵ�ͷ���ֵ
	
	key_return = 0; 									//������ذ���ֵ
	
	switch(keyscan())
	{
		case 1:key_press = KEY1;new_keynum = 1;break;		
		case 2:key_press = KEY2;new_keynum = 2;break;		
		case 3:key_press = KEY3;new_keynum = 3;break;		
		case 4:key_press = KEY4;new_keynum = 4;break;		
		default:key_press = 1;break;
	}
	if(key_press_nums > 0) 										//������������0��˵���а���
	{
		key_time_double++;											//˫����ʱ
		if(key_time_double >= DOUBLE_KEY_TIME && key_time_double < LONG_KEY_TIME) key_state = KEY_STATE_2;//�ڳ���ʱ���˫��ʱ���趨��Χ�ڣ���״̬2
	}
	
	switch (key_state)
	{
		case KEY_STATE_0: 											//����״̬0���ж����ް�������
		{
			if (!key_press) 											//�а�������
			{
				key_time = 0; 											//����ʱ��������
				key_state = KEY_STATE_1; 						//Ȼ����� ����״̬1
			}
		}break;
		case KEY_STATE_1: 											//����״̬1���������(ȷ�������Ƿ���Ч����������)��������Ч�Ķ��壺�����������³����趨������ʱ�䡣
		{
			if (!key_press)
			{
				key_time++; 												//һ��10ms
				if(key_time>=SINGLE_KEY_TIME) 			//����ʱ��Ϊ��SINGLE_KEY_TIME*10ms = 10ms;
				{
					key_state = KEY_STATE_2; 					//�������ʱ�䳬�� ����ʱ�䣬���ж�Ϊ���µİ�����Ч�����밴��״̬2�������ж������ǵ�����˫�����ǳ���
					key_press_nums++;									//��������+1
				}
			}
			else key_state = KEY_STATE_0; 				//�������ʱ��û�г������ж�Ϊ�󴥣�������Ч������ ����״̬0�������ȴ�����
		}break;
		case KEY_STATE_2: 											//����״̬2���ж�������Ч�����ࣺ�ǵ�����˫�������ǳ���
		{
			if(key_press) 												//��������� �趨��˫��ʱ�����ͷţ����ж�Ϊ����/˫��
			{
				if(key_time_double < 50 ) key_state = KEY_STATE_0;							//˫��ʱ��ﵽǰ���ٴ�ɨ�谴��
				if(key_time_double >= 50 && key_time_double < 80) 	//�ﵽ˫���趨ʱ���
				{
					if(key_press_nums == 1) 
						key_return = Single_click + new_keynum*10; 				//������Ч����ֵ������
					else if(key_press_nums ==2 && new_keynum == keynum) 
						key_return = Double_click + new_keynum*10; 	//������Ч����ֵ��˫��
					key_state = KEY_STATE_0; 					//���� ����״̬0�������ȴ�����
					key_press_nums = 0;								//��հ�������
					key_time_double = 0;							//���˫����ʱ
				}
			}
			else
			{	
				key_time++;													//����һֱ���ŵĻ���������ʱ
				if(key_time >= LONG_KEY_TIME) 			//�������ʱ�䳬�� �趨�ĳ���ʱ��(LONG_KEY_TIME*10ms=80*10ms=800ms), ���ж�Ϊ ����
				{
					key_return = Long_click + new_keynum*10; 	//������Ч��ֵֵ������
					key_state = KEY_STATE_3; 					//ȥ״̬3���ȴ������ͷ�
				}
			}
		}break;
		case KEY_STATE_3: 											//�ȴ������ͷ�
		{
			if (key_press)
			{
				key_state = KEY_STATE_0; 						//�����ͷź󣬽��� ����״̬0 ��������һ�ΰ������ж�
				key_press_nums = 0;									//��հ�������
				key_time_double = 0;								//���˫����ʱ
			}
		}break;
		default:key_state = KEY_STATE_0;break;	//���������key_state������ֵ�����������key_state���������һ������� û�г�ʼ��key_state����һ��ִ�����������ʱ��
	}
	keynum = new_keynum;											//���»�ȡ�ļ�ֵ��ֵ����ֵ
	return key_return; 												//���� ����ֵ
}