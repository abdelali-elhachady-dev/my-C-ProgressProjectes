#include <iostream>
using namespace std;

class rectangle 
{
    private:
    int lenght ;
    int width ;
    public:
    rectangle(int Lenght , int Width )
    {
        /*here u can put a counter so instead of the user put the name of rectangl any time the user 
        declare a objet will name 1 and counter++ */
        lenght = Lenght ;
        width = Width ;

    }
    friend void print(rectangle x , string name);
    friend void max( rectangle x , rectangle y);
};
void print(rectangle x , string name){
        cout<<"the rect area of rect "<<name<<" is "<<(x.lenght * x.width )<<endl;
    }

void   max( rectangle x , rectangle y)
{
    if ( (x.lenght * x.width ) >= (y.lenght * y.width ))
    {
        cout<<"the biggest rect is "<< (x.lenght * x.width )<<endl  ;
    }
    else
    {
     cout<<"the biggest rect is "<<(y.lenght * y.width )<<endl  ;
    }
}

int main ()
{
    rectangle first(10 , 19) ;
    rectangle second(12 , 18) ;
    print(first , "First");
    print(second , "Second");
    max(first , second);

    return 0;
}