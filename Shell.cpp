#include<iostream>
#include<string>
#include<string.h>
#include<cstdlib>


using namespace std ;

class Shell
{
    private :
        string User_Input ;
        string *Argument_List ;
    public :

    Shell()
    {
        User_Input = "" ;
        while(1)
        {
            cout << "\033[1;31m >>> \033[0m";
            getline( cin , this->User_Input ) ;
            system(this->User_Input.c_str()) ;
        }
    }
} ;



int main() 
{
    Shell *My_Shell = new Shell() ;
}