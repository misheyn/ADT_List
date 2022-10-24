#include <iostream>
#include <ctime>
#include "MyList.h"

using namespace std;

void menu() {
    cout << endl
         << "*********** Operation menu ***********" << endl
         << "1  - Request list size" << endl
         << "2  - Clear the list" << endl
         << "3  - Check list for empty" << endl
         << "4  - Request the presence of an element" << endl
         << "5  - Read value by number in list" << endl
         << "6  - Change value by number in list" << endl
         << "7  - Get element position by value" << endl
         << "8  - Insert value" << endl
         << "9  - Delete value" << endl
         << "10 - Request statistics" << endl
         << "11 - Show all values" << endl
         << "0  - Exit" << endl;
}

void insertMenu(MyList<int> list) {
    int choice = -1;
    while (choice != 0) {
        cout << "_____Choose what you want to do:" << endl
        << "1 - Fill the list with random values" << endl
        << "2 - Insert new value" << endl
        << "3 - Insert new value by number" << endl
        << "0 - Go back" << endl;
        cout << "Enter number: ";
        cin >> choice;
        switch (choice) {
            case 1:
                srand(time(nullptr));
                for (int i = 0; i < list.sizeOfList(); ++i) {
                    list.push(-50 + rand() % 100);
                }
                break;
            case 2:
                int val;
                cout << "Enter value: ";
                cin >> val;
                if (list.push(val)) cout << "Done" << endl;
                break;
            case 3:
                int ind;
                cout << "Enter value: ";
                cin >> val;
                cout << "Enter index from 0 to " << list.sizeOfList() - 1 << ": ";
                cin >> ind;
                if (list.push(val, ind)) cout << "Done" << endl;
                break;
            default:
                break;
        }
    }
}

void deleteMenu(MyList<int> list) {
    int choice = -1;
    while (choice != 0) {
        cout << "_____Choose what you want to do:" << endl
        << "1 - Delete value" << endl
        << "2 - Delete value by number" << endl
        << "0 - Go back" << endl;
        cout << "Enter number: ";
        cin >> choice;
        switch (choice) {
            case 1:
                int val;
                cout << "Enter value: ";
                cin >> val;
                if (list.pop(val)) cout << "Done" << endl;
                else cout << "Failed to delete. This value isn't in the list" << endl;
                break;
            case 2:
                int ind;
                cout << "Enter index from 0 to " << list.sizeOfList() - 1 << ": ";
                cin >> ind;
                if (list.popByInd(ind)) cout << "Done" << endl;
                else cout << "Failed to delete. Invalid index entered" << endl;
                break;
            default:
                break;
        }
    }
}

int main() {

    int key = -1, len = -1;
    cout << "Create a list. Enter the desired number of items: ";
    cin >> len;
    MyList<int> list(len);
    while (1) {
        menu();
        cout << endl << "Enter operation number: ";
        cin >> key;
        switch (key) {
            case 1:
                cout << "Size of list: " << list.sizeOfList() << endl;
                break;
            case 2:
                list.clear();
                cout << "Done" << endl;
                break;
            case 3:
                if (list.isEmpty()) cout << "List is empty" << endl;
                else cout << "List isn't empty" << endl;
                break;
            case 4:
                int val;
                cout << "Enter value: ";
                cin >> val;
                if (list.isExist(val)) cout << "Element is in the list" << endl;
                else cout << "Element isn't in the list" << endl;
                break;
            case 5:
                int ind;
                cout << "Enter index: ";
                cin >> ind;
                cout << "Value of this index: " << list.readValue(ind) << endl;
                break;
            case 6:
                cout << "Enter index: ";
                cin >> ind;
                cout << "Enter value: ";
                cin >> val;
                list.changeValue(ind, val);
                cout << "Done" << endl;
                break;
            case 7:
                cout << "Enter value: ";
                cin >> val;
                ind = list.getIndByValue(val);
                if (ind != -1) cout << "Element position: " << ind << endl;
                else cout << "This element isn't in the list" << endl;
                break;
            case 8:
                insertMenu(list);
                break;
            case 9:
                deleteMenu(list);
                break;
            case 10:
                cout << list.stat << endl;
                break;
            case 11:
                list.print();
                break;
            case 0:
                return 0;
            default:
                break;
        }
    }
}
