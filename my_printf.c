#include <stdio.h>
#include <stdarg.h>


// This function takes num, but because putchar can only 
// take one number from 0-9 at a time, this function will check if 
// the number is greater than 9 and if it is then it will recursively cut down the number 
// working its way up and printing every character from that number and onwards so the entire number could 
// be effectively printed. 

void print_number (int num) { 

    // Make sure to deal with negative numbers. 
    if (num < 0){ 
        putchar('-'); 
        num = -num;
    }
    // if the number is more than one character 
    if (num > 9){ 
        // recursively call the function itself and cutt down the number 
        print_number(num/10);
    }
    // make sure to change the number into a character sot that putchar will work effectively. 
    putchar((num %10)+ '0');
}


// simply put the character! 
void print_character(char c){ 
    putchar(c); 
}

void print_string(char str[]){
  for (int i =0; i != "\0"; i++){
    putchar(str[i]);
      }
}

void print_hex(int num){ 
    
}

// void print_string(const char s){
//     for ( const char *p = s; *p != '\0'; p++){ 
//         putchar(*p);
//     }

// }
void my_printf( char *str , ...){ 
    // initialize the va_list so that you can take in an unknown amount of arguments. 
    va_list args; 
    va_start(args, str); 
    // loop through the input string first argument
    // the '\0' makes sure to keep looping until a null is encountered
    
    for (const char *p = str; *p !='\0'; p++){
        // if no percent sign is encountered, put the character to stdout. 
        if (*p != '%'){
            putc(*p, stdout);
        }
        else 
            {
                // if a % is encountered, then increment p to the next character 
            p++; 
            switch (*p) {
                // if the character is a digit 

                case 'd':{
                    int value = va_arg(args, int); 
                    print_number(value); 
                    break;
                }
                // if the character is a character

                case 'c': {
                    int value = va_arg(args, int); 
                    print_character(value); 
                    break; 
                }
                // if the character is a hex digit 
                case 'x': {
                    int value = va_arg(args, int);
                    print_hex(value);
                    break;
                }

                // if the character is a string. 
                case 's': {
                    const char *value = va_arg(args, const char*);
                    print_string(value);

                    break;
                }

            }
        }
    }
 }

int main(){
    my_printf("NO PERCENTS TEST\n");
    my_printf("-------------------------\n");
    my_printf("Long Digit Test: %d \n", 123455);
    my_printf("Short Digit Test: %d \n", 3);
    my_printf("Negative Digit Test: %d \n", -123);
    my_printf("--------------------------\n"); 
    my_printf("Character Test: %c \n",'h');
    my_printf("--------------------------");
    my_printf("String Test: %s \n", "You successfully printed this string yay!");
     
}
