#include <iostream>

using namespace std;

template <typename T>
int binarnoTrazi(T polje[], int n, T x){
    int left = 0;
    int middle;
    int right = n-1;

    while (true){
        middle = (left + right)/2;
        if (polje[middle] == x) return middle;
        else if (left >= right) return -1;
        else if (x < polje[middle]){
            right = middle-1;
        }
        else if (x > polje[middle]){
            left = middle+1;
        }
    }
}

int main(){
    int n;
    cout << "Unesi velicinu polja: ";
    cin >> n;

    float A[n];

    float x;
    cout << "Unesite broj koji se trazi: ";
    cin >> x;

    cout << "Polje: ";
    for (int i = 0; i<n; i++){
        A[i] = i*1.1;
        cout << A[i] << " ";
    }

    int index = binarnoTrazi(A,n,x);

    if (index != -1) cout << endl<< "x nađen na poziciji: " << index << endl;
    else cout << endl << "x ne postoji u A..." << index << endl;



    return 0;
}