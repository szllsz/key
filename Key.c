#include <REGX52.H>

sbit key = P3^1;

unsigned char flag, High, Low;

void Key()
{
	if(key == 0 && flag == 0)															
	{
		High++;
		if(High >= 1)				//���¼��>=10ms
		{
			High = 0;
			flag = 1;
		}
	}
	else if(key != 0 && flag == 1)
	{
		Low++;
		if(Low >= 1)				//�ɿ����>=10ms
		{
			//ִ�г��򲿷�
			
			flag = 0;
		}
	}
}