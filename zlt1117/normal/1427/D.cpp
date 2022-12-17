#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define rd (rand()<<16^rand())
#define pb push_back
using namespace std;
inline int gi()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=105;
int now[maxn],n;
int times=0;
vector<vector<int> >ans; 
inline void change(vector<int>k)
{
	vector<int>temp;temp.clear();
	int cnt=0;
	FOR(i,0,k.size()-1)if(k[i]!=0)cnt++;
	if(cnt==1)return;
	++times;
//	printf("%d ",cnt);
//	FOR(i,0,k.size()-1)if(k[i]!=0)printf("%d ",k[i]);
//	printf("\n");
	int sta=1;
	FOR(i,0,k.size()-1)
	{
		if(k[i]==0)continue;
		int ed=sta+k[i]-1;
		for(int j=ed;j>=sta;--j)temp.push_back(now[j]);
		sta=ed+1;
	}
	reverse(temp.begin(),temp.end());
	FOR(i,0,temp.size()-1)now[i+1]=temp[i];
	reverse(k.begin(),k.end());
	k.push_back(cnt);
	reverse(k.begin(),k.end());
	ans.push_back(k); 
//	cerr<<endl;
//	FOR(i,1,n)cerr<<now[i]<<' ';cerr<<endl<<endl;
}
int main()
{
	n=gi();
	FOR(i,1,n)now[i]=gi();
	vector<int>vec;
	FOR(i,1,n)
	{
		if(now[i]==1)
		{
			vec.push_back(i-1);
			vec.push_back(n-i+1);
			break;
		}
	}
	change(vec);
	FOR(i,2,n-1)
	{
		if(i&1)
		{
			int pos=0;
			FOR(j,1,n)if(now[j]==i){pos=j;break;}
			vec.clear();
			vec.push_back(pos-1);
			vec.push_back(n-pos-i+2);
			FOR(j,1,i-1)vec.push_back(1);
			change(vec);
		}
		else
		{
			int pos=0;
			FOR(j,i,n)if(now[j]==i){pos=j;break;}
			vec.clear();
			FOR(j,1,i-1)vec.push_back(1);
			vec.push_back(pos-i+1);
			vec.push_back(n-pos);
			change(vec);
		}
	}
	if(n&1&&n!=1)
	{
		vec.clear();
		FOR(i,1,n)vec.push_back(1);
		change(vec);
	}
	printf("%d\n",times);
	FOR(i,0,times-1)
	{
		FOR(j,0,ans[i].size()-1)if(ans[i][j]!=0)printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}
///