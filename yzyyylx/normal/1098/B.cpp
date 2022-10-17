#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 300100
#define M 
using namespace std;

ll m,n,ans,a,b,cnt[2][N][4],zh[210],dp[N][4][4];
P last[N][4][4],pp;
char fz[4];
string str[N],tmp[N],A,B,C,D;

inline ll get(ll u,ll v)
{
	ll i,j,p,q,res=0;
	for(p=0;p<4;p++) if(p!=u && p!=v) break;
	for(q=p+1;q<4;q++) if(q!=u && q!=v) break;
	for(i=0;i<n;i++)
	{
		A[i]=(i&1)?fz[p]:fz[q];
		B[i]=(i&1)?fz[q]:fz[p];
		C[i]=(i&1)?fz[u]:fz[v];
		D[i]=(i&1)?fz[v]:fz[u];
	}
    for(i=0;i<m;i++)
	{
		ll c1,c2;
		c1=c2=0;
		if(i&1)
		{
			for(j=0;j<n;j++) c1+=(C[j]==str[i][j]),c2+=(D[j]==str[i][j]);
			if(c1>c2) tmp[i]=C,res+=c1;
			else tmp[i]=D,res+=c2;
		}
		else
		{
			for(j=0;j<n;j++) c1+=(A[j]==str[i][j]),c2+=(B[j]==str[i][j]);
			if(c1>c2) tmp[i]=A,res+=c1;
			else tmp[i]=B,res+=c2;
		}
	}
	/*
	for(i=0;i<m;i++)
	{
		cout<<tmp[i]<<endl;
	}
	cerr<<res<<endl;
	//*/
    return res;
}

inline ll cmp()
{
    ll i,j,res=0;
    for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		    res+=(str[i][j]==tmp[i][j]);
		}
	}
    return res;
}

int main()
{
    memset(dp,-0x3f,sizeof(dp));
    ios::sync_with_stdio(0);
    ll i,j,k,p,q,t;
    zh['A']=0,zh['G']=1,zh['T']=2,zh['C']=3;
    fz[0]='A',fz[1]='G',fz[2]='T',fz[3]='C';
    cin>>m>>n;
    for(i=0;i<m;i++) for(j=0;j<n;j++) tmp[i]+='0';
    for(i=0;i<n;i++) A+='0',B+='0',C+='0',D+='0';
    for(i=0;i<m;i++)
	{
		cin>>str[i];
		for(j=0;j<n;j++)
		{
		    cnt[i&1][j][zh[str[i][j]]]++;
		}
	}
    for(i=0;i<4;i++) for(j=0;j<4;j++) if(i!=j) dp[0][i][j]=cnt[0][0][i]+cnt[1][0][j];
    for(i=0;i<n-1;i++)
	{
		for(j=0;j<4;j++)
		{
		    for(k=0;k<4;k++)
			{
				if(j==k) continue;
				for(p=0;p<4;p++)
				{
				    if(p==j || p==k) continue;
				    for(q=0;q<4;q++)
					{
						if(q==p || q==j || q==k) continue;
						t=dp[i][j][k]+cnt[0][i+1][p]+cnt[1][i+1][q];
						if(dp[i+1][p][q] < t)
						{
						    dp[i+1][p][q]=t;
						    last[i+1][p][q]=mp(j,k);
						}
					}
				}
			}
		}
	}
    for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
		    if(i==j) continue;
		    if(dp[n-1][i][j]>ans)
			{
				a=i,b=j;
				ans=dp[n-1][i][j];
			}
		}
	}
    for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(i==j) continue;
			t=get(i,j);
			if(t>ans)
			{
				ans=t;
				pp=mp(i,j);
			}
		}
	}
    if(pp.fi || pp.se)
	{
		get(pp.fi,pp.se);
		for(i=0;i<m;i++) cout<<tmp[i]<<endl;
		return 0;
	}
    for(p=a,q=b,i=n-1;i>=0;i--)
	{
		tmp[0][i]=fz[p];
		tmp[1][i]=fz[q];
		pp=mp(p,q);
		p=last[i][pp.fi][pp.se].fi;
		q=last[i][pp.fi][pp.se].se;
	}
    for(i=0;i<m;i++)
	{
		cout<<tmp[i&1]<<endl;
	}
}
/*
5 5
GCTAG
CCCTA
TGAAC
TATTG
AGCGC
*/