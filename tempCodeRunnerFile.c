#include <stdio.h>
#define INT_MAX 2147483647

typedef struct{
    int minqm;
    int maxqm;
    int pqm;
    int minpreis;
    int maxpreis;
    int ppreis;
    int mingrundstueck;
    int maxgrundstueck;
    int pgrundstueck;
    int minzimmer;
    int maxzimmer;
    int pzimmer;
    int minbj;
    int maxbj;
    int pbj;
}Praeferenz;

typedef struct{
    int qm;
    int preis;
    int grundstueck;
    int zimmer;
    int baujahr;
    double punktzahl;
}Haus;


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

Haus hausEingeben(){
    Haus haus = {0,0,0,0,0,0,0.0};
    haus.qm = einlesen("Qm-Zahl (Abbruch mit 0): ", 0, INT_MAX);
    if(haus.qm != 0){
    haus.grundstueck = einlesen("Grundstueckgroesse: ", 0, INT_MAX);
    haus.zimmer = einlesen("Zimmerzahl: ", 0, INT_MAX);
    haus.baujahr = einlesen("Baujahr: ", 0, INT_MAX);
    haus.preis = einlesen("Preis: ", 0, INT_MAX);
    }
    return haus;
}

int pruefeHaus(Praeferenz praeferenz, Haus haus){
    if(haus.qm > praeferenz.maxqm || haus.qm<praeferenz.minqm){
        return 0;
    }
    if(haus.grundstueck > praeferenz.maxgrundstueck || haus.grundstueck<praeferenz.mingrundstueck){
        return 0;
    }
    if(haus.zimmer > praeferenz.maxzimmer || haus.zimmer<praeferenz.minzimmer){
        return 0;
    }
    if(haus.baujahr > praeferenz.maxbj || haus.baujahr<praeferenz.minbj){
        return 0;
    }
    if(haus.preis > praeferenz.maxpreis || haus.preis<praeferenz.minpreis){
        return 0;
    }
    return 1;
}

void hausBewerten(Haus haus, Praeferenz praeferenz){
    
}

int haeuserEingeben(Praeferenz praeferenz, Haus haeuser[]){
    int i = 0;
    for(; i<100; i++){
        printf("----Eingabe des %d.Hauses\n", i+1);
        haeuser[i]=hausEingeben();
        if(haeuser[i].qm==0){
            break;
        }
        if(pruefeHaus(praeferenz, haeuser[i])==1){
            printf("....Dieses Haus kommt in Frage\n");
        }
        else{
            printf("\n");
            haeuser[i].punktzahl=-1;
        }
    }
    return i;
}

Praeferenz praeferenzEingeben(){
    Praeferenz praeferenz = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
    praeferenz.minqm = einlesen("Minimale Quadratmeter-Zahl: ", 0, INT_MAX);
    praeferenz.maxqm = einlesen("Maximale Quadratmeter-Zahl: ", praeferenz.minqm+1, INT_MAX);
    praeferenz.pqm = einlesen("Bevorzugt (minimal=0; maximal=1): ", 0, 1);

    praeferenz.mingrundstueck = einlesen("Minimale Grundstuecksgroesse: ", 0, INT_MAX);
    praeferenz.maxgrundstueck = einlesen("Maximale Grundstuecksgroesse: ", praeferenz.mingrundstueck+1, INT_MAX);
    praeferenz.pgrundstueck = einlesen("Bevorzugt (minimal=0; maximal=1): ", 0, 1);

    praeferenz.minzimmer = einlesen("Minimale Zimmerzahl: ", 0, INT_MAX);
    praeferenz.maxzimmer = einlesen("Maximale Zimmerzahl: ", praeferenz.minzimmer+1, INT_MAX);
    praeferenz.pzimmer = einlesen("Bevorzugt (minimal=0; maximal=1): ", 0, 1);

    praeferenz.minbj = einlesen("Minimales Baujahr: ", 0, INT_MAX);
    praeferenz.maxbj = einlesen("Maximales Baujahr: ", praeferenz.minbj+1, INT_MAX);
    praeferenz.pbj = einlesen("Bevorzugt (minimal=0; maximal=1): ", 0, 1);

    praeferenz.minpreis = einlesen("Minimaler Preis: ", 0, INT_MAX);
    praeferenz.maxpreis = einlesen("Maximaler Preis: ", praeferenz.minpreis+1, INT_MAX);
    praeferenz.ppreis = einlesen("Bevorzugt (minimal=0; maximal=1): ", 0, 1);
    printf("\n");
    return praeferenz;
}

void Ausgeben(Haus haus, int nummer, Praeferenz praeferenz){
    printf("Nr: %d\n", nummer);
    printf("qm: %d (%d - %d)\n", haus.qm, praeferenz.minqm, praeferenz.maxqm);
    printf("Grund: %d (%d - %d)\n", haus.grundstueck, praeferenz.mingrundstueck, praeferenz.maxgrundstueck);
    printf("Zimmer: %d (%d - %d)\n", haus.zimmer, praeferenz.minzimmer, praeferenz.maxzimmer);
    printf("Baujahr: %d (%d - %d)\n", haus.baujahr, praeferenz.minbj, praeferenz.maxbj);
    printf("Preis: %d (%d - %d)\n", haus.preis, praeferenz.minpreis, praeferenz.maxpreis);  //===> zur Kennzeichnung der Praeferenz
}



void empfehlungAusgeben(Haus haeuser[], Praeferenz praeferenz,int eingegebeneHauser){
    printf("\nVon den %d eingegebenen Haeusern ist folg. sehr gut geeignet:\n", eingegebeneHauser);
    int max = 0;
    int nummer = -1;
    for(int i = 0; i<eingegebeneHauser; i++){
        if(haeuser[i].punktzahl> max){
            max = haeuser[i].punktzahl;
            nummer = i;
        }
    }
    if(eingegebeneHauser&&nummer!=-1){
        haeuser[nummer].punktzahl=-1;
        Ausgeben(haeuser[nummer], nummer, praeferenz);
    }

    max = 0;
    nummer = -1;
    for(int i = 0; i<eingegebeneHauser; i++){
        if(haeuser[i].punktzahl> max){
            max = haeuser[i].punktzahl;
            nummer = i;
        }
    }
    if(eingegebeneHauser&&nummer!=-1){
        printf("....Auch sind die Haeuser mit folg. Nrn sehr gut geeignet....\n");
        printf("%d", nummer);
    }

}

int main()
{
    Haus haeuser[100];
    Praeferenz praeferenz = praeferenzEingeben();
    int eingegebeneHauser = haeuserEingeben(praeferenz, haeuser);


    
    for(int i = 0; i<eingegebeneHauser;i++){
        if(haeuser[i].punktzahl!=-1){
        double ergebnis = (haeuser[i].qm-praeferenz.minqm)/(double)(praeferenz.maxqm-praeferenz.minqm); //pruefen das nicht durch 0 geteilt wird
        if(praeferenz.pqm == 0)
            haeuser[i].punktzahl = haeuser[i].punktzahl+ (1-ergebnis);
        else
            haeuser[i].punktzahl = haeuser[i].punktzahl+ ergebnis;

        ergebnis = (haeuser[i].grundstueck-praeferenz.mingrundstueck)/(double)(praeferenz.maxgrundstueck-praeferenz.mingrundstueck);
        if(praeferenz.pgrundstueck == 0)
            haeuser[i].punktzahl = haeuser[i].punktzahl+ (1-ergebnis);
        else
            haeuser[i].punktzahl = haeuser[i].punktzahl+ ergebnis;

        ergebnis = (haeuser[i].zimmer-praeferenz.minzimmer)/(double)(praeferenz.maxzimmer-praeferenz.minzimmer);
        if(praeferenz.pzimmer == 0)
            haeuser[i].punktzahl = haeuser[i].punktzahl+ (1-ergebnis);
        else
            haeuser[i].punktzahl = haeuser[i].punktzahl+ ergebnis;

        ergebnis = (haeuser[i].baujahr-praeferenz.minbj)/(double)(praeferenz.maxbj-praeferenz.minbj);
        if(praeferenz.pbj == 0)
            haeuser[i].punktzahl = haeuser[i].punktzahl+ (1-ergebnis);
        else
            haeuser[i].punktzahl = haeuser[i].punktzahl+ ergebnis;

        ergebnis = (haeuser[i].preis-praeferenz.minpreis)/(double)(praeferenz.maxpreis-praeferenz.minpreis);
        if(praeferenz.ppreis == 0)
            haeuser[i].punktzahl = haeuser[i].punktzahl+ (1-ergebnis);
        else
            haeuser[i].punktzahl = haeuser[i].punktzahl+ ergebnis;
    }
    }

    empfehlungAusgeben(haeuser, praeferenz, eingegebeneHauser);

    return 0;
}
