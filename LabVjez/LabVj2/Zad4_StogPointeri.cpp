#include <iostream>
#include <time.h>

using namespace std;

class Stack {

    private:
        static const size_t increment = 100;
        size_t size = 100;
        int *stack;
        int top = -1;

    public:
        Stack() { stack = (int *)malloc(size * sizeof(int)); }
        Stack(size_t size) : size(size) { stack = (int *)malloc(size * sizeof(int)); }
        bool push(int item) {
            if (top >= size) {
               int *tmp = (int *)realloc(stack, size + increment);
                if (!tmp)
                    return false;
                stack = tmp;
                size += increment;
            }
            stack[++top] = item;
            return true;
        }
        bool pop(int &item) {
            if (top < 0)
                return false;
            item = stack[top--];
            return true;
        }
};

int main(){
    Stack s;
    srand(time(NULL));

    for(int i = 0; i < 101; i++){
        s.push(rand()%21-10);
    }

    for(int i = 0; i < 101; i++){
        int x;
        s.pop(x);
        cout << "pop: " << x << endl;
    }

    return 0;
}
