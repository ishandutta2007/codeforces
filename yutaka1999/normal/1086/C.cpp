#include <bits/stdc++.h>
#define SIZE 1000005
#define ALP 30

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

char str[SIZE];
int nxt[ALP];
int mnxt[ALP];
bool use[ALP];

void solve()
{
	int K;
	scanf("%d",&K);
	string S,A,B;
	scanf("%s",&str);
	S=str;
	scanf("%s",&str);
	A=str;
	scanf("%s",&str);
	B=str;
	memset(nxt,-1,sizeof(nxt));
	memset(use,false,sizeof(use));
	bool up=true,va=false,vb=false;
	for(int i=0;i<S.size();i++)
	{
		if(A[i]==B[i])
		{
			if(use[A[i]-'a']&&nxt[S[i]-'a']!=A[i]-'a')
			{
				up=false;
				break;
			}
			if(nxt[S[i]-'a']!=-1&&nxt[S[i]-'a']!=A[i]-'a')
			{
				up=false;
				break;
			}
			nxt[S[i]-'a']=A[i]-'a';
			use[A[i]-'a']=true;
		}
		else if(nxt[S[i]-'a']!=-1)
		{
			int x=nxt[S[i]-'a'],a=A[i]-'a',b=B[i]-'a';
			if(x<a||b<x)
			{
				up=false;
				break;
			}
			if(a<x&&!va)
			{
				va=true;
				for(int j=i+1;j<S.size();j++) A[j]='a';
			}
			if(x<b&&!vb)
			{
				vb=true;
				for(int j=i+1;j<S.size();j++) B[j]='a'+(K-1);
			}
		}
		else
		{
			int x=S[i]-'a',a=A[i]-'a',b=B[i]-'a';
			bool XX=false;
			for(int j=a+1;j<b;j++)
			{
				if(!use[j])
				{
					nxt[x]=j;
					use[j]=true;
					XX=true;
					break;
				}
			}
			if(XX) break;
			for(int j=0;j<K;j++) mnxt[j]=nxt[j];
			if(!use[a])
			{
				bool now=true;
				nxt[x]=a;
				use[a]=true;
				for(int j=i+1;j<S.size();j++)
				{
					int t=S[j]-'a',x=A[j]-'a';
					if(nxt[t]!=-1)
					{
						//printf("* %d %d\n",nxt[t],x);
						if(nxt[t]<x)
						{
							now=false;
							break;
						}
						else if(x<nxt[t]) break;
					}
					else
					{
						int pos=-1;
						for(int k=x+1;k<K;k++) if(!use[k]) pos=k;
						if(pos!=-1)
						{
							nxt[t]=pos;
							use[pos]=true;
							break;
						}
						if(!use[x])
						{
							nxt[t]=x;
							use[x]=true;
						}
						else
						{
							now=false;
							break;
						}
					}
				}
				if(now) break;
				for(int j=0;j<K;j++) nxt[j]=mnxt[j];
				memset(use,false,sizeof(use));
				for(int j=0;j<K;j++) if(nxt[j]!=-1) use[nxt[j]]=true;
			}
			if(!use[b])
			{
				bool now=true;
				nxt[x]=b;
				use[b]=true;
				for(int j=i+1;j<S.size();j++)
				{
					int t=S[j]-'a',x=B[j]-'a';
					if(nxt[t]!=-1)
					{
						if(x<nxt[t])
						{
							now=false;
							break;
						}
						else if(nxt[t]<x) break;
					}
					else
					{
						int pos=-1;
						for(int k=0;k<x;k++) if(!use[k]) pos=k;
						if(pos!=-1)
						{
							nxt[t]=pos;
							use[pos]=true;
							break;
						}
						if(!use[x])
						{
							nxt[t]=x;
							use[x]=true;
						}
						else
						{
							now=false;
							break;
						}
					}
				}
				if(now) break;
			}
			up=false;
			break;
		}
	}
	if(!up)
	{
		puts("NO");
		return;
	}
	puts("YES");
	int pos=0;
	for(int j=0;j<K;j++)
	{
		if(nxt[j]==-1)
		{
			while(use[pos]) pos++;
			nxt[j]=pos;
			use[pos]=true;
		}
	}
	for(int j=0;j<K;j++) printf("%c",'a'+nxt[j]);
	puts("");
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}