#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

vector<int> DATA;
vector<vector<int>> history;
int currentHistoryIndex = -1;

int loadFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open file." << endl;
        return 0;
    }
    int number;
    while (file >> number) {
        DATA.push_back(number);
    }
    file.close();
    return 1;
}

void saveToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open file." << endl;
        return;
    }
    for (int num : DATA) {
        file << num << " ";
    }
    file.close();
    cout << "DATA saved to " << filename << endl;
}

void printDATA() {
    for (int num : DATA) {
        cout << num << " ";
    }
    cout << endl;
}

void pushToHistory() {
    if (currentHistoryIndex < history.size() - 1) {
        history.erase(history.begin() + currentHistoryIndex + 1, history.end());
    }
    history.push_back(DATA);
    currentHistoryIndex++;
}

void undo() {
    if (currentHistoryIndex > 0) {
        currentHistoryIndex--;
        DATA = history[currentHistoryIndex];
        printDATA();
    } else {
        cout << "No more undo steps available." << endl;
    }
}

void redo() {
    if (currentHistoryIndex < history.size() - 1) {
        currentHistoryIndex++;
        DATA = history[currentHistoryIndex];
        printDATA();
    } else {
        cout << "No more redo steps available." << endl;
    }
}

void deleteElement(int pos) {
    if (pos < 0 || pos >= DATA.size()) {
        cout << "Invalid position." << endl;
        return;
    }
    pushToHistory();
    DATA.erase(DATA.begin() + pos);
}

void insertElement(int pos, int value) {
    if (pos < 0 || pos > DATA.size()) {
        cout << "Invalid position." << endl;
        return;
    }
    pushToHistory();
    DATA.insert(DATA.begin() + pos, value);
}

int main() {
    if (!loadFile("input.txt")) {
        return 0;
    }

    int choice;
    do {
        cout << "------------------------" << endl;
        cout << "1. Delete element at position" << endl;
        cout << "2. Insert element at position" << endl;
        cout << "3. Undo" << endl;
        cout << "4. Redo" << endl;
        cout << "5. Save" << endl;
        cout << "6. Reset" << endl;
        cout << "7. Quit" << endl;
        cout << "------------------------" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        int pos, value;
        switch (choice) {
            case 1:
                cout << "Enter position to delete: ";
                cin >> pos;
                deleteElement(pos);
                printDATA();
                break;
            case 2:
                cout << "Enter position to insert: ";
                cin >> pos;
                cout << "Enter value to insert: ";
                cin >> value;
                insertElement(pos, value);
                printDATA();
                break;
            case 3:
                undo();
                break;
            case 4:
                redo();
                break;
            case 5:
                saveToFile("output.txt");
                break;
            case 6:
                DATA.clear();
                loadFile("input.txt");
                break;
            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid option, try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
