#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, a[MAXN];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
      
    
    long double L = -20000, R = 20000;
    while(R - L > 1e-12){
        long double mid = (L + R) / 2;
        
        long double X = -5e9, Y = -5e9;
        long double LX = 0, LY = 0;
        
        for(int i = 0; i < n; i++){
            LX = (a[i] + mid) + max(LX, (long double)0.0);
            X = max(X, LX);
            
            LY = (-a[i] - mid) + max(LY, (long double)0.0);
            Y = max(Y, LY);
        }
        
        if(X <= Y)L = mid;
        else R = mid;
    }

    long double X = -5e9, Y = -5e9;
    long double LX = 0, LY = 0;
    
    for(int i = 0; i < n; i++){
        LX = (a[i] + L) + max(LX, (long double)0.0);
        X = max(X, LX);
        
        LY = (-a[i] - L) + max(LY, (long double)0.0);
        Y = max(Y, LY);
    }
    printf("%.15Lf\n", max(X, Y));
    
    
    return 0;
}