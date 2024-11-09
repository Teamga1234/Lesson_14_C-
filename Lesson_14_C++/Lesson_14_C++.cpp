#include "ArrayTemplate.h"
#include "Date.h"
#include "Violation.h"
#include "Driver.h"
int findDriverByCarNumber(Driver* arr, int size, const char* car)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].carNumber, car) == 0) {
            return i;
        }
    }
    return -1;
}
int main()
{
    /*
     Violation a = { {8, 5, 2024}, "Speed 180 km/h", 25'000 };
     Violation b;

     b.fillViolation();
     cout << "-------------------------------------------\n\n";

     a.showViolation();
     b.showViolation();*/

     /*
      Driver a = { "Pupkin Vasyliy Petrovych", "AX6766BA", 2, new Violation[2]{
          {{1, 1, 2024}, "Speed 180 km/h", 25'000},
          {{8, 5, 2024}, "Parking", 350}
      } };

      Driver b;
      b.fillDriver();
      cout << "---------------------------------------\n\n";

      a.showDriver();
      b.showDriver();
      */


    int sizeDrivers = 3;
    Driver* arrD = new Driver[3]{
        { "Pupkin Vasyliy Petrovych", "AX6766BA", 2, new Violation[2]{
            {{1, 1, 2024}, "Speed 180 km/h", 25'000},
            {{8, 5, 2024}, "Parking", 350}
        } },
        {"Ivanko Sergiy Stepanovych", "AX6666AX", 0, nullptr},
        {"Rits Semen Ihorovych", "AX5432KH", 1, new Violation[1]{
            {{1, 2, 2024}, "Sign", 1200}
        }}
    };

    int menu = 0;
    char str[100] = "";
    int index = -1;

    do
    {
        cout << "\n++++++++++++++++++++++++++++++++++++++\n";
        cout << "|                MENU                |\n";
        cout << "++++++++++++++++++++++++++++++++++++++\n";
        cout << "| 0 - Exit                           |\n";
        cout << "| 1 - Add driver                     |\n";
        cout << "| 2 - Show all drivers               |\n";
        cout << "| 3 - Show all violations            |\n";
        cout << "| 4 - Find driver by car number      |\n";
        cout << "| 5 - Add Violation by car number    |\n";
        cout << "++++++++++++++++++++++++++++++++++++++\n";
        cin >> menu;

        switch (menu)
        {
        case 1: {
            Driver a;
            cout << "\t NEW DRIVER:\n";
            cin.ignore();
            a.fillDriver();
            addItemBack(arrD, sizeDrivers, a);
        }
              break;
        case 2:
            for (int i = 0; i < sizeDrivers; i++)
            {
                cout << "#" << i + 1 << ". \t" << arrD[i].name << endl;
                cout << "\t" << arrD[i].carNumber << endl;
            }
            break;
        case 3:
            for (int i = 0; i < sizeDrivers; i++)
            {
                cout << arrD[i].carNumber << endl;
                for (int j = 0; j < arrD[i].sizeViol; j++)
                {
                    arrD[i].arrViol[j].showViolation();
                }
            } break;
        case 4:
            cout << "Input car number: ";
            cin >> str;

            index = findDriverByCarNumber(arrD, sizeDrivers, str);
            
            if (index == -1) cout << "Not found " << str << endl;
            else {
                arrD[index].showDriver();
            }

            break;
        case 5:
            cout << "Input car number: ";
            cin >> str;
            index = findDriverByCarNumber(arrD, sizeDrivers, str);
            if (index == -1) cout << "Not found " << str << endl;
            else {
                Violation a;
                a.fillViolation();
                addItemBack(arrD[index].arrViol, arrD[index].sizeViol, a);
            }
            break;
        default: cout << "Error!!\n";   break;
        }

    } while (menu != 0);

}