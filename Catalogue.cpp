/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/


//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include<iostream>
#include<cstring>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//------------------------------------------------------ Include personnel
#include"CelluleTrajet.h"
#include"ListeChainee.h"
#include"TrajetSimple.h"
#include"TrajetCompose.h"
#include"Trajet.h"
#include"Catalogue.h"

//----------------------------------------------------- Fonctions utiles

void sauter(char sep,ifstream & f)
{
	string temp;
	getline(f,temp,sep);
}//--------Fin Fonction sauter


//----------------------------------------------------- Méthodes publiques

void Catalogue::afficherCat () const
{
	m_catalogue->afficherListe();
	
}//--------Fin Méthode afficherCat

void Catalogue::insertOrd(Trajet* nvTrajet)
{
	CelluleTrajet* courrant=m_catalogue->getPremier();
	CelluleTrajet* nouveau=new CelluleTrajet(nvTrajet);
	if (courrant==nullptr || strcmp(nvTrajet->getDepart(),(courrant->getTrajet())->getDepart())<=0) // on vérifie si la liste est nulle ou si la premiere lettre de la ville de départ courante est plus grande Alphabétiquement que le debut de la liste
	{
		
		m_catalogue->setPremier(nouveau);
	}
	else 
	{
		CelluleTrajet* precedant;
		while (courrant!=nullptr && strcmp((courrant->getTrajet())->getDepart(),nvTrajet->getDepart())<0)// tant que nous ne sommes pas arrivés a la fin de la liste et que le trajer rentré n'est pas à la bonne place dans l'ordre Alphabetique
		{
			precedant=courrant;
			courrant=courrant->getSuivant();
		}
		precedant->setSuivant(nouveau);	
	}
	nouveau->setSuivant(courrant);
}//--------Fin Méthode insertOrd



void Catalogue::ajouterTrajet(Trajet* nvTrajet)
{
	m_catalogue->ajouter(nvTrajet);
}//--------Fin Méthode ajouterTrajet


void Catalogue::itineraire(char* depart,char* arrivee) const
{
	CelluleTrajet* p=m_catalogue->getPremier();
	int n=0;
	while (p!=nullptr) 
	{
		Trajet* traj=p->getTrajet();
		if (strcmp(traj->getDepart(),depart)==0 && strcmp(traj->getArrivee(),arrivee)==0) 
		{
			traj->afficher();
			n++;
		}
		p=p->getSuivant();
	}
	if (n==0) 
	{
		cout<<"Aucun Itinéraire trouvé de "<<depart<<" à "<<arrivee<<endl;
	}	
}//--------Fin Méthode itineraire

void Catalogue::chargerToutCat(string nomFichier)
{
	ifstream monFlux(nomFichier);  
	if(monFlux)
	{
		while (monFlux.eof()==false) //condition de fin de fichier
		{
			char c; 
			monFlux.get(c);
			if (c=='$') {
				sauter(':',monFlux);
				string dep,moy,arr;
				getline(monFlux,dep,',');
				getline(monFlux,moy,',');
				getline(monFlux,arr,',');
				insertOrd(new TrajetSimple(dep.c_str(),arr.c_str(),moy.c_str()));
				monFlux.get(c); //On saute le caractère de fin de ligne
			}
			else if (c=='@') {
				TrajetCompose* tc=new TrajetCompose();
				sauter(',',monFlux);
				sauter(',',monFlux);
				char n;
				monFlux.get(n);
				int N=n-48; //Conversion de char vers int correspondant 
				sauter(':',monFlux);
				for(int i=0;i<N;i++) {
					string dep,moy,arr;
					getline(monFlux,dep,',');
					getline(monFlux,moy,',');
					getline(monFlux,arr,',');
					tc->ajouterTrajet(new TrajetSimple(dep.c_str(),arr.c_str(),moy.c_str()));
				}
				insertOrd(tc);
				monFlux.get(c); //On saute le caractère de fin de ligne
			}
		}
	}
	else
	{
    cerr << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
	
}//--------Fin Méthode chargerToutCat

void Catalogue::chargerSimple(string nomFichier)
{
	ifstream monFlux(nomFichier);  
	if(monFlux)
	{
		while (monFlux.eof()==false) //condition de fin de fichier
		{
			char c;
			monFlux.get(c);
			if (c=='$') {
				sauter(':',monFlux);
				string dep,moy,arr;
				getline(monFlux,dep,',');
				getline(monFlux,moy,',');
				getline(monFlux,arr,',');
				insertOrd(new TrajetSimple(dep.c_str(),arr.c_str(),moy.c_str()));
				monFlux.get(c);
			}		
		}
	}
	else
	{
    cerr << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}

}//--------Fin Méthode chargerSimple

void Catalogue::chargerCompose(string nomFichier)
{
	ifstream monFlux(nomFichier);  
	if(monFlux)
	{
		while (monFlux.eof()==false) //condition de fin de fichier
		{
			char c;
			monFlux.get(c);
			if (c=='@') {
				TrajetCompose* tc=new TrajetCompose();
				sauter(',',monFlux);
				sauter(',',monFlux);
				char n;
				monFlux.get(n);
				int N=n-48; //Conversion de char vers int correspondant 
				sauter(':',monFlux);
				for(int i=0;i<N;i++) {
					string dep,moy,arr;
					getline(monFlux,dep,',');
					getline(monFlux,moy,',');
					getline(monFlux,arr,',');
					tc->ajouterTrajet(new TrajetSimple(dep.c_str(),arr.c_str(),moy.c_str()));
				}
				insertOrd(tc);
			
			}
			//On saute jusqu'à la fin de la ligne dans tous les cas 
			string inutile;
			getline(monFlux,inutile);
			
		}
	}
	else
	{
    cerr << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}	
}//--------Fin Méthode chargerCompose

void Catalogue::chargerVoyage(string nomFichier,string depart,string arrivee)
{
	ifstream monFlux(nomFichier);  
	if(monFlux)
	{
		while (monFlux.eof()==false) //condition de fin de fichier
		{
			char c;
			monFlux.get(c);
			string mdep,marr;
			getline(monFlux,mdep,',');
			getline(monFlux,marr,',');
			if (mdep==depart && marr==arrivee) {
				if (c=='$') {
					sauter(':',monFlux);
					string dep,moy,arr;
					getline(monFlux,dep,',');
					getline(monFlux,moy,',');
					getline(monFlux,arr,',');
					insertOrd(new TrajetSimple(dep.c_str(),arr.c_str(),moy.c_str()));
					string inutile;
					getline(monFlux,inutile); // On saute jusqu'à la fin de la ligne

					}
				else if (c=='@') {
					TrajetCompose* tc=new TrajetCompose();
					char n;
					monFlux.get(n);
					int N=n-48; //Conversion de char vers int correspondant 
					sauter(':',monFlux);
					for(int i=0;i<N;i++) {
						string dep,moy,arr;
						getline(monFlux,dep,',');
						getline(monFlux,moy,',');
						getline(monFlux,arr,',');
						tc->ajouterTrajet(new TrajetSimple(dep.c_str(),arr.c_str(),moy.c_str()));
						}
					insertOrd(tc);
					string inutile;
					getline(monFlux,inutile); // On saute jusqu'à la fin de la ligne
					}
			}
			else {
				// On saute la ligne 
				string inutile;
				getline(monFlux,inutile);
			}
		}
	}
	else
	{
    cerr << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
	
}//--------Fin Méthode chargerVille

void Catalogue::chargerDepart(string nomFichier,string depart)
{
	ifstream monFlux(nomFichier);  
	if(monFlux)
	{
		while (monFlux.eof()==false) //condition de fin de fichier
		{
			char c;
			monFlux.get(c);
			string mdep,marr;
			getline(monFlux,mdep,',');
			getline(monFlux,marr,',');
			if (mdep==depart ) {
				if (c=='$') {
					sauter(':',monFlux);
					string dep,moy,arr;
					getline(monFlux,dep,',');
					getline(monFlux,moy,',');
					getline(monFlux,arr,',');
					insertOrd(new TrajetSimple(dep.c_str(),arr.c_str(),moy.c_str()));
					string inutile;
					getline(monFlux,inutile); // On saute jusqu'à la fin de la ligne

					}
				else if (c=='@') {
					TrajetCompose* tc=new TrajetCompose();
					char n;
					monFlux.get(n);
					int N=n-48; //Conversion de char vers int correspondant 
					sauter(':',monFlux);
					for(int i=0;i<N;i++) {
						string dep,moy,arr;
						getline(monFlux,dep,',');
						getline(monFlux,moy,',');
						getline(monFlux,arr,',');
						tc->ajouterTrajet(new TrajetSimple(dep.c_str(),arr.c_str(),moy.c_str()));
						}
					insertOrd(tc);
					string inutile;
					getline(monFlux,inutile); // On saute jusqu'à la fin de la ligne
					}
			}
			else {
				// On saute la ligne 
				string inutile;
				getline(monFlux,inutile);
			}
		}
	}
	else
	{
    cerr << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
	
}//--------Fin Méthode chargerDepart

void Catalogue::chargerArrivee(string nomFichier,string arrivee)
{
	ifstream monFlux(nomFichier);  
	if(monFlux)
	{
		while (monFlux.eof()==false) //condition de fin de fichier
		{
			char c;
			monFlux.get(c);
			string mdep,marr;
			getline(monFlux,mdep,',');
			getline(monFlux,marr,',');
			if (marr==arrivee ) {
				if (c=='$') {
					sauter(':',monFlux);
					string dep,moy,arr;
					getline(monFlux,dep,',');
					getline(monFlux,moy,',');
					getline(monFlux,arr,',');
					insertOrd(new TrajetSimple(dep.c_str(),arr.c_str(),moy.c_str()));
					string inutile;
					getline(monFlux,inutile); // On saute jusqu'à la fin de la ligne

					}
				else if (c=='@') {
					TrajetCompose* tc=new TrajetCompose();
					char n;
					monFlux.get(n);
					int N=n-48; //Conversion de char vers int correspondant 
					sauter(':',monFlux);
					for(int i=0;i<N;i++) {
						string dep,moy,arr;
						getline(monFlux,dep,',');
						getline(monFlux,moy,',');
						getline(monFlux,arr,',');
						tc->ajouterTrajet(new TrajetSimple(dep.c_str(),arr.c_str(),moy.c_str()));
						}
					insertOrd(tc);
					string inutile;
					getline(monFlux,inutile); // On saute jusqu'à la fin de la ligne
					}
			}
			else {
				// On saute la ligne 
				string inutile;
				getline(monFlux,inutile);
			}
		}
	}
	else
	{
    cerr << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
	
}//--------Fin Méthode chargerArrivee

void Catalogue::sauvTout (string nomFichier) const
{
    ofstream monFlux(nomFichier.c_str());
    if(monFlux)    
    {
		CelluleTrajet* p=m_catalogue->getPremier();
        while (p!=nullptr) // Parcours du Catalogue
		{
			p->getTrajet()->ecritureFichier(monFlux); // On écrit le Trajet
			p=p->getSuivant();
		}
    }
    else
    {
        cerr << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}//--------Fin Méthode sauvTout

void Catalogue::sauvCompose (string nomFichier) const
{
    ofstream monFlux(nomFichier.c_str());
    if(monFlux)    
    {
		CelluleTrajet* p=m_catalogue->getPremier();
        while (p!=nullptr) // Parcours du Catalogue
		{
			if (p->getTrajet()->isCompose()==1) // On ajoute uniquement les trajets composés
			{
				p->getTrajet()->ecritureFichier(monFlux);
			}
			p=p->getSuivant();
		}
    }
    else
    {
        cerr << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
} //--------Fin Méthode sauvCompose

void Catalogue::sauvSimple (string nomFichier) const
{
    ofstream monFlux(nomFichier.c_str());
    if(monFlux)    
    {
		CelluleTrajet* p=m_catalogue->getPremier();
        while (p!=nullptr) // Parcours du Catalogue
		{
			if (p->getTrajet()->isCompose()==0) // On ajoute uniquement les trajets simples
			{
				p->getTrajet()->ecritureFichier(monFlux);
			}
			p=p->getSuivant();
		}
    }
    else
    {
        cerr << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
} //--------Fin Méthode sauvSimple

void Catalogue::sauvVoyage (string nomFichier,string depart,string arrivee) const
{
    ofstream monFlux(nomFichier.c_str());
    if(monFlux)    
    {
		CelluleTrajet* p=m_catalogue->getPremier();
        while (p!=nullptr) // Parcours du Catalogue
		{
			Trajet* t=p->getTrajet();
			if (strcmp(depart.c_str(),t->getDepart())==0 && strcmp(arrivee.c_str(),t->getArrivee())==0) {
				p->getTrajet()->ecritureFichier(monFlux);
			}
			p=p->getSuivant();
		}
    }
    else
    {
        cerr << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}//--------Fin Méthode sauvVille

void Catalogue::sauvDepart (string nomFichier,string depart) const
{
    ofstream monFlux(nomFichier.c_str());
    if(monFlux)    
    {
		CelluleTrajet* p=m_catalogue->getPremier();
        while (p!=nullptr) // Parcours du Catalogue
		{
			Trajet* t=p->getTrajet();
			if (strcmp(depart.c_str(),t->getDepart())==0) {
				p->getTrajet()->ecritureFichier(monFlux);
			}
			p=p->getSuivant();
		}
    }
    else
    {
        cerr << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}//--------Fin Méthode sauvDepart

void Catalogue::sauvArrivee (string nomFichier,string arrivee) const
{
    ofstream monFlux(nomFichier.c_str());
    if(monFlux)    
    {
		CelluleTrajet* p=m_catalogue->getPremier();
        while (p!=nullptr) // Parcours du Catalogue
		{
			Trajet* t=p->getTrajet();
			if (strcmp(arrivee.c_str(),t->getArrivee())==0) {
				p->getTrajet()->ecritureFichier(monFlux);
			}
			p=p->getSuivant();
		}
    }
    else
    {
        cerr << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}//--------Fin Méthode sauvArrivee


//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue ()  
{
	m_catalogue=new ListeChainee();
}//--------Fin Constructeur Catalogue

Catalogue::~Catalogue()
{
	delete m_catalogue;
}//--------Fin destructeur ~Catalogue