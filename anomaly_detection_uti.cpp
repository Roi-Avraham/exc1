//**********************
//* Name:Roi Avraham and Shira Goren
//* Id: 318778081
//**********************
#include <iostream>
//returns the variance of X and Y
float var(float* x, int size) {
    float variance;
    float sum;
    for(int i=0; i<size; i++) {
        sum += (x[i] * x[i]);
    }
    float sum2 =  sum * (1.0/size);
    float sum3 = 0;
    float m;
    for(int i=0; i<size; i++) {
        sum3 += (x[i]);
    }
    m = sum3 * (1.0/size);
    variance = sum2 - (m * m);
    return variance;
}
float E(float* x, int size) {
    float sum;
    float m;
    for(int i=0; i<size; i++) {
        sum += (x[i]);
    }
    m = (1/size) * sum;
    return m;
}
// returns the covariance of X and Y
float cov(float* x, float* y, int size){
    float ex = E(x, size);
    float ey = E(y, size);
    float sum = 0;
    for(int i=0; i<size; i++) {
        sum += ((x[i] - ex) * (y[i] - ey));
    }
    float covariance = sum * (1/size);
    return covariance;
}
// returns the Pearson correlation coefficient of X and Y
float pearson(float* x, float* y, int size) {
    float covariance = cov(x, y, size);
    float sigmaX = sqrt(double(var(x, size)));
    float sigmaY = sqrt(double(var(y, size)));
    float p = covariance / (sigmaX * sigmaY);
    return p;
}
class Line{
public:
    float a,b;
    Line():a(0),b(0){}
    Line(float a, float b):a(a),b(b){}
    float f(float x){
        return a*x+b;
    }
};
class Point{
public:
    float x,y;
    Point(float x, float y):x(x),y(x){}
    float getX(){return x;};
    float getY(){return y;};
};
// performs a linear regression and return s the line equation
Line linear_reg(Point** points, int size) {
    float* x;
    float* y;
    float a;
    float b;
    for(int i = 0;i< size; i++) {
        x[i] = points[i]->getX();
        y[i] = points[i]->getY();
    }
    a = cov(x, y, size) / var(x, size);
    float aveX = E(x,size);
    float aveY = E(y, size);
    b = aveY - (a * aveX);
    return Line(a, b);
}
// returns the deviation between point p and the line equation of the points
float dev(Point p,Point** points, int size) {
    Line line = linear_reg(points, size);
    float f = line.f(p.getX());
    float deviation = abs(f - p.getY());
    return deviation;
}
// returns the deviation between point p and the line
float dev(Point p,Line l) {
    float f = l.f(p.getX());
    float deviation = abs(f - p.getY());
    return deviation;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

