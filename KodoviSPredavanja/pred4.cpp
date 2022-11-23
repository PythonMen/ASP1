#include <iostream>
#include <string>
#include <memory>

using namespace std;

void fja(int iref) { cout << "iref: " << iref << endl;}

template <typename T>
T veci(T a, T b){
    return a>b? a:b;
};

class MojaKlasa{
    public:
        int i; double j; string s;
        MojaKlasa() {i=0;j=0;s="";}
        MojaKlasa(int i, double j, string s) : i(i), j(j), s(s){}
        ~MojaKlasa(){cout<< "Klasa uništena..."<<endl;}
};

template <class T> class MojiContainer{
    private:
        T obj;
    public:
        MojiContainer(T a): obj(a){}

        T getObj(){return obj;}
        void setObj(T obj){
            obj = obj;
        }
};


int main(){
    
    string ime("G'day"); // -> Odmah dodjeluje "G'day" u objekt ime
    cout << ime << endl;

    string ime2 = "Marko"; // -> Prvo stvara objekt ime2 i onda u njega dodaje "Marko"
    cout << ime << endl;

    ime = "Alo Marko";
    cout << ime << endl;

    ime += " druže!";
    cout << ime << endl;

    int* iNaHeapu = new int(5); // -> Stvaranje na heapu, tj iNaHeapu pokazuje na broj 5 na heapu
    cout << *iNaHeapu << endl;

    int i=3;
    int &ref = i;

    fja(i);
    fja(ref);
    fja(35);
    // ^ No shit, Sherlock...

    // fja(iNaHeapu); // Nope, nemre pointer ako očekuješ referencu. Također jedan "No shit, Sherlock..."

    fja(*iNaHeapu);

    // Generics/Templates:
    int br1 = 3;
    int br2 = 5;
    cout << "Veći broj je: " << veci(br1,br2) << endl;
    string s1 = "aaaaaa";
    string s2 = "bb";
    cout << "Veći string je: " << veci(s1,s2) << endl;

    cout << "Veći string je: " << veci("cc","bbb") << endl;

    unique_ptr<MojaKlasa> up1(new MojaKlasa());
    unique_ptr<MojaKlasa> up2(new MojaKlasa(2,3.0,"ae"));

    cout << "Unique Pointer 1, i: " << up1->i << endl;
    cout << "Unique Pointer 2, s: " << up2->s << endl;
    // Nakon izvršavanja poziva destructore
    
    shared_ptr<MojaKlasa> sp1(new MojaKlasa(3,1,"stringic"));

    cout << "Shared Pointer 1, s: " << sp1->s << endl;
    shared_ptr<MojaKlasa> sp2 = sp1;
    cout << "Shared Pointer 2, s: " << sp2 -> s << endl;
    cout << "Broj Shared Pointera: " << sp2.use_count() << endl;

    sp1.reset();
    cout << "Broj Shared Pointera: " << sp2.use_count() << endl;

    // smart pointer na int:
    unique_ptr<int> upInt(new int(59));
    cout << *upInt << endl;


    return 0;
}