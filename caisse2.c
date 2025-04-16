#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure pour représenter le stock de billets et pièces
typedef struct {
    int billets_2000;
    int billets_1000;
    int billets_500;
    int billets_200;
    int billets_100;
    int billets_50;
    int billets_25;
    int pieces_20;
    int pieces_10;
    int pieces_5;
    int pieces_1;
    int pieces_50_sous;
    int pieces_20_sous;
    int pieces_5_sous;
} Stock;

// Fonction pour afficher l'état du stock
void afficher_stock(Stock *stock) {
    printf("\nÉtat du stock de la caisse :\n");
    printf("Billets de 2000 Rs : %d\n", stock->billets_2000);
    printf("Billets de 1000 Rs : %d\n", stock->billets_1000);
    printf("Billets de 500 Rs : %d\n", stock->billets_500);
    printf("Billets de 200 Rs : %d\n", stock->billets_200);
    printf("Billets de 100 Rs : %d\n", stock->billets_100);
    printf("Billets de 50 Rs : %d\n", stock->billets_50);
    printf("Billets de 25 Rs : %d\n", stock->billets_25);
    printf("Pièces de 20 Rs : %d\n", stock->pieces_20);
    printf("Pièces de 10 Rs : %d\n", stock->pieces_10);
    printf("Pièces de 5 Rs : %d\n", stock->pieces_5);
    printf("Pièces de 1 Rs : %d\n", stock->pieces_1);
    printf("Pièces de 50 sous : %d\n", stock->pieces_50_sous);
    printf("Pièces de 20 sous : %d\n", stock->pieces_20_sous);
    printf("Pièces de 5 sous : %d\n", stock->pieces_5_sous);
}

// Fonction pour calculer la monnaie à rendre
int rendre_monnaie(double monnaie, Stock *stock) {
    int total_monnaie = (int)(monnaie * 100); // Conversion en centimes

    // Rendre la monnaie en utilisant les billets et pièces disponibles
    while (total_monnaie >= 200000 && stock->billets_2000 > 0) {
        total_monnaie -= 200000;
        stock->billets_2000--;
    }
    while (total_monnaie >= 100000 && stock->billets_1000 > 0) {
        total_monnaie -= 100000;
        stock->billets_1000--;
    }
    while (total_monnaie >= 50000 && stock->billets_500 > 0) {
        total_monnaie -= 50000;
        stock->billets_500--;
    }
    while (total_monnaie >= 20000 && stock->billets_200 > 0) {
        total_monnaie -= 20000;
        stock->billets_200--;
    }
    while (total_monnaie >= 10000 && stock->billets_100 > 0) {
        total_monnaie -= 10000;
        stock->billets_100--;
    }
    while (total_monnaie >= 5000 && stock->billets_50 > 0) {
        total_monnaie -= 5000;
        stock->billets_50--;
    }
    while (total_monnaie >= 2500 && stock->billets_25 > 0) {
        total_monnaie -= 2500;
        stock->billets_25--;
    }
    while (total_monnaie >= 2000 && stock->pieces_20 > 0) {
        total_monnaie -= 2000;
        stock->pieces_20--;
    }
    while (total_monnaie >= 1000 && stock->pieces_10 > 0) {
        total_monnaie -= 1000;
        stock->pieces_10--;
    }
    while (total_monnaie >= 500 && stock->pieces_5 > 0) {
        total_monnaie -= 500;
        stock->pieces_5--;
    }
    while (total_monnaie >= 100 && stock->pieces_1 > 0) {
        total_monnaie -= 100;
        stock->pieces_1--;
    }
    while (total_monnaie >= 50 && stock->pieces_50_sous > 0) {
        total_monnaie -= 50;
        stock->pieces_50_sous--;
    }
    while (total_monnaie >= 20 && stock->pieces_20_sous > 0) {
        total_monnaie -= 20;
        stock->pieces_20_sous--;
    }
    while (total_monnaie >= 5 && stock->pieces_5_sous > 0) {
        total_monnaie -= 5;
        stock->pieces_5_sous--;
    }

    // Si la monnaie ne peut pas être rendue complètement
    if (total_monnaie > 0) {
        printf("\nArgent insuffisant dans la caisse pour rendre %.2f Rs.\n", monnaie);
        return 0; // Échec
    }

    return 1; // Succès
}

int main() {
    // Initialisation du stock
    Stock stock = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}; // Exemple de stock initial

    srand(time(NULL));
    int continuer = 1;

    while (continuer) {
        double paye = 100 + (rand() % 1000); // Montant à payer entre 100 et 1000 Rs
        printf("\nLa somme à payer est de : %.2f Rs\n", paye);

        double payer;
        printf("Veuillez entrer le montant de votre paiement : ");
        scanf("%lf", &payer);

        while (payer < paye) {
            printf("Montant insuffisant. Veuillez réessayer : ");
            scanf("%lf", &payer);
        }

        double monnaie = payer - paye;
        printf("Monnaie à rendre : %.2f Rs\n", monnaie);

        // Essaye de rendre la monnaie
        if (!rendre_monnaie(monnaie, &stock)) {
            printf("\nÉchec de la transaction. Souhaitez-vous fermer la caisse (1) ou la remplir (2) ? ");
            int choix;
            scanf("%d", &choix);
            if (choix == 1) {
                printf("Fermeture de la caisse.\n");
                break;
            } else if (choix == 2) {
                printf("Remplissage de la caisse...\n");
                stock = (Stock){10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}; // Réinitialise le stock
            }
        } else {
            printf("Transaction réussie.\n");
        }

        afficher_stock(&stock);

        printf("\nSouhaitez-vous effectuer une autre transaction ? (1 pour oui, 0 pour non) ");
        scanf("%d", &continuer);
    }

    printf("Fin du programme.\n");
    return 0;
}
