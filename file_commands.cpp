#include "file_commands.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <limits>
#include <iomanip>

using namespace std;

struct Student {
    int number;
    string name;
    string surname;
    int yearOfAdmission;
    int course;
    int grade1; 
    int grade2;
    int grade3;
};

vector <Student> studentData = {};

bool isValue = true;

void StudentTest() {

    for(int i = 0; i < studentData.size() - 1; i++) {
        
        if(studentData[i].yearOfAdmission > studentData[i + 1].yearOfAdmission) {
            swap(studentData[i], studentData[i + 1]);
        }

    }

}

void overFlowStudent() {
    
    for(size_t i = 0; i < studentData.size(); i++) {
        
        studentData[i].number = i + 1;

    }

}

void coutFile(string filename) {

    ifstream file(filename);
    string data;

    int lines{};

    file.clear();
    file.seekg(0, ios::beg);

    while(getline(file, data)) {

        stringstream ss(data);

        replace(data.begin(), data.end(), ',', ' ');

        Student student;

        ss >> student.name
 >> student.surname >> student.yearOfAdmission >> student.course >> student.grade1 >> student.grade2 
        >> student.grade3;

        studentData.push_back(student);

    }

    file.close();

    overFlowStudent();

}


void clearTerminal() {
    cin.ignore(numeric_limits<streamsize>:: max(), '\n');
    cin.get();
}

void mainError() {
    cout << "Enter a correct number" << endl;
}

void sortData() {
    cout << "sort enable" << endl;
}

void viewData() {
    const string BLUE = "\033[34m";
    const string RESET = "\033[0m";

    cout << left;

    for(int i = 0; i < 130; i++) {
        cout << BLUE << "-" << RESET;
    }

    cout << "\n";

    cout << setw(15) << "Номер" << setw(15) << "Имя" << setw(25) << "Фамилия" << setw(35) << "Год поступления" 
    << setw(24) << "Курс" << setw(27) << "1 предмет" << setw(27) << "2 предмет" << setw(27) << "3 предмет" << endl;

    for(int i = 0; i < 130; i++) {
        cout << BLUE << "-" << RESET;
    }

    cout << "\n";
    
    for(Student item : studentData) {
        cout 
        << setw(5) << right << item.number << left
        << BLUE << setw(5) << "|" << RESET
        << setw(10 + item.name.length() / 2) << item.name
 
        << BLUE << setw(2) << "|" << RESET
        << setw(16 + item.surname.length() / 2) << item.surname 
        << BLUE << setw(13) << "|" << RESET
        <<   right << item.yearOfAdmission << left
        << BLUE << setw(6) << "|" << RESET
        << right << setw(4) << item.course << left
        << BLUE << setw(14) << "|" << RESET
        << setw(11) << right << item.grade1 
        << BLUE << setw(1) << "|" << RESET
        << setw(19) << item.grade2 
        << BLUE << setw(1) << "|" << RESET
        << setw(19) << item.grade3 << setw(5)
        << BLUE << "|" << RESET
        << endl;
    }

    for(int i = 0; i < 130; i++) {
        cout << BLUE << "-" << RESET;
    }

    clearTerminal();

}

void loadTextData() {

    cout << "load text enabled" << endl;

}

void loadBinaryData() {

    cout << "load binary enabled" << endl;

}

void deleteData() {

    int deletedStudent{};

    viewData();

    cout << "Напишите номер студента, которого хотите удалить" << endl;

    cin >> deletedStudent;

    studentData.erase(studentData.begin() + deletedStudent - 1);

    overFlowStudent();

}

void addEntry() {

    cin.ignore(numeric_limits<streamsize>:: max(), '\n');

    cout << "Введите имя, фамилию, год поступления, курс, и оценки по 3 предметам" << endl;
    string input;

    getline(cin, input);

    stringstream ss(input);

    Student newStudent;

    if(!(ss >> newStudent.name
 >> newStudent.surname >> newStudent.yearOfAdmission
    >> newStudent.course >> newStudent.grade1 >> newStudent.grade2 >> newStudent.grade3)) {
        cout << "Введите корректные значения!" << endl;
        return;
    }
    
    ss >> newStudent.name
 >> newStudent.surname >> newStudent.yearOfAdmission >> 
    newStudent.course >> newStudent.grade1 >> newStudent.grade2 >> newStudent.grade3;

    int lastIndex = studentData.back().number;
    newStudent.number = ++lastIndex;

    studentData.push_back(newStudent);
    isValue = false;

}   

void editTheEntry() {

    int studentNumber{};

    viewData();

    cout << "Введите номер студента:" << endl;

    cin >> studentNumber;
    
    int chooseStudent{};

    cout << "Выберите, что хотите изменить: Имя - 1, Фамилия -2, Год поступления - 3, Курс - 4, 1 оценка - 5, 2 оценка - 6, 3 оценка - 7" << endl;
    cin >> chooseStudent;

    int index = studentNumber - 1;


    switch(chooseStudent) {
        case 1: {
            string name;
            cin >> name;
            studentData[index].name = name;
            break;
        }
        case 2: {
            string surname;
            cin >> surname;
            studentData[index].surname = surname;
            break;
        }
        case 3: {
            int age;
            cin >> age;
            studentData[index].yearOfAdmission = age;
            break;
        }
        case 4: {
            int course;
            cin >> course;
            studentData[index].course = course;
            break;
        }
        case 5: {
            int grade1;
            cin >> grade1;
            studentData[index].grade1 = grade1;
            break;
        }
        case 6: {
            int grade2;
            cin >> grade2;
            studentData[index].grade2 = grade2;
            break;
        }
        case 7: {
            int grade3;
            cin >> grade3;
            studentData[index].grade3 = grade3;
            break;
        }
        default: cout << "Введите верное значение!" << endl;                   
    }

}

void sortAdminData() {
   
    for(size_t i = 0; i < studentData.size(); i++) {

        for(size_t j = 0; j + 1 < studentData.size() - i; j++) {
            if(studentData[j].course > studentData[j + 1].course) {
                swap(studentData[j], studentData[j + 1]);
            }
        }

    }

    overFlowStudent();

}

void outputData() {

    double minScore = 6;
    int minIndex{};

    for(size_t i = 0; i < studentData.size(); i++) {
        double averageScore = (studentData[i].grade1 + studentData[i].grade2 + studentData[i].grade3) / 3.0;
        if(minScore > averageScore) {
            minScore = averageScore;
            minIndex = i + 1;
        }
    }

    cout << "Наименьший средний балл: " << endl;

     for(int i = 0; i < 63; i++) {
        cout << "-";
    }

    cout << "\n";

    cout << left;

    cout << setw(15) << "Имя" 
    << setw(20) << "Фамилия"
    << setw(35) << "Год поступления" 
    << setw(15) 
    << "Курс" << setw(10) << "Балл" << endl;

    for(int i = 0; i < 63; i++) {
        cout << "-";
    }

     cout << "\n";

    for(Student item : studentData) {
        if(minIndex == item.number) {
            cout <<
            setw(12 + item.name.length() / 2) << item.name
 
            << setw(13 + item.surname.length() / 2) << item.surname 
            << setw(21) << item.yearOfAdmission 
            << setw(11) 
            << item.course
            << setw(10) << fixed << setprecision(2) << minScore << endl;
        }
    }

    for(int i = 0; i < 63; i++) {
        cout << "-";
    }

    cout << '\n';
} 

void getBinaryFile() {
    cout << "get binary enable" << endl;
}

void saveData() {
    
    ofstream file("list_students", ios::app);

    if (!isValue) {
        file << studentData.back().name << " " << studentData.back().surname 
        << " " << studentData.back().yearOfAdmission << " "  << studentData.back().course
        <<" " << studentData.back().grade1 << " " << studentData.back().grade2 << " " << studentData.back().grade3;
    }

    file << endl;

    file.close();
    isValue = true;

} 

void enterKeyboard() {
    cout << "enter keyboard enable" << endl;
}