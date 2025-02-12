#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Livre {
	public :
    static int conter ;
     string titre ;
     string auteur; 
     int nombrePages;
     bool disponible;
     static vector<Livre*> BIBLIO;

   Livre(string a , string b ,int nombre , bool d )
{
   BIBLIO.push_back(this);
	titre = a ; 
	auteur = b ;
   nombrePages = nombre;
	disponible = d;
}

 virtual void afficherDetails()
{
    cout<<"name of the book is "<<titre<<" written by "<<auteur<<", with "<<nombrePages<<" of pages ."<<endl;
   if (disponible == 1 ){
	      cout<<" it is disponible right now "<<endl;
   }else{
	      cout<<" it is not  disponible right now "<<endl;
   }
}
  virtual void emprunter(string name, int x)
   {
      BIBLIO[x-1]->disponible = false;
       cout<<"Dear "<<name<<" you get the "<<BIBLIO[x-1]->titre<<endl<<" Book thank YOU ."<<endl;
   }
    virtual void returner(int x)
   {
      BIBLIO[x-1]->disponible = true;
      cout<<"Dear client  the "<<BIBLIO[x-1]->titre<<endl<<" Book returned succusfully ,thank YOU :) ."<<endl;

   }
};
    vector<Livre*>Livre::BIBLIO;
    int Livre::conter = 1;
class LivreNumerique : public Livre
{
   public :
   int tailleFichier;
   string format;
   //a,b,c,d ,e,f : sequencile with  string titre ;auteur; nombrePages;disponible;tailleFichier;format

    LivreNumerique(string a , string b ,int c , bool d ,int e , string f) 
    : Livre(a , b ,c  , d), tailleFichier(e) , format(f) {}
   void afficherDetails() override
{
   cout<<"name of the book is "<<titre<<" written by "<<auteur<<", with "<<nombrePages<<" of pages ."<<endl;
   if (disponible == 1 ){
	     cout<<" it is dispobible right now "<<endl;
   }else{
	     cout<<" it is not  dispobible right now "<<endl;
   }
   cout<<tailleFichier<<"Mo is taille of the file, with "<<format<<"forme ."<<endl;
}
 void emprunter(string name, int x) override
 {
     BIBLIO[x-1]->disponible = false;
       cout<<"Dear "<<name<<" you get the "<<BIBLIO[x-1]->titre<<endl<<" Book thank YOU ."<<endl;
   }
   void returner(int x) override
   {
      BIBLIO[x-1]->disponible = true;
      cout<<"Dear client  the "<<BIBLIO[x-1]->titre<<endl<<" Book returned succusfully ,thank YOU :) ."<<endl;

   }
};
class LivrePapier : public Livre
{
   public :
   int nombreExemplaires ; 
   string emplacement; 
 //a,b,c,d ,e,f : sequencile with  string titre ;auteur; nombrePages;disponible;nombreExemplaires;emplacement; 
   LivrePapier(string a , string b ,int c , bool d ,int e , string f) 
    : Livre(a , b ,c , d), nombreExemplaires(e),emplacement(f) {}

void afficherDetails() override
{
   cout<<"name of the book is "<<titre<<" written by "<<auteur<<", with "<<nombrePages<<" of pages ."<<endl;
   if (disponible == 1 ){
	     cout<<" it is dispobible right now "<<endl;
   }else{
	     cout<<" it is not  dispobible right now "<<endl;
   }
   cout<<"there is "<<nombreExemplaires<<" of copies and his place on"<<emplacement<<endl;
}
 void emprunter(string name, int x) override
{
      BIBLIO[x-1]->disponible = false;
       cout<<"Dear "<<name<<" you get the "<<BIBLIO[x-1]->titre<<endl<<" Book thank YOU ."<<endl; 
}  
 void returner(int x) override
{
      BIBLIO[x-1]->disponible = true;
      cout<<"Dear client  the "<<BIBLIO[x-1]->titre<<endl<<" Book returned succusfully ,thank YOU :) ."<<endl;
}
};

int main(){
   int x ,y;
   string name;
  
   //vector<Livre*> livres;
   Livre* book1 = new LivreNumerique("suui","alix",1259,true,20,"pdf");
   Livre* book2 = new LivrePapier("suuuuuuuuui","3ali",4129,true,10,"biblio");

  do{
   cout<<"you want get or getback a book .[1/2]"<<endl;
   cin>>y;
   if (y == 1){
      cout<<"what's your name :"<<endl;
      cin>>name;
      cout<<"The books that are disponible right now is :"<<endl;
      Livre::conter =1;
      for(Livre* i :Livre::BIBLIO){
       
         if(i->disponible == true){
          cout<<i->conter<<"-"<<i->titre<<" ."<<endl;
        }else{
          cout<<i->conter<<"-"<<i->titre<<" . not disponible >_< ."<<endl;
        }
        Livre::conter++;
    }
      cout<<"for choose a book press the numbre orderd by the book ."<<endl;
      cin>>x;
      Livre::BIBLIO[x-1]->emprunter(name,x);
   }else{
      cout<<"The books that are not disponible right now is :"<<endl;
       Livre::conter = 1 ;
      for(Livre* i :Livre::BIBLIO){
         if(i->disponible == false)
          cout<<i->conter<<"-"<<i->titre<<" ."<<endl;
           Livre::conter++;
    }
      cout<<"for choose a book you want get back  press the numbre orderd by the book ."<<endl;
      cin>>x;
      Livre::BIBLIO[x-1]->returner(x);
   }
  }while(true);


  //for( Livre *i : livres){
   //i->afficherDetails();
 // cout<<"-----------------------------------------------------------"<<endl;
 // }
 // for(Livre * i : livres){
  // delete i ;
 // }
	return 0;
}







