/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//------ Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ------
#ifndef DEF_TRAJET_COMPOSE
#define DEF_TRAJET_COMPOSE
//--------------------------------------------------- Interfaces utilisées
#include"TrajetSimple.h"
#include"ListeChainee.h"
#include"Trajet.h"
#include"CelluleTrajet.h"
//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Créer un Trajet composé de plusieurs Fractions de Trajets (simple ou composé)
// qui relient une ville de départ à une ville d'arrivée.
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC
public :
//----------------------------------------------------- Méthodes publiques
	
	void ajouterTrajet(TrajetSimple* nvTrajet);
	// Mode d'emploi : Ajoute un trajet au trajet composé
	//
	// Contrat : Aucun
	//

	void ajouterEtape(char* moyen,char* arrivee);
	// Mode d'emploi : Ajoute une étape au trajet composé
	//
	// Contrat : Aucun
	//

	void afficher() ;
	// Mode d'emploi : Affiche les caractéristiques du Trajet composé
	//
	//Contrat: Redéfinitin de la méthode virtuelle pure de la classe mère Trajet
	//
	
	char* getDepart() ;
	// Mode d'emploi : Renvoie la ville de départ
	//
	// Contrat : Aucun
	//

	char* getArrivee() ;
	// Mode d'emploi : Renvoie la ville d'Arrivée
	//
	// Contrat : Aucun
	//

	void ecritureFichier(ofstream & flux);
	// Mode d'emploi : Ecrit le trajet composé conformémément aux conventions dans le flux
    //
    // Contrat : Redéfinitin de la méthode virtuelle pure de la classe 
    //           mère Trajet

	void ecritureTS(ofstream & flux);
	// Mode d'emploi : methode vide, permetant l'existence de la méthode vituelle pure dans Trajet
    // Contrat : Redéfinitin de la méthode virtuelle pure de la classe 
    //           mère Trajet


	int isCompose();
	// Mode d'emploi : Méthode virtuelle qui renvoie 1 pour un trajet composé
    //
    // Contrat : Redéfinitin de la méthode virtuelle pure de la classe 
    //           mère Trajet

//-------------------------------------------- Constructeurs - destructeur

	TrajetCompose();//Constructeur
	// Mode d'emploi : définition des attributs de trajet composé à partir
	//                 des Paramètres formels du constructeur
	// Contrat : Aucun
	//

	~TrajetCompose();//Destructeur
	// Mode d'emploi : libère les allocations dynamiques réalisées
	//
	// Contrat : Aucun
	//
	
//------------------------------------------------------------------ Protégé
private :
//----------------------------------------------------- Attributs protégés
	ListeChainee *m_listeTrajets;

};


#endif