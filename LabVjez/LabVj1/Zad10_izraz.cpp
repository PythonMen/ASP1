#include <iostream>
#include <cmath>

using namespace std;

double f(double z, int k){
    if(k<0) return 0;
    else if (k==0) return z;
    else{
        return (-1*pow(z,2) * f(z,k-1))/ (((2*k)+1)*(2*k));
    }
}

int main(){
    double z=0.5;
    int k;

    while(true){
        cout << "k = ";
        cin >> k;

        if (k < 0){
            cout << "K mora biti >= 0." << endl;
        }
        else{
            cout << "f: " << f(z,k) << endl;
        }
    }
}