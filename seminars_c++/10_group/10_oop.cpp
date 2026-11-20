#include <iostream>


class Point2D {
private:
    int32_t x;
    int32_t y;

public:

    //Point2D() {
    //    x = 0;
    //    y = 0;
    //}

    Point2D(int32_t new_x = 0, int32_t new_y = 0) {
        x = new_x;
        y = new_y;
    }

    int32_t GetX() const {
        return x;
    }

    int32_t GetY() const {
        return y;
    }
    
    void SetX(int32_t x) {
        // this (Point2D*) 
        // (*this).x = x;
        this->x = x;
    }

    void SetY(int32_t); // .h
    
    // (a += b) += c += c
    // a += b <=> a = a + b
    Point2D& operator+=(const Point2D& other) {
        *this = *this + other;
        //x += other.x;
        //y += other.y;
        return *this;
    }
    
    friend Point2D operator+(const Point2D&, const Point2D&);
};


void Point2D::SetY(int32_t new_y) { // .cpp
    y = new_y;
}


Point2D operator+(const Point2D& lhs, const Point2D& rhs) {
    //Point2D res = lhs;
    //res += rhs;
    //return res;
    return Point2D{lhs.x + rhs.x, lhs.GetY() + rhs.GetY()};
}

void PrintPoint2D(const Point2D& p) {
    std::cout << '(' << p.GetX() << ';' << p.GetY() << ")\n";
}

// (std::cout << p1) << p2 << p3
std::ostream& operator<<(std::ostream& out, const Point2D& p) {
    out << '(' << p.GetX() << ';' << p.GetY() << ")\n";
    return out;
}


int main() {

    Point2D p{}; // (0;0)
    p.SetX(8); //p.x = 8;
    p.SetY(9); //p.y = 9;
    PrintPoint2D(p);

    Point2D point{7, 7}; // Point2D point(7, 7);
    PrintPoint2D(point);

    Point2D sum = p + point;
    //PrintPoint2D(sum);
    std::cout << sum;
}
