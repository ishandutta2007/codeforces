#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;

#define F first
#define S second

const int N = 100006;

pii p[N];

int main ()
{
    int n,s;
    scanf("%d %d",&n,&s);
    LL sum=0;
    LL dif=0;
    LL ans=0;
    LL cnt=0;
    for (int i=0;n>i;i++)
    {
        int num,a,b;
        scanf("%d %d %d",&num,&a,&b);
        p[i] = make_pair(b-a,num);
        cnt += num;
        sum += num*1LL*a;
    }
    if (cnt%s != 0)
    {
        p[n] = make_pair(0, s - cnt%s);
        n++;
    }
    sort(p,p+n);
    ans = sum;
    cnt=0;
    for (int i=n-1;i>=0;i--)
    {
        if (cnt + p[i].second >= s)
        {
            ans = max(ans,sum + dif + p[i].first * (s - cnt));
            ans = max(ans,sum + dif + p[i].first*( ((cnt + p[i].second)/s)*s - cnt ));
        }
        dif += p[i].first*1LL*p[i].second;
        cnt = (cnt + p[i].second)%s;
    }
    printf("%lld\n",ans);
}