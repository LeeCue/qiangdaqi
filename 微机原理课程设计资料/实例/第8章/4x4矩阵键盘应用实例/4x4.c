#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char
uchar code KEY_TABLE[]={ 0xee,0xde,0xbe,0x7e,
						 0xed,0xdd,0xbd,0x7d,
						 0xeb,0xdb,0xbb,0x7b,
						 0xe7,0xd7,0xb7,0x77};//���̱�
uchar code TABLE[]={0x3F,0x06,0x5B,0x4F,
			   		0x66,0x6D,0x7D,0x07,
			   		0x7F,0x6F,0x77,0x7c,
			   		0x39,0x5e,0x79,0x71};//����������ܱ����
void delayl()//����ʱ���������������
{uint n=50000;while(n--);}
void delays()//����ʱ����������
{uint n=10000;while(n--);}
main()
{
uchar temp,key,num,i;
	while(1)
	{
	P3=0xf0;//����Ϊ0����Ϊ1������ֵ��
		if(P3!=0xf0)//�ж��У��޼��̰���
		{delays();//����
			if(P3!=0xf0)//���if��ֵΪ�棬��ʱ����ȷ���м��̰���
			{
			temp=P3;//�洢�ж����ֵ
			P3=0x0f;//����Ϊ0����Ϊ1������ֵ��
			key=temp|P3;//���У���ֵ�ۺϣ�����key��
				for(i=0;i<16;i++)
				if(key==KEY_TABLE[i])//�����̱�ȷ������İ���ֵ
				{num=i;break;}
			P2=TABLE[num];//��������ܣ���ʾ����ֵ��
			delayl();
			}

		}

	}

}
