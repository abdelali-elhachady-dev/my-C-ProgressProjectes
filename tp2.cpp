#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Personne {
    public :
    int id;
    string nom;
    string prenom;
    string mail;
    string telephone;
    double salaire;
    Personne(int a ,string b, string c ,string d ,string e , double f)
    :id(a),nom(b),prenom(c),mail(d),telephone(e),salaire(f) {}
    
 double calculerSalaire()
{
  return salaire;
}
 void affiche()
{
    cout<<"id :"<<id<<" , nom : "<<nom<<" , prenom : "<<prenom<<", mail : "<<mail<<" , telephone : "<<telephone<<endl;
}
};
class Utilisateur : public Personne{
    public :
        string login ;
        string password ;
        string service ;
    Utilisateur(int a ,string b, string c ,string d ,string e , double f, string g ,string h , string i )
    :  Personne( a , b,  c , d , e ,  f), login(g), password(h), service(i) {}
    
 double calculerSalaire() 
{
    if ( service == "manager"){
        return salaire + salaire * 0.1;
    } else if (service ==  "directeur general") {
        return salaire + salaire * 0.4;
    }
}
 void affiche()  
{
    cout<<"service :"<<service<<" , login : "<<login<<"  , password : "<<password<<endl;
}
};
class Profil{
    public :
        int id ;
        string code ;
        string libelle ; 
    Profil(int id, string code, string libelle)
        : id(id), code(code), libelle(libelle) {}
    };

int main()
{
Profil ChefdeProjet(33445,"hdkjf","Chef de projet");
Profil manager(33545,"hdkjf","Manager");
Profil DHR(33545,"hdkjf","Directeur de projet ");
Profil DG(3345,"hdkjf","Directeur général"); 
//std::vector<Utilisateur*>
//This stores pointers to Utilisateur objects in the vector.
// The objects themselves are stored elsewhere in memory (e.g., on the heap)
/* std::vector<Utilisateur>
This stores objects of type Utilisateur directly in the vector.
 When you add an object to the vector, it creates a copy of the object.*/
 /*
     vector<User> utilisateurs = { User(), User(), User() };
ther is vector of objectes like bellow  | |
                                        \|/
 */
vector<Utilisateur> users;
users.push_back(Utilisateur(1234,"chadi","ali","ali29@gmail.com","9348534945",20934,"user","9959","Directeur général"));
users.push_back(Utilisateur(1234,"chahhgdi","ali","ali29@gmail.com","9348534945",20934,"user","9599","Manager"));
users.push_back(Utilisateur(1234,"chai","ali","ali29@gmail.com","9348534945",20934,"user","9599","Manager"));
users.push_back(Utilisateur(1234,"chgadi","ali","ali29@gmail.com","9348534945",20934,"user","9599","Directeur général"));
for( auto i :users){
    i.affiche();
    cout<<"_______________________________________________________________________________________________________________"<<endl;
}
for( auto i :users){
    if ( i.service == "Manager" )
        i.affiche();
    cout<<"_______________________________________________________________________________________________________________"<<endl;
}

    return 0 ;
}