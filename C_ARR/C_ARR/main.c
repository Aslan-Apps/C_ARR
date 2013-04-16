//
//  main.c
//  C_ARR
//
//  Created by Oguzhan Gungor on 14/04/13.
//  Copyright (c) 2013 Oguzhan Gungor. All rights reserved.
//

#include <stdio.h>
#include "C_ARR.h"

int main(int argc, const char * argv[])
{
    // create array
    C_ARR *arr = C_ARR_Create(1);
    //set values
    C_ARR_Set(arr, "OCG", 0);
    C_ARR_Set(arr, "1000", 1);

    //retrieve values
    printf("name : %s age: %s", C_ARR_Get(arr, 0), C_ARR_Get(arr, 1));
    //release array
    C_ARR_Delete(arr, NULL);
    

    return 0;
}

