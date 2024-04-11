#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int s[200010],p[200010];
int n,D;
int main(){
    cin>>n>>D;
    for (int i=1;i<=n;i++) cin>>s[i];
    for (int i=1;i<=n;i++) cin>>p[i];

    int sum = s[D] + p[1];
    int st = 2,ed = n, rk = 1;
    for (int i=1;i<D;i++)
        if (s[i] + p[ed] <= sum) ed--;  else {st++;rk++;}
    cout<<rk<<endl;
}