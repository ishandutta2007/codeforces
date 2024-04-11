#include<bits/stdc++.h>
#define maxn 205000

using namespace std;
typedef long long ll;
ll a[maxn],n,k,l,m,p,ans;

int main()
{
    cin >> n >> k >> l; m=n*k;
    for (int i=0;i<m;i++) scanf("%d",&a[i]);
    sort(a,a+m); p=0;
    while (p<m&&a[p]-a[0]<=l) p++;
    if (p<n){
        cout << 0 << endl;
        return 0;
    }
    for (int i=0;i<n;i++) ans+=a[min(k*i,p-n+i)];
    cout << ans << endl;
}