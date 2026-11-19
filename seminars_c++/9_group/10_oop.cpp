#include <iostream>
#include <ostream>


class Point2D {
private:
    int32_t x;
    int32_t y;

public:

    Point2D() {
        x = 0;
        y = 0;
    }

    Point2D(int32_t p_x, int32_t p_y) {
        x = p_x;
        y = p_y;
    }

    int32_t GetX() const {
        return x;
    }
    
    int32_t GetY() const {
        return y;
    }

    void SetX(int32_t x) {
        //(*this).x = x;
        this->x = x;
    }
    
    void SetY(int32_t new_y) {
        y = new_y;
    }

    friend Point2D operator+(const Point2D&, const Point2D&);
    
    // (a += (b += (c += d)))
    // (a += b) += c
    Point2D& operator+=(const Point2D& other) {
        //*this = *this + other;
        x += other.x;
        y += other.y;
        return *this;
    }
};


void PrintPoint2D(const Point2D& p) {
    std::cout << '(' << p.GetX() << ';' << p.GetY() << ")\n";
}

Point2D operator+(const Point2D& lhs, const Point2D& rhs) {
    Point2D copy = lhs;
    copy += rhs;
    return copy;
    //return Point2D{lhs.x + rhs.x, lhs.GetY() + rhs.GetY()};
}

// (std::cout << p1) << p2 << p3 << ...
std::ostream& operator<<(std::ostream& out, const Point2D& p) {

    out << '(' << p.GetX() << ';' << p.GetY() << ")\n";
    return out;
}


int main() {

    Point2D p(1, 1);
    //p.x = 12;
    //p.y = 7;
    //p.SetX(7);
    //p.SetY(8);

    Point2D p1(78, 78); // aggregate initialization
    PrintPoint2D(p);
    
    Point2D sum = p + p1;
    sum += p;
    PrintPoint2D(sum);
    std::cout << p;

}
