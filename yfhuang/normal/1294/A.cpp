#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>

using namespace std;

int t;

typedef long long LL;
LL a, b, c, n;

int main(){
    cin >> t;
    while(t--){
        scanf("%lld%lld%lld%lld", &a, &b, &c, &n);
        LL sum = a + b + c + n;
        if(sum % 3){
            cout << "NO" << endl;
        }else{
            sum /= 3;
            if(a > sum or b > sum or c > sum){
                cout << "NO" << endl;
            }else{
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}