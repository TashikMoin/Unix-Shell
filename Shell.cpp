#include<iostream>
#include<string>
#include<string.h>
#include<cstdlib>
#include<stdlib.h>
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

using namespace std ;

class Shell
{
    private :
        string User_Input ;
        string *Argument_List ;
        int Total_Arguments ;
    public :

    Shell( )
    {
        this->Total_Arguments = 0 ;
        this->User_Input = "" ;
        this->Argument_List = NULL ;
        while(1)
        {
            cout<<Present_Working_Directory()<< "\033[1;31m  >>> \033[0m"; 
            getline( cin , this->User_Input ) ;
            Tokenize() ;
            if( this->Argument_List[0] == "Youtube-Playlist" )
            {
                string YoutubeDL = "youtube-dl " ;
                YoutubeDL += this->Argument_List[1] ;
                system( YoutubeDL.c_str() ) ;
                continue ;
            }
            if( this->Argument_List[0] == "WhatsApp-Message")
            {
                string WhatsApp = "python3 WhatsApp.py " ;
                int i = this->Argument_List[0].length() + 1 , j = 1 , Length = 0 , Args = 0 ;
                while( i < this->User_Input.length() )
                {
                    this->Argument_List[j] = "" ;
                    Length = 0 ; Args = 0 ;
                    while( Length < 2 && i < this->User_Input.length() )
                    {
                        if( this->User_Input[i] == '"' )
                        {
                            ++Length ;
                        }
                        if( this->User_Input[i] == ' ')
                        {
                            ++Args ;
                        }
                        this->Argument_List[j] += this->User_Input[i] ;
                        ++i ;
                    }
                    WhatsApp += this->Argument_List[j] ;
                    j += Args ;
                    j++ ;
                }
                cout<<WhatsApp<<endl ;
                system( WhatsApp.c_str() ) ;
                continue ;
            }
            if( this->Argument_List[0] == "cd" )
            {   
                chdir( this->Argument_List[1].c_str() );
                continue ;
            }
            if( Search_If_A_Arithmetic_Expression() )
            {
                string Arithmetic_Expression = "python3 Arithmetic.py " ;
                Arithmetic_Expression += '"' ;
                for( int i = 0 ; i < Total_Arg() ; ++i )
                {
                    Arithmetic_Expression += this->Argument_List[i] ;
                    Arithmetic_Expression += " " ;
                }
                Arithmetic_Expression += '"' ;
                system( Arithmetic_Expression.c_str() ) ;
                continue ;
            }
            system( this->User_Input.c_str() ) ;
        }
    }

    string Present_Working_Directory() 
    {
        char buff[FILENAME_MAX]; 
        GetCurrentDir( buff, FILENAME_MAX );
        string Present_Working_Directory(buff);
        return Present_Working_Directory;
    }

    bool Search_If_A_Arithmetic_Expression()
    {
        for( int i = 0 ; i < this->User_Input.length() ; ++i )
        {
            if( this->User_Input[i] == '+' || this->User_Input[i] == '-' || this->User_Input[i] == '*' || this->User_Input[i] == '/')
            {
                return true ;
            }  
        }      
        return false ;
    }


    int Total_Arg( )
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
        this->Total_Arguments = Count ;
        return Count ;
    }

    void Tokenize()
    {
        this->Argument_List = new string[ Total_Arg() ] ;
        for( int i = 0 , j = 0 ; i < this->User_Input.length() ; ++i )
        {
            if( this->User_Input[i] == ' ' )
            {
                ++i ; ++j ;
            }
            this->Argument_List[j] += this->User_Input[i] ;
        }
    }
} ;



int main( int argc, char *argv[] ) 
{
    Shell *My_Shell = new Shell( ) ;
}