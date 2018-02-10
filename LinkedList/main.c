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
    LinkedList l = NULL;
    linkedList_init(&l);
//    for (int i = 0; i < 10; i++) {
//        linkedList_insert(l, 0, i);
//    }

    linkedList_clear(l);
    linkedList_print(l);
    return 0;
}
