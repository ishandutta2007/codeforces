#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=6e3+1e2+7;

int n,x[N],y[N];

int cnt[4][4][4];

ll ans1,ans2;

void solve(int a,int b,int c,int d,int e,int f)
{
    int g=__gcd((a-c)&3,(b-d)&3);
    int p=(a*d-b*c-e-f-g)&3;
    if(p||g%2)
        return;
    int flag=(a==c&&b==d&&e==f);
    ll &res=(e&1?ans1:ans2);
    if(flag)
        res+=(cnt[a][b][e]-1)*cnt[a][b][e];
    else
        res+=cnt[a][b][e]*cnt[c][d][f];
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
    {
        memset(cnt,0,sizeof(cnt));
        for(int j=1;j<=n;j++)
            if(i!=j)
                cnt[(x[i]-x[j])&3][(y[i]-y[j])&3][__gcd(abs(x[i]-x[j]),abs(y[i]-y[j]))&3]++;
        for(int a=0;a<4;a++)
            for(int b=0;b<4;b++)
                for(int c=0;c<4;c++)
                    for(int d=0;d<4;d++)
                    {
                        if((a*d-b*c)&1)
                            continue;
                        for(int e=1;e<4;e+=2)
                            for(int f=1;f<4;f+=2)
                                solve(a,b,c,d,e,f);
                        for(int e=0;e<4;e+=2)
                            for(int f=0;f<4;f+=2)
                                solve(a,b,c,d,e,f);
                    }
    }
    printf("%lld\n",ans1/2+ans2/6);
}