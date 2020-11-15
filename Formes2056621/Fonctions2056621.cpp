#include "Fonctions2056621.h"
#include <iostream>
#include <ctime>
using namespace std;

void afficherMenu1()											//Affiche les options de forme
{
	cout << "Choisissez la forme: \n";
	cout << "1. Rectangle" << endl;
	cout << "2. Triangle" << endl;
	cout << "3. Carr�" << endl;
	cout << "4. Losange" << endl;
	cout << "5. Quitter" << endl;
}

void afficherMenu2()											//Affiche les options de remplissage
{
	cout << "Choisissez le remplissage: \n";
	cout << "1. Forme pleine" << endl;
	cout << "2. Forme vide" << endl;
	cout << "3. Retour au menu pr�c�dent" << endl;
}

int validerMenu(int choixMenu, int nbOptions)					//Cette fonction sert � afficher le menu voulu, permet � l'utilisateur d'entrer son choix et confirme son choix
{
	int choix;													//Variable pour stocker le choix de l'utilisateur
	

	if (choixMenu == 1)											//Les ifs servent � afficher le bon menu. Le 1 est le menu pour la forme et le 2 est le menu pour le remplissage
	{
		afficherMenu1();										//Appelle la fonction afficherMenu1 pour afficher le menu de choix de forme
		cin >> choix;											//Stocke le choix de l'utilisateur dans la variable choix

		while (choix < 1 || choix > 5)							//Cette boucle permet de d�tecter les erreurs et � l'utilisateur de corriger son erreur. Cette boucle se d�clenche si le choix est un nombre plus grand que 5 ou plus petit que 1.
		{
			cout << "Erreur: l'option entr�e n'est pas valide.\n\n";		//Affiche le message d'erreur � l'utilisateur

			cout << "Choisissez la forme: \n";					//Redemande � l'utilisateur de faire un choix. Je n'ai pas remis la liste des choix puisqu'elle devrait toujours �tre juste en haut.
			cin >> choix;
		}
	}
	if (choixMenu == 2)											//M�me concept que le dernier if, mais pour le menu de remplissage
	{
		afficherMenu2();
		cin >> choix;

		while (choix < 1 || choix > 3)
		{
			cout << "Erreur: l'option entr�e n'est pas valide.\n\n";

			cout << "Choisissez le remplissage: \n";
			cin >> choix;
		}
	}

	cout << "Votre choix: " << choix << endl;					//Affiche son choix � l'utilisateur

	return choix;												//Retourne le contenu de la variable choix au main()
}

void traiterRectangle(int choixRemplissage)						//Cette fonction sert � recueuillir les informations n�c�ssaires � la cr�ation du rectangle et les donnes � la fonction dessinerRectangle
{
	int hauteur;												//D�finition des variables pour stocker la hauteur et la largeur d�sir�e du rectangle
	int largeur;

	cout << "Veuillez entrer la hauteur du rectangle:\n";		//On demande � l'utilisateur d'entrer les dimensions du rectangle
	cin >> hauteur;
	cout << "Veuillez entrer la largeur du rectangle:\n";
	cin >> largeur;

	if (choixRemplissage == 1)									//Les deux ifs servent seulement � afficher � l'utilisateur si son rectangle sera plein ou vide
	{
		cout << "Voici votre rectangle plein de " << hauteur << "x" << largeur << ":\n";		//Affiche � l'utilisateur les param�tres qu'il a choisi pour sa forme
	}
	if (choixRemplissage == 2)
	{
		cout << "Voici votre rectangle vide de " << hauteur << "x" << largeur << ":\n";
	}

	dessinerRectangle(choixRemplissage, hauteur, largeur);		//Appel de la fonction dessinerRectangle avec les param�tres choisis par l'utilisateur

	system("pause");											//Demande � l'utilisateur d'appuyer sur un bouton avant de continuer le programme
	system("cls");												//Efface tout ce qu'il y a d'affich� � la console

}

void traiterCarre(int choixRemplissage)							//Cette fonction est identique � la fonction traiterRectangle, sauf que les variables hauteur et largeur ont �t�s remplac�es par la variable longueur, puisque tout les cot�s sont identiques dans un carr�
{
	int longueur;

	cout << "Veuillez entrer la longueur des cot�s du carr�:\n";
	cin >> longueur;

	if (choixRemplissage == 1)
	{
		cout << "Voici votre carr� plein de " << longueur << "x" << longueur << ":\n";
	}
	if (choixRemplissage == 2)
	{
		cout << "Voici votre carr� vide de " << longueur << "x" << longueur << ":\n";
	}

	dessinerRectangle(choixRemplissage, longueur, longueur);	//On utilise toujours la fonction dessinerRectagle pour dessiner le carr�, mais on lui donne le m�me param�tre pour la hauteur et la largeur pour que tous les cot�s soient �gaux

	system("pause");
	system("cls");
}

void traiterTriangle(int choixRemplissage)
{
	int hauteur;

	cout << "Veuillez entrer la hauteur du triangle:\n";
	cin >> hauteur;

	if (choixRemplissage == 1)
	{
		cout << "Voici votre triangle plein de hauteur " << hauteur << ":\n";
	}
	if (choixRemplissage == 2)
	{
		cout << "Voici votre triangle vide de hauteur " << hauteur << ":\n";
	}

	switch (genererNombreAleatoire(1,4))
	{
	case 1:
		dessinerTriangle1(choixRemplissage, hauteur);
		break;
	case 2:
		dessinerTriangle2(choixRemplissage, hauteur);
		break;
	case 3:
		dessinerTriangle3(choixRemplissage, hauteur);
		break;
	case 4:
		dessinerTriangle4(choixRemplissage, hauteur);
		break;
	}

	system("pause");
	system("cls");

}

void traiterLosange(int choixRemplissage)
{
	int hauteur;

	cout << "Veuillez entrer la hauteur du losange. La hauteur du losange doit �tre un nombre impair:\n";
	cin >> hauteur;

	while (hauteur % 2 != 0)
	{
		cout << "Erreur: le nombre entr� n'est pas un nombre impair.\n\n";

		cout << "Veuillez entrer la hauteur du losange. La hauteur du losange doit �tre un nombre impair:\n";
		cin >> hauteur;
	}

	if (choixRemplissage == 1)
	{
		cout << "Voici votre losange plein de hauteur " << hauteur << ":\n";
	}
	if (choixRemplissage == 2)
	{
		cout << "Voici votre losange vide de hauteur " << hauteur << ":\n";
	}

	dessinerLosange(choixRemplissage, hauteur);

	system("pause");
	system("cls");

}

void dessinerRectangle(int choixRemplissage, int hauteur, int largeur)
{
	char contour = '*';
	char remplissage = '#';
	char vide = ' ';

	if (choixRemplissage == 1)
	{
		cout << largeur * contour << endl;

		for (int i = (hauteur - 2); i > 0; i--)
		{
			cout << contour << (largeur - 2) * remplissage << contour << endl;
		}
	
		cout << largeur * contour << endl;
	}

	if (choixRemplissage == 2)
	{
		cout << largeur * contour << endl;

		for (int i = (hauteur - 2); i > 0; i--)
		{
			cout << contour << (largeur - 2) * vide << contour << endl;
		}

		cout << largeur * contour << endl;
	}
}

void dessinerTriangle1(int choixRemplissage, int hauteur)
{
	char contour = '*';
	char remplissage = '#';
	char vide = ' ';
	int i = 1;


	if (choixRemplissage == 1)
	{
		while (i <= hauteur)
		{
			if (i <= 2 || i == hauteur)
			{
				cout << i * contour << endl;
			}
			if (i > 2 && i < hauteur)
			{
				cout << contour << (i - 2) * remplissage << contour << endl;
			}
			i++;
		}
	}

	if (choixRemplissage == 2)
	{
		while (i <= hauteur)
		{
			if (i <= 2 || i == hauteur)
			{
				cout << i * contour << endl;
			}
			if (i > 2 && i < hauteur)
			{
				cout << contour << (i - 2) * vide << contour << endl;
			}
			i++;
		}
	}
}

void dessinerTriangle2(int choixRemplissage, int hauteur)
{
	char contour = '*';
	char remplissage = '#';
	char vide = ' ';
	int i = hauteur;


	if (choixRemplissage == 1)
	{
		while (i >= 1)
		{
			if (i <= 2 || i == hauteur)
			{
				cout << i * contour << endl;
			}
			if (i > 2 && i < hauteur)
			{
				cout << contour << (i - 2) * remplissage << contour << endl;
			}
			i--;
		}
	}

	if (choixRemplissage == 2)
	{
		while (i >= 1)
		{
			if (i <= 2 || i == hauteur)
			{
				cout << i * contour << endl;
			}
			if (i > 2 && i < hauteur)
			{
				cout << contour << (i - 2) * vide << contour << endl;
			}
			i--;
		}
	}
}

void dessinerTriangle3(int choixRemplissage, int hauteur)
{
	char contour = '*';
	char remplissage = '#';
	char vide = ' ';
	int i = hauteur;


	if (choixRemplissage == 1)
	{
		while (i >= 1)
		{
			cout << (hauteur - i) * vide << endl;
			if (i <= 2 || i == hauteur)
			{
				cout << i * contour << endl;
			}
			if (i > 2 && i < hauteur)
			{
				cout << contour << (i - 2) * remplissage << contour << endl;
			}
			i--;
		}
	}

	if (choixRemplissage == 2)
	{
		while (i >= 1)
		{
			cout << (hauteur - i) * vide << endl;
			if (i <= 2 || i == hauteur)
			{
				cout << i * contour << endl;
			}
			if (i > 2 && i < hauteur)
			{
				cout << contour << (i - 2) * vide << contour << endl;
			}
			i--;
		}
	}
}

void dessinerTriangle4(int choixRemplissage, int hauteur)
{
	char contour = '*';
	char remplissage = '#';
	char vide = ' ';
	int i = 1;


	if (choixRemplissage == 1)
	{
		while (i <= hauteur)
		{
			cout << (hauteur - i) * vide << endl;
			if (i <= 2 || i == hauteur)
			{
				cout << i * contour << endl;
			}
			if (i > 2 && i < hauteur)
			{
				cout << contour << (i - 2) * remplissage << contour << endl;
			}
			i++;
		}
	}

	if (choixRemplissage == 2)
	{
		while (i <= hauteur)
		{
			cout << (hauteur - i) * vide << endl;
			if (i <= 2 || i == hauteur)
			{
				cout << i * contour << endl;
			}
			if (i > 2 && i < hauteur)
			{
				cout << contour << (i - 2) * vide << contour << endl;
			}
			i++;
		}
	}
}

void dessinerLosange(int choixRemplissage, int hauteur)
{
	char contour = '*';
	char remplissage = '#';
	char vide = ' ';
	int i = hauteur;
	int compteur = 1;
	int largeur = 1;

	if (choixRemplissage == 1)
	{
		while (i >= 1)
		{
			cout << ((i - compteur) / 2) * vide << endl;

			cout << contour;
			if (largeur < 2)
			{
				cout << (largeur - 2) * remplissage;
			}
			cout << contour;


	
			if (compteur > ((hauteur - 1) / 2))
			{
				compteur--;
			}
			if (compteur <= ((hauteur - 1) / 2))
			{
				compteur++;
			}
			if (largeur > ((hauteur - 1) / 2))
			{
				largeur = largeur - 2;
			}
			if (largeur <= ((hauteur - 1) / 2))
			{
				largeur = largeur + 2;
			}
		}
	}

	if (choixRemplissage == 2)
	{
		while (i >= 1)
		{
			cout << ((i - compteur) / 2) * vide << endl;

			cout << contour;
			if (largeur < 2)
			{
				cout << (largeur - 2) * remplissage;
			}
			cout << contour;



			if (compteur > ((hauteur - 1) / 2))
			{
				compteur--;
			}
			if (compteur <= ((hauteur - 1) / 2))
			{
				compteur++;
			}
			if (largeur > ((hauteur - 1) / 2))
			{
				largeur = largeur - 2;
			}
			if (largeur <= ((hauteur - 1) / 2))
			{
				largeur = largeur + 2;
			}
		}
	}
}

int genererNombreAleatoire(int min, int max)
{
	return rand()% (max - min + 1) + min;
}
