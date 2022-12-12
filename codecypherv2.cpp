// Section 10 v2
// Substitution Cipher
#include <iostream>
#include <iomanip>
#include <string> 
#include <unistd.h> // for sleep()
#include <cctype> 
using namespace std;

// menu and selection 
void display_menu();
char get_selection();
void handle_quit();
void handle_unknown();
// message, encrption,decrption
void encrypted_message (string &c);
void decrypted_message (string &c);

int main() {
    
     string message {};
     char selection {};
    
    do {
         display_menu();
         selection = get_selection ();
         switch (selection) {
            case 'E': 
                 encrypted_message(message); 
                break;
            case 'D':
                 decrypted_message (message);
                break;
            case 'Q':
                handle_quit();
                break;
            default:
                handle_unknown();
         }
        } while (selection != 'Q');
            cout << endl;
            return 0;
    }
    // display menu definition
    void display_menu (){
    cout << "\nSecret Message Machine \n";
        cout << "E - Encrypt Message \n";
        cout << "D - Decrypt Message \n";
        cout << "Q - Quit \n";
        cout << "\nEnter your choice: ";
    }
    // selection defenition
    char get_selection (){
    char selection {};
    cin >> selection;
    return toupper(selection);
    }
    // enter encrypted message
 void encrypted_message (string &c) {
                string message {};
                 string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"};
                 string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr0987654321"};
                string encrypted_message {};
                string decrypted_message {};
            cout << "Enter your message: ";
            cin.ignore();
            getline (cin, message );
            cout << "\n*** Encrypting message *** \n";
             while (true)
        {
            sleep(1);
            cout << "*" << flush;
            sleep(1);
            cout << "*" << flush;
            sleep(1);
            cout << "*" << flush;
            sleep(1);
            cout << "\b\b\b   \b\b\b" << flush;
            break;
        }       
                for (char c : message ) {
                size_t position = alphabet.find(c);
                if (position != string::npos) {
                 char new_char { key.at(position) };
                 encrypted_message += new_char;
                } else {
                    encrypted_message += c;
                }
            }
                cout << "Encrypted message: " << encrypted_message << endl;  
    }
    // decrypted messsage
    void decrypted_message (string &c){
            string message {};
             string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"};
             string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr0987654321"};
            string encrypted_message {};
            string decrypted_message {};
            cout << "Enter your message: ";
            cin.ignore();
            getline(cin, encrypted_message);
            cout << "\n*** Decrypting message *** \n";
            while (true)
            {
            sleep(1);
            cout << "*" << flush;
            sleep(1);
            cout << "*" << flush;
            sleep(1);
            cout << "*" << flush;
            sleep(1);
            cout << "\b\b\b   \b\b\b" << flush;
            break;
            }  
            for (char c : encrypted_message ) {
             size_t position = key.find(c);
                if (position != string::npos) {
                char new_char {alphabet.at(position)};
                decrypted_message += new_char;
                } else {
                decrypted_message += c;
                }
            }
            cout << "Decrypted message: " << decrypted_message << endl;

    }
    /***************************************************************
    This function is called when the user selects the quit 
        option from the main menu
    ***************************************************************/
    void handle_quit() {
    cout << "Goodbye" << endl;
    }
    /***************************************************************
    This function is called whenever the user enters a selection
    and we don't know how to handle it.
    It is not one of the valid options in the main menu
    ***************************************************************/
    void handle_unknown() {
    cout << "Unknown selection - try again" << endl;
}

