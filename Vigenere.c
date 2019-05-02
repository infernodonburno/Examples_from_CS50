#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if ( argc != 2)     // only allows two arguments of argc and argv
    {
        printf("Too many arguments. Please try again\n");
        return 1;
    }

    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)    // checks with isalpha to reject numeric values
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Must use alphabetic characters. \n");

                return 1;
            }
        }
    }


    //prompts user for their code to encrypt

    string plaintext = get_string("Enter plaintext to encrypt: \n");


    printf("ciphertext: ");

    string key = argv[1];           //sets the key to a string
    int keyLen = strlen(argv[1]);   //sets the string length to an integer

    for (int i = 0, j = 0, n = strlen(plaintext); i < n; i++)  //cycles through every letter in the string

            {

                //get key for the letter

                int newkey = tolower(key[j % keyLen]) - 'a';

                //uses ctype.h to check for upper or lower case then adds the key value
                //then uses ASCII arithmetic by taking out the base
                //and using modulo for the remainder to re add the base
                //for the new value


                if (isupper(plaintext[i]))
                {
                    printf("%c", 'A' + (((plaintext[i] + newkey) - 'A') % 26));

                    j++; //increment if used in loop

                }

                else if (islower(plaintext[i]))
                {
                    printf("%c", 'a' + (((plaintext[i] + newkey) - 'a') % 26));

                    j++; //increment if used in loop
                }

                else
                {
                    printf("%c", plaintext[i]);
                }


            }
     printf("\n");
     return 0;
}
