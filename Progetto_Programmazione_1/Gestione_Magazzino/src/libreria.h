/*========================================================
	Insieme di funzioni e struct.
	Scopo : Strutturazione struttura dati e gestione funzioni
			per la manipolazione dati magazzino.
--------------------------------------------------------*/

/*
	Struttura dati per la popolazione e manipolazione dei dati del magazzino.
	Per ogni prodotto ne viene memorizzato:
	Il suo codice, il nome, Il tipo di utilizzo (idraulico,muratura ecc.)
	La quantità in magazzino e il suo costo.
*/
#include <string.h>
#include <stdio.h>
#define N_PRODOTTI 20
#define MIN_SCORTA 5
struct{
    int Codice;
    char Nome[50];
    char Utilizzo[50];
    int Quantita;
    float Costo;
}typedef Prodotto;


/*
    La seguente funzione serve a popolare l'array di prodotti di 20 celle.
*/
void Caricamento_dati_magazzino(Prodotto Magazzino[])
{
    Magazzino[0].Codice = 1001;
    strcpy(Magazzino[0].Nome, "Rubinetti");
    strcpy(Magazzino[0].Utilizzo, "Idraulica");
    Magazzino[0].Quantita = 5;
    Magazzino[0].Costo = 100.00;

    Magazzino[1].Codice = 1002;
    strcpy(Magazzino[1].Nome, "Tubi");
    strcpy(Magazzino[1].Utilizzo, "Idraulica");
    Magazzino[1].Quantita = 3;
    Magazzino[1].Costo = 15.00;

    Magazzino[2].Codice = 1003;
    strcpy(Magazzino[2].Nome, "Connettori");
    strcpy(Magazzino[2].Utilizzo, "Idraulica");
    Magazzino[2].Quantita = 20;
    Magazzino[2].Costo = 5.00;

    Magazzino[3].Codice = 1004;
    strcpy(Magazzino[3].Nome, "Valvole");
    strcpy(Magazzino[3].Utilizzo, "Idraulica");
    Magazzino[3].Quantita = 8;
    Magazzino[3].Costo = 2.00;

    Magazzino[4].Codice = 1005;
    strcpy(Magazzino[4].Nome, "Guarnizioni");
    strcpy(Magazzino[4].Utilizzo, "Idraulica");
    Magazzino[4].Quantita = 15;
    Magazzino[4].Costo = 0.50;

    Magazzino[5].Codice = 1006;
    strcpy(Magazzino[5].Nome, "Martelli");
    strcpy(Magazzino[5].Utilizzo, "Muratura");
    Magazzino[5].Quantita = 25;
    Magazzino[5].Costo = 25.00;

    Magazzino[6].Codice = 1007;
    strcpy(Magazzino[6].Nome, "Scalpelli");
    strcpy(Magazzino[6].Utilizzo, "Muratura");
    Magazzino[6].Quantita = 4;
    Magazzino[6].Costo = 25.00;

    Magazzino[7].Codice = 1008;
    strcpy(Magazzino[7].Nome, "Cazzuole");
    strcpy(Magazzino[7].Utilizzo, "Muratura");
    Magazzino[7].Quantita = 10;
    Magazzino[7].Costo = 10.00;

    Magazzino[8].Codice = 1009;
    strcpy(Magazzino[8].Nome, "Livelle");
    strcpy(Magazzino[8].Utilizzo, "Muratura");
    Magazzino[8].Quantita = 15;
    Magazzino[8].Costo = 8.00;

    Magazzino[9].Codice = 1010;
    strcpy(Magazzino[9].Nome, "Trapani");
    strcpy(Magazzino[9].Utilizzo, "Muratura");
    Magazzino[9].Quantita= 0;
    Magazzino[9].Costo = 80.00;

    Magazzino[10].Codice = 1011;
    strcpy(Magazzino[10].Nome, "Sega a mano");
    strcpy(Magazzino[10].Utilizzo, "Muratura");
    Magazzino[10].Quantita= 8;
    Magazzino[10].Costo = 15.00;

    Magazzino[11].Codice = 1012;
    strcpy(Magazzino[11].Nome, "Rulli");
    strcpy(Magazzino[11].Utilizzo, "Verniciatura");
    Magazzino[11].Quantita= 5;
    Magazzino[11].Costo = 6.00;

    Magazzino[12].Codice = 1013;
    strcpy(Magazzino[12].Nome, "Carta Abrasiva");
    strcpy(Magazzino[12].Utilizzo, "Verniciatura");
    Magazzino[12].Quantita= 20;
    Magazzino[12].Costo = 0.50;

    Magazzino[13].Codice = 1014;
    strcpy(Magazzino[13].Nome, "Pennelli");
    strcpy(Magazzino[13].Utilizzo, "Verniciatura");
    Magazzino[13].Quantita= 1;
    Magazzino[13].Costo = 4.00;

    Magazzino[14].Codice = 1015;
    strcpy(Magazzino[14].Nome, "Mascherine respiratorie");
    strcpy(Magazzino[14].Utilizzo, "Verniciatura");
    Magazzino[14].Quantita= 10;
    Magazzino[14].Costo = 1.00;

    Magazzino[15].Codice = 1016;
    strcpy(Magazzino[15].Nome, "Vernice per legno");
    strcpy(Magazzino[15].Utilizzo, "Verniciatura");
    Magazzino[15].Quantita= 8;
    Magazzino[15].Costo = 20.00;

    Magazzino[16].Codice = 1017;
    strcpy(Magazzino[16].Nome, "Vernice per barche");
    strcpy(Magazzino[16].Utilizzo, "Verniciatura");
    Magazzino[16].Quantita= 50;
    Magazzino[16].Costo = 30.00;

    Magazzino[17].Codice = 1018;
    strcpy(Magazzino[17].Nome, "Vernice per metalli");
    strcpy(Magazzino[17].Utilizzo, "Verniciatura");
    Magazzino[17].Quantita= 100;
    Magazzino[17].Costo = 20.00;

    Magazzino[18].Codice = 1019;
    strcpy(Magazzino[18].Nome, "Pittura per esterni");
    strcpy(Magazzino[18].Utilizzo, "Verniciatura");
    Magazzino[18].Quantita= 15;
    Magazzino[18].Costo = 60.00;

    Magazzino[19].Codice = 1020;
    strcpy(Magazzino[19].Nome, "Pittura per interni");
    strcpy(Magazzino[19].Utilizzo, "Verniciatura");
    Magazzino[19].Quantita= 30;
    Magazzino[19].Costo = 35.00;
}

/*
	La funzione visualizza_sotto_scorta serve a visualizzare tutti i prodotto in magazzino sotto scorta
	(quantità < 5).

    Input:
        variabile Magazzino di tipo "Prodotto"->array di struct
*/
void Visualizza_sotto_scorta(Prodotto Magazzino[])
{
    printf("Prodotti sotto scorta:\n");

    //  ciclo for che itera attraverso gli elementi dell'array Magazzino.
    for(int i = 0; i < N_PRODOTTI; i++)
    {
    //  verifica se la quantità del prodotto corrente è inferiore a una certa quantità minima, specificata da MIN_SCORTA.
        if(Magazzino[i].Quantita < MIN_SCORTA)
        {
            printf("Codice: %d, Nome: %s, Utilizzo: %s, Quantita: %d, Costo: %0.2f\n", Magazzino[i].Codice, Magazzino[i].Nome, Magazzino[i].Utilizzo, Magazzino[i].Quantita, Magazzino[i].Costo);
        }
    }
}


/*
    Passata alla funzione acquista_prodotto il codice di un prodotto, questa funzione cerca il prodotto, verifica la sua quantità
	e se c'è disponibilità decrementa la quantità.

    Input:
        int Codice -> codice del prodotto.
        variabile Magazzino di tipo "Prodotto"-> array di struct.

*/
void Acquista_prodotto(int Codice, Prodotto Magazzino[])
{
    for(int i = 0; i < N_PRODOTTI; i++)
    {
        //verifica se il codice dell'i-esimo prodotto è uguale al codice inserito dall'utente.
        if(Magazzino[i].Codice == Codice)
        {
            // verifica se la quantità del prodotto in magazzino se è maggiore di zero.
            if(Magazzino[i].Quantita > 0)
            {
                //decrementa di una unità il prodotto.
                Magazzino[i].Quantita--;
                printf("Prodotto acquistato con successo!\n");
                return;
            }
            else
            {
                printf("Prodotto esaurito!\n");
                return;
            }
        }
    }
    printf("Prodotto non trovato!\n");
}

/*
	Passato un determinato settore, visualizzare tutti i prodotti associati.
    Input:
        char settore[] -> array che identifica il settore ("Idraulica", "Muratura", "Verniciatura",ecc..)
        variabile Magazzino di tipo "Prodotto"-> array di struct.
*/
void Visualizza_settore(char settore[], Prodotto Magazzino[])
{
    printf("Prodotti del settore %s:\n", settore);

    for(int i = 0; i < N_PRODOTTI; i++)
    {
        if (strcmp(Magazzino[i].Utilizzo, settore) == 0)
        {
            printf("Codice: %d, Nome: %s, Utilizzo: %s, Quantita': %d, Costo: %0.2f\n", Magazzino[i].Codice, Magazzino[i].Nome, Magazzino[i].Utilizzo, Magazzino[i].Quantita, Magazzino[i].Costo);
        }
    }
}