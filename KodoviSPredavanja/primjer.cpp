#include <chrono>
#include <iostream>

using namespace std::chrono;
using namespace std;

int main(){
    srand(time(0));

    int n = 10000;

    int sortiranoPolje[n];

    sortiranoPolje[0] = 1;

    for (int i=1; i<n; i++){
        sortiranoPolje[i] = sortiranoPolje[i-1] + rand()%20;
    }

    for (int i = 0; i<100; i++){
        cout << sortiranoPolje[i] << endl;
    }

    int x = sortiranoPolje[n-1] + 1;


    return 0;
}