#include <bits/stdc++.h>
using namespace std;

long long s(long long x){
    int res = 0;
    while (x){
	res += x % 10;
	x /= 10;
    }
    return res;
}

int main(){
    long long n;
    cin >> n;
    long long t = 0;
    while (t * 10 + 9 <= n){
	t *= 10;
	t += 9;
    }
    long long v = n - t;
    cout << s(v) + s(t) << endl;
    return 0;
}