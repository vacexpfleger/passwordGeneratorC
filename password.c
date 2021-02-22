/*Program na generovani hesla - Fisher-Yates metoda*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 10

void createPassword() {
    char password[LENGTH];
    int total = 62;
    char symbols[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;
    int ar[total];
    
    for(i = 0; i < total; i++){
        ar[i] = i;
    }

    for (i = total-1; i >= 1; i--){
        int temp = rand() % (i+1);
        int temp2 = ar[i];
        ar[i] = ar[temp];
        ar[temp] = temp2;
    }
    
    printf("Vytvorene heslo: ");
    for(i = 0;i < LENGTH;i++) {
        password[i] = symbols[ar[i]];
        printf("%c", password[i]);
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
    srand(time(0));
    printf("Povolene znaky: 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
    do {
        createPassword();
    } while(repeat());
    return (EXIT_SUCCESS);
}