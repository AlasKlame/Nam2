#include<iostream>
#include <unordered_set> 
using namespace std;

class CIntArray {
private:
    int *m_Array;
    int m_Length;

public:
    CIntArray() : m_Array(nullptr), m_Length(0) {}

    CIntArray(int *arr, int length) : m_Length(length) {
        m_Array = new int[m_Length];
        for (int i = 0; i < m_Length; i++) {
            m_Array[i] = arr[i];
        }
    }

    ~CIntArray() {
        delete[] m_Array;
    }

    void InputArray() {
        cout << "Enter the length of the array: ";
        cin >> m_Length;
        if (m_Length <= 0) {
            cout << "Invalid length. Please enter a positive integer." << endl;
            return;
        }
        m_Array = new int[m_Length];
        for (int i = 0; i < m_Length; i++) {
            cout << "Enter the element " << i << " of the array: ";
            cin >> m_Array[i];
        }
    }

    void OutputArray() {
        for (int i = 0; i < m_Length; i++) {
            cout << m_Array[i] << " ";
        }
        cout << endl;
    }

    void Remove() {
        unordered_set<int> seen;
        int index = 0;
        for (int i = 0; i < m_Length; ++i) {
            if (seen.find(m_Array[i]) == seen.end()) {
                m_Array[index++] = m_Array[i];
                seen.insert(m_Array[i]);
            }
        }
        m_Length = index;
    }

    void Remove(int position) {
        if (position < 0 || position >= m_Length) {
            cout << "Invalid position." << endl;
            return;
        }
        for (int i = position; i < m_Length - 1; i++) {
            m_Array[i] = m_Array[i + 1];
        }
        m_Length--;
    }

    void Remove(int n, int position) {
        if (position < 0 || position >= m_Length || n < 0) {
            cout << "Invalid position or number of elements." << endl;
            return;
        }
        for (int i = position; i < m_Length - n; i++) {
            m_Array[i] = m_Array[i + n];
        }
        m_Length -= n;
    }

    void Replace(int oldValue, int newValue) {
        for (int i = 0; i < m_Length; i++) {
            if (m_Array[i] == oldValue) {
                m_Array[i] = newValue;
            }
        }
    }

    void AddHead(int n) {
        m_Length++;
        int *temp = new int[m_Length];
        temp[0] = n;
        for (int i = 1; i < m_Length; i++) {
            temp[i] = m_Array[i - 1];
        }
        delete[] m_Array;
        m_Array = temp;
    }

    void AddTail(int n) {
        m_Length++;
        int *temp = new int[m_Length];
        for (int i = 0; i < m_Length - 1; i++) {
            temp[i] = m_Array[i];
        }
        temp[m_Length - 1] = n;
        delete[] m_Array;
        m_Array = temp;
    }

    void Insert(int value, int position) {
        if (position < 0 || position > m_Length) {
            cout << "Invalid position." << endl;
            return;
        }
        m_Length++;
        int *temp = new int[m_Length];
        for (int i = 0; i < position; i++) {
            temp[i] = m_Array[i];
        }
        temp[position] = value;
        for (int i = position + 1; i < m_Length; i++) {
            temp[i] = m_Array[i - 1];
        }
        delete[] m_Array;
        m_Array = temp;
    }

    int Max() {
        int max = m_Array[0];
        for (int i = 1; i < m_Length; i++) {
            if (m_Array[i] > max) {
                max = m_Array[i];
            }
        }
        return max;
    }

    int Min() {
        int min = m_Array[0];
        for (int i = 1; i < m_Length; i++) {
            if (m_Array[i] < min) {
                min = m_Array[i];
            }
        }
        return min;
    }

    void Ascending() {
        for (int i = 0; i < m_Length; i++) {
            for (int j = i + 1; j < m_Length; j++) {
                if (m_Array[i] > m_Array[j]) {
                    swap(m_Array[i], m_Array[j]);
                }
            }
        }
    }

    void Descending() {
        for (int i = 0; i < m_Length; i++) {
            for (int j = i + 1; j < m_Length; j++) {
                if (m_Array[i] < m_Array[j]) {
                    swap(m_Array[i], m_Array[j]);
                }
            }
        }
    }

    bool IsSymmetry() {
        for (int i = 0; i < m_Length / 2; i++) {
            if (m_Array[i] != m_Array[m_Length - i - 1]) {
                return false;
            }
        }
        return true;
    }

    void MoveForward(int n = 1) {
        if (n <= 0) {
            cout << "Invalid number of positions." << endl;
            return;
        }
        for (int k = 0; k < n; k++) {
            int temp = m_Array[0];
            for (int i = 0; i < m_Length - 1; i++) {
                m_Array[i] = m_Array[i + 1];
            }
            m_Array[m_Length - 1] = temp;
        }
    }

    void MoveBehind(int n = 1) {
        if (n <= 0) {
            cout << "Invalid number of positions." << endl;
            return;
        }
        for (int k = 0; k < n; k++) {
            int temp = m_Array[m_Length - 1];
            for (int i = m_Length - 1; i > 0; i--) {
                m_Array[i] = m_Array[i - 1];
            }
            m_Array[0] = temp;
        }
    }

    void Invert() {
        for (int i = 0; i < m_Length / 2; i++) {
            swap(m_Array[i], m_Array[m_Length - i - 1]);
        }
    }

    int Appearance(int n) {
        int count = 0;
        for (int i = 0; i < m_Length; i++) {
            if (m_Array[i] == n) {
                count++;
            }
        }
        return count;
    }
};

int main(){
    CIntArray arr;
    int choice;
    do {
        cout << "----- MENU -----" << endl;
        cout << "1. Input array" << endl;
        cout << "2. Output array" << endl;
        cout << "3. Remove duplicates" << endl;
        cout << "4. Remove element at position" << endl;
        cout << "5. Remove n elements starting from position" << endl;
        cout << "6. Replace element" << endl;
        cout << "7. Add element at the beginning" << endl;
        cout << "8. Add element at the end" << endl;
        cout << "9. Insert element at position" << endl;
        cout << "10. Find maximum element" << endl;
        cout << "11. Find minimum element" << endl;
        cout << "12. Sort array in ascending order" << endl;
        cout << "13. Sort array in descending order" << endl;
        cout << "14. Check if array is symmetric" << endl;
        cout << "15. Move elements forward" << endl;
        cout << "16. Move elements backward" << endl;
        cout << "17. Invert array" << endl;
        cout << "18. Count appearances of an element" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                arr.InputArray();
                break;
            case 2:
                arr.OutputArray();
                break;
            case 3:
                arr.Remove();
                break;
            case 4:
                int position;
                cout << "Enter the position: ";
                cin >> position;
                arr.Remove(position);
                break;
            case 5:
                int n, startPos;
                cout << "Enter the number of elements to remove: ";
                cin >> n;
                cout << "Enter the starting position: ";
                cin >> startPos;
                arr.Remove(n, startPos);
                break;
            case 6:
                int oldValue, newValue;
                cout << "Enter the old value: ";
                cin >> oldValue;
                cout << "Enter the new value: ";
                cin >> newValue;
                arr.Replace(oldValue, newValue);
                break;
            case 7:
                int headValue;
                cout << "Enter the value to add at the beginning: ";
                cin >> headValue;
                arr.AddHead(headValue);
                break;
            case 8:
                int tailValue;
                cout << "Enter the value to add at the end: ";
                cin >> tailValue;
                arr.AddTail(tailValue);
                break;
            case 9:
                int insertValue, insertPos;
                cout << "Enter the value to insert: ";
                cin >> insertValue;
                cout << "Enter the position to insert: ";
                cin >> insertPos;
                arr.Insert(insertValue, insertPos);
                break;
            case 10:
                cout << "Maximum element: " << arr.Max() << endl;
                break;
            case 11:
                cout << "Minimum element: " << arr.Min() << endl;
                break;
            case 12:
                arr.Ascending();
                break;
            case 13:
                arr.Descending();
                break;
            case 14:
                if (arr.IsSymmetry()) {
                    cout << "Array is symmetric" << endl;
                } else {
                    cout << "Array is not symmetric" << endl;
                }
                break;
            case 15:
                arr.MoveForward();
                break;
            case 16:
                arr.MoveBehind();
                break;
            case 17:
                arr.Invert();
                break;
            case 18:
                int element;
                cout << "Enter the element to count: ";
                cin >> element;
                cout << "Number of appearances: " << arr.Appearance(element) << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}