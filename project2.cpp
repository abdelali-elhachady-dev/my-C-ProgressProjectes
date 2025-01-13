#include <iostream>
using namespace std;

class work 
{
    public:
    int salary;
    string name;
    work(int age , string nam)
    {
        salary = age;
        name = nam;
    }
   friend int average( work a , work b , work c);
};

    int average( work a , work b , work c)
{
    return (a.salary + b.salary + c.salary) / 3;
}

int main ()
{
    work worker1(8000,"ali") ,worker2(10000,"ahmad") ,worker3(10500,"imad");
    cout<<"the average is "<<average(worker1,worker2,worker3)<<endl;


    return 0 ;
}