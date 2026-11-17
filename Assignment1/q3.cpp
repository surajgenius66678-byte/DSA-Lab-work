
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct employee
{
    int id;
    char name[50];
    int salary;
};

int main()
{
    int size;

    cout << "Enter size: ";
    cin >> size;

    if (size <= 0)
        return 0;

    employee* data = new employee[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter id: ";
        cin >> data[i].id;

        cout << "Enter name: ";
        cin.ignore(10000, '\n');
        cin.getline(data[i].name, 50);

        cout << "Enter salary: ";
        cin >> data[i].salary;
    }

    FILE* f = fopen("data.txt", "wb+");

    if (f == NULL)
    {
        perror("Error opening file");
        delete[] data;
        return 1;
    }

    for (int i = 0; i < size; i++)
        fwrite(&data[i], sizeof(employee), 1, f);

    rewind(f);

    employee emp;

    while (fread(&emp, sizeof(employee), 1, f) == 1)
    {
        if (emp.salary > 50000)
            emp.salary = emp.salary + (5 * emp.salary) / 100;

        else if (emp.salary > 20000)
            emp.salary = emp.salary + (10 * emp.salary) / 100;

        else
            emp.salary = emp.salary + (15 * emp.salary) / 100;

        fseek(f, -(long)sizeof(employee), SEEK_CUR);

        fwrite(&emp, sizeof(employee), 1, f);

        fflush(f);
    }

    rewind(f);

    cout << "---Updated Record---" << endl;

    while (fread(&emp, sizeof(employee), 1, f) == 1)
    {
        cout << "id : " << emp.id << endl;
        cout << "name : " << emp.name << endl;
        cout << "salary : " << emp.salary << endl;
    }

    fclose(f);

    delete[] data;

    return 0;
}
