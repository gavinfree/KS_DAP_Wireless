#ifndef __MALLOC_H
#define __MALLOC_H
#include "stm32f1xx_hal.h"

//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
//ALIENTEK��ӢSTM32F103������V1
//�ڴ���� ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2015/1/20
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) �������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////
 
 
#ifndef NULL
#define NULL 0
#endif

//���������ڴ��
#define SRAMIN	 0		//�ڲ��ڴ��

#define SRAMBANK 	1	//����֧�ֵ�SRAM����. ��Ӣ��ʵ����ֻ֧��1���ڴ�����,���ڲ��ڴ�.	


//mem1�ڴ�����趨.mem1��ȫ�����ڲ�SRAM����.
#define MEM1_BLOCK_SIZE			32  	  						//�ڴ���СΪ32�ֽ�
#define MEM1_MAX_SIZE			5*1024  						//�������ڴ� 40K
#define MEM1_ALLOC_TABLE_SIZE	MEM1_MAX_SIZE/MEM1_BLOCK_SIZE 	//�ڴ����С

//�ڴ����������
struct _m_mallco_dev
{
	void (*init)(uint8_t);					//��ʼ��
	uint8_t (*perused)(uint8_t);		  	    	//�ڴ�ʹ����
	uint8_t 	*membase[SRAMBANK];				//�ڴ�� ����SRAMBANK��������ڴ�
	uint16_t *memmap[SRAMBANK]; 				//�ڴ����״̬��
	uint8_t  memrdy[SRAMBANK]; 				//�ڴ�����Ƿ����
};
extern struct _m_mallco_dev mallco_dev;	 //��mallco.c���涨��

void mymemset(void *s,uint8_t c,uint32_t count);	//�����ڴ�
void mymemcpy(void *des,void *src,uint32_t n);//�����ڴ�     
void my_mem_init(uint8_t memx);				//�ڴ������ʼ������(��/�ڲ�����)
uint32_t my_mem_malloc(uint8_t memx,uint32_t size);	//�ڴ����(�ڲ�����)
uint8_t my_mem_free(uint8_t memx,uint32_t offset);		//�ڴ��ͷ�(�ڲ�����)
uint8_t my_mem_perused(uint8_t memx);				//����ڴ�ʹ����(��/�ڲ�����) 
////////////////////////////////////////////////////////////////////////////////
//�û����ú���
void myfree(void *ptr);  			//�ڴ��ͷ�(�ⲿ����)
void *mymalloc(uint32_t size);			//�ڴ����(�ⲿ����)
void *myrealloc(uint8_t memx,void *ptr,uint32_t size);//���·����ڴ�(�ⲿ����)
#endif












