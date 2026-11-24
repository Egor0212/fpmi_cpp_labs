#include <cmath>
#include <iostream>


class Point2D {
private:
    int x;
    int y;

public:

    //Point2D() {
    //    x = 0;
    //    y = 0;
    //}
    
    // uder-definded ctor
    Point2D(int x = 0, int y = 0): x(x), y(y) { 
        //x = x_;
        //y = y_;
    }

    
    int GetX() const {
        return x;
    }
    int GetY() const {
        return y;
    }

    void SetX(int x) {
        // (*this).x = x;
        this->x = x;
    }

    void SetY(int new_y) {
        y = new_y;
    }

    double DistanceFromZero() const; // .h or .hpp
    
    // a += (b += (c += d))
    Point2D& operator+=(const Point2D& other) {
        *this = *this + other; // *this = operator+(Point2D, Point2D);
        //x += other.x;
        //y += other.y;
        return *this;
    }

    friend Point2D operator+(const Point2D&, const Point2D&);
    friend std::ostream& operator<<(std::ostream&, const Point2D&);
};

double Point2D::DistanceFromZero() const { // .cpp
    return std::sqrt(x * x + y * y);
}

Point2D operator+(const Point2D& lhs, const Point2D& rhs) {
    //Point2D copy = lhs;
    //copy += rhs;
    //return copy;

    return Point2D{lhs.GetX() + rhs.GetX(), lhs.GetY() + rhs.GetY()};
}



void PrintPoint2D(const Point2D& p) {
    std::cout << '(' << p.GetX() << ';' << p.GetY() << ")\n";
}


std::ostream& operator<<(std::ostream& out, const Point2D& p) {
    out << '(' << p.x << ';' << p.y << ")\n";
    return out;
}


int main() {
    //Point2D p{7,7}; // aggregate initialization
    Point2D p{}; // Point2D()
    p.SetX(7);
    p.SetY(8);

    PrintPoint2D(p);

    Point2D p1(1, 1);
    PrintPoint2D(p1);
    std::cout << p1.DistanceFromZero();

    Point2D sum = p + p1;
    sum += p1;
    PrintPoint2D(sum);

    std::cout << p;
    return 0;
}



