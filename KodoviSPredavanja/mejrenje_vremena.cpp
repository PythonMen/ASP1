#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int main(){
    
    srand(time(NULL));
    int x = rand()%20;
    int y = rand()%20;
    int odg;

    cout << "Koliko je " << x << " + " << y << "?" << endl;
    cout << "Odg? ";

    auto start = chrono::system_clock::now();

    cin >> odg;

    auto end = chrono::system_clock::now();

    cout << "Odgovor je " << (odg == (x+y)? "Tocan!":"Netocan!") << endl;

    auto d = end - start;
    cout << "Vrijeme: " << d.count() << endl;

}