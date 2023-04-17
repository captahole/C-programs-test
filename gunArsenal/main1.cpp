#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void display_menu();
const int total_width{70};
const int field1_width{10}; // Make
const int field2_width{30}; // Model
const int field3_width{10}; // Serial Number
const int field4_width{10}; // Date
const int field5_width{10}; // Price

class Item
{
public:
    string make;
    string model;
    string serialNum;
    string datePurchased;
    double price;

    Item(string mk, string md, string sn, string dp, double pr)
    {
        make = mk;
        model = md;
        serialNum = sn;
        datePurchased = dp;
        price = pr;
    }
};

void addItem(vector<Item> &items) // Function to add an item to the vector
{
    string make, model, serialNum, datePurchased;
    double price;

    cout << "Enter make: ";
    cin >> make;
    cout << "Enter model: ";
    cin >> model;
    cout << "Enter serial number: ";
    cin >> serialNum;
    cout << "Enter date purchased: ";
    cin >> datePurchased;
    cout << "Enter price: ";
    cin >> price;

    Item newItem(make, model, serialNum, datePurchased, price);
    items.push_back(newItem);

    cout << "Item added to list.\n\n";
}

// Function to print the list of items to a text file
void printListToFile(vector<Item> &items, string fileName)
{
    ofstream outFile;
    outFile.open(fileName);
    
        outFile << left
                << setw(field1_width) << "| Make:"  
                << setw(field2_width) << "| Model: "
                << setw(field3_width) << "| Serial Number:" 
                << setw(field4_width) << "| Date Purchased: "
                << setw(field5_width) << "| Price:"  << endl;
        outFile << std::setw(total_width)
                << std::setfill('-')
                << ""
                << std::endl; // display total_width dashes

        outFile << std::setfill(' '); // reset setfill to blank spaces
        for (int i = 0; i < items.size(); i++)
        {
        outFile << left
                << setw(field1_width) << " | " << setw(field1_width) << items[i].make
                << setw(field2_width) << " | " << items[i].model
                << setw(field3_width) << " | " << items[i].serialNum
                << setw(field4_width) << " | " << items[i].datePurchased
                << setw(field5_width) << " | " << right << items[i].price
                << endl;
        }

    outFile.close();

    cout << "List printed to file.\n\n";
}

int main()
{
    vector<Item> items; // Initialize the vector of items
    int choice = 0;
    

    while (choice != 3)
    {
        display_menu();
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
            addItem(items);
            break;
            }    
            case 2:
            {
            string fileName;
            cout << "Enter file name to save list to: ";
            cin >> fileName;
            printListToFile(items, fileName);
            break;
            }   
            case 3:
            cout << "Exiting program\n";
            break;
            
            default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    }

    return 0;
}

void display_menu()
{
    cout << "1. Add item to list\n";
    cout << "2. Print list to file\n";
    cout << "3. Exit program\n";
    cout << "Enter your choice: ";
}