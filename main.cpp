/*************************************************************************
                           main -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du fichier principal (fichier main.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#define TAILLE_MOT 100
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "CelluleTrajet.h"
#include "ListeChainee.h"
#include "Catalogue.h"


int main() 
{
    cout<<"\n_______Bienvenue dans le Programme Trajet+ !_______\n"<<endl;
    Catalogue cat;
    unsigned int choixMenu=0; //entier caractérisant le choix dans le menu
    do {
        cout<<"-----------------MENU-------------------"<<endl;
        cout<<"1) Ajouter un Trajet Simple "<<endl;
        cout<<"2) Ajouter un Trajet Composé "<<endl;
        cout<<"3) Afficher le Catalogue courrant "<<endl;
        cout<<"4) Rechercher un Itinéraire "<<endl;
        cout<<"5) Sauvegarder le Catalogue "<<endl;
        cout<<"6) Importer un Catalogue "<<endl;
        cout<<"7) Quitter le Programme "<<endl;
        cout<<"----------------------------------------"<<endl;
        cin>> choixMenu;
        while (choixMenu != 1 && choixMenu !=2 && choixMenu !=3 && choixMenu !=4 && choixMenu !=5 && choixMenu!=6 && choixMenu!=7)
        {
            cout<<"Veuillez saisir un numéro correct : "<<endl;
            cin>>choixMenu;
        }

        switch (choixMenu)
        {
            case 1 : 
            {
            cout<<"-----Vous avez choisi d'ajouter un trajet simple-----"<<endl;
            //---Les trois buffers d'entrée :
	        char dep [TAILLE_MOT];
	        char moy [TAILLE_MOT];
	        char arr [TAILLE_MOT];
            //---Intervention de l'utilisateur 
            cout<<"Veuillez saisir la ville de départ : "<<endl;
            cin>>dep;
            cout<<"Veuillez saisir le moyen de transport : "<<endl;
            cin>>moy;
            cout<<"Veuillez saisir la ville d'arrivée : "<<endl;
            cin>>arr;
            cat.insertOrd(new TrajetSimple(dep,arr,moy)); //---Insertion ordonée du nouveau trajet que l'on alloue
            cout<<"Le Trajet a bien été ajouté. "<<endl;
            break;
            }

            case 2 :
            {
            cout<<"-----Vous avez choisi d'ajouter un trajet composé-----"<<endl;
            int choix(0);
            TrajetCompose* t;
            t=new TrajetCompose();
            //---Les trois buffers d'entrée :
	        char dep [TAILLE_MOT];
	        char moy [TAILLE_MOT];
	        char arr [TAILLE_MOT];
             //---Intervention de l'utilisateur 
            cout<<"Veuillez saisir la ville de départ : "<<endl;
            cin>>dep;
            cout<<"Veuillez saisir le moyen de transport : "<<endl;
            cin>>moy;
            cout<<"Veuillez saisir la ville d'arrivée : "<<endl;
            cin>>arr;
            t->ajouterTrajet( new TrajetSimple(dep,arr,moy));
            cout<<"Voulez-vous rajouter une étape au Trajet ? "<<endl;
            cout<<"1) Oui "<<endl;
            cout<<"2) Non "<<endl;
            cin>>choix;
            while (choix==1) 
            {
	    	    char moy [TAILLE_MOT];
	    	    char arr [TAILLE_MOT];
                cout<<"Veuillez saisir la ville d'arrivée : "<<endl;
                cin>>arr;
                cout<<"Veuillez saisir le moyen de transport : "<<endl;
                cin>>moy;
                t->ajouterEtape(moy,arr);
                cout<<"Voulez-vous rajouter une étape au Trajet ? "<<endl;
                cout<<"1) Oui "<<endl;
                cout<<"2) Non "<<endl;
                cin>>choix;
                while (choix!=1 && choix!=2) //---Boucle permettant le contrôle de la cohérence de l'entier inséré par l'utilisateur
                    {
                    cout<<"Veuillez saisir une réponse correcte : "<<endl;
                    cout<<"Voulez-vous rajouter une étape au Trajet ? "<<endl;
                    cout<<"1) Oui "<<endl;
                    cout<<"2) Non "<<endl;
                    cin>>choix;
                    }   
            }
            cat.insertOrd(t);//---Insertion ordonée du nouveau trajet composé
            cout<<"Le Trajet a bien été ajouté. "<<endl;
            break; 
            } 

            case 3 : 
            {
            cat.afficherCat();//---Appel à la méthode d'affichage du catalogue
            break;
            }

            case 4 :
            {
            cout<<"-----Vous avez choisi de faire une recherche d'itinéraire simple-----"<<endl;   
            //---Les deux buffers d'entrée 
	        char dep [TAILLE_MOT];
	        char arr [TAILLE_MOT];
            //---Insertion par l'utilisateur
            cout<<"Veuillez saisir la ville de départ : "<<endl;
            cin>>dep;
            cout<<"Veuillez saisir la ville d'arrivée : "<<endl;
            cin>>arr;
            cout<<"-----Les résultats sont :-----"<<endl;
            cat.itineraire(dep,arr);//---Appel à la méthode de recherche d'itinéraires
            break;
            }

            case 5 :
            { 
            unsigned int choixSauv=0;
            cout<<"-----Vous avez choisi d'effectuer une Sauvegarde-----"<<endl;
            cout<<"Veuillez choisir le type de sauvegarde à effectuer : "<<endl;
            cout<<"1) Sauvegarder tout le catalogue "<<endl;
            cout<<"2) Sauvegarder tous les trajets simples "<<endl;
            cout<<"3) Sauvegarder tous les trajets composés  "<<endl;
            cout<<"4) Sauvegarder tous les trajets correspondant à un voyage "<<endl;
            cout<<"5) Sauvegarder tous les trajets partants d'une ville "<<endl;
            cout<<"6) Sauvegarder tous les trajets arrivants dans une ville "<<endl;
            cin>>choixSauv; //---Insertion par l'utilisateur
            while (choixSauv != 1 && choixSauv !=2 && choixSauv !=3 && choixSauv !=4 && choixSauv!=5 && choixSauv!=6) //Controle du choix
            {
                cout<<"Veuillez saisir un numéro correct : "<<endl;
                cin>>choixSauv;
            }
            switch (choixSauv)
            {
                case 1 :
                {
                string nom;
                cout<<"Veuillez entrer le nom du fichier sauvegarde :"<<endl;
                cin>>nom; //---Insertion par l'utilisateur
                cat.sauvTout(nom); //---Appel à la méthode de sauvegarde du catalogue
                break;
                }
                case 2 :
                {
                string nom;
                cout<<"Veuillez entrer le nom du fichier sauvegarde :"<<endl;
                cin>>nom; //---Insertion par l'utilisateur
                cat.sauvSimple(nom); //---Appel à la méthode de sauvegarde du catalogue
                break;
                }
                case 3 :
                {
                string nom;
                cout<<"Veuillez entrer le nom du fichier sauvegarde :"<<endl;
                cin>>nom; //---Insertion par l'utilisateur
                cat.sauvCompose(nom); //---Appel à la méthode de sauvegarde du catalogue
                break;
                }
                case 4 :
                {
                string nom,depart,arrivee;
                cout<<"Veuillez entrer le nom du fichier sauvegarde :"<<endl;
                cin>>nom; //---Insertion par l'utilisateur
                cout<<"Veuillez entrer la ville de départ :"<<endl;
                cin>>depart; //---Insertion par l'utilisateur
                cout<<"Veuillez entrer la ville d'arrivée :"<<endl;
                cin>>arrivee; //---Insertion par l'utilisateur
                cat.sauvVoyage(nom,depart,arrivee); //---Appel à la méthode de sauvegarde du catalogue
                break;
                }
                case 5 :
                {
                string nom,depart;
                cout<<"Veuillez entrer le nom du fichier sauvegarde :"<<endl;
                cin>>nom; //---Insertion par l'utilisateur
                cout<<"Veuillez entrer la ville de départ :"<<endl;
                cin>>depart; //---Insertion par l'utilisateur
                cat.sauvDepart(nom,depart); //---Appel à la méthode de sauvegarde du catalogue
                break;
                }
                case 6 :
                {
                string nom,arrivee;
                cout<<"Veuillez entrer le nom du fichier sauvegarde :"<<endl;
                cin>>nom; //---Insertion par l'utilisateur
                cout<<"Veuillez entrer la ville d'arrivée :"<<endl;
                cin>>arrivee; //---Insertion par l'utilisateur
                cat.sauvArrivee(nom,arrivee); //---Appel à la méthode de sauvegarde du catalogue
                break;
                }  
            }
            break;
            }

            case 6 :
            {
            unsigned int choixSauv=0;
            cout<<"-----Vous avez choisi de charger des trajets-----"<<endl;
            cout<<"Veuillez choisir le type d'import : "<<endl;
            cout<<"1) Charger un catalogue en entier "<<endl;
            cout<<"2) Charger tous les trajets simples d'un catalogue "<<endl;
            cout<<"3) Charger tous les trajets composés d'un catalogue  "<<endl;
            cout<<"4) Charger tous les trajets correspondant à un voyage d'un catalogue "<<endl;
            cout<<"5) Charger tous les trajets partant d'une ville d'un catalogue "<<endl;
            cout<<"6) Charger tous les trajets arrivant dans une ville d'un catalogue "<<endl;
            cin>>choixSauv; //---Insertion par l'utilisateur
            while (choixSauv != 1 && choixSauv !=2 && choixSauv !=3 && choixSauv !=4 && choixSauv!=5 && choixSauv!=6)
            {
                cout<<"Veuillez saisir un numéro correct : "<<endl;
                cin>>choixSauv; //---Insertion par l'utilisateur
            }
            switch (choixSauv)
            {
                case 1 :
                {
                string nom;
                cout<<"Veuillez entrer le nom du fichier d'import :"<<endl;
                cin>>nom; //---Insertion par l'utilisateur
                cat.chargerToutCat(nom); //---Appel à la méthode d'import du catalogue
                break;
                }
                case 2 :
                {
                string nom;
                cout<<"Veuillez entrer le nom du fichier d'import :"<<endl;
                cin>>nom; //---Insertion par l'utilisateur
                cat.chargerSimple(nom); //---Appel à la méthode d'import du catalogue
                break;
                }
                case 3 :
                {
                string nom;
                cout<<"Veuillez entrer le nom du fichier d'import :"<<endl;
                cin>>nom; //---Insertion par l'utilisateur
                cat.chargerCompose(nom); //---Appel à la méthode d'import du catalogue
                break;
                }
                case 4 :
                {
                string nom,depart,arrivee;
                cout<<"Veuillez entrer le nom du fichier d'import :"<<endl;
                cin>>nom; //---Insertion par l'utilisateur
                cout<<"Veuillez entrer la ville de départ :"<<endl;
                cin>>depart; //---Insertion par l'utilisateur
                cout<<"Veuillez entrer la ville d'arrivée :"<<endl;
                cin>>arrivee; //---Insertion par l'utilisateur
                cat.chargerVoyage(nom,depart,arrivee); //---Appel à la méthode d'import du catalogue
                break;
                }
                case 5 :
                {
                string nom,depart;
                cout<<"Veuillez entrer le nom du fichier d'import :"<<endl;
                cin>>nom; //---Insertion par l'utilisateur
                cout<<"Veuillez entrer la ville de départ :"<<endl;
                cin>>depart; //---Insertion par l'utilisateur
                cat.chargerDepart(nom,depart); //---Appel à la méthode d'import du catalogue
                break;
                }
                case 6 :
                {
                string nom,arrivee;
                cout<<"Veuillez entrer le nom du fichier d'import :"<<endl;
                cin>>nom; //---Insertion par l'utilisateur
                cout<<"Veuillez entrer la ville d'arrivée :"<<endl;
                cin>>arrivee; //---Insertion par l'utilisateur
                cat.chargerArrivee(nom,arrivee); //---Appel à la méthode d'import du catalogue
                break;
                } 
            }
            break;
            }       
        }
    } while (choixMenu!=7);
    cout<<"________Merci, à bientôt !________"<<endl;
    return 0;

}
