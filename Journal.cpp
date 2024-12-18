#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
#include <vector>

using namespace std;

class journal
{
    private:
    public:
    void afficherHeureFichierExterne(string fichier)
    {
        auto now = chrono::system_clock::now();
        time_t current_time = chrono::system_clock::to_time_t(now);
        tm* local_time = localtime(&current_time);
        char buffer[100];
        strftime(buffer, sizeof(buffer), "%d%m%Y  %H:%M:%S", local_time);
        fstream monFlux(fichier, ios::app);
        monFlux <<  buffer;
        monFlux.close();
    }
    void afficherMessage(string aAfficher, string fichier)
    {
        fstream monFlux(fichier, ios::app);
        monFlux << " :    " << aAfficher << endl;
        monFlux.close();
    }
    vector<string> TrouverPrecedenteEntree(string jour , string mois, string annee)
    {
        ifstream outerFlux("C:/Users/Anis Djerrab/Documents/C++ oriente objet/JournalDeBord.txt");
        vector<string> chosesARetourner;
        string tout;
        string tout2;
        string indicateur;
        while (outerFlux >> indicateur)
        {
            if (indicateur==jour+mois+annee)
            {
                outerFlux.ignore();
                getline(outerFlux, tout);
                tout2 = jour + mois + annee + "  " + tout;
                chosesARetourner.push_back(tout2);
            }
            else if (indicateur!=jour+mois+annee)
            {
                outerFlux.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        return chosesARetourner;
    }
};


int main()
{
    string const fichier("C:/Users/Anis Djerrab/Documents/C++ oriente objet/JournalDeBord.txt");
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\033[34m";
    cout << "                    ********      **********     *          *        ***********          *             *               *                *" << endl;
    cout << "                   *      *      *        *     *          *        *         *           *            **              * *               *" << endl;
    cout << "                  *      *      *        *     *          *        *         *            *           * *             *   *              *" << endl;
    cout << "                 *      *      *        *     *          *        ***********             *          *  *            *     *             *" << endl;
    cout << "                *      *      *        *     *          *        * *                      *         *   *           *       *            *" << endl;
    cout << "               *      *      *        *     *          *        *   *                     *        *    *          *         *           *" << endl;
    cout << "              *      *      *        *     *          *        *     *                    *       *     *         *************          *" << endl;
    cout << "             *      *      *        *     *          *        *       *                   *      *      *        *             *         *" << endl;
    cout << "            *      *      *        *     *          *        *         *                  *     *       *       *               *        *" << endl;
    cout << "           *      *      *        *     *          *        *           *                 *    *        *      *                 *       *" << endl;
    cout << "   ********      *      *        *     *          *        *             *                *   *         *     *                   *      *" << endl;
    cout << "  *             *      *        *     *          *        *               *               *  *          *    *                     *     *" << endl;
    cout << " *             *      *        *     *          *        *                 *              * *           *   *                       *    *               " << endl;
    cout << "***************      **********     ************        *                   *             *             *  *                         *   *****************" << endl;
    cout << "\033[0m";
    cout << endl;
    cout << endl;
    while (true)
    {
        journal JOURNAL;
        string confirmation;
        cout << "\033[33mVoulez vous entrer une nouvelle sauvegarde? (Y/n)  \033[0m";
        cout << endl;
        cin >> confirmation;
        cin.ignore();
        if (confirmation == "Y")
        {
            JOURNAL.afficherHeureFichierExterne(fichier);
            string variable;
            string total;
            cout << endl;
            cout << "\033[33mEntrez votre Texte :      \033[0m";
            getline(cin, variable);
            cin.ignore();
            JOURNAL.afficherMessage(variable, fichier);
            cout << endl;
            cout << "\033[32mVotre fichier a ete sauvegarde avec succes!\033[0m" << endl;
        }

        string confir;
        cout << endl;
        cout << "\033[33mvoulez vous jeter un coup d'oeil a vos precedentes sauvegardes? (Y/n)  \033[0m";
        cin >> confir;
        if (confir == "Y")
        {
            string jour;
            string mois;
            string annee;
            cout << endl;
            cout << "\033[33mMaintenant, vous allez entrer le jour, le mois et l'annee de cette sauvegarde : \033[0m" << endl;
            cout << "\033[32mJour : \033[0m";
            cin >> jour;
            cout << "\033[32mMois : \033[0m";
            cin >> mois;
            cout << "\033[32mAnnee : \033[0m";
            cin >> annee;
            if (jour != "0" and mois != "0" and annee != "0")
            {
                vector<string> texte = JOURNAL.TrouverPrecedenteEntree(jour, mois, annee);
                int n(0);
                string u;
                vector<string> premiereParties;
                vector<string> secondeParties;
                for (int i(0); i < texte.size(); i++)
                {
                    string premierePartie, secondePartie;
                    for (int o(0); o < texte[i].size(); o++)
                    {
                        u = texte[i];
                        if (n <= 23)
                        {
                            premierePartie += u[o];
                            if (o == 3)
                            {
                                premierePartie += " ";
                            }
                            else if (o == 5)
                            {
                                premierePartie += " ";
                            }
                        }
                        else
                        {
                        secondePartie += u[o]; 
                        }
                        n++;

                        
                        
                    }
                    premiereParties.push_back(premierePartie);
                    secondeParties.push_back(secondePartie);
                    n = 0;
                }
                cout << endl;
                cout << endl;
                for (int i(0); i < premiereParties.size(); i++)
                {
                    cout << "\033[1;32m" << premiereParties[i] << "\033[0m" <<"\033[33m" << secondeParties[i] << "\033[0m" << endl;
                }
                if (premiereParties.empty())
                {
                    cout << "\033[31mDate invalide! \033[0m" << endl;
                }
            }
            else
            {
                cout << "\033[31mdate invalide!\033[0m" << endl;
            }
        }
        cout << endl;
        string decision;
        cout << "\033[31mvoulez vous quitter le programme? (Y/n) \033[0m" << endl;
        cin >> decision;
        cout << endl;
        cout << endl;
        cout << endl;
        if (decision!="n")
        {
            cout << "\033[31mMerci d'avoir utilise ce programme et de soutenir mon travail :)\033[0m";
            cout << endl;
            break;
        }
    }
    return 0;
}