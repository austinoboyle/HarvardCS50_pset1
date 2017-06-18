#include <stdio.h>
#include <cs50.h>

int main(void){
    printf ("Number: ");
    long long cardNumber = get_long_long();
   
    
    int index = 0;
    int sumDigits = cardNumber % 10;
    long long currentNum = cardNumber/10;
    int firstTwoDigits;
    int firstDigit;
    
    while (currentNum > 0){
        int currentDigit = currentNum % 10;
        
        switch (index % 2){
            case 1: 
                sumDigits += currentDigit;
                break;
                
            default:
                currentDigit *= 2;
                sumDigits += currentDigit % 10 + (currentDigit / 10) % 10;
                break;
        }
        
        if (currentNum >= 10 && currentNum < 100){
            firstTwoDigits = currentNum;
            firstDigit = currentNum / 10;
        }
        
        index++;
        currentNum /= 10;
    }
    bool validSum = sumDigits % 10 == 0;
    
    if (validSum){
        switch(firstTwoDigits){
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
                printf ("MASTERCARD\n");
                break;
                
            case 34:
            case 37:
                printf ("AMEX\n");
                break;
                
            default:
                if (firstDigit == 4) printf("VISA\n");
                else{
                    printf ("INVALID\n");
                }
                break;
            
        }
    }
    else{
        printf ("INVALID\n");
    }
    
    
}