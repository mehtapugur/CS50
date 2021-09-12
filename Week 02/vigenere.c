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
