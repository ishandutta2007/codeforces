#include <bits/stdc++.h>
using namespace std;

int a[6];
int main(){
    for(int i = 0; i < 6; i++)
        scanf("%d", &a[i]);
        
    int r = 0;
    r += a[0] * a[1] + a[0] * a[2] + a[1] * a[2];
    r += a[5] * a[4] + a[5] * a[3] + a[4] * a[3];
    printf("%d\n", r);
    
    return 0;
}