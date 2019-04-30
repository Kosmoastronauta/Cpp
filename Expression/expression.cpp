#include "expression.hpp"
// Mateusz Gil
vector< pair < string, double> > Variable::values;

Constant::Constant(double d ) : value(d){}

Pi::Pi() : Constant(3.141592653589793238462643383279)
{
}
double Pi::calc()
{
    return this->value;
}

string Pi::description()
{
    return "pi";
}

Fi::Fi(): Constant(1.618033988749894848)
{

}

double Fi::calc()
{
    return this->value;
}

string Fi::description()
{
    return "fi";
}
E::E() : Constant (2.718281828459045235360287471352662497757247094)
{

}

double E::calc()
{
    return this->value;
}

string E::description()
{
    return "e";
}

Number::Number(double x)
{
    this->value = x;
}

double Number::calc()
{
    return this->value;
}

string Number::description()
{
    return to_string(this->value);
}

Variable::Variable(string name)
{
    this->name = name;
   // setName(name);
}

string Variable::description()
{
    return this->name;
}

double Variable::getValue(string name)
{
    for (int i = 0; i < values.size(); i++)
    {
        if(values[i].first==name)
            return values[i].second;
    }
    return -1.0;
}

double Variable::Size()
{

    return values[1].second;
}

void Variable::setValue(string name, double x)
{
    bool b = true;

    for (int i = 0; i < values.size(); i++)
    {
        if(values[i].first==name)
            {
                values[i].second = x;
                b = false;
                break;
            }
    }
    if(b)
   {
       values.push_back(make_pair(name, x));
   } 
}

void Variable::setName(string name)
{
    values.push_back(make_pair(name, 0.0));
}
double Variable::calc()
{
    return getValue(this->name);
}

Sin::Sin(Expression *e1)
{
    this->e = e1;
}

double Sin::calc()
{
    return sin(this->e->calc());
}

string Sin::description()
{
    string temp = "sin(";
    temp += this->e->description();
    temp += ")";
    return temp;
}

Cos::Cos(Expression *e1): e(e1)
{
  //  this->e = e1;
}

double Cos::calc()
{
    return cos(this->e->calc());
}

string Cos::description()
{
    string temp = "cos(";
    temp += this->e->description();
    temp += ")";
    return temp;
}

Exp::Exp(Expression *e1): e(e1)
{

}

double Exp::calc()
{
    E *temp = new E();
    return exp(this->e->calc());
}

string Exp::description()
{
    string temp;
    temp = "e^";
    temp += this->e->description();
    temp += ')';
    return temp;

}

Ln::Ln(Expression *e): e(e)
{
}

double Ln::calc()
{
    return log(this->e->calc());
}

string Ln::description()
{
    string temp;
    temp = "Ln(";
    temp += this->e->description();
    temp += ")";
    return temp;
}

Abs::Abs(Expression *e): e(e)
{
   
}

double Abs::calc()
{
    return abs(this->e->calc());
}

string Abs::description()
{
    string temp;
    temp = '|';
    temp += this->e->description();
    temp += '|';
    return temp;
}

Opposite::Opposite(Expression *e): e(e)
{

}

double Opposite::calc()
{
    return -1 * this->e->calc();
}

string Opposite::description()
{
    string temp;
    temp = "-1(";
    temp += this->e->description();
    temp += ')';

    return temp;
}

Resiprocal::Resiprocal(Expression *e): e(e)
{

}


double Resiprocal::calc()
{
    if(this->calc()==0)
    {
        throw invalid_argument("Invalid syntax.");
    }
    return 1.0 / this->e->calc();
}

string Resiprocal::description()
{
    string temp;
    temp = "1/(";
    temp += this->e->description();
    temp += ')';
    return temp;
}

Add::Add(Expression *e1, Expression *e2): e1(e1), e2(e2)
{

}

double Add::calc()
{
    return this->e1->calc() + this->e2->calc();
}

string Add::description()
{
    string temp;
    temp = "(";
    temp += this->e1->description();
    temp += '+';
    temp += this->e2->description();
    temp += ')';
    return temp;
}

Sub::Sub(Expression *e1, Expression *e2): e1(e1), e2(e2)
{
    
}

double Sub::calc()
{
    return this->e1->calc() - this->e2->calc();
}

string Sub::description()
{
    string temp;
    temp = "(";
    temp += this->e1->description();
    temp += '-';
    temp += this->e2->description();
    temp += ')';
    return temp;
}

Mult::Mult(Expression *e1, Expression *e2): e1(e1), e2(e2)
{
  
}

double Mult::calc()
{
    return this->e1->calc() * this->e2->calc();
}

string Mult::description()
{
    string temp;
    temp = this->e1->description();
    temp += '*';
    temp += this->e2->description();
    return temp;
}

Div::Div(Expression *e1, Expression *e2)
{
  ///  if( e2->calc()==0)
     //   throw invalid_argument("Dividing by 0!!!");

    this->e1 = e1;
    this->e2 = e2;
}

double Div::calc()
{
    return this->e1->calc() / this->e2->calc();
}

string Div::description()
{
    string temp;
    temp = this->e1->description();
    temp += '/';
    temp += this->e2->description();
    return temp;
}

Log::Log(Expression *e1, Expression *e2)
{
     if(e1->calc() <= 0) 
        throw invalid_argument("Invalid base of logarithm!!!");

    this->e1 = e1;
    this->e2 = e2;
}

double Log::calc()
{
    return log(this->e1->calc()) / log(this->e2->calc());
}

string Log::description()
{
    string temp;
    temp = "Log(";
    temp += this->e1->description();
    temp += ',';
    temp += this->e2->description();
    temp += ')';
    return temp;
}

Mod::Mod(Expression *e1, Expression *e2): e1(e1), e2(e2)
{    
   
}

double Mod::calc()
{
    return (int)(this->e1->calc())%(int)(this->e2->calc());
}

string Mod::description()
{
    string temp;
    temp = '(';
    temp += this->e1->description();
    temp += ")%(";
    temp += this->e2->description();
    temp += ')';
    return temp;
}

Pow::Pow(Expression *e1, Expression *e2): e1(e1), e2(e2)
{    
  
}

double Pow::calc()
{
    return pow(this->e1->calc(), this->e2->calc());
}

string Pow::description()
{
    string temp;
    temp = '(';
    temp += this->e1->description();
    temp += ")^(";
    temp += this->e2->description();
    temp += ')';
    return temp;
}














