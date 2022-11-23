#include <iostream>
#include <cmath>


using namespace std;

void f(int polje[], int n, int m){
    if (n == 0) return;
    else {
        polje[n-1] = pow(m, (n-1));
        f(polje, n-1, m);
    }
}

int main(){
    int n;
    cout << "Vel polja, molim: ";
    cin >> n;
    int *polje = new int[n];


    int m;
    cout << "Broji koji ce biti potenciran: ";
    cin >> m;

    f(polje,n,m);

    cout << "Polje: ";
    for(int i=0; i<n; i++){
        cout << polje[i] << " ";
    }
    cout << endl;


    return 0;
}