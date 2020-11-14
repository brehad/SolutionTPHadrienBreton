#include "Fonctions2056621.h"
#include <iostream>
using namespace std;

void afficherMenu1()
{
	cout << "Choisissez la forme: \n";
	cout << "1. Rectangle" << endl;
	cout << "2. Triangle" << endl;
	cout << "3. Carré" << endl;
	cout << "4. Losange" << endl;
	cout << "5. Quitter" << endl;
}

void afficherMenu2()
{
	cout << "Choisissez le remplissage: \n";
	cout << "1. Forme pleine" << endl;
	cout << "2. Forme vide" << endl;
	cout << "3. Retour au menu précédent" << endl;
}

int validerMenu(int choixMenu, int nbOptions)
{
	int choix;
	
	cin >> choix;

	if (choixMenu == 1)
	{
		while (choix < 1 || choix > 5)
		{
			cout << "Erreur: l'option entrée n'est pas valide.\n\n";

			cout << "Choisissez la forme: \n";
			cin >> choix;
		}
	}
	if (choixMenu == 2)
	{
		while (choix < 1 || choix > 3)
		{
			cout << "Erreur: l'option entrée n'est pas valide.\n\n";

			cout << "Choisissez le remplissage: \n";
			cin >> choix;
		}
	}

	cout << "Votre choix: " << choix << endl;

	return choix;
}
