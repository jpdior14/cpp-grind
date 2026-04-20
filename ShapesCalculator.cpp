#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <memory>

// ---------- Abstract Shape Class ----------
class Shape {
protected:
    std::string color;
    static int shapeCount;

public:
    Shape(const std::string& color = "white") : color(color) {
        shapeCount++;
    }

    virtual ~Shape() {
        shapeCount--;
    }

    // Pure virtual functions
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    // Virtual functions
    virtual void draw() const {
        std::cout << "Drawing a " << color << " shape.\n";
    }

    virtual void display() const {
        std::cout << "Color: " << color << ", Area: " << area()
                  << ", Perimeter: " << perimeter() << std::endl;
    }

    static int getShapeCount() { return shapeCount; }

    friend bool operator==(const Shape& lhs, const Shape& rhs) {
        return lhs.area() == rhs.area(); // simplistic equality
    }

    friend std::ostream& operator<<(std::ostream& os, const Shape& shape) {
        os << "Shape(color=" << shape.color << ", area=" << shape.area()
           << ", perimeter=" << shape.perimeter() << ")";
        return os;
    }
};

int Shape::shapeCount = 0;

// ---------- Circle Class ----------
class Circle : public Shape {
private:
    double radius;
    static const double PI;

public:
    Circle(double radius, const std::string& color = "white")
        : Shape(color), radius(radius) {}

    double area() const override {
        return PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * PI * radius;
    }

    void draw() const override {
        std::cout << "Drawing a " << color << " circle of radius " << radius << ".\n";
    }

    double getDiameter() const { return 2 * radius; }
    double getRadius() const { return radius; }
};

const double Circle::PI = 3.14159265358979323846;

// ---------- Rectangle Class ----------
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double width, double height, const std::string& color = "white")
        : Shape(color), width(width), height(height) {}

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }

    double getWidth() const { return width; }
    double getHeight() const { return height; }
    bool isSquare() const { return width == height; }

    void draw() const override {
        std::cout << "Drawing a " << color << " rectangle of size "
                  << width << "x" << height << ".\n";
    }
};

// ---------- Triangle Class ----------
class Triangle : public Shape {
private:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3, const std::string& color = "white")
        : Shape(color), side1(s1), side2(s2), side3(s3) {}

    double area() const override {
        // Heron's formula
        double s = (side1 + side2 + side3) / 2.0;
        return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double perimeter() const override {
        return side1 + side2 + side3;
    }

    std::string getType() const {
        if (side1 == side2 && side2 == side3)
            return "Equilateral";
        else if (side1 == side2 || side2 == side3 || side1 == side3)
            return "Isosceles";
        else
            return "Scalene";
    }

    bool isValid() const {
        return (side1 + side2 > side3) &&
               (side2 + side3 > side1) &&
               (side1 + side3 > side2);
    }

    void draw() const override {
        std::cout << "Drawing a " << color << " triangle of sides "
                  << side1 << ", " << side2 << ", " << side3 << ".\n";
    }
};

// ---------- Shape Factory (optional) ----------
class ShapeFactory {
public:
    enum ShapeType { CIRCLE, RECTANGLE, TRIANGLE };

    static Shape* createShape(ShapeType type) {
        // For simplicity, hardcoded parameters
        switch(type) {
            case CIRCLE: return new Circle(5.0, "red");
            case RECTANGLE: return new Rectangle(4.0, 6.0, "blue");
            case TRIANGLE: return new Triangle(3.0, 4.0, 5.0, "green");
            default: return nullptr;
        }
    }
};

// ---------- Main Demonstration ----------
int main() {
    std::vector<Shape*> shapes;

    // Create shapes using factory or direct instantiation
    shapes.push_back(new Circle(5.0, "red"));
    shapes.push_back(new Rectangle(4.0, 6.0, "blue"));
    shapes.push_back(new Triangle(3.0, 4.0, 5.0, "green"));

    // Demonstrate polymorphism
    std::cout << "=== Shape Information ===\n";
    for (const auto& shape : shapes) {
        std::cout << *shape << std::endl;
        shape->draw();
        shape->display();
        std::cout << "---" << std::endl;
    }

    // Clean up
    for (auto shape : shapes) {
        delete shape;
    }

    std::cout << "Total shapes created: " << Shape::getShapeCount() << std::endl;

    return 0;
}
