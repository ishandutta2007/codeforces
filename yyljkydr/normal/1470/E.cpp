#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=3e5+1e3+7;

int T,n,c,q;

int p[N];

int sl[N][5],sr[N][5];

int ways[N][5];

int C(int n,int m)
{
    if(n<m||n<0||m<0)
        return 0;
    __int128 ret=1;
    for(int i=1;i<=m;i++)
        ret=ret*(n-i+1)/i;
    return ret;
}

bool cmp(int a,int b)
{
    return p[a]<p[b];
}

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&n,&c,&q);
		for(int i=1;i<=n;i++)
			scanf("%lld",&p[i]);
		// random_shuffle(p+1,p+n+1);
		for(int j=0;j<=c;j++)
			ways[1][j]=ways[0][j]=1;
        for(int i=2;i<=n;i++)
        {
            ways[i][0]=1;
            for(int j=1;j<=c;j++)
                ways[i][j]=ways[i][j-1]+C(i-1,j);
        }
        for(int i=1;i<=n;i++)
        {
            for(int t=0;t<=c;t++)
            {
                sl[i][t]=sl[i-1][t];
                sr[i][t]=sr[i-1][t];
                for(int j=i+1;j-i<=t&&j<=n;j++)
                    if(p[j]<p[i])
                        sl[i][t]+=ways[n-j][t-(j-i)];
                    else
                        sr[i][t]+=ways[n-j][t-(j-i)];
            }
        }
        while(q--)
        {
            int x,y;
            scanf("%lld%lld",&x,&y);
			// x=rand()%n+1,y=rand()%n*10+1;
            if(y>ways[n][c])
            {
                puts("-1");
                continue;
            }
            int pos=1,rm=c;
            while(pos<=n)
            {
				assert(rm>=0);
                if(!rm)
                {
                    printf("%lld\n",p[x]);
                    break;
                }
                int l=pos-1,r=n+1;
                while(r-l>1)
                {
                    int mid=(l+r)>>1;
                    if(y<=sl[mid][rm]-sl[pos-1][rm]||y>=ways[n-pos+1][rm]-(sr[mid][rm]-sr[pos-1][rm])+1)
                        r=mid;
                    else
                        l=mid;
                }
                if(x<r)
                {
                    printf("%lld\n",p[x]);
                    break;
                }
                y-=sl[r-1][rm]-sl[pos-1][rm];
                pos=r;
                vector<int>v;
                for(int i=pos;i-pos<=rm&&i<=n;i++)
                    v.push_back(i);
                sort(v.begin(),v.end(),cmp);
                int pl=-1,pr=-1;
				int sum=0;
				for(auto x:v)
					if(x!=pos)
						sum+=ways[n-x][rm-(x-pos)];
	            for(auto x:v)
                {
                    if(y<=ways[n-x][rm-(x-pos)])
                    {
                        pl=pos,pr=x;
                        break;
                    }   
                    y-=ways[n-x][rm-(x-pos)];
                }
                if(pl<=x&&x<=pr)
                {
                    printf("%lld\n",p[pl+pr-x]);
                    break;
                }
                pos=pr+1;
                rm-=(pr-pl);
            }
        }
    }  
}