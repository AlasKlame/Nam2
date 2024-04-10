#include <iostream>
using namespace std;

int bruteforce(float buffaloes, float bunches_of_grass) {
    int count = 0;
    for (int standing = 1; standing < buffaloes; ++standing) {
        for (int lying = 1; lying < buffaloes - standing; ++lying) {
            float oldbulls = (buffaloes - standing - lying);
            if ((float)(standing * 5 + lying * 3 +(float)( oldbulls / 3)) == bunches_of_grass) {
                cout << "(" << standing << ", " << lying << ", " << oldbulls << ")" << endl;
                ++count;
            }
        }
    }
    return count;
}

int main() {
    float buffaloes, bunches_of_grass;
    cout << "Enter the number of buffaloes: ";
    cin >> buffaloes;
    cout << "Enter the number of bunches of grass: ";
    cin >> bunches_of_grass;

    cout << "Number of valid combinations: " << bruteforce(buffaloes, bunches_of_grass) << endl;

    return 0;
}
