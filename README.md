# Bus-Mangement-System 
Reservation Bus Line Administration System (Simulator System by C++) : -
Is system used by reservation bus companies in their stations to control the data of the  ( customers – buses ) at used databases that can be used locally or can be used by host server to share the databases among the stations of the company.

Our system is secured as it has a locally one admin account that its data is Encrypted
In the admin database that no one can know the real email & password of the locally Administration system all the data that required to login is totally Encrypted & the data that stored in the data base are not in the exported form so no one can use it.

After login, the system had 7 main functions to control the flow data of the reservation process every function had some of subfunctions.
The main processes that control the flow of data are (Add New Bus Line - Client Registration - Client Information - Lines Information - Clear Databases - Edit Administration Login – Logout & saving data).
All data stored as strings except (financial data – counting data) to avoid the most entering data errors & there are functions to confirm the entered data or to edit it.
All data exported to files that can be used locally as database or can be merged on a host server to share the data among the company servers.
Please be attention & read user manual before using the system to avoid entering wrong data which will make you face a lot of problems.
Our system is not case sensitive & can store up to 3 GB in each Database file.


#######################################################################################

First, you need 2 main files with the Application .exe file in the same folder to run the program with a correct way (admin.txt, journey) the 2 files of the database used in login & storing data.
All these files are ready in the WinRAR file just Extract it.
Do not worry from admin.txt file as you cannot read what it contains, all the data saved in it is just Encrypted.

Operating errors: - 
    • The admin.txt file will cause an logical error if it’s not found in the file of the program as it’s a database file that the program use to check the login information so if it’s not found it won’t able the system to login even the email & password are correct .
    • The journey file is the database used to store the lines information so if it’s not found the program can’t run and store the data in it as it is not exist, so if you don’t have this file the system will cause infinity loops.

########################################################################################

Login: -
    • The default Administration Login data -> Email: admin & Password: admin.
    • After login you must change this data to protect your databases.
    • Also, the admin.txt file had data Encrypted so no one can know your email & password from it, and the appeared data in it cannot used in login.
    • If you entered invalid email & password there will be error message to re-enter the login.
    If you entered invalid email & password for 3 times the program will Exit.
    
########################################################################################

Main: -
    • had 7 main functions that used in our system each function had some features.
    
2.1) ADD New Bus Line: -
This feature will made you add a new bus line to the main database.
    • Time is in 24 formats, there space between the hours & minutes entry.
    • Capacity must be entered as integer so any letters will break the process.
    • Journey code must be 4 characters without any space in entry. 
    • Any confirmation (continue) question can accept lower- and upper-case entry.
    • If you choose to edit data, choose your data number to edit then it saved.
    
(2.2) Client Registration: -
    • When you register new customer, the available lines will be showed automatically that you can enter the code of the line you want to register in.
    • The client name must not contain spaces.
    • The time of registration will be saved and showed automatically.
    • You will need to click enter to back to menu or any other key for exit system.
    
(2.3) Lines Information: -
    • This function is used to view the available & non available lines 
    • used to export the lines information in external database that the data can be readable, the function is not sensitive case (accept upper & lower) cases.

(2.4) Client Information: -
    • This function is used to show the customers information in each line.
    • The lines will be showed automatically to enter the code of the line you want.
    • There is ability to return to menu by clicking m or M in the line code field.
    • The customers information will be exported automatically in external file.
    
(2.5) Clear Databases: -
    • (1) to clear all databases, you entered and exported without delete any operating files.
    • (2) to delete only databases, you had exported from the main database.
    
(2.6) Edit Administration Login: -
    • The first function you must do after login with the default login information.
    • After that, your new data will be saved in the admin.txt file as Encrypted data.
    • Your data will be unreadable so if you entered the shown data in login the system will not login.
    
(2.7) Logout Function: -
    • Finally, the system will logout and save all data you added.
