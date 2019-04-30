#include <string>
#include "cmath"
#include <stdexcept>
#include <vector>
#include <utility>
//Mateusz Gil
using namespace std;

class Expression
{
    public:
      virtual double calc() =0;
      virtual string description() =0;
};

class Constant : public Expression
{
    protected:
      const double value;

      public:
        Constant(double );
        virtual string description() = 0;
        virtual double calc()=0;
};

class Pi : public Constant
{

    public:
      
      double calc();
      string description();
      Pi();
      
};

class Fi : public Constant
{

    public:
      double calc();
      string description();
      Fi();
     // ~Fi();
};

class E : public Constant
{

    public:
      double calc();
      string description();
      E();
      //~E();
};

class Number : public Expression
{
        public:
          Number();
          Number(double x);
          string description();
          double calc();

        private:
          double value;
        
};

class Variable : public Expression
{
    private:
      string name;
       static vector< pair < string, double> > values;

    public:
      static double getValue(string name);
      static void setValue(string name, double x);
      static void setName(string name);
      Variable(string name);
      double calc();
      string description();
      double Size();
};

class OneArgOperator : public virtual Expression
{
    public:
      OneArgOperator(Expression *e1);
      double calc();
      string description();

    protected:
      Expression *e1;

};

class Sin : public Expression
{
    public:
      double calc();
      string description();
      Sin(Expression *e1);

    private:
      Expression *e;
};

class Cos : public Expression
{
    public:
      double calc();
      string description();
      Cos(Expression *e);

    private:
      Expression *e;

};

class Exp : Expression
{
    public:
      double calc();
      string description();
      Exp(Expression *e1);

    private:
      Expression *e;
};

class Ln : public Expression
{
    public:
      double calc();
      string description();
      Ln(Expression *e);

    private:
      Expression *e;
};

class Abs :  public Expression
{
    public:
      double calc();
      string description();
      Abs(Expression *e);

    private:
      Expression *e;
};

class Opposite :  public Expression
{
    public:
      double calc();
      string description();
      Opposite(Expression *e);

    private:
      Expression *e;
};

class Resiprocal : public Expression // Odwrotna
{   
    public:
      double calc();
      string description();
      Resiprocal(Expression *e);
    
    private:
      Expression *e;
};

class TwoArgOperator : Expression
{
    private:
       // Expression e1;
       // Expression e2;
    public:
      TwoArgOperator(Expression *e1, Expression *e2);
      double calc();
      string description();
};

class Add :  public Expression
{
    public:
      double calc();
      string description();
      Add(Expression *e1, Expression *e2);

    private:
      Expression *e1, *e2;
};

class Sub :  public Expression
{

    public:
      double calc();
      string description();
      Sub(Expression *e1, Expression *e2);

    private:
      Expression *e1, *e2;
};

class Mult : public Expression
{
    public:
      double calc();
      string description();
      Mult(Expression *e1, Expression *e2);

    private:
      Expression *e1, *e2;
};

class Div : public Expression
{
    public:
      double calc();
      string description();
      Div(Expression *e1, Expression *e2);

    private:
      Expression *e1, *e2;
};

class Log : public Expression
{
    public:
      double calc();
      string description();
      Log(Expression *e1, Expression *e2);

    private:
      Expression *e1, *e2;
};

class Mod : public Expression
{
    public:
      double calc();
      string description();
      Mod(Expression *e1, Expression *e2);

    private:
      Expression *e1, *e2;
};

class Pow : public Expression
{
    public:
      double calc();
      string description();
      Pow(Expression *e1, Expression *e2);

    private:
      Expression *e1, *e2;
};
