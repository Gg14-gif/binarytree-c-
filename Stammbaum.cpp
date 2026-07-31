/*
 * Stamnbaum.cpp
 *
 *  Created on: 28.06.2026
 *      Author: bayka
 */

#include "Stammbaum.h"
#include <iostream>
#include <fstream>
using namespace std;

Stammbaum::Stammbaum() :
		Wurzel(nullptr), aktuell(nullptr) {
}

Stammbaum::~Stammbaum() {
	deleteTree(Wurzel);
}

void Stammbaum::deleteTree(Person *Knoten) {
	if (Knoten) {
		deleteTree(Knoten->Vater);
		deleteTree(Knoten->Mutter);
		delete Knoten;
	}
}

void Stammbaum::createWurzel(std::string &Vorname, std::string &Nachname) {
	if (Wurzel == nullptr) {
		Wurzel = new Person;
		Wurzel->Vorname = Vorname;
		Wurzel->Nachname = Nachname;
		Wurzel->Vater = nullptr;
		Wurzel->Mutter = nullptr;
		Wurzel->Kind = nullptr;
		aktuell = Wurzel;
	} else {
		std::cout << "Eine Wurzel ist bereits vorhanden";
	}
}
void Stammbaum::addVater(std::string &Vorname, std::string &nachname) {
	if (aktuell) {
		if (aktuell->Vater == nullptr) {
			aktuell->Vater = new Person;
			aktuell->Vater->Vorname = Vorname;
			aktuell->Vater->Nachname = nachname;
			aktuell->Vater->Kind = aktuell;
			aktuell->Vater->Vater = nullptr;
			aktuell->Vater->Mutter = nullptr;
		} else {
			std::cout << "Vater wurde bereits eingetragen";
		}
	}
}
void Stammbaum::addMutter(std::string &Vorname, std::string &nachname) {
	if (aktuell) {
		if (aktuell->Mutter == nullptr) {
			aktuell->Mutter = new Person;
			aktuell->Mutter->Vorname = Vorname;
			aktuell->Mutter->Nachname = nachname;
			aktuell->Mutter->Kind = aktuell;
			aktuell->Mutter->Mutter = nullptr;
			aktuell->Mutter->Vater = nullptr;

		} else {
			std::cout << "Mutter wurde bereits eingetragen";
		}
	}
}
void Stammbaum::gehezuVater() {
	if ((aktuell && aktuell->Vater)) {
		aktuell = aktuell->Vater;
	} else {
		std::cout << "Entweder kein Vater oder nicht eingetragen";
	}
}
void Stammbaum::gehezuMutter() {
	if ((aktuell && aktuell->Mutter)) {
		aktuell = aktuell->Mutter;
	} else {
		std::cout << "Entweder keine Mutter oder nicht eingetragen";

	}
}

void Stammbaum::gehezuKind() {
	if ((aktuell && aktuell->Kind)) {
		aktuell = aktuell->Kind;

	} else {
		std::cout << "keine Kinder eingetragen";
	}
}

void Stammbaum::speicherRekursiv(std::ofstream &outfile, Person *Knoten) {
	if (Knoten == nullptr) {
		outfile << "Nicht_eingetragen" << endl;
	} else {

		outfile << Knoten->Vorname << endl;
		outfile << Knoten->Nachname << endl;
		Stammbaum::speicherRekursiv(outfile, Knoten->Vater);
		Stammbaum::speicherRekursiv(outfile, Knoten->Mutter);
	}

}
void Stammbaum::speichernDatei() { // prof hat geholfen
	ofstream outfile("StammbaumVersuch");
	Stammbaum::speicherRekursiv(outfile, Wurzel);
	outfile.close();
}
void Stammbaum::PrintRekursiv(Person *knoten, int tiefe, char typ) {
	// Cgeht bis letzter knoten vater  und dann nach hinten
	if (knoten->Vater != nullptr) {
		PrintRekursiv(knoten->Vater, tiefe + 1, 'V');
	}

	for (int i = 0; i < tiefe; ++i) {
		cout << "    ";
	}
	//PRINTER
	if (knoten == aktuell) {
		cout << ">>> ";
	} else if (typ == 'V') {
		cout << "/-- ";
	} else if (typ == 'M') {
		cout << "\\-- ";
	} else {
		cout << "--- ";
	}
	// das gleiche wie bei vater
	cout << knoten->Vorname << " " << knoten->Nachname << endl;
	if (knoten->Mutter != nullptr) {
		PrintRekursiv(knoten->Mutter, tiefe + 1, 'M');
	}
}

void Stammbaum::printTree() {
	if (Wurzel == nullptr) {
		cout << "der Stammbaum ist leer" << endl;
	} else {
		Stammbaum::PrintRekursiv(Wurzel, 0, 'r');
	}
}
Stammbaum::Person* Stammbaum::ladeRekursiv(std::ifstream &filein) {
	string Vorname;
	string Nachname;
	filein >> Vorname;
	if (Vorname == "Nicht_eingetragen") {
		cout << "nullptr"<<endl;
		return nullptr;
	}
	filein >> Nachname;
	Person *Ladekonstrukt = new Person;
	Ladekonstrukt->Vorname = Vorname;
	Ladekonstrukt->Nachname = Nachname;
	Ladekonstrukt->Kind = nullptr;
	cout << Vorname << " "<< Nachname << " beispiel" <<endl;
	Ladekonstrukt->Vater = Stammbaum::ladeRekursiv(filein);
	Ladekonstrukt->Mutter = Stammbaum::ladeRekursiv(filein);

	if (Ladekonstrukt -> Vater!= nullptr) {
		Ladekonstrukt->Vater->Kind = Ladekonstrukt;

	}
	if (Ladekonstrukt ->Mutter != nullptr) {
		Ladekonstrukt->Mutter->Kind = Ladekonstrukt;

	}
	return Ladekonstrukt;

}

void Stammbaum::DateiLaden() {

	std::ifstream filein;
	filein.open("StammbaumVersuch");
	//if(in.is_open()){
	deleteTree(Wurzel);
	Wurzel = Stammbaum::ladeRekursiv(filein);
	aktuell = Wurzel;
	filein.close();

	//}
	//else{
	//	cout<<"Fehler beim öffnen der Datei"<<endl;
	//}
}
