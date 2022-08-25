// SCHDAM003 programme for radix conversion

#include <stdio.h>  // include releavent libraries 
#include <math.h>
#define TITLE "DECIMAL TO RADIX-i converter"  // define string constants 
#define AUTHOR "Damien Schutz"
#define YEAR "2022"

// ***************************************************************** //
// FUNCTION THAT CONVERTS ANY DECIMAL INTEGER TO A DIFFERENT NUMBER SYSTEM DEPENDING ON A RADIX VALUE

void Dec2RadixI (int decValue, int radValue){           // function requires a decimal and radix integer value
    
    int logVal = floor(log(decValue)/log(radValue));    // flooring decimal/radix gives the number of iterations we require to print every character in our converted number system  

    if(decValue == 0){
        printf("%c", 48);                               // give additional clause that outputs zero if decimal is zero - to mitigate error from logging zero = -infinity
    }
    else{
        for (int i = 0; i <= logVal; i++) {             // run loop for logVal iterations
            int factor = pow(radValue, logVal-i);       // calculate the highest possible factor in this number system by rasing the radix value to the power of the logVal - this is updated each loop logVal - 1 each iteration
            int multiplier = (decValue/factor);         // calculate the number of times the factor goes into the decimal number
            if(multiplier>9){                           // if the number if greater than 9 we have to use characters "A,B,C" etc 
                printf("%c", multiplier+55);            // print the ASCII character associated with the number + 55 - these will be the capital letters
            }
            else{                                       // if the number is less than 9 we need not worry about letters
                printf("%c", multiplier+48);            // print the assigned ASCII character to that number - i.e. 1 is the character 49 is ASCII
            }
            decValue -= (factor*multiplier);            // after each iteration we need to remove the highest factor * the multiplier from the decimal value and update the decimal value
        }
    }

// ************************************************************************************************* //
// ALTERNATIVE METHOD TO CONVERTING NUMBER SYSTES
// the method below makes use of modulo division and stores the remainder in an array
// that array is then reversed and printed whihc gives the converted number

    // int digits = ceil((log(decValue)/log(radValue)));
    // int rev_arr[digits];
    // int arr[digits];

    // for(int i = 0; i < digits; i++ ){
    //     int rem = (decValue%radValue);
    //     if (rem < 10){
    //         rev_arr[i] = rem + 48;
    //         decValue = floor(decValue/radValue);
    //     }
    //     else{
    //         rem = rem + 55;
    //         rev_arr[i] = rem;
    //         decValue = floor(decValue/radValue);
    //     }
    // }
    // for(int i=0; i<digits; i++){
    //     arr[i] = rev_arr[digits-1-i];
    // }

    // for(int i =0; i<digits; i++){
    //     printf("%c", arr[i]);
    // }
}

// ********************************************************************** //
// MAIN FUNCTION

int main (void){
    
    printf("*****************************\n %s\n Written by: %s\n Date: %s\n*****************************", TITLE, AUTHOR, YEAR);  // print title card using constants
    int dec = 0, radix;                                         // initialize decimal and radix number
    
    while(dec>=0){                                              // start infintie loop that restarts the programme unless the decimal input number is less than zero

        printf("\nEnter a decimal number: ");                   // ask user to input a decimal number and scan it
        scanf("%d", &dec);

        if(dec<0){
            printf("EXIT");                                     // print EXIT and terminate programme is decimal is less than zero
        }

        else {
            printf("The number you have entered is %d", dec);
            printf("\nEnter a radix for the converter between 2 and 16: ");             // ask user to input a radix number and scan it
            scanf("%d", &radix);
            if (radix<2 | radix>16){                                                    // radix check that returns user to the start if they input an incorrect radix
                printf("Not a valid radix");
                continue;
                }
            printf("The radix you have entered is %d", radix);
            double x = log2(dec);                                                       // calcualte the log base 2 value of the decimal and print it to screen
            printf("\nThe log2 of the number is %.2f", x);
            printf("\nThe integer result of the number divided by %d is %d", radix, (dec/radix)); // calculate the integer division and remainder of decimal/radix
            printf("\nThe remainder is %d\n", (dec%radix));
            Dec2RadixI(dec, radix);                                                     // call radix conversion function using user inputted values                                                     
        }
    }
    return 0;
}