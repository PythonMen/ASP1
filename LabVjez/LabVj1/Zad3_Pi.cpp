#include <iostream>
#include <cmath>

using namespace std;

double pi (double n){
    if (n==1){
        return 4;
    }
    else{
        return pi(n-1) + 4 * (pow(-1,n+1) * (1/(2*n-1)));
    }
}


int main(){
    int n;
    cout << "Unesi n: ";
    cin >> n;
    double A[n];

    for (int i=0; i<n; i++){
        A[i] = pi(i+1);
    }

    cout << "Pi: ";
    for (int i=0; i<n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}