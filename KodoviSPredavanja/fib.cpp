#include <iostream>
#include <unistd.h>

using namespace std;

// FIBONACCI
// fib(0) = 1
// fib(1) = 1
// fib(2) = fib(0) + fib(1)
// fib(3) = fib(2) + fib(1)
// fib(3) = fib(0) + fib(1) + fib(1)
// fib(n) = fib(n-1) + fib(n-2)

// Rekurzivno:
int fib(int n){
    if (n <= 1) return 1;
    else{
        return fib(n-1) + fib(n-2);
    }
}

// Pointer na polje:
int* fibPolje(int n){
    int *f = new int[n];
    f[0] = f[1] = 1;
    for (int i=2; i<=n; i++){
        f[i] = f[i-1] + f[i-2];
    }
    return f;
}


// Iterativno:
int fibI(int n){
    int f;
    int prev = 1;
    int prevPrev = 1;

    for(int i=2; i<=n; i++){
        f = prev + prevPrev;
        prevPrev = prev;
        prev = f;
    }

    return f;
}



int main(){

    int n;

    cout << "Unesi n > ";
    cin >> n;

    // Rekurzivno
    cout << n << ". Fibonacciev broj = " << fib(n) << endl;
    

    // Poljima
    cout << "Polje fib brojeva do n=" << n <<": ";
    int* fpolje = fibPolje(n);
    for (int i=0; i<=n; i++){
        cout << *(fpolje + i) << " ";
    } cout << endl;


    // Iterativno
    cout << n << ". Fib broj računan iterativno: " << fibI(n) << endl;


    return 0;
}