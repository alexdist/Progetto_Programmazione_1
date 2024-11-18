/*
	Traccia: 	Consideriamo un magazzino di prodotti di ferramenta. Ogni prodotto è identificato
				da un codice, dal nome del prodotto, il suo utilizzo (idraulica, muratura, ecc.), la
				quantità di scorta nel magazzino e il costo.
				Si suppone che il numero totale di prodotti sia 20. Scrivere un algoritmo che
				permette di gestire il magazzino.
				Inoltre l'utente può scegliere di effettuare le seguenti operazioni:
					- Visualizzare i dati dei prodotti che sono sotto scorta (numero di prodotti
				minore di 5).
					- Acquisto di un prodotto (controllare se il numero dei prodotti è zero).
					- Dato un settore (idraulica, muratura, ecc.) visualizzare tutti i prodotti
				relativi al settore che sono nel magazzino.
*/
#include "libreria.h"

int main() {
    Prodotto Magazzino[N_PRODOTTI];

    Caricamento_dati_magazzino(Magazzino);

    int scelta = 1;
    int codice;
    char settore[50];

    while(1)
    {
        printf("Menu:\n1. Visualizza prodotti sotto scorta\n2. Acquista prodotto\n3. Visualizza prodotti per settore\n4. Esci\nScelta: ");
        scanf("%d", &scelta);

        switch(scelta)
        {
            case 1:
                Visualizza_sotto_scorta(Magazzino);
                break;
            case 2:
                printf("Inserisci codice prodotto: ");
                scanf("%d", &codice);
                Acquista_prodotto(codice, Magazzino);
                break;
            case 3:
                printf("Inserisci settore: ");
                scanf("%s", settore);
                Visualizza_settore(settore, Magazzino);
                break;
            case 4:
                return 0;
            default:
                printf("Scelta non valida!\n");
                break;
        }
        return 0;
    }
}