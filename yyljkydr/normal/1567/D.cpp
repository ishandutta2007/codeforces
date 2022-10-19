#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+1e3+7;

int T,n,s;

multiset<int>c;

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        c.clear();
        scanf("%lld%lld",&s,&n);
        int x=s;
        for(int i=1;i<=x;i*=10)
        {
            int res=x%(i*10);
            int num=min(res/i,n-1);
            for(int j=0;j<num;j++)
                c.insert(i),x-=i,n--;
        }
        if(x)
            c.insert(x),n--;
        while(n)
        {
            auto it=c.lower_bound(10);
            int num=min(9ll,n);
            int val=*it;
            c.erase(it);
            int nval=val/10;
            for(int j=0;j<num;j++)
                c.insert(nval),val-=nval,n--;
            if(val)
                c.insert(val);
        }
        for(auto x:c)
            printf("%lld ",x);
        puts("");
    }
}