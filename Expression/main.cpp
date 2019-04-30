    #include <iostream>
    #include "expression.hpp"
    //Mateusz Gil
    int main()
    {
        try{

        
        Expression *e1 = new Pi();
    
    Expression *e2 = new Sub(new Pi(), new Add(new Ln(new Number(3.0)), new Fi()));
    cout << e2->description() << endl;
    
    Variable *v1;


    //(3+5)/(2+x*7)
    Expression *e4 = new Div(new Add(new Number(3), new Number(5)), new Add(new Number(2), new Mult(new Variable("x"), new Number(7))));

        //2+x*7-(y*3+5)
    Expression *e5 = new Add(new Number(2), new Sub(new Mult(new Variable("x"), new Number(7)), new Add(new Mult(new Variable("x"), new Number(3)), new Number(5))));
        
        //cos((x+1)*x)/e^x^2
        Expression *e6 = new Div(new Cos(new Mult(new Add(new Variable("x"),new Number(1)),new Variable("x"))),new Pow(new E(),new Pow(new Variable("x"),new Number(2))));

        cout << e4->description() << endl;
        cout << e5->description() << endl;
        cout << e6->description() << endl;
        for (double i = 0.1; i <= 1; i += 0.01)
        {
            v1->setValue("x", i);
            //cout << i << endl;
            cout << v1->getValue("x") << endl;
            ///  cout << "First: " << e4->calc() << endl;
            //  cout << "Second: " << e5->calc() << endl;
            //  cout << "Third: " << e6->calc() << endl;
        }
        }
        catch(...){}
        return 0;
    }
