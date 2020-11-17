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

			cout << "Votre choix: " << choix << endl;					//Affiche son choix � l'utilisateur
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

			cout << "Votre choix: " << choix << endl;					//Affiche son choix � l'utilisateur
		}
	}

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

void traiterTriangle(int choixRemplissage)						//Cette fonction sert � recueuillir les informations pour le triangle et appelle la fonction dessinerTriangle
{
	int hauteur;												//D�claration de la variable hauteur

	cout << "Veuillez entrer la hauteur du triangle:\n";		//On demande � l'utilisateur d'entrer la hauteur du triangle
	cin >> hauteur;

	if (choixRemplissage == 1)									//Les deux ifs servent � afficher une message l�g�rement diff�rent d�pendant de quel sorte de remplissage l'utilisateur � choisi
	{
		cout << "Voici votre triangle plein de hauteur " << hauteur << ":\n";
	}
	if (choixRemplissage == 2)
	{
		cout << "Voici votre triangle vide de hauteur " << hauteur << ":\n";
	}

	switch (genererNombreAleatoire(1,4))						//Appelle la fonction genererNombre aleatoire pour obtenir un nombre entre 1 et 4. Le switch appelle une fonction diff�rente pour chacun des 4 nombres possibles
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

	system("pause");											//Demande � l'utilisateur d'appuyer sur un bouton avant de continuer le programme
	system("cls");												//Efface tout ce qu'il y a d'affich� � la console

}

void traiterLosange(int choixRemplissage)						//Sert � recueuillir les informations pour le losange et apelle la fonction dessinerLosange
{
	int hauteur;												//�a commence � �tre redondant, donc je crois que je vais arr�ter de faire des commentaires sur les lignes qui sont identiques

	cout << "Veuillez entrer la hauteur du losange. La hauteur du losange doit �tre un nombre impair:\n";
	cin >> hauteur;

	while (hauteur % 2 != 1)									//S'ex�cute seulement si le nombre entr� par l'utilisateur n'est pas impair. Cette boucle s'ex�cute tant que l'utilisateur n'a pas entr� un nombre impair
	{
		cout << "Erreur: le nombre entr� n'est pas un nombre impair.\n\n";		//Affiche un message d'erreur

		cout << "Veuillez entrer la hauteur du losange. La hauteur du losange doit �tre un nombre impair:\n";	//Redemande � l'utilisateur d'entrer un nombre impair
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

void dessinerRectangle(int choixRemplissage, int hauteur, int largeur)			//Cette fonction sert � dessiner les carr�s et les rectangles
{
	char contour = '*';					//J'ai mis les caract�res dans des variables pour qu'ils soient plus faciles � changer, si n�c�ssaire
	char remplissage = '#';
	char vide = ' ';

	if (hauteur == largeur)								//Ce if sert � d�tecter si la forme est un carr�. Je fais la diff�rence entre le carr� et le rectangle parce que j'ai ins�r� des espaces entre chaquees caract�res du carr� pour qu'il apparaisse correctement � l'�cran
	{
		if (choixRemplissage == 1)						//Ce if sert � d�tecter si la forme doit �tre pleine, la seule diff�rence entre vide et plein est qu'il y a la variable remplissage dans un et la variable vide dans l'autre.
		{
			for (int i = 0; i < largeur; i++)			//Cette boucle sert � afficher la premi�re ligne, compos�e uniquement d'* (et d'espaces pour �loigner les caract�res puisqu'il s'agit du carr�)
			{
				cout << contour << vide;
			}
			cout << endl;								//Le endl est s�par� de la boucle pr�c�dente, m�me s'il est pour la m�me ligne, pour ne pas qu'il y ait un saut de ligne � chaque it�ration de cette derni�re

			for (int i = (hauteur - 2); i > 0; i--)		//Cette boucle sert � afficher toutes les lignes sauf la premi�re et la derni�re, puisqu'elles sont toutes identiques
			{
				cout << contour << vide;				//Affiche le * qui commence la ligne (et un espace parce que c'est un carr�)

				for (int i = 0; i < largeur - 2; i++)	//Cette boucle sert � afficher le remplissage de la forme, dans ce cas, il s'agit de #
				{
					cout << remplissage << vide;		//Affiche un # (suivit d'un espace parce que carr�)
				}

				cout << contour << endl;				//Affiche le dernier * de la ligne et fait un saut de ligne
			}

			for (int i = 0; i < largeur; i++)			//C'est la m�me boucle que la premi�re. Cette fois, elle serta � afficher la derni�re ligne
			{
				cout << contour << vide;
			}
			cout << endl;
		}

		if (choixRemplissage == 2)						//La seule diff�rence est le vide qui remplace le remplissage, donc je ne referais pas les commentaires
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
	else										//Si li premier if �tait faux (donc la forme est un rectangle), cette boucle s'ex�cute. La seule diff�rence avec ce if est qu'il n'y a pas d'espaces apr�s chaque caract�re, donc je ne referai pas les commentaires
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

void dessinerTriangle1(int choixRemplissage, int hauteur)							//Premi�re fonction pour dessiner un triangle
{
	char contour = '*';
	char remplissage = '#';
	char vide = ' ';
	int i = 1;																//Cette variable va me servir de compteur dans cette fonction pour d'autres choses que les for


	if (choixRemplissage == 1)												
	{
		while (i <= hauteur)												//Cette boucle s'ex�cute tant que i est plus petit ou �gal � hauteur
		{
			if (i <= 2 || i == hauteur)										//Ce if s'ex�cute seulement pour la premi�re, deuxi�me et derni�re ligne
			{
				for (int compteur = 0; compteur < i; compteur++)			//Affiche un nombre de * �gal au num�ro de la rang�e (1 dans la premi�re, 2 dans la deuxi�me...)
				{
					cout << contour;
				}
				cout << endl;
			}
			if (i > 2 && i < hauteur)										//Pour les lignes entre la 2e et la derni�re (excluant ces deux rang�es). On affiche un *, puis un nombre de # �gal au num�ro de la rang�e -2, puis une autre *
			{
				cout << contour;

				for (int compteur = 0; compteur < i-2; compteur++)			//Affiche un nombre de # �gal au num�ro de la rang�e -2
				{
					cout << remplissage;
				}
				cout << contour << endl;
			}
			i++;					//On augmente la valeur de la variable i pour ne pas avoir de boucle infinie et que les for et if fonctionnent comme il faut
		}
	}

	if (choixRemplissage == 2)		//M�me chose, mais avec vide au lieux de remplissage
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

void dessinerTriangle2(int choixRemplissage, int hauteur)			//Cette fonction est tr�s semblable � la fonction dessinerTriangle1. Les diff�rences sont bas�es sur le fait que i commence � la m�me valeur que la hauteur
{
	char contour = '*';
	char remplissage = '#';
	char vide = ' ';
	int i = hauteur;			//Sert de compteur invers� et sert au fonctionnement des for et des if

	//Les changements par rapport � dessinerTriangle1 sont en commentaires

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

void dessinerTriangle3(int choixRemplissage, int hauteur)			//Similaire � dessinerTriangle2, mais avec quelques �tapes suppl�mentaires
{
	char contour = '*';
	char remplissage = '#';
	char vide = ' ';
	int i = hauteur;


	if (choixRemplissage == 1)
	{
		while (i >= 1)
		{
			for (int compteur = 0; compteur < (hauteur - i); compteur++)		//Sert � afficher les espaces avant les autres caract�res pour donner sa forme au triangle. Commence par 0 espaces et en affiche 1 de plus par ligne
			{
				cout << vide;
			}
			if (i <= 2 || i == hauteur)											//Ce if, le if suivant et leur contenu est comme pour les autres triangles. Celui-ci sert � afficher la premi�re, avant-derni�re et derni�re lignes(parce que le triangle est invers�)
			{
				for (int compteur = 0; compteur < i; compteur++)
				{
					cout << contour;
				}
				cout << endl;
			}
			if (i > 2 && i < hauteur)											//Ce if sert � afficher les autres lignes
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

void dessinerTriangle4(int choixRemplissage, int hauteur)					//Encore une fois, tr�s similaires aux autres triangles
{
	char contour = '*';
	char remplissage = '#';
	char vide = ' ';
	int i = 1;				//Comme pour dessinerTriangle1, i = 1 (pour l'information, la valeur de i est reli�e � l'orientation du traingle), donc cette fonction partage plusieurs similarit�s avec cette derni�re.


	if (choixRemplissage == 1)
	{
		while (i <= hauteur)
		{
			for (int compteur = 0; compteur < (hauteur - i); compteur++)				//Un peu comme pour dessinerTriangle3, on affiche des espaces avant le rest de la ligne. La diff�rence est qu'on commence par afficher plusieurs espaces et le nombre diminue par la suite
			{
				cout << vide;
			}
			if (i <= 2 || i == hauteur)													//Le reste est identique � dessinerTriangle1
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
	int largeur = 1;				//J'ai du cr�er 3 variables � utiliser pour cette fonction. Largeur repr�sente le nombre de symbole par ligne, excluant les espaces
	int i = 0;						//i sert uniquement pour le fonctionnement du while
	bool inversion = 0;				//inversion devient �gal � 1 lorsquele losange atteint sa largeur maximale pour que la largeur diminue

	if (choixRemplissage == 1)
	{
		while (i < hauteur)			//Cette boucle s'ex�cute tant que i est plus petit que la hauteur. Ceci sert � ce qu'il y ait le bon nombre de rang�es
		{
			for (int comtpeur = 0; comtpeur < (((hauteur - largeur) / 2)); comtpeur++)			//Affiche un nombre d'espaces �gal � la moiti� de la (hauteur - le nombre de symbole dans la ligne)
			{
				cout << vide;
			}
			
			
			cout << contour;				//Cette section sert � afficher les symboles de la rang�e
			if (largeur >= 3)				//Ce if ne s'ex�cute pas si largeur est plus petit que 3. J'ai fait cela parce qu'il ne doit avoir qu'un seul caract�re dans la premi�re et derni�re rang�e
			{
				for (int compteur = 0; compteur < (largeur - 2); compteur++)		//Affiche un nombre de # �gal � largeur-2
				{
					cout << remplissage;
				}
				cout << contour;
			}
			cout << endl;


			//Ces deux ifs servent � modifier la valeur de largeur ad�quatement
			if (largeur >= hauteur || inversion == 1)			//Ce if est le deuxi�me de ce bloc � s'ex�cuter (dans le programme, pas dans la boucle, si �a fait du sens). Une fois que ce if � �t� ex�cut�, le prochain ne le sera plus.
			{
				largeur = largeur - 2;							//Diminue la valeur de largeur de 2

				inversion = 1;									//Met inversion �gal � 1. 
			}
			if (largeur < hauteur && inversion == 0)			//Ce if est ex�cut� avant le if pr�c�dent. Si inversion est �gal � 1, il ne peut plus �tre ex�cut�
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

int genererNombreAleatoire(int min, int max)			//G�n�re un nombre al�atoire entre le nombre minimum et maximum qui sont fournis en param�tres. Cette fonction est la m�me qui a �t� faite en classe
{
	return rand()% (max - min + 1) + min;				//Retourne un nombre al�atoire entre le min et max. 
}
