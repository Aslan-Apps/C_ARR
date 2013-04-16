/*
 * C_ARR.m
 *
 * Created by Oguzhan Cansin Gungor on 17/04/13.
 *
 * Copyright (c) 2013 Aslan-Apps. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *       This product includes software developed by Aslan-Apps.
 * 4. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "C_ARR.h"


static void C_ARR_Grow (C_ARR *a) {
    void **tmp = NULL;
    a->size *= 2;
    
    tmp = realloc (a->data, a->size * (sizeof *(a->data)));
    if (tmp == NULL) {
        perror ("can't grow array");
        exit (EXIT_FAILURE);
    }
    a->data = tmp;
}

C_ARR *C_ARR_Create (size_t n) {
    C_ARR *a = malloc (sizeof *a);
    
    if (n < 1)
        n = 1;
    
    if (a != NULL) {
        a->data = calloc (n, sizeof *(a->data));
        if (a->data == NULL) {
            free (a);
            perror ("can't create array");
            exit (EXIT_FAILURE);
        }
        else
            a->size = n;
        
    }
    else {
        perror ("can't create array");
        exit (EXIT_FAILURE);
    }
    
    return a;
}

size_t C_ARR_Size (C_ARR *a) {
    return a->size;
}

void C_ARR_Delete (C_ARR *a) {

    free (a->data);
    free (a);
}

void C_ARR_Set (C_ARR *a, void *data, size_t index) {
    while (a->size < index + 1)
        C_ARR_Grow(a);
    
    a->data[index] = data;
}

void *C_ARR_Get (C_ARR *a, size_t index) {
    void *data = NULL;
    
    if (index < a->size)
        data = a->data[index];
    
    return data;
}
