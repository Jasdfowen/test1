#include <stdio.h>
#define INT_MAX 2147483647
int einlesen(char prompt[] ,int min, int max){
    int eingabe = 0;
    int eingelesen = 0;
    while(eingelesen == 0 ||eingabe>max||eingabe<min){
        printf("%s", prompt);
        eingelesen = scanf("%d", &eingabe);
        while(getchar()!='\n'){}
    }
    return eingabe;
}

int main(void){
    int n = einlesen("Bis wohin sollen die Primzahlen berechnet werden (Ende=0) ? ", 0, INT_MAX);
    return 0;
}