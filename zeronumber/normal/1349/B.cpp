#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+3;
int a[maxn],n,k;
int main(){
    int _; cin >> _;
    while (_--){
        cin >> n >> k;
        for (int i=1;i<=n;i++) cin >> a[i];
        bool flag=0;
        for (int i=1;i<=n;i++) flag|=a[i]==k;
        if (!flag){puts("no");continue;}
        if (n==1){puts("yes");continue;}
        flag=0;
        for (int i=1;i<=n-1;i++) flag|=(a[i]>=k)&&(a[i+1]>=k);
        for (int i=1;i<=n-2;i++) flag|=(a[i]>=k)&&(a[i+2]>=k);
        if (flag) puts("yes"); else puts("no");
    }
    return 0;
}