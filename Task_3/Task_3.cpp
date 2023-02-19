#include <iostream>

class Figure {
public:
    Figure() { this->name = "Фигура"; this->sides = 0; }

    virtual void print_info();
protected:
    virtual bool check();

    int sides;
    std::string name;
};

bool Figure::check() {
    if (this->sides == 0)
        return true;
    return false;
};

void Figure::print_info() {
    std::cout << std::endl;
    std::cout << this->name << ":" << std::endl;
    if (this->check())
        std::cout << "Правильная" << std::endl;
    else
        std::cout << "Неправильная" << std::endl;
    std::cout << "Количество сторон: " << this->sides << std::endl;
}

class Triangle : public Figure {
public:
    Triangle() : Triangle(10, 20, 30, 50, 60, 70) {}

    // Вывод информации
    void print_info() override { 
        Figure::print_info();
        std::cout << "Стороны: a=" << this->side_a << " b=" << this->side_b << " c=" << this->side_c << std::endl;
        std::cout << "Углы: a=" << this->corner_a << " b=" << this->corner_b << " c=" << this->corner_c << std::endl;
    }
protected:
    Triangle(int a, int b, int c, int A, int B, int C) {
        this->side_a = a; this->side_b = b; this->side_c = c;
        this->corner_a = A; this->corner_b = B; this->corner_c = C;
        this->sides = 3;
        this->name = "Треугольник";
    }

    // Проверка
    bool check() override {
        if ((this->sides == 3) && ((this->corner_a + this->corner_b + this->corner_c) == 180))
            return true;
        return false;
    }

    // Стороны
    int side_a, side_b, side_c;
    // Углы
    int corner_a, corner_b, corner_c;
};

class RightTriangle : public Triangle {
public:
    RightTriangle() : RightTriangle(10, 20, 30, 50, 60) {}

    // Вывод информации
    void print_info() override {
        Triangle::print_info();
    }
protected:
    RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
        this->name = "Прямоугольный треугольник";
    }

    // Проверка
    bool check() override {
        if (this->corner_c == 90)
            return Triangle::check();
        return false;
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle() : IsoscelesTriangle(10, 20, 50, 60) {}

    // Вывод информации
    void print_info() override { Triangle::print_info(); }
protected:
    // Проверка
    bool check() override {
        if ((this->side_a == this->side_c) && (this->corner_a == this->corner_c))
            return Triangle::check();
        return false;
    }

    IsoscelesTriangle(int ac, int b, int AC, int B) : Triangle(ac, b, ac, AC, B, AC) {
        this->name = "Равнобедренный треугольник";
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle() : EquilateralTriangle(30) {}

    // Вывод иформации
    void print_info() override {
        Triangle::print_info();
    }
protected:
    // Проверка
    bool check() override {
        if (((this->side_a == this->side_b) && (this->side_a == this->side_c)) && (this->corner_a, this->corner_b, this->corner_c) == 60)
            return Triangle::check();
        return false;
    }

    EquilateralTriangle(int abc) : Triangle(abc, abc, abc, 60, 60, 60) {
        this->name = "Равносторонний треугольник";
    }
};
                            // Треугольники
//==============================================================================================================
                            // Четырехугольники
class Quadrilateral : public Figure {
public:
    Quadrilateral() : Quadrilateral(10, 20, 30, 40, 50, 60, 70, 80) {}

    // Вывод информации
    void print_info() override {
        Figure::print_info();
        std::cout << "Стороны: a=" << this->side_a << " b=" << this->side_b << " c=" << this->side_c << " d=" << this->side_d << std::endl;
        std::cout << "Углы: A=" << this->corner_a << " B=" << this->corner_b << " C=" << this->corner_c << " D=" << this->corner_d << std::endl;
    }
protected:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) {
        this->side_a = a; this->side_b = b; this->side_c = c; this->side_d = d;
        this->corner_a = A; this->corner_b = B; this->corner_c = C; this->corner_d = D;
        this->sides = 4;
        this->name = "Четырехугольник";
    }

    bool check() override {
        if ((this->sides == 4) && ((this->side_a != this->side_b) && (this->side_b != this->side_c) && (this->corner_d != this->side_a)) && ((this->corner_a + this->corner_b + this->corner_c + this->corner_d) == 360))
            return true;
        return false;
    }

    // Стороны
    int side_a, side_b, side_c, side_d;
    // Углы
    int corner_a, corner_b, corner_c, corner_d;
};

class Rectangle : public Quadrilateral {
public:
    Rectangle() : Rectangle(10, 20) {}

    void print_info() override { Quadrilateral::print_info(); }
protected:
    bool check() override {
        if ((this->side_a == this->side_c) && (this->side_b == this->side_d) && ((this->corner_a, this->corner_b, this->corner_c, this->corner_d) == 90))
            return true;
        return false; 
    }

    Rectangle(int ac, int bd) : Quadrilateral(ac, bd, ac, bd, 90, 90, 90, 90) {
        this->name = "Прямоугольник";
    }
};

class Square : public Rectangle {
public:
    Square() : Square(20) {}

    void print_info() override {
        Rectangle::print_info();
    }
protected:
    bool check() override {
        if (((this->side_a, this->side_b, this->side_c) == this->side_d))
            return Rectangle::check();
        return false;
    }

    Square(int abcd) : Rectangle(abcd, abcd) {
        this->name = "Квадрат";
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram() : Parallelogram(20, 30, 30, 40) {}

    void print_info() override {
        Quadrilateral::print_info();
    }
protected:
    bool check() override {
        if ((this->side_a == this->side_c) && (this->side_b == this->side_d) && (this->corner_a == this->corner_c) && (this->corner_b == this->corner_d))
            return Quadrilateral::check();
        return false;
    }

    Parallelogram(int ac, int bd, int AC, int BD) : Quadrilateral(ac, bd, ac, bd, AC, BD, AC, BD) {
        this->name = "Параллелограмм";
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus() : Rhombus(30, 40) {}

    void print_info() { Parallelogram::print_info(); }
private:
    bool check() override {
        if ((this->side_a, this->side_b, this->side_c) == this->side_d)
            Parallelogram::check();
        return false;
    }

    Rhombus(int AC, int BD) : Parallelogram(30, 30, AC, BD) {
        this->name = "Ромб";
    }
};

int main(void) {
    setlocale(LC_ALL, "Rus");

    Figure f;
    f.print_info();

    Triangle t;
    Figure* ft = &t;
    ft->print_info();

    RightTriangle rt;
    Figure* rtf = &rt;
    rtf->print_info();

    IsoscelesTriangle it;
    Figure* itf = &it;
    itf->print_info();

    EquilateralTriangle et;
    Figure* etf = &et;
    etf->print_info();

    // Четырехугольники
    Quadrilateral q;
    Figure* qf = &q;
    qf->print_info();

    Rectangle r;
    Figure* rf = &r;
    rf->print_info();

    Square s;
    Figure* sf = &s;
    sf->print_info();

    Parallelogram p;
    Figure* pf = &p;
    pf->print_info();

    Rhombus rh;
    Figure* rhf = &rh;
    rhf->print_info();

    return 0;
}