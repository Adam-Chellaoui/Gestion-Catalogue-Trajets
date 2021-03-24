/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----
#ifndef DEF_TRAJET_SIMPLE
#define DEF_TRAJET_SIMPLE

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Implemente un trajet direct entre une uneVilleDepart et uneVilleArrive
// avec moyen de Transport.
//------------------------------------------------------------------------


class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC
public :
//----------------------------------------------------- Méthodes publiques

    void afficher() ;
    // Mode d'emploi : Affiche les caractéristiques du trajet simple
    //
    // Contrat : Redéfinitin de la méthode virtuelle pure de la classe 
    //           mère Trajet

    char* getDepart() ;
    // Mode d'emploi : Renvoie la ville de départ
    //
    // Contrat : Redéfinitin de la méthode virtuelle pure de la classe 
    //           mère Trajet

	char* getArrivee() ;
    // Mode d'emploi : Renvoie la ville d'arrivee
    //
    // Contrat : Redéfinitin de la méthode virtuelle pure de la classe 
    //           mère Trajet

	char* getMoyen() ;
    // Mode d'emploi : Renvoie le moyen de transport
    //
    // Contrat : Aucun
    //

    void ecritureFichier(ofstream & flux);
    // Mode d'emploi : Ecrit le trajet simple conformémément aux conventions dans le flux
    //
    // Contrat : Redéfinitin de la méthode virtuelle pure de la classe 
    //           mère Trajet

    void ecritureTS(ofstream & flux);
    // Mode d'emploi : Ecrit le trajet simple conformémément aux conventions dans le flux
    //                 de manière à être utilisé par ecritureFichier de TrajetCompose
    // Contrat : Redéfinitin de la méthode virtuelle pure de la classe 
    //           mère Trajet

    int isCompose();
    // Mode d'emploi : Méthode virtuelle qui renvoie 0 pour un trajet simple
    //
    // Contrat : Redéfinitin de la méthode virtuelle pure de la classe 
    //           mère Trajet


//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple (const char* debut,const char* fin,const char* moyen_transport);//Contructeur
    // Mode d'emploi : définition des attributs de trajet simple à partir
    //                 des Paramètres formels du constructeur
    // Contrat : Aucun
    //

    ~TrajetSimple();// Destructeur
    // Mode d'emploi : libère les allocations dynamiques réalisées
    //
    // Contrat : Aucun
    //
    
//------------------------------------------------------------------ Protégé
private :
    char* m_depart;
    char* m_arrivee;
    char* m_moyen_transport;
    
};


#endif










