#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int mod=1000000007,sed1=1641,sed2=1641129,inv2=500000004;
int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
int po1[2000010],po2[2000010],phas1[2000010],phas2[2000010],shas1[2000010],shas2[2000010],cphas1[1000010],cphas2[1000010],cshas1[1000010],cshas2[1000010];
int n,q,p,len[1000],b[100010];
char s[2000020],t[100010],a[1000010];
int rt[1000];
int ch[1100010][26],fail[1100010],tot,pos[100010],cnt[1100010];
int ans[100010];
int coef[26];
vector<int>E[1100010];
struct query
{
	int p,c;
	friend bool operator < (query x,query y){return b[x.p]<b[y.p];}
}qry[1000010];
int qnum;
void buildhas()
{
	po1[0]=po2[0]=1;
	for(int i=1;i<=len[p];++i)
	{
		po1[i]=1ll*po1[i-1]*sed1%mod;
		po2[i]=1ll*po2[i-1]*sed2%mod;
		phas1[i]=(1ll*phas1[i-1]*sed1+s[i])%mod;
		phas2[i]=(1ll*phas2[i-1]*sed2+s[i])%mod;
	}
	for(int i=len[p];i;--i)
	{
		shas1[len[p]+1-i]=(shas1[len[p]-i]+1ll*s[i]*po1[len[p]-i])%mod;
		shas2[len[p]+1-i]=(shas2[len[p]-i]+1ll*s[i]*po2[len[p]-i])%mod;
	}
}
void ins(int p,int id)
{
	if(!rt[p])rt[p]=++tot;
	int u=rt[p],lena=strlen(a+1),c;
	for(int i=1;i<=lena;++i)
	{
		c=a[i]-'a';
		if(!ch[u][c])ch[u][c]=++tot;
		u=ch[u][c];
	}
	pos[id]=u;
}
void build()
{
	queue<int>q;
	for(int i=0;i<=p;++i)
		if(rt[i])
		{
			for(int j=0;j<26;++j)ch[0][j]=rt[i];
			q.push(rt[i]);
			while(!q.empty())
			{
				int x=q.front();q.pop();
				for(int k=0;k<26;++k)
					if(ch[x][k])q.push(ch[x][k]),fail[ch[x][k]]=ch[fail[x]][k],E[ch[fail[x]][k]].emplace_back(ch[x][k]);
					else ch[x][k]=ch[fail[x]][k];
			}
		}
}
void dfs(int v)
{
	for(auto u:E[v])
	{
		dfs(u);
		cnt[v]+=cnt[u];
	}
}
int main()
{
	scanf("%d %d",&n,&q);
	scanf("%s",s+1);
	scanf("%s",t+1);
	len[0]=strlen(s+1),p=0;
	while(len[p]<1000000)
	{
		s[len[p]+1]=t[p+1];
		for(int i=1;i<=len[p];++i)s[len[p]+1+i]=s[i];
		len[p+1]=len[p]*2+1;++p;
	}
	buildhas();
	for(int i=1;i<=q;++i)
	{ 
		scanf("%d %s",&b[i],a+1);
		ins(min(b[i],p),i);
		if(b[i]<=p)continue;
		int lena=strlen(a+1);
		for(int j=1;j<=lena;++j)
		{
			cphas1[j]=(1ll*cphas1[j-1]*sed1+a[j])%mod;
			cphas2[j]=(1ll*cphas2[j-1]*sed2+a[j])%mod;
		}
		for(int j=lena;j;--j)
		{
			cshas1[lena+1-j]=(cshas1[lena-j]+1ll*a[j]*po1[lena-j])%mod;
			cshas2[lena+1-j]=(cshas2[lena-j]+1ll*a[j]*po2[lena-j])%mod;
		}
		for(int j=1;j<=lena;++j)
			if(cphas1[j-1]==shas1[j-1]&&cphas2[j-1]==shas2[j-1]&&cshas1[lena-j]==phas1[lena-j]&&cshas2[lena-j]==phas2[lena-j])
				qry[++qnum]=query{i,a[j]};
	}
	build();
	for(int i=0;i<=p;++i)
		if(rt[i])
		{
			int u=rt[i];
			for(int j=1;j<=len[i];++j)
			{
				u=ch[u][s[j]-'a'];
				++cnt[u];
			}
			dfs(rt[i]);
		}
	for(int i=1;i<=q;++i)
	{
		if(b[i]<=p)ans[i]=cnt[pos[i]];
		else ans[i]=1ll*cnt[pos[i]]*kpow(2,b[i]-p)%mod;
	}
	// for(int i=1;i<=q;++i)printf("ans%d\n",ans[i]);
	sort(qry+1,qry+1+qnum);
	// for(int i=1;i<=qnum;++i)printf("qry%d %d\n",qry[i].p,qry[i].c);
	int pow2=1,ipow2=1,last=1;
	for(int i=1;i<=n;++i)
	{
		pow2=2*pow2%mod,ipow2=1ll*inv2*ipow2%mod;
		if(i>p)coef[t[i]-'a']=(coef[t[i]-'a']+ipow2)%mod;
		while(last<=qnum&&b[qry[last].p]==i)
		{
			ans[qry[last].p]=(ans[qry[last].p]+1ll*pow2*coef[qry[last].c-'a'])%mod;
			++last;
		}
	}
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
	return 0;
}