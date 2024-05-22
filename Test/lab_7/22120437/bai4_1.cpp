#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int n;
    cout << "Nhập số lượng ứng cử viên: ";
    cin >> n;

    string names[100]; 
    int votes[100];


    for (int i = 0; i < n; i++) {
        cout << "Nhập tên ứng cử viên " << i + 1 << ": ";
        cin >> names[i];
        cout << "Nhập số phiếu của " << names[i] << ": ";
        cin >> votes[i];
    }


    int totalVotes = 0;
    for (int i = 0; i < n; i++) {
        totalVotes += votes[i];
    }


    cout << "\nKết quả bầu cử:\n";
    for (int i = 0; i < n; i++) {
        double percentage = (double) votes[i] / totalVotes * 100;
        cout << names[i] << ": " << votes[i] << " phiếu (" << fixed << setprecision(2) << percentage << "%)\n";
    }


    int maxVotes = 0;
    int winnerIndex = 0;
    for (int i = 0; i < n; i++) {
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            winnerIndex = i;
        }
    }

    cout << "\nNgười chiến thắng là: " << names[winnerIndex] << " với " << maxVotes << " phiếu.\n";

    return 0;
}