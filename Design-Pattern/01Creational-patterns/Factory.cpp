class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
    virtual ~Shape() {}
};
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Circle\n";
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Square\n";
    }
};
class ShapeFactory {
public:
    virtual Shape* createShape() = 0; // Factory method
    virtual ~ShapeFactory() {}
};
class CircleFactory : public ShapeFactory {
public:
    Shape* createShape() override {
        return new Circle();
    }
};

class SquareFactory : public ShapeFactory {
public:
    Shape* createShape() override {
        return new Square();
    }
};
int main() {
    ShapeFactory* factory;

    factory = new CircleFactory();
    Shape* shape1 = factory->createShape();
    shape1->draw(); // Output: Drawing Circle
    delete shape1;
    delete factory;

    factory = new SquareFactory();
    Shape* shape2 = factory->createShape();
    shape2->draw(); // Output: Drawing Square
    delete shape2;
    delete factory;

    return 0;
}