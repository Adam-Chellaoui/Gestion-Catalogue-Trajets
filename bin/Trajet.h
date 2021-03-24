/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------

#ifndef DEF_TRAJET
#define DEF_TRAJET


//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Implémente un trajet entre une ville de départ et une ville d'arrivée
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC
public :

    virtual void afficher()=0;
    // Mode d'emploi : Permet d'afficher les caractéristiques d'un Trajet
	//
	// Contrat : c'est une méthode virtuelle pure (=0) on définit ainsi une classe abstraite

    virtual char* getDepart()=0;
    // Mode d'emploi : Renvoie la ville de départ
	//
	// Contrat : c'est une méthode virtuelle pure (=0) on définit ainsi une classe abstraite
	
    virtual char* getArrivee()=0;
    // Mode d'emploi : Renvoie la ville de d'arrivée
	//
	// Contrat : c'est une méthode virtuelle pure (=0) on définit ainsi une classe abstraite
	
    virtual char* getMoyen();
    // Mode d'emploi : Renvoie le moyen de Transport
	//
	// Contrat : c'est une méthode virtuelle pure (=0) on définit ainsi une classe abstraite

	virtual void ecritureFichier(ofstream & flux)=0;
	// Mode d'emploi : Ecrit le trajet conformémément aux conventions dans le flux
	//
	// Contrat : c'est une méthode virtuelle pure (=0) on définit ainsi une classe abstraite

	virtual void ecritureTS (ofstream & flux)=0;
	// Mode d'emploi : Ecrit le trajet simple conformémément aux conventions dans le flux
	//
	// Contrat : c'est une méthode virtuelle pure (=0) on définit ainsi une classe abstraite

	virtual int isCompose()=0;
	// Mode d'emploi : indique si le trajet est simple (renvoie 0) ou composé (renvoie 1)
	//
	// Contrat : c'est une méthode virtuelle pure (=0) on définit ainsi une classe abstraite

//-------------------------------------------- Constructeurs - destructeur

    Trajet();// Constructeur
    // Mode d'emploi : Constructeur de la classe Trajet
	//
	// Contrat : Aucun
	

 	virtual ~Trajet();// Destrcuteur
 	// Mode d'emploi : libère toutes les allocations dynamiques effectuées
	//
	// Contrat : Aucun
	
 };


#endif