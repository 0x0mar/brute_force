#include"allocate_numbers.h"
#include"custom_number_operations.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/*int main() {
    int i;
    int no_of_numbers;
    char t[4] = {0};
    custom_num n = {t, 4};
    custom_num *no = allocate_numbers(&n, 5, 0.01, &no_of_numbers);
    printf("No of numbers allocated %i\n", no_of_numbers);
    for(i=0; i<no_of_numbers; i++) {
        print_custom_number(&no[i]);
        printf("\n");
    }
    return 0;
}*/


custom_num *allocate_numbers(custom_num *num, int wrap, float fraction_permutations_required, int* number_of_nos_generated) {
    int i;
    int total_permutations, no_permutations_required;
    int no_digits;
    custom_num* c_num;
    no_digits = num->number_of_digits;
    total_permutations = (int)pow(wrap, no_digits); // wrap to the power no_of_digits (wrap ^ no_of_digits)
    no_permutations_required = (int)(fraction_permutations_required * total_permutations);

    //Letting the caller function know how many numbers have been created. This could prove to be a very important
    //piece of information.
    *number_of_nos_generated = no_permutations_required;

    //Actual Stuff Starts Here
    //First Allocate space for required numbers
    c_num = (custom_num*)malloc(sizeof(custom_num) * no_permutations_required);
    //printf("Allocated %i byte memory\n", (int)sizeof(custom_num) * no_permutations_required);

    //Then do a simple reset on the first number, setting NULLs and 0s
    //Then copy the initial number (which was passed as arg) to the first num.
    simple_reset_number(&c_num[0]);
    copy_custom_number(&c_num[0], num);

    //Then copy a number to next block and increase it. Reapeat and propogate
    for(i=1; i < no_permutations_required; i++) {
        simple_reset_number(&c_num[i]);
        copy_custom_number(&c_num[i], &c_num[i-1]);
        increment_number(&c_num[i], wrap);
    }
    //At the end you have a set of consecutive numbers.

    //Finally return the address of the start number.
    return c_num;
}

