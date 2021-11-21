/*          C++ CALCULATOR USING MULTI-LEVEL INHERITANCE 
                1.SIMPLE CALCULATOR
                2.SCIENTIFIC CALCULATOR
                    Base class   : SimpleCalc
                    First Level  : ScientificCalc
                    Second Level : Calculator
*/

#include <iostream>
#include <cmath>
using namespace std;

								/*--- Class Declarations ---*/
class SimpleCalc;
class ScientificCalc;
class Calculator;

								/*--- Class Definitions ---*/
class SimpleCalc
{
protected: // protected variables can be inherited
    float num1, num2;
    float add, sub, prod, div, mod;

public:
    void addition();
    void subtraction();
    void product();
    void division();
    void modulus();
    void simplec(); // Function to select which funtion to call
};

class ScientificCalc : public SimpleCalc // ScientificCalc class inherited from the base class (SimpleCalc) -> (Single-level)
{
protected:
    float squ1, squ2;
    float exp1, exp2;
    float fact1, fact2;
    float sq1, sq2;
    float sin1,cos1,tan1,cosec1,sec1,cot1,log1;
    float sin2,cos2,tan2,cosec2,sec2,cot2,log2;
public:
    void square();
    void exponent();
    void factorial();
    void squareroot();
    void trigonometric();
    void trigDisplay();
    void scientific(); // Function to select which funtion to call
};

class Calculator : public ScientificCalc // Calculator class inherited from the class (ScientificCalc) -> (Multi-level)
{
public:
    void getvalue(); // taking two values from the user
    void choose();   // Function to choose simple or Scientific calculators
    void simpleRes();
    void scientificRes();
    void init();           // Initialize all the variables from all the classes to zero(0)
    void displayResults(); // Displaying the Results
};

							/* ---- FUNCTION DEFINIONS ----*/

							/* ----- SIMPLE CALCULATOR CLASS FUNCTIONS DEFINED -----*/

void SimpleCalc ::addition() // Function to add two numbers
{
    add = num1 + num2;
    cout << "Addition is : " << add << endl;
}

void SimpleCalc ::subtraction() //Function to Subtract two numbers
{
    sub = num1 - num2;
    cout << "Subtraction is : " << sub << endl;
}

void SimpleCalc ::product() // Function to Multiply two numbers
{
    prod = num1 * num2;
    cout << "Product is : " << prod << endl;
}

void SimpleCalc ::division() // Function to Divide two numbers
{
    div = num1 / num2;
    cout << "Divison  is : " << div << endl;
}

void SimpleCalc ::modulus() // Function to find the modulus of two numbers
{
    mod = int(num1) % int(num2); // Typecasting from float to integer (modulus operator works only with integer)
    cout << "Modulus is : " << mod << endl;
}

void SimpleCalc ::simplec() // Function to select which funtion to call
{
    int choice;

    system("CLS"); // clears the screen
    cout << endl
         << "1.Addition" << endl
         << "2.Subtraction" << endl
         << "3.Product" << endl
         << "4.Division" << endl
         << "5.Modulus" << endl
         << "6.Return" << endl;

    cout << "Enter your choice : ";
    cin >> choice;
    switch (choice)
    {
	    case 1: addition(); break;
	    case 2: subtraction(); break;
	    case 3: product(); break;
	    case 4: division(); break;
	    case 5: modulus(); break;
	    case 6: Calculator choose(); break; // calling the Function with reference to class
	    default: cout << "Invalid Choice!" << endl;
    }
}

						/*----- SCIENTIFIC CALCULATOR CLASS FUNCTIONS DEFINED -----*/

void ScientificCalc ::square() // Function to find the Square of numbers
{
    squ1 = num1 * num1;
    squ2 = num2 * num2;
    cout << "Square of " << num1 << " is: " << squ1 << endl;
    cout << "Square of " << num2 << " is: " << squ2 << endl;
}

void ScientificCalc ::exponent() // Function to find the exponent of numbers
{
    exp1 = pow(num1, num2); // Built in Function
    cout << "The Exponent of " << num1 << " raise to " << num2 << " is: " << exp1 << endl;
    exp2 = pow(num1, num2);
    cout << "The Exponent of " << num2 << " raise to " << num1 << " is: " << exp2 << endl;
}

void ScientificCalc ::factorial() // Function to find the Factorial of numbers
{
    // Factorial for number 1
    fact1 = 1.0;
    num1 = int(num1); // Type casting from float to integer (Factorial can't be calculated using float)
    num2 = int(num2);

    if (num1 == 0 || num1 == 1)
    {
        cout << "The Factorial of " << num1 << " is : 1" << endl;
    }
    else if (num1 > 1)
    {
        for (int i=1; i<=num1; i++)
        {
            fact1 *= i;
        }
        cout << "The Factorial of " << num1 << " is : " << fact1 << endl;
    }

    // Factorial for number 2
    fact2 = 1;
    if (num2 == 0 || num2 == 1)
    {
        cout << "The Factorial of " << num2 << " is : 1" << endl;
    }
    else if (num2 > 1)
    {
        for (int i=1; i<=num2; i++)
        {
            fact2 *= i;
        }
        cout << "The Factorial of " << num2 << " is : " << fact2 << endl;
    }
}

void ScientificCalc ::squareroot() // Function to find the Square root of numbers
{
    sq1 = sqrt(num1); // Built in funtion
    sq2 = sqrt(num2);
    cout << "The Square Root of " << num1 << " is : " << sq1 << endl;
    cout << "The Square Root of " << num2 << " is : " << sq2 << endl;
}

void ScientificCalc ::trigonometric() // Function to find the values of trigonometric function
{
    sin1 = sin(num1);
    sin2 = sin(num2);
    cos1 = cos(num1); cos2 = cos(num2);
    tan1 = tan(num1); tan2 = tan(num2);
    cosec1 = 1/sin1; cosec2 = 1/sin2;
    sec1 = 1/cos1; sec2 = 1/cos2;
    cot1 = 1/tan1; cot2 = 1/tan2;
    log1 = log(num1); log2 = log(num2);

    trigDisplay();
}

void ScientificCalc ::trigDisplay()
{
    cout << "sin (" << num1 << ") = " << sin1 << " and " << "sin (" << num2 << ") = " << sin2 << endl;
    cout << "cos (" << num1 << ") = " << cos1 << " and " << "cos (" << num2 << ") = " << cos2 << endl;
    cout << "tan (" << num1 << ") = " << tan1 << " and " << "tan (" << num2 << ") = " << tan2 << endl;
    cout << "cosec (" << num1 << ") = " << cosec1 << " and " << "cosec (" << num2 << ") = " << cosec2 << endl;
    cout << "sec (" << num1 << ") = " << sec1 << " and " << "sec (" << num2 << ") = " << sec2 << endl;
    cout << "cot (" << num1 << ") = " << cot1 << " and " << "cot (" << num2 << ") = " << cot2 << endl;
    cout << "log10 (" << num1 << ") = " << log1 << " and " << "log10 (" << num2 << ") = " << log2 << endl;
}

void ScientificCalc ::scientific() // Function to select which funtion to call
{
    int choice;

    system("CLS"); // clears the screen before printing next
    cout << endl
         << "1.Square" << endl
         << "2.Exponent" << endl
         << "3.Factorial" << endl
         << "4.Square Root" << endl
         << "5.Trigonometric Functions" << endl
         << "6.Return" << endl;

    cout << "Enter your choice : ";
    cin >> choice;
    switch (choice)
    {
	    case 1: square(); break;
	    case 2: exponent(); break;
	    case 3: factorial(); break;
	    case 4: squareroot(); break;
        case 5: trigonometric(); break;
	    case 6: Calculator choose(); break; // Calling the Function with reference to class
	    default: cout << "Invalid Choice!" << endl;
    }
}

						/*----- CALCULATOR CLASS FUNCTION DEFINED -----*/

void Calculator ::getvalue() // Function to get two values from the user
{
    cout << endl;
    cout << "Enter the First number  : ";
    cin >> num1;
    cout << "Enter the Second number : ";
    cin >> num2;
}

void Calculator ::displayResults() // Function to select which results to display
{
    int choice;

    system("CLS"); // clears the screen
    cout << endl
         << "1.Simple Calculator Results : " << endl
         << "2.Scientific Calculator Results : " << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    switch (choice)
    {
	    case 1: simpleRes(); break;
	    case 2: scientificRes(); break;
	    default: cout << "Enter correct choice" << endl;
    }
}

void Calculator ::simpleRes() // Function to Display the Simple calculator results
{
    cout << endl << "Results are:" << endl;
    cout << "1.Addition    : " << add << endl
         << "2.Subtraction : " << sub << endl
         << "3.Product     : " << prod << endl
         << "4.Divison     : " << div << endl
         << "5.Modulus     : " << mod << endl;
}

void Calculator ::scientificRes() // Function to Display the Scientific calculator results
{
    cout << endl << "Results are:" << endl;
    cout << "1.Square      :" << num1 << "=" << squ1 << " and " << num2 << "=" << squ2 << endl
         << "2.Exponent    :" << exp1 << " and " << exp2 << endl
         << "3.Factorial   :" << num1 << "=" << fact1 << " and " << num2 << "=" << fact2 << endl
         << "4.Square Root :" << num1 << "=" << sq1 << " and " << num2 << "=" << sq2 << endl
         << "5.The results of Trigonometric Functions are : " << endl; trigDisplay();

}

void Calculator ::init() // Function to initialize all the variables to zero(0)
{
    num1 = num2 = add = sub = prod = div = mod = 0;
    squ1 = squ2 = exp1 = exp2 = fact1 = fact2 = sq1 = sq2 = 0; // initializing multiple variables same time
}

void Calculator ::choose() // Function to choose what to do with the Calculator
{
    int choice;

    while (true)
    {
        cout << endl
             << "1.Simple Calculator " << endl
             << "2.Scientific Calculator " << endl
             << "3.View All Results" << endl
             << "4.New values" << endl
             << "5.Exit" << endl;

        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
	        case 1: simplec(); break;
	        case 2: scientific(); break;
	        case 3: displayResults(); break;
            case 4: getvalue(); init(); break;
	        case 5: exit(0);
	        default: cout << "Invalid choice!" << endl;
        }
    }
}

									/*---- MAIN FUNCTION ----*/
int main()
{
    Calculator calc; // Object created from multi level inheritance

    cout << endl;
    cout << "----------- CALCULATOR USING MULTILEVEL INHERITSANCE ----------" << endl;
    calc.init();
    calc.getvalue();
    calc.choose();

    return 0;
}