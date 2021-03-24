/*************************************************************************
                           ListeChainee  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ListeChainee> (fichier ListeChainee.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include<iostream>
#include<cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include"CelluleTrajet.h"
#include"ListeChainee.h"
#include"Trajet.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


CelluleTrajet* ListeChainee::getPremier ()const
{
	return premier;
}//--------------Fin Méthode getPremier

CelluleTrajet* ListeChainee::getDernier ()const
{
	return dernier;
}//--------------Fin Méthode getDernier

unsigned int ListeChainee::getLen() const 
{
	return len;
}//--------------Fin Méthode getLen

void ListeChainee::setPremier(CelluleTrajet* ptr)
{
	premier=ptr;
}//--------------Fin Méthode setPremier

void ListeChainee::setDernier(CelluleTrajet* ptr)
{
	dernier=ptr;
}//--------------Fin Méthode getDernier


void ListeChainee::ajouter(Trajet* nv_trajet)
{
	
	CelluleTrajet* nouveau=new CelluleTrajet(nv_trajet);
	nouveau->setTrajet(nv_trajet);
	if (premier==NULL) { // on vérifie que la liste est vide
		premier=nouveau;

	}
	else {
		CelluleTrajet* p=dernier;
		p->setSuivant(nouveau);
	}
	dernier=nouveau;
	len++;

}//--------------Fin Méthode ajouter

void ListeChainee::afficherListe () const
{
	CelluleTrajet* p=premier;
	cout <<"La Liste est composée des trajets suivants : "<<endl;
	cout<<"{"<<endl;
	cout<<" "<<endl;
	while (p!=nullptr) { // on vérifie qu'on est pas encore arrivé à la fin de liste

		Trajet* t=(p->getTrajet());
		t->afficher();
		cout<<" "<<endl;
		p=p->getSuivant();
	}
	cout<<"}"<<endl;	
}//--------------Fin Méthode afficherListe

void ListeChainee::insertListe(Trajet* nvTrajet)
{
	CelluleTrajet* courrant=premier;
	CelluleTrajet* nouveau=new CelluleTrajet(nvTrajet);
	if (courrant==nullptr || strcmp(nvTrajet->getDepart(),(courrant->getTrajet())->getDepart())<=0) // si la liste est nulle ou si la ville de départ du trajet entré est supérieur alphabétiquement au premier élément de la liste
	{
		
		premier=nouveau;
	}
	else 
	{
		CelluleTrajet* precedant;
		while (courrant!=nullptr && strcmp((courrant->getTrajet())->getDepart(),nvTrajet->getDepart())<0)
		{
			precedant=courrant;
			courrant=courrant->getSuivant();
		}
		precedant->setSuivant(nouveau);	
	}
	nouveau->setSuivant(courrant);
	len++;
}//--------------Fin Méthode insertListe

//-------------------------------------------- Constructeurs - destructeur

ListeChainee::ListeChainee() : premier(NULL), dernier(NULL), len(0)
{}//--------------Fin Constructeur ListeChainee

ListeChainee::~ListeChainee()
{

	CelluleTrajet* tmp;
	while (premier!=dernier) {
		tmp=premier;
		premier=tmp->getSuivant();
		delete(tmp);
	}
	delete (premier);
	len=0;
}//--------------Fin Destructeur ~ListeChainee




