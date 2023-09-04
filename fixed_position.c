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

void fixed_position(double prec, double a, double b) {
    double x, x_minus_one, abs_xk_minus_xk_minus_one; //this is mid point
    double fx; //function evaluations for mid point and a    
    int step = 1;    
    int found = 0; //found = false    

    x = (a + b) / 2;

    printf("\nFixed Position Method\n"); 
    printf("Stopping at |xk - xk-1| <= precision threshold\n");
    printf("Chosen x0 = %.2lf as starting value\n", x);
    printf("Step\tx\t\tf(x)\t\t|xk - xk-1|\n");    

    do {
        x = g(x); // calculating mid point using newton-raphson method
        
        abs_xk_minus_xk_minus_one = fabs(x - x_minus_one);
        
        printf("%d\t%.8lf\t%.8lf\t%.8lf\n", step, x, f(x), abs_xk_minus_xk_minus_one);
        
        found = compare_double_to_zero(f(x), prec); //0 or 1         

        x_minus_one = x;        
        step++;

    } while (abs_xk_minus_xk_minus_one > prec && !found);

    printf("\n");    
}

//function
double f(double x) {
    return                                  //Νο.   left, right     required precission
    
    //pow(x, 3) - 2 * x - 5;                //1.    [2, 3]            10^-6
    //pow(x, 3) + pow(x, 2) - 3 * x - 3;    //2.    [1, 2]            10^-6 
    //pow(e, x) - 2 * x - 1;                //3.    [1.2, 1.3]        10^-5
    //pow(x, 2) - x - 1;                    //4.
    //pow(x, 6) - x - 1;                    //5.
    //pow(x, 3) - 4 * pow(x, 2) - 10;       //6.    
    //pow(x, 3) + 2 * x - 2;                //7.    [1, 0]            10^-3
    //pow(x, 2) - 2;                        //8.    [1, 2]
    pow(e, -x) - x;                       //9.    [0.5, 1]
    //2 * x - pow(e, -x);                   //10.   [0, 1]            10^-5
    
}

//THE DERIVATIVES OF YOUR FUNCTIONS GO HERE (required for newton-raphson method)
double f_prime(double x) {
    return                                    //Function No.

    //3 * pow(x, 2) + 2;                      //1
    //3 * pow(x, 2) + 2 * x - 3;              //2
    //pow(-e, -x) - 1;                          //3
    //2 * x;                                  //8
    pow(-e, -x) - 1;                          //9
    //2 + pow(e, -x);                           //10  
}

//Function refactor
double g(double x) {
    return                                     //Function No.

    pow(e, -x);                           //9
}

int main(int argc, char **argv) {   
    double prec; //required precision   
            
    prec = pow(10, -6); //Error precision for calculating using the logs formula 1
       
    fixed_position(prec, 0.5, 1);
    
    return 0;
}