#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <cctype>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include <typeinfo>
#include <unistd.h> // for sleep function
#include <ctime> // for time function 

using namespace std ;
								
		// Variables used ..............
		
	int choose , i = 2 , x = 14 , choice11 , k = 0 , j = 0 , u , b = 2 , p , ind = 0 , ind2 , l = 0 , q = 0 ;
	string email , password , email2 , password2 , file , code ;
	fstream login , infile , available , available2 , out ;
	ofstream newline , head , exporT  ;
	char edit ;
	

	
void SetColor(int color); // color function 

void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}

/* this is values of colors for using 
Black        |   0
Blue         |   1
Green        |   2
Cyan         |   3
Red          |   4
Magenta      |   5
Brown        |   6
Light Gray   |   7
Dark Gray    |   8
Light Blue   |   9
Light Green  |   10
Light Cyan   |   11
Light Red    |   12
Light Magenta|   13
Yellow       |   14
White        |   15
*/ 

string now() ; // get time function now from ctime 

string now()
{
	time_t now;
    time (&now);
	return ctime(&now) ;
}

struct addln // add new line struct datatype
{
	string from ;
	string to ;
	string time_hour ;
	string time_minute ;
	int capacity ;
	string ticketcost ;
	string busno ;
	string drivername ;
	string code ;
}nwline;

struct store // storage data from files struct datatype
{
	string code[100] ;
	string from[100] ;
	string to[100] ;
	string time_hour[100] ;
	string time_minute[100] ;
	int capacity[100] ;
	string ticketcost[100] ;
	string busno[100] ;
	string drivername[100] ;
}t1,t2,t3;

struct clientr // registration client struct datatype
{
	string name ;
	string phone ;
	int chairn ;
	int capacity ;
	string code ;
	string time[5] ;
}c1;

struct clients // registration client struct datatype
{
	string name[100] ;
	string phone[100] ;
	int chairn[100] ;
	string time[100] ;
}c2;


void show () ; // show function for available Bus lines

void show () // used with show available lines & registration 
{ 
	int flag = 0 ;
	available.open("journey") ;
			
			available >> t1.code[k] >> t1.from[k] >> t1.to[k] >> t1.time_hour[k] >> t1.time_minute[k] ;
			available >> t1.ticketcost[k] >> t1.busno[k] >> t1.drivername[k] ;
			available2.open(t1.code[k]);
			available2 >> t1.code[k] >> t1.capacity[k] ;
			available2.close();
			while (t1.code[k] != "EOF") // maximum 2 journies is saved in the system 
			{
				k++ ;
				available >> t1.code[k] >> t1.from[k] >> t1.to[k] >> t1.time_hour[k] >> t1.time_minute[k] ;
				available >> t1.ticketcost[k] >> t1.busno[k] >> t1.drivername[k] ;
				available2.open(t1.code[k]);
				available2 >> t1.code[k] >> t1.capacity[k] ;
				available2.close();
			}
			available.close();
			for ( j = 0 ; j <= k ; j++ )
			{
				if ( t1.capacity[j] != 0 && t1.code[j] != "EOF" && t1.capacity[j] > 0 ) // Bug Resolved of exported files
				{
					SetColor(7) ;
					printf ("(%d) Line Code : " , j+1 ) ;
					cout <<  t1.code[j] << "\t" ;
					cout << "\tLeaving from : " << t1.from[j] << "\t" << "Traveling to : " << t1.to[j] << "\t" << "At : " << t1.time_hour[j] << ":" << t1.time_minute[j] << endl ;
					cout << "    Available Places : " << t1.capacity[j] << "\t" << "Ticket cost : " << t1.ticketcost[j] << "\t\t" << "Bus No : " << t1.busno[j] << "\t" << "\tDriver Name : " << t1.drivername[j] << endl << endl ;
					SetColor(x) ;
					flag = 1 ;
				}
				else if ( t1.capacity[j] <= 0 && t1.code[j] != "EOF" )
				{
					SetColor(12) ;
					printf ("(%d) Line Code : " , j+1 ) ;
					cout <<  t1.code[j] << "\t" ;
					cout << "\tLeaving from : " << t1.from[j] << "\t" << "Traveling to : " << t1.to[j] << "\t" << "At : " << t1.time_hour[j] << ":" << t1.time_minute[j] << endl ;
					cout << "    Available Places : " << t1.capacity[j] << "\t" << "Ticket cost : " << t1.ticketcost[j] << "\t\t" << "Bus No : " << t1.busno[j] << "\t" << "\tDriver Name : " << t1.drivername[j] << endl << endl ;
					SetColor(x) ;
					flag = 1 ;
				}
				else if ( t1.code[j] == "EOF" )
				{
					continue ;
				}
				else 
				{
					flag = 0 ;
					continue ;
				}
			}
			
	k = 0 ;
	j = 0 ;
	if ( flag == 1 )
	{
		
	}
	else if ( flag == 0 )
	{
		SetColor(12) ;
		cout << "\n\tNo Lines Added To Database\n" ;
		SetColor(x) ;
	}
	flag = 0 ;
}
void Export ()
{
	available.open("journey") ;
			
			if (!available)
			{
				SetColor(12) ;
				cout << "\n\tNo DataBase had Founded For Bus Lines\n" ;
				SetColor(x);
			}
			else {
			available >> t1.code[k] >> t1.from[k] >> t1.to[k] >> t1.time_hour[k] >> t1.time_minute[k] ;
			available >> t1.ticketcost[k] >> t1.busno[k] >> t1.drivername[k] ;
			available2.open(t1.code[k]);
			available2 >> t1.code[k] >> t1.capacity[k] ;
			available2.close();
			while (t1.code[k] != "EOF") // maximum 2 journies is saved in the system 
			{
				k++ ;
				available >> t1.code[k] >> t1.from[k] >> t1.to[k] >> t1.time_hour[k] >> t1.time_minute[k] ;
				available >> t1.ticketcost[k] >> t1.busno[k] >> t1.drivername[k] ;
				available2.open(t1.code[k]);
				available2 >> t1.code[k] >> t1.capacity[k] ;
				available2.close();
			}
			available.close();
				exporT.open("Exported Lines.txt");
				
				for ( j = 0 ; j <= k ; j++ )
				{
				if ( t1.code[j] != "EOF" ) // Bug Resolved of exported files
				{
					exporT << "Line Code : " ;
					exporT <<  t1.code[j] << "\t" ;
					exporT << "Leaving from : " << t1.from[j] << "\t" << "Traveling to : " << t1.to[j] << "\t" << "At : " << t1.time_hour[j] << ":" << t1.time_minute[j] << endl ;
					exporT << "Available Places : " << t1.capacity[j] << "\t" << "Ticket cost : " << t1.ticketcost[j] << "\t" << "Bus No : " << t1.busno[j] << "\t" << "\tDriver Name : " << t1.drivername[j] << endl << endl ;
			
				}
				else 
				{	}
				}
				SetColor(10) ;
				cout << "\n\nLines Data Exported Successfully" << endl ;
				SetColor(x) ;
				exporT.close();
			}
			k = 0 ;
			j = 0 ;
}


void cleardata () ; // clear DataBase Functions 
void cleardata ()
{
	int j = 0 , statue ;
	ifstream infile ;
	ofstream outfile ;
	const char *ptr ;
	string temp ;
	char coode[25] ;
	
	infile.open ("journey") ;
	k = 0 ;
	
	while ( !infile.eof() ) // remove file function 
	{
		infile >> t3.code[k] >> t3.from[k] >> t3.to[k] >> t3.time_hour[k] >> t3.time_minute[k] >> t3.ticketcost[k] >> t3.busno[k] >> t3.drivername[k] ;
		temp = t3.code[k] ;
		
		if ( temp != "EOF" )
		{
			while ( temp[j] != '\0' )
			{
				coode[j] = temp[j] ;
				j++ ;
			}
				statue = remove(coode) ;
				if( statue == 0 )
				{
					cout << "Line " << temp << " Deleted successfully..\n\n" ;
				}
				else
				{
					cout << "Unable to delete Line " << temp << "\n\n" ;
				}
		}
		else {
			
		}
		k++ ;
		j = 0 ;
	}
	
	infile.close() ;
	outfile.open ("journey") ;
	outfile << "\nEOF" ;
	remove ("Exported Lines.txt") ;
	remove ("Exported Clients Line.txt");
	outfile.close() ;
	k = 0 ;
	j = 0 ;
}
			
void loginedit () ;
void loginedit ()
{
	int i = 0 , l = 0 ;
	string email , password ;
	ofstream out ;
	cout << "\nEnter New Email : " ;
	cin >> email ;
	cout << "\nEnter New Password : " ;
	cin >> password ;
	
	while ( password[i] != '\0' ) // Encrypation of Email 
	{
		if ( password[i] != '\0' )
		{
			password[i] += 11 ;
			i++ ;
		}
		else {
			break ;
		}
	}
	while ( email[l] != '\0' ) // Encrypation of Password 
	{
		if ( email[l] != '\0' )
		{
			email[l] += 16 ;
			l++ ;
		}
		else {
			break ;
		}
	}
	
	out.open ("admin.txt");
	out << email << " " << password ;
	SetColor(10) ;
	cout << "\n\tYour Adminstration Data Had Been Updated\n" ;
	out.close() ;
}



void clearexp () ;
void clearexp ()
{
	int statue , statue2 ;
	
	statue = remove("Exported Clients Line.txt") ;
	statue2 = remove("Exported Lines.txt") ;
		if( statue == 0 || statue2 == 0)
		{
			cout << "\nDataBase " << "Deleted successfully..\n\n" ;
		}
		else
		{
			cout << "\nUnable to delete Database\n" << "\n\n" ;
		}
	
}
