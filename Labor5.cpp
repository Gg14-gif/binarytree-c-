//============================================================================
// Name        : Labor5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Stammbaum.h"
using namespace std;

int main() {
	Stammbaum Stamm;
string eingabe;
string  Vorname , Nachname;
string dateiname = "stammbaum.txt";
    while (eingabe != "q"){
    	cout<<"r = Root , v = erstelle Vater , m = erstelle Mutter,d = gehe zu Vater , a = gehe zu Mutter" <<endl;
    	cout <<" w = gehe zu Kind , s= Speicher ,f = Laden ,q = Quit"<<endl;
    	cin >> eingabe;
    if (eingabe == "r"){
    	cout<<"Vorname der Wurzel"<<endl;
    	cin>> Vorname;
    	cout<<"Nachname der Wurzel"<<endl;
    	cin>> Nachname;
    	Stamm.createWurzel(Vorname,Nachname);

    }
    else if (eingabe == "v"){
    	        cout<<"Vorname vom Vaters"<<endl;
    	    	cin>> Vorname;
    	    	cout<<"Nachname vom Vater"<<endl;
    	    	cin>> Nachname;
    	    	Stamm.addVater(Vorname,Nachname);
    }
    else if (eingabe == "m"){
    	  cout<<"Vorname von Mutter"<<endl;
    	    	    	cin>> Vorname;
    	    	    	cout<<"Nachname von Mutter "<<endl;
    	    	    	cin>> Nachname;
    	    	    	Stamm.addMutter(Vorname,Nachname);
       }
    else if (eingabe == "s"){
    	cout<< "dateiname eingeben"<<endl;
    	cin >> dateiname;
          Stamm.speichernDatei();
          cout << "Die Datei wurde gespeichert in "<<dateiname<< endl;
       }
    else if (eingabe == "f"){
                Stamm.DateiLaden();
                cout<< "Datei Erfolgreich geladen"<<endl;
       }
    else if (eingabe == "d"){
                  Stamm.gehezuVater();
       }
    else if (eingabe == "a"){
                  Stamm.gehezuMutter();
       }
    else if (eingabe == "w"){
                   Stamm.gehezuKind();
       }
    Stamm.printTree();
    }

    return 0;

}
