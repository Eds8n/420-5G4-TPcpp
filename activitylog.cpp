#include "activitylog.h"
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>

ActivityLog::ActivityLog(const string& path) {
    this->filePath = path;
}

void ActivityLog::log(const string& action, const string& details) {
    ofstream fichier(filePath, ios::app);

    if (!fichier.is_open()) {
        cerr << "Erreur : Probleme d'ouverture du journal.\n";
        return;
    }

    time_t tempsActuel = time(nullptr);
    tm* dateActuelle = localtime(&tempsActuel);

    fichier << put_time(dateActuelle, "%Y-%m-%d %H:%M:%S")
            << " - [" << action << "] "
            << details << endl;
}