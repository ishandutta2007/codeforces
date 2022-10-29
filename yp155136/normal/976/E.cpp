#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 200006;

LL h[N],d[N];
int p[N];

bool cmp(const int &a,const int &b)
{
    return h[a] - d[a] > h[b] - d[b];
}

int main ()
{
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    b = min(b,n);
    for (int i=1;n>=i;i++)
    {
        scanf("%lld %lld",&h[i],&d[i]);
        p[i] = i;
    }
    sort(p+1,p+n+1,cmp);
    LL ans=0;
    for (int i=1;n>=i;i++)
    {
        ans += d[ p[i] ];
        if (i <= b)
        {
            ans -= d[ p[i] ];
            ans += max( h[ p[i] ] , d[ p[i] ] );
        }
    }
    LL mx = ans;
    if (!b)
    {
        printf("%lld\n",ans);
        return 0;
    }
    //cout << "ans = " << ans << endl;
    for (int i=1;n>=i;i++)
    {
        LL tmp = ans;
        if (i <= b)
        {
            tmp -= max( h[ p[i] ]  , d[ p[i] ]);
            tmp += max( (h[ p[i] ]<<a) , d[ p[i] ] );
            mx = max(mx,tmp);
        }
        else
        {
            tmp -= d[ p[i] ];
            tmp -= max( h[ p[b] ] , d[ p[ b ] ] );
            tmp += d[ p[b] ];
            tmp += max( (h[ p[i] ]<<a) , d[ p[i] ] );
            mx = max(mx,tmp);
        }
    }
    printf("%lld\n",mx);
}