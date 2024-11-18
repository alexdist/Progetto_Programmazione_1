/*
	Define generici
*/
#define MAXCOL 50
#define MAXROW 50

/*
	Define da gioco
*/
#define VUOTO 0
#define BUCA  1
#define GIOCATORE 2

/*
	Define direzioni
*/
#define SOPRA  		8
#define SOTTO  		2
#define DESTRA 		6
#define SINISTRA  	4
#define SOPRA_DX 	9
#define SOTTO_DX 	3
#define SOPRA_SX 	7
#define SOTTO_SX 	1

/*
	Variabili di stato del tiro
*/
#define BALL_OUT  0
#define GOOD_SHOT 1
#define	HOLE_IN   2

/*
	Definizione carattere per valore di gioco
*/
const char CHARARRAY[] = {'_', 'O', '*'};