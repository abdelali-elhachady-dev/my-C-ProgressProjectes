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
   student ali(21,3453454,"ali","2eme");
   ali.print(ali);
   
       return 0 ;
}


/*                         if u wnat use array instead u have two choices
First one :::::::
student ali[5] = {
        student(22, 3453454, "Ali", "2eme"),
        student(23, 3453455, "Ahmed", "3eme"),
        student(21, 3453456, "Sara", "5eme"),
        student(24, 3453457, "Omar", "4eme"),
        student(25, 3453458, "Laila", "1ere")
    };
    
    // Call the print function for each student object
    for (int i = 0; i < 5; ++i) {
        ali[i].print(ali[i]);
    }

second one ::::::
student ali[5]; // Declare an array of 5 student objects

    // Use constructor to assign values to each student
    ali[0] = student(22, 3453454, "Ali", "2eme");
    ali[1] = student(23, 3453455, "Ahmed", "3eme");
    ali[2] = student(21, 3453456, "Sara", "5eme");
    ali[3] = student(24, 3453457, "Omar", "4eme");
    ali[4] = student(25, 3453458, "Laila", "1ere");

    // Print the information for each student
    for (int i = 0; i < 5; ++i) {
        ali[i].print(ali[i]);
    }










*/