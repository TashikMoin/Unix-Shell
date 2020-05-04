#include<iostream>
#include<string>
#include<string.h>
#include<cstdlib>
#include<stdlib.h>


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
            this->Tokenize() ;
            if( this->User_Input == "EXIT" || this->User_Input == "exit" )
            {
                exit(1) ;
            }
            else if( this->User_Input == "cd" )
            {
                system("cd <path> && dir");
            }
            system(this->User_Input.c_str()) ; 
        }
    }

    void Tokenize( )
    {
        char TokenString[ this->User_Input.length() + 1 ] ;
        strcpy( TokenString , this->User_Input.c_str() ) ;
        char *Token ;
        Token = strtok( TokenString , " "); 
        this->Argument_List = new string[ Total_Argument() ] ;
        int i = 0 ;
        while (Token != NULL) 
        { 
            this->Argument_List[i] = Token ;
            Token = strtok(NULL, " "); 
            i++ ;
            cout<<this->Argument_List[i]<<endl ;
        } 
    }

    int Total_Argument( )
    {
        int i = 0 , Arg = 0 ;
        while( i < this->User_Input.length() )
        {
            if(this->User_Input[i] == ' ')
            {
                Arg++ ;
            }
            i++ ;
        }
        return Arg ;
    }



} ;



int main() 
{
    Shell *My_Shell = new Shell() ;
}