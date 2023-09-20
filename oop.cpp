#include <iostream>
#include <fstream>
using std::string;
using namespace std;

class AbstractEmployee{
    virtual void AskForPromotion()=0;
};

ifstream bazededatein("bazadedate.in");
ofstream bazadedateout("bazadedate.out");

class Employee:AbstractEmployee
{
private:
    string Name;
    string Company;
    string Gender;
    int Age;
    int ActiveTime;
public:
    void setName(string name){
        Name=name;
    }
    string getName(){
        return Name;
    }
    void setCompany(string company){
        Company=company;
    }
    string getCompany(){
        return Company;
    }
    void setAge(int age){
        if(age>=18)
            Age=age;
    }
    void setActiveTime(double time)
    {
        ActiveTime=time;
    }
    int getActiveTime()
    {
        return ActiveTime;
    }
    int getAge(){
        return Age;
    }
    void setGender(string gender){
        Gender=gender;
    }
    string getGender(){

        return Gender;
    }
    void userDataDefDataBase()
    {
        bazadedateout<<Name<<' '<<Company<<' '<<Gender<<' '<<Age<<endl;
    }
    void userDataDef()
    {
        cout<<"Nume - ";
        cout<<Name<<endl;
        cout<<"Companie - ";
        cout<<Company<<endl;
        cout<<"Gen - ";
        cout<<Gender<<endl;
        cout<<"Varsta - ";
        cout<<Age<<endl;
    }
    Employee(string name, string company, string gender, int age)
    {
        Name=name;
        Company=company;
        Age=age;
        Gender=gender;
        bazadedateout<<Name<<' '<<Company<<' '<<Gender<<' '<<Age<<endl;
    }
    void AskForPromotion(){
        if(Age>30)
            cout<<Name<<" got promoted"<<endl;
        else
            cout<<Name<<" got denied for promotion."<<endl;
    }
};

class Developer:public Employee{
public:
    string FavouriteProgrammingLanguage;
    Developer(string name, string company, string gender, int age, string prlng)
        :Employee(name, company, gender, age)
        {
            FavouriteProgrammingLanguage= prlng;
        }
    void FixBug(){
        cout<<getName()<<" fixed bug using" <<FavouriteProgrammingLanguage<<std::endl;
    }
};

int main()
{
/**    Employee alex=Employee("Alex","Hronica","masculin",17);
    alex.userDataDef();
    Employee angajat=Employee("angajat","Hronica","neutru",16);
    angajat.userDataDef();
    alex.setAge(16);
    cout<<alex.getName()<<" are "<<alex.getAge()<<" ani.";
    Employee alex=Employee("Alex","Hronica","masculin",17);
    alex.AskForPromotion();**/
    Developer d = Developer("vai","Hronica","neutru",23,"C++");
    d.FixBug();
}
