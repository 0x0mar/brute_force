#include"custom_number_operations.h"
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

/*int main() {
    int i, length_of_num;
    char n[4] = {0};
    char n2[4] = {4, 5, 6, 7};
    length_of_num = sizeof(n)/sizeof(n[0]);
    custom_num num = {n, length_of_num};
    //#Test1
    printf("Test1\n");
    print_custom_number(&num);
    increment_number(&num, 5);
    printf("\n");
    increment_number(&num, 5);
    print_custom_number(&num);
    printf("\n");
    //#Test1End

    //#Test2
    printf("Test2\n");
    custom_num num2 = {n2, 4};
    copy_custom_number(&num, &num2);
    print_custom_number(&num);
    //#Test2End    
}*/

int increment_number(custom_num *n, int wrap) {
    int okay_flag = 1;
    int i;
    //printf("Here is the number - ");
    //print_custom_number(n);
    //printf("\n");
    //printf("no of digits - %i\n", n.no_of_digits);
    //printf("wrap - %i\n", wrap);
    for(i = 0; i < n->number_of_digits; i++) {
        if (n->number_array[i] >= wrap) {
            okay_flag = 0;
            break;
        }

        n->number_array[i]++;
        if(n->number_array[i] == wrap) {
            n->number_array[i] = 0;
        }
        else {
            break;
        }
    }

    /*if(okay_flag) {
        printf("Here is the new num - ");
        print_custom_number(n);
        printf("\n");
    }
    else {
        printf("Something Broke\n");
    }*/

    return okay_flag;
}

int copy_custom_number(custom_num *copy_to, custom_num *copy_from) {
    int i;
    copy_to->number_of_digits = copy_from->number_of_digits;
    copy_to->number_array = NULL;
    copy_to->number_array = (char*)malloc(sizeof(char) * copy_to->number_of_digits);
    //printf("Allocated %i byte memory\n", (int)sizeof(char) * copy_to->number_of_digits);
    for (i = 0; i < copy_to->number_of_digits; i++) {
        copy_to->number_array[i] = copy_from->number_array[i];
    }
    return copy_to->number_of_digits;
    //Function returns number of digits copied
}

void reset_number(custom_num *n) {
    n->number_of_digits = 0;
    free(n->number_array);
    n->number_array = NULL;
}

void simple_reset_number(custom_num *n) {
    n->number_of_digits = 0;
    n->number_array = NULL;
}

int is_zero(custom_num *n) {
    int i;
    bool flag = true;
    for(i = 0; i < n->number_of_digits; i++) {
        if(n->number_array[i]) {
            flag = false;
            break;
        }
    }
    return (int)flag;
}

void print_custom_number(custom_num *n) {
    int i;
    int no_of_digits;
    char *num;

    no_of_digits = n->number_of_digits;
    num = n->number_array;
    
    for(i = 0; i < no_of_digits; i++) {
        printf("%i ", num[i]);
    }
}
