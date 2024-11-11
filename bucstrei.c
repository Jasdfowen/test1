//erstellt unter Zusammenarbeit von Lukas Ströbel und Conrad Ackermann
#include <stdio.h>
#include <string.h>


void gibTextEin(const char prompt[], char eingabe[])
{
    printf("%s", prompt);
    int eingelesen = 0;
    while(eingelesen==0){
        eingelesen =  scanf("%1000[^\n]s", eingabe);
        while(getchar() != '\n');
    }
}

char gibCharEin(){
    printf("Geben Sie das zu loeschende Zeichen ein:");
    int eingelesen = 0;
    char zeichen;
    while(eingelesen==0){
        eingelesen= scanf("%c", &zeichen);
        while(getchar() != '\n');
    }
    return zeichen;
}

void loescheZeichen(char ursprungsSatz[], char zeichen, int laenge){
    char* startPunkt = ursprungsSatz;
    char* aktuellesZeichen = ursprungsSatz;
    do{
        printf("aktuelles Zeichen: %c\n", *aktuellesZeichen);
        if(*aktuellesZeichen==zeichen){
            char *parser = aktuellesZeichen;
            do{
                *parser = *(parser+1);
                parser = parser+1;
            }while(*parser!='\0'&&parser<startPunkt+laenge-2); //nochmal längen kontrolle anschauen
            aktuellesZeichen++;
        }
        else{
            aktuellesZeichen++;
        }
    }while(*aktuellesZeichen!='\0' && aktuellesZeichen<startPunkt+laenge-2); //nochmal längen kontrolle anschauen
}
int main(void){
    char ursprungsSatz[1001];
    char zeichen;
    char prompt[] = "Geben Sie eine Zeichenkette (max. 1000 Zeichen) ein:" ;
    gibTextEin(prompt, ursprungsSatz);
    zeichen = gibCharEin();

    loescheZeichen(ursprungsSatz, zeichen, 1001);

    printf("......Die neue Zeichenkette ist dann: %s", ursprungsSatz);
    return 0;
}