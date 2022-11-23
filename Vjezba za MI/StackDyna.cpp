#include <iostream>

using namespace std;

template <class T> class Stack{
    private:
        static const size_t increment = 100;
        size_t size=100;
        T *stack;
        int top = -1;
        
    public:
        Stack() { stack = (T*) malloc (size*sizeof(T)); }
        Stack(size_t size): size(size) {stack = (T*)malloc(size*sizeof(T));}

        bool push(T item){
            if(top >= int(size-1)){
                T *tmp = (T*)realloc(stack,(stack+increment)*sizeof(T));
                if (!tmp){
                    return false;
                }
                stack = tmp;
                size += increment;
            }
            stack[++top] = item;
            return true;
        }

        bool pop(T &item){
            if(top < 0) return false;
            item = stack[top--];

            if (top != -1 && top < (int)(size-increment)){
                T *tmp = (T*)realloc(stack,(stack-increment)*sizeof(T));
                if (!tmp) return false;
                stack = tmp;
                size -= increment;
            } 
            
        }

        bool peek(T &el, Stack<T> s){
            if(!s.pop(el));
                return 0;
            s.push(el);
            return true;
        }

        bool peek2(int &el, int index){
            Stack <T> pom;
            int i;
            T j;
            bool found = false;
            i = -1;

            while (this -> pop(j)){
                pom.push(j);
                i++;
                if (i == index){
                    found = true; 
                    el = j;
                    break;
                }
            }
            while (pom.pop(j)){
                this -> push(j);
            }
            return found;
        }
};

int main(){

    return 0;
}