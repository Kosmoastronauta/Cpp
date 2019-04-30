#include <iostream>
#include <ctime>
#include <cstdlib>
#include "polynomial.hpp"
using namespace std;

int main()
{
    double ratio[5+1];
    double ratio2[5];
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        ratio[i] = rand() % 100;
    }
    
    
    Polynomial p2 = Polynomial(4, ratio);
  //  cout << p2;
   // cout << p2[2] << endl;
   // cout << p2;
     for (int i = 0; i < 5; i++)
    {
        ratio2[i] = rand() % 100;
    }
    Polynomial p3 =Polynomial();
    Polynomial p1 = Polynomial(4, ratio2);
    cout << p3;
  
   // cin >> p1;
    cout << p1;
    cout << p2;
    p3 = p1 + p2;
    cout << p3;

    return 0;
}