#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Person {
    public:
      virtual ~Person(){
        cout<<"I'm father"<<endl;
    }
};

class Man:  public Person{
    public:
        ~Man(){
        cout<<"I'm son"<<endl;
    }
};
int main(){
        Person* m1 = new Man;
        delete m1;
    }
    