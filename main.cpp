/*This program was developed to register users with email and a password. 
In order to store this information, a record was created in a text file with the email of each registered user. 
For the user, a menu is displayed where they choose whether to register or log in.*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Global variables
string strMail;
string strPassword;

///<summary>
/// Method to validate if the user is logged in
///</summary>
bool BlnLogin()
{
    /// Variables
    string strUser;
    string strPaw;

    //Enter main information to login 
    cout<<"Enter a mail: "; cin >> strMail;
    cout<<"Enter a password: "; cin >> strPassword;

    // Read file.
    ifstream read("C:\\src\\" + strMail + ".txt");
    getline(read, strUser);
    getline(read, strPaw);
    

    // Validate mail and password
    if(strUser == "Mail: " + strMail && strPaw == "Password: " + strPassword)
    {
        return true;
    }
    else
    {
        return false;
    }
}
///<summary>
/// Main method
///</summary>
int main()
{
    // Variables
    int intChoice;
    string strName, strLastname, strPhone;
    bool blnStatus;
    
    system("CLS"); // Clear screen
    //Menu
    cout << "Menu";
    cout <<"\n===========================\n";
    cout << "1: Register\n";
    cout << "2: Login\n";
    cout << "===========================\n";
    cout << "Enter your choice: "; cin >> intChoice;
   
    system("CLS");// Clear screen
    if(intChoice == 1)
    {
      //Register
      cout << "Please, enter all information required\n";
      cout << "Enter your mail: "; cin >> strMail;
      cout << "Enter a password: "; cin >> strPassword;
      cout <<"Enter your name: "; cin >> strName;
      cout <<"Enter your lastname: "; cin >> strLastname;
      cout << "Enter your phone number: "; cin >> strPhone;
           
      //Save file
      ofstream file;

      file.open("C:\\src\\" + strMail + ".txt");
      file << "Mail: " + strMail << endl;
      file << "Password: " + strPassword << endl;
      file <<  "Name: " + strName << endl;
      file << "Lastname: " + strLastname << endl; 
      file << "Phone: " + strPhone << endl;
    
      file.close();
      main();
    }
    else if(intChoice == 2)
    {
        // Login
        cout << "Please, enter all information required\n";
        blnStatus = BlnLogin();
        if(!blnStatus)
        {
            // Login failed
            cout << "Login is not right!" << endl;
            system("PAUSE");
            return 0;
        }
        else
        {
            // Login successfully
            cout << "Login successfully" << endl;
            ifstream read("C:\\src\\" + strMail + ".txt");
            getline(read, strMail);
            getline(read, strPassword);
            getline(read, strName);
            getline(read, strLastname);
            getline(read, strPhone);

            system("CLS");// Clear screen
            
            cout <<"User information: \n";
            cout << "Mail: " + strMail << endl;
            cout << "Password: " + strPassword  << endl;
            cout << "Name: " + strName  << endl;
            cout << "Lastname: " + strLastname  << endl;
            cout << "Phone: " + strPhone  << endl;

            system("PAUSE");
            return 1;
        }
    }
}