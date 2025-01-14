#include <iostream>
using namespace std;
class student ;
class univer 
{
    public : 
    string name;
    void print(student stdnt);
   
};

class student : public univer
{
    public:
    int age ;
    int id ;
    string name ;
    string grade;

    student ( int Age , int Id, string Name , string Grade)
    {
        age = Age;
        id = Id;
        name = Name;
        grade = Grade;
    }  
};
 void univer::print (student stdnt)
    {
        cout<<" Hi your name is "<<stdnt.name <<" you have "<<stdnt.age<<endl<<", with grade "<<stdnt.grade<<" annee ,and id "<<stdnt.id<<endl;
    }
int main ()
{
   student ali(22,3453454,"ali","2eme");
   ali.print(ali);
   
       return 0 ;
}