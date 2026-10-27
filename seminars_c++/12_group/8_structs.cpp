#include <iostream>


struct Point2D {
    int x = 0;
    int y = 0;
};


void PrintPoint2D(const Point2D& p) {
    std::cout << '(' << p.x << ';' << p.y << ")\n";
}


struct Triangle {
    Point2D a, b, c;
};


bool IsPointInTriangle(const Triangle& t, const Point2D& p);


struct S {
    double y;
    int x;
};


int main() {
    Point2D pp;
    Point2D p{7,7};
    // std::cout << p.x; // UB
    p.x = 5;
    p.y = 4;
    // std::cout << p.x; // 5
    PrintPoint2D(p);
    PrintPoint2D(pp);
    std::cout << sizeof(p);
    
    S s;
    std::cout << sizeof(s);
    return 0;
}



