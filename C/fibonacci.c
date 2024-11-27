#include <stdio.h>

int main(void){
    int i,num,anterior,anteriorDoanterior,atual=1;
    num = 10;
    for(i=0;i<=num;i++){
        if(i<=1){
            printf("%d  ",atual);
            anterior = atual;
            anteriorDoanterior = 1;
            continue;
        }
        atual = anteriorDoanterior + anterior;
        printf("%d  ",atual);
        anterior = atual;
        anteriorDoanterior = atual - anteriorDoanterior;
    }
}
