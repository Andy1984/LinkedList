


//
//  LinkedList.c
//  LinkedList
//
//  Created by mac on 10/02/2018.
//  Copyright © 2018 AO. All rights reserved.
//

#include "LinkedList.h"
#include <stdlib.h>
#include <string.h>

Node *linkedList_reverseLoopWithFirstNode(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node *pre = NULL;
    Node *next = NULL;
    while (head) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

void linkedList_reverseLoop(LinkedList list) {
    list->next = linkedList_reverseLoopWithFirstNode(list->next);
}

void linkedList_reverse(LinkedList linkedList) {
    linkedList_reverseLoop(linkedList);
}

Node *linkedList_reverseRecurrsiveWithFirstNode(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node *newHead = linkedList_reverseRecurrsiveWithFirstNode(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

void linkedList_reverseRecurrsive(LinkedList list) {
    list->next = linkedList_reverseRecurrsiveWithFirstNode(list->next);
}

void linkedList_init(LinkedList *linkedList) {
    *linkedList = (Node *)malloc(sizeof(Node));
    memset(*linkedList, 0, sizeof(Node));
}

int linkedList_insert(LinkedList linkedList, int position, int value) {
    Node *currentNode = linkedList;
    while (position > 0) {
        if (currentNode->next == NULL) {
            printf("链表插入value: %d 失败， 越界 position: %d \n",value, position);
            return -1;
        }
        currentNode = currentNode->next;
        position--;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    return 0;
}

int linkedList_delete(LinkedList linkedList, int position) {
    if (linkedList == NULL) {
        printf("链表不存在 \n");
    }
    if (position < 0) {
        printf("链表删除失败 position < 0 \n");
        return -1;
    }
    Node *currentNode = linkedList;
    if (currentNode->next == NULL) {
        printf("链表删除失败 position: %d， 越界 \n",position);
        return -1;
    }
    while (position > 0) {
        if (currentNode->next == NULL) {
            printf("链表删除失败 position: %d， 越界 \n",position);
            return -1;
        }
        currentNode = currentNode->next;
        position--;
    }
    Node *deleteNode = currentNode->next;
    int deleteValue = deleteNode->value;
    printf("链表: %p 删除: %d \n", linkedList, deleteValue);
    currentNode->next = deleteNode->next;
    if (deleteNode != NULL) {
        free(deleteNode);
        deleteNode = NULL;
    }
    return 0;
}

void linkedList_print(LinkedList linkedList) {
    if (linkedList == NULL) {
        printf("要打印的链表不存在 \n");
        return;
    }
    Node *currentNode = linkedList->next;
    if (currentNode == NULL) {
        printf("链表: %p 为空 \n", linkedList);
        return;
    }
    printf("打印链表 ");
    while (currentNode) {
        printf("%d ",currentNode->value);
        currentNode = currentNode->next;
    }
    printf("\n");
}

void linkedList_clear(LinkedList linkedList) {
    Node *currentNode = linkedList;
    while (currentNode->next) {
        currentNode = linkedList->next;
        linkedList_delete(linkedList, 0);
    }
}

void linkedList_dealloc(LinkedList *linkedList) {
    linkedList_clear(*linkedList);
    if (*linkedList) {
        free(*linkedList);
        *linkedList = NULL;
    }
}

void linkedList_initWithRandomNumbers(LinkedList *linkedList, int length) {
    linkedList_init(linkedList);
    for (int i = 0; i < length; i++) {
        linkedList_insert(*linkedList, i, random() % 100);
    }
}

int linkedList_length(LinkedList linkedList) {
    Node *currentNode = linkedList->next;
    int i = 0;
    while (currentNode) {
        i++;
        currentNode = currentNode->next;
    }
    return i;
}

void swap(Node *a, Node *b) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->value = a->value;
    a->value = b->value;
    b->value = temp->value;
    free(temp);
    temp = NULL;
}

Node *linkedList_nodeAtIndex(LinkedList linkedList, int index) {
    Node *head = linkedList;
    while (index >= 0) {
        if (head->next == NULL) {
            printf("nodeAtIndex越界 index: %d \n",index);
            return NULL;
        }
        head = head->next;
        index--;
    }
    return head;
}

void linkedList_sort(LinkedList linkedList) {
//    int length = linkedList_length(linkedList);
//    for (int i = 0; i < length - 1; i++) {
//        for (int j = i + 1; j < length; j++) {
//            Node *a = linkedList_nodeAtIndex(linkedList, i);
//            Node *b = linkedList_nodeAtIndex(linkedList, i);
//            swap(a, b);
//        }
//    }
}
void linkedList_bubbleSort(LinkedList linkedList) {
    int length = linkedList_length(linkedList);
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            Node *a = linkedList_nodeAtIndex(linkedList, i);
            Node *b = linkedList_nodeAtIndex(linkedList, j);
            if (a->value > b->value) {
                swap(a, b);
            }
        }
    }
}
void linkedList_fastSort(LinkedList linkedList);
void linkedList_mergeSort(LinkedList linkedList);
