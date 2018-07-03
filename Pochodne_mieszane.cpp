#include <iostream>
#include <cmath>

template <typename T>
T funkcja (const T & x , const T & y ) ;
//----------------------------------------------------------------------
class Vec {
    public:
        Vec() { value = 1.0; x = y = xy = yy = xx = 0.0; }
        Vec(float x) { this->value = x; this->x = 1.0; y = xy = yy = xx = 0.0; }
        Vec(const Vec& v) { this->value = v.value; this->x = v.x; this->y = v.y; this->xx = v.xx; this->xy = v.xy; this-> yy = v.yy; }
        ~Vec() {}
        /*
            *\/*\/* Other  stuff *\/*\/*
                                            */
        Vec operator=(const Vec& v) {
            Vec temp;
            temp.value = v.value; temp.x = v.x;
            temp.y = v.y; temp.xx = v.xx; 
            temp.xy = v.xy; temp.yy = v.yy;
            //std::cout << " :1: " << temp.value;
            return temp;
        }
        Vec operator=(float v) {
            Vec temp;
            temp.value = v;
            temp.x = temp.y = temp.xx = temp.xy = temp.yy = 0;
            //std::cout << " :2: " << temp.value;
            return temp;
        }
        
    //private:
        float value, x, y, xx, xy, yy;
};
//----------------------------------------------------------------------
std::ostream& operator<< (std::ostream& os, const Vec& V3) {
            os << V3.value << " " << V3.x <<
                " " << V3.y << " " << V3.xx << " " <<
                V3.xy << " " << V3.yy << "\n";
            return os;
        }
//----------------------------------------------------------------------
        
        Vec operator+(const Vec& t, const Vec& v) {
            Vec temp;
            temp.value = v.value + t.value; temp.x = v.x + t.x;
            temp.y = v.y + t.y; temp.xx = v.xx + t.xx; 
            temp.xy = v.xy + t.xy; temp.yy = v.yy + t.yy;
            return temp;
        }
        Vec operator-(const Vec& t, const Vec& v) {
            Vec temp;
            temp.value = t.value - v.value; temp.x = t.x - v.x;
            temp.y = t.y - v.y; temp.xx = t.xx - v.xx; 
            temp.xy = t.xy - v.xy; temp.yy = t.yy - v.yy;
            return temp;
        }
        Vec operator*(const Vec& t, const Vec& v) {
            Vec temp(v.value * t.value);
            temp.x = t.value*v.x + t.x*v.value;
            temp.y = t.value*v.y + t.y*v.value;
            temp.xx = 2*t.x*v.x + t.value*v.xx + v.value*t.xx;
            temp.xy = t.value * v.value * v.x * t.y + 
                    t.value * t.value * v.x * v.y +
                    t.x * v.value * t.value * v.y +
                    t.x * v.value * v.value * t.y;
            temp.yy = 2*t.y*v.y + t.value*t.yy + t.value*v.yy;
            //std::cout << " :3: " << temp.value;
            return temp;
        }
        Vec operator/(const Vec& u, const Vec& v) {
            Vec temp;
            temp.value /= v.value;
            temp.x = (u.x - (u.value/v.value)*v.x)/v.value;
            temp.y = (u.y - (u.value/v.value)*v.y)/v.value;
            temp.xx = (u.xx * v.value) / pow(v.value, 2) - (u.value * v.xx) / pow(v.value, 2) - (temp.x * 2 * v.x) / v.value;
            temp.xy = (u.xy * v.value) / pow(v.value, 2) + (u.x * v.y) / pow(v.value, 2) - (u.y * v.x) / pow(v.value, 2) - (u.value * v.xy) / pow(v.value, 2) - (temp.x * 2 * v.y) / v.value;
            temp.yy = (u.yy * v.value) / pow(v.value, 2) - (u.value * v.yy) / pow(v.value, 2) - (temp.y * 2 * v.y) / v.value;
            return temp;
        }
        
        Vec operator+(const Vec& t, float v) {
            Vec temp;
            temp.value = t.value + v;
            temp.x = t.x;
            temp.y = t.y;
            temp.xx = t.xx;
            temp.xy = t.xy;
            temp.yy = t.yy;
            return temp;
        }
        Vec operator-(const Vec& t, float v) {
            Vec temp;
            temp.value = t.value - v;
            temp.x = t.x;
            temp.y = t.y;
            temp.xx = t.xx;
            temp.xy = t.xy;
            temp.yy = t.yy;
            return temp;
        }
        Vec operator*(const Vec& t, float v) {
            Vec temp;
            temp.value = t.value * v;
            temp.x = t.x * v;
            temp.y = t.y * v;
            temp.xx = t.xx * v;
            temp.xy = t.xy * v;
            temp.yy = t.yy * v;
            //std::cout << " :5: " << temp.value;
            return temp;
        }
        Vec operator/(const Vec& t, float v) {
            Vec temp;
            temp.value = t.value / v;
            temp.x = t.x / v;
            temp.y = t.y / v;
            temp.xx = t.xx / v;
            temp.xy = t.xy / v;
            temp.yy = t.yy / v;
            return temp;
        }
        Vec operator-(const Vec& t) {
            Vec temp;
            temp.value = -t.value; temp.x = -t.x; temp.y = -t.y;
            temp.xx = -t.xx; temp.xy = -t.xy; temp.yy = -t.yy;
            return temp;
        }
//----------------------------------------------------------------------
Vec operator+(float v, const Vec& temp) {
    Vec temp2(v);
    temp2.x = 0;
    temp2 = temp2 + temp;
    return temp2;
}

Vec operator-(float v, const Vec& temp) {
    Vec temp2(v);
    temp2.x = 0;
    temp2 = temp2 - temp;
    return temp2;
}

Vec operator*(float v, const Vec& temp) {
    return temp * v;
}

Vec operator/(float v, const Vec& temp) {
    Vec temp2(v);
    temp2.x = 0;
    temp2 = temp2 / temp;
    return temp2;
}
//----------------------------------------------------------------------
Vec sin(const Vec& v){
    Vec temp;
    temp.x = v.x * cos(v.value);
    temp.y = v.y * cos(v.value);
    temp.xy = v.xy * cos(v.value);
    temp.yy = v.yy * cos(v.value);
    temp.xx = v.xx * cos(v.value);
    temp.value = sin(v.value);
    return temp;
}
Vec cos(const Vec& v){
    Vec temp;
    float sinV = -sin(v.value);
    temp.x = v.x * sinV;
    temp.y = v.y * sinV;
    temp.xy = v.xy * sinV;
    temp.yy = v.yy * sinV;
    temp.xx = v.xx * sinV;
    temp.value = cos(v.value);
    return temp;
}
Vec exp(const Vec& v){
    Vec temp;
    temp.value = exp(v.value);
    temp.x = v.x * temp.value;
    temp.y = v.y * temp.value;
    temp.xy = v.xy * temp.value;
    temp.yy = v.yy * temp.value;
    temp.xx = v.xx * temp.value;
    return temp;
}

//----------------------------------------------------------------------

template <typename T>
T funkcja(const T & x, const T & y){
    T w = sin(x*x - 2*(y+1))/exp(-y*y+cos(x*y));
    return w;
} 


int main() {
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        float x, y;
        std::cin >> x >> y;
        Vec V1(x);
        Vec V2(y);
        V2.x = 0;
        V2.y = 1;
        std::cout << V2+1 << std::endl;
        std::cout << 2*(V2+1) << std::endl;
        std::cout << V1*V1 << std::endl;
        std::cout << V1*V1-2*(V2+1) << std::endl;
        std::cout << sin(V1*V1-2*(V2+1)) << std::endl;
        std::cout << V1*V2 << std::endl;
        std::cout << cos(V1*V2) << std::endl;
        std::cout << -V2 << std::endl;
        std::cout << -V2*V2 << std::endl;
        std::cout << -V2*V2 + cos(V1*V2) << std::endl;
        std::cout << exp(-V2*V2 + cos(V1*V2)) << std::endl;
        std::cout << std::endl;
        Vec V3 = funkcja(V1, V2);
        std::cout << V3 << std::endl;
    }
    return 0;
}