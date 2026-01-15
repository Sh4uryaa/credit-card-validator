//Checks the validity of a credit card number using Luhn's Algorithm and identifies the card type (MasterCard, AMEX, Visa).
#include <stdio.h>

int main(void)
{
    long long num;                                                      //long long is used instead of long because its size is guaranteed to be at least 64 bits,
                                                                        // ensuring it can safely store full credit card numbers across all platforms.
    int digit_1, digit_2, digits=0, sum_1 = 0, sum_2 = 0, sum_final = 0, dig;

    //input
    printf("Enter your card number: ");
    scanf("%lli", &num);
    long long temp = num;

    //number of digits
    while(temp>0)
    {
        digits++;
        temp /= 10;
    }

    //alt number sum
    temp = num;
    temp /=10;
    for(int i = 0; i < digits/2; i++)
    {
        digit_2 = temp % 10;
        temp /= 100;
        dig = digit_2*2;
        if (dig < 10)
        {
            sum_2 +=dig;
        }
        else
        {
            sum_2 += (dig/10) + (dig%10);
        }
    }
    

    //alt number not multiplied by 2
    temp = num;
    for (int i = 0; i < digits-digits/2; i++)
    {
        digit_1 = temp % 10;
        temp /= 100; //we need alternate numbers, and not the number next to the number being stored in digit_1, hence temp/100.
        sum_1 += digit_1;
    }

    sum_final = sum_1 + sum_2;

    long long divisor_1 = 1; //pow returns double, which can cause precision issues for large integers.
    for (int i = 0; i < digits - 1; i++)
    divisor_1 *= 10;
    long long divisor_2 = 1;
    for (int i = 0; i < digits - 2; i++)
    divisor_2 *= 10;

    //invalid if the remainder of the sum isnt 0.
    if(sum_final % 10 != 0)
    {
    printf("INVALID\n");
    return 0; 
    }

    //credit card type
    int printed = 0;
    if (digits == 15 && (num / divisor_2 == 34  || num / divisor_2 == 37))
    {
        printf("AMEX\n"); //AMEX
        printed = 1;
    }

    else if (digits == 16 && (num / divisor_2 == 51 || num / divisor_2 == 52 || num / divisor_2 == 53 || num / divisor_2 == 54 || num / divisor_2 == 55))
    {
            printf("MASTERCARD\n"); //MASTERCARD
            printed = 1;
    }

    if ((digits == 13 || digits == 16) && num / divisor_1 == 4)
    {
            printf("VISA\n"); //VISA
            printed = 1;  
    }
    
    if (printed == 0)
    printf("INVALID\n");
    

}