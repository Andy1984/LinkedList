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

void linkedList_init(LinkedList *linkedList);

void linkedList_reverse(LinkedList linkedList);

int linkedList_insert(LinkedList linkedList, int position, int value);

int linkedList_delete(LinkedList linkedList, int position);

void linkedList_print(LinkedList linkedList);

void linkedList_dealloc(LinkedList linkedList);

void linkedList_clear(LinkedList linkedList);
#endif /* LinkedList_h */
