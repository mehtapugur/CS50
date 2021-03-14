Lecture notes https://cs50.harvard.edu/x/2020/notes/1/#more-examples

* "Hello" task

```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name?\n");
    printf("hello, %s\n", name);
}
```

* "Mario" task

```
int main(void)
{
    int n;
    do
    {
        n = get_int("%s", "Height: ");
    } while (n < 1 || n > 8);
    
    printf("%i\n", n);

     for (int i = 0; i < n; i++)
  {
      for (int j = 0 ; j < (n-i-1); j++)
      {
          printf(" ");
      }
      for (int j = (n-i-1); j < n; j++)
      {
          printf("#");
      }
      printf("\n");
  }
}
```

* "Credit" task

```
#include <stdio.h>
#include <cs50.h>

int main(void){

    long number = get_long("Enter your Credit Card Number: \n");
    long check = number;

    int counter = 0;
    int ilk_iki;

    while(check > 0){

        if(check < 100 && check > 10){ // ilk iki basamağa ihtiyacımız var
            ilk_iki = check;
        }
    
        counter++; //basamak sayısı
        check /= 10; //her seferinde 10a bölüp basamak azaltılır
    }

    if((counter != 13) && (counter != 15) && (counter != 16)){ //bu basamak sayısına sahip değilse kontrol edilmez
        printf("INVALID\n");

    } else {

        int a = 0; //altı çizili olmayan sayıları toplama sayacı
        int b = 0; //altı çizili olan sayıları toplama sayacı
        int c = 0;

        while( number > 0){ //check yukarıda değiştiği için number kullanıldı

            a += number%10; // 45623879564542
            number /= 10; // 4562387956454.2

            if(number > 0){

                c = (number%10) *2; // tekrar mod alır sondan 2. basamağı bulur, 2 ile çarpar
                b += c/10; // sonucun ilk basamağı, sonuç 17 ise 1 i b ye ekler
                b += c%10; // sonucun 2. basamağı, sonuç 17 ise 7 yi b ye ekler
                number /= 10;
            }

        }

        int rmn = (a+b)%10; // kontrol için toplamın son basamağı elde edilir

        if(rmn != 0){

            printf("INVALID\n");

        } else if(rmn == 0){

            if((counter == 15) && ((ilk_iki == 34) || (ilk_iki == 37))){

                printf("AMEX\n");

            }
            else if((counter == 16) && ((ilk_iki == 51) || (ilk_iki == 52) || (ilk_iki == 53) || (ilk_iki == 54) || (ilk_iki == 55) )){

                     printf("MASTERCARD\n");
            }
            else if(((counter == 13) || (counter = 16)) && (ilk_iki / 10)==4 ){
                printf("VISA\n");

            }
            else {
                printf("INVALID\n");
            }
        }
    }
}

```
