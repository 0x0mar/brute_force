# custom_number_incrementor
This will increment numbers built by the user (custom numbers, i.e number types not predefined by the c language)

Simply call increment_number() function with these paramters.

struct custom_num n
int wrap_around

The first argument is a structure that comprises a reference to an array of chars and 
the length of the chars.

So you could have 8 byte, 10 byte, 16 byte etc array.

Just create the struct with it and also pass the number of bytes 8, 10, 16.

Ex:-
    char[13] no = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32};
    struct custom_num n = {no, 13};

wrap_around is simply a number by which you want to wrap around.
Ex:-
    wrap_around = 5, would mean numbers like :-
    0 0 0 0
    1 0 0 0
    2 0 0 0
    3 0 0 0
    4 0 0 0
    0 1 0 0

In binary systems we wrap around 2, in decimal 10, in hexa 16.

calling increment_number() is as easy as typing:-
increment_number(n, wrap_around)
