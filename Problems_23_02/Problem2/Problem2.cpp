#include <iostream>
#pragma warning(disable : 4996)

namespace Establishments
{
    enum class Position {
        Software_Engeneer,
        Senior_Software_Engeneer,
        Engeneer_Manager,
        Lead_Software_Engineer,
        Unassigned
    };

    void PrintPosition(const Position& pos)
    {
        using std::cout;
        switch (pos)
        {
            case Position::Software_Engeneer:
                cout << "Software Engeneer";
                break;
            case Position::Senior_Software_Engeneer:
                cout << "Senior Software Engeneer";
                break;
            case Position::Engeneer_Manager:
                cout << "Engeneer Manager";
                break;
            case Position::Lead_Software_Engineer:
                cout << "Lead Software Engineer";
                break;
        }
    }

    struct Employee {
        static const int NAME_MAX_SIZE = 100;
        static const int MAX_EMPLOYEE_SCORE = 5;

        char Name[NAME_MAX_SIZE] = "";
        double Salary = 0;
        int Score = 0;
        Position JobPosition = Position::Unassigned;
    };

    void InitEmployee(Employee& employee)
    {
        using std::cin;
        using std::cout;
        using std::endl;

        char name[Employee::NAME_MAX_SIZE];
        double salary = 0.0;
        int score = 0.0;
        int position = 0;

        cout << "Enter name: ";
        cin.ignore();
        cin.getline(name, Employee::NAME_MAX_SIZE);
        strcpy(employee.Name, name);

        cout << "Salary: ";
        cin >> salary;
        employee.Salary = salary;

        cout << "Enter a score [0 - " << Employee::MAX_EMPLOYEE_SCORE << "]: ";
        cin >> score;
        employee.Score = score;

        cout << "Please enter job position code [0 - 3]: ";
        cin >> position;
        employee.JobPosition = (Position)position;
    }
    void PrintEmployee(const Employee& employee)
    {
        using std::cout;
        using std::endl;

        cout << "Name: " << employee.Name << ", ";
        PrintPosition(employee.JobPosition);
        cout << endl;
        cout << "Current score: " << employee.Score << "/" << Employee::MAX_EMPLOYEE_SCORE << endl;
        cout << "Salary: " << employee.Salary << endl;

    }

    struct Establishment {
        static const int MAX_EMPLOYEE_COUNT = 4;
        Employee employees[MAX_EMPLOYEE_COUNT];
    };

    void InitEstablishment(Establishment& firm) {
        for (size_t i = 0; i < Establishment::MAX_EMPLOYEE_COUNT; i++)
        {
            std::cout << "Reading employee #" << i + 1 << std::endl;
            std::cout << "{" << std::endl;
            InitEmployee(firm.employees[i]);
            std::cout << "}" << std::endl;
        }
    }

    enum class Criteria
    {
        Salary,
        Score
    };

    short Compare(const Employee& first, const Employee& second, Criteria criteria)
    {
        switch (criteria)
        {
            case Criteria::Salary:
                return first.Salary - second.Salary;
            case Criteria::Score:
                return first.Score - second.Score;
        }
    }
    
    bool GetMinMaxIndexes(Position pos, const Employee* employees, int& maxIndex, int& minIndex, Criteria criteria)
    {
        minIndex = 0, maxIndex = 0;
        bool hasEmployees = false;
        for (size_t i = 1; i < Establishment::MAX_EMPLOYEE_COUNT; i++)
        {
            if (employees[i].JobPosition != pos)
                continue;
            if (!hasEmployees)
                hasEmployees = true;
            if (Compare(employees[i], employees[minIndex], criteria) < 0)
                minIndex = i;
            if (Compare(employees[i], employees[maxIndex], criteria) > 0)
                minIndex = i;
        }
        return hasEmployees;
    }
    void PrintMinMax(const Employee* employees, Criteria criteria)
    {
        for (size_t i = 0; i < 4; i++)
        {
            int minIndex, maxIndex;
            Position pos = (Position)i;
            bool hasEmployees = GetMinMaxIndexes(pos, employees, maxIndex, minIndex, Criteria::Score);
            PrintPosition(pos);
            if (!hasEmployees)
            {
                std::cout << " -> No employees with this position!" << std::endl;
                continue;
            }
            std::cout << " -> Min: " << employees[minIndex].Score << ", Max:" << employees[maxIndex].Score;
            std::cout << std::endl;
        }
    }

    double GetAverageSalary(const Employee* employees, size_t count)
    {
        double sum = 0;
        for (size_t i = 0; i < count; i++)
            sum += employees[i].Salary;
        return sum / count;
    }

    void Swap(int& a, int& b)
    {
        int _ = a;
        a = b;
        b = _;
    }

    void SortMask(const Employee* employees, size_t count, int* mask)
    {
        for (size_t i = 0; i < count; i++)
        {
            if (mask[i] < 0)
                continue;
            unsigned minIndex = i;
            for (size_t j = i + 1; j < count; j++)
            {
                if (mask[j] < 0)
                    continue;
                if (strcmp(employees[mask[minIndex]].Name, employees[mask[j]].Name) < 0)
                    minIndex = j;
            }
            if (minIndex != i)
                Swap(mask[minIndex], mask[i]);
        }
    }

    void PrintSorted(const Employee* employees, size_t count, int* mask)
    {
        using std::cout;
        using std::endl;

        SortMask(employees, count, mask);
        
        for (size_t i = 0; i < count; i++)
        {
            if (mask[i] < 0)
                continue;
            PrintEmployee(employees[mask[i]]);
        }
    }

    void PrintAboveAverage(const Employee* employees, size_t count)
    {
        double averageSalary = GetAverageSalary(employees, count);
        int* aboveAverage = new int[count];

        for (size_t i = 0; i < count; i++)
        {
            aboveAverage[i] = -1;
            if (employees[i].Salary > averageSalary)
                aboveAverage[i] = i;
        }

        PrintSorted(employees, count, aboveAverage);

        delete[] aboveAverage;
    }

}


int main()
{
    using namespace Establishments;
    using std::cout;
    using std::endl;

    Establishment companyLLC;
    InitEstablishment(companyLLC);
    cout << endl;

    cout << "Highly-paid employees: " << endl;
    PrintAboveAverage(companyLLC.employees, Establishment::MAX_EMPLOYEE_COUNT);
    cout << endl;

    cout <<"Min & max scores per position: " << endl;
    PrintMinMax(companyLLC.employees, Criteria::Score);
}