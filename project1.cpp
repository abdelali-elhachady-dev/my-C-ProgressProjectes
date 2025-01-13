                      // exercie about friend function//
               /*Use friend functions when you need direct 
                    access to private/protected members but don't want to make them public.
                Use normal functions to interact with a class only through its public interface 
                for better encapsulation.*/
#include <iostream>
using namespace std;
#include <string>

class animal 
{
    public :
    string name;
    int age; 
    animal(string nam){
        cout<<nam<<"it's come  ."<<endl;
    }

    friend void changeName( animal& x , string y );
};
void changeName(animal& x , string nam){
       x.name = nam;
}

int main ( )
{
    animal cat("chiwiwi");
    cat.age = 2;
    cat.name = "chiwiwi";
    cout<<"name of cat is "<<cat.name<<endl;
    changeName(cat,"newCHiwiwi");
    cout<<" new name of cat is "<<cat.name<<endl;

    return 0 ;
}