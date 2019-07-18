#include <stdio.h>

/* MACRO for bitwise operation's */

# ifndef    __BITWISE__
# define    __BITWISE__

/* Assign the Maximum value of the integer */

# define    MAX    (-1) >> 1

/* Mask the odd bit's in the given number */

# define    O_MASK            0x55555555

/* Mask the even bit's of the given number */

# define    E_MASK            0xAAAAAAAA

/* Find the number is power of four or not */

# define    P_FOUR(num)        (num & O_MASK) ? (!(num & (~(-num)))) ? 1 : 0 : 0

/* Find the number is power of two or not */

# define    P_TWO(num)        (num) ? (num & (~(-num))) ? 0 : 1 : 0

/* Find the given number is multiply by 2,4,8 or not */

# define    MUL_2(num)    (num & 1) ? 0 : 1

# define    MUL_4(num)    (num & 3) ? 0 : 1

# define    MUL_8(num)    (num & 7) ? 0 : 1

/* Find the given number is multiply by 9 or not */

# define    MUL_9(num)    ((num << 3) | (num))

/* Arithmetic addition of two number's using bitwise operation */

# define    ADD(a,b)         while(b = ((((a ^= b) ^ b) & b ) << 1 )) ;

/* Arithmetic subtraction of two number's using bitwise operation */

# define    SUB(a,b)          while(b = ((~((a ^= b) ^ b) & b ) << 1 )) ;

/* Set the particular bit in the given number */

# define    SET(num,pos)        num = num | (1 << pos)

/* Clear the particular bit in the given number */

# define    CLEAR(num,pos)        num  = num & (~(1 << pos))

/* Set two bit's in the given number using two different position's */

# define    SET_2_BIT(num,p1,p2)     num = ((num | (1 << p1)) | (num | (1 << p2)))

/* Complement the bit's in a given number for a particular source and destination position */

# define    COMP(num,src,des)    num = num ^ ( (unsigned) -1  >> ((32 - (des-src))-1) ) << src

/* Complement the even bit's in the number */

# define    C_EVEN(num)        num = num ^ E_MASK

/* Complement the odd bit's in the number */

# define    C_ODD(num)        num = num ^ O_MASK

/* Toggle the entire bit's in the number */

# define    TOG(num)        num = ~num

/* Find the greatest number from the given two number's */

# define    GREAT(num1,num2)    ((num1 - num2) >> 31) ? num2 : num1

/* Increment operator using bitwise */

# define    INC(num)        num = -(~num)

/* Decrement operator using bitwise */

# define    DEC(num)        num = ~(-num)

/* Check the MSB bit is set or not */

# define    HIGHT(num)        (num & (1 << (sizeof(num)*8)-1)) ? 1 : 0

/* Check the LSB bit is set or not */

# define    LOW(num)        (num & 1) ? 1 : 0

/* Right Rotate the given number by n times */

# define    R_RIGHT(num,n)        num = ((num >> n) | (num << 32-n))

/* Left Rotate the given number by n times */

# define    R_LEFT(num,n)         num = ((num << n) | (num >> 32-n))

/* Swap the two integer number's using bitwise */

# define    SWAP_NUM(a,b)        a = a ^ b; b = a ^ b;  a = a ^ b;

/* Swap the adjacent bit's in the given number */

# define    SWAP_ADJ(num)    num = (((num & E_MASK) >> 1) | ((num & O_MASK) << 1));

/* Swap the nibble's from the given integer number */

# define    INT(num)    num = ((num << 28) | (num >> 28) | (num & 0x0ffffff0))
# define    INT_S(num)    num = ( (num & 0x0A0A0A0A ) >> 4 ) | ( ( num & 0xA0A0A0A0) << 4 )

/* Swap the nibble's from the given charecter */

# define    SWP_NIB_CHR(n)         n = (n << 4) | (n >> 4)

/* convert the charecter from upper to lower case   */

# define    TO_LOWER(c)    (c >= 65 && c <= 91) ? c |= 1 << 5 : 0

/* convert the charecter from lower to upper case   */

# define    TO_UPPER(c)    (c >= 97 && c <= 122) ? c ^= 1 << 5 : 0

/* Inline functions */

/* count trailing zeros in the given number */

static inline int trailing(unsigned int num)
{
    int count = 0;
    for(;((!(num & 1)) && count!= 32 );num >>= 1,count++) ;
    return count;
}

/* count the number of ones in an given number */

static inline int count_set(unsigned int num)
{
    int count = 0;
    for(; num ;count += num & 1, num >>= 1) ;
    return count;
}

/* print the next largest number containing same number of 1's and 0's  */

static inline int next_large(unsigned int num)
{
    int f,s = 0;
    for(f = count_set(num) ; f != s ; s = count_set(INC(num))) ;
    return num;
}

/* check whether given number is bit pallindrome or not  */

static inline int palindrome(unsigned int num)
{
    int i;

    for(i = 0;(((num >> i) & 1 ) == ((num >> 31-i) & 1)) && i < 16; i++) ;

    (i == 16)? 1 : 0;
}
/* Display the binary form of the given number */

void show(int num)
{
    int i;
    for(i = 31;i>=0;i--)
        (num & (1 << i)) ? printf("1 ") : printf("0 ");
}

# endif


void main(void)
{

}


/* End of the file */
