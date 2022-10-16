#include <stdio.h>
int n, aa, bb;
int main(){
    scanf("%i", &n);
    aa=1;
    bb=n;
    for(int a=2; a<=n; a++){
        if(n%a==0){
            int b=n/a;
            if(b<a) break;
            if(b-a<bb-aa){
                bb=b;
                aa=a;
            }
        }
    }
    printf("%d %d", aa, bb);
}