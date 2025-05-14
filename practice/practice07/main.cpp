// practice07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>
#include <string>
#include <iomanip>

//base class
class Employee {
public:
    Employee(std::string name, int id) : name(std::move(name)), id(id) {}
    virtual ~Employee() = default;

    virtual double calculateSalary() const = 0;
    virtual void displayInfo() const = 0;
protected:
    std::string name;
    int id;
};

//derived classes
class SalariedEmployee : public Employee {
public:
    SalariedEmployee(std::string name, int id, double salary)
        : Employee(std::move(name), id), monthlySalary(salary) {
    }

    double calculateSalary() const override {
        return monthlySalary;
    }

    void displayInfo() const override {
        std::cout << "ID: " << id << ", Name: " << name
            << ", Type: Salaried, Monthly Salary: $"
            << std::fixed << std::setprecision(2)
            << monthlySalary << std::endl;
    }
private:
    double monthlySalary;
};

class HourlyEmployee : public Employee {
public:
    HourlyEmployee(std::string name, int id, double rate, int hours)
        : Employee(std::move(name), id), hourlyRate(rate), hoursWorked(hours) {
    }

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void displayInfo() const override {
        std::cout << "ID: " << id << ", Name: " << name
            << ", Type: Hourly, Hours Worked: " << hoursWorked
            << ", Hourly Rate: $" << std::fixed << std::setprecision(2) << hourlyRate
            << ", Salary: $" << calculateSalary() << std::endl;
    }
private:
    double hourlyRate;
    int hoursWorked;
};

class CommissionEmployee : public Employee {
public:
    CommissionEmployee(std::string name, int id, double base, double sales, double rate)
        : Employee(std::move(name), id), baseSalary(base), salesAmount(sales), commissionRate(rate) {
    }

    double calculateSalary() const override {
        return baseSalary + (salesAmount * commissionRate);
    }

    void displayInfo() const override {
        std::cout << "ID: " << id << ", Name: " << name
            << ", Type: Commission, Base Salary: $"
            << std::fixed << std::setprecision(2) << baseSalary
            << ", Sales: $" << salesAmount
            << ", Commission Rate: " << (commissionRate * 100) << "%"
            << ", Salary: $" << calculateSalary() << std::endl;
    }
private:
    double baseSalary;
    double salesAmount;
    double commissionRate;
};

//load employees from file
std::vector<Employee*> loadEmployees(const std::string& filename) {
    std::vector<Employee*> employees;
    std::ifstream infile(filename);
    std::string line;
    int lineNum = 0;

    while (std::getline(infile, line)) {
        ++lineNum;
        std::istringstream iss(line);
        std::string type;
        int id;
        std::string name;

        if (!(iss >> type >> id >> name)) {
            std::cerr << "Error on line " << lineNum << ": Incompatible line contents\n";
            continue;
        }

        if (type == "Salaried") {
            double salary;
            if (iss >> salary) {
                employees.push_back(new SalariedEmployee(name, id, salary));
            }
            else {
                std::cerr << "Error on line " << lineNum << ": Incompatible line contents\n";
            }
        }
        else if (type == "Hourly") {
            double rate;
            int hours;
            if (iss >> rate >> hours) {
                employees.push_back(new HourlyEmployee(name, id, rate, hours));
            }
            else {
                std::cerr << "Error on line " << lineNum << ": Incompatible line contents\n";
            }
        }
        else if (type == "Commission") {
            double base, sales, rate;
            if (iss >> base >> sales >> rate) {
                employees.push_back(new CommissionEmployee(name, id, base, sales, rate));
            }
            else {
                std::cerr << "Error on line " << lineNum << ": Incompatible line contents\n";
            }
        }
        else {
            std::cerr << "Error on line " << lineNum << ": Incompatible line contents\n";
        }
    }

    return employees;
}

int main()
{
    std::vector<Employee*> employees = loadEmployees("employees.txt");

    for (const auto& e : employees) {
        e->displayInfo();
    }

    for (auto& e : employees) {
        delete e;
    }

    return 0;
}
