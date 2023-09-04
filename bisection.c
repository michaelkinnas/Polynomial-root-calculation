#include <stdio.h>
#include <math.h>

#define e 2.71828

double f(double x);
double f_prime(double x);
double g(double x);

//compares if double is equal to 0, to variable zeros according to prec input;
int compare_double_to_zero(double f1, double prec) {
    //double precision = 0.00001;
    double precision = prec; // this is in testing phase
    if (((f1 - 0.000000001) < 0) && 
        ((f1 + 0.000000001) > 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//calculate number of steps needed
int kCalc(double a, double b, double prec) {
    return ((log10(b-a) - log10(prec)) / log10(2) + 1);
}


void bisection(double a, double b, double prec) {
    double x, x_minus_one, abs_xk_minus_xk_minus_one; //this is mid point
    double fx, fa; //function evaluations for mid point and a
    double abs_fx = 1;
    int k = kCalc(a, b, prec); 
    int step = 1;    
    int found = 0; //found = false    
    char chosen_x = ' ';

    printf("\nBisection Method\n");
    printf("Calculated required steps <= %d\n", k);
    printf("Stopping at |xk - xk-1| <= precision threshold\n");
    printf("Step\tLeft (a)\tMiddle (x)\tRight (b)\tf(a)\t\tf(x)\t\t|xk - xk-1|\tWhich side moves\n");
    
    do {
        x = ((a + b) / 2); //next midpoint
        
        abs_xk_minus_xk_minus_one = fabs(x - x_minus_one);
        
        printf("%d\t%.8lf\t%.8lf\t%.8lf\t%.8lf\t%.8lf\t%.8lf\t%c\n", step, a, x, b, f(a), f(x), abs_xk_minus_xk_minus_one, chosen_x);
        
        found = compare_double_to_zero(f(x), prec); //0 or 1        
        
        //Reduce input range
        if ((f(a) * f(x)) > 0) {
            a = x;
            chosen_x = 'a';
        } else {
            b = x;
            chosen_x = 'b';
        }      
        
        x_minus_one = x;
        step++;

    } while (abs_xk_minus_xk_minus_one > prec && !found);

        
    printf("\n");
}


//FUNCTIONS GO HERE
double f(double x) {
    return                                  //Νο.   left, right     required precission
    
    //pow(x, 3) - 2 * x - 5;                //1.    [2, 3]            10^-6
    //pow(x, 3) + pow(x, 2) - 3 * x - 3;    //2.    [1, 2]            10^-6 
    pow(e, x) - 2 * x - 1;                //3.    [1.2, 1.3]        10^-5
    //pow(x, 2) - x - 1;                    //4.
    //pow(x, 6) - x - 1;                    //5.
    //pow(x, 3) - 4 * pow(x, 2) - 10;       //6.    
    //pow(x, 3) + 2 * x - 2;                //7.    [1, 0]            10^-3
    //pow(x, 2) - 2;                        //8.    [1, 2]
   
    //2 * x - pow(e, -x);                   //10.   [0, 1]            10^-5
    
}

int main(int argc, char **argv) {  
    double a, b;    //initial input values, range 
    double prec;    //required precision   
   
    //2. PUT YOUR FUNCTION VALUES HERE--------
    a = 1.2;              //Left 
    b = 1.3;              //Right
    prec = pow(10, -6); //Error precision for calculating using the logs formula 1

    bisection(a, b, prec);

    return 0;
}