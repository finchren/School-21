// Copyright 2022 finchren
/* 
Write a program in C to find the sum of the series [ 1-X^2/2!+X^4/4!- .........]. Go to the editor
Test Data :
Input the Value of x :2
Input the number of terms : 5
Expected Output :
the sum = -0.415873
Number of terms = 5
value of x = 2.000000

+ 1. Take the input of x and number of terms
+ 2. Write factorial function
+ 2.1 Write pow function
2.3 Write function for counting the sum
+ 2.5 Display the sum, number of term and value of x
+ 3. Work around invalid input
+ 4. Test
+ 5. Cpplint test
+ 6. Add and push
+ 7. Switch from double to double to allow to input bigger numbers
+ 8. Change code to process negitive x as well
*/

#include <stdio.h>

double input_value_of_x();
double input_number_of_terms();
double factorial(double number);
double power(double number, double power);
double count_sum(double x, double number_of_terms);
void print_sum(double sum);
void print_number_of_terms(double number_of_terms);
void print_value_of_x(double x);

int main() {
    double x = input_value_of_x();
    double number_of_terms = input_number_of_terms();
    if (x != 0 && number_of_terms > 0) {
        print_sum(count_sum(x, number_of_terms));
        print_number_of_terms(number_of_terms);
        print_value_of_x(x);
    } else {
        printf("n/a");
    }
    return 0;
}

void print_value_of_x(double x) {
    printf("Value of x = %f\n", x);
}

void print_number_of_terms(double number_of_terms) {
    printf("Number of terms = %d\n", (int) number_of_terms);
}

void print_sum(double sum) {
    printf("The sum = %f\n", sum);
}

double count_sum(double x, double number_of_terms) {
    double sum = 1.0, multiplier = 2.0;
    for (int i = 1; i <= number_of_terms; i++) {
        if (i % 2 == 0) {
            sum += power(x, multiplier) / factorial(multiplier);
            multiplier += 2.0;
        } else {
            sum -= power(x, multiplier) / factorial(multiplier);
            multiplier += 2.0;
        }
    }
    return sum;
}

double power(double number, double power) {
    double result = number;
    for (double i = 2; i <= power; i++) {
        result *= number;
    }
    return result;
}

double input_number_of_terms() {
    double number_of_terms;
    char endline;
    printf("Input the number of terms:\n");
    if (scanf("%lf%c", &number_of_terms, &endline) == 2 && ((endline == ' ') || (endline == '\n'))) {
        if (number_of_terms <= 0) {
            number_of_terms = 0;
        }
    } else {
        number_of_terms = 0;
    }
    return number_of_terms;
}

double input_value_of_x() {
    double x;
    printf("Input the value of x:\n");
    if (scanf("%lf", &x) == 1) {
    } else {
        x = 0;
    }
    return x;
}

double factorial(double number) {
    double result = 1.0;
    for (double i = 1; i <= number; i++) {
        result *= i;
    }
    return result;
}