#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// 기본 클래스: 교통수단
class Vehicle {
protected:
    string name;
    int speed;

public:
    Vehicle(string n, int s) : name(n), speed(s) {}

    virtual void displayInfo() const {
        cout << "교통수단: " << name << ", 속도: " << speed << " km/h" << endl;
    }

    virtual ~Vehicle() {}
};

// 파생 클래스: 자동차
class Car : public Vehicle {
private:
    int passengers;

public:
    Car(string n, int s, int p) : Vehicle(n, s), passengers(p) {}

    void displayInfo() const override {
        cout << "자동차: " << name << ", 속도: " << speed << " km/h, 승객: " << passengers << " 명" << endl;
    }
};

// 파생 클래스: 드론
class Drone : public Vehicle {
private:
    int altitude;

public:
    Drone(string n, int s, int a) : Vehicle(n, s), altitude(a) {}

    void displayInfo() const override {
        cout << "드론: " << name << ", 속도: " << speed << " km/h, 비행 고도: " << altitude << " 미터" << endl;
    }
};

// 파일 저장 함수
void saveToFile(const vector<Vehicle*>& vehicles, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "파일을 열 수 없습니다: " << filename << endl;
        return;
    }

    for (const auto& vehicle : vehicles) {
        // 다형성을 사용하여 다양한 교통수단 정보를 저장
        vehicle->displayInfo();
    }

    file.close();
    cout << "교통수단 정보가 파일에 저장되었습니다: " << filename << endl;
}

// 메인 함수
int main() {
    vector<Vehicle*> vehicles;

    // 교통수단 객체 생성
    vehicles.push_back(new Car("테슬라", 120, 4));
    vehicles.push_back(new Drone("배달 드론", 60, 500));

    // 교통수단 정보 표시
    cout << "미래의 스마트 교통 시스템: " << endl;
    for (const auto& vehicle : vehicles) {
        vehicle->displayInfo();
    }

    // 파일 저장
    string filename = "vehicles.txt";
    saveToFile(vehicles, filename);

    // 메모리 해제
    for (auto& vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}
