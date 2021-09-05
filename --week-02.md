Caesar task

```
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // if arc doesn't has 2 argument prints error
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // if there are 2 arguments checks if all the second argument contains digits
        string k = argv[1];
        for (int i = 0; i < strlen(k); i++)
        {
            if (isdigit(k[i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;

            }
        }
        // print commands below for testing purpose

        // printf("Success\n");
        // printf("%s\n",k);

        // converts second argument to int
        int myKey = atoi(k);

        // asks users for plaintext to be ciphered
        string plaintext = get_string("Plaintext: ");

        // For loop to convert to ciphertext
        for (int i = 0; i < strlen(plaintext); i++)
        {
            if (isupper(plaintext[i]))
            {
                // by given formula need to change base so that A is 0
                // when you minus capital A ASCII value by 65 it becomes 0
                plaintext[i] = (plaintext[i] - 65);
                plaintext[i] = (plaintext[i] + myKey) % 26;
                plaintext[i] = (plaintext[i] + 65);
                // printf("%c",plaintext[i]);
            }
            if (islower(plaintext[i]))
            {
                plaintext[i] = (plaintext[i] - 97);
                plaintext[i] = (plaintext[i] + myKey) % 26;
                plaintext[i] = (plaintext[i] + 97);
                // printf("%c",plaintext[i]);

            }
            if (isalpha(plaintext[i]) == 0)
            {
                plaintext[i] = plaintext[i];
                // printf("%c",plaintext[i]);
            }
        }
        printf("Ciphertext: %s", plaintext);
        printf("\n");

    }

}

```

Vigenere task

```
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// input cipher key at command line
int main(int argc, string argv[]){
    
    int keyLength;
    
    // per instructions -- terminate program if more than one key
    if(argc != 2){

        printf("error");
        return 1;
    
    // check to ensure key characters are alphabetical
    } else {
        
        keyLength = strlen(argv[1]);
        
        for(int h = 0; h < keyLength; h++){
            if(!isalpha(argv[1][h])){
                printf("error");
                return 1;
            }
        }
    }

    // log command line cipher key input to array of int
    char key[keyLength];
    
    for(int g = 0; g < keyLength; g++){
        
        key[g] = argv[1][g];
        
    }
    
    // prompt user for plaintext input
    printf("plaintext:");
    string plainText = get_string();
    
    // declare ciphertext array of characters
    
    char cipherText[strlen(plainText)];
    int plainLength = strlen(plainText);
    
    // iterate over and encrypt each character in plaintext by the most int value of the most recent key element, wrapping around key when end reached, as necessary
    for(int i = 0, j = 0; i < plainLength; i++){

        if(isalpha(plainText[i])){
            
            if(isupper(key[j % keyLength])){
                
                if(isupper(plainText[i])){
                
                    cipherText[i] = ((((plainText[i] - 65) + (key[j % keyLength] - 65)) % 26) + 65);
                
                } else {
                
                    cipherText[i] = ((((plainText[i] - 97) + (key[j % keyLength] - 65)) % 26) + 97);
                    
                }
            } else {
                
                if(isupper(plainText[i])){
                
                    cipherText[i] = ((((plainText[i] - 65) + (key[j % keyLength] - 97)) % 26) + 65);
                
                } else {
                
                    cipherText[i] = ((((plainText[i] - 97) + (key[j % keyLength] - 97)) % 26) + 97);
                }
            }
            
            j++;
        // leave all non-alphabetical items as is    
        } else {
            cipherText[i] = plainText[i];
        }
        
    }
    
    // per instructions, print cipherText array with no newline
    printf("ciphertext: ");
    
    for(int k = 0; k < plainLength; k++){
        
        printf("%c",cipherText[k]);
    }
    // per instructions, print newline
    printf("\n");
        
    return 0;

}
```
