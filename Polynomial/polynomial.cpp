#include "polynomial.hpp"



Polynomial::Polynomial() : n(0), a(new double [1])
{

}

Polynomial::Polynomial(int degree, const double ratio[]) : n(degree)
{
    if(degree<0)
        throw std::invalid_argument("Invalid degree");

    int degree1;
    this->a = new double[n + 1];
    for (int i = 0; i <= degree; i++)
    {
        this->a[i] = ratio[i];
        if(ratio[i]!=0)
            degree1 = i;
    }
    this->n = degree1;
}

Polynomial::Polynomial(initializer_list<double> ratio)
{
    int i = 0;
    this->a = new double[ratio.size()+1];
    int degree;
    for (auto it = ratio.begin(); it != ratio.end(); it++, i++)
    {
        if(*it!=0)
            {
                degree = i;
                this->a[i] = *it;
            }
        
    }
    this->n = degree;
}

Polynomial::Polynomial(const Polynomial &p)
{
    this->a = new double[p.n+1];
    for (int i = 0; i < p.n; i++)
    {
        this->a[i] = p.a[i];
    }
}

Polynomial::Polynomial(Polynomial &&p): n(p.n)
{
    delete[] this->a;
    this->a = p.a;
    p.n = 0;
    p.a = nullptr;
}

Polynomial &Polynomial::operator=(const Polynomial &p)
{
    this->n = p.n;
    delete[] this->a;
    this->a = new double[this->n+1];

    for (int i = 0; i <=this->n; i++)
    {
        this->a[i] = p.a[i];
    }

    return *this;
}

Polynomial &Polynomial::operator=(Polynomial &&p)
{
    this->n = p.n;
    p.n = 0;
    delete[] this->a;
    this->a = p.a;

    p.a = nullptr;
    return *this;
}

Polynomial::~Polynomial()
{
    this->n = 0;
    delete[] this->a;
}

Polynomial &Polynomial::operator+=(const Polynomial &p)
{
    int degree = 0;
    if (this->n >= p.n)
    {
        for (int i = 0; i <= p.n; i++)
        {
            this->a[i] += p.a[i];
            if(this->a[i]!=0)
            {
                degree = i;
            }
        }
    }

    else
    {
        double *temp = new double[p.n];

        for (int i = 0; i <= p.n; i++)
        {
            if(i<this->n)
            {
                temp[i] = this->a[i] + p.a[i];
                
            }

            else
            {
                temp[i] = p.a[i];
                
            }

            if(temp[i]!=0)
                    degree = i;
        }

        this->n = degree;
        delete[] this->a;
        this->a = new double[degree];
        for (int i = 0; i < degree; i++)
        {
            this->a[i] = temp[i];
        }
        delete[] temp;
    }
    return *this;
}

Polynomial &Polynomial::operator-=(const Polynomial &p)
{
    int degree = 0;
    if (this->n >= p.n)
    {
        for (int i = 0; i <= p.n; i++)
        {
            this->a[i] -= p.a[i];
            if(this->a[i]!=0)
                degree = i;
        }
    }

    else
    {
        double *temp = new double[p.n+1];

        for (int i = 0; i <=p.n; i++)
        {
            if(i<this->n)
            {
                temp[i] = this->a[i] - p.a[i];

            }

            else
            {
                temp[i] = -1*p.a[i];
            }


            if(temp[i]!=0)
                    degree = i;
        }

        this->n = degree;
        delete[] this->a;
        this->a = new double[degree+1];

        for (int i = 0; i < degree; i++)
        {
            this->a[i] = temp[i];
        }
        delete[] temp;
    }
    return *this;
}

Polynomial &Polynomial::operator*=(const Polynomial &p)
{
    double *temp = new double [this->n + p.n+1];
    int degree = 0;
    for (int i = 0; i <= this->n; i++)
    {
        for (int j = 0; j <= p.n; j++)
        {
            temp[i + j] += this->a[i] * p.a[j];
            if(temp[i+j]!=0 && i+j>degree)
                degree = i + j;

        }
    }

    delete[] this->a;
    this->a = new double[degree+1];
    for (int i = 0; i <= degree; i++)
    {
        this->a[i] = temp[i];
    }
    this->n = degree;

    return *this;
}

Polynomial &Polynomial::operator*=(double c)
{
    for (int i = 0; i < this->n; i++)
    {
        this->a[i] *= c;
    }

    return *this;
}

int Polynomial::Get_degree()
{
    return this->n;
}

void Polynomial::Set_degree(int i)
{
    if(n>=0)
    this->n = i;

    else
    {
        throw std::invalid_argument("Invalid degree");
    }
}

void Polynomial::Set_index(int i, double v)
{
    if(i<=this->n)
    {
        this->a[i] = v;
    }

    else
    {
        throw std::invalid_argument("Invalid degree");
    }
}

double Polynomial::Get_index(int i)
{
    if(i<=this->n)
    {
        return this->a[i];
    }

    else
    {
        throw std::invalid_argument("Invalid index");
    }
}

std::istream &operator>>(istream &in, Polynomial &p)
{
    cout << "Enter grade: ";
    in >> p.n;
    delete[] p.a;
    p.a = new double[p.n + 1];
    for (int i = 0; i <= p.n; i++)
    {
        cout << "Enter " << i << " ratio: ";
        in >> p.a[i];
    }
    return in;
}

std::ostream &operator<<(ostream &out, Polynomial &p)
{
    for (int i = p.n; i >=0; i--)
    {
        if(i==0)
        {
            out << p.a[i] << endl;
            continue;
        }
        out << p.a[i] << "x^" << i <<" + ";
    }
    return out;
}

Polynomial operator+(const Polynomial &u, const Polynomial &v)
{
    Polynomial *temp = new Polynomial();
    if (u.n >= v.n)
    {
        temp->n = u.n;
        temp->a = new double[temp->n + 1];
        for (int i = 0; i <= u.n; i++)
        {
            temp->a[i] = u.a[i];
            if (i <= v.n)
            {
                temp->a[i] += v.a[i];
            }
        }
    }

    else
    {
        temp->n = v.n;
        temp->a = new double[temp->n + 1];
        for (int i = 0; i <= v.n; i++)
        {
            temp->a[i] = v.a[i];
            if (i <= u.n)
            {
                temp->a[i] += u.a[i];
            }
            
        }
    }
    
    cout << *temp;
  //  return *temp;
}

Polynomial operator-(const Polynomial &u, const Polynomial &v)
{
    Polynomial *temp = new Polynomial();
    
    int max;
    int degree;
    if (u.n >= v.n)
        max = u.n;

    else
        max = v.n;

    temp->a = new double[max+1];
    for (int i = 0; i < max; i++)
    {
        if(i<=u.n)
        {
            temp->a[i] = u.a[i];
        }

        if(i<=v.n)
        {
            temp->a[i] -= v.a[i];
        }
        
        if(temp->a[i]!=0)
            degree = i;
    }

    temp->n = degree;

    return *temp;
}

Polynomial operator*(const Polynomial &u, const Polynomial &v)
{
    Polynomial temp;
    temp.a = new double[u.n + v.n+1];
    int degree;

    for (int i = 0; i <= u.n; i++)
    {
        for (int j = 0; j <= v.n; j++)
        {
            temp.a[i + j] += u.a[i] * v.a[j];
            if(temp.a[i+i]!=0 && i+j>degree)
                degree = i + j;
        }Get_index
    }
    temp.n = degree;
    return temp;
}

Polynomial operator*(const Polynomial &u,const double c)
{
    Polynomial temp;
    temp.n = u.n;
    temp.a = new double[temp.n + 1];
    for (int i = 0; i <= u.n; i++)
    {
        u.a[i] *= c;
    }

    return temp;
}

double Polynomial::operator[](int i) const
{
    return this->a[i];
}

double& Polynomial::operator[](int i)
{

    return this->a[i];
}

double Polynomial::operator()(double x) const
{
    double temp = 0;

    for (int i = 0; i <= this->n; i++)
    {
        temp += x * temp + this->a[i];
    }

    return temp;
}
