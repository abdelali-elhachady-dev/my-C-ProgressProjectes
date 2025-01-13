#include <iostream>
using namespace std;

class engineer ;

class teacher 
{
    public :
    int salary = 0 ;
    string name ;

    friend void addSalary ( teacher x , engineer y);
};

class engineer 
{
    public:
    int salary = 0 ;
    string name ;
    friend void addSalary ( teacher x , engineer y);
};

void addSalary ( teacher x, engineer y )
{
    x.salary += 1000;
    y.salary += 1000;
    cout<<"salary of "<<x.name<<" is "<<x.salary<<" and for " <<y.name<<" is "<<y.salary<<endl;
}

int main ()
{
    teacher alix;
    engineer imadx;
    alix.name = "ali";
    imadx.name= "imad";
    addSalary( alix, imadx);

    return 0 ;
}