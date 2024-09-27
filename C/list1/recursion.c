#include <stdio.h>

int fatorialRecursivo(int n){
    if(n==0){
        return 1;
    }
    return n * fatorialRecursivo(n-1);
}

int fatorialLoop(int n){
    int j,result=1;
    if(n==0){
        return 1;
    }
    for(j=n;j>=1;j--){
        result *= j;
    }
    return result;
}

int fibonacci(int n) {
    int result;
    if (n <= 1)
        return n;
    else
        result = (n-1+n-2);
        printf("%d - ", result);
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void){
    int n=4;
    printf("recursivo %d\n",fatorialRecursivo(n));
    n=5;
    printf("iterativo %d\n",fatorialLoop(n));v
    fibonacci(5);
    return 0;
}
