#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e6+10;
int len[M];
int t[M][26];
char c[M];
int n,tot,tg[M];
vector<int> ed[M];
void ins(char *s,int nn,int id){
	int p=0;
	F(i,1,nn){
		int o=s[i]-'a';
		if (!t[p][o]) t[p][o]=++tot;
		p=t[p][o];
		ed[id].pb(p);
	}
	tg[p]=id;
}
int fail[M];
vector<int> v[M];
void build(){
	queue<int> q;
	F(i,0,25) if (t[0][i]) q.push(t[0][i]);
	while (q.size()){
		int x=q.front(); q.pop();
		v[fail[x]].pb(x);
		F(i,0,25){
			if (t[x][i]){
				fail[t[x][i]]=t[fail[x]][i];
				q.push(t[x][i]);
			}
			else t[x][i]=t[fail[x]][i];
		}
	}
}
int sz[M],dfn[M],tim;
void dfs(int x){
	dfn[x]=++tim; sz[x]=1;
	for (int y:v[x]){
		if (!tg[y]) tg[y]=tg[x];
		dfs(y);
		sz[x]+=sz[y];
	}
}
#define lowbit(x) (x&-x)
int d[M];
void add(int x,int o){
	for (;x<=tim;x+=lowbit(x)) d[x]+=o;
}
int qry(int x){
	int ret=0;
	for (;x;x-=lowbit(x)) ret+=d[x];
	return ret;
}
int sum(int l,int r){
	return qry(r)-qry(l-1);
}
int mt[M],oc[M];
bool in[M];
int main(){
	n=read();
	F(i,1,n){
		scanf("%s",c+1); len[i]=strlen(c+1);
		ins(c,len[i],i);
	}
	build();
	dfs(0);
	int ans=0;
	F(i,1,n){
		vector<int> cand;
		int ct=0;
		for (int ps:ed[i]){
//			cerr<<"pos : "<<dfn[ps]<<"\n";
			add(dfn[ps],1); ++ct; mt[ct]=0;
			if (ps==ed[i].back()){
				mt[ct]=tg[fail[ps]];
				if (tg[fail[ps]] && !in[tg[fail[ps]]]){
					in[tg[fail[ps]]]=1;
					cand.pb(tg[fail[ps]]);
				}
			}
			else{
				mt[ct]=tg[ps];
				if (tg[ps] && !in[tg[ps]]){
					in[tg[ps]]=1;
					cand.pb(tg[ps]);
				}
			}
//			cerr<<mt[ct]<<" ";
		}
//		cout<<"  match \n";
		int ml=len[i]+1;
		DF(j,len[i],1){
			int le=len[mt[j]];
			if (j-le+1<ml){
//				cerr<<mt[j]<<"  full match \n";
				oc[mt[j]]++;
				ml=j-le+1;
			}
		}
		for (int y:cand){
			in[y]=0; int pos=ed[y].back();
			int num=sum(dfn[pos],dfn[pos]+sz[pos]-1);
//			cout<<dfn[pos]<<" "<<dfn[pos]+sz[pos]-1<<" "<<tot<<"\n";
//			cout<<num<<" of "<<y<<" ?? \n";
			if (num==oc[y]) ans++;
			oc[y]=0;
		}
		for (int ps:ed[i]){
			add(dfn[ps],-1);
		}
//		cerr<<ans<<"  -------------------------\n";
	}
	cout<<ans<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/