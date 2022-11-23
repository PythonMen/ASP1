#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int* randomSquares (int *polje, int n){
    int *novoPolje = new int[n];
    bool usedIndex[n] = {};
    
    int newIndex,i=0;
    for (int i = 0; i<n; i++){
        while(true){
            newIndex = rand()%n;
            if (!usedIndex[newIndex]){
                novoPolje[i] = polje[newIndex]*polje[newIndex];
                usedIndex[newIndex] = true;
                break;
            }
        }
    }
    return novoPolje;
}

int main(){
    srand(time(NULL));
    int n;
    cout << "Velicina polja: ";
    cin >> n;
    int *polje = new int[n];


    for (int i=0;i<n;i++){
        polje[i] = rand()%20+1;
        cout << polje[i] << " ";
    }

    polje = randomSquares(polje, n);
    cout << endl;

    for (int i=0;i<n;i++){
        cout << polje[i] << " ";
    }
    cout << endl;



    return 0;
}