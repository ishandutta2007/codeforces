#include<bits/stdc++.h>
#define maxn 100050
using namespace std;

int n;
int mp[maxn],a[maxn];

int T[maxn];

int main()  {
    scanf("%d",&n);
    for (int t,i=1;i<=n;++i)
        scanf("%d",&t),mp[t]=i;
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]),a[i]=mp[a[i]];
    
    int mn=maxn,cnt=0;
    for (int i=n;i;--i)  {
        if (mn<a[i])
            ++cnt;
        mn=min(mn,a[i]);
    }
    cout<<cnt<<endl;
    return 0;
}