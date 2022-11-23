#include <iostream>

using namespace std;

class SanitizedString{
    private:
        string str;
    public:
        SanitizedString(string ulaz){
            str = ulaz;
            removeDuplicateWhitespace();
            removeNonAlphaChars();
        }

        void removeDuplicateWhitespace(){
            for (int i = 1; i< str.size(); i++){
                if(str[i] == ' ' && str[i-1] == ' '){
                    str.erase(str.begin() + i);
                    i--;
                }
            }
        }

        void removeNonAlphaChars(){
            for(int i=0; i<str.size(); i++){
                if(!(isalpha(str[i])) && str[i]!=' '){
                    str.erase(str.begin() + i);
                    i--;
                }
            }
        }

    friend ostream &operator<<(ostream &os, const SanitizedString &str);
};

ostream &operator<<(ostream &os, const SanitizedString &str)
{
    os << str.str;
    return os;
}

int main(){
    string ulaz;
    cout << "Unesi string: ";
    getline(cin, ulaz);

    SanitizedString sanitizedUlaz(ulaz);

    cout << "Sanitized: " << sanitizedUlaz << endl;
}