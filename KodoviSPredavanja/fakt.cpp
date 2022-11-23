#include <iostream>
#include <unistd.h>

using namespace std;

int fakt(int n){
    if(n<=1) return 1;
    return n * fakt(n-1);
}

int faktI(int n){
    int f=1;

    for (int i = 1; i <= n; i++){
        f*=i;
    }

    return f;
}

int main(){

    int n;

    cout << "Unesi n > ";
    cin >> n;

    cout << n << "! = " << fakt(n) << endl;
    cout << n << "! = " << faktI(n) << endl;


    return 0;
}