#include <iostream>
#include <string>

using namespace std;

template <class T> class List {
    template <class X> struct ListElement {
       X data;
       ListElement<X> *next;
    };

   ListElement<T> *head = nullptr;

public:
    bool insert(T data) { // umetanje na početak liste
        ListElement<T> *newElement = new (nothrow) ListElement<T>;
        if (newElement == nullptr)
            return false;
        newElement->data = data;
        newElement->next = head;
        head = newElement;
        return true;
    }
   bool append(T data) { // dodavanje na kraj liste
      ListElement<T> *newElement = new ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = nullptr;
#if 1
      // elementarno, s jednostrukim pokazivačem
      if (!head) { // prazna lista
         head = newElement;
      } else {
         ListElement<T> *p;
         for (p = head; p->next; p = p->next)
            ; // iteracija na kraj liste
         p->next = newElement;
      }
#else
      // naprednije, s **
      ListElement<T> **p;
      for (p = &head; *p; p = &((*p)->next))
         ;
      *p = newElement;
#endif
      return true;
   }
   bool insertSorted(T data) { // umetanje po sortiranom redoslijedu, T mora
                               // imati implementiran operator >
      ListElement<T> *newElement = new (nothrow) ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      ListElement<T> **p;
      for (p = &head; *p && data > (*p)->data; p = &((*p)->next))
         ;
      newElement->next = *p;
      *p = newElement;
      return true;
   }
   bool remove(T data) {
      ListElement<T> **p;
      for (p = &head; *p && data != (*p)->data; p = &((*p)->next))
         ;
      if (*p) {
         ListElement<T> *tmp;
         tmp = *p;
         *p = (*p)->next;
         delete tmp;
         return true;
      } else {
         return false;
      }
   }
   void print() {
      for (ListElement<T> *p = head; p; p = p->next) {
         cout << p->data << " ";
      }
      cout << endl;
   }
    // Zadaci: 

    T& List<T>::at(int k){  // Dohvati podatak u k-tom elementu liste
        int i;
        List<T>::iterator it;
        for(i=0, it = this->begin(); i<k && it != this->end(); i++, it++);
        if (k>= 0 && it!=this->end()) return *it;
        else throw std::runtime_error("Index out of range!"); 
    }

    ListElement<T>* List<T>::at2(int k){    // Dohvati pokazivać na k-ti element liste.
        if(k < 0) return nullptr;
        int i;
        for(i=0,p=head;i<k && p, p = p->next);
        return p;
    }

    int List<T>::length(){  // Duljina liste
        int counter = 0;
        for(iterator it = this -> begin(); it != this -> end(); it++, counter++);
        return counter;
    }

    int List<T>::countItem(T item){
        int counter = 0;
        for (iterator it = this->begin(); it != this->end(); it++){
            if (*it == item) counter++
        }
        return counter;
    }
    void List<T>::deleteAll(){
        ListElement<T> *p = head;
        while(p){
            ListElement<T> *tmp = p;
            p = p->next;
            delete tmp;
        }
        head = nullptr;
    }
    void List<T>::reverseList(){
        ListElement<T> *p = head;
        ListElement<T> *pprev = nullptr;
        ListElement<T> *pnext = nullptr;

        while (p){
            pnext = p->next;
            p->next = pprev;
            pprev = p;
            p = pnext;
        }
        head = pprev;
    }
};


int main(void) {
#if 1
   List<int> l;
   l.append(4);
   l.append(5);
   l.insert(1);
   l.insert(2);
   l.insert(3);



#else
   List<string> l;
   l.insertSorted("pero");
   l.insertSorted("ante");
   l.insertSorted("branko");
   l.insertSorted("zoran");
#endif
   l.print();
   // l.printRecursive();
   l.remove(4);
   l.print();
   return 0;
}