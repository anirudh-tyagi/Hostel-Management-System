#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;

class Hostel {
private:
    string name;
    int rent;
    int beds;

public:
    Hostel(string n, int r, int b) : name(n), rent(r), beds(b) {}

    string getName() const { return name; }
    int getRent() const { return rent; }
    int getBeds() const { return beds; }

    void reserve() {
        if (beds <= 0) {
            cout << "\tSorry, no beds available!" << endl;
            return;
        }

        ifstream inFile("Hostel.txt");
        if (!inFile) {
            cerr << "Error: Unable to open file for reading." << endl;
            return;
        }
        
        ofstream outFile("HostelTemp.txt");
        if (!outFile) {
            cerr << "Error: Unable to open file for writing." << endl;
            return;
        }

        string line;
        while (getline(inFile, line)) {
            if (line.find(name) != string::npos) {
                beds--; // Update bed count
                stringstream ss;
                ss << beds;
                size_t pos = line.find_last_of(':');
                line.replace(pos + 1, string::npos, ss.str());
            }
            outFile << line << endl;
        }

        inFile.close();
        outFile.close();

        remove("Hostel.txt");
        rename("HostelTemp.txt", "Hostel.txt");

        cout << "\tBed Reserved Successfully!" << endl;
    }
};

class Student {
private:
    string name, rollNo, address;

public:
    void setName(const string& n) { name = n; }
    void setRollNo(const string& r) { rollNo = r; }
    void setAddress(const string& a) { address = a; }

    string getName() const { return name; }
    string getRollNo() const { return rollNo; }
    string getAddress() const { return address; }
};

void saveHostelData(const Hostel& h) {
    ofstream outFile("Hostel.txt");
    if (!outFile) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }
    outFile << h.getName() << " : " << h.getRent() << " : " << h.getBeds() << endl;
    outFile.close();
    cout << "Hostel Data Saved Successfully." << endl;
}

void saveStudentData(const Student& s) {
    ofstream outFile("Student.txt", ios::app);
    if (!outFile) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }
    outFile << s.getName() << " : " << s.getRollNo() << " : " << s.getAddress() << endl;
    outFile.close();
}

int main() {
    Hostel hostel("3star", 5000, 2);
    saveHostelData(hostel);

    Student student;
    bool exitProgram = false;
    while (!exitProgram) {
        cout << "\n\tWelcome To Hostel Accommodation System" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t1. Reserve A Bed." << endl;
        cout << "\t2. Exit." << endl;
        cout << "\tEnter Choice: ";
        int choice;
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1: {
                cout << "\tEnter Name of Student: ";
                cin.ignore();
                string name;
                getline(cin, name);
                student.setName(name);
                
                cout << "\tEnter RollNo of Student: ";
                string rollNo;
                getline(cin, rollNo);
                student.setRollNo(rollNo);
                
                cout << "\tEnter Address of Student: ";
                string address;
                getline(cin, address);
                student.setAddress(address);
                
                if (hostel.getBeds() > 0) {
                    hostel.reserve();
                    saveStudentData(student);
                } else {
                    cout << "\tSorry, no beds available!" << endl;
                }
                break;
            }
            case 2:
                exitProgram = true;
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}