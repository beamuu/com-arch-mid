#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*

README
    In this c source file, there are 4 functions
    1.  is_signed_two_complement()
    2.  is_signed_magnitude()
    3.  is_big_endian()
    4.  is_little_endian()

    I found the function which can print the bits of any number in
    the internet which is from
    "https://www.geeksforgeeks.org/binary-representation-of-a-given-number/" ,
    so i will use it to easily represents the bits of each number in this testing.
    ( The function name is bin() ).

    And thanks
    "https://open4tech.com/wp-content/uploads/2020/05/little_endian_vs_big_endian.png"
    for a little endian and big endian comaparison picture which makes me more clear 
    about how both of them work.

    author: Nutchanon C. 6210503578;
*/

/* Extra function (external) */
void bin(int n) {
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
    printf("\n");
}


int is_signed_two_complement() {
    /*
    2's complement machines is checked by these case:
        1.  They always have only one zero value (don't have -0).
        2.  When we compare the same positive and negative numbers,
            if we swap all positive number bits then add 1 , we should
            get the same exact number but in negative value. 
    In this function, I choose number 14 for testing.

    author: Nutchanon C. 6210503578;
    */


    // I choose case 2 for testing 2's complement machine.
    // Start with declaring to variable which they are 
    // opposite to each others.
    int a = 14;
    int b = -14;
    
    // swap all positive number bits (14)
    // or we can call it convert to 1's complement
    int swapped = ~a;

    // Then add 1 to the 1's complement
    int two_complement_result = swapped+1;

    // So now, if our hypothesis is true, two_complement_result
    // must be equal to b (-14). Let's try.
    if (two_complement_result == b) {
        return 1;
    } else return 0;

    // Back to main()
    

}

int is_signed_magnitude() {
    /*
    Signed magnitude testing
        Signed magnitude has two zeroes, which is 0x00000000
        and 0x80000000. If two of them are equal, we can assume
        that the machine uses signed magnitude for represent 
        the numbers.

    author: Nutchanon C. 6210503578;
    */
    
    int a = 0x00000000;
    int b = 0x80000000;
    
    //printf("%d %d",a,b);
    if (a == abs(b)) return 1;
    return 0;

}

int is_big_endian() {
    /*
    Big endian
        Big endian is how computer store a value in a memory 
        which MSB start from the lower address to the higher
        address.

    author: Nutchanon C. 6210503578
    */
    int a = 0x12345678;
    // Use char pointer because its read 1 byte each
    char *pointer = &a;

    if (*pointer == 0x12) return 1;
    return 0;
}

int is_little_endian() {
    /*
    Little endian
        Little endian is how cumputer store a value in memory
        which MSB start from the higher address to the lower
        address.

    author: Nutchanon C. 6210503578
    */
    int a = 0x12345678;
    // Use char pointer because its read 1 byte each
    char *pointer = &a;

    if (*pointer == 0x78) return 1;
    return 0;
}




int main() {

    if (is_signed_two_complement()) {
        printf("This computer uses signed two complement representation.\n");
    }
    else if (is_signed_magnitude()) {
        printf("This computer uses signed magnitude representation.\n");
    }

    if (is_big_endian()) {
        printf("This is a big-endian computer.\n");
    }
    else if (is_little_endian()) {
        printf("This is a little-endian computer.\n");
    }
}
