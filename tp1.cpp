#include <iostream>
using namespace std;

class Livre {
	public :
     string titre ;
     string auteur; 
     int nombrePages;
     bool disponible;

   Livre(string a , string b ,int nombre , bool d )
{
	titre = a ; 
	auteur = b ;
   nombrePages = nombre;
	disponible = d;
}
void affiche()
{
 cout<<"name of the book is "<<titre<<" written by "<<auteur<<", with "<<nombrePages<<" of pages ."<<endl;
if (disponible == 1 ){
	cout<<" it is dispobible right now "<<endl;
   }else{
	cout<<" it is not  dispobible right now "<<endl;
   }
}
};
int main(){

  Livre book1("sui","ali",129,1) ;
	book1.affiche();

	return 0;
}
