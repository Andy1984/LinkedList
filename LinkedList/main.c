//
//  main.c
//  LinkedList
//
//  Created by mac on 10/02/2018.
//  Copyright © 2018 AO. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"

int main(int argc, const char * argv[]) {
    LinkedList list = NULL;
    linkedList_initWithRandomNumbers(&list, 20);
    int length = linkedList_length(list);
    printf("链表长度 %d \n",length);
    linkedList_print(list);
    linkedList_dealloc(&list);
    
    return 0;
}
