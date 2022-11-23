#include<iostream>
#include<ctime>

using namespace std;


void ispis (float* polje, int n){
    if (n == -1) return;
    if (*(polje+n) < 0) cout << *(polje+n) << " ";
    ispis(polje, n-1);
}

int main(){
    srand(time(NULL));
    int n;

    cout << "Unesi n: ";
    cin >> n;
    float *p = new float[n];
    cout << "Unesi članove niza:\n";
    for (int i = 0; i < n; i++){
        cin >> *(p+i);
    }

    cout << "Negativni članovi: ";
    ispis(p, n);
    cout << endl;

    return 0;
}