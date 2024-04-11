#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){
    int T;
    cin >> T;
    while(T--){
        long long a, b, k;
        cin >> a >> b >> k;
        long long g = gcd(a, b);
        a /= g, b /= g;
        if(a > b * (k - 1) + 1 or b > a * (k - 1) + 1){
            cout << "REBEL" << endl;
        }else{
            cout << "OBEY" << endl;
        }
    }
    return 0;
}