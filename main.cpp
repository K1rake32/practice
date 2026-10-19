#include <iostream>
#include <cmath>
#include "file_commands.h"
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

struct MainMenu
{
    int number;
    string title;
    void (*action)();
};

struct StartMenu
{
    int number;
    string title;
};

void startMenu() {

    coutFile("list_students");

    int mainChoose = -1;

    StartMenu startMenuItems[] = {
        {1, "Авторизоваться как пользователь"},
        {2, "Авторизоваться как администратор"}
    };

    MainMenu userMainMenu[] = {
        {1, "Посмотреть данные", viewData},
        {2, "Загрузить данные", nullptr},
        {3, "Отсортировать данные", sortData},
    };

    MainMenu userMinorMenu[] = {
        {1, "Загрузить данные из текстового файла", loadTextData},
        {2, "Загрузить данные из бинарного файла", loadBinaryData}
    };

    MainMenu adminMainMenu[] = {
        {1, "Посмотреть данные", viewData},
        {2, "Загрузить данные", nullptr},
        {3, "Изменить запись", editTheEntry},
        {4, "Удалить запись", deleteData},
        {5, "Добавить запись", addEntry},
        {6, "Вывод данных по запросу", outputData},
        {7, "Отсортировать данные по любому из полей",sortAdminData},
        {8, "Получить бинарный файл из текстового", getBinaryFile},
        {9, "Сохранить данные", saveData}
    };

    MainMenu adminMinorMenu[] = {
        {1, "Загрузить данные из текстового файла", loadTextData},
        {2, "Загрузить данные из бинарного файла", loadBinaryData},
        {3, "Ввести с клавиатуры", enterKeyboard}
    };

    while (true)
    {

        
        for(const StartMenu& item : startMenuItems){
            cout << item.number << ": " << item.title << endl;
        }

        int choose{};
        cin >> choose;

        if(choose == 0) {
            break;
        }

        for(const StartMenu& item: startMenuItems) {
            if(item.number == choose) {
                cout << item.title << endl;
                break;
            }
        }

        switch(choose) {
            case 0: break;
            case 1: {
                while(true) {
                    
                    for(const MainMenu& item: userMainMenu) {
                    cout << item.number << ": " << item.title << endl;
                    }
                    
                    int userMainChoose{};
                    cin >> userMainChoose;

                    if(userMainChoose == 0) {
                        break;
                    }

                    for(const MainMenu& item: userMainMenu) {
                        if(userMainChoose == item.number) {
                            if(item.action != nullptr) {
                                item.action();
                            }

                            else {
                            for(const MainMenu& thing: userMinorMenu) {
                                cout << thing.number << ": " << thing.title << endl;
                            }

                            int userMinorChoose{};
                            cin >> userMinorChoose;

                            if(userMinorChoose == 0) {
                                break;
                            }

                            for(const MainMenu& object: userMinorMenu) {
                                if(userMinorChoose == object.number) {
                                    object.action();
                                }
                            }
                        }
                        } 
                    }
                }
                break;
            }
            case 2: {
                while(true) {
                     for(const MainMenu& item : adminMainMenu) {
                    cout << item.number << ": " << item.title << endl;;
                } 
                int mainAdminChoose = -1;
                cin >> mainAdminChoose;

                if(mainAdminChoose == 0) {
                    break;
                }

                for(const MainMenu& item: adminMainMenu) {
                    if(mainAdminChoose == item.number) {
                        if(item.action != nullptr) {
                            item.action();
                        } else {
                            for(const MainMenu& object : adminMinorMenu) {
                                cout << object.number << ": " << object.title << endl; 
                            }

                            int minorAdminChoose = -1;
                            cin >> minorAdminChoose;

                            for(const MainMenu& object : adminMinorMenu) {
                                if(minorAdminChoose == object.number) {
                                    object.action();
                                }
                            }
                        }
                        
                    }
                }
                }
                break;
            }
            default: mainError();
        }
    }

}

int main() {

    system("chcp 65001");

    startMenu();

    return 0;
}