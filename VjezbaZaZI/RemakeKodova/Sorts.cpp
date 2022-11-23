#include <iostream>

using namespace std;

template <typename T>
void swapElements (T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T> void selectionSort(T A[], int n){
    for (int i = 0; i < n; i++){
        int minIdx = i;
        for (int j = i; j < n; j++){
            if (A[j] < A[minIdx]){
                swapElements(A[j], A[minIdx]);
            }
        }
    }
}

template <typename T>
void bubbleSort(T A[], int n){
    for (int i = 0; i < n; i++){
        for ( int j = 0; j < n-1-i; j++){
            if (A[j] > A[j+1]) swapElemetns(A[j], A[j+1]);  // Ovo ce uvijek nać najveći el u nizu i odvest ga na zadnje mjesto
        }
    }
}

template <typename T>
void bubbleSortImproved (T A[], int n){
    bool swapHappened = true;
    // Ako prode kroz cijeli niz bez swapa, već je sortiran
    for (int i = 0; swapHappened == true; i++){
        swapHappened = false;
        for (j = 0; j < n-1-i; j++){
            if (A[j] > A[j+1]){
                swapHappened = true;
                swapElements(A[j], A[j+1]);
            }
        }
    }
}

template <typename T>
void insertionSort(T A[], int n){
    // Podijeliš u dva niza (sortirani i nesortirani)
    // Uzmeš da je tmp = A[i], pa prestrojavaš unazad sortirani niz
    // do kad ne dođeš do mjesta di ovaj treba bit. Tam ga stavis
    T tmp;
    int i,j;

    for (i = 1; i<n; i++){
        temp = A[i];
        for (j=i; j>=1 && A[j-1] > temp; j--){
            A[j] = A[j-1];
        }
        A[j] = tmp;
    }
}

template <typename T>
void shellSort(int A[], int n){
    int i, j, step;
    T tmp;
    for (step = n/2; step > 0; step /= 2){
        for (i = step; i < n; i++){
            tmp = A[i];
            for (j = i; j >= step && A[j-step] > temp; j -= step){
                A[j] = A[j-step];
            }
            A[j] = tmp;
        }
    }
}


// Za ovo pogledaj u P08/Merge.cpp
template <typename T>
void marge(T A[], T pom[], int leftPos, int rightPos, int rightEnd){ // ovo su sve indexi, tj. UKLJUČIVE GRANICE!
    //leftPos - početak lijevog podniza
    //rightPos - početak desnog
    //rightEnd - kraj desnog podniza (leftEnd nam ne treba, to je rightPos-1)
    int leftEnd = rightPos - 1;
    int numOfElements = rightEnd - leftPos + 1; // od početka lijevog podniza do kraja desnog, +1 jer su UKLJUČIVE GRANICE!
    int pomPos = leftPos;

    //dok ima elemenata u oba podniza
    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        //gledaj u oba podniza prvi el pa prepiši manji u pomocni niz, pomakni index tog niza pa opet uspoređuj...
        if (A[leftPos] < A[rightPos]) {
            pom[pomPos] = A[leftPos];
            pomPos++;
            leftPos++;
        }
        else 
            pom[pomPos++] = A[rightPos++]; //kraće zapisano ali isto kao i za left
    }
        
    //ovo gore se vrtilo dok god je bilo elemenata u oba podniza
    //sad je još u SAMO jednom od njih ostalo elemenata, ali ne znamo u kojem
    //te elemente sve prepišemo u pom, kako dolaze.. (jer se više nemaju s čim uspoređivati)
    //ako su u lijevom
    while (leftPos <= leftEnd)
        pom[pomPos++] = A[leftPos++];
    //ili ako su u desnom podnizu
    while (rightPos <= rightEnd)
        pom[pomPos++] = A[rightPos++];

    //vrati elemente iz pomoćnog polja natrag
    for (int i=0; i < numOfElements; i++) 
        //pazi, ovdje nemamo više originalne leftPos ili rightPos
        // ali imamo rightEnd i numOfElements pa ćemo iz njih izračunati što nam treba
        A[rightEnd-i] = pom[rightEnd-i];
}

template <typename T>
void margeSort(T A[], T pom[], int left, int right){
    int middle;
    if (left < right) {
        middle = (left + right) / 2;
        margeSort(A, pom, left, middle);
        margeSort(A, pom, middle+1, right);
        // spoji A[left...middle] i A[middle+1...right] u sortirani niz 
        marge(A, pom, left, middle+1, right); //polje, pom polje, poč 1. podniza, poč 2. podniza i kraj
    }
}



template <typename T>
int calculatePivot(T A[], int left, int right) {
    //nađi srednji el.
    int middle = (left+right) / 2;

    //sortiraj ta tri elementa
    if (A[left] > A[middle])
        swapElements(A[left], A[middle]);
    if (A[left] > A[right])
        swapElements(A[left], A[right]);
    if (A[middle] > A[right])
        swapElements(A[middle], A[right]);
    
    cout << "Stozer: " << A[middle] << endl;

    return middle;
}

template <typename T>
void quickSort(T A[], int left, int right) {
    int pivotIdx = calculatePivot(A, left, right);
    T pivot = A[pivotIdx];

    // KRAJ: ako ima 3 ili manje el - sortirano u calculatePivot
    if (right-left < 3)
        return;
    
    //skrivanje pivota
    swapElements(A[pivotIdx], A[right-1]);

    int i = left; //idx prvog elementa u nizu
    int j = right-1; //idx skrivenog pivota

    //prebacujem elemente veće od pivota na desno, a manje na lijevo
    while (true) {

        while (A[++i] < pivot) {} //ne radim ništa, samo povećavam i

        while (A[--j] > pivot) {} //samo smanjujem j

        //indexi su stali na el. koje treba zamijeniti
        if (i<j) { //ako je i<j mijenjam elemente
            swapElements(A[i], A[j]);
        }
        else //indexi su se sreli, kraj zamjena
            break;
    }

    //vratim pivot na i-to mjesto
    swapElements(A[right-1], A[i]);

    // pozovi quicksort za svaki podniz
    quickSort(A, left, i-1); //indexi
    quickSort(A, i+1, right); // "i" ne spada nigdje jer je na dobrom mjestu
}

