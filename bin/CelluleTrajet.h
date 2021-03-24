/*************************************************************************
                           CelluleTrajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <CelluleTrajet> (fichier CelluleTrajet.h) ----------
#ifndef DEF_CELLULE_TRAJET
#define DEF_CELLULE_TRAJET

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <CelluleTrajet>
//  Implémente une Cellule ainsi que le pointeur sur la Cellule suivante dans ListeChainee.
//------------------------------------------------------------------------

class CelluleTrajet 
{
//----------------------------------------------------------------- PUBLIC

public :
	//----------------------------------------------------- Méthodes publiques 

 	Trajet* getTrajet();
 	// Mode d'emploi : Renvoie le trajet stocké dans la CaseTrajet
	//

	CelluleTrajet* getSuivant();
	// Mode d'emploi : Renvoie la case suivante
	//

	void setSuivant (CelluleTrajet* ptr);
	// Mode d'emploi : Set la case suivante à la valeure rentrée en paramètre
	//

	void setTrajet (Trajet* trajet);
	// Mode d'emploi : Set la le pointeur trajet à la valeure rentrée en paramètre
	//

//-------------------------------------------- Constructeurs - destructeur
	CelluleTrajet (Trajet* trajet); //Constructeur
	// Mode d'emploi : Création d'une Case de trajet à partir du Trajet
	//		   donné en paramètre.

	~CelluleTrajet(); //Destructeur
	// Mode d'emploi : Libération mémoire de CaseTrajet et de ses attributs
	//


private :
	Trajet* m_Trajet ;
 	CelluleTrajet* suivant ;

};

#endif