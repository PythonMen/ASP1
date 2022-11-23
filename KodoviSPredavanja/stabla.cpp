// Provjeri zašto ispis ne radi...

#include <iostream>
#include <string>

#include <memory>
// Shared pointeri iz <memory>:
/*
    Dio smart pointera (pointeri koji služe za sprječavanje memory overflowa)
        uništit će pointer kada izađe iz nekog opsega memorije
        nešto kao garbage collection iz Jave
    Normalan (unique) pointer može pokazivati na samo jedan objekt, shared mogu na više
    Koristimo shared_ptr da ne moramo ručno stvarati i uništavati objekte
    Funkcioniraju u praksi isto kao i normalan pointer
*/


using namespace std;

template<typename T>
class BinaryTree{
    private:
        struct Atom{
            T data;
            shared_ptr<Atom> left;
            shared_ptr<Atom> right;

            Atom(const T data) : data(data), left(nullptr), right(nullptr){}
            Atom(const T data, shared_ptr<Atom> left, shared_ptr<Atom> right) : data(data), left(left), right(right){}

        };

        shared_ptr<Atom> root;

        void insertR(shared_ptr<Atom> node, T data){
            if (node != nullptr){
                if(data < node->data)
                    insertR(node->left, data);
                else if (data > node->data)
                    insertR(node->right, data);
                else    // nemoze
                    throw invalid_argument("Element vec postoji u stablu");
            }
            else{   // Node JE nullptr
                node = make_shared<Atom>(data);
            }
        }

        void printPreorderR(shared_ptr<Atom> node){
            if (node != nullptr){
                cout << node->data << " ";
                printPreorderR(node->left);
                printPreorderR(node->right);
            }
        }

        void printInorderR(shared_ptr<Atom> node){
            if (node != nullptr){
                printInorderR(node->left);
                cout << node->data << " ";
                printInorderR(node->right);
            }
        }

    public:
        BinaryTree() : root(nullptr) {}

        // Ubacivanje elemenata:
        void insert(T data){
            cout << "Dodajem element " << data << endl;
            insertR(root, data);
        }

        // Ispis:
        void printPreorder(){
            cout << "Stablo: ";
            printPreorderR(root);
        }

        void printInorder(){
            cout << "Stablo: ";
            printInorderR(root);
        }

        // Pretrazivanje:


};

int main(){
    BinaryTree<int> bt;
    bt.insert(5);
    bt.insert(7);
    bt.insert(9);
    bt.insert(8);
    bt.insert(6);
    bt.printPreorder();
    cout << endl;

    return 0;
}