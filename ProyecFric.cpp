#include <iostream>
#include <cmath>
using namespace std;

// Basado en método visto en Lab. Métodos Computacionales

// variable constantes globales
const double DeltaT = 0.0001;
const double g = 9.8;

// declaracion de funciones
double f0a(double y1); // derivada de y0
double f1a(double K, double y1, double x1); // derivada de y1 (y1 velovidad en y)
double f0b(double x1); // derivada de x0
double f1b(double K, double x1, double y1); // derivada de x1 (x1 velovidad en x)
void rk4(double K, double h, double & y0, double & y1, double & x0, double & x1); // metodo de runge kutta 4 orden

int main(int argc, char **argv)
{
	double K;
	if(atoi(argv[1]) == 1)
		K = 0.7;
	else
		K = 0;
    double x, vx, y, vy, time;
    x = 0;
    vx = 10;
    y = 0;
    vy = 10;
    for(time = 0; time <= 2; time += DeltaT)
    {
        cout << "\t" << x << "\t" << y << endl;
        rk4( K, DeltaT, y, vy, x, vx );
    }
    
    return 0;
}

double f0a(double y1)
{
    return y1;
}

double f1a(double K, double y1, double x1)
{
    return -g-K*y1*y1/sqrt(y1*y1 + x1*x1);
}

double f0b(double x1)
{
    return x1;
}

double f1b(double K, double x1, double y1)
{
    return -K*x1*x1/sqrt(y1*y1 + x1*x1);
}

void rk4(double K, double h, double & y0, double & y1, double & x0, double & x1) // metodo de runge kutta 4 orden
{
    double k10a, k11a, k20a, k21a, k30a, k31a, k40a, k41a, k10b, k11b, k20b, k21b, k30b, k31b, k40b, k41b;
    k10a = h*f0a(y1);
    k11a = h*f1a(K, y1, x1);
    
    k10b = h*f0b(x1);
    k11b = h*f1b(K, x1, y1);
    
    k20a = h*f0a(y1 + k11a/2);
    k21a = h*f1a(K, y1 + k11a/2, x1 + k11b/2);
    
    k20b = h*f0b(x1 + k11b/2);
    k21b = h*f1b(K, x1 + k11b/2, y1 + k11a/2);
    
    k30a = h*f0a(y1 + k21a/2);
    k31a = h*f1a(K, y1 + k21a/2, x1 + k21b/2);
    
    k30b = h*f0b(x1 + k21b/2);
    k31b = h*f1b(K, x1 + k21b/2, y1 + k21a/2);
    
    k40a = h*f0a(y1 + k31a);
    k41a = h*f1a(K, y1 + k31a, x1 + k31b);
    
    k40b = h*f0b(x1 + k31b);
    k41b = h*f1b(K, x1 + k31b, y1 + k31b);
    
    y0 = y0 + (1.0/6.0)*(k10a + 2*k20a + 2*k30a + k40a);
    y1 = y1 + (1.0/6.0)*(k11a + 2*k21a + 2*k31a + k41a);
    
    x0 = x0 + (1.0/6.0)*(k10b + 2*k20b + 2*k30b + k40b);
    x1 = x1 + (1.0/6.0)*(k11b + 2*k21b + 2*k31b + k41b);
}