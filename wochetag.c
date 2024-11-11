//erstellt unter Zusammenarbeit von Lukas Ströbel und Conrad Ackermann
#include <stdio.h>
#include <string.h>


char istSchaltjahr(int jahr){
    if (jahr%400==0)
        return 1;
    else
        if (jahr%100==0)
            return 0;
        else
            if (jahr%4==0)
                return 1;
            else
                return 0;
}

char datumKorrekt(int tag, int monat, int jahr){ //hier nochmal testen
    if(jahr < 0){
        return 0;
    }

    if(monat >12 || monat<1){
        return 0;
    }

    if(tag<1 || tag > 32){
        return 0;
    }
    if(monat==1||monat==3||monat==5||monat==7||monat==8||monat==10||monat==12){
        if(tag>31){
            return 0;
        }
    }
    else if(monat ==2){
        if(istSchaltjahr(jahr)){
            if(tag>29){
                return 0;
            }
        }
        else{
            if(tag >28){
                return 0;
            }
        }
    }
    else{
        if(tag>30){
            return 0;
        }
    }

    return 1;
}


void gibDatumEin(const char prompt[], int* tag, int * monat, int* jahr) // evtl. noch Absätze eingeben lassen
{
    int eingelesen = 0;
    char korrekt = 0;
    while(eingelesen!=3||korrekt == 0){
        printf("%s", prompt);
        eingelesen =  scanf("%d.%d.%d", tag, monat, jahr);
        while(getchar() != '\n');
        korrekt = datumKorrekt(*tag, *monat, *jahr);
    }
}

int main(void){
    int tag = 0;
    int monat = 0;
    int jahr = 0;
    char prompt[] = "Gib Datum ein (tt.mm.jjjj): " ;
    gibDatumEin(prompt, &tag, &monat, &jahr);

    int jh_koeff[4] = { 4, 2, 0, 5 };
    int monat_koeff[12] = { 2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0 };
    int schaltjahr = 0;
    int jh = jahr/100;
    int ja = jahr%100;
    int wochentagzahl = 0;
    char* Wochentag;

    if (monat > 2)
        schaltjahr = 0;
    else
        if (jahr%400==0)
            schaltjahr = 1;
        else
            if (jahr%100==0)
                schaltjahr = 0;
            else
                if (jahr%4==0)
                    schaltjahr = 1;
                else
                    schaltjahr = 0;

    wochentagzahl = (tag+monat_koeff[monat-1]-schaltjahr+jh_koeff[jh%4] + ja + ja/4 ) %7;

    switch(wochentagzahl){
        case 0: Wochentag = "Sonntag"; break; 
        case 1: Wochentag = "Montag"; break; 
        case 2: Wochentag = "Dienstag"; break; 
        case 3: Wochentag = "Mittwoch"; break; 
        case 4: Wochentag = "Donnerstag"; break; 
        case 5: Wochentag = "Freitag"; break; 
        case 6: Wochentag = "Samstag"; break; 
    }

    printf("Das Datum %d.%d.%d ist ein %s", tag, monat, jahr, Wochentag);

    return 0;
}