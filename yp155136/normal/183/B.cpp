#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int N = 256;
const int Q = 1000006;

LL x[N],y[N];
LL cnt[Q];

vector<pii> v[Q];

pii gee(pii p)
{
    LL a=p.first,b=p.second;
    if (a<0 || a<=0 && b<0)
    {
        a = -a;
        b = -b;
    }
    LL gcd = __gcd(abs(a),abs(b));
    return make_pair(a/gcd,b/gcd);
}

int main ()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;m>=i;i++)
    {
        scanf("%lld %lld",&x[i],&y[i]);
    }
    for (int i=1;m>=i;i++)
    {
        for (int j=i+1;m>=j;j++)
        {
            if (y[i] == y[j]) continue;
            //if (x[i] == x[j] && i>j) continue;
            if (abs((x[j]-x[i])*y[j])%(abs(y[j]-y[i])) == 0)
            {
                LL xx = x[j] - (x[j]-x[i])*(y[j])/(y[j]-y[i]);
                //cout << "i = " << i << " , j = " << j << " , xx = " << xx << endl;
                if (1 <= xx && xx <= n)
                {
                    v[xx].push_back(gee(make_pair(x[j]-x[i],y[j]-y[i])));
                    cnt[xx]++;
                }
            }
        }
    }
    map<LL,LL> mp;
    for (int i=1;m>=i;i++)
    {
        mp[ (i*(i-1))/2 ] = i;
    }
    LL ans=0;
    for (int i=1;n>=i;i++)
    {
        if (cnt[i] == 0) ++ans;
        else
        {
            map<pii,int> mpp;
            for (pii p:v[i]) mpp[p]++;
            int mx=0;
            for (auto i:mpp) mx = max(mx,i.second);
            ans += mp[mx];
        }
    }
    printf("%lld\n",ans);
}