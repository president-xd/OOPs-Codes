#include <iostream>
using namespace std;

class Cube{
    private:
        static const int Max_size = 6;
        int Array[Max_size] = {1,2,3,4,5,6};
        int size = 5;
    public:
        void pop(){
            if (size > 0){
                size--;
                Array[size] = 0;
            } else {
                cout << "Array is empty already. Cannot be popped." << endl;
            }
        }

        void push(int i){
            if (size < Max_size){
                Array[size] = i;
                size++;
            } else {
                cout << "Array is already full. Cannot push more elements." << endl;
            }
        }

        void display(){
            for (int i = size - 1; i > 0; i--){
                cout << Array[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    Cube C;
    cout << "Normal Stack" << endl;
    C.display();

    cout << "Stack after Pop function." << endl;
    C.pop();
    C.display();

    cout << "Stack After Push Function." << endl;
    C.push(9);
    C.display();
}
