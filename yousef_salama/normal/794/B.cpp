#include <bits/stdc++.h>
using namespace std;

int n, h;
int main(){
    scanf("%d %d", &n, &h);
    for(int i = 1; i < n; i++)
        printf("%.12f\n", sqrt((double)h * h * i / n));
    
    return 0;
}