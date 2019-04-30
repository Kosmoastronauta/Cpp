
#include <initializer_list>
#include <stdexcept>
#include <iostream>
using namespace std;
class Polynomial
{
    private:
      int n;
      double *a;

    public:
      Polynomial();                                     // create a monomial
      Polynomial(int degree, const double ratio[]);     // create a polynomial
      Polynomial(initializer_list<double> ratio);       // list of ratios (ratio - wspolczynnik)
      Polynomial(const Polynomial &p);                  // copying constructor
      Polynomial(Polynomial &&p);                       // transfering constructor
      Polynomial &operator=(const Polynomial &p);       // copying assignment
      Polynomial &operator=(Polynomial &&p);            // transfering assignment
      int Get_degree();                            
      void Set_degree(int i);
      double Get_index(int i);
      void Set_index(int i, double v);
      ~Polynomial();                                    // destructor

      friend Polynomial operator+(const Polynomial &u, const Polynomial &v);
      friend Polynomial operator-(const Polynomial &u, const Polynomial &v);
      friend Polynomial operator*(const Polynomial &u, const Polynomial &v);
      friend Polynomial operator*(const Polynomial &u, const double c);

      Polynomial &operator+=(const Polynomial &p);
      Polynomial &operator-=(const Polynomial &p);
      Polynomial &operator*=(const Polynomial &p);
      Polynomial &operator*=(double c);

      double operator()(double x) const; // calculate value for x
      double operator[](int i) const;    // read i-ratio
      double& operator[](int i);

      friend istream &operator>>(istream &in, Polynomial &p);
      friend ostream &operator<<(ostream &out, Polynomial &p);
};