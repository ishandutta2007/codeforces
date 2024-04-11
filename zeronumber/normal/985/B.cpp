#include<bits/stdc++.h>
#define maxn 2050

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
int n,a[maxn],s,t,m;
char c[maxn][maxn];

int main()
{
    cin >> n >> m;
    for (int i=0;i<n;i++) scanf("%s",c[i]);
    for (int i=0;i<m;i++){
        s=0;
        for (int j=0;j<n;j++) if (c[j][i]=='1') s++,t=j;
        if (s==1) a[t]=1;
    }
    for (int i=0;i<n;i++) if (!a[i]) {puts("YES");return 0;}
    puts("NO");
}