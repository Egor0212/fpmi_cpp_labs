#include <iostream>


struct Point2D {
    int32_t x = 0;
    int32_t y = 0;
};


void PrintPoint2D(const Point2D& p) {
    std::cout << '(' << p.x << ';' << p.y << ")\n";
}


struct Triangle {
    Point2D a, b, c;
};


bool IsPointInTriangle(const Triangle& t, const Point2D p);


int main() {

    Point2D p; // (0;0)
    std::cout << p.x; // ?
    p.x = 8;
    p.y = 9;

    Point2D point{7, 7}; // aggregate initialization
    PrintPoint2D(point);

    Triangle t{Point2D{0, 0}, Point2D{1, 0}, Point2D{0, 1}};
    std::cout << t.a.x;
}
