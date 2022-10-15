
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

///<summary>
/// Method to validate if the user is logged in
///</summary>
bool BlnLogin()
{
    /// Variables
    string strPassword, strMail, strUser, strPaw;

    cout<<"Enter a mail: "; cin >> strMail;
    cout<<"Enter a password: "; cin >> strPassword;

    // Read file.
    ifstream read("C:\\src\\" + strMail + ".txt");
    getline(read, strUser);
    getline(read, strPaw);

    // Validate mail and password
    if(strUser == strMail && strPaw == strPassword)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // Variables
    int choice;
    string strPassword, strMail;
    bool blnStatus;
    
    //Menu
    cout <<"1: Register\n2: Login\nYour choice: "; cin >> choice;
    if(choice == 1)
    {
      cout << "Enter a mail: "; cin >> strMail;
      cout << "Enter a password: "; cin >> strPassword;
      
      //Save file
      ofstream file;
      file.open("C:\\src\\" + strMail + ".txt");
      file << strMail << endl << strPassword << endl;
      file.close();
      main();
    }
    else if(choice == 2)
    {
        blnStatus = BlnLogin();
        if(!blnStatus)
        {
            cout << "Login is not right!" << endl;
            system("PAUSE");
            return 0;
        }
        else
        {
            cout << "Login succesfully" << endl;
            system("PAUSE");
            return 1;
        }
    }
}