#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n;
const int maxn = 1e5 + 5;
long long c[maxn], t[maxn];
long long pre[maxn];
long long suf[maxn];
int main(){
    while(cin >> n){
        for(int i = 1;i <= n;i++){
            scanf("%lld", &c[i]);
        }
        for(int i = 1;i <= n;i++){
            scanf("%lld", &t[i]);
        }
        bool flag = true;
        if(c[1] != t[1]) flag = false;
        if(c[n] != t[n]) flag = false;

        if(flag && n > 2){
            for(int i = 2;i <= n;i++){
                pre[i - 1] = c[i] - c[i - 1];
                suf[i - 1] = t[i] - t[i - 1];
            }
            sort(pre + 1, pre + n);
            sort(suf + 1, suf + n);
            for(int i = 1;i < n;i++){
                if(pre[i] != suf[i])
                    flag = false;
            }
        }
        if(flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}