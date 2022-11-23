#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;

class Point{
    public:     // Javni pristup
        double x,y;
        void print() {cout << "x = " << x << ", y = " << y << endl;}

        // Cool stvar za olakšavanje života: ovakvi konstruktori:
        
        Point(): x(0), y(0) {}
        Point(double xin, double yin) : x(xin), y(yin) {}

        /*
        // Klasični konstruktori rade, ali zašto se mućit ako ima ovo gore ^

        Point(){    // Konstruktor (isti kao u Javi)
            x = 0;
            y = 0;
        }

        
        Point(double xin, double yin){
            x = xin;    // U C++ ne radi this.y = y -> moraju različite varijable
            y = yin;
        }

        // this u C++ je pokazivac:
        
        Point(double x, double y){
           this -> x = x;
           this -> y = y;
        }

        */

       ~Point(){ cout << "Destruktor" << endl;} // ~SomeClass(){} se izvodi kada se objekt uništava. "Destruktor" jer se obično koristi za oslobađanje memorije
};

int main(){

    Point p;
    p.x = 1;
    p.y = 23;

    p.print();

    Point q;
    q = p; // Izjednačavanje vrijednosti, ne pokazivanje na istu točku!

    q.print();
    q.x = 5;

    cout << "p = "; p.print();
    cout << "q = "; q.print();

    Point *pp = &p;

    pp->print(); // MORA BIT "->" umjesto "." kod pointera!
    pp->x = 23;
    //Promjena na pointeru = promjena na onom na što pointer pokazuje!
    cout << "pp = "; pp->print(); 
    cout << "p = "; p.print();

    Point pDefKonstr;
    cout << "Inicijalizacija sa def konstruktorom:\n";
    pDefKonstr.print();

    Point pKonstr(1.23, 2.34);
    cout << "Inicijalizacija sa normalnim konstruktorom:\n";
    pKonstr.print();

    // Uniformna inicijalizacija -> type VariableName{parameters};
    // "Uniformna" jer vrijedi za sve živo (objekte, polja...)
    int i{20};
    cout << i << endl;
    Point r{2,6};
    r.print();

    // p + q;

    return 0;
}


