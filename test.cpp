#include<iostream>
using namespace std;
int main()
{
    int i = 4;
    int && r1 = std::move(i);
    cout<<r1<<endl;
    cout<<i<<endl;
    return 0;
}