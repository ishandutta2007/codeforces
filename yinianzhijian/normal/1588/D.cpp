#include<bits/stdc++.h>
//#include<cstring>
//#include<iostream>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
int T;
int to[1000];
int f[55][1026];//  
int vis[55][1026];
pair<int,int>pr[55][1026];
int A[11][55],B[11][55];
char s[11][55];
int len[11];
char hs[1000];
int get(int chuan,int id,int op)
{
	if(op==0)return A[chuan][id];
	return B[chuan][id];
}
void dg(pair<int,int>p)
{
	if(p.first==53&&p.second==0)return;
	dg(pr[p.first][p.second]);
	cout<<hs[p.first];
}
signed main(){
	for(int i=0;i<26;i++)
	{
		to['a'+i]=i;
		hs[i]='a'+i;
	}
	for(int i=0;i<26;i++)
	{
		to['A'+i]=26+i;
		hs[26+i]='A'+i; 
	}
	T=read();
	while(T--)
	{
		memset(f,-0x3f,sizeof(f));
		memset(vis,0,sizeof(vis));
		memset(A,-1,sizeof(A));
		memset(B,-1,sizeof(B));
		int n=read();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s[i]+1);
			len[i]=strlen(s[i]+1);
			for(int j=1;j<=len[i];j++)
			{
				if(A[i][to[s[i][j]]]==-1)
					A[i][to[s[i][j]]]=j;
				else 
				B[i][to[s[i][j]]]=j;
			}
		}
		for(int i=1;i<=n;i++)A[i][53]=0;// 
		f[53][0]=0;
		queue<pair<int,int> >q;
		vis[53][0]=1;// 
		q.push(make_pair(53,0));
		int mx=0;
		pair<int,int>mxid;
		while(!q.empty())
		{
			int a=q.front().first,b=q.front().second;
//			cout<<a<<" "<<b<<"\n";
			q.pop();
			if(f[a][b]>mx)
			{
				mx=f[a][b];
				mxid=make_pair(a,b);
			}
			vis[a][b]=0;
			for(int i=0;i<=53;i++)// 
			{
				int vs=1;
				int id=0;
				for(int j=1;j<=n;j++)
				{
					if(get(j,i,0)>get(j,a,(b>>(j-1)&1)))
					{
						//0 
					}
					else if(get(j,i,1)>get(j,a,(b>>(j-1)&1)))
					{
						id+=(1<<(j-1));//1 
					}
					else 
					{
						vs=0;
						break;
					}
				}
				if(vs)
				{
					if(f[i][id]<f[a][b]+1)
					{
						pr[i][id]=make_pair(a,b);
						f[i][id]=f[a][b]+1;
						if(!vis[i][id])
						{
							vis[i][id]=1;
							q.push(make_pair(i,id));
						}
					}
				}
			}
		}
		cout<<mx<<"\n";
		if(mx)dg(mxid);
		puts("");
	}
	pc('1',1);
	return 0;
}