// Example program
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

float accFunc(float x, float K, float L){
    return 0.5*log(x*x+x+K) + ( (L-0.5) /sqrt(K-0.25))*atan((x+0.5)/sqrt(K-0.25));
}

float func(float x, float K, float L){
  return (x+L)/(x*x+x+K);
}

int main(){
  float K = 3.8, L = 2.2;
  float a = (K-L)/2; 
  float b = K + L;
  cout << "Data:\n";
  cout << "a = " << a << ", b = " << b << ", K = " << K << ", L = " << L << "\n\n";
  
//Gauss
  float t4[4] = {-0.861136, -0.339981,0.339981, 0.861136};
  float A4[2] = {0.347854, 0.652145};

  float t6[6] = {-0.932464, -0.661209, -0.238619, 0.238619, 0.661209, 0.932464};
  float A6[3] = {0.171324, 0.360761, 0.467913};

  float t8[8] = {-0.960289, -0.796666, -0.525532, -0.183434, 0.183434, 0.525532, 0.796666, 0.960289};
  float A8[4] = {0.101228, 0.222381, 0.313706, 0.362683};

  cout << "Just calculations:\n";
  cout << accFunc(b, K, L) - accFunc(a, K, L) << "\n\n";

//Trapecium
    cout << "\n-------------------------------------------------------\n";
    cout << "Trapezium method (n = 4):\n";
      cout << "Count of intervals is eqaul to 4 with length ";
      float h = (b - a)/4;
      cout << "h = " << h << "\n\n";

      float x1 = a + 1 * h;
      cout << "x1 = " << x1 << "\n";
      float x2 = a + 2 * h;
      cout << "x2 = " << x2 << "\n";
      float x3 = a + 3 * h;
      cout << "x3 = " << x3 << "\n";

      cout << "f(a) = " << func(a, K, L) << "\n";
      cout << "f(x1) = " << func(x1, K, L) << "\n";
      cout << "f(x2) = " << func(x2, K, L) << "\n";
      cout << "f(x3) = " << func(x3, K, L) << "\n";
      cout << "f(b) = " << func(b, K, L) << "\n"; 

      cout << "\nResult (n = 4): " << (h/2) * (func(a, K, L) + 2*(func(x1, K, L) + func(x2, K, L) + func(x3, K, L)) + func(b, K, L));
  ////////////
    cout << "\nTrapezium method (n = 6):\n";
      h = (b - a)/6;
      cout << "h = " << h << "\n\n";

      x1 = a + 1 * h;
      cout << "x1 = " << x1 << "\n";
      x2 = a + 2 * h;
      cout << "x2 = " << x2 << "\n";
      x3 = a + 3 * h;
      cout << "x3 = " << x3 << "\n";
      float x4 = a + 4 * h;
      cout << "x4 = " << x4 << "\n";
      float x5 = a + 5 * h;
      cout << "x5 = " << x5 << "\n";

      cout << "f(a) = " << func(a, K, L) << "\n";
      cout << "f(x1) = " << func(x1, K, L) << "\n";
      cout << "f(x2) = " << func(x2, K, L) << "\n";
      cout << "f(x3) = " << func(x3, K, L) << "\n";
      cout << "f(x4) = " << func(x4, K, L) << "\n";
      cout << "f(x5) = " << func(x5, K, L) << "\n";
      cout << "f(b) = " << func(b, K, L) << "\n"; 

    cout << "\nResult (n = 6): " << (h/2) * (func(a, K, L) + 2*(func(x1, K, L) + func(x2, K, L) + func(x3, K, L) + func(x4, K, L) + func(x5, K, L)) + func(b, K, L));
  ////////////
    cout << "\nTrapezium method (n = 8):\n";
      h = (b - a)/8;
      cout << "h = " << h << "\n\n";

      x1 = a + 1 * h;
      cout << "x1 = " << x1 << "\n";
      x2 = a + 2 * h;
      cout << "x2 = " << x2 << "\n";
      x3 = a + 3 * h;
      cout << "x3 = " << x3 << "\n";
      x4 = a + 4 * h;
      cout << "x4 = " << x4 << "\n";
      x5 = a + 5 * h;
      cout << "x5 = " << x5 << "\n";
      float x6 = a + 6 * h;
      cout << "x6 = " << x6 << "\n";
      float x7 = a + 7 * h;
      cout << "x7 = " << x7 << "\n";

      cout << "f(a) = " << func(a, K, L) << "\n";
      cout << "f(x1) = " << func(x1, K, L) << "\n";
      cout << "f(x2) = " << func(x2, K, L) << "\n";
      cout << "f(x3) = " << func(x3, K, L) << "\n";
      cout << "f(x4) = " << func(x4, K, L) << "\n";
      cout << "f(x5) = " << func(x5, K, L) << "\n";
      cout << "f(x6) = " << func(x6, K, L) << "\n";
      cout << "f(x7) = " << func(x7, K, L) << "\n";
      cout << "f(b) = " << func(b, K, L) << "\n"; 

    cout << "\nResult (n = 8): " << (h/2) * (func(a, K, L) + 2*(func(x1, K, L) + func(x2, K, L) + func(x3, K, L) + func(x4, K, L) + func(x5, K, L) + func(x6, K, L) + func(x7, K, L)) + func(b, K, L));

//Simpson  
    cout << "\n-------------------------------------------------------\n";
    cout << "\nSimpson method (n = 4):\n";
    h = (b - a)/(2*4);
    cout << "h = " << h << "\n\n";

    x1 = a + 1 * h;
    cout << "x1 = " << x1 << "\n";
    x2 = a + 2 * h;
    cout << "x2 = " << x2 << "\n";
    x3 = a + 3 * h;
    cout << "x3 = " << x3 << "\n";
    x4 = a + 4 * h;
    cout << "x4 = " << x4 << "\n";
    x5 = a + 5 * h;
    cout << "x5 = " << x5 << "\n";
    x6 = a +  6 * h;
    cout << "x6 = " << x6 << "\n";
    x7 = a +  7 * h;
    cout << "x7 = " << x7 << "\n";

      cout << "f(a) = " << func(a, K, L) << "\n";
      cout << "f(x1) = " << func(x1, K, L) << "\n";
      cout << "f(x2) = " << func(x2, K, L) << "\n";
      cout << "f(x3) = " << func(x3, K, L) << "\n";
      cout << "f(x4) = " << func(x4, K, L) << "\n";
      cout << "f(x5) = " << func(x5, K, L) << "\n";
      cout << "f(x6) = " << func(x6, K, L) << "\n";
      cout << "f(x7) = " << func(x7, K, L) << "\n";
      cout << "f(b) = " << func(b, K, L) << "\n"; 

    cout << "\nResult (n = 4): " << (h/3) * (func(a, K, L) + func(b, K, L) + 2*(func(x2, K, L) + func(x4, K, L) + func(x6, K, L)) + 4*(func(x1, K, L) + func(x3, K, L) + func(x5, K, L) + func(x7, K, L)));
  ////////////
    cout << "\nSimpson method (n = 6):\n";
    h = (b - a)/(2*6);
    cout << "h = " << h << "\n\n";

    x1 = a + 1 * h;          cout << "x1 = " << x1 << "\n";
    x2 = a + 2 * h;          cout << "x2 = " << x2 << "\n";
    x3 = a + 3 * h;          cout << "x3 = " << x3 << "\n";
    x4 = a + 4 * h;          cout << "x4 = " << x4 << "\n";
    x5 = a + 5 * h;          cout << "x5 = " << x5 << "\n";
    x6 = a +  6 * h;         cout << "x6 = " << x6 << "\n";
    x7 = a +  7 * h;         cout << "x7 = " << x7 << "\n";
    float x8 = a +  8 * h;   cout << "x8 = " << x8 << "\n";
    float x9 = a +  9 * h;   cout << "x9 = " << x9 << "\n";
    float x10 = a +  10 * h; cout << "x10 = " << x10 << "\n";
    float x11 = a +  11 * h; cout << "x11 = " << x11 << "\n";

      cout << "f(a) = " << func(a, K, L) << "\n";
      cout << "f(x1) = " << func(x1, K, L) << "\n";
      cout << "f(x2) = " << func(x2, K, L) << "\n";
      cout << "f(x3) = " << func(x3, K, L) << "\n";
      cout << "f(x4) = " << func(x4, K, L) << "\n";
      cout << "f(x5) = " << func(x5, K, L) << "\n";
      cout << "f(x6) = " << func(x6, K, L) << "\n";
      cout << "f(x7) = " << func(x7, K, L) << "\n";
      cout << "f(x8) = " << func(x8, K, L) << "\n";
      cout << "f(x9) = " << func(x9, K, L) << "\n";
      cout << "f(x10) = " << func(x10, K, L) << "\n";
      cout << "f(x11) = " << func(x11, K, L) << "\n";
      cout << "f(b) = " << func(b, K, L) << "\n"; 

    float Result = (h/3) * (func(a, K, L) + func(b, K, L) + 2*(func(x2, K, L) + func(x4, K, L) + func(x6, K, L) + func(x8, K, L) + func(x10, K, L)) + 4*(func(x1, K, L) + func(x3, K, L) + func(x5, K, L) + func(x7, K, L)+ func(x9, K, L) + func(x11, K, L)));
    cout << "\nResult (n = 6): " << Result;
  ////////////
    cout << "\nSimpson method (n = 8):\n";
    h = (b - a)/(2*8);
    cout << "h = " << h << "\n\n";

    x1 = a + 1 * h;          cout << "x1 = " << x1 << "\n";
    x2 = a + 2 * h;          cout << "x2 = " << x2 << "\n";
    x3 = a + 3 * h;          cout << "x3 = " << x3 << "\n";
    x4 = a + 4 * h;          cout << "x4 = " << x4 << "\n";
    x5 = a + 5 * h;          cout << "x5 = " << x5 << "\n";
    x6 = a +  6 * h;         cout << "x6 = " << x6 << "\n";
    x7 = a +  7 * h;         cout << "x7 = " << x7 << "\n";
    x8 = a +  8 * h;   cout << "x8 = " << x8 << "\n";
    x9 = a +  9 * h;   cout << "x9 = " << x9 << "\n";
    x10 = a +  10 * h; cout << "x10 = " << x10 << "\n";
    x11 = a +  11 * h; cout << "x11 = " << x11 << "\n";
    float x12 = a +  12 * h; cout << "x12 = " << x12 << "\n";
    float x13 = a +  13 * h; cout << "x13 = " << x13 << "\n";
    float x14 = a +  14 * h; cout << "x14 = " << x14 << "\n";
    float x15 = a +  15 * h; cout << "x15 = " << x15 << "\n";

      cout << "f(a) = " << func(a, K, L) << "\n";
      cout << "f(x1) = " << func(x1, K, L) << "\n";
      cout << "f(x2) = " << func(x2, K, L) << "\n";
      cout << "f(x3) = " << func(x3, K, L) << "\n";
      cout << "f(x4) = " << func(x4, K, L) << "\n";
      cout << "f(x5) = " << func(x5, K, L) << "\n";
      cout << "f(x6) = " << func(x6, K, L) << "\n";
      cout << "f(x7) = " << func(x7, K, L) << "\n";
      cout << "f(x8) = " << func(x8, K, L) << "\n";
      cout << "f(x9) = " << func(x9, K, L) << "\n";
      cout << "f(x10) = " << func(x10, K, L) << "\n";
      cout << "f(x11) = " << func(x11, K, L) << "\n";
      cout << "f(x12) = " << func(x11, K, L) << "\n";
      cout << "f(x13) = " << func(x11, K, L) << "\n";
      cout << "f(x14) = " << func(x11, K, L) << "\n";
      cout << "f(x15) = " << func(x11, K, L) << "\n";
      cout << "f(b) = " << func(b, K, L) << "\n"; 

    Result = (h/3) * (func(a, K, L) + func(b, K, L) + 2*(func(x2, K, L) + func(x4, K, L) + func(x6, K, L) + func(x8, K, L) + func(x10, K, L)+func(x12, K, L) + func(x14, K, L)) + 4*(func(x1, K, L) + func(x3, K, L) + func(x5, K, L) + func(x7, K, L)+ func(x9, K, L) + func(x11, K, L) + func(x13, K, L) + func(x15, K, L)));
    cout << "\nResult (n = 8): " << Result;

//Gauss
    cout << "\n-------------------------------------------------------\n";
    cout << "Gauss method (n = 4):\n";
      h = (b - a)/4;
      cout << "h = " << h << "\n\n";
      
      x1 = (a+b)/2 + (b-a)*t4[0]*0.5; cout << "x1 = " << x1 << "\n";
      x2 = (a+b)/2 + (b-a)*t4[1]*0.5; cout << "x2 = " << x2 << "\n";
      x3 = (a+b)/2 + (b-a)*t4[2]*0.5; cout << "x3 = " << x3 << "\n";
      x4 = (a+b)/2 + (b-a)*t4[3]*0.5; cout << "x4 = " << x4 << "\n";

      cout << "f(x1) = " << func(x1, K, L) << "\n";
      cout << "f(x2) = " << func(x2, K, L) << "\n";
      cout << "f(x3) = " << func(x3, K, L) << "\n";
      cout << "f(x4) = " << func(x4, K, L) << "\n";  
      Result = ((b - a)*0.5)*(A4[0]*func(x1, K, L) + A4[1]*func(x2, K, L) + A4[1]*func(x3, K, L) + A4[0]*func(x4, K, L));
      cout << "\nResult (n = 4): " << Result;
    //////////
      cout << "\nGauss method (n = 6):\n";
      h = (b - a)/4;
      cout << "h = " << h << "\n\n";
      
      x1 = (a+b)/2 + (b-a)*t6[0]*0.5; cout << "x1 = " << x1 << "\n";
      x2 = (a+b)/2 + (b-a)*t6[1]*0.5; cout << "x2 = " << x2 << "\n";
      x3 = (a+b)/2 + (b-a)*t6[2]*0.5; cout << "x3 = " << x3 << "\n";
      x4 = (a+b)/2 + (b-a)*t6[3]*0.5; cout << "x4 = " << x4 << "\n";
      x5 = (a+b)/2 + (b-a)*t6[4]*0.5; cout << "x5 = " << x5 << "\n";
      x6 = (a+b)/2 + (b-a)*t6[5]*0.5; cout << "x6 = " << x6 << "\n";

      cout << "f(x1) = " << func(x1, K, L) << "\n";
      cout << "f(x2) = " << func(x2, K, L) << "\n";
      cout << "f(x3) = " << func(x3, K, L) << "\n";
      cout << "f(x4) = " << func(x4, K, L) << "\n";  
      cout << "f(x5) = " << func(x5, K, L) << "\n"; 
      cout << "f(x6) = " << func(x6, K, L) << "\n"; 

      Result = ((b - a)*0.5)*(A6[0]*func(x1, K, L) + A6[1]*func(x2, K, L) + A6[2]*func(x3, K, L) + A6[2]*func(x4, K, L) + A6[1]*func(x5, K, L) + A6[0]*func(x6, K, L));
      cout << "\nResult (n = 6): " << Result;

    //////////
      cout << "\nGauss method (n = 8):\n";
      h = (b - a)/4;
      cout << "h = " << h << "\n\n";
      
      x1 = (a+b)/2 + (b-a)*t8[0]*0.5; cout << "x1 = " << x1 << "\n";
      x2 = (a+b)/2 + (b-a)*t8[1]*0.5; cout << "x2 = " << x2 << "\n";
      x3 = (a+b)/2 + (b-a)*t8[2]*0.5; cout << "x3 = " << x3 << "\n";
      x4 = (a+b)/2 + (b-a)*t8[3]*0.5; cout << "x4 = " << x4 << "\n";
      x5 = (a+b)/2 + (b-a)*t8[4]*0.5; cout << "x5 = " << x5 << "\n";
      x6 = (a+b)/2 + (b-a)*t8[5]*0.5; cout << "x6 = " << x6 << "\n";
      x7 = (a+b)/2 + (b-a)*t8[6]*0.5; cout << "x7 = " << x7 << "\n";
      x8 = (a+b)/2 + (b-a)*t8[7]*0.5; cout << "x8 = " << x8 << "\n";

      cout << "f(x1) = " << func(x1, K, L) << "\n";
      cout << "f(x2) = " << func(x2, K, L) << "\n";
      cout << "f(x3) = " << func(x3, K, L) << "\n";
      cout << "f(x4) = " << func(x4, K, L) << "\n";  
      cout << "f(x5) = " << func(x5, K, L) << "\n"; 
      cout << "f(x6) = " << func(x6, K, L) << "\n"; 
      cout << "f(x7) = " << func(x7, K, L) << "\n"; 
      cout << "f(x8) = " << func(x8, K, L) << "\n"; 

      Result = ((b - a)*0.5)*(A8[0]*func(x1, K, L) + A8[1]*func(x2, K, L) + A8[2]*func(x3, K, L) + A8[3]*func(x4, K, L) + A8[3]*func(x5, K, L) + A8[2]*func(x6, K, L) + A8[1]*func(x7, K, L) + A8[0]*func(x8, K, L));
      cout << "\nResult (n = 8): " << Result;
}
