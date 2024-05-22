#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_TIME = 3;
const int MAX_FRACTION = 2;
const int MAX_STUDENTS = 100;
const int MAX_CARS = 100;
const int MAX_PLAYERS = 100;

// Bài tập 1: Thời gian
struct Time {
    int values[MAX_TIME]; // [hour, minute, second]
};

// Hàm tính khoảng cách thời gian
Time calculateTimeDifference(Time time1, Time time2) {
    Time difference;
    int totalSeconds1 = time1.values[0] * 3600 + time1.values[1] * 60 + time1.values[2];
    int totalSeconds2 = time2.values[0] * 3600 + time2.values[1] * 60 + time2.values[2];
    int diffSeconds = abs(totalSeconds1 - totalSeconds2);

    difference.values[0] = diffSeconds / 3600;
    difference.values[1] = (diffSeconds % 3600) / 60;
    difference.values[2] = diffSeconds % 60;

    return difference;
}

// Bài tập 2: Phân số
struct Fraction {
    int values[MAX_FRACTION]; // [numerator, denominator]
};

// Hàm tối giản phân số
Fraction simplifyFraction(Fraction fraction) {
    int gcd = __gcd(fraction.values[0], fraction.values[1]);
    fraction.values[0] /= gcd;
    fraction.values[1] /= gcd;
    return fraction;
}

// Hàm cộng hai phân số
Fraction addFractions(Fraction fraction1, Fraction fraction2) {
    Fraction sum;
    sum.values[0] = fraction1.values[0] * fraction2.values[1] +
                   fraction2.values[0] * fraction1.values[1];
    sum.values[1] = fraction1.values[1] * fraction2.values[1];
    return simplifyFraction(sum);
}

// Bài tập 3: Phân số nhỏ nhất
Fraction findSmallestFraction(Fraction fractions[], int numFractions) {
    Fraction smallestFraction = fractions[0];
    for (int i = 1; i < numFractions; i++) {
        Fraction simplifiedFraction = simplifyFraction(fractions[i]);
        if (simplifiedFraction.values[0] * smallestFraction.values[1] <
            smallestFraction.values[0] * simplifiedFraction.values[1]) {
            smallestFraction = simplifiedFraction;
        }
    }
    return smallestFraction;
}

// Bài tập 4: Quản lý Sinh viên
struct Student {
    int id;
    string name;
    float scores[3]; // [mathScore, physicsScore, chemistryScore]
};

// Hàm tính điểm trung bình
float calculateAverageScore(Student student) {
    return (student.scores[0] + student.scores[1] + student.scores[2]) / 3;
}

// Bài tập 5: Quản lý xe hơi
struct Car {
    string carMake;
    string carModel;
    int yearModel;
    double cost;
    int quantity;
};

// Hàm nhập thông tin xe mới
void inputNewCar(Car cars[], int& numCars) {
    cout << "Nhập thông tin xe mới:\n";
    cout << "Tên hãng: ";
    cin >> cars[numCars].carMake;
    cout << "Tên model: ";
    cin >> cars[numCars].carModel;
    cout << "Năm sản xuất: ";
    cin >> cars[numCars].yearModel;
    cout << "Giá: ";
    cin >> cars[numCars].cost;
    cout << "Số lượng: ";
    cin >> cars[numCars].quantity;
    numCars++;
    cout << "Đã thêm xe mới.\n";
}

// Hàm bán xe
void sellCar(Car cars[], int& numCars) {
    string carMake, carModel;
    int quantity;

    cout << "Nhập tên hãng xe: ";
    cin >> carMake;
    cout << "Nhập tên model xe: ";
    cin >> carModel;
    cout << "Nhập số lượng cần bán: ";
    cin >> quantity;

    bool found = false;
    for (int i = 0; i < numCars; i++) {
        if (cars[i].carMake == carMake && cars[i].carModel == carModel && cars[i].quantity >= quantity) {
            cars[i].quantity -= quantity;
            cout << "Đã bán " << quantity << " xe " << carMake << " " << carModel << ".\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Không tìm thấy xe hoặc số lượng không đủ.\n";
    }
}

// Hàm thu hồi xe cũ
void removeCar(Car cars[], int& numCars) {
    string carMake, carModel;

    cout << "Nhập tên hãng xe: ";
    cin >> carMake;
    cout << "Nhập tên model xe: ";
    cin >> carModel;

    bool found = false;
    for (int i = 0; i < numCars; i++) {
        if (cars[i].carMake == carMake && cars[i].carModel == carModel) {
            for (int j = i; j < numCars - 1; j++) {
                cars[j] = cars[j + 1];
            }
            numCars--;
            cout << "Đã thu hồi xe " << carMake << " " << carModel << ".\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Không tìm thấy xe.\n";
    }
}

// Bài tập 6: Quản lý cầu thủ
struct Player {
    string name;
    int numAssists;
    int numGoals;
};

// Hàm tính điểm bestPlayer
float calculateBestPlayerScore(Player player) {
    return 0.4 * player.numAssists + 0.6 * player.numGoals;
}

// Hàm thêm cầu thủ mới
void addPlayer(Player players[], int& numPlayers) {
    cout << "Nhập thông tin cầu thủ mới:\n";
    cout << "Tên cầu thủ: ";
    cin >> players[numPlayers].name;
    cout << "Số lượng kiến tạo: ";
    cin >> players[numPlayers].numAssists;
    cout << "Số lượng bàn thắng: ";
    cin >> players[numPlayers].numGoals;
    numPlayers++;
    cout << "Đã thêm cầu thủ mới.\n";
}

// Hàm xóa cầu thủ
void removePlayer(Player players[], int& numPlayers) {
    string name;

    cout << "Nhập tên cầu thủ cần xóa: ";
    cin >> name;

    bool found = false;
    for (int i = 0; i < numPlayers; i++) {
        if (players[i].name == name) {
            for (int j = i; j < numPlayers - 1; j++) {
                players[j] = players[j + 1];
            }
            numPlayers--;
            cout << "Đã xóa cầu thủ " << name << ".\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Không tìm thấy cầu thủ.\n";
    }
}

// Hàm cập nhật thông tin cầu thủ
void updatePlayer(Player players[], int numPlayers) {
    string name;
    int choice, newValue;

    cout << "Nhập tên cầu thủ cần cập nhật: ";
    cin >> name;

    bool found = false;
    for (int i = 0; i < numPlayers; i++) {
        if (players[i].name == name) {
            cout << "Bạn muốn cập nhật gì?\n";
            cout << "1. Số lượng kiến tạo\n";
            cout << "2. Số lượng bàn thắng\n";
            cout << "Chọn lựa chọn: ";
            cin >> choice;

            if (choice == 1) {
                cout << "Nhập số lượng kiến tạo mới: ";
                cin >> newValue;
                players[i].numAssists = newValue;
                cout << "Đã cập nhật số lượng kiến tạo.\n";
            } else if (choice == 2) {
                cout << "Nhập số lượng bàn thắng mới: ";
                cin >> newValue;
                players[i].numGoals = newValue;
                cout << "Đã cập nhật số lượng bàn thắng.\n";
            } else {
                cout << "Lựa chọn không hợp lệ.\n";
            }
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Không tìm thấy cầu thủ.\n";
    }
}

// Hàm tìm cầu thủ xuất sắc nhất
Player findBestPlayer(Player players[], int numPlayers) {
    Player bestPlayer = players[0];
    for (int i = 1; i < numPlayers; i++) {
        if (calculateBestPlayerScore(players[i]) > calculateBestPlayerScore(bestPlayer)) {
            bestPlayer = players[i];
        }
    }
    return bestPlayer;
}

int main() {
    // Bài tập 1: Thời gian
    Time time1 = {{10, 30, 15}};
    Time time2 = {{12, 15, 45}};
    Time difference = calculateTimeDifference(time1, time2);
    cout << "Khoảng cách thời gian: " << difference.values[0] << " giờ " << difference.values[1]
         << " phút " << difference.values[2] << " giây" << endl;

    // Bài tập 2: Phân số
    Fraction fraction1 = {{2, 3}};
    Fraction fraction2 = {{1, 2}};
    Fraction sum = addFractions(fraction1, fraction2);
    cout << "Tổng hai phân số: " << sum.values[0] << "/" << sum.values[1] << endl;

    // Bài tập 3: Phân số nhỏ nhất
    Fraction fractions[3] = {{{1, 2}}, {{3, 4}}, {{2, 5}}};
    Fraction smallestFraction = findSmallestFraction(fractions, 3);
    cout << "Phân số nhỏ nhất: " << smallestFraction.values[0] << "/"
         << smallestFraction.values[1] << endl;

    // Bài tập 4: Quản lý Sinh viên
    Student students[MAX_STUDENTS] = {
        {1, "Nguyen Van A", {8.0, 7.5, 9.0}},
        {2, "Tran Thi B", {9.0, 8.5, 8.0}},
        {3, "Le Van C", {7.0, 6.5, 7.5}}
    };

    // Tìm sinh viên có điểm trung bình cao nhất và thấp nhất
    int highestScoreIndex = 0;
    int lowestScoreIndex = 0;
    for (int i = 1; i < 3; i++) { // Giả sử có 3 sinh viên
        if (calculateAverageScore(students[i]) > calculateAverageScore(students[highestScoreIndex])) {
            highestScoreIndex = i;
        }
        if (calculateAverageScore(students[i]) < calculateAverageScore(students[lowestScoreIndex])) {
            lowestScoreIndex = i;
        }
    }

    cout << "\nSinh viên có điểm trung bình cao nhất:\n";
    cout << "ID: " << students[highestScoreIndex].id << endl;
    cout << "Tên: " << students[highestScoreIndex].name << endl;
    cout << "Điểm trung bình: " << calculateAverageScore(students[highestScoreIndex]) << endl;

    cout << "\nSinh viên có điểm trung bình thấp nhất:\n";
    cout << "ID: " << students[lowestScoreIndex].id << endl;
    cout << "Tên: " << students[lowestScoreIndex].name << endl;
    cout << "Điểm trung bình: " << calculateAverageScore(students[lowestScoreIndex]) << endl;

    // Bài tập 5: Quản lý xe hơi
    Car cars[MAX_CARS];
    int numCars = 0;
    cars[numCars++] = {"Ford", "Taurus", 1997, 21000, 10};
    cars[numCars++] = {"Honda", "Accord", 1992, 11000, 5};

    int choice;
    do {
        cout << "\nMenu quản lý xe hơi:\n";
        cout << "1. In danh sách xe\n";
        cout << "2. Nhập xe mới\n";
        cout << "3. Bán xe\n";
        cout << "4. Thu hồi xe cũ\n";
        cout << "5. Thoát\n";
        cout << "Chọn lựa chọn: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (numCars == 0) {
                    cout << "Danh sách xe trống.\n";
                } else {
                    cout << "\nDanh sách xe:\n";
                    for (int i = 0; i < numCars; i++) {
                        cout << "Hãng: " << cars[i].carMake << endl;
                        cout << "Model: " << cars[i].carModel << endl;
                        cout << "Năm sản xuất: " << cars[i].yearModel << endl;
                        cout << "Giá: " << cars[i].cost << endl;
                        cout << "Số lượng: " << cars[i].quantity << endl;
                        cout << "--------------------\n";
                    }
                }
                break;
            }
            case 2:
                inputNewCar(cars, numCars);
                break;
            case 3:
                sellCar(cars, numCars);
                break;
            case 4:
                removeCar(cars, numCars);
                break;
            case 5:
                cout << "Kết thúc chương trình.\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ.\n";
        }
    } while (choice != 5);

    // Bài tập 6: Quản lý cầu thủ
    Player players[MAX_PLAYERS];
    int numPlayers = 0;
    players[numPlayers++] = {"Lionel Messi", 28, 8};
    players[numPlayers++] = {"Antoine Griezmann", 12, 6};

    do {
        cout << "\nMenu quản lý cầu thủ:\n";
        cout << "1. In danh sách cầu thủ\n";
        cout << "2. Thêm cầu thủ mới\n";
        cout << "3. Xóa cầu thủ\n";
        cout << "4. Cập nhật thông tin cầu thủ\n";
        cout << "5. Tìm cầu thủ xuất sắc nhất\n";
        cout << "6. Thoát\n";
        cout << "Chọn lựa chọn: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (numPlayers == 0) {
                    cout << "Danh sách cầu thủ trống.\n";
                } else {
                    cout << "\nDanh sách cầu thủ:\n";
                    for (int i = 0; i < numPlayers; i++) {
                        cout << "Tên: " << players[i].name << endl;
                        cout << "Số lượng kiến tạo: " << players[i].numAssists << endl;
                        cout << "Số lượng bàn thắng: " << players[i].numGoals << endl;
                        cout << "--------------------\n";
                    }
                }
                break;
            }
            case 2:
                addPlayer(players, numPlayers);
                break;
            case 3:
                removePlayer(players, numPlayers);
                break;
            case 4:
                updatePlayer(players, numPlayers);
                break;
            case 5: {
                Player bestPlayer = findBestPlayer(players, numPlayers);
                cout << "\nCầu thủ xuất sắc nhất:\n";
                cout << "Tên: " << bestPlayer.name << endl;
                cout << "Số lượng kiến tạo: " << bestPlayer.numAssists << endl;
                cout << "Số lượng bàn thắng: " << bestPlayer.numGoals << endl;
                cout << "Điểm: " << calculateBestPlayerScore(bestPlayer) << endl;
                break;
            }
            case 6:
                cout << "Kết thúc chương trình.\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ.\n";
        }
    } while (choice != 6);

    return 0;
}