#include <stdio.h>
int main(){
    int n, a, b;
    scanf("%i%i", &n, &a);
    if(n==1){
        if(a==0) printf("UP");
        else if(a==15) printf("DOWN");
        else printf("-1");
    }
    else {
        for(int i=1; i<n; i++){
            b=a;
            scanf("%i", &a);
        }
        if(a<b){
            if(a==0) printf("UP");
            else printf("DOWN");
        }
        else{
            if(a==15) printf("DOWN");
            else printf("UP");
        }
    }
}