// Radi, ali provjerit:
// "Warning (line 34|) control reaches end of non-void function"

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Lista{
    template<class X>
    struct Cvor{
        X el;
        Cvor<X>* next;
    };
    Cvor<T>* head = nullptr;

    public:
        bool upis(string element){
            Cvor<string> *newElement = new Cvor<string>;

            if (newElement == nullptr) return false;
            
            newElement->el = element;
            newElement->next = nullptr;

            if (!head) { // prazna lista
            head = newElement;
            } else {
            
            Cvor<string> *p;
            for (p = head; p->next; p = p->next); // iteracija na kraj liste
            p->next = newElement;
            return true;
            }
        }



        void ispis(){
            cout << "Lista: ";
            for (Cvor<T>* p = head; p != nullptr; p = p->next)
                cout << p->el << " ";
            cout << endl;
        }
};

int main(){
    int n = 11;
    do{
    cout << "Unesi n (<=10): ";
    cin >> n;
    } while (n>10);

    Lista<string> lista;
    string tmp;

    for (int i = 0; i<n; i++){
        cout << i+1 << ". broj: ";
        cin >> tmp;
        lista.upis(tmp);
    }

    lista.ispis();
    
    return 0;
}
