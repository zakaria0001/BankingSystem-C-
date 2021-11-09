#include <iostream>
#include <stdio.h>
#include "compte.h"

using namespace std;

// Fonction pour inserer le solde
compte::compte(double s)
{
    solde = s;
}

// Fonction pour deposer l'Argent
void compte::depotArgent(double montant)
{
    solde = solde + montant;
    cout << "Vous Avez Déposer " << montant << " Dhs , Votre  Nouveau Solde  est : " << solde << " Dhs \n";
}
void compte::depotArgent2emeCompte(double montant)
{
    solde = solde + montant;
    cout << "Message Au Compte N2 : Votre Compte a été créditer de " << montant << " Dhs , Votre  Nouveau Solde  est : " << solde << " Dhs \n";
}

// Fonction pour retraire l'argent
bool compte::retraitArgent(double montant)
{
    if (solde > montant)
    {
        solde = solde - montant;
        cout << "Vous Avez Retirer " << montant << " Dhs , Votre  Solde restant est : " << solde << " Dhs \n";
        return true;
    }
    else
    {
        cout << "Vous Avez Saisi Un Grand Montant \n";
        return false;
    }
}

// Fonction pour transferer l'argent
bool compte::transfertArgent(double montant, compte &c)
{

    if (retraitArgent(montant) == true)
    {

        c.depotArgent2emeCompte(montant);
        return true;
    }
    else
        return false;
}

// Fonction pour afficher son solde
double compte::getSolde()
{
    cout << "Votre Solde Actuel est :" << solde << " Dhs \n";
    return solde;
}

int choix;
int main()
{
    compte c1(1000), c2;
beginning:
    cout << "----------- MENU -----------\n";
    cout << "1- Dépot " << endl;
    cout << "2- Retrait " << endl;
    cout << "3- Transfére " << endl;
    cout << "4- Mon Solde" << endl;
    cout << "5- Quitter" << endl;

    cout << "Votre Choix : ";
    cin >> choix;

    string input;

    switch (choix)
    {
        double montant;
    case 1:

        cout << "Veuillez Saisir Le Montant Que Vous Souhaitez Déposer : ";
        cin >> montant;
        c1.depotArgent(montant);
        cout << "\nVoulez Vous Quitter Le Programme ? ( oui / non ) \n";
        cin >> input;

        if (input == "non")
            goto beginning;

        else
            cout << "Au Revoir !\n";
        break;

    case 2:
        cout << "Veuillez Saisir Le Montant Que Vous Souhaitez Retraire : ";
        cin >> montant;
        c1.retraitArgent(montant);
        cout << "\nVoulez Vous Quitter Le Programme ? ( oui / non ) \n";
        cin >> input;

        if (input == "non")
            goto beginning;

        else
            cout << "Au Revoir !\n";
        break;
    case 3:
        cout << "Veuillez Saisir Le Montant Que Vous Souhaitez Transférer : ";
        cin >> montant;
        cout << "Montant Transférer Avec Succès ! \n";
        c1.transfertArgent(montant, c2);
        cout << "\nVoulez Vous Quitter Le Programme ? ( oui / non ) \n";
        cin >> input;

        if (input == "non")
            goto beginning;

        else
            cout << "Au Revoir !\n";
        break;
    case 4:
        c1.getSolde();
        cout << "\nVoulez Vous Quitter Le Programme ? ( oui / non ) \n";
        cin >> input;

        if (input == "non")
            goto beginning;

        else
            cout << "Au Revoir !\n";
        break;
    case 5:
        cout << "Au Revoir !\n";
        break;
    default:
        break;
    }
}