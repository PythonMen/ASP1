// Radi

#include <iostream>
#include <time.h>

using namespace std;

template <typename T>
class Stog{
    static const int MAX = 100;
    T stog[100];
    int top = -1;

    public:
        bool push(T el){
            if (top >= 99) return false;
            else {
                stog[++top] = el;
                return true;
            }
        }

        bool pop(T &item){
            if (top < 0) return false;
            item = stog[top--];
            return true;
        }
};

int main(){
    srand(time(NULL));

    Stog<int> stog;
    int randNum;

    for(int i=0; i<=101; i++){
        randNum = rand()%21 - 10;
        cout << i+1 << ". -> " << randNum;
        if (stog.push(randNum)) cout << " spremljen u stog." << endl;
        else cout << " nije spremljen u stog." << endl;
    }
    cout << endl;

    return 0;
}