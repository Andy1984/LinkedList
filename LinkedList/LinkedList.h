//
//  LinkedList.h
//  LinkedList
//
//  Created by mac on 10/02/2018.
//  Copyright © 2018 AO. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
typedef struct Node {
    int value;
    struct Node *next;
} Node, *LinkedList;

//创建空链表
void linkedList_init(LinkedList *linkedList);
void linkedList_initWithRandomNumbers(LinkedList *linkedList, int length);
//链表翻转
void linkedList_reverse(LinkedList linkedList);
void linkedList_reverseLoop(LinkedList list);
void linkedList_reverseRecurrsive(LinkedList list);
Node *linkedList_reverseLoopWithFirstNode(Node *head);
Node *linkedList_reverseRecurrsiveWithFirstNode(Node *head);
//插入
int linkedList_insert(LinkedList linkedList, int position, int value);
//删除
int linkedList_delete(LinkedList linkedList, int position);
//打印
void linkedList_print(LinkedList linkedList);
//销毁
void linkedList_dealloc(LinkedList *linkedList);
//清空
void linkedList_clear(LinkedList linkedList);
//排序
void linkedList_sort(LinkedList linkedList);
void linkedList_bubbleSort(LinkedList linkedList);
void linkedList_fastSort(LinkedList linkedList);
void linkedList_mergeSort(LinkedList linkedList);

#endif /* LinkedList_h */
