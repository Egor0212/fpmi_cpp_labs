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


bool IsPointInTriangle(const Triangle& t, const Point2D& p);


int main() {

    Point2D p;
    std::cout << p.x; // 0
    p.x = 12;
    p.y = 7;

    Point2D point{78, 78};
    PrintPoint2D(point);

    Point2D* ptr_point = &point;
    std::cout << ptr_point->x; // (*ptr_point).x

    Triangle t{Point2D{0, 0}, Point2D{1, 0}, Point2D{0, 1}};

}
