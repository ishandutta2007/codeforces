#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=2e5+10;
int n,k;
int lst=1,tot=1;
struct node{
	int fa,len,c[26];
}t[M];
string s[M];
vector<int> ed[M];
void extend(int o){
	int p=lst,np=++tot; lst=tot; t[np].len=t[p].len+1;
	while (p && !t[p].c[o]) t[p].c[o]=np,p=t[p].fa;
	if (!p) t[np].fa=1;
	else{
		int q=t[p].c[o];
		if (t[q].len==t[p].len+1) t[np].fa=q;
		else{
			int nq=++tot; t[nq]=t[q]; t[nq].len=t[p].len+1;
			t[np].fa=t[q].fa=nq;
			while (p && t[p].c[o]==q) t[p].c[o]=nq,p=t[p].fa;
		}
	}
}
int la[M],sz[M],val[M];
bool vis[M];
void dfs(int x){
	if (!x || vis[x]) return ;
	vis[x]=1; dfs(t[x].fa); 
	val[x]+=val[t[x].fa];
}
int main(){
	n=read(); k=read();
	F(i,1,n){
		cin>>s[i];
		lst=1;
		F(j,0,SZ(s[i])){
			extend(s[i][j]-'a');
		}
	}
	F(i,1,n){
		int ps=1;
		F(j,0,SZ(s[i])){
			int o=s[i][j]-'a';
			ps=t[ps].c[o];
			ed[i].pb(ps);
			int x=ps;
			while (x && la[x]!=i){
				la[x]=i;
				sz[x]++;
				x=t[x].fa;
			}
		}
	}
	F(i,1,tot) val[i]=(sz[i]>=k ? t[i].len-t[t[i].fa].len : 0);
	F(i,1,tot) dfs(i); 
    F(i,1,n){
    	LL ans=0;
    	for (int x:ed[i]) ans+=val[x];
    	cout<<ans<<" ";
	}
	return 0;
}