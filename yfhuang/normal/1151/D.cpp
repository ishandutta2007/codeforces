#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 5;

struct stu{
    int a, b, dis;
    stu(int _a = 0, int _b = 0, int _dis = 0):a(_a), b(_b), dis(_dis){}
    bool operator < (const stu & rhs) const{
        return dis > rhs.dis;
    }
}s[maxn];


int main(){
    int n;
    while(cin >> n){
        for(int i = 1;i <= n;i++){
            int a, b;
            scanf("%d%d", &a, &b);
            s[i] = {a,b,a-b};
        }
        sort(s + 1,s + 1 + n);
        long long ans = 0;
        for(int i = 1;i <= n;i++){
            ans = ans + (1LL * (i - 1) * s[i].a + 1LL * (n - i) * s[i].b);
        }
        cout << ans << endl;
    }
    return 0;
}