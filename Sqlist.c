/**
  ******************************************************************************
  * @file      Sqlist.c
  * @author    青椒san
  * @version   V1.0
  * @date      2017-1-16
  * @brief     线性表顺序存储结构操作的C语言实现
  *
  ******************************************************************************
  * @attention
  *  参照《大话数据结构》线性表章节
  *
  ******************************************************************************
  */
  
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
 
/* Private define ------------------------------------------------------------*/

/**
  * @brief 存储空间初始分配量
  */
#define  MAXSIZE 20     

#define  TRUE   1
#define  FALSE  0   
/* Private typedef -----------------------------------------------------------*/

/**
  * @brief 定义 Elem_TypeDef 的类型为int型
  */
typedef int Elem_TypeDef;

/**
  * @brief 定义线性表的结构体
  */
typedef struct{
	Elem_TypeDef data[MAXSIZE];
	int length;
}Sqlist_TypeDef;
/**
  * @brief 定义函数的返回值状态
  */
typedef enum{
	FUN_OK,
	FUN_ERROR
}FUN_Status_TypeDef;
/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/




/* Private function prototypes -----------------------------------------------*/


/* Private functions ---------------------------------------------------------*/

/**
  * @brief 	建立一个空的线性表
  * @param  sqlist:线性表指针        
  *            
  * @retval FUN_OK:成功
  *			FUN_ERROR：失败
  */
FUN_Status_TypeDef InitList(Sqlist_TypeDef *sqlist)
{
	int i;
	for (i=0;i<MAXSIZE;i++){
		sqlist->data[i] = 0x00;
	}
	sqlist->length = 0;
	return FUN_OK;
}

/**
  * @brief  判断线性表是否为空
  * @param  sqlist:线性表      
  *            
  * @retval TRUE:线性表为空
  *			FALSE：线性表为非空
  */
int ListEmpty(Sqlist_TypeDef sqlist)
{
	if ( sqlist.length == 0 ){
		return TRUE;
	}
	else if ( sqlist.length > 0 ){
		return FALSE;
	}
}

/**
  * @brief 	将线性表清空
  * @param  sqlist:线性表指针       
  *            
  * @retval FUN_OK:成功
  *			FUN_ERROR：失败
  */
FUN_Status_TypeDef CleanList(Sqlist_TypeDef *sqlist)
{
	free(sqlist);
	return FUN_OK;
}

/**
  * @brief  获取线性表的某个元素的值
  * @param  sqlist:线性表
  * @param  i:要获取的元素的位置
  * @param  e:获取的元素的值的指针        
  *            
  * @retval FUN_OK:成功
  *			FUN_ERROR：失败
  */
FUN_Status_TypeDef GetElem(Sqlist_TypeDef sqlist,int i,Elem_TypeDef *e)
{
	if ( sqlist.length==0 || i<1 || i>sqlist.length ){
		return FUN_ERROR;
	}
	*e = sqlist.data[i-1];
	return FUN_OK;
}


/**
  * @brief 	在线性表中查找给定值e的元素，并返回其序号
  * @param  sqlist:线性表指针       
  * @param  e:要查找的值       
  * @retval 查找成功： 返回序号
  *			查找失败： 返回 -1
  */
int LocateElem(Sqlist_TypeDef sqlist,Elem_TypeDef e)
{
	int i=0;
	for (i=0;i<sqlist.length;i++){
		if ( sqlist.data[i] == e ){
			return i;
		}
	}
	return -1;
}

/**
  * @brief 	线性表中插入新元素
  * @param  sqlist:线性表指针   
  * @param  i:插入的位置  
  * @param  e:新元素的值      
  * @retval FUN_OK:成功
  *			FUN_ERROR：失败
  */
FUN_Status_TypeDef ListInsert(Sqlist_TypeDef *sqlist,int i,Elem_TypeDef e)
{
	int j=0;
	if ( i>sqlist->length || i<0 || sqlist->length >= MAXSIZE ){
		return FUN_ERROR;
	}
	/* 插入位置为表尾 */
	else if ( i == sqlist->length ){
		sqlist->length++;
		sqlist->data[sqlist->length-1] = e;
	}
	/* 插入位置为表头或者其他位置 */
	else {
		sqlist->length++;
		for ( j=sqlist->length;j>i;j-- ){
			sqlist->data[j] = sqlist->data[j-1];
		}
		sqlist->data[i] = e;
	}
	return FUN_OK;
}

/**
  * @brief 	删除线性表中的元素
  * @param  sqlist:线性表指针   
  * @param  i:删除的元素的位置  
  * @param  e:被删除的元素的值    
  * @retval FUN_OK:成功
  *			FUN_ERROR：失败
  */
FUN_Status_TypeDef ListDelete(Sqlist_TypeDef *sqlist,int i,Elem_TypeDef *e){
	
	int j;
	if ( i<0 || i>sqlist->length ){
		return FUN_ERROR;
	}
	else {
		*e = sqlist->data[i-1];
		for ( j=i-1;j<sqlist->length;j++ ){
			sqlist->data[j] = sqlist->data[j+1];
		}
		sqlist->length--;
	}
	return FUN_OK;
}

/**
  * @brief 	获取线性表的元素个数
  * @param  sqlist:线性表   
  * @retval 线性表元素个数
  *			
  */
int ListLength(Sqlist_TypeDef sqlist){
	return sqlist.length;
}
	
/* Exported functions --------------------------------------------------------*/

int main(void)
{
	int i=0;
	Sqlist_TypeDef sqlist;
	Elem_TypeDef deletE=0;
	
	InitList(&sqlist);
	printf("%d\n",ListLength(sqlist));
	printf("%d\n",sqlist.data[5]);
	printf("%d\n",sqlist.data[9]);
	
	ListInsert(&sqlist,0,0);
	ListInsert(&sqlist,1,111);
	ListInsert(&sqlist,2,222);
	ListInsert(&sqlist,3,333);
	for (i=0;i<10;i++){
		printf("%d\n",sqlist.data[i]);
	}
	printf("\n\n\n");
	ListInsert(&sqlist,3,999);
	for (i=0;i<10;i++){
		printf("%d\n",sqlist.data[i]);
	}
	printf("%d\n",ListLength(sqlist));
	
}



/*****************************END OF FILE*******************************/
