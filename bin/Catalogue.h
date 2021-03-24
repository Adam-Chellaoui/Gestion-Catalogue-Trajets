/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------
#ifndef DEF_CATALOGUE
#define DEF_CATALOGUE



//--------------------------------------------------- Interfaces utilisées
#include"Trajet.h"
#include"ListeChainee.h"
#include"CelluleTrajet.h"

//------------------------------------------------------------------------
// Role de la classe <Catalogue>
//Implemente le catalogue de trajets :les méthodes d'Ajout
//la  Recherche de trajets et l'affichage de Trajet
//------------------------------------------------------------------------

class Catalogue 
{
//----------------------------------------------------------------- PUBLIC

public :
//----------------------------------------------------- Méthodes publiques
	void afficherCat () const ;
	// Mode d'emploi : Afiiche le catalogue en utilisatant la méthode d'affichage 
	//					de ListeChainee

	void ajouterTrajet (Trajet* nvTrajet);
	// Mode d'emploi : Ajoute un trajet au catalogue en faisant appelle à 
	//                 la méthode Ajouter dans ListeChainee.

	void insertOrd(Trajet* nvTrajet);
	// Mode d'emploi : Ajoute un trajet au catalogue en faisant en sortes
	//					que le catalogue soit ordonée par ordre alphabétique.

	void itineraire(char* depart, char* arrivee) const;
	// Mode d'emploi : Recherche un trajet dans le catalogue à  partir d'une ville
	//                 de départ et ville d'arrivé saisies par l'utilisateur.

	void sauvTout (string nomFichier) const;
	// Mode d'emploi : Sauvegarde dans un fichier tout le contenu du catalogue courrant
	//        		   suivant les conventions adopotées      

	void sauvSimple (string nomFichier) const;
	// Mode d'emploi : Sauvegarde dans un fichier tous les trajets simples du catalogue courrant
	//        		   suivant les conventions adopotées   

	void sauvCompose (string nomFichier) const;
	// Mode d'emploi : Sauvegarde dans un fichier tous les trajets composés du catalogue courrant
	//        		   suivant les conventions adopotées   

	void sauvVoyage (string nomFichier,string depart,string arrivee) const;
	// Mode d'emploi : Sauvegarde dans un fichier tous les trajets correspondant à un voyage donné 
	//        		  du catalogue courrant suivant les conventions adopotées

	void sauvDepart (string nomFichier,string depart) const;
	// Mode d'emploi : Sauvegarde dans un fichier tous les trajets partants d'une ville, 
	//        		  du catalogue courrant suivant les conventions adopotées  

	void sauvArrivee (string nomFichier,string arrivee) const;
	// Mode d'emploi : Sauvegarde dans un fichier tous les trajets arrivants dans une ville, 
	//        		  du catalogue courrant suivant les conventions adopotées  

	void chargerToutCat(string nomFichier);
	// Mode d'emploi : Importe dans le catalogue courrant tout le contenu du fichier
	//        		   suivant les conventions adopotées 

	void chargerSimple(string nomFichier);
	// Mode d'emploi : Importe dans le catalogue courrant tous les trajets simples contenus 
	//        		   dans le fichier suivant les conventions adopotées 

	void chargerCompose(string nomFichier);
	// Mode d'emploi : Importe dans le catalogue courrant tous les trajets composés contenus 
	//        		   dans le fichier suivant les conventions adopotées 

	void chargerVoyage(string nomFichier,string depart,string arrivee);
	// Mode d'emploi : Importe dans le catalogue courrant tous les trajets correspondant à un 
	//        		   voyage donné contenus dans le fichier suivant les conventions adopotées 

	void chargerDepart(string nomFichier,string depart);
	// Mode d'emploi : Importe dans le catalogue courrant tous les trajets correspondant à un 
	//        		   voyage commençant par une ville dans le fichier suivant les conventions adopotées 

	void chargerArrivee(string nomFichier,string arrivee);
	// Mode d'emploi : Importe dans le catalogue courrant tous les trajets correspondant à un 
	//        		   voyage arrivant dans une ville contenus dans le fichier suivant les conventions adopotées 

//-------------------------------------------- Constructeurs - destructeur
	Catalogue(); //Constructeur
	// Mode d'emploi : crée une liste de trajets à partir du constructeur de ListeChainee

	~Catalogue(); //Destructeur
	// Mode d'emploi : delete la liste catalogue pour libérer la mémoire.
	//


protected :
//----------------------------------------------------- Attributs protégés
	ListeChainee* m_catalogue;

};

#endif