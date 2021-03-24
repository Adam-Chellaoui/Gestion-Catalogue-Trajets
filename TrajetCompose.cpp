/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//-------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include"TrajetCompose.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


char* TrajetCompose::getDepart() 
{
	CelluleTrajet* cell=m_listeTrajets->getPremier();
	Trajet* T=cell->getTrajet();
	return T->getDepart();
}//-------- Fin Méthode getDepart

char* TrajetCompose::getArrivee() 
{
	CelluleTrajet* cell=m_listeTrajets->getDernier();
	Trajet* T=cell->getTrajet();
	return T->getArrivee();
}//-------- Fin Méthode getArrivee


void TrajetCompose::afficher()
{
	CelluleTrajet* p=m_listeTrajets->getPremier();
	if (p!=NULL) {
		Trajet* ts=(p->getTrajet());
		cout<<ts->getDepart()<<"---("<<ts->getMoyen()<<")--->"<<ts->getArrivee();
		p=p->getSuivant();
	}
	while (p!=NULL) {// tant que nous ne somme pas arrivés à la fin de la liste
		Trajet* ts=(p->getTrajet());
		cout<<"---("<<ts->getMoyen()<<")--->"<<ts->getArrivee();
		p=p->getSuivant();
	}
	cout<<" "<<endl;
}//-------- Fin Méthode afficher

void TrajetCompose::ajouterTrajet(TrajetSimple* nvTrajet)
{	
	if (m_listeTrajets->getPremier()==NULL) { // si la liste est vide
		m_listeTrajets->ajouter(nvTrajet);
	}
	else {
		CelluleTrajet* p=m_listeTrajets->getDernier();
		if (strcmp((p->getTrajet())->getArrivee(),nvTrajet->getDepart())==0) { // on verifie que la ville d'arrivée du premier trajet est la même quela ville du depart du 2eme trajet
		m_listeTrajets->ajouter(nvTrajet);
		}
		else {
		cout<<"Le nouveau Trajet ne peut être ajouté. "<<endl;
		}
	}
}//-------- Fin Méthode ajouterTrajet

void TrajetCompose::ajouterEtape(char* moyen,char* arrivee)
{
	CelluleTrajet* p=m_listeTrajets->getDernier();
	char* depart=p->getTrajet()->getArrivee();
	m_listeTrajets->ajouter(new TrajetSimple(depart,arrivee,moyen));

}//-------- Fin Méthode ajouterEtape

void TrajetCompose::ecritureFichier(ofstream & flux)
{
	CelluleTrajet* p=m_listeTrajets->getPremier();
	CelluleTrajet* d=m_listeTrajets->getDernier();
	char longueur=m_listeTrajets->getLen()+48;
	flux<<"@"<<p->getTrajet()->getDepart()<<","<<d->getTrajet()->getArrivee()<<","<<longueur<<":";
	while (p!=nullptr)
	{
		p->getTrajet()->ecritureTS(flux);
		p=p->getSuivant();
	}
	flux<<"%"<<endl;
}//-------- Fin Méthode ecritureFichier

void TrajetCompose::ecritureTS(ofstream & flux)
{} //-------- Fin Méthode ecritureTS

int TrajetCompose::isCompose() {return 1;}//-------- Fin Méthode isCompose

//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose () 
{
	m_listeTrajets=new ListeChainee();
}//-------- Fin du constructeur TrajetCompose

TrajetCompose::~TrajetCompose()
{
	delete m_listeTrajets;
}//-------- Fin du destructeur ~TrajetCompose 














