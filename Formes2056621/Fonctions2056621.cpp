#include "Fonctions2056621.h"
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

void afficherMenu1()											//Affiche les options de forme
{
	cout << "Choisissez la forme: \n";
	cout << "1. Rectangle" << endl;
	cout << "2. Triangle" << endl;
	cout << "3. Carré" << endl;
	cout << "4. Losange" << endl;
	cout << "5. Quitter" << endl;
}

void afficherMenu2()											//Affiche les options de remplissage
{
	cout << "Choisissez le remplissage: \n";
	cout << "1. Forme pleine" << endl;
	cout << "2. Forme vide" << endl;
	cout << "3. Retour au menu précédent" << endl;
}

int validerMenu(int choixMenu, int nbOptions)					//Cette fonction sert à afficher le menu voulu, permet à l'utilisateur d'entrer son choix et confirme son choix
{
	int choix;													//Variable pour stocker le choix de l'utilisateur
	

	if (choixMenu == 1)											//Les ifs servent à afficher le bon menu. Le 1 est le menu pour la forme et le 2 est le menu pour le remplissage
	{
		afficherMenu1();										//Appelle la fonction afficherMenu1 pour afficher le menu de choix de forme
		cin >> choix;											//Stocke le choix de l'utilisateur dans la variable choix

		while (choix < 1 || choix > 5)							//Cette boucle permet de détecter les erreurs et à l'utilisateur de corriger son erreur. Cette boucle se déclenche si le choix est un nombre plus grand que 5 ou plus petit que 1.
		{
			cout << "Erreur: l'option entrée n'est pas valide.\n\n";		//Affiche le message d'erreur à l'utilisateur

			cout << "Choisissez la forme: \n";					//Redemande à l'utilisateur de faire un choix. Je n'ai pas remis la liste des choix puisqu'elle devrait toujours être juste en haut.
			cin >> choix;

			cout << "Votre choix: " << choix << endl;					//Affiche son choix à l'utilisateur
		}
	}
	if (choixMenu == 2)											//Même concept que le dernier if, mais pour le menu de remplissage
	{
		afficherMenu2();
		cin >> choix;

		while (choix < 1 || choix > 3)
		{
			cout << "Erreur: l'option entrée n'est pas valide.\n\n";

			cout << "Choisissez le remplissage: \n";
			cin >> choix;

			cout << "Votre choix: " << choix << endl;					//Affiche son choix à l'utilisateur
		}
	}

	return choix;												//Retourne le contenu de la variable choix au main()
}

void traiterRectangle(int choixRemplissage)						//Cette fonction sert à recueuillir les informations nécéssaires à la création du rectangle et les donnes à la fonction dessinerRectangle
{
	int hauteur;												//Définition des variables pour stocker la hauteur et la largeur désirée du rectangle
	int largeur;

	cout << "Veuillez entrer la hauteur du rectangle:\n";		//On demande à l'utilisateur d'entrer les dimensions du rectangle
	cin >> hauteur;
	cout << "Veuillez entrer la largeur du rectangle:\n";
	cin >> largeur;

	if (choixRemplissage == 1)									//Les deux ifs servent seulement à afficher à l'utilisateur si son rectangle sera plein ou vide
	{
		cout << "Voici votre rectangle plein de " << hauteur << "x" << largeur << ":\n";		//Affiche à l'utilisateur les paramètres qu'il a choisi pour sa forme
	}
	if (choixRemplissage == 2)
	{
		cout << "Voici votre rectangle vide de " << hauteur << "x" << largeur << ":\n";
	}

	dessinerRectangle(choixRemplissage, hauteur, largeur);		//Appel de la fonction dessinerRectangle avec les paramètres choisis par l'utilisateur

	system("pause");											//Demande à l'utilisateur d'appuyer sur un bouton avant de continuer le programme
	system("cls");												//Efface tout ce qu'il y a d'affiché à la console

}

void traiterCarre(int choixRemplissage)							//Cette fonction est identique à la fonction traiterRectangle, sauf que les variables hauteur et largeur ont étés remplacées par la variable longueur, puisque tout les cotés sont identiques dans un carré
{
	int longueur;

	cout << "Veuillez entrer la longueur des cotés du carré:\n";
	cin >> longueur;

	if (choixRemplissage == 1)
	{
		cout << "Voici votre carré plein de " << longueur << "x" << longueur << ":\n";
	}
	if (choixRemplissage == 2)
	{
		cout << "Voici votre carré vide de " << longueur << "x" << longueur << ":\n";
	}

	dessinerRectangle(choixRemplissage, longueur, longueur);	//On utilise toujours la fonction dessinerRectagle pour dessiner le carré, mais on lui donne le même paramètre pour la hauteur et la largeur pour que tous les cotés soient égaux

	system("pause");
	system("cls");
}

void traiterTriangle(int choixRemplissage)						//Cette fonction sert à recueuillir les informations pour le triangle et appelle la fonction dessinerTriangle
{
	int hauteur;												//Déclaration de la variable hauteur

	cout << "Veuillez entrer la hauteur du triangle:\n";		//On demande à l'utilisateur d'entrer la hauteur du triangle
	cin >> hauteur;

	if (choixRemplissage == 1)									//Les deux ifs servent à afficher une message légèrement différent dépendant de quel sorte de remplissage l'utilisateur à choisi
	{
		cout << "Voici votre triangle plein de hauteur " << hauteur << ":\n";
	}
	if (choixRemplissage == 2)
	{
		cout << "Voici votre triangle vide de hauteur " << hauteur << ":\n";
	}

	switch (genererNombreAleatoire(1,4))						//Appelle la fonction genererNombre aleatoire pour obtenir un nombre entre 1 et 4. Le switch appelle une fonction différente pour chacun des 4 nombres possibles
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

	system("pause");											//Demande à l'utilisateur d'appuyer sur un bouton avant de continuer le programme
	system("cls");												//Efface tout ce qu'il y a d'affiché à la console

}

void traiterLosange(int choixRemplissage)						//Sert à recueuillir les informations pour le losange et apelle la fonction dessinerLosange
{
	int hauteur;												//Ça commence à être redondant, donc je crois que je vais arrêter de faire des commentaires sur les lignes qui sont identiques

	cout << "Veuillez entrer la hauteur du losange. La hauteur du losange doit être un nombre impair:\n";
	cin >> hauteur;

	while (hauteur % 2 != 1)									//S'exécute seulement si le nombre entré par l'utilisateur n'est pas impair. Cette boucle s'exécute tant que l'utilisateur n'a pas entré un nombre impair
	{
		cout << "Erreur: le nombre entré n'est pas un nombre impair.\n\n";		//Affiche un message d'erreur

		cout << "Veuillez entrer la hauteur du losange. La hauteur du losange doit être un nombre impair:\n";	//Redemande à l'utilisateur d'entrer un nombre impair
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

	dessinerLosange(choixRemplissage, hauteur);					//Appelle la fonction dessinerLosange

	system("pause");
	system("cls");

}

void dessinerRectangle(int choixRemplissage, int hauteur, int largeur)			//Cette fonction sert à dessiner les carrés et les rectangles
{
	char contour = '*';					//J'ai mis les caractères dans des variables pour qu'ils soient plus faciles à changer, si nécéssaire
	char remplissage = '#';
	char vide = ' ';

	if (hauteur == largeur)								//Ce if sert à détecter si la forme est un carré. Je fais la différence entre le carré et le rectangle parce que j'ai inséré des espaces entre chaquees caractères du carré pour qu'il apparaisse correctement à l'écran
	{
		if (choixRemplissage == 1)						//Ce if sert à détecter si la forme doit être pleine, la seule différence entre vide et plein est qu'il y a la variable remplissage dans un et la variable vide dans l'autre.
		{
			for (int i = 0; i < largeur; i++)			//Cette boucle sert à afficher la première ligne, composée uniquement d'* (et d'espaces pour éloigner les caractères puisqu'il s'agit du carré)
			{
				cout << contour << vide;
			}
			cout << endl;								//Le endl est séparé de la boucle précédente, même s'il est pour la même ligne, pour ne pas qu'il y ait un saut de ligne à chaque itération de cette dernière

			for (int i = (hauteur - 2); i > 0; i--)		//Cette boucle sert à afficher toutes les lignes sauf la première et la dernière, puisqu'elles sont toutes identiques
			{
				cout << contour << vide;				//Affiche le * qui commence la ligne (et un espace parce que c'est un carré)

				for (int i = 0; i < largeur - 2; i++)	//Cette boucle sert à afficher le remplissage de la forme, dans ce cas, il s'agit de #
				{
					cout << remplissage << vide;		//Affiche un # (suivit d'un espace parce que carré)
				}

				cout << contour << endl;				//Affiche le dernier * de la ligne et fait un saut de ligne
			}

			for (int i = 0; i < largeur; i++)			//C'est la même boucle que la première. Cette fois, elle serta à afficher la dernière ligne
			{
				cout << contour << vide;
			}
			cout << endl;
		}

		if (choixRemplissage == 2)						//La seule différence est le vide qui remplace le remplissage, donc je ne referais pas les commentaires
		{
			for (int i = 0; i < largeur; i++)
			{
				cout << contour << vide;
			}

			cout << endl;

			for (int i = (hauteur - 2); i > 0; i--)
			{
				cout << contour << vide;

				for (int i = 0; i < largeur - 2; i++)
				{
					cout << vide << vide;
				}

				cout << contour << endl;
			}

			for (int i = 0; i < largeur; i++)
			{
				cout << contour << vide;
			}

			cout << endl;
		}
	}
	else										//Si li premier if était faux (donc la forme est un rectangle), cette boucle s'exécute. La seule différence avec ce if est qu'il n'y a pas d'espaces après chaque caractère, donc je ne referai pas les commentaires
	{
		if (choixRemplissage == 1)
		{
			for (int i = 0; i < largeur; i++)
			{
				cout << contour;
			}

			cout << endl;

			for (int i = (hauteur - 2); i > 0; i--)
			{
				cout << contour;

				for (int i = 0; i < largeur - 2; i++)
				{
					cout << remplissage;
				}

				cout << contour << endl;
			}

			for (int i = 0; i < largeur; i++)
			{
				cout << contour;
			}

			cout << endl;
		}

		if (choixRemplissage == 2)
		{
			for (int i = 0; i < largeur; i++)
			{
				cout << contour;
			}

			cout << endl;

			for (int i = (hauteur - 2); i > 0; i--)
			{
				cout << contour;

				for (int i = 0; i < largeur - 2; i++)
				{
					cout << vide;
				}

				cout << contour << endl;
			}

			for (int i = 0; i < largeur; i++)
			{
				cout << contour;
			}

			cout << endl;
		}
	}
	
		
		
}

void dessinerTriangle1(int choixRemplissage, int hauteur)							//Première fonction pour dessiner un triangle
{
	char contour = '*';
	char remplissage = '#';
	char vide = ' ';
	int i = 1;																//Cette variable va me servir de compteur dans cette fonction pour d'autres choses que les for


	if (choixRemplissage == 1)												
	{
		while (i <= hauteur)												//Cette boucle s'exécute tant que i est plus petit ou égal à hauteur
		{
			if (i <= 2 || i == hauteur)										//Ce if s'exécute seulement pour la première, deuxième et dernière ligne
			{
				for (int compteur = 0; compteur < i; compteur++)			//Affiche un nombre de * égal au numéro de la rangée (1 dans la première, 2 dans la deuxième...)
				{
					cout << contour;
				}
				cout << endl;
			}
			if (i > 2 && i < hauteur)										//Pour les lignes entre la 2e et la dernière (excluant ces deux rangées). On affiche un *, puis un nombre de # égal au numéro de la rangée -2, puis une autre *
			{
				cout << contour;

				for (int compteur = 0; compteur < i-2; compteur++)			//Affiche un nombre de # égal au numéro de la rangée -2
				{
					cout << remplissage;
				}
				cout << contour << endl;
			}
			i++;					//On augmente la valeur de la variable i pour ne pas avoir de boucle infinie et que les for et if fonctionnent comme il faut
		}
	}

	if (choixRemplissage == 2)		//Même chose, mais avec vide au lieux de remplissage
	{
		while (i <= hauteur)
		{
			if (i <= 2 || i == hauteur)
			{

				for (int compteur = 0; compteur < i; compteur++)
				{
					cout << contour;
				}
				cout << endl;
			}
			if (i > 2 && i < hauteur)
			{
				cout << contour;

				for (int compteur = 0; compteur < i - 2; compteur++)
				{
					cout << vide;
				}
				cout << contour << endl;
			}
			i++;
		}
	}
}

void dessinerTriangle2(int choixRemplissage, int hauteur)			//Cette fonction est très semblable à la fonction dessinerTriangle1. Les différences sont basées sur le fait que i commence à la même valeur que la hauteur
{
	char contour = '*';
	char remplissage = '#';
	char vide = ' ';
	int i = hauteur;			//Sert de compteur inversé et sert au fonctionnement des for et des if

	//Les changements par rapport à dessinerTriangle1 sont en commentaires

	if (choixRemplissage == 1)
	{
		while (i >= 1)		//Au lieu de (i <= hauteur)
		{
			if (i <= 2 || i == hauteur)
			{
				for (int compteur = 0; compteur < i; compteur++)
				{
					cout << contour;
				}
				cout << endl;
			}
			if (i > 2 && i < hauteur)
			{
				cout << contour;
				for (int compteur = 0; compteur < i - 2; compteur++)
				{
					cout << remplissage;
				}
				cout << contour << endl;
			}
			i--;		//Au lieu de i++
		}
	}

	if (choixRemplissage == 2)
	{
		while (i >= 1)		//Au lieu de (i <= hauteur)
		{
			if (i <= 2 || i == hauteur)
			{
				for (int compteur = 0; compteur < i; compteur++)
				{
					cout << contour;
				}
				cout << endl;
			}
			if (i > 2 && i < hauteur)
			{
				cout << contour;
				for (int compteur = 0; compteur < i - 2; compteur++)
				{
					cout << vide;
				}
				cout << contour << endl;
			}
			i--;		//Au lieu de i++
		}
	}
}

void dessinerTriangle3(int choixRemplissage, int hauteur)			//Similaire à dessinerTriangle2, mais avec quelques étapes supplémentaires
{
	char contour = '*';
	char remplissage = '#';
	char vide = ' ';
	int i = hauteur;


	if (choixRemplissage == 1)
	{
		while (i >= 1)
		{
			for (int compteur = 0; compteur < (hauteur - i); compteur++)		//Sert à afficher les espaces avant les autres caractères pour donner sa forme au triangle. Commence par 0 espaces et en affiche 1 de plus par ligne
			{
				cout << vide;
			}
			if (i <= 2 || i == hauteur)											//Ce if, le if suivant et leur contenu est comme pour les autres triangles. Celui-ci sert à afficher la première, avant-dernière et dernière lignes(parce que le triangle est inversé)
			{
				for (int compteur = 0; compteur < i; compteur++)
				{
					cout << contour;
				}
				cout << endl;
			}
			if (i > 2 && i < hauteur)											//Ce if sert à afficher les autres lignes
			{
				cout << contour;
				for (int compteur = 0; compteur < (i - 2); compteur++)
				{
					cout << remplissage;
				}
				cout << contour << endl;
			}
			i--;
		}
	}

	if (choixRemplissage == 2)
	{
		while (i >= 1)
		{
			for (int compteur = 0; compteur < (hauteur - i); compteur++)
			{
				cout << vide;
			}
			if (i <= 2 || i == hauteur)
			{
				for (int compteur = 0; compteur < i; compteur++)
				{
					cout << contour ;
				}
				cout << endl;
			}
			if (i > 2 && i < hauteur)
			{
				cout << contour;
				for (int compteur = 0; compteur < (i - 2); compteur++)
				{
					cout << vide;
				}
				cout << contour << endl;
			}
			i--;
		}
	}
}

void dessinerTriangle4(int choixRemplissage, int hauteur)					//Encore une fois, très similaires aux autres triangles
{
	char contour = '*';
	char remplissage = '#';
	char vide = ' ';
	int i = 1;				//Comme pour dessinerTriangle1, i = 1 (pour l'information, la valeur de i est reliée à l'orientation du traingle), donc cette fonction partage plusieurs similarités avec cette dernière.


	if (choixRemplissage == 1)
	{
		while (i <= hauteur)
		{
			for (int compteur = 0; compteur < (hauteur - i); compteur++)				//Un peu comme pour dessinerTriangle3, on affiche des espaces avant le rest de la ligne. La différence est qu'on commence par afficher plusieurs espaces et le nombre diminue par la suite
			{
				cout << vide;
			}
			if (i <= 2 || i == hauteur)													//Le reste est identique à dessinerTriangle1
			{
				for (int compteur = 0; compteur < i; compteur++)
				{
					cout << contour ;
				}
				cout << endl;
			}
			if (i > 2 && i < hauteur)
			{
				cout << contour;
				for (int compteur = 0; compteur < (i - 2); compteur++)
				{
					cout << remplissage;
				}
				cout << contour << endl;
			}
			i++;
		}
	}

	if (choixRemplissage == 2)
	{
		while (i <= hauteur)
		{
			for (int compteur = 0; compteur < (hauteur - i); compteur++)
			{
				cout << vide;
			}
			if (i <= 2 || i == hauteur)
			{
				for (int compteur = 0; compteur < i; compteur++)
				{
					cout << contour;
				}
				cout << endl;
			}
			if (i > 2 && i < hauteur)
			{
				cout << contour;
				for (int compteur = 0; compteur < (i - 2); compteur++)
				{
					cout << vide;
				}
				cout << contour << endl;
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
	int largeur = 1;				//J'ai du créer 3 variables à utiliser pour cette fonction. Largeur représente le nombre de symbole par ligne, excluant les espaces
	int i = 0;						//i sert uniquement pour le fonctionnement du while
	bool inversion = 0;				//inversion devient égal à 1 lorsquele losange atteint sa largeur maximale pour que la largeur diminue

	if (choixRemplissage == 1)
	{
		while (i < hauteur)			//Cette boucle s'exécute tant que i est plus petit que la hauteur. Ceci sert à ce qu'il y ait le bon nombre de rangées
		{
			for (int comtpeur = 0; comtpeur < (((hauteur - largeur) / 2)); comtpeur++)			//Affiche un nombre d'espaces égal à la moitié de la (hauteur - le nombre de symbole dans la ligne)
			{
				cout << vide;
			}
			
			
			cout << contour;				//Cette section sert à afficher les symboles de la rangée
			if (largeur >= 3)				//Ce if ne s'exécute pas si largeur est plus petit que 3. J'ai fait cela parce qu'il ne doit avoir qu'un seul caractère dans la première et dernière rangée
			{
				for (int compteur = 0; compteur < (largeur - 2); compteur++)		//Affiche un nombre de # égal à largeur-2
				{
					cout << remplissage;
				}
				cout << contour;
			}
			cout << endl;


			//Ces deux ifs servent à modifier la valeur de largeur adéquatement
			if (largeur >= hauteur || inversion == 1)			//Ce if est le deuxième de ce bloc à s'exécuter (dans le programme, pas dans la boucle, si ça fait du sens). Une fois que ce if à été exécuté, le prochain ne le sera plus.
			{
				largeur = largeur - 2;							//Diminue la valeur de largeur de 2

				inversion = 1;									//Met inversion égal à 1. 
			}
			if (largeur < hauteur && inversion == 0)			//Ce if est exécuté avant le if précédent. Si inversion est égal à 1, il ne peut plus être exécuté
			{
				largeur = largeur + 2;							//Augmente la valeur de largeur de 2
			}

			i++;
		}
	}


	if (choixRemplissage == 2)
	{
		while (i < hauteur)
		{
			for (int comtpeur = 0; comtpeur < (((hauteur - largeur) / 2)); comtpeur++)
			{
				cout << vide;
			}


			cout << contour;
			if (largeur >= 3)
			{
				for (int compteur = 0; compteur < (largeur - 2); compteur++)
				{
					cout << vide;
				}
				cout << contour;
			}
			cout << endl;

			if (largeur >= hauteur || inversion == 1)
			{
				largeur = largeur - 2;

				inversion = 1;
			}
			if (largeur < hauteur && inversion == 0)
			{
				largeur = largeur + 2;
			}

			i++;
		}
	}
}

int genererNombreAleatoire(int min, int max)			//Génère un nombre aléatoire entre le nombre minimum et maximum qui sont fournis en paramètres. Cette fonction est la même qui a été faite en classe
{
	return rand()% (max - min + 1) + min;				//Retourne un nombre aléatoire entre le min et max. 
}
