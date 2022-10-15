#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e6+5;
string s;
int f[maxn],g[maxn],pos[maxn],pre[maxn];
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
	string tmp0,tmp1;cin>>tmp0>>tmp1;
	for(int i=0;i<tmp0.size();i++){s.push_back(tmp0[i]);s.push_back(tmp1[i]);}
	memset(f,0x3f,sizeof f);
	memset(g,0x3f,sizeof g);
	f[0]=0;
	for(int i=1;i<=s.size();i++)
	{
		T.insert(i-1);
		if(i%2==0&&s[i-1]==s[i-2])f[i]=f[i-2],pre[i]=i-2;
		for(int now=T.ls;now>1;now=T.t[now].tp)
		{
			g[now]=f[i-T.L(T.t[now].tp)-T.t[now].d];pos[now]=i-T.L(T.t[now].tp)-T.t[now].d;
			
			if(T.t[now].d==T.t[T.F(now)].d&&g[now]>g[T.F(now)])
			{
				g[now]=g[T.F(now)];
				pos[now]=pos[T.F(now)];
			}
			if(i%2==0&&g[now]+1<f[i])
			{
				f[i]=g[now]+1;
				pre[i]=pos[now];
				
			}
		}
	}
	if(f[s.size()]>s.size())puts("-1");
	else
	{
		printf("%d\n",f[s.size()]);
		int now=s.size();
		while(now){if(pre[now]+2!=now)printf("%d %d\n",(pre[now]+2)/2,now/2);now=pre[now];}
	}
	return 0;
}