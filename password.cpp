#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <fstream>
#include <cstdio>
using namespace std;


void removeFile(string fichier)
{
    remove(fichier.c_str());
}
void CommencerMotDePasse()
{   
    string const fichier("C:/Users/Anis Djerrab/Documents/C++ oriente objet/mot_de_passe.txt");
    fstream monFlux(fichier, ios::app);
    monFlux << "--Anis Djerrab // 08/12/2024--" << endl;
    monFlux.close();
}

class Hasard
{
    private : 
    int nombre;
    vector<char> lettresChiffres;
    
    
    public : 
    Hasard(int nombre, const vector<char>& lettresChiffres) : nombre(nombre), lettresChiffres(lettresChiffres) {}
    vector<char> Generer_liste_Caractere()
    {
        vector<char> motDePasse;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, lettresChiffres.size() - 1);

        for (int i(0); i < nombre; i++)
        {
            int random_index = dis(gen);
            motDePasse.push_back(lettresChiffres[random_index]);
        
        }
        return motDePasse;
    }
    
    void erengisterMotDePasse(char mot, bool confirmation)
    {   
        string const fichier("C:/Users/Anis Djerrab/Documents/C++ oriente objet/mot_de_passe.txt");
        fstream monFlux;
        if (confirmation)
        {
            monFlux.open(fichier, ios::app);
            monFlux << mot;
        }
        else if (confirmation == false)
        {
            monFlux.open(fichier, ios::app);
            monFlux << endl;
        }
        monFlux.close();
    }
    string regarderMotDePasse(int nombre, int number)
    {
        string valeur;
        ifstream outerFlux("C:/Users/Anis Djerrab/Documents/C++ oriente objet/mot_de_passe.txt");
        for (int i(0); i < nombre+2; i++)
        {
            if (!getline(outerFlux, valeur)) 
            {
                return "";
            }
          
            
            

        }
        return valeur;

    }
    
};

int main()
{
    removeFile("C:/Users/Anis Djerrab/Documents/C++ oriente objet/mot_de_passe.txt");
    vector<char> lettresChiffres;
    int n(0);
    for (char c('A'); c <= 'Z'; c++)
        {
            lettresChiffres.push_back(c);
        }
    for (char c('a'); c <= 'z'; c++)
        {
            lettresChiffres.push_back(c);
        }
    for (char c('1'); c <= '9'; c++)
        {
            lettresChiffres.push_back(c);
        }
    string caracteres_speciaux("/:;,!!)?%^^<>-*+&___-");
    for (char c : caracteres_speciaux)
        {
            lettresChiffres.push_back(c);
        }
    CommencerMotDePasse();
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "************************************************************************************************************************************************************" << endl;
    cout << endl;
    cout << "\033[33mBienvenue sur le programme de generation et de sauvegarde de mots de passe aleatoire!\033[0m" << endl;
    cout << endl;
    cout << endl;

    while (true)
    {
        int nombre;
        
        cout << "\033[33mde combien de caracteres se composera votre mot de passe ?  \033[0m";
        while (true)
        {
            cin >> nombre;
            if (nombre >= 8)
            {
                cout << "\033[32mmot de passe valide!\033[0m" << endl;
                cout << endl;
                break;
            }
            else if (nombre > 0 and nombre < 8)
            {
                cout << endl;
                cout << "\033[33mmot de passe faible (<8 caracteres). etes vous sur de vouloir proceder (Y/n) : \033[0m";
                string Criteria;
                cin >> Criteria;
                if (Criteria != "Y")
                {
                    cout << "\033[33mentrez votre nouveau mot de passe : \033[0m";
                }
                else
                {
                    break;
                }
            }
            else
            {
                cout << endl;
                cout << "\033[31mmot de passe invalide. entrez votre nouveau mot de passe : \033[0m";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            }
        }
        
        
        Hasard HASARD(nombre, lettresChiffres);
        vector<char> motDePasse = HASARD.Generer_liste_Caractere();
        cout << "\033[1mVoici le mot de passe numero " << n << "  : \033[0m";
        for (int o(0); o < motDePasse.size(); o++)
            {
                cout << motDePasse[o];
            }
        cout << endl;
        cout << "\033[33mVoulez vous sauvegarder votre mot de passe dans un fichier exterieure ? (Y/n) : \033[0m";
        string sauvagarde_rapide;
        cin >> sauvagarde_rapide;
        if (sauvagarde_rapide=="Y")        
            for (int o(0); o < motDePasse.size(); o++) {
                    HASARD.erengisterMotDePasse(motDePasse[o], true);
                }
                HASARD.erengisterMotDePasse(motDePasse[0], false);

        cout << endl;
        string constataion;
        cout << "\033[33mVoulez vous regarder de precedent mots de passe (Y/n) ? \033[0m";
        cin >> constataion;
        if (constataion=="Y")
        {
            int number;
            cout << "\033[33mQuel est le numero du mot de pass que vous voulez consulter ? \033[0m";
            cin >> number;
            string valeur = HASARD.regarderMotDePasse(number, n);
            cout << endl;
            if (valeur!="")
            {
            
            
                cout << endl;
                cout << "\033[32mle mot de passe numero " << number << "est : " << valeur << " \033[0m" << endl;
                
            
            }
            else
            {
                cout << "\033[31mCe mot de passe n'existe pas!\033[0m" << endl;
            }
                
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        n++;
        cout << endl;

        string FinalConfirmation;
        cout << "\033[31mVoulez vous quitter ce programme ? (Y/n) : \033[0m";
        cin >> FinalConfirmation;
        if (FinalConfirmation=="Y")
        {
            cout << endl;
            cout << "\033[31mMerci d'avoir utilise ce programme et de soutenir mon travail :)\033[0m";
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "************************************************************************************************************************************************************" << endl;
            cout << endl;
            break;
        }
    }
    return 0;
}


