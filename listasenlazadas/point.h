#ifndef POINT_H
#define POINT_H

template <class T>
class Point;

template <class T>
std::ostream& operator <<(std::ostream& o,Point<T> p){
    o<<"("<< p.x <<","<<p.y<<")";
    return o;
}

template <class T>
class Point{
private:
    T x,y;
public:
    Point(){}
    Point(T x,T y) {
        this->x=x;
        this->y=y;
    }
    bool operator <(Point<T>& a){
        return x<a.x;
    }

    bool operator ==(Point<T>& a){
        return (x==a.x && y==a.y);
    }

    bool operator !=(Point<T>& a){
        return (x!=a.x || y!=a.y);
    }
    friend std::ostream& operator << <>(std::ostream& o,Point<T> p);
};


#endif