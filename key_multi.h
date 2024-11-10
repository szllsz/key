#ifndef __KEY_MULTI_H__
#define __KEY_MULTI_H__

#include <REGX52.H>

sbit KEY1 = P3^1; 			//����IO								//�������޸Ĵ˴�����������/���ٰ�������
sbit KEY2 = P3^0;													//�������޸Ĵ˴�����������/���ٰ�������
sbit KEY3 = P3^2;													//�������޸Ĵ˴�����������/���ٰ�������
sbit KEY4 = P3^3;													//�������޸Ĵ˴�����������/���ٰ�������

#define KEY_STATE_0 0 										//����״̬
#define KEY_STATE_1 1
#define KEY_STATE_2 2
#define KEY_STATE_3 3
#define KEY_STATE_4 4

#define LONG_KEY_TIME 80 									//�ж�����ʱ�䣺LONG_KEY_TIME*10MS = 800MS
#define SINGLE_KEY_TIME 1 								//�ж�����ʱ�䣺SINGLE_KEY_TIME*10MS = 10MS
#define DOUBLE_KEY_TIME 50 								//�ж�����ʱ�䣺DOUBLE_KEY_TIME*10MS = 500MS

#define None_click 0 											//�ް���  	����ֵ��0
#define Single_click 1 										//����		����ֵ��1	
#define Double_click 2										//˫��		����ֵ��2
#define Long_click 3 											//����		����ֵ��3

#define uchar unsigned char
#define uint unsigned int	
	
#define Key1_Single_Click 11							//�������޸Ĵ˴�����������/���ٰ�������
#define Key1_Double_Click 12							//�������޸Ĵ˴�����������/���ٰ�������
#define Key1_Long_Click 13								//�������޸Ĵ˴�����������/���ٰ�������

#define Key2_Single_Click 21							//�������޸Ĵ˴�����������/���ٰ�������
#define Key2_Double_Click 22							//�������޸Ĵ˴�����������/���ٰ�������
#define Key2_Long_Click 23								//�������޸Ĵ˴�����������/���ٰ�������

#define Key3_Single_Click 31							//�������޸Ĵ˴�����������/���ٰ�������
#define Key3_Double_Click 32							//�������޸Ĵ˴�����������/���ٰ�������
#define Key3_Long_Click 33								//�������޸Ĵ˴�����������/���ٰ�������

#define Key4_Single_Click 41							//�������޸Ĵ˴�����������/���ٰ�������
#define Key4_Double_Click 42							//�������޸Ĵ˴�����������/���ٰ�������
#define Key4_Long_Click 43								//�������޸Ĵ˴�����������/���ٰ�������

unsigned char key_multi(void);						//�๦�ܰ���ɨ�躯�������� ��ֵ+������ ����ֵ
unsigned char keyscan();									//��ͨ����ɨ�躯�������� ��ֵ
#endif