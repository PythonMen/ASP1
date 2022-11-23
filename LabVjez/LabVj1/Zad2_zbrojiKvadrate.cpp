#include <iostream>
#include <cmath>

using namespace std;

int zbrojiKvadrate (int polje [], int n){
    static int sum=0;
    if (n==-1) return sum;
    if (sqrt(polje[n]) - int(sqrt(polje[n])) == 0) sum+=polje[n];
    return zbrojiKvadrate(polje, n-1);
}

int main(){
    int n;
    srand(time(NULL));


    cout << "Upisati n: ";
    cin >> n;
    int A[n];

    cout << "Polje: ";
    for (int i = 0; i < n; i++){
        A[i] = rand()%101;
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "Suma kvadrata: " << zbrojiKvadrate(A,n) << endl;

    return 0;
}