#include <iostream>
using namespace std;
    class test{
        public:
            test(int n): num1(n) { }
            test operator = (const test & t){
                num1 = t.num1;
                return *this;
            }
            void display(){
                cout<< num1<<endl;
            }
        private:
        int num1;
    };
    
int main(){
        test t1(3);
        t1.display();
        test t2(4);
        t2.display();
        t2 = t1;
        t2.display();
        return 1;
    }
    