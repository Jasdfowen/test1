//erstellt unter Zusammenarbeit von Lukas Ströbel und Conrad Ackermann
#include <stdio.h>
#include <string.h>


void gibTextEin(const char prompt[], char eingabe[]) // evtl. noch Absätze eingeben lassen
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

void ermittleWortlaenge(char ursprungsSatz[], char zeichen){
    char* aktuellesZeichen = ursprungsSatz;
    char* token;
    int maxLaenge = 0;
    
    int laengeAktuellesZeichen = 1;
    if((*aktuellesZeichen>64&&*aktuellesZeichen<91)||(*aktuellesZeichen>96&&*aktuellesZeichen<123)){
            laengeAktuellesZeichen = 1;
    }
    
    while(*aktuellesZeichen!='\0'){ //evtl. längenprüfung
        aktuellesZeichen++;
        if((*aktuellesZeichen>64&&*aktuellesZeichen<91)||(*aktuellesZeichen>96&&*aktuellesZeichen<123)){
            laengeAktuellesZeichen++;
        }
        else{
            if(maxLaenge<laengeAktuellesZeichen){
                maxLaenge=laengeAktuellesZeichen;
            }
            laengeAktuellesZeichen=0;
        }
    }

    int wortlaengen[maxLaenge+1];
    for(int i = 0; i<maxLaenge+1; i++){
        wortlaengen[i]=0;
    }

    aktuellesZeichen = ursprungsSatz;
    laengeAktuellesZeichen = 0;
    if((*aktuellesZeichen>64&&*aktuellesZeichen<91)||(*aktuellesZeichen>96&&*aktuellesZeichen<123)){
            laengeAktuellesZeichen = 1;
    }
    while(*aktuellesZeichen!='\0'){
        aktuellesZeichen++;
        if((*aktuellesZeichen>64&&*aktuellesZeichen<91)||(*aktuellesZeichen>96&&*aktuellesZeichen<123)){
            laengeAktuellesZeichen++;
        }
        else{
            wortlaengen[laengeAktuellesZeichen]++;
            laengeAktuellesZeichen = 0;
        }
    }

    printf("Wortlaenge| Anzahl \n");
    printf("----------+--------\n");
    for(int i = 1; i<maxLaenge+1; i++){
        if(wortlaengen[i]!=0){
            printf("%10d|%7d\n", i, wortlaengen[i]);
        }
    }

}
int main(void){
    char ursprungsSatz[1001];
    char zeichen;
    char prompt[] = "Geben Sie eine Zeichenkette (max. 1000 Zeichen) ein:" ;
    gibTextEin(prompt, ursprungsSatz);

    ermittleWortlaenge(ursprungsSatz, zeichen);

    return 0;
}