#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=35;

int n,oc[N],c[N],q;

signed main()
{
    scanf("%lld%lld",&n,&q);
    for(int i=0;i<n;i++)
        scanf("%lld",&oc[i]);
    while(q--)
    {
        int op,x,y;
        scanf("%lld",&op);
        scanf("%lld%lld",&x,&y);
        if(op==1)
            oc[x]=y;
        else
        {
            //at/ least k less than or equal to 2^x
            for(int i=0;i<n;i++)
                c[i]=oc[i];
            int now=0;
            for(int i=0;i<=x;i++)
                now+=c[i];
            int nd=y-now;
            int ans=0;
            if(nd>0)
            {
                for(int i=x+1;i<n;i++)
                {
                    int r=min(c[i],nd/(1<<(i-x)));
                    c[i]-=r;
                    nd-=(1<<(i-x))*r;
                    ans+=r*((1<<(i-x))-1);
                    c[x]+=r*(1<<(i-x));
                }
            }
            int s=0;
            for(int i=1;i<=x;i++)
                s+=c[i]*((1<<i)-1);
            if(nd>0&&s>=nd)
            {
                ans+=nd;
                nd=0;
            }
            if(nd>0)
            {
                int pos=-1;
                for(int i=x+1;i<n;i++)
                    if(c[i])
                    {
                        pos=i;
                        break;
                    }
                int fans=1e18;
                if(pos!=-1)
                {
                    while(pos>x)
                    {
                        ans++;
                        pos--;
                        if(nd>=(1<<(pos-x)))
                        {
                            ans+=(1<<(pos-x))-1;
                            nd-=(1<<(pos-x));
                            if(x)
                                s+=(1<<(pos-x));
                            if(s>=nd)
                                fans=min(fans,ans+nd);
                        }
                    }
                    if(nd==0)
                        ans=min(ans,fans);
                    else
                        ans=fans;
                }
            }
            if(nd>0)
                puts("-1");
            else
                printf("%lld\n",ans);
        }
    }
}