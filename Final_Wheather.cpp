//This program is created by 22AIML054,22AIML025,22AIML040
#include <conio.h>
#include <bits/stdc++.h>
#include <unistd.h>
#include <windows.h>
#include <string.h>
using namespace std;
map<string, int> mp = {
    {"Jan", 01}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6}, {"Jul", 07}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}};
class date
{
private:
    int date1, month, year;

public:
    void setdate(string str)
    {
        stringstream ss(str);
        char ch;
        ss >> setfill('0') >> setw(2) >> date1 >> ch >> setfill('0') >> setw(2) >> month >> ch >> year;
    }
    void printdate()
    {
        cout << setfill('0') << setw(2) << right << date1 << '/' << setfill('0') << setw(2) << right << month << '/' << year;
    }
    string getdate()
    {
        stringstream ss;
        ss << setfill('0') << setw(2) << date1 << '/' << setfill('0') << setw(2) << month << '/' << year;
        return ss.str();
    }
};
class Temperature : public date
{
private:
    float hightemp, lowtemp, humidity, windspeed;
    string type;

public:
    string place;
    void setdata(float high, float low, float hum, float wind, string typ, string plc)
    {
        hightemp = high;
        lowtemp = low;
        humidity = hum;
        windspeed = wind;
        type = typ;
        place = plc;
    }
    void dayprintdata()
    {
        system("cls");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "-------------------------------------------------\n";
        cout << "|     ";
        SetConsoleTextAttribute(hConsole, 14);
        cout << "-:-BUG SLAYERS Whether forecasting-:-";
        SetConsoleTextAttribute(hConsole, 15);
        cout << "     |\n";
        cout << "|\t\t\t\t\t\t|\n";
        cout << "|  ";
        printdate();
        cout <<setfill(' ')<< setw(34) << place << " |\n";
        cout << "|\t\t       ";
        SetConsoleTextAttribute(hConsole, 14);
        cout << (hightemp + lowtemp) / 2 << "*C";
        SetConsoleTextAttribute(hConsole, 15);
        cout << "      \t\t|\n";
        cout << "|\t\t\t\t\t\t|\n";
        if (type.size() % 2 != 0)
        {
            cout << setfill(' ') << setw((50 - type.size()) / 2) << left << "|";
            SetConsoleTextAttribute(hConsole, 244);
            cout << type;
            SetConsoleTextAttribute(hConsole, 15);
            cout << setfill(' ') << setw((((50 - type.size()) / 2)) + 1) << right << "|\n";
        }
        else
        {
            cout << setfill(' ') << setw((50 - type.size()) / 2) << left << "|";
            SetConsoleTextAttribute(hConsole, 244);
            cout << type;
            SetConsoleTextAttribute(hConsole, 15);
            cout << setfill(' ') << setw((50 - type.size()) / 2) << right << "|\n";
        }

        cout << "|\t\t\t\t\t\t|\n";
        cout << "|\t        ";
        cout << "H: ";
        SetConsoleTextAttribute(hConsole, 12);
        cout << hightemp << "*C    ";
        SetConsoleTextAttribute(hConsole, 15);
        cout << "L: ";
        SetConsoleTextAttribute(hConsole, 11);
        cout << lowtemp << "*C";
        SetConsoleTextAttribute(hConsole, 15);
        cout << "\t\t|" << endl;
        cout << "|\t\t\t\t\t\t|\n";
        cout << "|\t\t\t\t\t\t|\n";
        cout << "|\t          ";
        cout << "Wind: ";
        SetConsoleTextAttribute(hConsole, 2);
        cout << windspeed << "km/hr";
        SetConsoleTextAttribute(hConsole, 15);
        cout << "\t\t\t|" << endl;
        cout << "|\t          ";
        cout << "Humidity: ";
        SetConsoleTextAttribute(hConsole, 2);
        cout << humidity << "%";
        SetConsoleTextAttribute(hConsole, 15);
        cout << "\t\t\t|" << endl;
        cout << "|\t\t\t\t\t\t|\n";
        cout << "-------------------------------------------------\n\n";
        SetConsoleTextAttribute(hConsole, 23);
        cout << "[<]";
        SetConsoleTextAttribute(hConsole, 15);
        cout << " Previous day    ";
        SetConsoleTextAttribute(hConsole, 23);
        cout << "[>]";
        SetConsoleTextAttribute(hConsole, 15);
        cout << " Next day    ";
        SetConsoleTextAttribute(hConsole, 23);
        cout << "[x]";
        SetConsoleTextAttribute(hConsole, 15);
        cout << " Main menu \n";
    }
    void weekprintdata()
    {
        int count = 16 - place.size();
        cout << "|: ";
        printdate();
        cout << setw((count / 2) + 2) << setfill(' ') << left << " :";
        cout << place;
        if (place.size() % 2 == 0)
        {
            cout << setw((count / 2)) << setfill(' ') << right << ":";
        }
        else
        {
            cout << setw((count / 2) + 1) << setfill(' ') << right << ":";
        }

        cout << "  " << hightemp << "*C  :  " << lowtemp << "*C :    " << humidity << "%   :    " << windspeed << "kph   :|\n";
    }
};
int filecnt()
{
    FILE *ptr;
    ptr = fopen("temperature.txt", "r");
    int i = 0;
    char c;
    while (c != EOF)
    {
        c = fgetc(ptr);
        if (c == '\n')
        {
            i++;
        }
    }
    fclose(ptr);
    return i;
}
void boundcheck(int cnt, string plc, Temperature t[])
{
    vector<string> v1;
    string str1;
    for (int i = 0; i < cnt; i++)
    {
        if (t[i].place == plc)
        {
            string str = t[i].getdate();
            const char *c = str.data();
            v1.push_back(c);
        }
    }
    cout << "\n\nData Available from:  " << v1[0] << " to "
         << *(v1.end() - 1);
}
void particularwhether(int ct, Temperature t[], string plc)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "------------------------------------------------\n";
    cout << "     ";
    SetConsoleTextAttribute(hConsole, 14);
    cout << "-:-BUG SLAYERS Whether forecasting-:-";
    boundcheck(ct, plc, t);
    SetConsoleTextAttribute(hConsole, 15);
    cout << "     \n"
         << " \t\t\t\t\t\t \n"
         << "  ";
    SetConsoleTextAttribute(hConsole, 12);
    cout << "Enter date (dd/mm/yyyy) : ";
    SetConsoleTextAttribute(hConsole, 15);
    string str;
    cin >> str;
    int flag1 = 1;
    for (int i = 0; i < ct; i++)
    {
        if ((t[i].getdate() == str) && t[i].place == plc)
        {
            flag1 = 0;
            t[i].dayprintdata();
        }
    }
    if (flag1)
    {
        system("cls");
        cout << "No data found : " << str << endl
             << endl;
        SetConsoleTextAttribute(hConsole, 23);
        cout << "[x]";
        SetConsoleTextAttribute(hConsole, 15);
        cout << " Main menu \n";
    }
    char a;
    for (int i = 1; i; i++)
    {
        a = getch();
        if (a == 75)
        {
            char tp;
            int tempdt, tempmon, tempyear;
            stringstream ss(str), string_updt;
            ss >> setfill('0') >> setw(2) >> tempdt >> tp >> tempmon >> tp >> tempyear;
            if ((tempdt == 1) && (tempmon <= 7 && tempmon > 1) && (tempmon % 2 != 0) || (tempdt == 1) && (tempmon >= 7) && (tempmon % 2 == 0))
            {
                string_updt << setfill('0') << setw(2) << 30 << '/' << setfill('0') << setw(2) << (tempmon - 1) << '/' << tempyear;
                str = string_updt.str();
            }
            else if ((tempdt == 1) && (tempmon <= 7 && tempmon > 1) && (tempmon % 2 == 0) || (tempdt == 1) && (tempmon >= 7) && (tempmon % 2 != 0))
            {
                string_updt << setfill('0') << setw(2) << 31 << '/' << setfill('0') << setw(2) << (tempmon - 1) << '/' << tempyear;
                str = string_updt.str();
            }
            else if (tempdt == 1 && tempmon == 1)
            {
                string_updt << setfill('0') << setw(2) << 31 << '/' << setfill('0') << setw(2) << 12 << '/' << tempyear - 1;
                str = string_updt.str();
            }
            else
            {
                string_updt << setfill('0') << setw(2) << (tempdt - 1) << '/' << setfill('0') << setw(2) << tempmon << '/' << tempyear;
                str = string_updt.str();
            }
            int flag = 1;
            for (int j = 0; j < ct; j++)
            {
                if ((t[j].getdate() == str) && t[j].place == plc)
                {
                    flag = 0;
                    t[j].dayprintdata();
                }
            }
            if (flag)
            {
                system("cls");
                cout << "No data found : " << str << endl
                     << endl;
                SetConsoleTextAttribute(hConsole, 23);
                cout << "[<]";
                SetConsoleTextAttribute(hConsole, 15);
                cout << " Previous day    ";
                SetConsoleTextAttribute(hConsole, 23);
                cout << "[>]";
                SetConsoleTextAttribute(hConsole, 15);
                cout << " Next day    ";
                SetConsoleTextAttribute(hConsole, 23);
                cout << "[x]";
                SetConsoleTextAttribute(hConsole, 15);
                cout << " Main menu \n";
            }
        }
        else if (a == 77)
        {
            char tp;
            int tempdt, tempmon, tempyear;
            stringstream ss(str), string_updt;
            ss >> setfill('0') >> setw(2) >> tempdt >> tp >> tempmon >> tp >> tempyear;
            if (tempdt == 31 && tempmon < 12)
            {
                string_updt << setfill('0') << setw(2) << 1 << '/' << setfill('0') << setw(2) << (tempmon + 1) << '/' << tempyear;
                str = string_updt.str();
            }
            else if ((tempdt == 30 && tempmon <= 7 && tempmon % 2 == 0) || (tempdt == 30 && (tempmon >= 7 && tempmon < 12) && tempmon % 2 != 0))
            {
                string_updt << setfill('0') << setw(2) << 1 << '/' << setfill('0') << setw(2) << (tempmon + 1) << '/' << tempyear;
                str = string_updt.str();
            }
            else if (tempdt == 31 && tempmon == 12)
            {
                string_updt << setfill('0') << setw(2) << 1 << '/' << setfill('0') << setw(2) << 1 << '/' << tempyear + 1;
                str = string_updt.str();
            }
            else
            {
                string_updt << setfill('0') << setw(2) << (tempdt + 1) << '/' << setfill('0') << setw(2) << tempmon << '/' << tempyear;
                str = string_updt.str();
            }
            int flag = 1;
            for (int j = 0; j < ct; j++)
            {
                if ((t[j].getdate() == str) && t[j].place == plc)
                {
                    flag = 0;
                    t[j].dayprintdata();
                }
            }
            if (flag)
            {
                system("cls");
                cout << "No data found : " << str << endl
                     << endl;
                SetConsoleTextAttribute(hConsole, 23);
                cout << "[<]";
                SetConsoleTextAttribute(hConsole, 15);
                cout << " Previous day    ";
                SetConsoleTextAttribute(hConsole, 23);
                cout << "[>]";
                SetConsoleTextAttribute(hConsole, 15);
                cout << " Next day    ";
                SetConsoleTextAttribute(hConsole, 23);
                cout << "[x]";
                SetConsoleTextAttribute(hConsole, 15);
                cout << " Main menu \n";
            }
        }
        else if (a == 'x' || a == 'X')
        {
            system("cls");
            return;
        }
    }
}
void week_whether(int n, Temperature t[], string plc)
{

    int today_date, today_year;
    string tempstrdt, mon;
    time_t now = time(0);
    char *dt = ctime(&now);
    stringstream st(dt), st1;
    string str, string_updt;
    st >> tempstrdt >> mon >> today_date >> tempstrdt >> today_year;
    st1 << setfill('0') << setw(2) << today_date << '/' << setfill('0') << setw(2) << mp[mon] << '/' << today_year;
    str = st1.str();
    cout << "------------------------------------------------------------------------\n";
    cout << "|\t            ";
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);
    cout << "-:-BUG SLAYERS Whether forecasting-:-";
    SetConsoleTextAttribute(hConsole, 15);
    cout << "\t       |\n";
    cout << "|\t\t\t\t\t\t\t\t       |\n";
    cout << "|:    Date    :     Place     :  High  :  Low  : Humidity : Windspeed :|\n";
    cout << "|:------------:---------------:--------:-------:----------:-----------:|\n";
    for (int i = 0; i < 7; i++)
    {
        stringstream string_updt;
        for (int j = 0; j < n; j++)
        {

            if ((t[j].getdate() == str) && t[j].place == plc)
            {
                t[j].weekprintdata();
                char tp;
                int tempdt, tempmon, tempyear;
                stringstream ss(str);
                ss >> tempdt >> tp >> tempmon >> tp >> tempyear;
                string_updt << setfill('0') << setw(2) << (tempdt - 1) << '/' << setfill('0') << setw(2) << tempmon << '/' << tempyear;
            }
        }
        str = string_updt.str();
    }
    cout << "------------------------------------------------------------------------\n";
    system("pause");
    system("cls");
}
void menu1()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "-------------------------------------------------------------\n";
    cout << "|\t     ";
    SetConsoleTextAttribute(hConsole, 14);
    cout << "-:-BUG SLAYERS Whether forecasting-:-";
    SetConsoleTextAttribute(hConsole, 15);
    cout << "\t    |\n";
    cout << "|\t\t\t\t\t\t\t    |\n";
    cout << "|\t     ";
    SetConsoleTextAttribute(hConsole, 23);
    cout << "[1]";
    SetConsoleTextAttribute(hConsole, 15);
    cout << " for viewing Whether                        |\n";
    cout << "|\t     ";
    SetConsoleTextAttribute(hConsole, 23);
    cout << "[2]";
    SetConsoleTextAttribute(hConsole, 15);
    cout << " for Adding Whether data(Admin only)        |\n";
    cout << "|\t     ";
    SetConsoleTextAttribute(hConsole, 23);
    cout << "[3]";
    SetConsoleTextAttribute(hConsole, 15);
    cout << " for Exit\t\t\t\t    |\n";
    cout << "-------------------------------------------------------------\n";
}
void menu2()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "-------------------------------------------------\n";
    cout << "|\t";
    SetConsoleTextAttribute(hConsole, 14);
    cout << "-:-BUG SLAYERS Whether forecasting-:-";
    SetConsoleTextAttribute(hConsole, 15);
    cout << "\t|\n";
    cout << "|\t\t\t\t\t\t|\n";
    cout << "|\t     ";
    cout << "\t  Which city?\t\t\t|\n";
    cout << "|\t\t\t\t\t\t|\n";
    vector<string> arr = {"changa", "Anand", "Ahmedabad", "Surat", "Vadodara"};
    for (int i = 0; i < 5; i++)
    {
        cout << "|\t       ";
        SetConsoleTextAttribute(hConsole, 23);
        cout << "[" << i + 1 << "]";
        SetConsoleTextAttribute(hConsole, 15);
        cout << " for ";
        cout << setfill(' ') << setw(25) << left << arr[i];
        cout << "|" << endl;
    }
    cout << "|\t       ";
    SetConsoleTextAttribute(hConsole, 23);
    cout << "[6]";
    SetConsoleTextAttribute(hConsole, 15);
    cout << " for going back\t\t|\n";
    cout << "-------------------------------------------------\n";
}
void menu3()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "-------------------------------------------------------------------\n";
    cout << "|\t\t";
    SetConsoleTextAttribute(hConsole, 14);
    cout << "-:-BUG SLAYERS Whether forecasting-:-";
    SetConsoleTextAttribute(hConsole, 15);
    cout << "\t\t  |\n";
    cout << "|\t\t\t\t\t\t\t\t  |\n";
    cout << "|\t     ";
    SetConsoleTextAttribute(hConsole, 23);
    cout << "[1]";
    SetConsoleTextAttribute(hConsole, 15);
    cout << " for viewing Whether of any particular Date\t  |\n";
    cout << "|\t     ";
    SetConsoleTextAttribute(hConsole, 23);
    cout << "[2]";
    SetConsoleTextAttribute(hConsole, 15);
    cout << " for viewing Whether of this Week\t\t  |\n";
    cout << "|\t     ";
    SetConsoleTextAttribute(hConsole, 23);
    cout << "[3]";
    SetConsoleTextAttribute(hConsole, 15);
    cout << " for for going Back\t\t\t\t  |\n";
    cout << "-------------------------------------------------------------------\n";
}
int main()
{
lablemain:
    int cnt;
    cnt = filecnt();
    Temperature t[cnt];
    ifstream ftr("temperature.txt");
    for (int i = 0; i < cnt; i++)
    {
        string dt, plc, typ, tmp;
        float low, high, hum, wind;
        ftr >> dt >> plc >> tmp >> tmp >> low >> tmp >> tmp >> high >> tmp >> tmp >> hum >> tmp >> tmp >> wind >> tmp >> tmp >> typ;
        t[i].setdata(high, low, hum, wind, typ, plc);
        t[i].setdate(dt);
    }
    ftr.close();
    for (int i = 1; i; i++)
    {
    label:
        menu1();
        char ch = getch();
        system("cls");
        if (ch == '1')
        {
        label2:
            menu2();
            char ch1 = getch();
            system("cls");
            if (ch1 == '1')
            {
                menu3();
                char ch2 = getch();
                system("cls");
                if (ch2 == '1')
                {
                    particularwhether(cnt, t, "Changa");
                }
                else if (ch2 == '2')
                {
                    week_whether(cnt, t, "Changa");
                }
                else if (ch2 == '3')
                    goto label2;
            }
            else if (ch1 == '2')
            {
                menu3();
                char ch2 = getch();
                system("cls");
                if (ch2 == '1')
                {
                    particularwhether(cnt, t, "Anand");
                }
                else if (ch2 == '2')
                {
                    week_whether(cnt, t, "Anand");
                }
                else if (ch2 == '3')
                    goto label2;
            }
            else if (ch1 == '3')
            {
                menu3();
                char ch2 = getch();
                system("cls");
                if (ch2 == '1')
                {
                    particularwhether(cnt, t, "Ahmedabad");
                }
                else if (ch2 == '2')
                {
                    week_whether(cnt, t, "Ahmedabad");
                }
                else if (ch2 == '3')
                    goto label2;
            }
            else if (ch1 == '4')
            {
                menu3();
                char ch2 = getch();
                system("cls");
                if (ch2 == '1')
                {
                    particularwhether(cnt, t, "Surat");
                }
                else if (ch2 == '2')
                {
                    week_whether(cnt, t, "Surat");
                }
                else if (ch2 == '3')
                    goto label2;
            }
            else if (ch1 == '5')
            {
                menu3();
                char ch2 = getch();
                system("cls");
                if (ch2 == '1')
                {
                    particularwhether(cnt, t, "Vadodara");
                }
                else if (ch2 == '2')
                {
                    week_whether(cnt, t, "Vadodara");
                }
                else if (ch2 == '3')
                    goto label2;
            }
        }
        else if (ch == '2')
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            cout << "------------------------------------------------\n";
            cout << "     ";
            SetConsoleTextAttribute(hConsole, 14);
            cout << "-:-BUG SLAYERS Whether forecasting-:-";
            SetConsoleTextAttribute(hConsole, 15);
            cout << "     \n"
                 << " \t\t\t\t\t\t \n"
                 << "  ";
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Enter Password : ";
            SetConsoleTextAttribute(hConsole, 15);
            string pass = "pass123", temppass;
            getline(cin, temppass);
            if (temppass == pass)
            {
                system("cls");
                string tmpdt, tmpplc, tmptyp;
                float tmplow, tmphigh, tmphum, tmpwind;
                cout << "  Enter the date(dd/mm/yyyy): ";
                cin >> tmpdt;
                cout << "  Enter place(Changa, Anand, Ahmedabad, Surat, Vadodara) : ";
                cin >> tmpplc;
                cout << "  Enter type of wheather: ";
                cin >> tmptyp;
                cout << "  Enter low temperature: ";
                cin >> tmplow;
                cout << "  Enter High temperature: ";
                cin >> tmphigh;
                cout << "  Enter Humidity percentage : ";
                cin >> tmphum;
                cout << "  Enter wind speed: ";
                cin >> tmpwind;
                ofstream fobj("temperature.txt", ios::app);
                fobj << tmpdt << " " << tmpplc << " low = " << tmplow << " high = " << tmphigh << " hum = " << tmphum << " wind = " << tmpwind << " type = " << tmptyp << "\n";
                system("cls");
                cout << "Data added successfully....";
                sleep(2);
                system("cls");
                goto lablemain;
            }
            else
            {
                system("cls");
                cout << "Wrong Password!!!";
                sleep(1);
                system("cls");
                goto lablemain;
            }
        }
        else if (ch == '3')
        {
            cout << "Byee\n\n";
            system("Pause");
            break;
        }
    }

    return 0;
}
