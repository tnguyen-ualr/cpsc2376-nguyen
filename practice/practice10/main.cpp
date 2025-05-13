// practice10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <string>
#include <iomanip>

//pi
const double PI = 3.14159;

//base class
class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};

//derived classes
class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override {
        return width * height;
    }
private:
    double width, height;
};

class Circle : public Shape {
public:
    Circle(double r) : radius(r) {}
    double getArea() const override {
        return PI * radius * radius;
    }
private:
    double radius;
};

//print area
void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        std::cout << "Area: " << std::fixed << std::setprecision(4)
            << shape->getArea() << std::endl;
    }
}

//load shapes from file
std::vector<std::unique_ptr<Shape>> loadShapes(const std::string& filename) {
    std::vector<std::unique_ptr<Shape>> shapes;
    std::ifstream infile(filename);
    std::string line;
    int lineNumber = 0;

    while (std::getline(infile, line)) {
        ++lineNumber;
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "rectangle") {
            double w, h;
            if (iss >> w >> h) {
                shapes.push_back(std::make_unique<Rectangle>(w, h));
            }
            else {
                std::cout << "Error! Line " << lineNumber
                    << ": Contains incompatible contents\n";
            }
        }
        else if (type == "circle") {
            double r;
            if (iss >> r) {
                shapes.push_back(std::make_unique<Circle>(r));
            }
            else {
                std::cout << "Error! Line " << lineNumber
                    << ": Contains incompatible contents\n";
            }
        }
        else {
            std::cout << "Error! Line " << lineNumber
                << ": Contains incompatible contents\n";
        }
    }

    return shapes;
}

int main()
{
    std::string filename = "shapes.txt";
    auto shapes = loadShapes(filename);
    printAllAreas(shapes);
}