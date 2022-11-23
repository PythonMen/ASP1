#include <iostream>
#include <string>


using namespace std;

int main(){

    string s("Ja cu bit greška :(... ");

    try{
        cout << s.at(80) << endl;
    } catch (exception &e) {
        cerr << "Greška: " << e.what() << endl;
    }


    try{
        int i=0;
        if(i==0){
            throw invalid_argument("Division by 0");
        }
        int j = 5/i;
    } catch(invalid_argument &a){
        cerr << "Alo! Vidi ga, djeli s 0: " << a.what() << endl;
    }

    

    return 0;
}