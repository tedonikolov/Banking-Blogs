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
    {   // � ������� �� ����� ��������� ������, ������ �� �� ������ �������� 10(����).
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
    cout<<"\n\t  ����";
    cout<<"\n 1. �������� �� ��������";
    cout<<"\n 2. ��������� �� ������ ���������";
    cout<<"\n 3. �������� �� ��� ����";
    cout<<"\n 4. ��������� �� ����";
    cout<<"\n 5. �������";
    cout<<"\n 6. ��������� � ����";
    cout<<"\n 7. �������� � ������� ����";
    cout<<"\n 8. ����"<<endl;
    do{ // � ������� �� ����� ��������� ����� �����, ����� ������������ ������ �� � �� 1-10
        // ��� �� � � ���� �������� ������ ����������� �� ������ ���� ��������.
        cout<<"\n �������� ����� [1-8]:";
        cin>>choice;
    }while(choice<1 || choice>8);
    system("cls"); // ���������� �� ������ ���� ������� �������� �����.
    return choice;
}

void add_depositor(person p[],int& i)
{
    int n;
    cout<<"\n\t  ����";
    cout<<"\n 1. �������� �� ���� ��������";
    cout<<"\n 2. �������� �� ����� ���������";
    do{ // � ������� �� ����� ��������� ����� �����, ����� ������������ ������ �� � �� 1-2
        // ��� �� � � ���� �������� ������ ����������� �� ������ ���� ��������.
        cout<<"\n �������� ����� [1-2]:";
        cin>>n;
    }while(n<1 || n>2);
    system("cls"); // ���������� �� ������ ���� ������� �������� �����.

    if (n==1)
    { // ������ ������� ������� ����� ��������� ���������� 1 ��������.
        while(n==1)
        {   // � ������ �� while ����� � ��������� ������� ���������� �� ����� �����.
            // ���� ���� �� ������ 1 �������� �� ���� ���� ����������� ����� �� ������ ��� ��������.
            system("cls");
            cout<<"\t�������� ��������:"<<endl;
            cout<<" �����: ";
            cin>>p[i].card_number;
            cout<<" ��� �����: ";
            cin.ignore();
            getline(cin,p[i].name);
            int k=0;
            do{ // � ������� �� ����� ��������� ��������, ����� ������������ ������ �� � BGN/USD/EURO.
                // ��� ��� ������ ������ ������ ����������� �� ������ ���� ������.
                cout<<" �������� ����(BGN (����), USD (������),EURO (����)): ";
                cin>>p[i].dp[0].currency;
                if(p[i].dp[0].currency=="BGN" || p[i].dp[0].currency=="USD" || p[i].dp[0].currency=="EURO")
                    k=1;
                else
                    cout<< " ����� ������!"<<endl;
            }while(k!=1);
            cout<<" ����: ";
            cin>>p[i].dp[0].amount;
            cout<<" �������� ���� �� ��������� �� �����.(���/�����/������) ";
            char delimeter('/');
            cin.ignore();
            getline(cin, p[i].day, delimeter);
            getline(cin, p[i].month, delimeter);
            getline(cin, p[i].year);
            p[i].counts=1;
            i++;
            // ������ ����� ���� �� �������� �� ��� ��������.
            cout<<"\n\t  ������� �� �� �������� ���� ��������?";
            cout<<"\n 1. ��";
            cout<<"\n 2. ��";
            do{ // � ������� �� ����� ��������� ����� �����, ����� ������������ ������ �� � �� 1-2
                // ��� �� � � ���� �������� ������ ����������� �� ������ ���� ��������.
                cout<<"\n �������� ����� [1-2]:";
                cin>>n;
            }while(n<1 || n>2);
            system("cls");
        }
    }
    else
    {
        cout<<" �������� ���� �� ������: ";
        cin>>n;
        int x=1;
        while (x<=n)
        {
            system("cls");
            cout<<"\t�������� �������� �"<<x<<":"<<endl;
            cout<<" �����: ";
            cin>>p[i].card_number;
            cout<<" ��� �����: ";
            cin.ignore();
            getline(cin,p[i].name);
            int k=0;
            do{ // � ������� �� ����� ��������� ��������, ����� ������������ ������ �� � BGN/USD/EURO.
                // ��� ��� ������ ������ ������ ����������� �� ������ ���� ������.
                cout<<" �������� ����(BGN (����), USD (������),EURO (����)): ";
                cin>>p[i].dp[0].currency;
                if(p[i].dp[0].currency=="BGN" || p[i].dp[0].currency=="USD" || p[i].dp[0].currency=="EURO")
                    k=1;
                else
                    cout<< " ����� ������!"<<endl;
            }while(k!=1);
            cout<<" ����: ";
            cin>>p[i].dp[0].amount;
            cout<<" �������� ���� �� ��������� �� �����.(���/�����/������) ";
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
    cout<<"\n ��������� ��:";
    cout<<"\n 1. ������ ���������;";
    cout<<"\n 2. �� ��������� � ���� BGN;";
    cout<<"\n 3. �� ��������� � ���������� ���� EURO.";
    do{ // � ������� �� ����� ��������� ����� �����, ����� ������������ ������ �� � �� 1-3
        // ��� �� � � ���� �������� ������ ����������� �� ������ ���� ��������.
        cout<<"\n �������� ����� [1-3]:";
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
        cout<<"\n ����� ������, � ��������� ���� �������� ���������."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
}

void print_all(person p[],int i)  // ���������� �� ������� print_depositor().
{
    int br=0;
    cout<<"\n\t������ ���������:"<<endl;
    cout<<setfill('*')<<setw(50)<<"*";
    for (int n=0; n<i; n++)
    { // �����, ����� ����� ���������� �� ������.
        int x=0;
        cout<<"\n �����: ";
        cout<<p[n].card_number<<endl;
        cout<<" ��� �����: ";
        cout<<p[n].name<<endl;
        cout<<" ���� �������: "<<p[n].counts<<endl<<endl;
        while(x<p[n].counts)
        {// �����, ����� ����� ���������� �� ���������.
            cout<<" ���� �"<<x+1<<": ";
            cout<<p[n].dp[x].currency<<endl;
            cout<<" ����: ";
            cout<<p[n].dp[x].amount<<endl;
            br++;
            x++;
        }
        cout<<setfill('*')<<setw(50)<<"*";
    }
    if (br==0)
    {
        cout<<"\n ���� ������."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
}

void print_BGN(person p[],int i)  // ���������� �� ������� print_depositor().
{
    int br=0;
    cout<<"\n\t��������� � ���� BGN:"<<endl;
    cout<<setfill('*')<<setw(50)<<"*";
    for (int n=0; n<i; n++)
    {// �����, ����� ����� ���������� �� ������.
        int x=0;
        while(x<3)
        {// �����, ����� ����� ���������� �� ���������.
            if(p[n].dp[x].currency=="BGN")
            {// �������� �� ������ � ���� BGN.
                cout<<"\n �����: ";
                cout<<p[n].card_number<<endl;
                cout<<" ��� �����: ";
                cout<<p[n].name<<endl;
                cout<<" ����: ";
                cout<<p[n].dp[x].amount<<endl;
                br++;
                cout<<setfill('*')<<setw(50)<<"*";
            }
            x++;
        }
    }
    if (br==0)
    {
        cout<<"\n ���� ������."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }

}

void print_EURO(person p[],int i)  // ���������� �� ������� print_depositor().
{
    struct depositor
        { // ��������� ����� ������� ������ �� �����, �����, ����� � ���������� ����.
            string card_number;
            string name;
            string currency;
            unsigned int amount=0;
        }m[50];
    cout<<"\n\t��������� � ���������� ���� EURO:"<<endl;
    cout<<setfill('*')<<setw(50)<<"*";
    int br=0;
    for (int n=0; n<i; n++)
    {// �����, ����� ����� ���������� �� ������.
        m[n].card_number=p[n].card_number;
        m[n].name=p[n].name;
    }
    for (int n=0; n<i; n++)
    {// �����, ����� ����� ���������� �� ������.
        int x=0;
        while(x<3)
        {// �����, ����� ����� ���������� �� ���������.
            if(p[n].dp[x].amount>m[n].amount)
            {
                m[n].amount=p[n].dp[x].amount;
                m[n].currency=p[n].dp[x].currency;
            }
            x++;
        }
    }
    for (int n=0; n<i; n++)
    {// �����, ����� ����� ���������� �� ������.
        int x=0;
        if(m[n].currency=="EURO")
        {// �������� �� ������ � ���� EURO.
            cout<<"\n �����: ";
            cout<<m[n].card_number<<endl;
            cout<<" ��� �����: ";
            cout<<m[n].name<<endl;
            cout<<" ����: ";
            cout<<m[n].amount<<endl;
            br++;
            cout<<setfill('*')<<setw(50)<<"*";
        }
    }
    if (br==0)
    {
        cout<<"\n ���� ������."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
}

void add_amount(person p[],int pos,int x)  // ���������� �� ������� add_deposit().
{
    cout<<" �������� ���� �� ��������� �������� 500: ";
    cin>>p[pos].dp[x].amount;
    while (p[pos].dp[x].amount<500)
    { // �������� �� �������� �������� ����.
        cout<<" ������ ��-������ ����: ";
        cin>>p[pos].dp[x].amount;
    }
    p[pos].counts=x+1; // ���� �� ��������� �� ����� � 1.
}

void add_deposit(person p[],int i)
{
    string number;
    int pos=-1,n;
    if(i==0)
    {
        system("cls");
        cout<<"\n ����� ������, � ��������� ���� �������� ���������."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
    else
    {
        cout<<"\t�������� �� ��� ����"<<endl;
        cout<<" �������� ����� �� ������: ";
        cin>>number;
        while(pos==-1)
        {
            for(int n=0; n<i; n++)
            {// �����, ����� ����� ���������� �� ������.
                if(p[n].card_number==number)
                {// �������� �� ������ � ���������.
                    pos=n;
                    break;
                }
            }
            if(pos!=-1)
                break;
            cout<<"\n �� ���������� ����� ����� � ���������!";
            cout<<"\n\t  ������� �� �� �������� ���� �����?";
            cout<<"\n 1. ��";
            cout<<"\n 2. ��";
            do{ // � ������� �� ����� ��������� ����� �����, ����� ������������ ������ �� � �� 1-2
                // ��� �� � � ���� �������� ������ ����������� �� ������ ���� ��������.
                cout<<"\n �������� ����� [1-2]:";
                cin>>n;
            }while(n<1 || n>2);
            if(n==1)
            {
                cout<<" �������� ����� �� ����: ";
                cin>>number;
            }
            else
            {
                system("cls");
                break;
            }
            system("cls");
        }
        if(pos!=-1) // ��� � �������.
        {
            if(p[pos].counts==1) // ��� ��� 1 ����.
            {
                if(p[pos].dp[0].currency=="BGN") // ��� � � BGN.
                {
                    int k=0;
                    do{ // �������� �� �������� �������� ������.
                        cout<<" �������� ����(USD (������), EURO (����)): ";
                        cin>>p[pos].dp[1].currency;
                        if(p[pos].dp[1].currency=="USD" || p[pos].dp[1].currency=="EURO")
                            k=1;
                        else
                            cout<< " ����� ������!"<<endl;
                    }while(k!=1);
                    add_amount(p,pos,1); // ����������� �� ����������.
                }
                else if(p[pos].dp[0].currency=="EURO") // ��� � � EURO.
                {
                    int k=0;
                    do{ // �������� �� �������� �������� ������.
                        cout<<" �������� ����(BGN (����), USD (������)): ";
                        cin>>p[pos].dp[1].currency;
                        if(p[pos].dp[1].currency=="BGN" || p[pos].dp[1].currency=="USD")
                            k=1;
                        else
                            cout<< " ����� ������!"<<endl;
                    }while(k!=1);
                    add_amount(p,pos,1); // ����������� �� ����������.
                }
                else  // ��� � � USD.
                {
                    int k=0;
                    do{ // �������� �� �������� �������� ������.
                        cout<<" �������� ����(BGN (����), EURO (����)): ";
                        cin>>p[pos].dp[1].currency;
                        if(p[pos].dp[1].currency=="BGN" || p[pos].dp[1].currency=="EURO")
                            k=1;
                        else
                            cout<< " ����� ������!"<<endl;
                    }while(k!=1);
                    add_amount(p,pos,1); // ����������� �� ����������.
                }
                system("cls");
            }
            else if(p[pos].counts==2) // ��� ��� 2 ������������ �����.
            {
                if((p[pos].dp[0].currency=="BGN"&&p[pos].dp[1].currency=="EURO") || (p[pos].dp[1].currency=="BGN"&&p[pos].dp[0].currency=="EURO")) // ��� � � BGN � EURO.
                {
                    cout<<" ������ �� ����� ���� ��� ���� ���� ��� ������ USD (������): "<<endl;
                    string s;
                    int k=0;
                    do{  // �������� �� �������� ������� �����.
                        cout<<" ������� �� �� �� ���� ������? (��/��) ";
                        cin>>s;
                        if(s=="��")
                        {
                            k=1;
                            p[pos].dp[2].currency="USD";
                            add_amount(p,pos,2); // ����������� �� ����������.
                        }
                        else if(s=="��")
                            break;
                        else
                            cout<< " ����� ������!"<<endl;
                    }while(k!=1);
                }
                if((p[pos].dp[0].currency=="BGN"&&p[pos].dp[1].currency=="USD") || (p[pos].dp[1].currency=="BGN"&&p[pos].dp[0].currency=="USD")) // ��� � � BGN � USD.
                {
                    cout<<" ������ �� ����� ���� ��� ���� ���� ��� ������ EURO (������): "<<endl;
                    string s;
                    int k=0;
                    do{ // �������� �� �������� ������� �����.
                        cout<<" ������� �� �� �� ���� ������? (��/��) ";
                        cin>>s;
                        if(s=="��")
                        {
                            k=1;
                            p[pos].dp[2].currency="EURO";
                            add_amount(p,pos,2); // ����������� �� ����������.
                        }
                        else if(s=="��")
                            break;
                        else
                            cout<< " ����� ������!"<<endl;
                    }while(k!=1);
                }
                if((p[pos].dp[0].currency=="EURO"&&p[pos].dp[1].currency=="USD") || (p[pos].dp[1].currency=="EURO"&&p[pos].dp[0].currency=="USD")) // ��� � � USD � EURO.
                {
                    cout<<" ������ �� ����� ���� ��� ���� ���� ��� ������ BGN (������): "<<endl;
                    string s;
                    int k=0;
                    do{ // �������� �� �������� ������� �����.
                        cout<<" ������� �� �� �� ���� ������? (��/��) ";
                        cin>>s;
                        if(s=="��")
                        {
                            k=1;
                            p[pos].dp[2].currency="BGN";
                            add_amount(p,pos,2); // ����������� �� ����������.
                        }
                        else if(s=="��")
                            break;
                        else
                            cout<< " ����� ������!"<<endl;
                    }while(k!=1);
                }
                system("cls");
            }
            else // ��� ��� 3 ��������� �����.
            {
                cout<<"\n";
                cout<<setfill('*')<<setw(50)<<"*";
                cout<<"\n �� ����� �� ����� ������� ���� �������, ��� ���� ����������� ���� � ���������!"<<endl;
                cout<<setfill('*')<<setw(50)<<"*";
            }
        }
    }
}

void deposits(person p[],int h)  // ���������� �� ������� withdrawal_deposit().
{
    int money;
    if(p[h].counts==1) // ��� ��� 1 ����.
    {
        cout<<" ��� ����� 1 ���� �� �������� "<<p[h].dp[0].amount<<" � "<<p[h].dp[0].currency<<endl;
        if(p[h].dp[0].amount==0) // ��� ���� ���� � ��������.
        {
                system("cls");
                cout<<"\n ����� ���� � ������! �� ������ �� ������� ����!"<<endl;
                cout<<setfill('*')<<setw(50)<<"*";
        }
        else // ��� �� �.
        {
            cout<<" �������� �������� ���� �� �������: ";
            cin>>money;
            while (money>p[h].dp[0].amount)
            { // ��� ���������� ���� � ��-������ �� ��������.
                cout<<" ������ ������� ���� � ��������:"<<endl;
                string s;
                int k=0;
                do{ // �������� ���� ����� �� ������ ���� ����.
                    cout<<" ������� �� �� �������� ���� ����? (��/��) ";
                    cin>>s;
                    if(s=="��")
                    {
                        k=1;
                        cout<<" �������� ���� ���� �� �������: ";
                        cin>>money;
                    }
                    else if(s=="��")
                    {
                        money=0;
                        break;
                    }
                    else
                        cout<< " ����� ������!"<<endl;
                }while(k!=1);
            }
            if(money<=p[h].dp[0].amount)
            {
                p[h].dp[0].amount=p[h].dp[0].amount-money;
            }
            system("cls");
        }
    }
    else if(p[h].counts==2) // ��� ��� 2 ����.
    {
        cout<<" ��� ����� 2 ����� �� �������� "<<p[h].dp[0].amount<<" � "<<p[h].dp[0].currency<<" � "<<p[h].dp[1].amount<<" � "<<p[h].dp[1].currency<<endl;
        int y;
        do{
            cout<<"\n �������� ���� �� ����� ������ �� ������� (1/2): ";
            cin>>y;
        }while(y<1 || y>2);
        if (y==1) // ��� ����� �� ���� 1.
        {
            if(p[h].dp[0].amount==0) // ��� ���� ���� � ��������.
            {
                system("cls");
                cout<<"\n ����� ���� � ������! �� ������ �� ������� ����!"<<endl;
                cout<<setfill('*')<<setw(50)<<"*";
            }
            else // ��� �� �.
            {
                cout<<" �������� �������� ���� �� �������: ";
                cin>>money;
                while (money>p[h].dp[0].amount)
                { // ��� ���������� ���� � ��-������ �� ��������.
                    cout<<" ������ ������� ���� � ��������:"<<endl;
                    string s;
                    int k=0;
                    do{ // �������� ���� ����� �� ������ ���� ����.
                        cout<<" ������� �� �� �������� ���� ����? (��/��) ";
                        cin>>s;
                        if(s=="��")
                        {
                            k=1;
                            cout<<" �������� ���� ���� �� �������: ";
                            cin>>money;
                        }
                        else if(s=="��")
                        {
                            money=0;
                            break;
                        }
                        else
                            cout<< " ����� ������!"<<endl;
                    }while(k!=1);
                }
                if(money<=p[h].dp[0].amount)
                {
                    p[h].dp[0].amount=p[h].dp[0].amount-money;
                }
                system("cls");
            }
        }
        else // ��� ����� �� ���� 2.
        {
            if(p[h].dp[1].amount==0) // ��� ���� ���� � ��������.
            {
                system("cls");
                cout<<"\n ����� ���� � ������! �� ������ �� ������� ����!"<<endl;
                cout<<setfill('*')<<setw(50)<<"*";
            }
            else // ��� �� �.
            {
                cout<<" �������� �������� ���� �� �������: ";
                cin>>money;
                while (money>p[h].dp[1].amount)
                { // ��� ���������� ���� � ��-������ �� ��������.
                    cout<<" ������ ������� ���� � ��������:"<<endl;
                    string s;
                    int k=0;
                    do{ // �������� ���� ����� �� ������ ���� ����.
                        cout<<" ������� �� �� �������� ���� ����? (��/��) ";
                        cin>>s;
                        if(s=="��")
                        {
                            k=1;
                            cout<<" �������� ���� ���� �� �������: ";
                            cin>>money;
                        }
                        else if(s=="��")
                        {
                            money=0;
                            break;
                        }
                        else
                            cout<< " ����� ������!"<<endl;
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
    else // ��� ��� 3 ����.
    {
        cout<<" ��� ����� 3 ����� �� �������� "<<p[h].dp[0].amount<<" � "<<p[h].dp[0].currency<<", "<<p[h].dp[1].amount<<" � "<<p[h].dp[1].currency <<" � "<<p[h].dp[2].amount<<" � "<<p[h].dp[2].currency<<endl;
        int y;
        do{
            cout<<"\n �������� ���� �� ����� ������ �� ������� (1/2/3): ";
            cin>>y;
        }while(y<1 || y>3);
        if (y==1) // ��� ����� �� ���� 1.
        {
            if(p[h].dp[0].amount==0) // ��� ���� ���� � ��������.
            {
                system("cls");
                cout<<"\n ����� ���� � ������! �� ������ �� ������� ����!"<<endl;
                cout<<setfill('*')<<setw(50)<<"*";
            }
            else // ��� �� �.
            {
                cout<<" �������� �������� ���� �� �������: ";
                cin>>money;
                while (money>p[h].dp[0].amount)
                { // ��� ���������� ���� � ��-������ �� ��������.
                    cout<<" ������ ������� ���� � ��������:"<<endl;
                    string s;
                    int k=0;
                    do{ // �������� ���� ����� �� ������ ���� ����.
                        cout<<" ������� �� �� �������� ���� ����? (��/��) ";
                        cin>>s;
                        if(s=="��")
                        {
                            k=1;
                            cout<<" �������� ���� ���� �� �������: ";
                            cin>>money;
                        }
                        else if(s=="��")
                        {
                            money=0;
                            break;
                        }
                        else
                            cout<< " ����� ������!"<<endl;
                    }while(k!=1);
                }
                if(money<=p[h].dp[0].amount)
                {
                    p[h].dp[0].amount=p[h].dp[0].amount-money;
                }
                system("cls");
            }
        }
        else if (y==2) // ��� ����� �� ���� 2.
        {
            if(p[h].dp[1].amount==0) // ��� ���� ���� � ��������.
            {
                system("cls");
                cout<<"\n ����� ���� � ������! �� ������ �� ������� ����!"<<endl;
                cout<<setfill('*')<<setw(50)<<"*";
            }
            else // ��� �� �.
            {
                cout<<" �������� �������� ���� �� �������: ";
                cin>>money;
                while (money>p[h].dp[1].amount)
                { // ��� ���������� ���� � ��-������ �� ��������.
                    cout<<" ������ ������� ���� � ��������:"<<endl;
                    string s;
                    int k=0;
                    do{ // �������� ���� ����� �� ������ ���� ����.
                        cout<<" ������� �� �� �������� ���� ����? (��/��) ";
                        cin>>s;
                        if(s=="��")
                        {
                            k=1;
                            cout<<" �������� ���� ���� �� �������: ";
                            cin>>money;
                        }
                        else if(s=="��")
                        {
                            money=0;
                            break;
                        }
                        else
                            cout<< " ����� ������!"<<endl;
                    }while(k!=1);
                }
                if(money<=p[h].dp[1].amount)
                {
                    p[h].dp[1].amount=p[h].dp[1].amount-money;
                }
                system("cls");
            }
        }
        else // ��� ����� �� ���� 3.
        {
            if(p[h].dp[2].amount==0) // ��� ���� ���� � ��������.
            {
                system("cls");
                cout<<"\n ����� ���� � ������! �� ������ �� ������� ����!"<<endl;
                cout<<setfill('*')<<setw(50)<<"*";
            }
            else // ��� �� �.
            {
                cout<<" �������� �������� ���� �� �������: ";
                cin>>money;
                while (money>p[h].dp[2].amount)
                { // ��� ���������� ���� � ��-������ �� ��������.
                    cout<<" ������ ������� ���� � ��������:"<<endl;
                    string s;
                    int k=0;
                    do{ // �������� ���� ����� �� ������ ���� ����.
                        cout<<" ������� �� �� �������� ���� ����? (��/��) ";
                        cin>>s;
                        if(s=="��")
                        {
                            k=1;
                            cout<<" �������� ���� ���� �� �������: ";
                            cin>>money;
                        }
                        else if(s=="��")
                        {
                            money=0;
                            break;
                        }
                        else
                            cout<< " ����� ������!"<<endl;
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
    cout<<"\n\t  ����";
    cout<<"\n 1. ������� �� ���� �� ����";
    cout<<"\n 2. ������������ �� �������";
    do{ // � ������� �� ����� ��������� ����� �����, ����� ������������ ������ �� � �� 1-2
        // ��� �� � � ���� �������� ������ ����������� �� ������ ���� ��������.
        cout<<"\n �������� ����� [1-2]:";
        cin>>n;
    }while(n<1 || n>2);
    system("cls");
    int br=0;
    if(i==0)
    {
        cout<<"\n ����� ������, � ��������� ���� �������� ���������."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
    else if (n==1) // ��� ��� ������� ����� 1.
    {
        cout<<" �������� ������ �� ���������: ";
        cin>>number;
        while(br==0)
        {// �����, ����� ����� ���������� �� ������.
            for (int x=0; x<i; x++)
            {
                if(p[x].card_number==number)
                { // �������� �� ������ � ���������.
                    cout<<endl;
                    deposits(p,x); // ������������ �� ����������.
                    br++;
                }
            }
            if (br==0) // ��� �� � ������� � ���������.
            {
                cout<<"\n �� ���������� ����� ����� � ���������!";
                cout<<"\n\t  ������� �� �� �������� ���� �����?";
                cout<<"\n 1. ��";
                cout<<"\n 2. ��";
                do{ // � ������� �� ����� ��������� ����� �����, ����� ������������ ������ �� � �� 1-2
                    // ��� �� � � ���� �������� ������ ����������� �� ������ ���� ��������.
                    cout<<"\n �������� ����� [1-2]:";
                    cin>>n;
                }while(n<1 || n>2);
                if(n==1)
                {
                    cout<<" �������� ����� �� ����: ";
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
    else // ��� ��� ������� ����� 2.
    {
        cout<<" �������� ������ �� ���������: ";
        cin>>number;
        cout<<endl;
        while(br==0)
        {
            for (int x=0; x<i; x++)
            {// �����, ����� ����� ���������� �� ������.
                if(p[x].card_number==number)
                { // �������� �� ������ � ���������.
                    int suma=0;
                    for(int l=0;l<p[x].counts;l++)
                    { // ��������� �� ������, ����� ��������� � ����.
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
                    cout<<"\n �������� ���� ������ �������!"<<endl;
                    cout<<" ������, ����� ��������� � "<<suma<<" ����."<<endl;
                    cout<<setfill('*')<<setw(50)<<"*";
                    break;
                }
                system("cls");
            }
            if (br==0)// ��� �� � ������� � ���������.
            {
                cout<<"\n �� ���������� ����� ����� � ���������!";
                cout<<"\n\t  ������� �� �� �������� ���� �����?";
                cout<<"\n 1. ��";
                cout<<"\n 2. ��";
                do{ // � ������� �� ����� ��������� ����� �����, ����� ������������ ������ �� � �� 1-2
                    // ��� �� � � ���� �������� ������ ����������� �� ������ ���� ��������.
                    cout<<"\n �������� ����� [1-2]:";
                    cin>>n;
                }while(n<1 || n>2);
                if(n==1)
                {
                    cout<<" �������� ����� �� ����: ";
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
    cout<<"\n\t  ����";
    cout<<"\n 1. ��������� �� ����������� � �������� ���";
    cout<<"\n 2. ��������� �� ��������� � ���-����� ���� �� �������� ������";
    cout<<"\n 3. ��������� �� �����������, ����� ���� ���� ���� ����";
    do{// � ������� �� ����� ��������� ����� �����, ����� ������������ ������ �� � �� 1-3
        // ��� �� � � ���� �������� ������ ����������� �� ������ ���� ��������.
        cout<<"\n �������� ����� [1-3]:";
        cin>>n;
    }while(n<1 || n>3);
    system("cls");
    if (i==0)
    { // ��� � ��������� ���� �������� ������.
        cout<<"\n ����� ������, � ��������� ���� �������� ���������."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
    else
    {
        switch (n)
        {
            case 1: sort_depositors(p,i); break; // ���������� �� ����������.
            case 2: max_deposit(p,i); break; // ���������� �� ����������.
            case 3: depositors_one(p,i); // ���������� �� ����������.
        }
    }
}

void sort_depositors(person p[],int i) // ���������� �� ������� references().
{
    int br=0;
    int n;
    cout<<"\n ��������� �� ����������� � �������� ��� ��:";
    cout<<"\n 1. ������ �� ���������� �� ���������;";
    cout<<"\n 2. ������ �������� �� ���������.";
    do{ // � ������� �� ����� ��������� ����� �����, ����� ������������ ������ �� � �� 1-2
        // ��� �� � � ���� �������� ������ ����������� �� ������ ���� ��������.
        cout<<"\n �������� ����� [1-2]:";
        cin>>n;
    }while(n<1 || n>2);
    system("cls");

    if (n==1) // ��� ��� ������� ����� 1.
    {
        struct depositor
        { // ��������� ����� ������� ������ �� �����, �����, � ������ �� ���������.
            string card_number;
            string name;
            string day;
            string month;
            string year;
        }d[50],d2[50]; // ��������� �� ��� ������ �� �� ���� �� �����������.

        for (int n=0; n<i; n++)
        { // ���� ����� �� ������� ������� ���������� �� ������� �����.
            d[n].card_number=p[n].card_number;
            d[n].name=p[n].name;
            d[n].day=p[n].day;
            d[n].month=p[n].month;
            d[n].year=p[n].year;
        }
        // ���� ������ �� ���������, ����������� �� ���������, ������ ������.
        for (int n=i; n>1; n--)
        { // ����� ����� �� ����� �� ���� �� �������� ������ ����� 1.
            for(int j=0;j<n-1;j++)
            { // ����� ����� �� ����� �� �������� �� �������� �� ������� �� ������ �����.
                // ���������� �� ������� � �����.
                stringstream a(d[j].year);
                int aa;
                a>>aa;
                stringstream b(d[j+1].year);
                int bb;
                b>>bb;
                if(aa<bb) // ���������� �� ��������.
                {
                    d2[j]=d[j];
                    d[j]=d[j+1];
                    d[j+1]=d2[j];
                }
                else if(aa==bb) // ���������� �� ��������.
                {// ���������� �� ������� � �����.
                    stringstream c(d[j].month);
                    int cc;
                    c>>cc;
                    stringstream l(d[j+1].month);
                    int ll;
                    l>>ll;
                    if(cc<ll) // ���������� �� ��������.
                    {
                        d2[j]=d[j];
                        d[j]=d[j+1];
                        d[j+1]=d2[j];
                    }
                    else if(cc==ll) // ���������� �� ��������.
                    {// ���������� �� ������� � �����.
                        stringstream m(d[j].day);
                        int mm;
                        m>>mm;
                        stringstream v(d[j+1].day);
                        int vv;
                        v>>vv;
                        if(mm<vv) // ���������� �� �����.
                        {
                            d2[j]=d[j];
                            d[j]=d[j+1];
                            d[j+1]=d2[j];
                        }
                    } // strlen(str), strcpy(string,string), strcat(str,str),strcmp(str,str)
                }// char ime[]="Teodor";
            }// cout<<hex<<13;
        }
        cout<<"\n ��������� �� ����������� ������ �� ������ �� ���������� �� ���������."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
        for (int n=0; n<i; n++)
        { // ��������� �� ���������� �����.
            cout<<endl;
            cout<<" �����: "<<d[n].card_number<<endl;
            cout<<" ���: "<<d[n].name<<endl;
            cout<<" ���� �� ����������: "<<d[n].day<<"/"<<d[n].month<<"/"<<d[n].year<<endl;
            cout<<setfill('*')<<setw(50)<<"*";
        }
    }
    else // ��� ��� ������� ����� 2.
    {
        struct depositor
        { // ��������� ����� ������� ������ �� �����, �����, � ������ ����.
            string card_number;
            string name;
            unsigned int amount;
        }d[50],d2[50]; // ��������� �� ��� ������ �� �� ���� �� �����������.

        for (int n=0; n<i; n++)
        { // ���� ����� �� ������� ������� ���������� �� ������� �����.
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
        { // ����� ����� �� ����� �� ���� �� �������� ������ ����� 1.
            for(int j=0;j<n-1;j++)
            { // ����� ����� �� ����� �� �������� �� �������� �� ������� �� ������ �����.
                if(d[j].amount<d[j+1].amount) // ���������� �� ������.
                {
                    d2[j]=d[j];
                    d[j]=d[j+1];
                    d[j+1]=d2[j];
                }
            }
        }
        cout<<"\n ��������� �� ����������� ������ �� ������ �������� �� ���������."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
        for (int n=0; n<i; n++)
        { // ��������� �� ���������� �����.
            cout<<"\n\t �"<<n+1<<endl;
            cout<<" �����: "<<d[n].card_number<<endl;
            cout<<" ���: "<<d[n].name<<endl;
            cout<<" ����: "<<d[n].amount<<"��."<<endl;
            cout<<setfill('*')<<setw(50)<<"*";
        }
    }
}

void max_deposit(person p[],int i) // ���������� �� ������� references().
{
    string s,name,number;
    int k, maxa=0,br=0;
    do{ // ������� �� �������� �������� ������.
        cout<<"\n �������� ������(BGN (����), USD (������),EURO (����)): ";
        cin>>s;
        if(s=="BGN" || s=="USD" || s=="EURO")
            k=1;
        else
            cout<< " ����� ������!"<<endl;
    }while(k!=1);
    system("cls");
    for (int n=0; n<i; n++)
    { // ������� �� ������.
        for (int x=0; x<3; x++)
        { // ������� �� ����������.
            if(p[n].dp[x].currency==s)
            {
                if (p[n].dp[x].amount>maxa)  // ���������� �� ������.
                {
                    maxa=p[n].dp[x].amount;
                    number=p[n].card_number;
                    name=p[n].name;
                }
                br++;
            }
        }
    }
    if (br==0) // ��� ���� ���� � ������� �������.
        cout<<"\n ���� ��������� � ���� "<<s<<"."<<endl;
    else // ��� ��� ��������� ������ � ���-�����.
        cout<<"\n ���������, ����� ��� ���-������ ���� �� �������� "<<maxa<<" � "<<s<<" � "<<name<<" � ����� �� ������� "<<number<<"."<<endl;
    cout<<setfill('*')<<setw(50)<<"*";
}

void depositors_one(person p[],int i) // ���������� �� ������� references().
{
    int br=0;
    cout<<"\n\t �����������, ����� ���� ���� ���� ����:"<<endl;
    cout<<setfill('*')<<setw(50)<<"*";
    for (int n=0; n<i; n++)
    { // ������� �� ������.
        if(p[n].counts==1)
        { // ��������� �� ������ � ���� ����.
            cout<<"\n �����: "<<p[n].card_number<<endl;
            cout<<" ��� �����: "<<p[n].name<<endl;
            cout<<" ����: "<<p[n].dp[0].currency<<endl;
            cout<<" ����: "<<p[n].dp[0].amount<<endl;
            cout<<setfill('*')<<setw(50)<<"*";
            br++;
        }
    }
    if (br==0) // ��� ���� ������ ����.
    {
        cout<<"\n ���� ������ ���������."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
}

void normal_file(person p[],int& i,int& FP)
{
    int n;
    cout<<"\n\t  ����";
    cout<<"\n 1. ��������� �� ���������� ����� ��� ����";
    cout<<"\n 2. ����������� �� ������� �� ����� � ����������";
    cout<<"\n 3. ��������� �� ������� �� �����";
    cout<<"\n 4. ���������� �� ���������� ����� ��� �����";
    do{ // � ������� �� ����� ��������� ����� �����, ����� ������������ ������ �� � �� 1-2
        // ��� �� � � ���� �������� ������ ����������� �� ������ ���� ��������.
        cout<<"\n �������� ����� [1-4]:";
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
        cout<<"\n\t������ ���� ������� �������!"<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
        fstream f;
        // ������������� �������� �� �����, � ��� �� �� ������� ���������� �����.
        f.open("Depositors.txt", ios::out | ios::trunc);
        f.close();
        // �������� �� �����.
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
        // ��������� �� �����.
        f.close();
    }
    else
    {
        cout<<"\n ����� ������, � ��������� ���� �������� ���������."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
}

void fileToProgram(person p[],int& i,int& FP)
{
    fstream f;
    f.open("Depositors.txt", ios::in);
    // �������� ���� ������ ���� � ��� ����������.
    if(FP==1)
    {
        cout<<"\n\t������ ���� ���� ����������."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
    // �������� ���� ������ � ������.
    else if ( f.peek() == EOF)
    {
        cout<<"\n\t������ � ������!"<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
    else
    {
        cout<<"\n ������� �� ����� ���� ����������� �������!"<<endl;
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
    // �������� ���� ������ � ������.
    if ( f.peek() == EOF)
    {
        cout<<"\n\t������ � ������!"<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
    else
    {
        cout<<"\n\t������� �� �����"<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
        f>>j;
        for(int n=0; n<j; n++)
        {
            f>>a;
            cout<<"\n �����: "<<a<<endl;
            f.ignore();
            getline(f, a);
            cout<<" ��� �����: "<<a<<endl;
            f>>a;
            f>>b;
            f>>c;
            cout<<" ���� �� ���������: "<<a<<"/"<<b<<"/"<<c<<endl;
            int y;
            f>>y;
            cout<<" ���� �������: "<<y<<endl<<endl;
            int x=0;
            while (x<y)
            {
                f>>a;
                cout<<" ���� �"<<x+1<<": "<<a<<endl;
                f>>a;
                cout<<" ����: "<<a<<endl;
                x++;
            }
            cout<<setfill('*')<<setw(50)<<"*";
        }
    }
    f.close();
}

void clear_file()
{
    cout<<"\n\t������ ���� �������� �������!"<<endl;
    cout<<setfill('*')<<setw(50)<<"*";
    fstream f;
    f.open("Depositors.txt", ios::out | ios::trunc);
    f.close();
}

void binary_file(person p[],int& i,int& FPB)
{
    int n;
    cout<<"\n\t  ����";
    cout<<"\n 1. ��������� �� ���������� ����� ��� ����";
    cout<<"\n 2. ����������� �� ������� �� ����� � ����������";
    cout<<"\n 3. ��������� �� ������� �� �����";
    cout<<"\n 4. ���������� �� ���������� ����� ��� �����";
    do{ // � ������� �� ����� ��������� ����� �����, ����� ������������ ������ �� � �� 1-2
        // ��� �� � � ���� �������� ������ ����������� �� ������ ���� ��������.
        cout<<"\n �������� ����� [1-4]:";
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
        cout<<"\n\t������ ���� ������� �������!"<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
        fstream f;
        // ������������� �������� �� �����, � ��� �� �� ������� ���������� �����.
        f.open("Depos.dat", ios::out | ios::trunc);
        f.close();
        // �������� �� �����.
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
        // ��������� �� �����.
        f.close();
    }
    else
    {
        cout<<"\n ����� ������, � ��������� ���� �������� ���������."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
}

void fileToProgramb(person p[],int& i,int& FPB)
{
    fstream f;
    f.open("Depos.dat", ios::binary | ios::in);
    // �������� ���� ������ ���� � ��� ����������.
    if(FPB==1)
    {
        cout<<"\n\t������ ���� ���� ����������."<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
    // �������� ���� ������ � ������.
    else if ( f.peek() == EOF)
    {
        cout<<"\n\t������ � ������!"<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
    else
    {
        cout<<"\n ������� �� ����� ���� ����������� �������!"<<endl;
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
    // �������� ���� ������ � ������.
    if ( f.peek() == EOF)
    {
        cout<<"\n\t������ � ������!"<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
    }
    else
    {
        cout<<"\n\t������� �� �����"<<endl;
        cout<<setfill('*')<<setw(50)<<"*";
        f.read((char*)&j, sizeof(int));
        for(int n=0; n<j; n++)
        {
            int razmer;
            f.read((char*)&razmer, sizeof(int));
            char nomer[razmer];
            f.read(nomer, razmer);
            cout<<"\n �����: "<<nomer<<endl;
            f.read((char*)&razmer, sizeof(int));
            char name[razmer];
            f.read(name, razmer);
            cout<<" ��� �����: "<<name<<endl;
            f.read((char*)&razmer, sizeof(int));
            char day[razmer];
            f.read(day, razmer);
            f.read((char*)&razmer, sizeof(int));
            char month[razmer];
            f.read(month, razmer);
            f.read((char*)&razmer, sizeof(int));
            char year[razmer];
            f.read(year, razmer);
            cout<<" ���� �� ���������: "<<day<<"/"<<month<<"/"<<year<<endl;
            int counts;
            f.read((char*)&counts, sizeof(int));
            cout<<" ���� �������: "<<counts<<endl<<endl;
            int x=0;
            while (x<counts)
            {
                f.read((char*)&razmer, sizeof(int));
                char currency[razmer];
                f.read(currency, razmer);
                cout<<" ���� �"<<x+1<<": "<<currency<<endl;
                int amount;
                f.read((char*)&amount, sizeof(int));
                cout<<" ����: "<<amount<<endl;
                x++;
            }
            cout<<setfill('*')<<setw(50)<<"*";
        }
    }
    f.close();
}

void clear_fileb()
{
    cout<<"\n\t������ ���� �������� �������!"<<endl;
    cout<<setfill('*')<<setw(50)<<"*";
    fstream f;
    f.open("Depos.dat", ios::binary | ios::out | ios::trunc);
    f.close();
}

