#include <stdio.h>
#include <math.h>

#define e 2.71828

double f(double x);
double f_prime(double x);
double f_double_prime(double x);

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

double calculate_side_for_starting_x(double a, double b) {
    if (f(a) * f_double_prime(a) > 0) {
        return a;
    }
    return b;
}

void newton_raphson(double prec, double a, double b) {
    double fx, x, x_minus_one, abs_xk_minus_xk_minus_one; //this is mid point
    int step = 1;    
    int found = 0; //found = false

    x = calculate_side_for_starting_x(a, b);

    printf("\nNewton-Raphson Method\n");   
    printf("Stopping at |xk - xk-1| <= precision threshold\n");
    printf("f(%.2lf) * f''(%.2lf) = %.8lf \nf(%.2lf) * f''(%.2lf) = %.8lf\n", a, a, f(a) * f_double_prime(a), b, b, f(b) * f_double_prime(b));
    printf("Chosen x0 = %.2lf as starting value\n", x);
    printf("Step\tx\t\tf(x)\t\tf'(x)\t\tf''(x)\t\t|xk - xk-1|\n");

    do {
        x = x - f(x) / f_prime(x); // calculating mid point using newton-raphson method
        
        abs_xk_minus_xk_minus_one = fabs(x - x_minus_one);
        
        printf("%d\t%.8lf\t%.8lf\t%.8lf\t%.8lf\t%.8lf\n", step, x, f(x), f_prime(x), f_double_prime(x), abs_xk_minus_xk_minus_one);
        
        found = compare_double_to_zero(f(x), prec); //0 or 1         

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

//THE DERIVATIVES OF YOUR FUNCTIONS GO HERE (required for newton-raphson method)
double f_prime(double x) {
    return                                    //Function No.

    //3 * pow(x, 2) + 2;                      //1
    //3 * pow(x, 2) + 2 * x - 3;              //2
    pow(e, x) - 2;                            //3
    //2 * x;                                  //8
   
    //2 + pow(e, -x);                         //10  
}

//2nd order derivatives go here
double f_double_prime(double x) {
    return

    pow(e, x);                               //3
}

int main(int argc, char **argv) {  
    double prec; //required precision     
    
    prec = pow(10, -6); //Error precision for calculating using the logs formula 1
       
    newton_raphson(prec, 1.2, 1.3); //arguments are prec, left limit a, right limit b

    return 0;
}