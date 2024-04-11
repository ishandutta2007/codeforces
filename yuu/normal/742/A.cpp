#include <stdio.h>
int main(){
    int n;
    scanf("%i", &n);
    int res=1;
    if(n>4){
        n%=4;
        for(int i=1; i<=n; i++)
            res=res*8%10;
        res=res*6%10;
    }
    else if(n!=0){
        for(int i=1; i<=n; i++)
            res=res*8%10;
    }
    printf("%d", res);
}