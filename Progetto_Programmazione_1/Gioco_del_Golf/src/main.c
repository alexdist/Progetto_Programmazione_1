#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "define.h"
#include "libreria.h"

int main()
{
    srand(time(NULL)); //srand è una funzione che viene utilizzata per iniziallizare il generatore di numeri casuali.

    int Campo[MAXROW][MAXCOL]; //è la matrice che rappresenta il campo da gioco.

    int PunteggiSfidanti[10]; //è un array che memorizza i punteggi ottenuti da 10 giocatori.
    int TentativiSfidanti = 0; //è una variabile che tiene traccia del numero di giocatori che hanno giocato.

    do
    {
        setta_array(*Campo, MAXROW*MAXCOL, VUOTO);

        int PosizioneX = 0, PosizioneY = 0;
        posiziona_giocatore(*Campo, MAXROW*MAXCOL);
        posiziona_buca(*Campo, MAXROW*MAXCOL);

        int Tentativi = 50;
        int DirezioneScelta;
        int EsitoPartita;

        do
        {
            system("cls");
            stampa_campo_grafico(*Campo, MAXROW, MAXCOL);

            printf("Tentativi = %d\n", --Tentativi);

            printf("Inserire riga con lettera d'2"
                   " interesse : ");
            DirezioneScelta = getch() - '0';
            printf("%d\n", DirezioneScelta);

            if(DirezioneScelta > 0 && DirezioneScelta < 10 && DirezioneScelta != 5)
            {
                int LunghezzaTiro, PosizioneFinaleStabile;
                get_dati_di_lancio(&DirezioneScelta, &LunghezzaTiro, &PosizioneFinaleStabile);

                printf("Lunghezza tiro : %d\nDirezione ottenuta : %d\nPosizione Stabile %d\n", LunghezzaTiro, DirezioneScelta, !(PosizioneFinaleStabile == 0));
                EsitoPartita = effettua_tiro(*Campo, MAXROW, MAXCOL, DirezioneScelta, LunghezzaTiro, PosizioneFinaleStabile, &PosizioneX, &PosizioneY);
            }
            else
            {
                printf("Direzione di lancio non valida.\nRiprovare.\n");
            }

            printf("Premere un tasto per continuare...\n");
            getch();
        }
        while(Tentativi > 0 && EsitoPartita != HOLE_IN);


        if(EsitoPartita == HOLE_IN)
        {
            printf("Complimenti hai vinto!\n");
        }
        else
        {
            printf("Hai perso, riprova!\n");
        }

        PunteggiSfidanti[TentativiSfidanti++] = Tentativi;
        printf("Sfidanti rimasti : %d",10 - TentativiSfidanti);
    }
    while(TentativiSfidanti < 10);

    ord_sel_min(PunteggiSfidanti, 10);



    printf("Ecco i punteggi ottenuti dai nostri giocatori in ordine crescente.\n");
    for(int i = 0; i < 10; i ++)
    {
        printf("Punteggio : %d\n", PunteggiSfidanti[i]);
    }
}