#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main()
{
	// Dichiarazione delle variabili
	int n_cin, i, tot = 0, cella, stato = 0, j;
	char str[100], spostamento, leggi, scrivi;

	// Chiedere l'input per il numero di stati, finché non viene inserito un valore valido
	do {
		printf("Inserisci il numero degli stati: ");
		scanf("%d", &n_cin);
	} while (n_cin < 1);

	// Dichiarazione dell'array per il numero di input per ogni stato
	int pos[n_cin];

	// Chiedere l'input per il numero di input per ogni stato, finché non viene inserito un valore valido
	for (i = 0; i < n_cin; i++) {
		do {
			printf("Inserisci il numero di input per lo stato '%d': ", i);
			scanf("%d", &pos[i]);
		} while (pos[i] < 1);
		tot += pos[i];
	}

	// Dichiarazione delle matrice che conterrà i comandi
	char comandi[tot][10];

	// Chiedere l'input per i comandi
	printf("\nInserisci i comandi (stato-leggi-scrivi-posizione):\n");
	for (i = 0; i < tot; i++) {
		scanf("%s", comandi[i]);
	}

	// Pulire lo schermo e chiedere l'input per la stringa
	system("cls");
	printf("Inserisci la stringa tra due #:\n");
	scanf("%s", str);

	// Pulire lo schermo e mostrare la stringa
	system("cls");
	printf("%s\n\n", str);

	// Chiedere l'input per la posizione di partenza, finché non viene inserito un valore valido
	do {
		printf("Inserisci il numero di cella da cui partire: ");
		scanf("%d", &cella);
	} while (cella < 1 || cella > strlen(str) - 1);

	// Mostrare la stringa con la posizione di partenza
	system("cls");
	printf("%s\n", str);
	for (i = 0; i < cella; i++) {
		printf(" ");
	}
	printf("|");

	// Loop che esegue il funzionamento dell'automa
		do{
			// Sleep per 100 millisecondi
			Sleep(250);

			// Variabile tot inizializzata a 0
			tot=0;

			// Loop che calcola la somma di tutti i valori in pos[] fino all'indice stato corrente
			for(i=0; i<=stato ; i++)
			{
				tot+=pos[i];
			}

			// Loop che esegue un'azione basata sui valori in comandi[]
			for(i=pos[stato] ; tot>tot-i ; i--)
			{
				// Verifica se il valore in comandi[tot-i][2] è uguale a quello in str[cella]
				if(comandi[tot-i][2] == str[cella])
				{
					// Sostituisce il valore in str[cella] con quello in comandi[tot-i][4]
					str[cella]=comandi[tot-i][4];

					// Pulisce lo schermo e stampa il contenuto di str[] con un cursore che indica la posizione corrente
					system("cls");
					printf("%s\n",str);
					for(j=0;j<cella;j++)
					{
						printf(" ");
					}
					printf("|");

					// Verifica se l'azione successiva è 'D' (spostamento a destra) o 'S' (spostamento a sinistra)
					if(comandi[tot-i][6] == 'D')
					{
						// Incrementa la posizione corrente e cambia lo stato corrente in base a comandi[tot-i][0]
						cella++;
						stato=comandi[tot-i][0]-48;
						break;
					}
					else if(comandi[tot-i][6] == 'S')
					{
						// Decrementa la posizione corrente e cambia lo stato corrente in base a comandi[tot-i][0]
						cella--;
						stato=comandi[tot-i][0]-48;
						break;
					}
					else
					{
						// Imposta spostamento su 'F' per interrompere il ciclo
						spostamento='F';
						break;
					}
				}
			}
		} while(spostamento!='F'); // Continua il ciclo fino a quando spostamento è diverso da 'F'


		// Pulisce il terminale
		system("cls");

			// Stampa la stringa str
				printf("%s\n",str);

				// Stampa una serie di spazi bianchi in base alla variabile cella
				for(i=0;i<cella;i++)
				{
    			printf(" ");
			}

		// Stampa il carattere '|' sulla stessa riga della stringa str
		printf("|\n\n");

		// Attende l'input dell'utente prima di continuare
		system("pause");
		}
