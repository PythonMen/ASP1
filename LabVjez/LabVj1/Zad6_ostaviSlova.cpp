#include <iostream>

using namespace std;

char *ostaviSlova (string ulaz){
    int charNum = 0;

    for (char& c : ulaz){
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') charNum++;
    }

    char *newString = new char[charNum+1];
    int i=0;

    for (char& c: ulaz){
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') newString[i++] = c;
    }

    newString[i] = '\0';

    return newString;
}

int main(){
    string ulaz = "asp12_i_ASP13";
    cout << ostaviSlova(ulaz) << endl;

    return 0;
}