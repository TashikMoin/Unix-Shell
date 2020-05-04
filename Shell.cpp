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
        this->User_Input = "" ;
        this->Argument_List = NULL ;
    }

    void Load_Shell()
    {
        while(1)
        {
            cout << "\033[1;31m >>> \033[0m";
            getline( cin , this->User_Input ) ;
            Tokenize() ;
            system(this->User_Input.c_str()) ;
        }
    }

    int Total_Words( )
    {
        int i = 0 , Count = 1 ;
        while( i < this->User_Input.length() )
        {
            if(this->User_Input[i] == ' ')
            {
                Count++ ;
            }
            i++ ;
        }
        return Count ;
    }

    void Tokenize()
    {
        int x = Total_Words() ;
        this->Argument_List = new string[ x * 20 ] ;
        for( int i = 0 , j = 0 ; i < this->User_Input.length() ; ++i )
        {
            if( this->User_Input[i] == ' ' )
            {
                ++i ; ++j ;
            }
            this->Argument_List[j] += this->User_Input[i] ;
        }

        for( int i = 0 ; i < this->Total_Words() ; ++i )
        {
            cout<<this->Argument_List[i]<<endl ;
        }
        cin.get() ;
    }
} ;



int main() 
{
    Shell *My_Shell = new Shell() ;
    My_Shell->Load_Shell() ;
}