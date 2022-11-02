#include<bits/stdc++.h>
#define maxn 234567

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
int n,a[maxn],s,t;

int main()
{
    scanf("%d",&n); n/=2;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) s+=abs(a[i]-i*2),t+=abs(a[i]-(i*2-1));
    cout << min(s,t) << endl;
}