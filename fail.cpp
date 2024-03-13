#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

void func(float *stck_p, char * heap_p){
    char *r = (char *)malloc(5 * sizeof(char)); // not dealocated
    stck_p[5] =  18.2;  // stack out of index
    stck_p[1] =  '2';  // wrong type assigned
    heap_p[100] =  '2';  // potentional heap out of index

    // scanf("%s", r); // load malitious code and rewrite RA + stack overflow
    strcpy(heap_p, r); // heap overflow
}

int main(int argc, char* argv[]) {
         printf("You have entered %d arguments:\n", argc);

     for (int i = 0; i < argc; i++) {
         printf("%s\n", argv[i]);
     }
    char arg_chr[10];
    strcpy(arg_chr, argv[1]); // No check on the length of input, stack overflow
    int arg_num = atoi(argv[2]); // atoi not safe, what is not number

    float f[3] = {3.14, 2.0, 0.66};
    char *p = (char *)malloc(10 * sizeof(char));

    func(f, p);

    unsigned int n = 4294967295;
    n += 1; // preteceni na 0

    memcpy(p, arg_chr, 30); // heap overflow, zadna kontrola delky nahravane vs size, kladne cislo
    free(p); // x

    if (arg_num > 1500) {        
        int *i = NULL;
        printf("%d", *i); // using unitialized pointer
    }

    if (arg_num > 1000) free(p); // potentional double free

    return 0;
}
