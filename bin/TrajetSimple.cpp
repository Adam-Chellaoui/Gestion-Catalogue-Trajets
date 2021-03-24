/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


char* TrajetSimple::getDepart () 
{
	return m_depart;
} //-------- Fin de la Méthode getDepart


char* TrajetSimple::getArrivee() 
{
	return m_arrivee;
} //-------- Fin de la Méthode getArrivee

char* TrajetSimple::getMoyen()
{
	return m_moyen_transport;
} //-------- Fin de la Méthode getMoyen

void TrajetSimple::afficher()  
{
	cout<<m_depart<<"---("<< m_moyen_transport<<")--->" <<m_arrivee<<endl;
} //-------- Fin de la Méthode afficher

void TrajetSimple::ecritureFichier(ofstream & flux)
{
	flux<<"$"<<m_depart<<","<<m_arrivee<<",1:"<<m_depart<<","<<m_moyen_transport<<","<<m_arrivee<<",%"<<endl;
}//-------- Fin de la Méthode ecritureFichier

void TrajetSimple::ecritureTS(ofstream & flux)
{
	flux<<m_depart<<","<<m_moyen_transport<<","<<m_arrivee<<",";
}//-------- Fin de la Méthode ecritureTS

int TrajetSimple::isCompose() {return 0;} //-------- Fin de la Méthode isCompose

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple (const char* debut,const char* fin,const char* moyen_transport)
{
	m_depart= new char[strlen(debut)+1];
	m_arrivee= new char[strlen(fin)+1];
	m_moyen_transport= new char[strlen(moyen_transport)+1];
	strcpy(m_depart,debut);
	strcpy(m_arrivee,fin); 
	strcpy(m_moyen_transport, moyen_transport);

} //-------- Fin du constructeur TrajetSimple


TrajetSimple::~TrajetSimple() 
{
    delete[] m_depart;
    delete[] m_arrivee;
    delete[] m_moyen_transport;	

} //-------- Fin du destructeur ~TrajetSimple
