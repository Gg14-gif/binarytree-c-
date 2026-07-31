#ifndef STAMMBAUM_H
#define STAMMBAUM_H

#include <string>
#include <iosfwd>
#include <iostream>
#include <fstream>
class Stammbaum {
private :
struct  Person{
	std::string Vorname;
	std::string Nachname;
	Person * Vater;
	Person *Mutter;
	Person * Kind;
};

Person * Wurzel=nullptr;
Person * aktuell=nullptr;


/* erstellePerson(const std::string& vorname,
                           const std::string& nachname);*/


void speicherRekursiv (std::ofstream &outfile, Person* Knoten); // finished
Person * ladeRekursiv(std::ifstream& in); //finished
void deleteTree(Person * Knoten ); // finished
public:
Stammbaum();
~Stammbaum();

void PrintRekursiv (Person * knoten , int tiefe , char typ); //finished
void createWurzel(std::string &Vorname ,std::string &Nachname ); // finished
void addVater (std::string & Vorname ,std::string&nachname); // finished
void addMutter (std::string & Vorname ,std::string&nachname); //finished

void gehezuVater(); // finished
void gehezuMutter(); // finished

void gehezuKind(); //finished

void speichernDatei(); // finished
void DateiLaden();

void printTree (); //finished
bool hasRoot () {
	return Wurzel != nullptr;
} // finished


};
#endif
