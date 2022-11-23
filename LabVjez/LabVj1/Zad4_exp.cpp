#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int fact(int n){
    if (n == 0) return 1;
    else return n * fact(n-1);
}

double exp(double x, int n, int *fakt, double *xpot){
    if (n < 0) return 0;
    else return (*xpot) / (*fakt) + exp(x, n-1, fakt+1, xpot+1);
}

int main(){
    int n;
    double x;


    cout << "Upišite željenu veličinu polja: ";
    cin >> n;

    
    cout << "Upišite željenu vrijednost broja x: ";
    cin >> x;

    int *nthFactorial = new int[n];

    for (int i = 0; i < n; i++){
        nthFactorial[i] = fact(i);
    }
    
    cout << "Faktorijeli: ";
    for (int i = 0; i < n; i++){
        cout << nthFactorial[i] << " ";
    }

    double *xPot = new double[n];
    for (int i = 0; i < n; i++){
        xPot[i] = pow(x, i);
    }

    cout << endl << "Potencije: ";
    for (int i = 0; i < n; i++){
        cout << xPot[i] << " ";
    }

    double *A = new double[n];
    for (int i = 0; i < n; i++){
        A[i] = exp(x, i, nthFactorial, xPot);
    }

    cout << endl << "Polje A:";
    cout << fixed;
    cout << setprecision(6);
    for (int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    

    delete[] nthFactorial;
    delete[] xPot;
    delete[] A;

    return 0;
}