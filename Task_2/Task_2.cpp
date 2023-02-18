#include <iostream>

class Triangle {
public:
    Triangle() : Triangle(10, 20, 30, 50, 60, 70) {}

    std::string get_name() { return name; }
    int get_side_a() { return side_a; }
    int get_side_b() { return side_b; }
    int get_side_c() { return side_c; }
    int get_corner_a() { return corner_a; }
    int get_corner_b() { return corner_b; }
    int get_corner_c() { return corner_c; }
protected:
    Triangle(int a, int b, int c, int A, int B, int C) {
        this->side_a = a; this->side_b = b; this->side_c = c;
        this->corner_a = A; this->corner_b = B; this->corner_c = C;
        this->name = "Треугольник";
    }

    std::string name;
    // Стороны
    int side_a, side_b, side_c;
    // Углы
    int corner_a, corner_b, corner_c;
};

class RightTriangle : public Triangle {
public:
    RightTriangle() : RightTriangle(10, 20, 30, 50, 60) {}
protected:
    RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) { 
        this->name = "Прямоугольный треугольник";
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle() : IsoscelesTriangle(10, 20, 50, 60) {}
protected:
    IsoscelesTriangle(int ac, int b, int AC, int B) : Triangle(ac, b, ac, AC, B, AC) { 
        this->name = "Равнобедренный треугольник";
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle() : EquilateralTriangle(30) {}
protected:
    EquilateralTriangle(int abc) : Triangle(abc, abc, abc, 60, 60, 60) {
        this->name = "Равносторонний треугольник";    
    }
};
                            // Треугольники
//==============================================================================================================
                            // Четырехугольники
class Quadrilateral {
public:
    Quadrilateral() : Quadrilateral(10, 20, 30, 40, 50, 60, 70, 80) {}

    std::string get_name() { return name; }
    int get_side_a() { return side_a; }
    int get_side_b() { return side_b; }
    int get_side_c() { return side_c; }
    int get_side_d() { return side_d; }
    int get_corner_a() { return corner_a; }
    int get_corner_b() { return corner_b; }
    int get_corner_c() { return corner_c; }
    int get_corner_d() { return corner_d; }
protected:
    Quadrilateral (int a, int b, int c, int d, int A, int B, int C, int D) {
        this->side_a = a; this->side_b = b; this->side_c = c; this->side_d = d;
        this->corner_a = A; this->corner_b = B; this->corner_c = C; this->corner_d = D;
        this->name = "Четырехугольник";
    }

    std::string name;
    // Стороны
    int side_a, side_b, side_c, side_d;
    // Углы
    int corner_a, corner_b, corner_c, corner_d;
};

class Rectangle : public Quadrilateral {
public:
    Rectangle() : Rectangle(10, 20) {}
protected:
    Rectangle(int ac, int bd) : Quadrilateral(ac, bd, ac, bd, 90, 90, 90, 90) {
        this->name = "Прямоугольник";
    }
};

class Square : public Rectangle {
public:
    Square() : Square(20) {}
protected:
    Square(int abcd) : Rectangle(abcd, abcd) {
        this->name = "Квадрат";
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram() : Parallelogram(20, 30, 30, 40) {}
protected:
    Parallelogram(int ac, int bd, int AC, int BD) : Quadrilateral(ac, bd, ac, bd, AC, BD, AC, BD) {
        this->name = "Параллелограмм";
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus() : Rhombus(30, 40) {}
private:
    Rhombus(int AC, int BD) : Parallelogram(30, 30, AC, BD) {
        this->name = "Ромб";
    }
};

void print_info(Triangle* T) {
    std::cout << T->get_name() << ":\n";
    std::cout << "Стороны: " << "a=" << T->get_side_a() << " b=" << T->get_side_b() << " c=" << T->get_side_c() << std::endl;
    std::cout << "Углы: " << "A=" << T->get_corner_a() << " B=" << T->get_corner_b() << " C=" << T->get_corner_c() << std::endl;
    std::cout << std::endl;
}

void print_info(Quadrilateral* Q) {
    std::cout << Q->get_name() << ":\n";
    std::cout << "Стороны: " << "a=" << Q->get_side_a() << " b=" << Q->get_side_b() << " c=" << Q->get_side_c() << " d=" << Q->get_side_d() << std::endl;
    std::cout << "Углы: " << "A=" << Q->get_corner_a() << " B=" << Q->get_corner_b() << " C=" << Q->get_corner_c() << " D=" << Q->get_corner_d() << std::endl;
    std::cout << std::endl;

}

int main(void) {
    setlocale(LC_ALL, "Rus");

    // Треугольники
    Triangle t;
    print_info(&t);

    RightTriangle rt;
    print_info(&rt);

    IsoscelesTriangle it;
    print_info(&it);

    EquilateralTriangle et;
    print_info(&et);

    // Четырехугольники
    Quadrilateral q;
    print_info(&q);

    Rectangle r;
    print_info(&r);

    Square s;
    print_info(&s);

    Parallelogram p;
    print_info(&p);

    Rhombus rs;
    print_info(&rs);
    return 0;
}