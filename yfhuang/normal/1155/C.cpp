#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n, m;

const int maxn = 3e5 + 5;
typedef long long LL;
LL x[maxn];
LL q[maxn];

LL gcd(LL a, LL b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){
    while(cin >> n >> m){
        LL p;
        for(int i = 1;i <= n;i++){
            scanf("%lld", &x[i]);
            if(i == 2){
                p = x[i] - x[i - 1];
            }else if(i > 2){
                p = gcd(p, x[i] - x[i - 1]);
            }
        }
        bool flag = false;
        int i;
        for(i = 1;i <= m;i++){
            scanf("%lld", &q[i]);         
        }
        for(i = 1;i <= m;i++){
            if(p % q[i] == 0){
                flag = true;
                break;
            }
        }
        if(!flag){
            puts("NO");
        }else{
            puts("YES");
            cout << x[1] << " " << i << endl;
        }
    } 
    return 0;
}