/*************************************************************************
                           CelluleTrajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <CelluleTrajet> (fichier CelluleTrajet.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include<iostream>
#include<cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include"CelluleTrajet.h"

//----------------------------------------------------- Méthodes publiques

Trajet* CelluleTrajet::getTrajet()
{
	return m_Trajet;
}//--------Fin de la Méthode getTrajet

CelluleTrajet* CelluleTrajet::getSuivant()
{
	return suivant;
}//--------Fin de la Méthode getSuivant

void CelluleTrajet::setTrajet (Trajet* trajet)
{
	m_Trajet=trajet;
}//--------Fin de la Méthode setTrajet

void CelluleTrajet::setSuivant(CelluleTrajet* ptr)
{
	suivant = ptr;
}//--------Fin de la Méthode setSuivant

//-------------------------------------------- Constructeurs - destructeur

CelluleTrajet::CelluleTrajet (Trajet* trajet) 
{
	m_Trajet=trajet;
	suivant=NULL;
}//--------Fin du constructeur CelluleTrajet

CelluleTrajet::~CelluleTrajet()
{
	delete m_Trajet;
	suivant=NULL;	
}//--------Fin du Destructeur ~CelluleTrajet