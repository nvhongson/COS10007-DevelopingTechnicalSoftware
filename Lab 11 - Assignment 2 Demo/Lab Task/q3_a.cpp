#include <iostream>

class Rectangle {
protected:
    double length;
    double width;

public:
    Rectangle(double len, double wid) : length(len), width(wid) {}

    double area() {
        return length * width;
    }
};

class Box : public Rectangle {
private:
    double depth;

public:
    Box(double len, double wid, double dep) : Rectangle(len, wid), depth(dep) {}

    double volume() {
        return length * width * depth;
    }

    double area() override {
        double side1 = length * width;
        double side2 = length * depth;
        double side3 = width * depth;

        return 2 * (side1 + side2 + side3);
    }
};

int main() {
    Box myBox(3.0, 4.0, 5.0);

    std::cout << "Box area: " << myBox.area() << std::endl;
    std::cout << "Box volume: " << myBox.volume() << std::endl;

    return 0;
}
