#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e6+5,mod=1e9+7;
string s;
int f[maxn],g[maxn];
struct PAM
{
	#define S(u,i) t[u].ch[i]
	#define F(u) t[u].fa
	#define L(u) t[u].len
	struct node{int ch[26],len,fa,tp,d;}t[maxn];int cnt=1,ls;
	int getfail(int pos,int x){while(x-L(pos)-1<0||s[x-L(pos)-1]!=s[x])pos=F(pos);return pos;}	
	PAM(){F(0)=1;L(1)=-1;}
	void insert(int x)
	{
		int pos=getfail(ls,x);int now=s[x]-'a';
		if(!S(pos,now))
		{
			cnt++;
			F(cnt)=S(getfail(F(pos),x),now);
			S(pos,now)=cnt;
			L(cnt)=L(pos)+2;
			t[cnt].d=L(cnt)-L(F(cnt));
			if(t[cnt].d==t[F(cnt)].d)t[cnt].tp=t[F(cnt)].tp;
			else t[cnt].tp=F(cnt);
		}
		ls=S(pos,now);
	}
}T;
int main()
{
	string tmp;cin>>tmp;
	for(int i=0;i<tmp.size()/2;i++)s.push_back(tmp[i]),s.push_back(tmp[tmp.size()-1-i]);
	f[0]=1;
	for(int i=1;i<=s.size();i++)
	{
		T.insert(i-1);
		for(int now=T.ls;now>1;now=T.t[now].tp)
		{
			g[now]=f[i-T.L(T.t[now].tp)-T.t[now].d];
			if(T.t[now].d==T.t[T.F(now)].d)(g[now]+=g[T.F(now)])%=mod;
			if(i%2==0)(f[i]+=g[now])%=mod;
		}
	}
	printf("%d\n",f[s.size()]);
	return 0;
}