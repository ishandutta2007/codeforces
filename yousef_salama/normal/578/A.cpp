#include <bits/stdc++.h>
using namespace std;

int a, b;
int main(){
    scanf("%d %d", &a, &b);
    
    if(b > a){
        printf("-1\n");
        return 0;
    }
    
    int q = (a + b) / (2 * b);
    printf("%.15f\n", 0.5 * (a + b) / q);
    
    return 0;
}