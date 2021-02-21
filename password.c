#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 10

void createPassword() {
    char password[LENGTH];
    char nums[] = "0123456789";
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    char caps[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int selector = rand() % 3; //nahodny vyber skupiny znaku
    int i;
    
    printf("Vytvorene heslo: ");
    for(i = 0;i < LENGTH;i++) {
        if(selector == 1) { //pokud je selector = 1, pridej do hesla cislo
            password[i] = nums[rand() % 10];
            printf("%c", password[i]);
            selector = rand() % 3;
        }
        else if(selector == 2) { //pokud je selector = 2, pridej do hesla male pismeno
            password[i] = letters[rand() % 26];
            printf("%c", password[i]);
            selector = rand() % 3;
        }
        else { //pokud je selector = 3, pridej do hesla velke pismeno
            password[i] = caps[rand() % 26];
            printf("%c", password[i]);
            selector = rand() % 3;
        }
    }
}

int repeat() {
    printf("\nPro vygenerovani dalsiho hesla stiskni Enter: ");
    char input=fgetc(stdin);
    if(input == 0x0A){
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    srand(time(NULL));
    printf("Povolene znaky: 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
    do {
        createPassword();
    } while(repeat());
    return (EXIT_SUCCESS);
}