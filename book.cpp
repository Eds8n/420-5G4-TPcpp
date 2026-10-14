#include "book.h"
#include <sstream>
#include <vector>

// constructeurs

Book::Book() {
    title = "";
    author = "";
    isbn = "";
    isAvailable = true;
    borrowerId = "";
}

Book::Book(const string& title, const string& author, const string& isbn) {
    this->title = title;
    this->author = author;
    this->isbn = isbn;
    isAvailable = true;
    borrowerId = "";
}

// Getters
string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getISBN() const {
    return isbn;
}

bool Book::getAvailability() const {
    return isAvailable;
}

string Book::getBorrowerId() const {
    return borrowerId;
}

// Setters

void Book::setTitle(const string& title) {
    this->title = title;
}

void Book::setAuthor(const string& author) {
    this->author = author;
}

void Book::setISBN(const string& isbn) {
    this->isbn = isbn;
}

void Book::setAvailability(bool isAvailable) {
    this->isAvailable = isAvailable;
}

void Book::setBorrowerId(const string& id) {
    this->borrowerId = id;
}


// Emprunter et retourner des livres
void Book::checkOut(const string& borrowerId) {
    if (this-> isAvailable) {
        this->borrowerId = borrowerId;
        this->isAvailable = false;
    }
}

void Book::returnBook() {
    this-> isAvailable = true;
    this->borrowerId = "";
}

// afficher les livres en string
string Book::toString() const {
    string resultat = "Titre : " + title + "\nAutheur : " + author + "\nISBN : " + isbn + "\ndisponibilite : " + (isAvailable ? "Disponible" : "Pas Disponible");
    return resultat;
}

// affichage des donnees en FileFormat
string Book::toFileFormat() const {
    return title + "|" + author + "|" + isbn + "|" + (isAvailable ? "1|" : "0|" + borrowerId);
}


void Book::fromFileFormat(const string& line) {
    vector<string> donnees;
    stringstream ss(line);
    string texte;

    while (getline(ss, texte, '|')) {
        donnees.push_back(texte);
    }

    if (!line.empty() && line.back() == '|') {
        donnees.push_back("");
    }

    if (donnees.size() != 5) {
        return;
    }

    title = donnees[0];
    author = donnees[1];
    isbn = donnees[2];
    isAvailable = (donnees[3] == "1");
    borrowerId = donnees[4];
}

