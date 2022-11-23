#include <iostream>

using namespace std;

class Red{
    static const int MAX = 10;
    double red[MAX];
    int write = 0;
    int read = 0;

    public:
        bool enqueue(double el){
            if ((write + 1)%MAX == read){
                return false;
            }
            red[write] = el;
            write = (write+1)%MAX;
            return true;
        }

        bool dequeue(double &item){
            if (write == read){
                return false;
            }
            item = red[read];
            read = (read+1)%MAX;
            return true;
        }

};

int main(){
    int n;
    double x;
    Red r;
    do{
        cout << "Unesi n: ";
        cin >> n;
    } while(n>10 || n<0);

    for (int i = 0; i < n; i++){
        cout << "Unesi " << i+1 << ". broj: ";
        cin >> x;
        r.enqueue(x);
    }

    for(int i = 0; i < n; i++){
        r.dequeue(x);
        cout << x << " ";
    }

    return 0;
}