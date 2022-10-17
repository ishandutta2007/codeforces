#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e6+1e3+7;

int T,n;

ll x[N],y[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        x[0]=0,y[0]=0;
        for(int i=1;i<=n*2;i++)
        {
            ll a,b;
            scanf("%lld%lld",&a,&b);
            if(b==0)
                x[++x[0]]=abs(a);
            else
                y[++y[0]]=abs(b);
        }
        sort(x+1,x+n+1);
        sort(y+1,y+n+1);
        double s1=0,s2=0;
        for(int i=1;i<=n;i++)
            s1+=sqrt(x[i]*x[i]+y[i]*y[i]);
        for(int i=1;i<=n;i++)
            s2+=sqrt(x[i]*x[i]+y[n-i+1]*y[n-i+1]);
        printf("%.16lf\n",min(s1,s2));
    }
}