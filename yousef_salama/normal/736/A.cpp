#include <bits/stdc++.h>
using namespace std;

long long n;
int main(){
    scanf("%I64d", &n);
    
    long long a = 1, b = 2;
    int d = 1;
    
    while((a + b) <= n){
        long long c = a + b;
        a = b;
        b = c;
        
        d++;
    }
    printf("%d\n", d);
    
    return 0;
}