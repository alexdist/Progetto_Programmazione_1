/*========================================================
	Insieme di funzioni.
--------------------------------------------------------*/

/*
	La funzione setta_array inizializza tutte le celle di un array differenziate l'una all'altra di un'unità.
	L'offset è il valore da cui inizia il valore della prima cella.
	L'ordine di inserimento numeri è crescente.

	Input/output:
		int *array -> array dì interesse per il settaggio dei valori

	Input:
		int size -> size dell'array
		int valore -> valore da voler mettere a tutte le celle dell'array

*/
void setta_array(int *array, int size, int valore)
{
    int i;
    for(i=0;i<size;i++)
        array[i]=valore;
}

/*
	La funzione stampa_campo_grafico stampa un array con grafica a matrice passato il numero di righe e colonne per parametro.

	Input/output:
		int *array -> campo da gioco da stampare

	Input:
		int R -> righe della matrice
		int C -> colonne della matrice
*/
void stampa_campo_grafico(int *array, int R, int C)
{
    for(int r = 0; r < R; r++)	//Per ogni riga della matrice
    {
        for(int c = 0; c < C; c++)	//Per ogni colonna di ogni riga
            printf("%c", CHARARRAY[array[r*R + c]]);	//Stampa il valore della cella

        printf("\n");	//Alla fine di ogni riga, stampa il carattere "da capo"
    }
}

/*
    La funzione posiziona_buca posiziona casualmente la buca sulla matrice di gioco.

	Input/output:
		int *array -> array dìinteresse per il settaggio dei valori

	Input:
		int size -> size dell'array
*/
void posiziona_buca(int array[], int size)
{
    array[rand()%(size - 1) + 1] = BUCA;
}

/*
    La funzione posiziona_giocatore posiziona il giocatore all'inizio del campo di gioco.
    Questa funzione ha un parametro di input/output:
    -un puntatore all'array "array" di tipo intero.

	Input/output:
		int *array -> campo da gioco

	Input:
		int size -> size dell'array
 */
void posiziona_giocatore(int *array, int size)
{
    array[0] = GIOCATORE;
}

/*
   La funzione get_dati_di_lancio calcola i dati necessari per il tiro del giocatore, come la lunghezza del tiro
   e la posizione finale stabile.

	Input/output:
		int *direzione -> direzione della palla
		int *lunghezza -> lunghezza del tiro
		int *stabilita -> stabilità (0 non stabile, 1 stabile)
*/
void get_dati_di_lancio(int *direzione, int *lunghezza, int *stabilita)
{
    //la lunghezza viene impostata su un numero casuale compreso tra 0 e 5 utilizzando la funzione rand().
    *lunghezza = rand()%6;

    //la stabilità viene impostata su un numero casuale compreso tra 0 e 9.
    *stabilita = rand()%10;

    //viene calcolata una possibilità casuale di spostamento compresa tra 0 e 3.
    int possibilita_spostamento = rand()%4;

    //Possibilità del 50% che la palla non vada nella direzione scelta
    if(possibilita_spostamento == 0 || possibilita_spostamento == 1)
    {
        while((*direzione = rand()%9 + 1) == 5);
    }
        /*
        Se la possibilità di spostamento è 3, vengono controllati i valori casuali
        di una seconda chiamata a rand() per determinare se la direzione deve
        essere spostata verso sinistra o verso destra
        */
    else if(possibilita_spostamento == 3)
    {
        /*
			Vengono effettuati i calcoli necessari per spostare la direzione nella direzione corretta,
			in base alla posizione attuale della direzione.

			Nel primo blocco la direzione scelta è spostata di una verso sinistra.
        */
        if(rand()%2 == 0)
        {
            if(*direzione == SOPRA || *direzione == SOPRA_DX)
            {
                (*direzione)--;
            }
            else if(*direzione == SOPRA_SX || *direzione == SINISTRA)
            {
                (*direzione)-=3;
            }
            else if(*direzione == SOTTO_SX || *direzione == SOTTO)
            {
                (*direzione)++;
            }
            else
                (*direzione)+=3;
        }
        else
        {
            //di una verso la destra
            if(*direzione == SOPRA_SX || *direzione == SOPRA)
            {
                (*direzione)++;
            }
            else if(*direzione == SOPRA_DX || *direzione == DESTRA)
            {
                (*direzione)-=3;
            }
            else if(*direzione == SOTTO_DX || *direzione == SOTTO)
            {
                (*direzione)--;
            }
            else
                (*direzione)+=3;
        }
    }
}

/*
	La funzione effettua_tiro effettua il tiro del giocatore e restituisce l'esito.

	Input/output:
		int *array -> campo da gioco

	Input:
		int R -> righe della matrice
		int C -> colonne della matrice
		int direzione -> direzione della palla
		int lunghezza -> lunghezza del tiro
		int stabilita -> stabilità (0 non stabile, 1 stabile)

	Output:
		int *posizioneX -> Posizione finale della pallina, coordinata x
		int *posizioneY -> Posizione finale della pallina, coordinata y
*/
int effettua_tiro(int *array, int R, int C, int direzione, int lunghezza, int stabilita, int *posizioneX, int *posizioneY)
{
    //La variabile EsitoTiro verrà utilizzata per memorizzare il risultato del tiro. Inizialmente viene impostata a "GOOD_SHOT".
    int EsitoTiro = GOOD_SHOT;

    //Vengono create due variabili locali X e Y che vengono inizializzate con i valori di posizioneX e posizioneY
    int X = *posizioneX, Y = *posizioneY;

    /*
		Controlla se la lunghezza del tiro è maggiore di 0. Se è così procede ad effettuare il tiro.
		Ad esempio, se la direzione è "SOPRA_DX", allora la posizioneX viene incrementata di "lunghezza"
		e posizioneY viene decrementata di "lunghezza".
    */
    if(lunghezza > 0)
    {
        if(direzione == SOPRA_DX)
            *posizioneX += lunghezza, *posizioneY -= lunghezza;
        else if(direzione == DESTRA)
            *posizioneX += lunghezza;
        else if(direzione == SOTTO_DX)
            *posizioneX += lunghezza,  *posizioneY += lunghezza;
        else if(direzione == SOTTO)
            *posizioneY += lunghezza;
        else if(direzione == SOTTO_SX)
            *posizioneX -= lunghezza,  *posizioneY += lunghezza;
        else if(direzione == SINISTRA)
            *posizioneX -= lunghezza;
        else if(direzione == SOPRA_SX)
            *posizioneX -= lunghezza,  *posizioneY -= lunghezza;

        /*
         Se la stabilita è impostata su false, viene generato un indice casuale che rappresenta una variazione
         casuale della posizione del giocatore.
         */
        if(!stabilita)
        {
            const int VARIAZIONE[8][2] = {
                    {1,0},
                    {1,1},
                    {0,1},
                    {-1,+1},
                    {-1,0},
                    {-1,-1},
                    {0,-1},
                    {+1,-1} };
            int indiceSpost = rand()%8;

            (*posizioneX) += VARIAZIONE[indiceSpost][0];
            (*posizioneY) += VARIAZIONE[indiceSpost][1];
        }

        /*
          Viene verificato se la nuova posizione del giocatore è all'interno dei limiti del campo da gioco.
          Se non lo è, allora "EsitoTiro" viene impostato su "BALL_OUT". La posizione del giocatore viene quindi
          impostata a una posizione casuale all'interno del campo.
        */
        if(*posizioneX < 0 || *posizioneX > C || *posizioneY < 0 || *posizioneY > R)
        {
            EsitoTiro = BALL_OUT;

            if(*posizioneX < 0)
            {
                *posizioneX = 0;
                *posizioneY = rand()%R;
            }
            else if(*posizioneX > MAXCOL)
            {
                *posizioneX = C - 1;
                *posizioneY = rand()%R;
            }
            else if(*posizioneY < 0)
            {
                *posizioneY = 0;
                *posizioneX = rand()%C;
            }
            else if(*posizioneY > MAXROW)
            {
                *posizioneY = R - 1;
                *posizioneX = rand()%C;
            }
        }
        /*
         Viene verificato se la nuova posizione del giocatore è su una buca. Se lo è,
         allora "EsitoTiro" viene impostato su "HOLE_IN".
        */
        if(array[(*posizioneY)*C + (*posizioneX)] == BUCA)
        {
            EsitoTiro = HOLE_IN;
        }
        //La vecchia posizione del giocatore viene impostata come "VUOTO" e la nuova posizione viene impostata come "GIOCATORE".
        array[Y*C + X] = VUOTO;
        array[*posizioneY*C + *posizioneX] = GIOCATORE;
    }

    return EsitoTiro;
}

/*
   Questa funzione (algoritmo di ordinamento per selezione di minimo) ordina l'array dei punteggi
   dei giocatori in ordine crescente

 	Input/output:
		int *arr -> campo da gioco
		int n -> size del campo da gioco
*/
void ord_sel_min(int arr[], int n)
{
    int i, j, minIndex, temp;

    for (i = 0; i < n-1; i++)
    {
        minIndex = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

