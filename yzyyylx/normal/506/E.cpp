#include<bits/stdc++.h>
#define N 310
#define M 10007
using namespace std;

int n,m,L,ans,dp[N][N][N],sum[N];
char str[N];

inline void Add(int &u,int v){u+=v,u%=M;}
struct Jz
{
    int num[N][N];
    Jz(){memset(num,0,sizeof(num));}
    void clear(){memset(num,0,sizeof(num));}
    Jz operator * (const Jz &u) const
    {
	int i,j,k;
	Jz res;
	for(i=0; i<=L; i++)
	{
	    for(j=i; j<=L; j++)
	    {
		for(k=i; k<=L; k++)
		{
		    Add(res.num[i][j],num[i][k]*u.num[k][j]%M);
		}
	    }
	}
	return res;
    }
} dw,st,an;

inline Jz po(Jz u,int v)
{
    int i;
    Jz res;
    for(i=0;i<=L;i++) res.num[i][i]=1;
    for(;v;)
    {
	if(v&1) res=res*u;
	u=u*u;
	v>>=1;
    }
    return res;
}

int main()
{
    int i,j,k,t;
    scanf("%s%d",str+1,&m);
    n=strlen(str+1);
    dp[1][n][0]=1;
    for(i=1; i<=n; i++)
    {
	for(j=n; j>=i; j--)
	{
	    if(str[i]==str[j])
	    {
		for(k=0; k<=n; k++)
		{
		    if(!dp[i][j][k]) continue;
		    if(j-i>1) Add(dp[i+1][j-1][k],dp[i][j][k]);
		    else Add(sum[k],dp[i][j][k]);
		}
	    }
	    else
	    {
		for(k=0; k<=n; k++)
		{
		    if(!dp[i][j][k]) continue;
		    Add(dp[i+1][j][k+1],dp[i][j][k]);
		    Add(dp[i][j-1][k+1],dp[i][j][k]);
		}
	    }
	}
    }
    st.num[0][1]=1;
    st.num[0][n]=sum[0];
    t=(n+1)/2;
    L=n+t;
    for(i=1;i<n;i++)
    {
	dw.num[i][L-(n-i+1)/2]=sum[i];
	dw.num[i][i]=24;
	if(i<n-1) dw.num[i][i+1]=1;
    }
    for(i=n;i<L;i++)
    {
	dw.num[i][i]=25;
	dw.num[i][i+1]=1;
    }
    dw.num[L][L]=26;
    an=st*po(dw,(n+m+1)>>1);
    ans=an.num[0][L];
    if((n+m)&1)
    {
	dw.clear();
	memset(sum,0,sizeof(sum));
	for(i=1;i<n;i++)
	{
	    if(str[i]!=str[i+1]) continue;
	    for(j=0;j<=n;j++)
	    {
		Add(sum[j],dp[i][i+1][j]);
	    }
	}
	st.num[0][n]=sum[0];
	for(i=1;i<n;i++)
	{
	    dw.num[i][L-(n-i+1)/2]=sum[i];
	    dw.num[i][i]=24;
	    if(i<n-1) dw.num[i][i+1]=1;
	}
	for(i=n;i<L;i++)
	{
	    dw.num[i][i]=25;
	    dw.num[i][i+1]=1;
	}
	an=st*po(dw,(n+m+1)>>1);
	Add(ans,M-an.num[0][L]);
    }
    cout<<ans;
}