#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double calcul_monnaie(double paye ) 
{
	double paye
	do {
		printf("Erreur\n");
		printf("Veuillez reessayer, Montant insuffisant\n");
		scanf("%d", &payer);
	}
	while ( payer >= paye );
	double monaie = paye - payer
	printf("Paiement effectuer : (%2f)Rs\n", monaie);
	return monaie;
	}
}
int main() {
	printf("La somme a payer est de :\n");
	srand(time(NULL));
	double min =10;
	double max = 100000;
	double paye= rand() % (max - min + 1) + min;
	printf("(%2f)Rs\n",paye)
	
	calcul_monaie(paye);
	return 0;
}
