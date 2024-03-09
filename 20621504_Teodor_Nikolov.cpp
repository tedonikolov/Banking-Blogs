#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <windows.h>
using namespace std;

struct deposit
{
    string currency;
    unsigned int amount;
};

struct person
{
    string card_number;
    string name;
    struct deposit dp[3];
    string day;
    string month;
    string year;
    unsigned int counts;
};

int menu();
void add_depositor(person p[],int& i);
void print_all(person p[],int i);
void print_BGN(person p[],int i);
void print_EURO(person p[],int i);
void print_depositor(person p[],int i);
void add_deposit(person p[],int i);
void withdrawal_deposit(person p[],int& i);
void deposits(person p[],int h);
void references(person p[],int i);
void sort_depositors(person p[],int i);
void max_deposit(person p[],int i);
void depositors_one(person p[],int i);
void normal_file(person p[],int& i,int& FP);
void save(person p[],int i);
void fileToProgram(person p[],int& i,int& FP);
void file();
void clear_file();
void binary_file(person p[],int& i,int& FPB);
void saveb(person p[],int i);
void fileToProgramb(person p[],int& i,int& FPB);
void fileb();
void clear_fileb();

int main()
{
    person p[50];
	setlocale(LC_ALL,"Bulgarian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int i=0,FP=0,FPB=0,choice;
	do
    {   // С помощта на цикъл повтаряме менюто, докато не се въведе стойност 10(край).
		choice=menu();
		switch (choice)
		{
		case 1: add_depositor(p,i); break;
		case 2: print_depositor(p,i); break;
		case 3: add_deposit(p,i); break;
		case 4: withdrawal_deposit(p,i); break;
		case 5: references(p,i); break;
		case 6: normal_file(p,i,FP); break;
		case 7: binary_file(p,i,FPB);break;
		case 8: exit(0);
        }
	}while(choice!=8);
	return 0;
}

int menu()
{
    int choice;
    cout<<"\n\t  МЕНЮ";
    cout<<"\n 1. Добавяне на вложител";
    cout<<"\n 2. Извеждане на всички вложители";
    cout<<"\n 3. Добавяне на нов влог";
    cout<<"\n 4. Изтегляне на влог";
    cout<<"\n 5. Справки";
    cout<<"\n 6. Дейстивия с файл";
    cout<<"\n 7. Действия с двойчен файл";
    cout<<"\n 8. Край"<<endl;
    do{ // С помощта на цикъл въвеждаме нашия избор, който задължително трябва да е от 1-10
        // ако не е в този диапазон трябва потребителя да въведе нова стойност.
        cout<<"\n Въведете избор [1-8]:";
        cin>>choice;
    }while(choice<1 || choice>8);
    system("cls"); // Изчистване на буфера след въведен правелен избор.
    return choice;
}

void add_depositor(person p[],int& i)
{
    int n;
    cout<<"\n\t  МЕНЮ";
    cout<<"\n 1. Добавяне на един вложител";
    cout<<"\n 2. Добавяне на много вложители";
    do{ // С помощта на цикъл въвеждаме нашия избор, който задължително трябва да е от 1-2
        // ако не е в този диапазон трябва потребителя да въведе нова стойност.
        cout<<"\n Въведете избор [1-2]:";
        cin>>n;
    }while(n<1 || n>2);
    system("cls"); // Изчистване на буфера след въведен правелен избор.

    if (n==1)
    { // Когато изберем първата опция системата запаметява 1 вложител.
        while(n==1)
        {   // С помоща на while цикъл е изпълнено първото допълнение за бонус точки.
            // След като се въведе 1 вложител се пита дали потрибителя желае да въведе нов вложител.
            system("cls");
            cout<<"\tВъведете вложител:"<<endl;
            cout<<" Номер: ";
            cin>>p[i].card_number;
            cout<<" Три имена: ";
            cin.ignore();
            getline(cin,p[i].name);
            int k=0;
            do{ // С помощта на цикъл въвеждаме валутата, която задължително трябва да е BGN/USD/EURO.
                // ако сме въвели грешно трябва потребителя да въведе нова валута.
                cout<<" Изберете влог(BGN (лева), USD (долара),EURO (евро)): ";
                cin>>p[i].dp[0].currency;
                if(p[i].dp[0].currency=="BGN" || p[i].dp[0].currency=="USD" || p[i].dp[0].currency=="EURO")
                    k=1;
                else
                    cout<< " Имате грешка!"<<endl;
            }while(k!=1);
            cout<<" Сума: ";
            cin>>p[i].dp[0].amount;
            cout<<" Въведете дата на откриване на влога.(ден/месец/година) ";
            char delimeter('/');
            cin.ignore();
            getline(cin, p[i].day, delimeter);
            getline(cin, p[i].month, delimeter);
            getline(cin, p[i].year);
            p[i].counts=1;
            i++;
            // Менюто което пита за добавяне на нов вложител.
            cout<<"\n\t  Желаете ли да въведете друг вложител?";
            cout<<"\n 1. Да";
            cout<<"\n 2. Не";
            do{ // С помощта на цикъл въвеждаме нашия избор, който задължително трябва да е от 1-2
                // ако не е в този диапазон трябва потребителя да въведе нова стойност.
                cout<<"\n Въведете избор [1-2]:";
                cin>>n;
            }while(n<1 || n>2);
            system("cls");
        }
    }
    else
    {
        cout<<" Въведете броя на хората: ";
        cin>>n;
        int x=1;
        while (x<=n)
        {
            system("cls");
            cout<<"\tВъведете вложител №"<<x<<":"<<endl;
            cout<<" Номер: ";
            cin>>p[i].card_number;
            cout<<" Три имена: ";
            cin.ignore();
            getline(cin,p[i].name);
            int k=0;
            do{ // С помощта на цикъл въвеждаме валутата, която задължително трябва да е BGN/USD/EURO.
                // ако сме въвели грешно трябва потребителя да въведе нова валута.
                cout<<" Изберете влог(BGN (лева), USD (долара),EURO (евро)): ";
                cin>>p[i].dp[0].currency;
                if(p[i].dp[0].currency=="BGN" || p[i].dp[0].currency=="USD" || p[i].dp[0].currency=="EURO")
                    k=1;
                else
                    cout<< " Имате грешка!"<<endl;
            }while(k!=1);
            cout<<" Сума: ";
            cin>>p[i].dp[0].amount;
            cout<<" Въведете дата на откриване на влога.(ден/месец/година) ";
            char delimeter('/');
            cin.ignore();
            getline(cin, p[i].day, delimeter);
            getline(cin, p[i].month, delimeter);
            getline(cin, p[i].year);
            p[i].counts=1;
            x++;
            i++;
            system("cls");
        }
    }
}

void print_depositor(person p[],int i)
{
    int n;
    cout<<"\n Извеждане на:";
    cout<<"\n 1. Всички вложители;";
    cout<<"\n 2. На вложители с влог BGN;";
    cout<<"\n 3. На вложители с максимален влог EURO.";
    do{ // С помощта на цикъл въвеждаме нашия избор, който задължително трябва да е от 1-3
        // ако не е в този диапазон трябва потребителя да въведе нова стойност.
        cout<<"\n Въведете избор [1-3]:";
        cin>>n;
    }while(n<1 || n>3);
    system("cls");
    if(i!=0)
    {
        switch(n)
        {
            case 1: print_all(p,i); break;
            case 2: print_BGN(p,i); break;
            case 3: print_EURO(p,i);
        }
    }
    else
    {
        cout<<"\n Имате грешка, в системата няма въведени вложители."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
}

void print_all(person p[],int i)  // Подфункция за функция print_depositor().
{
    int br=0;
    cout<<"\n\tВсички вложители:"<<endl;
    cout<<setfill('*')<<setw(50)<<"*";
    for (int n=0; n<i; n++)
    { // Цикъл, който върти елементите на масива.
        int x=0;
        cout<<"\n Номер: ";
        cout<<p[n].card_number<<endl;
        cout<<" Три имена: ";
        cout<<p[n].name<<endl;
        cout<<" Брой влогове: "<<p[n].counts<<endl<<endl;
        while(x<p[n].counts)
        {// Цикъл, който върти елементите на подмасива.
            cout<<" Влог №"<<x+1<<": ";
            cout<<p[n].dp[x].currency<<endl;
            cout<<" Сума: ";
            cout<<p[n].dp[x].amount<<endl;
            br++;
            x++;
        }
        cout<<setfill('*')<<setw(50)<<"*";
    }
    if (br==0)
    {
        cout<<"\n Няма такива."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
}

void print_BGN(person p[],int i)  // Подфункция за функция print_depositor().
{
    int br=0;
    cout<<"\n\tВложители с влог BGN:"<<endl;
    cout<<setfill('*')<<setw(50)<<"*";
    for (int n=0; n<i; n++)
    {// Цикъл, който върти елементите на масива.
        int x=0;
        while(x<3)
        {// Цикъл, който върти елементите на подмасива.
            if(p[n].dp[x].currency=="BGN")
            {// Изкарват се хората с влог BGN.
                cout<<"\n Номер: ";
                cout<<p[n].card_number<<endl;
                cout<<" Три имена: ";
                cout<<p[n].name<<endl;
                cout<<" Сума: ";
                cout<<p[n].dp[x].amount<<endl;
                br++;
                cout<<setfill('*')<<setw(50)<<"*";
            }
            x++;
        }
    }
    if (br==0)
    {
        cout<<"\n Няма такива."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }

}

void print_EURO(person p[],int i)  // Подфункция за функция print_depositor().
{
    struct depositor
        { // Структура която запазва номера на карта, името, влога с максимална сума.
            string card_number;
            string name;
            string currency;
            unsigned int amount=0;
        }m[50];
    cout<<"\n\tВложители с максимален влог EURO:"<<endl;
    cout<<setfill('*')<<setw(50)<<"*";
    int br=0;
    for (int n=0; n<i; n++)
    {// Цикъл, който върти елементите на масива.
        m[n].card_number=p[n].card_number;
        m[n].name=p[n].name;
    }
    for (int n=0; n<i; n++)
    {// Цикъл, който върти елементите на масива.
        int x=0;
        while(x<3)
        {// Цикъл, който върти елементите на подмасива.
            if(p[n].dp[x].amount>m[n].amount)
            {
                m[n].amount=p[n].dp[x].amount;
                m[n].currency=p[n].dp[x].currency;
            }
            x++;
        }
    }
    for (int n=0; n<i; n++)
    {// Цикъл, който върти елементите на масива.
        int x=0;
        if(m[n].currency=="EURO")
        {// Изкарват се хората с влог EURO.
            cout<<"\n Номер: ";
            cout<<m[n].card_number<<endl;
            cout<<" Три имена: ";
            cout<<m[n].name<<endl;
            cout<<" Сума: ";
            cout<<m[n].amount<<endl;
            br++;
            cout<<setfill('*')<<setw(50)<<"*";
        }
    }
    if (br==0)
    {
        cout<<"\n Няма такива."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
}

void add_amount(person p[],int pos,int x)  // Подфункция за функция add_deposit().
{
    cout<<" Въведете сума от минимална стойност 500: ";
    cin>>p[pos].dp[x].amount;
    while (p[pos].dp[x].amount<500)
    { // Проверка за правилно въведена сума.
        cout<<" Трябва по-голяма сума: ";
        cin>>p[pos].dp[x].amount;
    }
    p[pos].counts=x+1; // Броя на влоговете се вдига с 1.
}

void add_deposit(person p[],int i)
{
    string number;
    int pos=-1,n;
    if(i==0)
    {
        system("cls");
        cout<<"\n Имате грешка, в системата няма въведени вложители."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
    else
    {
        cout<<"\tДобавяне на нов влог"<<endl;
        cout<<" Въведете номер на сметка: ";
        cin>>number;
        while(pos==-1)
        {
            for(int n=0; n<i; n++)
            {// Цикъл, който върти елементите на масива.
                if(p[n].card_number==number)
                {// Намиране на номера в системата.
                    pos=n;
                    break;
                }
            }
            if(pos!=-1)
                break;
            cout<<"\n Не съществува такъв номер в системата!";
            cout<<"\n\t  Желаете ли да въведете друг номер?";
            cout<<"\n 1. Да";
            cout<<"\n 2. Не";
            do{ // С помощта на цикъл въвеждаме нашия избор, който задължително трябва да е от 1-2
                // ако не е в този диапазон трябва потребителя да въведе нова стойност.
                cout<<"\n Въведете избор [1-2]:";
                cin>>n;
            }while(n<1 || n>2);
            if(n==1)
            {
                cout<<" Въведете номер на ново: ";
                cin>>number;
            }
            else
            {
                system("cls");
                break;
            }
            system("cls");
        }
        if(pos!=-1) // Ако е намерен.
        {
            if(p[pos].counts==1) // Ако има 1 влог.
            {
                if(p[pos].dp[0].currency=="BGN") // Ако е в BGN.
                {
                    int k=0;
                    do{ // Проверка за правилно въведена валута.
                        cout<<" Изберете влог(USD (долара), EURO (евро)): ";
                        cin>>p[pos].dp[1].currency;
                        if(p[pos].dp[1].currency=="USD" || p[pos].dp[1].currency=="EURO")
                            k=1;
                        else
                            cout<< " Имате грешка!"<<endl;
                    }while(k!=1);
                    add_amount(p,pos,1); // Изпълняване на подфункция.
                }
                else if(p[pos].dp[0].currency=="EURO") // Ако е в EURO.
                {
                    int k=0;
                    do{ // Проверка за правилно въведена валута.
                        cout<<" Изберете влог(BGN (лева), USD (долара)): ";
                        cin>>p[pos].dp[1].currency;
                        if(p[pos].dp[1].currency=="BGN" || p[pos].dp[1].currency=="USD")
                            k=1;
                        else
                            cout<< " Имате грешка!"<<endl;
                    }while(k!=1);
                    add_amount(p,pos,1); // Изпълняване на подфункция.
                }
                else  // Ако е в USD.
                {
                    int k=0;
                    do{ // Проверка за правилно въведена валута.
                        cout<<" Изберете влог(BGN (лева), EURO (евро)): ";
                        cin>>p[pos].dp[1].currency;
                        if(p[pos].dp[1].currency=="BGN" || p[pos].dp[1].currency=="EURO")
                            k=1;
                        else
                            cout<< " Имате грешка!"<<endl;
                    }while(k!=1);
                    add_amount(p,pos,1); // Изпълняване на подфункция.
                }
                system("cls");
            }
            else if(p[pos].counts==2) // Ако има 2 съществуващи влога.
            {
                if((p[pos].dp[0].currency=="BGN"&&p[pos].dp[1].currency=="EURO") || (p[pos].dp[1].currency=="BGN"&&p[pos].dp[0].currency=="EURO")) // Ако е в BGN и EURO.
                {
                    cout<<" Можете да имате само още един влог във валута USD (долара): "<<endl;
                    string s;
                    int k=0;
                    do{  // Проверка за правилно въведен избор.
                        cout<<" Желаете ли да ви бъде открит? (да/не) ";
                        cin>>s;
                        if(s=="да")
                        {
                            k=1;
                            p[pos].dp[2].currency="USD";
                            add_amount(p,pos,2); // Изпълняване на подфункция.
                        }
                        else if(s=="не")
                            break;
                        else
                            cout<< " Имате грешка!"<<endl;
                    }while(k!=1);
                }
                if((p[pos].dp[0].currency=="BGN"&&p[pos].dp[1].currency=="USD") || (p[pos].dp[1].currency=="BGN"&&p[pos].dp[0].currency=="USD")) // Ако е в BGN и USD.
                {
                    cout<<" Можете да имате само още един влог във валута EURO (долара): "<<endl;
                    string s;
                    int k=0;
                    do{ // Проверка за правилно въведен избор.
                        cout<<" Желаете ли да ви бъде открит? (да/не) ";
                        cin>>s;
                        if(s=="да")
                        {
                            k=1;
                            p[pos].dp[2].currency="EURO";
                            add_amount(p,pos,2); // Изпълняване на подфункция.
                        }
                        else if(s=="не")
                            break;
                        else
                            cout<< " Имате грешка!"<<endl;
                    }while(k!=1);
                }
                if((p[pos].dp[0].currency=="EURO"&&p[pos].dp[1].currency=="USD") || (p[pos].dp[1].currency=="EURO"&&p[pos].dp[0].currency=="USD")) // Ако е в USD и EURO.
                {
                    cout<<" Можете да имате само още един влог във валута BGN (долара): "<<endl;
                    string s;
                    int k=0;
                    do{ // Проверка за правилно въведен избор.
                        cout<<" Желаете ли да ви бъде открит? (да/не) ";
                        cin>>s;
                        if(s=="да")
                        {
                            k=1;
                            p[pos].dp[2].currency="BGN";
                            add_amount(p,pos,2); // Изпълняване на подфункция.
                        }
                        else if(s=="не")
                            break;
                        else
                            cout<< " Имате грешка!"<<endl;
                    }while(k!=1);
                }
                system("cls");
            }
            else // Ако има 3 създадени влога.
            {
                cout<<"\n";
                cout<<setfill('*')<<setw(50)<<"*";
                cout<<"\n Не могът да бъдат открити нови влогове, тъй като максималния брой е достигнат!"<<endl;
                cout<<setfill('*')<<setw(50)<<"*";
            }
        }
    }
}

void deposits(person p[],int h)  // Подфункция за функция withdrawal_deposit().
{
    int money;
    if(p[h].counts==1) // Ако има 1 влог.
    {
        cout<<" Вие имате 1 влог на стойност "<<p[h].dp[0].amount<<" в "<<p[h].dp[0].currency<<endl;
        if(p[h].dp[0].amount==0) // Ако няма пари в сметката.
        {
                system("cls");
                cout<<"\n Вашия влог е празен! Не можете да теглите пари!"<<endl;
                cout<<setfill('*')<<setw(50)<<"*";
        }
        else // Ако не е.
        {
            cout<<" Въведете желаната сума на теглене: ";
            cin>>money;
            while (money>p[h].dp[0].amount)
            { // Ако въведената сума е по-голяма от текущата.
                cout<<" Нямате толкова пари в сметката:"<<endl;
                string s;
                int k=0;
                do{ // Проверка дали желае да въведе нова сума.
                    cout<<" Желаете ли да въведете нова сума? (да/не) ";
                    cin>>s;
                    if(s=="да")
                    {
                        k=1;
                        cout<<" Въведете нова сума за теглене: ";
                        cin>>money;
                    }
                    else if(s=="не")
                    {
                        money=0;
                        break;
                    }
                    else
                        cout<< " Имате грешка!"<<endl;
                }while(k!=1);
            }
            if(money<=p[h].dp[0].amount)
            {
                p[h].dp[0].amount=p[h].dp[0].amount-money;
            }
            system("cls");
        }
    }
    else if(p[h].counts==2) // Ако има 2 влог.
    {
        cout<<" Вие имате 2 влога на стойност "<<p[h].dp[0].amount<<" в "<<p[h].dp[0].currency<<" и "<<p[h].dp[1].amount<<" в "<<p[h].dp[1].currency<<endl;
        int y;
        do{
            cout<<"\n Изберете влог от който искате да теглите (1/2): ";
            cin>>y;
        }while(y<1 || y>2);
        if (y==1) // Ако тегли от влог 1.
        {
            if(p[h].dp[0].amount==0) // Ако няма пари в сметката.
            {
                system("cls");
                cout<<"\n Вашия влог е празен! Не можете да теглите пари!"<<endl;
                cout<<setfill('*')<<setw(50)<<"*";
            }
            else // Ако не е.
            {
                cout<<" Въведете желаната сума на теглене: ";
                cin>>money;
                while (money>p[h].dp[0].amount)
                { // Ако въведената сума е по-голяма от текущата.
                    cout<<" Нямате толкова пари в сметката:"<<endl;
                    string s;
                    int k=0;
                    do{ // Проверка дали желае да въведе нова сума.
                        cout<<" Желаете ли да въведете нова сума? (да/не) ";
                        cin>>s;
                        if(s=="да")
                        {
                            k=1;
                            cout<<" Въведете нова сума за теглене: ";
                            cin>>money;
                        }
                        else if(s=="не")
                        {
                            money=0;
                            break;
                        }
                        else
                            cout<< " Имате грешка!"<<endl;
                    }while(k!=1);
                }
                if(money<=p[h].dp[0].amount)
                {
                    p[h].dp[0].amount=p[h].dp[0].amount-money;
                }
                system("cls");
            }
        }
        else // Ако тегли от влог 2.
        {
            if(p[h].dp[1].amount==0) // Ако няма пари в сметката.
            {
                system("cls");
                cout<<"\n Вашия влог е празен! Не можете да теглите пари!"<<endl;
                cout<<setfill('*')<<setw(50)<<"*";
            }
            else // Ако не е.
            {
                cout<<" Въведете желаната сума на теглене: ";
                cin>>money;
                while (money>p[h].dp[1].amount)
                { // Ако въведената сума е по-голяма от текущата.
                    cout<<" Нямате толкова пари в сметката:"<<endl;
                    string s;
                    int k=0;
                    do{ // Проверка дали желае да въведе нова сума.
                        cout<<" Желаете ли да въведете нова сума? (да/не) ";
                        cin>>s;
                        if(s=="да")
                        {
                            k=1;
                            cout<<" Въведете нова сума за теглене: ";
                            cin>>money;
                        }
                        else if(s=="не")
                        {
                            money=0;
                            break;
                        }
                        else
                            cout<< " Имате грешка!"<<endl;
                    }while(k!=1);
                }
                if(money<=p[h].dp[1].amount)
                {
                    p[h].dp[1].amount=p[h].dp[1].amount-money;
                }
                system("cls");
            }
        }
    }
    else // Ако има 3 влог.
    {
        cout<<" Вие имате 3 влога на стойност "<<p[h].dp[0].amount<<" в "<<p[h].dp[0].currency<<", "<<p[h].dp[1].amount<<" в "<<p[h].dp[1].currency <<" и "<<p[h].dp[2].amount<<" в "<<p[h].dp[2].currency<<endl;
        int y;
        do{
            cout<<"\n Изберете влог от който искате да теглите (1/2/3): ";
            cin>>y;
        }while(y<1 || y>3);
        if (y==1) // Ако тегли от влог 1.
        {
            if(p[h].dp[0].amount==0) // Ако няма пари в сметката.
            {
                system("cls");
                cout<<"\n Вашия влог е празен! Не можете да теглите пари!"<<endl;
                cout<<setfill('*')<<setw(50)<<"*";
            }
            else // Ако не е.
            {
                cout<<" Въведете желаната сума на теглене: ";
                cin>>money;
                while (money>p[h].dp[0].amount)
                { // Ако въведената сума е по-голяма от текущата.
                    cout<<" Нямате толкова пари в сметката:"<<endl;
                    string s;
                    int k=0;
                    do{ // Проверка дали желае да въведе нова сума.
                        cout<<" Желаете ли да въведете нова сума? (да/не) ";
                        cin>>s;
                        if(s=="да")
                        {
                            k=1;
                            cout<<" Въведете нова сума за теглене: ";
                            cin>>money;
                        }
                        else if(s=="не")
                        {
                            money=0;
                            break;
                        }
                        else
                            cout<< " Имате грешка!"<<endl;
                    }while(k!=1);
                }
                if(money<=p[h].dp[0].amount)
                {
                    p[h].dp[0].amount=p[h].dp[0].amount-money;
                }
                system("cls");
            }
        }
        else if (y==2) // Ако тегли от влог 2.
        {
            if(p[h].dp[1].amount==0) // Ако няма пари в сметката.
            {
                system("cls");
                cout<<"\n Вашия влог е празен! Не можете да теглите пари!"<<endl;
                cout<<setfill('*')<<setw(50)<<"*";
            }
            else // Ако не е.
            {
                cout<<" Въведете желаната сума на теглене: ";
                cin>>money;
                while (money>p[h].dp[1].amount)
                { // Ако въведената сума е по-голяма от текущата.
                    cout<<" Нямате толкова пари в сметката:"<<endl;
                    string s;
                    int k=0;
                    do{ // Проверка дали желае да въведе нова сума.
                        cout<<" Желаете ли да въведете нова сума? (да/не) ";
                        cin>>s;
                        if(s=="да")
                        {
                            k=1;
                            cout<<" Въведете нова сума за теглене: ";
                            cin>>money;
                        }
                        else if(s=="не")
                        {
                            money=0;
                            break;
                        }
                        else
                            cout<< " Имате грешка!"<<endl;
                    }while(k!=1);
                }
                if(money<=p[h].dp[1].amount)
                {
                    p[h].dp[1].amount=p[h].dp[1].amount-money;
                }
                system("cls");
            }
        }
        else // Ако тегли от влог 3.
        {
            if(p[h].dp[2].amount==0) // Ако няма пари в сметката.
            {
                system("cls");
                cout<<"\n Вашия влог е празен! Не можете да теглите пари!"<<endl;
                cout<<setfill('*')<<setw(50)<<"*";
            }
            else // Ако не е.
            {
                cout<<" Въведете желаната сума на теглене: ";
                cin>>money;
                while (money>p[h].dp[2].amount)
                { // Ако въведената сума е по-голяма от текущата.
                    cout<<" Нямате толкова пари в сметката:"<<endl;
                    string s;
                    int k=0;
                    do{ // Проверка дали желае да въведе нова сума.
                        cout<<" Желаете ли да въведете нова сума? (да/не) ";
                        cin>>s;
                        if(s=="да")
                        {
                            k=1;
                            cout<<" Въведете нова сума за теглене: ";
                            cin>>money;
                        }
                        else if(s=="не")
                        {
                            money=0;
                            break;
                        }
                        else
                            cout<< " Имате грешка!"<<endl;
                    }while(k!=1);
                }
                if(money<=p[h].dp[2].amount)
                {
                    p[h].dp[2].amount=p[h].dp[2].amount-money;
                }
                system("cls");
            }
        }
    }
}

void withdrawal_deposit(person p[],int& i)
{
    string number;
	int n, money;
    cout<<"\n\t  МЕНЮ";
    cout<<"\n 1. Теглене на сума от влог";
    cout<<"\n 2. Прекратяване на профила";
    do{ // С помощта на цикъл въвеждаме нашия избор, който задължително трябва да е от 1-2
        // ако не е в този диапазон трябва потребителя да въведе нова стойност.
        cout<<"\n Въведете избор [1-2]:";
        cin>>n;
    }while(n<1 || n>2);
    system("cls");
    int br=0;
    if(i==0)
    {
        cout<<"\n Имате грешка, в системата няма въведени вложители."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
    else if (n==1) // Ако сме избрали опция 1.
    {
        cout<<" Въведете номера на вложителя: ";
        cin>>number;
        while(br==0)
        {// Цикъл, който върти елементите на масива.
            for (int x=0; x<i; x++)
            {
                if(p[x].card_number==number)
                { // Намиране на номера в системата.
                    cout<<endl;
                    deposits(p,x); // Изпълнявване на подфункция.
                    br++;
                }
            }
            if (br==0) // Ако не е намерен в системата.
            {
                cout<<"\n Не съществува такъв номер в системата!";
                cout<<"\n\t  Желаете ли да въведете друг номер?";
                cout<<"\n 1. Да";
                cout<<"\n 2. Не";
                do{ // С помощта на цикъл въвеждаме нашия избор, който задължително трябва да е от 1-2
                    // ако не е в този диапазон трябва потребителя да въведе нова стойност.
                    cout<<"\n Въведете избор [1-2]:";
                    cin>>n;
                }while(n<1 || n>2);
                if(n==1)
                {
                    cout<<" Въведете номер на ново: ";
                    cin>>number;
                }
                else
                {
                    br=1;
                    system("cls");
                }
            }
        }
    }
    else // Ако сме избрали опция 2.
    {
        cout<<" Въведете номера на вложителя: ";
        cin>>number;
        cout<<endl;
        while(br==0)
        {
            for (int x=0; x<i; x++)
            {// Цикъл, който върти елементите на масива.
                if(p[x].card_number==number)
                { // Намиране на номера в системата.
                    int suma=0;
                    for(int l=0;l<p[x].counts;l++)
                    { // Извличане на сумата, която притижава в лева.
                        if(p[x].dp[l].currency=="EURO")
                            suma=suma+p[x].dp[l].amount*1.96;
                        else if(p[x].dp[l].currency=="USD")
                            suma=suma+p[x].dp[l].amount*1.61;
                        else
                            suma+=p[x].dp[l].amount;
                    }
                    i=i-1;
                    for(int k=x; k<i; k++)
                    {
                        p[k]=p[k+1];
                    }
                    br++;
                    cout<<"\n Профилът беше закрит успешно!"<<endl;
                    cout<<" Сумата, която извлечена е "<<suma<<" лева."<<endl;
                    cout<<setfill('*')<<setw(50)<<"*";
                    break;
                }
                system("cls");
            }
            if (br==0)// Ако не е намерен в системата.
            {
                cout<<"\n Не съществува такъв номер в системата!";
                cout<<"\n\t  Желаете ли да въведете друг номер?";
                cout<<"\n 1. Да";
                cout<<"\n 2. Не";
                do{ // С помощта на цикъл въвеждаме нашия избор, който задължително трябва да е от 1-2
                    // ако не е в този диапазон трябва потребителя да въведе нова стойност.
                    cout<<"\n Въведете избор [1-2]:";
                    cin>>n;
                }while(n<1 || n>2);
                if(n==1)
                {
                    cout<<" Въведете номер на ново: ";
                    cin>>number;
                }
                else
                {
                    br=1;
                    system("cls");
                }
            }
        }
    }
}

void references(person p[],int i)
{
    int n;
    cout<<"\n\t  МЕНЮ";
    cout<<"\n 1. Извеждане на вложителите в подреден ред";
    cout<<"\n 2. Извеждане на вложителя с най-голям влог от въведена валута";
    cout<<"\n 3. Извеждане на вложителите, които имат само един влог";
    do{// С помощта на цикъл въвеждаме нашия избор, който задължително трябва да е от 1-3
        // ако не е в този диапазон трябва потребителя да въведе нова стойност.
        cout<<"\n Въведете избор [1-3]:";
        cin>>n;
    }while(n<1 || n>3);
    system("cls");
    if (i==0)
    { // Ако в системата няма въведени записи.
        cout<<"\n Имате грешка, в системата няма въведени вложители."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
    else
    {
        switch (n)
        {
            case 1: sort_depositors(p,i); break; // Използване на подфункция.
            case 2: max_deposit(p,i); break; // Използване на подфункция.
            case 3: depositors_one(p,i); // Използване на подфункция.
        }
    }
}

void sort_depositors(person p[],int i) // Подфункция за функция references().
{
    int br=0;
    int n;
    cout<<"\n Извеждане на вложителите в подреден ред по:";
    cout<<"\n 1. Датата на основаване на влоговете;";
    cout<<"\n 2. Общата стойност на влоговете.";
    do{ // С помощта на цикъл въвеждаме нашия избор, който задължително трябва да е от 1-2
        // ако не е в този диапазон трябва потребителя да въведе нова стойност.
        cout<<"\n Въведете избор [1-2]:";
        cin>>n;
    }while(n<1 || n>2);
    system("cls");

    if (n==1) // Ако сме избрали избор 1.
    {
        struct depositor
        { // Структура която запазва номера на карта, името, и датата на създаване.
            string card_number;
            string name;
            string day;
            string month;
            string year;
        }d[50],d2[50]; // Създаване на два масива от по типа на структурата.

        for (int n=0; n<i; n++)
        { // Чрез цикъл се запазва нужната информация от главния масив.
            d[n].card_number=p[n].card_number;
            d[n].name=p[n].name;
            d[n].day=p[n].day;
            d[n].month=p[n].month;
            d[n].year=p[n].year;
        }
        // Чрез метода на мехурчето, вложителите се подреждът, спрямо датата.
        for (int n=i; n>1; n--)
        { // Цикъл който се върти от края на елемните докато стане 1.
            for(int j=0;j<n-1;j++)
            { // Цикъл който се върти от началото на елемните до елемнта от горния цикъл.
                // Превръщане на стринга в число.
                stringstream a(d[j].year);
                int aa;
                a>>aa;
                stringstream b(d[j+1].year);
                int bb;
                b>>bb;
                if(aa<bb) // Сравняване на годините.
                {
                    d2[j]=d[j];
                    d[j]=d[j+1];
                    d[j+1]=d2[j];
                }
                else if(aa==bb) // Сравняване на годините.
                {// Превръщане на стринга в число.
                    stringstream c(d[j].month);
                    int cc;
                    c>>cc;
                    stringstream l(d[j+1].month);
                    int ll;
                    l>>ll;
                    if(cc<ll) // Сравняване на месеците.
                    {
                        d2[j]=d[j];
                        d[j]=d[j+1];
                        d[j+1]=d2[j];
                    }
                    else if(cc==ll) // Сравняване на месеците.
                    {// Превръщане на стринга в число.
                        stringstream m(d[j].day);
                        int mm;
                        m>>mm;
                        stringstream v(d[j+1].day);
                        int vv;
                        v>>vv;
                        if(mm<vv) // Сравняване на дните.
                        {
                            d2[j]=d[j];
                            d[j]=d[j+1];
                            d[j+1]=d2[j];
                        }
                    } // strlen(str), strcpy(string,string), strcat(str,str),strcmp(str,str)
                }// char ime[]="Teodor";
            }// cout<<hex<<13;
        }
        cout<<"\n Извеждане на вложителите подред по датата на основаване на влоговете."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
        for (int n=0; n<i; n++)
        { // Извеждане на подредения масив.
            cout<<endl;
            cout<<" Номер: "<<d[n].card_number<<endl;
            cout<<" Име: "<<d[n].name<<endl;
            cout<<" Дата на основаване: "<<d[n].day<<"/"<<d[n].month<<"/"<<d[n].year<<endl;
            cout<<setfill('*')<<setw(50)<<"*";
        }
    }
    else // Ако сме избрали избор 2.
    {
        struct depositor
        { // Структура която запазва номера на карта, името, и общата сума.
            string card_number;
            string name;
            unsigned int amount;
        }d[50],d2[50]; // Създаване на два масива от по типа на структурата.

        for (int n=0; n<i; n++)
        { // Чрез цикъл се запазва нужната информация от главния цикъл.
            int sum=0;
            int x=p[n].counts;
            for(int y=0; y<x; y++)
            {
                if(p[n].dp[y].currency=="EURO")
                    sum=sum+p[n].dp[y].amount*1.96;
                else if(p[n].dp[y].currency=="USD")
                    sum=sum+p[n].dp[y].amount*1.61;
                else
                    sum+=p[n].dp[y].amount;
            }
            d[n].card_number=p[n].card_number;
            d[n].name=p[n].name;
            d[n].amount=sum;
        }

        for (int n=i; n>1; n--)
        { // Цикъл който се върти от края на елемните докато стане 1.
            for(int j=0;j<n-1;j++)
            { // Цикъл който се върти от началото на елемните до елемнта от горния цикъл.
                if(d[j].amount<d[j+1].amount) // Сравняване на сумите.
                {
                    d2[j]=d[j];
                    d[j]=d[j+1];
                    d[j+1]=d2[j];
                }
            }
        }
        cout<<"\n Извеждане на вложителите подред по общата стойност на влоговете."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
        for (int n=0; n<i; n++)
        { // Извеждане на подредения масив.
            cout<<"\n\t №"<<n+1<<endl;
            cout<<" Номер: "<<d[n].card_number<<endl;
            cout<<" Име: "<<d[n].name<<endl;
            cout<<" Сума: "<<d[n].amount<<"лв."<<endl;
            cout<<setfill('*')<<setw(50)<<"*";
        }
    }
}

void max_deposit(person p[],int i) // Подфункция за функция references().
{
    string s,name,number;
    int k, maxa=0,br=0;
    do{ // Провека за правилно въведена валута.
        cout<<"\n Изберете валута(BGN (лева), USD (долара),EURO (евро)): ";
        cin>>s;
        if(s=="BGN" || s=="USD" || s=="EURO")
            k=1;
        else
            cout<< " Имате грешка!"<<endl;
    }while(k!=1);
    system("cls");
    for (int n=0; n<i; n++)
    { // Въртене на масива.
        for (int x=0; x<3; x++)
        { // Въртене на подмасаива.
            if(p[n].dp[x].currency==s)
            {
                if (p[n].dp[x].amount>maxa)  // Сравняване на сумата.
                {
                    maxa=p[n].dp[x].amount;
                    number=p[n].card_number;
                    name=p[n].name;
                }
                br++;
            }
        }
    }
    if (br==0) // Ако няма хора с подобни влогове.
        cout<<"\n Няма вложители с влог "<<s<<"."<<endl;
    else // Ако има изкаравав човека с няй-голям.
        cout<<"\n Вложителя, който има най-голяма сума на стойност "<<maxa<<" в "<<s<<" е "<<name<<" с номер на картата "<<number<<"."<<endl;
    cout<<setfill('*')<<setw(50)<<"*";
}

void depositors_one(person p[],int i) // Подфункция за функция references().
{
    int br=0;
    cout<<"\n\t Вложителите, които имат само един влог:"<<endl;
    cout<<setfill('*')<<setw(50)<<"*";
    for (int n=0; n<i; n++)
    { // Въртене на масива.
        if(p[n].counts==1)
        { // Изкарване на хората с един влог.
            cout<<"\n Номер: "<<p[n].card_number<<endl;
            cout<<" Три имена: "<<p[n].name<<endl;
            cout<<" Влог: "<<p[n].dp[0].currency<<endl;
            cout<<" Сума: "<<p[n].dp[0].amount<<endl;
            cout<<setfill('*')<<setw(50)<<"*";
            br++;
        }
    }
    if (br==0) // Ако няма такива хора.
    {
        cout<<"\n Няма такива вложители."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
}

void normal_file(person p[],int& i,int& FP)
{
    int n;
    cout<<"\n\t  МЕНЮ";
    cout<<"\n 1. Запазване на въведените данни във файл";
    cout<<"\n 2. Прехвърляне на данните от файла в програмата";
    cout<<"\n 3. Извеждане на данните от файла";
    cout<<"\n 4. Изчистване на запазените данни във файла";
    do{ // С помощта на цикъл въвеждаме нашия избор, който задължително трябва да е от 1-2
        // ако не е в този диапазон трябва потребителя да въведе нова стойност.
        cout<<"\n Въведете избор [1-4]:";
        cin>>n;
    }while(n<1 || n>4);
    system("cls");

    switch(n)
    {
        case 1: save(p,i); break;
        case 2: fileToProgram(p,i,FP); break;
        case 3: file(); break;
        case 4: clear_file(); break;
    }
}

void save(person p[],int i)
{
    if(i!=0)
    {
        cout<<"\n\tФайлът беше записън успешно!"<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
        fstream f;
        // Предварително отваряне на файла, с цел да се изтрият предишните данни.
        f.open("Depositors.txt", ios::out | ios::trunc);
        f.close();
        // Отваряне на файла.
        f.open("Depositors.txt",ios::out);
        f<<i<<endl;
        for (int n=0; n<i; n++)
        {
            int x=0;
            f<<p[n].card_number<<endl;
            f<<p[n].name<<endl;
            f<<p[n].day<<endl;
            f<<p[n].month<<endl;
            f<<p[n].year<<endl;
            f<<p[n].counts<<endl;
            while(x<p[n].counts)
            {
                f<<p[n].dp[x].currency<<endl;
                f<<p[n].dp[x].amount<<endl;
                x++;
            }
        }
        // Затваряне на файла.
        f.close();
    }
    else
    {
        cout<<"\n Имате грешка, в системата няма въведени вложители."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
}

void fileToProgram(person p[],int& i,int& FP)
{
    fstream f;
    f.open("Depositors.txt", ios::in);
    // Проверка дали файлът вече и бил прехвърлен.
    if(FP==1)
    {
        cout<<"\n\tФайлът вече беше прехвърлен."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
    // Проверка дали файлът е празен.
    else if ( f.peek() == EOF)
    {
        cout<<"\n\tФайлът е празен!"<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
    else
    {
        cout<<"\n Данните от файла бяха прехвърлени успешно!"<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
        int j;
        f>>j;
        int n=i+j;
        for(i; i<n; i++)
        {
            f>>p[i].card_number;
            f.ignore();
            getline(f, p[i].name);
            f>>p[i].day;
            f>>p[i].month;
            f>>p[i].year;
            f>>p[i].counts;
            int x=0;
            while (x<p[i].counts)
            {
                f>>p[i].dp[x].currency;
                f>>p[i].dp[x].amount;
                x++;
            }
        }
        FP++;
    }
    f.close();
}

void file()
{
    fstream f;
    f.open("Depositors.txt", ios::in);
    string a,b,c;
    int j;
    j=0;
    // Проверка дали файлът е празен.
    if ( f.peek() == EOF)
    {
        cout<<"\n\tФайлът е празен!"<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
    else
    {
        cout<<"\n\tДанните от Файла"<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
        f>>j;
        for(int n=0; n<j; n++)
        {
            f>>a;
            cout<<"\n Номер: "<<a<<endl;
            f.ignore();
            getline(f, a);
            cout<<" Три имена: "<<a<<endl;
            f>>a;
            f>>b;
            f>>c;
            cout<<" Дата на откриване: "<<a<<"/"<<b<<"/"<<c<<endl;
            int y;
            f>>y;
            cout<<" Брой влогове: "<<y<<endl<<endl;
            int x=0;
            while (x<y)
            {
                f>>a;
                cout<<" Влог №"<<x+1<<": "<<a<<endl;
                f>>a;
                cout<<" Сума: "<<a<<endl;
                x++;
            }
            cout<<setfill('*')<<setw(50)<<"*";
        }
    }
    f.close();
}

void clear_file()
{
    cout<<"\n\tФайлът беше изчистен успешно!"<<endl;
    cout<<setfill('*')<<setw(50)<<"*";
    fstream f;
    f.open("Depositors.txt", ios::out | ios::trunc);
    f.close();
}

void binary_file(person p[],int& i,int& FPB)
{
    int n;
    cout<<"\n\t  МЕНЮ";
    cout<<"\n 1. Запазване на въведените данни във файл";
    cout<<"\n 2. Прехвърляне на данните от файла в програмата";
    cout<<"\n 3. Извеждане на данните от файла";
    cout<<"\n 4. Изчистване на запазените данни във файла";
    do{ // С помощта на цикъл въвеждаме нашия избор, който задължително трябва да е от 1-2
        // ако не е в този диапазон трябва потребителя да въведе нова стойност.
        cout<<"\n Въведете избор [1-4]:";
        cin>>n;
    }while(n<1 || n>4);
    system("cls");

    switch(n)
    {
        case 1: saveb(p,i); break;
        case 2: fileToProgramb(p,i,FPB); break;
        case 3: fileb(); break;
        case 4: clear_fileb(); break;
    }
}

void saveb(person p[],int i)
{
    int razmer;
    if(i!=0)
    {
        cout<<"\n\tФайлът беше записън успешно!"<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
        fstream f;
        // Предварително отваряне на файла, с цел да се изтрият предишните данни.
        f.open("Depos.dat", ios::out | ios::trunc);
        f.close();
        // Отваряне на файла.
        f.open("Depos.dat",ios::binary | ios::out);
        f.write((char*)&i,sizeof(int));
        for (int n=0; n<i; n++)
        {
            int x=0;
            int razmer = p[n].card_number.length()+1;
            char ch[razmer];
            strcpy(ch,p[n].card_number.c_str());
            f.write((char*)&razmer,sizeof(int));
            f.write(ch,razmer);
            razmer = p[n].name.length()+1;
            ch[razmer];
            strcpy(ch,p[n].name.c_str());
            f.write((char*)&razmer,sizeof(int));
            f.write(ch,razmer);
            razmer = p[n].day.length()+1;
            ch[razmer];
            strcpy(ch,p[n].day.c_str());
            f.write((char*)&razmer,sizeof(int));
            f.write(ch,razmer);
            razmer = p[n].month.length()+1;
            ch[razmer];
            strcpy(ch,p[n].month.c_str());
            f.write((char*)&razmer,sizeof(int));
            f.write(ch,razmer);
            razmer = p[n].year.length()+1;
            ch[razmer];
            strcpy(ch,p[n].year.c_str());
            f.write((char*)&razmer,sizeof(int));
            f.write(ch,razmer);
            f.write((char*)&p[n].counts,sizeof(int));
            while(x<p[n].counts)
            {
                razmer = p[n].dp[x].currency.length()+1;
                ch[razmer];
                strcpy(ch,p[n].dp[x].currency.c_str());
                f.write((char*)&razmer,sizeof(int));
                f.write(ch,razmer);
                f.write((char*)&p[n].dp[x].amount,sizeof(int));
                x++;
            }
        }
        // Затваряне на файла.
        f.close();
    }
    else
    {
        cout<<"\n Имате грешка, в системата няма въведени вложители."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
}

void fileToProgramb(person p[],int& i,int& FPB)
{
    fstream f;
    f.open("Depos.dat", ios::binary | ios::in);
    // Проверка дали файлът вече и бил прехвърлен.
    if(FPB==1)
    {
        cout<<"\n\tФайлът вече беше прехвърлен."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
    // Проверка дали файлът е празен.
    else if ( f.peek() == EOF)
    {
        cout<<"\n\tФайлът е празен!"<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
    else
    {
        cout<<"\n Данните от файла бяха прехвърлени успешно!"<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
        int j;
        f.read((char*)&j, sizeof(int));
        int n=i+j;
        for(i; i<n; i++)
        {
            int razmer;
            f.read((char*)&razmer, sizeof(int));
            char nomer[razmer];
            f.read(nomer, razmer);
            p[i].card_number=nomer;
            f.read((char*)&razmer, sizeof(int));
            char name[razmer];
            f.read(name, razmer);
            p[i].name=name;
            f.read((char*)&razmer, sizeof(int));
            char day[razmer];
            f.read(day, razmer);
            p[i].day=day;
            f.read((char*)&razmer, sizeof(int));
            char month[razmer];
            f.read(month, razmer);
            p[i].month=month;
            f.read((char*)&razmer, sizeof(int));
            char year[razmer];
            f.read(year, razmer);
            p[i].year=year;
            int counts;
            f.read((char*)&counts, sizeof(int));
            p[i].counts=counts;
            int x=0;
            while (x<p[i].counts)
            {
                f.read((char*)&razmer, sizeof(int));
                char currency[razmer];
                f.read(currency, razmer);
                p[i].dp[x].currency=currency;
                int amount;
                f.read((char*)&amount, sizeof(int));
                p[i].dp[x].amount=amount;
                x++;
            }
        }
        FPB++;
    }
    f.close();
}

void fileb()
{
    fstream f;
    f.open("Depos.dat", ios::binary | ios::in);
    int j;
    // Проверка дали файлът е празен.
    if ( f.peek() == EOF)
    {
        cout<<"\n\tФайлът е празен!"<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
    else
    {
        cout<<"\n\tДанните от Файла"<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
        f.read((char*)&j, sizeof(int));
        for(int n=0; n<j; n++)
        {
            int razmer;
            f.read((char*)&razmer, sizeof(int));
            char nomer[razmer];
            f.read(nomer, razmer);
            cout<<"\n Номер: "<<nomer<<endl;
            f.read((char*)&razmer, sizeof(int));
            char name[razmer];
            f.read(name, razmer);
            cout<<" Три имена: "<<name<<endl;
            f.read((char*)&razmer, sizeof(int));
            char day[razmer];
            f.read(day, razmer);
            f.read((char*)&razmer, sizeof(int));
            char month[razmer];
            f.read(month, razmer);
            f.read((char*)&razmer, sizeof(int));
            char year[razmer];
            f.read(year, razmer);
            cout<<" Дата на откриване: "<<day<<"/"<<month<<"/"<<year<<endl;
            int counts;
            f.read((char*)&counts, sizeof(int));
            cout<<" Брой влогове: "<<counts<<endl<<endl;
            int x=0;
            while (x<counts)
            {
                f.read((char*)&razmer, sizeof(int));
                char currency[razmer];
                f.read(currency, razmer);
                cout<<" Влог №"<<x+1<<": "<<currency<<endl;
                int amount;
                f.read((char*)&amount, sizeof(int));
                cout<<" Сума: "<<amount<<endl;
                x++;
            }
            cout<<setfill('*')<<setw(50)<<"*";
        }
    }
    f.close();
}

void clear_fileb()
{
    cout<<"\n\tФайлът беше изчистен успешно!"<<endl;
    cout<<setfill('*')<<setw(50)<<"*";
    fstream f;
    f.open("Depos.dat", ios::binary | ios::out | ios::trunc);
    f.close();
}

