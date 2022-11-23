// Probaj skuzit zasto ovo radi?

#include <iostream>

using namespace std;

template <typename T>
class Lista{

    template <class X> 
    struct Cvor {
      X el;
      Cvor<X> *next;
    };
    Cvor<T> *head = nullptr;

    public:
        bool upis(T el) {
            Cvor<T> *newElement = new (nothrow) Cvor<T>;  // Novi Cvor za predani T el
            if (newElement == nullptr) return false;
            newElement->el = el;    
            Cvor<T> **p;
            for (p = &head; *p && el > (*p)->el; p = &((*p)->next));    // Vrtis kroz listu dok ne nades prvi element koji je veci od el ili dok *p nije nullptr
            newElement->next = *p;      // Postavis da je next taj prvi veci broj
            *p = newElement;
            return true;
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

    Lista<float> lista;
    float tmp;

    for (int i = 0; i<n; i++){
        cout << i+1 << ". broj: ";
        cin >> tmp;
        lista.upis(tmp);
    }

    lista.ispis();

    
    return 0;
}