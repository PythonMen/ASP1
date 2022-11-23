#include <iostream>

using namespace std;

int Nzm(int a,int b){
    cout << "nzm(" << a << ", " << b << ") = ";
    if (b==0){
        cout << a << endl;
        return a;
    }
    return Nzm(b, a%b);

}

int main(){

    int a,b;

    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    int nzm = Nzm(a,b);

    return 0;
}