#include <iostream>

class Figure {
public:
	Figure() { sides_count = 0; name = "Фигура"; }
	int get_sides_count() { return sides_count; }
	std::string get_name_figure() { return name; }
protected:
	int sides_count;
	std::string name;
};

class Trinagle : public Figure {
public:
	Trinagle() { sides_count = 3; name = "Треугольник"; }
};

class Quadrangle : public Figure {
public:
	Quadrangle() { sides_count = 4; name = "Прямоугольник"; };
	//int get_sides_count() { return sides_count; }
};

int main(void) {
	//setlocale(LC_ALL, "Rus");
	Figure F;
	std::cout << "Количество сторон: \n";
	std::cout << F.get_name_figure() << ": " << F.get_sides_count() << std::endl;

	Trinagle T;
	std::cout << T.get_name_figure() << ": " << T.get_sides_count() << std::endl;

	Quadrangle Q;
	std::cout << Q.get_name_figure() << ": " << Q.get_sides_count() << std::endl;

	return 0;
}