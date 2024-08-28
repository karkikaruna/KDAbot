#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
const string BOLD = "\033[1m";
const string UNDERLINE = "\033[4m";
class loginRegistration {
public:
    void herobeforelogin() {
        int c;
        do {
            system("cls");

            cout << endl << endl;
            cout << BLUE << BOLD << "\t\t\t\t\t\t\t\tHi, I am KDA bot" << RESET << endl;
            cout << BLUE << BOLD << "\t\t\t\t\t\t\tI am your personal Assistant!" << RESET << endl;
            cout << endl << endl << endl;
            cout << CYAN << BOLD << "\t\t\t\t---------------------------------------------------------------------------------" << RESET << endl;
            cout << CYAN << BOLD << "\t\t\t\t|                    Please create your account to reach KDA bot.........        |" << RESET << endl;
            cout << CYAN << BOLD << "\t\t\t\t----------------------------------------------------------------------------------" << RESET << endl;
            cout << YELLOW << "\t\tPress 1 to LOGIN " << RESET << endl;
            cout << YELLOW << "\t\tPress 2 to REGISTER" << RESET << endl;
            cout << YELLOW << "\t\tPress 3 if you forget your PASSWORD" << RESET << endl;
            cout << YELLOW << "\t\tPress 4 to EXIT" << RESET << endl;
            cin >> c;
            cout << endl;

            switch (c) {
                case 1:
                    userLogin();
                    break;
                case 2:
                    registerUser();
                    break;
                case 3:
                    forgotPassword();
                    break;
                case 4:
                    cout<<" Do visit soon for good experience, I am under construction..."<<endl;
                    cout << "Thank you!" << endl;
                    cout<<"press any key "<<endl;
                    cin.ignore();
                    cin.get();
                    break;
                default:
                    cout << "Please choose a valid number \n" << endl;
                    break;
            }
        } while (c != 4);
    }

    void userLogin() {
        int count = 0;
        string userNam, userpass, id, pass;
        system("cls");
        cout << "Please enter the username and password: " << endl;
        cout << "Username: ";
        cin >> userNam;
        cout << "Password: ";
        cin >> userpass;

        ifstream read("userRecords.txt"); // to read the data
        while (read >> id >> pass) {
            if (id == userNam && pass == userpass) {
                count = 1;
                break;
            }
        }
        read.close();

        if (count == 1) {
            cout << userNam << "\nYour login is successful \nThanks for logging in!\n";
            heroAfterlogin(); // Call this function after successful login
        } else {
            cout << "\nPlease check your username and password" << endl;
            cout<<"press any key to go back to the login page"<<endl;
            cin.ignore();
            cin.get();
            system("cls");
        }
    }

    void registerUser() {
        string ruserNam, rpassword;
        cout << "Enter the username: ";
        cin >> ruserNam;
        cout << "Enter the password: ";
        cin >> rpassword;

        ofstream write("userRecords.txt", ios::app);
        write << ruserNam << ' ' << rpassword << endl;
        write.close();

        system("cls");
        cout << "Registration is successful!" << endl;
        cout<<"press any key to go back to the login page "<<endl;
        cin.get();
        system("cls");
        herobeforelogin();
    }

    void forgotPassword() {
        int option;
        system("cls");
        cout << "Forgot password?" << endl;
        cout << "Press 1 to search your id by username" << endl;  
        cout << "press 2 to reset your password "<<endl;
         cout << "Press 3 to go back to the main menu" << endl;
        cin >> option;

        switch (option) {
            case 1: {
                int count = 0;
                string fuserNam, fid, fpass;
                cout << "Enter the username which you remember: ";
                cin >> fuserNam;

                ifstream forg("userRecords.txt");
                while (forg >> fid >> fpass) {
                    if (fid == fuserNam) {
                        count = 1;
                        break;
                    }
                }
                forg.close();

                if (count == 1) {
                    cout << "Your account is found!\n";
                    cout << "Your password is: " << fpass << endl;
                    cout<<"press any key to go back to the main menu"<<endl;
                    cin.ignore();
                    cin.get();
                    system("cls");
                } else {
                    cout << "Sorry! Your account is not found" << endl;
                }
                break;
            }
                case 2:{
                void resetPassword(const string& username);
                  
                  break;
                  }
        break;
       case 3:
         break;
        default:
        cout << "Please try again" << endl;
        break;
        }
        
     
    }
    void resetPassword(const string& username) {
                string newPassword;
                cout << "Enter your new password: ";
                cin >> newPassword;

                ifstream inFile("userRecords.txt");
                    ofstream tempFile("temp.txt");
                string id, pass;

            while (inFile >> id >> pass) {
                if (id == username) {
                    tempFile << id << ' ' << newPassword << endl;
                } else {
                    tempFile << id << ' ' << pass << endl;
                }
            }
            inFile.close();
            tempFile.close();

            remove("userRecords.txt");
            rename("temp.txt", "userRecords.txt");

            cout << "Password reset successfully!" << endl;
            cout<<"press any key to go back to the main menu"<<endl;
            cin.ignore();
            cin.get();
            system("cls");
            
        }
    void heroAfterlogin() {
        cout<<"press any key to continue "<<endl;
        cin.ignore();
        cin.get();
        system("start kdaBot.exe");
    }
};
int main() {
    loginRegistration lg;
    lg.herobeforelogin();
    return 0;
}
