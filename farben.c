//erstellt unter Zusammenarbeit von Lukas Ströbel und Conrad Ackermann
#include <stdio.h>
#include <string.h>

int gibTextEin(const char prompt[], char eingabe[], char farben[][8])
{
    printf("%s", prompt);
    scanf("%7[^\n]s", eingabe);
    while(getchar() != '\n');
    for(int i = 0; i<3; i++){
        if(strcmp(eingabe, farben[i])==0){
            return i;
        }
    }
    while(1){
        printf("Unbekannte Grundfarbe %s (Neue Eingabe machen): ", eingabe);
        scanf("%7[^\n]s", eingabe);
        while(getchar() != '\n');
        for(int i = 0; i<3; i++){
            if(strcmp(eingabe, farben[i])==0){
                return i;
            }
        }
    }
}
int main(void){
    char farben[][8]={"Gruen", "Rot", "Violett", "Blau", "Gelb", "Purpur"};
    const char mischtabelle[3][3][8]={{"Gruen","Gelb","Blau"},{"Gelb","Rot","Purpur"},{"Blau","Purpur","Violett"}};
    char prompt[] = "Erste Grundfarbe (Gruen Rot Violett ):  " ;
    char farbe1[8];
    int farbe1Zahl = gibTextEin(prompt, farbe1, farben);
    char prompt2[] = "Zweite Grundfarbe (Gruen Rot Violett ): " ;
    char farbe2[8];
    int farbe2Zahl = gibTextEin(prompt2, farbe2, farben);

    printf("Endfarbe: %s", mischtabelle[farbe1Zahl][farbe2Zahl]);
    return 0;
}