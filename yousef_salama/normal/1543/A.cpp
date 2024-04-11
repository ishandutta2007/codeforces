#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        long long a, b;
        cin >> a >> b;
        
        long long diff = llabs(a - b);
        printf("%lld %lld\n", diff, diff == 0 ? 0 : min(a % diff, diff - a % diff));
    }
    return 0;
}