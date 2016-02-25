//
//  main.c
//  DeleteLinkedList
//
//  Created by chenyufeng on 16/2/25.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

/**
 *  删除链表中的某个节点
 （1）删除pos位置的节点；
 （2）判断x值是否在链表中，若存在则删除；
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elemType;
typedef struct ListNode{
    int element;
    struct ListNode *next;
}Node;

//初始化链表
void initList(Node *pNode){

    pNode = NULL;
    printf("%s函数执行，初始化链表成功\n",__FUNCTION__);
}

//打印链表
void printList(Node *pNode){

    if (pNode == NULL) {
        printf("%s函数执行，链表为空，打印失败\n",__FUNCTION__);
    }else{
        while (pNode != NULL) {
            printf("%d ",pNode->element);
            pNode = pNode->next;
        }
        printf("\n");
    }
}

//尾插法构建链表
Node *TailInsert(Node *pNode){

    Node *pInsert;
    Node *pMove;
    pInsert = (Node*)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->next = NULL;

    scanf("%d",&(pInsert->element));
    pMove = pNode;

    if (pInsert->element <= 0) {
        printf("%s函数执行，输入数据非法，建立链表停止\n",__FUNCTION__);
        return NULL;
    }

    while (pInsert->element > 0 ) {
        if (pNode == NULL) {
            pNode = pInsert;
            pMove = pNode;
        }else{

            while (pMove->next != NULL) {
                pMove = pMove->next;
            }
            pMove->next = pInsert;
        }
        pInsert = (Node*)malloc(sizeof(Node));
        memset(pInsert, 0, sizeof(Node));
        pInsert->next = NULL;
        scanf("%d",&(pInsert->element));
    }//while

    printf("%s函数执行，尾插法构建链表成功\n",__FUNCTION__);

    return pNode;
}

//获取链表长度
elemType sizeList(Node *pNode){

    int i = 0;
    if (pNode == NULL) {
        printf("%s函数执行，链表为空，长度为0\n",__FUNCTION__);
        return 0;
    }else{

        while (pNode != NULL) {
            i++;
            pNode = pNode->next;
        }
        printf("%s函数执行，链表长度为%d\n",__FUNCTION__,i);
        return i;
    }
}

//删除pos位置的节点,删除成功返回1，失败返回0
elemType deletePosElement(Node *pNode,int pos){

    Node *pMove;
    int i = 1;
    if (pos <= 0 || pos > sizeList(pNode)) {
        printf("%s函数执行，输入pos值非法，删除节点失败\n",__FUNCTION__);
        return 0;
    }

    pMove = pNode;
    while (pMove != NULL) {
        if (i == pos - 1) {
            break;
        }
        i++;
        pMove = pMove->next;
    }

    free(pMove->next);
    pMove->next = pMove->next->next;

    printf("%s函数执行，删除pos=%d位置元素成功\n",__FUNCTION__,pos);

    return 1;

}


int main(int argc, const char * argv[]) {

    Node *pList;

    //初始化
    initList(pList);
    printList(pList);

    //构建链表
    pList = TailInsert(pList);
    printList(pList);

    //获取链表长度
    sizeList(pList);

    //删除pos位置元素
    deletePosElement(pList, 1);//删除第一个节点有问题
    printList(pList);
    sizeList(pList);

    
    return 0;
}













