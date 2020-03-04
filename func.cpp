#include <iostream>
#include <windows.h>
#include <fstream>
#include "func.h"

using namespace std;

Planeta** read_db(Planeta** arr, char* filename)
{
    int N = 0;
    if (arr != NULL) {
        N = amount(filename);
        for (int i = 0; i < N; i++)
        {  
         //arr[i]->~Planeta();
         delete arr[i];              
        }
        delete[] arr;
    }
    N = amount(filename);
    arr = new Planeta* [N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new Planeta;
    }
    read_file(filename, arr, N);
    return arr;
}

int amount(char* filename)
{
    int i = -1;
    char* str = new char[1024];
    ifstream fin(filename, ios::in);
    if (!fin)
    {
        cout << "Нет файла" << filename << endl;
    }
    while (!fin.eof())
    {
        fin.getline(str, 1024, '\n');
        i++;
    }
    fin.close();
    delete[] str;
    return i;
}

int read_file(char* filename, Planeta** arr, int& N)
{
    char name1[20];
    double radnum1, sredred1, gravite1;
    ifstream fin(filename, ios::in);
    if (!fin)
    {
        cout << "Heт файла " << filename << endl;
        return 1;
    }
    for (int i = 0; i < N; i++)
    {
        fin >> name1;
        arr[i]->setName(name1);
        fin >> radnum1;
        arr[i]->setRadnum(radnum1);
        fin >> sredred1;
        arr[i]->setSredred(sredred1);
        fin >> gravite1;
        arr[i]->setGravite(gravite1);
        cout << arr[i]->getName() << " " << arr[i]->getRadnum() << " " << arr[i]->getSredred() << " " << arr[i]->getGravite() << endl;
    };

    fin.close();
    return 0;
}

int write_file(char* filename, int& k)
{
    char name1[20];
    double radnum1, sredred1, gravite1;
    ofstream fout;
    fout.open(filename, ios::app);
    if (!fout)
    {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }
    for (int i = 0; i < k; i++)
    {
        cout << "Введите имя планеты ";
        cin >> name1;
        cout << "Введите номер планеты ";
        cin >> radnum1;
        cout << "Введите сред.рад планеты ";
        cin >> sredred1;
        cout << "Введите гравитацию планеты ";
        cin >> gravite1;
        fout << name1 << "  " << radnum1 << "  " << sredred1 << "  " << gravite1 << endl;

    }
    fout.close();
    return 0;
}

int write_new_file(Planeta** arr, int& N)
{
    ofstream fout("123lkm.txt", ios::out);
    if (!fout)
    {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }
    for (int i = 0; i < N; i++)
        fout << arr[i]->getName() << " " << arr[i]->getRadnum() << " " << arr[i]->getSredred() << " " << arr[i]->getGravite() << endl;

    fout.close();
    return 0;
}

int sort_puserek(char* filename, Planeta** arr, int& N)
{
    char name1[20];
    double radnum1, sredred1, gravite1;
    ifstream fin(filename, ios::in);
    if (!fin)
    {
        cout << "Heт файла " << filename << endl;
        return 1;
    }
    for (int i = 0; i < N; i++)
    {
        fin >> name1;
        arr[i]->setName(name1);
        fin >> radnum1;
        arr[i]->setRadnum(radnum1);
        fin >> sredred1;
        arr[i]->setSredred(sredred1);
        fin >> gravite1;
        arr[i]->setGravite(gravite1);
    }
    fin.close();
    int* sort_arr = new int[N];
    for (int i = 0; i < N; i++) {
        sort_arr[i] = arr[i]->getGravite();
        cout << arr[i]->getName() << " --- ";
        cout << arr[i]->getGravite() << endl;
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (sort_arr[j] > sort_arr[j + 1]) {
                swap(arr[j], arr[j + 1]);

            }
        }
    }

   // write_db(filename, arr, n);
    return 0;
} 
//написать функцию для записи в файл через массив 

int edit(char* filename, Planeta** arr)
{
    char name1[20];
    int number, score;
    double radnum1, sredred1, gravite1;
    do {
        cin >> number;
        number = number - 1;
        cout << "Введите название планеты ";
        cin >> name1;
        arr[number]->setName(name1);
        cout << "Введите расположение ";
        cin >> radnum1;
        arr[number]->setRadnum(radnum1);
        cout << "Введите сред. рад. орбиты";
        cin >> sredred1;
        arr[number]->setSredred(sredred1);
        cout << "Введите силу притяж. ";
        cin >> gravite1;
        arr[number]->setGravite(gravite1);
        cout << "Хотите продолжить редактирование, если (да) нажмите 1, если(нет), то любую другую ";
        cin >> score;
    } while (score == 1);
  //  write_db(filename, arr, a);
    return 0;
}
//написать функцию для записи в файл через массив 

/*int write_db(char* filename, int& k)
{
    char name1[20];
    double radnum1, sredred1, gravite1;
    ofstream fout;
    fout.open(filename, ios::app);
    if (!fout)
    {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }
    for (int i = 0; i < k; i++)
    {
        cout << "Введите имя планеты ";
        cin >> name1;
        cout << "Введите номер планеты ";
        cin >> radnum1;
        cout << "Введите сред.рад планеты ";
        cin >> sredred1;
        cout << "Введите гравитацию планеты ";
        cin >> gravite1;
        fout << name1 << "  " << radnum1 << "  " << sredred1 << "  " << gravite1 << endl;

    }
    fout.close();
    return 0;
}
*/
