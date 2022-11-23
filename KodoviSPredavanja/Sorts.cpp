#include <iostream>

using namespace std;

template<typename T>
void swapElements(T &a, T &b){
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

// Svi su slozenosti n^2, ali neki jesu brzi nego drugi. (sporiji < brzi):
// BubbleSort < SelectionSort < InsertionSort < ShellSort
template <typename T>
void selectionSort(T A[], int n){
    // Nadji najmanji, pa ga zamjeni s prvim u polju

    for (int i = 0; i < n-1; i++){
        int minIdx = i;
        for (int j = i; j < n; j++){
            if (A[j] < A[minIdx]){
                swapElements(A[j], A[minIdx]);
            }
        }
        // Ispis za demonstraciju funkcionalnosti:
        cout << "i = " << minIdx << " -> ";
        for (int k=0; k < 10; k++){
            cout << A[k] << " ";
        } cout << endl;
    }

    // Dvije for petlje, složenost je uvijek n^2, čak i nakon optimizacije. Very bad :(
}

template <typename T>
void bubbleSort(T A[], int n){
    // usporedimo dva uzastopna el i zamjenimo ih po potrebi
    // time na vrh niza "isplivaju" najviši brojevi jedan po jedan (hence, bubble sort)

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-1-i; j++){
            if (A[j] > A[j+1]) swapElements(A[j], A[j+1]);
        }
    // Ispis za demonstraciju funkcionalnosti:
        cout << "i = " << i << " -> ";
        for (int k=0; k < 10; k++){
            cout << A[k] << " ";
        } cout << endl;
    }

    // Slozenost je n^2, najsporija je opcija, ali daje mir u dusi jer se u svakom prolazu napravi nekakva zamjena el za razliku od selection sorta
    // Da se optimizirat tako da omega bude n
}

template <typename T>
void bubbleSortImproved(T A[], int n){
    // U praksi optimizirano samo za slučaj kad je input niz vec sortiran.

    bool swapHappened = true;

    for (int i = 0; swapHappened == true; i++){
        swapHappened = false;
        for (int j = 0; j < n-1-i; j++){
            if (A[j] > A[j+1]) {
                swapHappened = true;
                swapElements(A[j], A[j+1]);
            }
        }
    // Ispis za demonstraciju funkcionalnosti:
        cout << "i = " << i << " -> ";
        for (int k=0; k < 10; k++){
            cout << A[k] << " ";
        } cout << endl;
    }

    // Slozenost je n^2, ALI omega slozenost je n (za vec sortiran)
}

template <typename T>
void insertionSort(T A[], int n){
    // Podjelis niz u "sortirani" (prije i) i nesortirani (nakon i) dio
    // Uzmes A[i] da je temp, te ga usporedujes sa sortiranim djelom
    // Shuffle-aš sortirani niz do tamo gdje temp treba bit, pa ubacis temp tamo.

    T temp;
    int i,j;

    for (i = 1; i < n; i++){
        temp = A[i];
        for (j = i; j >= 1 && A[j-1] > temp; j--){
            A[j] = A[j-1];
        }
        A[j] = temp;
        // Ispis za demonstraciju funkcionalnosti:
        cout << "i = " << i << " -> ";
        for (int k=0; k < 10; k++){
            cout << A[k] << " ";
        } cout << endl;
    }

    // Relativno malo provjera i promjena u odnosu na bubble i selection.
    // Slozenost takoder n^2, ali najbolji slucaj za sortirani niz -> n

    // Ovaj sort pazi da se relativna sortacija ne mijenja,
    //      npr: sortiranje po godinama pa po oibu nece ispremjesat godine i oib
}

template <typename T>
void shellSort(int A[], int n){

}


int main(){
    int i;
    int A[10] = {10,9,8,7,6,5,11,12,13,14};
    int n = 10;

    // selectionSort(A, n);
    // bubbleSort(A, n);
    // bubbleSortImproved(A, n);
    insertionSort(A, n);


    cout << "Niz nakon sorta: ";
    for (i=0; i < 10; i++){
        cout << A[i] << " ";
    } cout << endl;


    return 0;
}