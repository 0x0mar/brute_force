#include<stdio.h>
#include<stdbool.h>
#include"increment_number.h"

struct custom_num {
    char *num;
    int no_of_digits;
};


int main() {
    int i, length_of_num;
    char n[4] = {0};
    length_of_num = sizeof(n)/sizeof(n[0]);
    struct custom_num num = {n, length_of_num};
    do {
        if(increment_number(num, 26)) {
            print_custom_num(num);
            printf("\n");
        }
        else {
            printf("Error\n");
            break;
        }
    } while(!is_zero(num));
    return 0;
}

int increment_number(struct custom_num n, int wrap) {
    int okay_flag = 1;
    int i;
    //printf("Here is the number - ");
    //print_custom_num(n);
    //printf("\n");
    //printf("no of digits - %i\n", n.no_of_digits);
    //printf("wrap - %i\n", wrap);
    for(i = 0; i < n.no_of_digits; i++) {
        if (n.num[i] >= wrap) {
            okay_flag = 0;
            break;
        }

        n.num[i]++;
        if(n.num[i] == wrap) {
            n.num[i] = 0;
        }
        else {
            break;
        }
    }

    /*if(okay_flag) {
        printf("Here is the new num - ");
        print_custom_num(n);
        printf("\n");
    }
    else {
        printf("Something Broke\n");
    }*/

    return okay_flag;
}

int is_zero(struct custom_num n) {
    int i;
    bool flag = true;
    for(i = 0; i < n.no_of_digits; i++) {
        if(n.num[i]) {
            flag = false;
            break;
        }
    }
    return (int)flag;
}

void print_custom_num(struct custom_num n) {
    int i;
    int no_of_digits;
    char *num;

    no_of_digits = n.no_of_digits;
    num = n.num;
    
    for(i = 0; i < no_of_digits; i++) {
        printf("%i ", num[i]);
    }
}
