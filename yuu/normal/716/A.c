#include <stdio.h>
int main(){
    int n, c, wc=0, t[2];
    t[1]=0;
    scanf("%i", &n);
    scanf("%i", &c);
    for(int i=1; i<=n; i++){
        scanf("%i", &t[1-i%2]);
        if(t[1-i%2]-t[i%2]>c)
            wc=1;
        else wc++;
    }
    printf("%d", wc);
}