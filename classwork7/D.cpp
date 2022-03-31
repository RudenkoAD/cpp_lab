#include <iostream>
#include <math.h>

struct vect{
    double x;
    double y;
    vect(){
        x=0;
        y=0;
    }
    vect(double ix, double iy){
        x=ix;
        y=iy;
    }
    vect operator+ (vect other){
        return vect(x+other.x, y+other.y);
    }
    vect operator- (vect other){
        return vect(x-other.x, y-other.y);
    }
    double operator* (vect other){
        return (x*other.y-y*other.x);
    }
    double abs(){
        return sqrt(pow(x,2)+ pow(y, 2));
    }
    double project(vect other){
        return (other.x*x+other.y*y)/abs();
    }
};

struct road{
    vect p1;
    vect p2;
    double length = (p2-p1).abs();

    road(double a, double b, double c, double d){
        p1 = vect(a, b);
        p2 = vect(c, d);
    }

    double calc_poly(vect v){
        return (v-p1)*(p2-p1)/((p2-p1).abs());
    }

    double project(vect v){
        return (p2-p1).project(v-p1);
    }
};

bool intersect(road a, road b){
    if (a.calc_poly(b.p1)*a.calc_poly(b.p2)>0) return true;
    if (b.calc_poly(a.p1)*b.calc_poly(a.p2)>0) return true;
    return((a.project(b.p1)<0 and a.project(b.p2)<0) or (a.project(b.p1)>a.length and a.project(b.p2)>a.length));
}//returns true is the roads do NOT intersect


int main(){
    int a, b, c, d;
    std::cin>>a>>b>>c>>d;
    road road1 = road(a, b, c, d);
    std::cin>>a>>b>>c>>d;
    road road2 = road(a, b, c, d);
    std::cout<<intersect(road1, road2);
}