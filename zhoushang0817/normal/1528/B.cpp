#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
bool mark[N];
int n,A=1,prim[N],d[N],num[N];
int cnt;
signed main()
{
    cnt=0;
    d[1]=1;
    for (int i=2 ; i<N ; ++i)
    {
        if (!mark[i])
        {
            prim[cnt++]=i;
            num[i]=1;
            d[i]=2;
        }
        for (int j=0 ; j<cnt && i*prim[j]<N ; ++j)
        {
            mark[i*prim[j]]=1;
            if (!(i%prim[j]))
            {
                num[i*prim[j]]=num[i]+1;
                d[i*prim[j]]=d[i]/(num[i]+1)*(num[i*prim[j]]+1);
                break;
            }
            d[i*prim[j]]=d[i]*d[prim[j]];
            num[i*prim[j]]=1;
        }
    }
    cin>>n;
    for(int i=2;i<=n;i++)
        A*=2,(A+=d[i]-d[i-1])%=998244353;
    cout<<A;
	return 0;
}