#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_DIG 1000

typedef struct{
    int *arr;
    int dig;
} Number;

Number createNumber(int n){
    Number num;
    num.dig = n;
    num.arr = (int *)malloc(n * sizeof(int));

    for(int i=0; i<n; i++){
        int random_digit = rand() % 10;   //Generate random digits
        if(i == n - 1 && random_digit == 0){
            random_digit = (rand() % 9) + 1; // Ensure non-zero digit
        }
        num.arr[i] = random_digit;
    }

    return num;
}

int compare(Number num1, Number num2){
    if(num1.dig > num2.dig){
        return 1;
    }
    else if(num1.dig < num2.dig){
        return -1;
    }
    else{
        int i = num1.dig - 1;
        while(i >= 0){
            if(num1.arr[i] > num2.arr[i]){
                return 1;
            }
            else if(num1.arr[i] < num2.arr[i]){
                return -1;
            }
            i--;
        }
    }
    return 0;
}

Number addition(Number num1, Number num2){
    Number ans;
    ans.dig = MAX_DIG;
    ans.arr = (int *)malloc(MAX_DIG * sizeof(int));
    int i = 0, j = 0, k = 0;
    int carry = 0;

    while (i < num1.dig || j < num2.dig) {
        int digit1 = (i < num1.dig) ? num1.arr[i] : 0;
        int digit2 = (j < num2.dig) ? num2.arr[j] : 0;

        int sum = (digit1 + digit2 + carry) % 10;
        carry = (digit1 + digit2 + carry) / 10;

        ans.arr[k++] = sum;
        i++;
        j++;
    }

    if(carry == 1) ans.arr[k++] = 1;
    ans.dig = k;
    return ans;
}

Number subtraction(Number num1, Number num2){
    Number ans;
    ans.dig = MAX_DIG;
    ans.arr = (int *)malloc(MAX_DIG * sizeof(int));
    int i = 0, j = 0, k = 0;
    int borrow = 0;

    while (i < num1.dig || j < num2.dig) {
        int digit1 = (i < num1.dig) ? num1.arr[i] : 0;
        int digit2 = (j < num2.dig) ? num2.arr[j] : 0;

        digit1 -= borrow;  
        if (digit1 < digit2) {
            digit1 += 10;  
            borrow = 1;
        } else {
            borrow = 0;
        }

        ans.arr[k++] = digit1 - digit2;
        i++;
        j++;
    }

    while (k > 1 && ans.arr[k - 1] == 0) {
        k--;
    }

    ans.dig = k;
    return ans;
}

Number multiplication(Number num1, Number num2) {
    Number ans;
    ans.dig = num1.dig + num2.dig;
    ans.arr = (int *)calloc(ans.dig, sizeof(int));
    for (int i = 0; i < num1.dig; i++) {
        int carry = 0;
        for (int j = 0; j < num2.dig; j++) {
            int prod = num1.arr[i] * num2.arr[j] + ans.arr[i + j] + carry;
            ans.arr[i + j] = prod % 10; 
            carry = prod / 10;
        }
        if (carry > 0) {
            ans.arr[i + num2.dig] += carry;
        }
    }

    while (ans.dig > 1 && ans.arr[ans.dig - 1] == 0) {
        ans.dig--;
    }

    return ans;
}

void printNumber(Number num){
    for(int i=num.dig-1; i>=0; i--){
        printf("%d",num.arr[i]);
    }printf("\n");
}

int main(){
    srand(time(NULL));
    
    int n1, n2;
    printf("Enter number of digits in first number(<1000): ");
    scanf("%d",&n1);
    printf("Enter number of digits in second number(<1000): ");
    scanf("%d",&n2);
    
    Number num1 = createNumber(n1);
    Number num2 = createNumber(n2);

    Number add = addition(num1,num2);
    Number sub;
    if(compare(num1,num2) >= 0){
        sub = subtraction(num1,num2);
    }
    else{
        sub = subtraction(num2,num1);
    }
    Number mul = multiplication(num1,num2);

    printf("First number: ");
    printNumber(num1);

    printf("Second number: ");
    printNumber(num2);

    printf("Sum: ");
    printNumber(add);

    printf("Difference: ");
    printNumber(sub);

    printf("Product: ");
    printNumber(mul);

    return 0;
}