#include <iostream>

class Vector3D {
public:
    double x, y, z;

    Vector3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

    friend bool operator==(const Vector3D& v1, const Vector3D& v2);
    friend bool operator!=(const Vector3D& v1, const Vector3D& v2);
};

bool operator==(const Vector3D& v1, const Vector3D& v2) {
    return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
}

bool operator!=(const Vector3D& v1, const Vector3D& v2) {
    return !(v1 == v2);
}

int main() {
    Vector3D v1(1, 2, 3);
    Vector3D v2(1, 2, 3);
    Vector3D v3(4, 5, 6);

    if (v1 == v2) {
        std::cout << "Wektory v1 i v2 sa rowne" << std::endl;
    } else {
        std::cout << "Wektory v1 i v2 nie sa rowne" << std::endl;
    }

    if (v1 != v3) {
        std::cout << "Wektory v1 i v3 sa rowne" << std::endl;
    } else {
        std::cout << "Wektory v1 i v3 nie sa rowne" << std::endl;
    }

    return 0;
}
