/*************************************************************************
                           ListeTrajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/


//---------- Interface de la classe <ListeChainee> (fichier ListeChainee.h) ----------
#ifndef DEF_LISTE_CHAINEE
#define DEF_LISTE_CHAINEE

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "CelluleTrajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <ListeChainee>
// Implémente une Liste de pointeur de CelluleTrajet pour les stocker
//------------------------------------------------------------------------


class ListeChainee
{
//----------------------------------------------------------------- PUBLIC
public : 
//----------------------------------------------------- Méthodes publiques

	void ajouter (Trajet* nv_trajet);
	// Mode d'emploi : ajoute un trajet à la liste 
	//

	CelluleTrajet* getPremier()const;
	// Mode d'emploi : Renvoie la case de début de la liste de trajets
	//

	CelluleTrajet* getDernier()const;
	// Mode d'emploi : Renvoie la case de fin de la liste de trajets
	//

	unsigned int getLen() const;
	// Mode d'emploi : Renvoie la longueur de la liste de trajets
	//

	void setPremier (CelluleTrajet* ptr);
	// Mode d'emploi : Met le pointeur de début premier à ptr
	//

	void setDernier (CelluleTrajet* ptr);
	// Mode d'emploi : Met le pointeur de fin dernier à ptr
	//

	void insertListe(Trajet* nvTrajet);
	// Mode d'emploi : ajoute un trajet à la liste de manière ordonée
	//

	void afficherListe () const;
	// Mode d'emploi : Parcourt la liste de pointeur de trajet et appelle
	//                 leur méthode affichage


//-------------------------------------------- Constructeurs - destructeur

	ListeChainee();//Cosntructeur
	// Mode d'emploi : crée une liste chainée au départ vide
	//

	~ListeChainee();//Destructeur
	// Mode d'emploi : Libération mémoire de ListeTrajet et de ses attributs
	// 

//------------------------------------------------------------------ PROTECTED

private :
//----------------------------------------------------- Attributs protégés 
	CelluleTrajet* premier;
	CelluleTrajet* dernier;
	unsigned int len;

};

#endif











