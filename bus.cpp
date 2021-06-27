#include "function.h"

int main ()
{
	
try2 :
system("CLS") ;
SetColor(x);
cout << "\t\t\t\t  AmeenGo Bus Adminstration System\n" << endl ;
cout << " System Login ->\n" << endl ;
								
								// Login Adminstrator 
	cout << " Enter Email : " ;
	cin >> email ;
	cout << "\n Enter Password : " ;
	cin >> password ;
	cout << endl ;

	login.open("admin.txt") ;
	login >> email2 >> password2 ;
	
	while ( email2[l] != '\0' ) // Decrypation of Password 
	{
		if ( email2[l] != '\0' )
		{
			email2[l] -= 16 ;
			l++ ;
		}
		else {
			break ;
		}
	}
	
	while ( password2[q] != '\0' ) // Decrypation of Email 
	{
		if ( password2[q] != '\0' )
		{
			password2[q] -= 11 ;
			q++ ;
		}
		else {
			break ;
		}
	}

	if (email == email2 && password == password2)
	{	
		SetColor(10);
		cout << "\t\tSuccessful Login Welcome ..." << endl << endl ;
		sleep(3);
		login.close() ;
	}
	else if (email != email2 || password != password2)
	{
		if ( i == 0 ) // 3 failed logins 
		{
			SetColor(12) ; 
			cout << "\t\tYou Failed login 3 times ...\n" << endl ;
			SetColor(x);
			cout << "Program Exited" << endl ;
			login.close();
			sleep(3) ;
			exit (1) ;
		}
		SetColor(12) ;
		cout << "\t\tLogin failed try again \n\n" ;
		sleep(3);
		i-- ;
		q = 0 ;
		l = 0 ;
		login.close() ;
		goto try2 ;
	}
		
q = 0 ;
l = 0 ;		
 // >>>>>>>>>>>>>>>>>>>>> Menu >>>>>>>>>>>>>>>>>>>>>
 
menu :
SetColor(x);
system("CLS") ;
cout << "\t\t\t\t  AmeenGo Bus Adminstration System\n" << endl ;

cout << " (1) ADD New Bus Line\n (2) Client Registration\n (3) Lines Information\n (4) Client Information\n (5) Clear Databases\n (6) Edit Adminstration Login\n (7) Logout\n" << endl ;
cout << "Choose : " ;
cin >> choose ;
cout << endl ;

switch(choose)
{
	case 1 : // Add Bus Line 
			SetColor(x);
			system("CLS") ;
			cout << "\t\t\t\t  AmeenGo Bus Adminstration System\n" << endl ;
			cout << "ADD New Bus Line -> \n" << endl ;
			cout << "\nLeaving from : " ;
			cin >> nwline.from ;
			cout << "\nTraveling to : " ;
			cin >> nwline.to ;
			cout << "\nAt Time in hour & minutes\n" << "(Use Space between hh & mm) : " ;
			cin >> nwline.time_hour >> nwline.time_minute ;
			cout << "\nAvailable Capacity : " ;
			cin >> nwline.capacity ;
			cout << "\nTicket Cost\n" << "(Without Spaces) : " ;
			cin >> nwline.ticketcost ;
			cout << "\nEnter Bus Number : " ;
			cin >> nwline.busno ;
			cout << "\nThe Driver Name : " ;
			cin >> nwline.drivername ;
			cout << "\nEnter Journey Code\n" << "(4 chars Without Spaces) : " ;
			cin >> nwline.code ;
								
											// confirmation or Edit ******
											
			cout << "\n\nDo you want to Edit any Data , y or n ? " ;
			cin >> edit ;
			if ( edit == 'y' || edit == 'Y' )
			{
				cout << "\n\nChoose the Data Number would be edited from list ... \n" ;
				cout << " (1) Leaving from\n (2) Traveling to\n (3) Time in hour & minutes\n (4) Available Capacity\n (5) Ticket Cost\n (6) Enter Bus Number\n" ;
				cout << " (7) The Driver Name\n (8) Enter Journey Code\n" << endl ;
				cout << "Choose : " ;
				cin >> choice11 ;
				switch ( choice11 )
				{
					case 1 : 
							cout << "\nLeaving from : " ;
							 cin >> nwline.from ;
							 break ;
					case 2 : 
							cout << "\nTraveling to : " ;
							cin >> nwline.to ;
							break ;
					case 3 : 
							cout << "\nAt Time in hour & minutes : " ;
							cin >> nwline.time_hour >> nwline.time_minute ;
							break ;
					case 4 :
							cout << "\nAvailable Capacity : " ;
							cin >> nwline.capacity ;
							break ;
					case 5 : 
							cout << "\nTicket Cost : " ;
							 cin >> nwline.ticketcost ;
							break ;
					case 6 : 
							cout << "\nEnter Bus Number : " ;
							cin >> nwline.busno ;
							break ;
					case 7 : 
							cout << "\nThe Driver Name : " ;
							cin >> nwline.drivername ;
							break ;
					case 8 : 
							cout << "\nEnter Journey Code : " ;
							cin >> nwline.code ;
							break ;
					default :
							SetColor(12);
							cout << "Input Error Program Exited\n\n" ;
							SetColor(x);
							break ;
							
				}
			SetColor(10);
			cout << "\nLine Data Saved Correctly with Code " << nwline.code << endl ;
			SetColor(x);
			}
			else if ( edit == 'n' )
			{
				SetColor(10);
				cout << "\nLine Data Saved Correctly with Code " << nwline.code << endl ;
				SetColor(x);
			}
			else {
				SetColor(12) ;
				cout << "Input Error Process Failed\n\n" ;
				goto menu ;
				SetColor(x) ;
			}
			newline.open(nwline.code) ;
			newline << nwline.code << " " << nwline.capacity << endl ;
			newline << "EOF" ;
			newline.close();
			infile.open("journey") ; 
			infile >> t1.code[k] >> t1.from[k] >> t1.to[k] >> t1.time_hour[k] >> t1.time_minute[k] ;
			infile >> t1.ticketcost[k] >> t1.busno[k] >> t1.drivername[k] ;
			while (t1.code[k] != "EOF" ) // maximum 5 journies is saved in the system 
			{
				k++ ;
				infile >> t1.code[k] >> t1.from[k] >> t1.to[k] >> t1.time_hour[k] >> t1.time_minute[k] ;
				infile >> t1.ticketcost[k] >> t1.busno[k] >> t1.drivername[k] ;
			}
			infile.close();
			
			head.open("journey") ;
			head << nwline.code << " " << nwline.from << " " << nwline.to << " " << nwline.time_hour << " " << nwline.time_minute << " " ;
			head << nwline.ticketcost << " " << nwline.busno << " " << nwline.drivername << endl ;
			for ( j = 0 ; j < k ; j++ ) // BUG :-- *********
			{
				if ( t1.code[j] != "EOF" )
				{
				head << t1.code[j] << " " << t1.from[j] << " " << t1.to[j] << " " << t1.time_hour[j] << " " << t1.time_minute[j] << " " ;
				head << t1.ticketcost[j] << " " << t1.busno[j] << " " << t1.drivername[j] << endl ;
				}
			}
			head << "EOF" << endl  ;
			head.close();
			j = 0 ;
			k = 0 ;
			/*****************************************************************/
			
			SetColor(10) ;
			cout << "\nPress Enter to Back to main menu or any key for Exit .. " << endl ; // continue function in system
			cin.ignore();
			if ( cin.get() == '\n' )
			{
				goto menu ;
			}
			else 
			{
				SetColor(12);
				cout << "\t\t\t\tprogram Exited" << endl ;
				SetColor(x) ;
				exit(1);
			}
			break ;
			
			
	case 2 : // client Registration
			wrongn :
			SetColor(x);
			system("CLS") ;
			cout << "\t\t\t\t  AmeenGo Bus Adminstration System\n" << endl ;
			cout << "Register Client -> \n" << endl ;
			show() ; // show available lines
			nofile :
			SetColor(10) ;
			cout << "\nPress Enter to Continue Client Registration or any key to Main Menu .. " << endl ; // continue function to regesitration
			cin.ignore();
			if ( cin.get() == '\n' )
			{
				
			}
			else
			{
				goto menu ;
			}		
			SetColor(x);
			cout << "Client Name\n(nospaces underscore only) : " ;
			cin >> c1.name ;
			cout << "\nPhone Number : " ;
			cin >> c1.phone ;
			cout << "\nNumber of chairs : " ;
			cin >> c1.chairn ;
			cout << "\nEnter Line code : " ;
			cin >> c1.code ;
			available.open (c1.code) ;
			if (!available) // file doesn't exist
			{
				SetColor(12);
				cout << "\nYou Entered Wrong code\n" ; // wrong code entered for journey
				SetColor(x);
				sleep(2) ;
				goto wrongn ;
			}
			else // file exist 
			{
				available >> c1.code >> c1.capacity ;
				c1.capacity = c1.capacity - c1.chairn ;
				if ( c1.capacity < 0 )
				{
					SetColor(12) ;
					cout << "\n\tAll Tickets For this Line Had been Reserved\n" ;
					SetColor(x) ;
					available.close();
					sleep (2) ;
					goto wrongn ;
				}
				else {
				available >> c2.name[p] >> c2.phone[p] >> c2.chairn[p] ;
				while ( c2.name[p] != "EOF" )
				{
					p++ ;
					available >> c2.name[p] >> c2.phone[p] >> c2.chairn[p] ;
				}
				
				available.close() ;
				out.open (c1.code) ;
				out << c1.code << " " << c1.capacity << endl ;
				out << c1.name << " " << c1.phone << " " << c1.chairn << endl ;
				for ( k = 0 ; k <= p ; k++ )
				{
					if ( c2.name[k] != "EOF" && c2.phone[k] != "0" && c2.chairn[k] != 0 ) // for no bugs in file 
					{
						out << c2.name[k] << " " << c2.phone[k] << " " << c2.chairn[k] << endl ;
					}
				}
				out << "EOF" ;
				out.close();
			}
				SetColor(14) ;
				cout << "\n\tClient had been Registered At -> " << now() << endl ;
				j = 0 ; // Return values 
				k = 0 ;
				p = 0 ; 
				SetColor(10) ;
				cout << "\nPress Enter to Back to main menu or any key for Exit .. " << endl ; // continue function in system
				cin.ignore();
				if ( cin.get() == '\n' )
				{
					goto menu ;
				}
				else 
				{
				SetColor(3);
				cout << "\t\t\tprogram Exited ... " << endl ;
				SetColor(x) ;
				sleep(3) ;
				exit(1);
				}
			}
				break ;
				
	case 3 : // Available Lines & export Lines information //finished *****************************************>
			SetColor(x);
			system("CLS") ;
			cout << "\t\t\t\t  AmeenGo Bus Adminstration System\n" << endl ;
			cout << "ALL Lines Information -> \n" << endl ;
			show() ; // show available lines 
			cout << "\nExport Lines Information ? y or n ? " ; // to export lines data
			cin >> edit ;
			if ( edit == 'y' || edit == 'Y' ) // to export files 
			{
				Export() ;
			}
			else {
				
			}
				j = 0  ; // Bug Repeated Files
				k = 0 ;
				SetColor(10) ;
				cout << "\nPress Enter to Back to main menu or any key for Exit .. " << endl ; // continue function in system
				cin.ignore();
				if ( cin.get() == '\n' )
				{
					SetColor(x) ;
					goto menu ;
				}
				else 
				{
				SetColor(3);
				cout << "\t\t\tprogram Exited ... " << endl ;
				SetColor(x) ;
				sleep(3) ;
				exit(1);
				
				break ;
	
	case 4 : // client export data 
			noofile :
			SetColor(x);
			system("CLS") ;
			cout << "\t\t\t\t  AmeenGo Bus Adminstration System\n" << endl ;
			cout << "\nClient Information ->\n" << endl ; 
			show();
			SetColor(10) ;
			SetColor(x);
			cout << "\nEnter M For Menu Or" ;
			cout << "\nEnter Line Code : " ;
			cin >> c1.code ;
			if ( c1.code == "M" || c1.code == "m" )
			{
				ind = 0 ;
				goto menu ;
			}
			available.open (c1.code) ;
			if (!available) // file doesn't exist
			{
				SetColor(12);
				cout << "\nYou Entered Wrong code\n" ; // wrong code entered for journey
				SetColor(x);
				sleep(2) ;
				ind ++ ;
				if ( ind >= 2 )
				{
					goto cont ;
				}
				else {
				goto noofile ;
				}
			}
			
			else // file exist 
			{
				available >> c1.code >> c1.capacity ;	
				available >> c2.name[p] >> c2.phone[p] >> c2.chairn[p] ;
			if ( c2.name [p] != "EOF" )
			{
				while ( c2.name[p] != "EOF" )
				{
					p++ ;
					available >> c2.name[p] >> c2.phone[p] >> c2.chairn[p] ;
				}
				available.close() ;
				exporT.open ("Exported Clients Line.txt") ;
				exporT << "Name" << "\t\tphone" << "\t\tChairs" << "\t\tLine Code" << endl ;
				SetColor (11) ;
				cout << endl << "\tName" << "\t\tphone" << "\t\tChairs" << "\t\tLine Code" << endl ;
				for ( k = 0 ; k <= p ; k++ )
				{
					if ( c2.name[k] != "EOF" && c2.phone[k] != "0" && c2.chairn[k] != 0 ) // for no bugs in file 
					{
						exporT << c2.name[k] << "\t" << c2.phone[k] << "\t " << c2.chairn[k] << "\t\t" << c1.code << endl ;
						cout << "\t" << c2.name[k] << "\t" << c2.phone[k] << "\t " << c2.chairn[k] << "\t\t" << c1.code << endl ;
					}
				}
				p = 0 ;
				k = 0 ;
				SetColor(10) ;
				exporT.close() ;
				cout << "\nClients Data Exported Successfully" << endl ;
			}
			
			else if ( c2.name [p] == "EOF" )
			{
				SetColor (12) ;
				cout << "\n\tNo Clients Are Reserved in that Line\n" ; 
			}
			cont :
				p = 0 ;
				k = 0 ;
				ind = 0 ;
				SetColor(10) ;
				cout << "\nPress Enter to Back to main menu or any key for Exit .. " << endl ; // continue function in system
				cin.ignore();
				if ( cin.get() == '\n' )
				{
					goto menu ;
				}
				else 
				{
				SetColor(3);
				cout << "\t\t\tprogram Exited ... " << endl ;
				SetColor(x) ;
				sleep(3) ;
				exit(1);
				
				}
				break ;
			}
			
	case 5 :	
				SetColor(x);
				system("CLS") ;
				cout << "\t\t\t\t  AmeenGo Bus Adminstration System\n" << endl ;
				cout << "Clear Databases ->\n\n" ;
				cout << " (1) Clear All DataBase\n (2) Clear Exported Databases\n (3) Back to menu\n" ;
				cout << "\nChoose : " ;
				cin >> choice11 ;
			
					if ( choice11 == 1 )
					{						
								system("CLS") ;
								cout << "\t\t\t\t  AmeenGo Bus Adminstration System\n" << endl ;
								cout << "Clear All Databases ->\n\n" ;
								cleardata () ; 
								cout << "\tAll Databases Had been Deleted\n" ;
					}
					
					else if ( choice11 == 2 )
					{						
								system("CLS") ;
								cout << "\t\t\t\t  AmeenGo Bus Adminstration System\n" << endl ;
								cout << "Clear Exported Databases ->\n\n" ;
								clearexp () ;
								cout << "\tExported Databases Had been Deleted\n" ;
					}
					else if ( choice11 == 3 )
					{
						goto menu ;
					}
					else {
								SetColor(12) ;
								cout << "\t\tNo Correct Choice" << endl ;
								SetColor(x) ;
					}
				continuu :
				SetColor(10) ;
				cout << "\nPress Enter to Back to main menu or any key for Exit .. " << endl ; // continue function in system
				cin.ignore();
				if ( cin.get() == '\n' )
				{
					SetColor(x);
					goto menu ;
				}
				else 
				{
				SetColor(3);
				cout << "\t\t\tprogram Exited ... " << endl ;
				SetColor(x) ;
				sleep(3) ;
				exit(1);
				
				}
	
	case 6 : 	
				SetColor(x);
				system("CLS") ;
				cout << "\t\t\t\t  AmeenGo Bus Adminstration System\n" << endl ;
				cout << "Edit Adminstration Login ->\n\n" ;
				loginedit() ;
				SetColor(10) ;
				cout << "\nPress Enter to Back to main menu or any key for Exit .. " << endl ; // continue function in system
				cin.ignore();
				if ( cin.get() == '\n' )
				{
					SetColor(x);
					goto menu ;
				}
				else 
				{
				SetColor(3);
				cout << "\t\t\tprogram Exited ... " << endl ;
				SetColor(x) ;
				sleep(3) ;
				exit(1);
				
				}
			
	
	case 7 :    SetColor(3) ; // finished
				cout << "\tSystem Logout" << "\n\t   Saving Data ... " << endl << endl ;
				SetColor(x) ;
				sleep(3) ;
				exit(1);
				break ;
	
	default : 
				ind2 ++ ;
				cout << "\t\tNo Correct Choice Try Again" << endl ;
				if ( ind2 == 3 )
				{
				SetColor(12) ;
				cout << "\t\tYou Failed 3 times Program Exited" << endl ;
				SetColor(x) ;
				sleep(3) ;
				exit(1) ;
				break ;
				}
				else 
				{
					sleep(2) ;
					goto menu ;
				}
}
}
return 0 ;
}