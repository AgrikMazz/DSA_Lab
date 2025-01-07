#include "polynomial.h"

Polynomial* emptyPolynomial(int n){
    Polynomial* p = (Polynomial*)malloc(sizeof(Polynomial));
    p->deg = n;
    p->coeff = (int*)calloc((n+1),sizeof(int));
    return p;
}

Polynomial* createPolynomial(){
    int n;
    printf("Enter degree of polynomial: ");
    scanf("%d",&n);
    if(n<0){
        do{
            printf("Coefficient of highest degree term must be non-zero! Try Again.\n");
            printf("Enter degree of polynomial: ");
            scanf("%d",&n);
        }while(n < 0);
    }
    Polynomial* p = emptyPolynomial(n);

    for(int i=0 ; i<=n ; i++){
        printf("Enter coefficient of x^%d: ",i);
        scanf("%d",&p->coeff[i]);
        if(i == n && p->coeff[i] == 0){
            do{
                printf("Coefficient of highest degree term must be non-zero! Try Again.\n");
                printf("Enter coefficient of x^%d: ",i);
                scanf("%d",&p->coeff[i]);
            }while(p->coeff[i] == 0);
        }
    }
    return p;
}

void display(Polynomial* p){
    printf("p(x) = ");
    if(p->deg == 0){
        printf("%d\n",p->coeff[0]);
        return;
    }
    
    for(int i=0; i<=p->deg; i++){
        if(i == 0){
            printf("%d + ",p->coeff[i]);
        }
        else if(i == p->deg){
            printf("%dx^%d\n",p->coeff[i],i);
            return;
        }
        else{
            printf("%dx^%d + ",p->coeff[i],i);
        }
    }
}

void getDegree(Polynomial* p){
    printf("Degree of the polynomial is: %d",p->deg);
}

long long evaluate(Polynomial* p, int x){
    long long ans = 0;
    int prod = 1;
    for(int i=0; i<=p->deg; i++){
        ans += p->coeff[i] * prod;
        prod*=x;
    }
    return ans;
}

Polynomial* scalarMultiply(Polynomial* p, int n){
    Polynomial* res = emptyPolynomial(p->deg);
    for(int i=0; i<=p->deg; i++){
        res->coeff[i] = n * p->coeff[i];
    }
    return res;
}

Polynomial* add(Polynomial* p1, Polynomial* p2){
    int n1 = p1->deg;
    int n2 = p2->deg;
    int n = n1 > n2 ? n1 : n2;
    Polynomial* res = emptyPolynomial(n);

    int i = 0, j = 0, k = 0;
    while(i <= n1 && j <= n2){
        res->coeff[k++] = p1->coeff[i++] + p2->coeff[j++];
    }
    while(i <= n1){
        res->coeff[k++] = p1->coeff[i++];
    }
    while(j <= n2){
        res->coeff[k++] = p2->coeff[j++];
    }
    while(res->coeff[res->deg] == 0 && res->deg != 0){
        res->deg--;
    }
    return res;
}

Polynomial* sub(Polynomial* p1, Polynomial* p2){
    int n1 = p1->deg;
    int n2 = p2->deg;
    int n = n1 > n2 ? n1 : n2;
    Polynomial* res = emptyPolynomial(n);

    int i = 0, j = 0, k = 0;
    while(i <= n1 && j <= n2){
        res->coeff[k++] = p1->coeff[i++] - p2->coeff[j++];
    }
    while(i <= n1){
        res->coeff[k++] = p1->coeff[i++];
    }
    while(j <= n2){
        res->coeff[k++] = -p2->coeff[j++];
    }
    while(res->coeff[res->deg] == 0 && res->deg != 0){
        res->deg--;
    }
    return res;
}

Polynomial* mul(Polynomial* p1, Polynomial* p2){
    int n1 = p1->deg;
    int n2 = p2->deg;
    Polynomial* res = emptyPolynomial(n1+n2);
    for(int i=0; i<=n1; i++){
        for(int j=0; j<=n2; j++){
            res->coeff[i+j] += p1->coeff[i] * p2->coeff[j];
        }
    }
    return res;
}

Polynomial* power(Polynomial* p, int n){
    Polynomial* res = emptyPolynomial(p->deg);
    if(n == 0){
        res->deg = 0;
        res->coeff[res->deg] = 1;
        return res;
    }
    for(int i=0; i<=p->deg; i++){
        res->coeff[i] = p->coeff[i];
    }
    for(int i=2; i<=n; i++){
        res = mul(res,p);
    }
    return res;
}

Polynomial* composition(Polynomial* p1, Polynomial* p2){
    int n1 = p1->deg, n2 = p2->deg;
    Polynomial* res = emptyPolynomial(n1 * n2);
    for(int i=0; i<= n1; i++){
        Polynomial* pow = power(p2,i);
        res = add(res, scalarMultiply(pow,p1->coeff[i]));
    }
    return res;
}
