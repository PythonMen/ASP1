#include <iostream>
#include <string>

using namespace std;

int main(){

    int polje[10]{-5,1,3,2,6,0,9,123,32,-9};

    int n = sizeof(polje);  //40
    n /= sizeof(int);    // devided by size of intiger

    for (int i=0; i<n; i++){
        cout << polje[i] << " ";
    }
    cout << endl;

    for (int i=0;i<n; i++){
        polje[i]*=3;
        cout << polje[i] << " ";
    }
    cout << endl;

    // Traženje nekog broja

    cout << "Koji broj tražimo? ";
    int x;
    cin >> x;

    for (int i = 0; i<n; i++){
        if (polje[i] == x){
            cout << "Broj " << x << " je na indeksu " << i << endl;
            return 0;
        }
    }
    cout << "Broj " << x << " ne postoji u polju!" << endl;

    return 0;
}