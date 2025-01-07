#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int deg;
    int* coeff;
} Polynomial;

Polynomial* emptyPolynomial(int n);
Polynomial* createPolynomial();
void display(Polynomial* p);
void getDegree(Polynomial* p);
long long evaluate(Polynomial* p, int x);
Polynomial* scalarMultiply(Polynomial* p, int n);
Polynomial* add(Polynomial* p1, Polynomial* p2);
Polynomial* sub(Polynomial* p1, Polynomial* p2);
Polynomial* mul(Polynomial* p1, Polynomial* p2);
Polynomial* power(Polynomial* p, int n);
Polynomial* composition(Polynomial* p1, Polynomial* p2);

#endif