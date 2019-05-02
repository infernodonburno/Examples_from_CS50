/* Implements a credit card checker using Luhn's algorithm 
   to verify the validity of a credit card. From the cs50
   curriculum. 
   
   by Chris Purnell 
*/

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    //set card to 20 length string
    char card_num[20];
    char *ptr;

do
{
    printf("Please enter your credit card number\n");
    scanf("%s",card_num);
}while((strlen(card_num) < 9) || (strlen(card_num) > 17));

    int len = strlen(card_num);
    int i = 0;
    int num = 0;
    int sum = 0;

// luhn algorithm by string to int conversion
        for(i = 0; i < len; i++)
        {
            if((i % 2) == 0) //if number in the index is even, multiply by 2
            {
                num = (card_num[i] - '0')*2; //converting from string to number by ascii table

                if(num > 9) // products are split in algorithm, so if it is greater than 9, we subtract for the correct integer
                {
                    num -= 9;
                }
            }

            else
                num = card_num[i] - '0'; //other numbers in index are not multiplied, just summed
                sum += num;
        }
//printf("%d\n",sum);

        /*if( sum % 10 != 0)
        {
            printf("INVALID\n");
            return 0;
        }*/

//printf("%s\n", card_num);
    int count = 0;
    long val;
    val = strtol(card_num,&ptr,10); // convert str to long number for arithmetic on deciding cards first numbers
    long newcard = val;

            while(val != 0) // divides down to the last two numbers to set the card type
            {
                val = val / 10;
                count++;
            }

            if( count != 16 && count != 13 && count != 15)
            {
                printf("INVALID\n");
                return 0;
            }

            if (count == 15)
            {
                while(newcard >= 100)
                {
                    newcard = newcard / 10;
                }
                if (newcard == 34 || newcard == 37)
                {
                    printf("AMEX\n");

                }
                else
                {
                    printf("INVALID\n");
                }
            }


            if (count == 16 || count == 13)
            {
                if (sum % 10 != 0)
                {
                    printf("INVALID\n");
                    return 0;
                }

                while (newcard >= 100)
                {
                    newcard /= 10;
                }
                if (newcard == 51 || newcard == 52 || newcard == 53 || newcard == 54 || newcard == 55)
                {
                    printf("MASTERCARD\n");
                }

                else if (newcard == 40 || newcard == 41 || newcard == 42 || newcard == 43 || newcard == 44 ||
                         newcard == 45 || newcard == 46 || newcard == 47 || newcard == 48 || newcard == 49)
                {
                    printf("VISA\n");
                    return 0;
                }
                else
                {
                    printf("INVALID\n");
                }
            }
}
