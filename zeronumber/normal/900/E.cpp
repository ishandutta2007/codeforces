#include<bits/stdc++.h>
#define maxn 200050

using namespace std;

char s[maxn];

int a[maxn][2],b[maxn][2],c[maxn],d[maxn],r[maxn],n,m,p,q,f;

int main()
{
    scanf("%d",&n);scanf("%s",s);scanf("%d",&m);
    p=(m+1)/2;q=m/2;
    a[0][0]=a[0][1]=0;b[0][1]=0;c[0]=0;
    for (int i=1;i<=n;i++)
    {
        a[i][0]=a[i-1][0];a[i][1]=a[i-1][1];
        b[i][0]=b[i-1][0];b[i][1]=b[i-1][1];
        c[i]=c[i-1];
        if (s[i-1]=='a') a[i][i&1]++;
        else if (s[i-1]=='b') b[i][i&1]++;
        else a[i][i&1]++,b[i][i&1]++,c[i]++;
    }
    memset(d,0,sizeof(d));memset(r,0,sizeof(r));
    for (int i=m;i<=n;i++)
    {
        d[i]=d[i-1]; r[i]=r[i-1];
        f=(i-m+1)&1;
        if (a[i][f]-a[i-m][f]==p&&b[i][f^1]-b[i-m][f^1]==q)
        {
            if (d[i]<d[i-m]+1||d[i]==d[i-m]+1&&r[i]>r[i-m]+c[i]-c[i-m])
            {
                d[i]=d[i-m]+1;
                r[i]=r[i-m]+c[i]-c[i-m];
            }
        }
    }
    printf("%d\n",r[n]);
    return 0;
}