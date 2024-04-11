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
const int M=4e5+10;
int lst=1,tot=1;
struct node{
	int ch[30],fa,len;
}t[M];
int pos[M];
void extend(int c,int ps){
//	cout<<char(c+'a')<<ps<<" "<<tot<<"  opoop\n";
	int np=++tot,p=lst; lst=np; t[np].len=t[p].len+1;
	while (p&&!t[p].ch[c]) t[p].ch[c]=np,p=t[p].fa; pos[ps]=np;
	if (!p) t[np].fa=1;
	else {
//		cout<<"cnm\n";
		int q=t[p].ch[c];
		if (t[q].len==t[p].len+1) t[np].fa=q;
		else {
			int nq=++tot; t[nq]=t[q]; t[nq].len=t[p].len+1;
			t[q].fa=t[np].fa=nq;
			while (p&&t[p].ch[c]==q) t[p].ch[c]=nq,p=t[p].fa; 
		}
	}
}
vector<int> v[M],g[M];
int st[M<<1][19],fir[M],ct,lg[M<<1];
int cp(int x,int y){
	return t[x].len<t[y].len ? x : y;
}
void dfs(int x){
//	cout<<t[x].fa<<" ->> "<<x<<"  o\n";
	fir[x]=++ct; st[ct][0]=x;
	F(i,0,SZ(v[x])){
		int y=v[x][i];
		dfs(y);
		st[++ct][0]=x;
	}
}
int lca(int x,int y){
	if (!x) return 0;
	if (fir[x]<fir[y]) swap(x,y);
	int len=lg[fir[x]-fir[y]+1];
//	cout<<st[fir[y]][len]<<" "<<st[fir[x]-(1<<len)+1][len]<<" "<<len<<"   cococo\n";
	return cp(st[fir[y]][len],st[fir[x]-(1<<len)+1][len]);
}
bool A[M],B[M];
int tmp[M],s[M],tp;
bool cmp(int x,int y){
	return fir[x]<fir[y];
}
int dp[M][2];
LL ans;
void dfs2(int x){
	int t0=0,t1=0;
	dp[x][0]=dp[x][1]=0;
	LL gg=0;
	F(i,0,SZ(g[x])){
		int y=g[x][i];
		dfs2(y);
		t0+=dp[y][0]; t1+=dp[y][1];
		gg+=1ll*dp[y][0]*dp[y][1];
	} 	
//	if (x==2) cout<<
//	cout<<x<<" "<<t[x].len<<" "<<t0*t1-gg+A[x]*t1+B[x]*t0+A[x]*B[x]<<"    omg\n";
	ans+=(1ll*t0*t1-gg+A[x]*t1+B[x]*t0+A[x]*B[x])*t[x].len;
	dp[x][0]=t0+A[x]; dp[x][1]=t1+B[x];
	g[x].clear();
}
int n,q;
char ch[M];
int main(){
	n=read(); q=read();
	scanf("%s",ch+1);
	DF(i,n,1) extend(ch[i]-'a',i);
	F(i,2,tot) v[t[i].fa].pb(i);
	F(i,2,n*4) lg[i]=lg[i>>1]+1;
	dfs(1);
	F(i,1,lg[ct]){
		for (int j=1;j+(1<<i)-1<=ct;j++){
			st[j][i]=cp(st[j][i-1],st[j+(1<<i-1)][i-1]);
		}
	}
//	cout<<tot<<"  qwq\n";
	F(i,1,q){
		int u=read(),v=read();
		int o=0;
		F(j,1,u){
			int x=read();
			A[pos[x]]=1; tmp[++o]=pos[x];
//			cout<<x<<" "<<pos[x]<<"     oooo\n";
		}
		F(j,1,v) {
			int x=read(); 
			B[pos[x]]=1; tmp[++o]=pos[x];			//cout<<x<<" "<<pos[x]<<"     ooo\n";

		}
		sort(tmp+1,tmp+o+1,cmp);
		tp=1; s[1]=1; 
		F(j,1,o){
			if (tmp[j]==tmp[j-1]) continue;
//			cout<<tmp[j]<<"   o\n";
			if (tp==1) {
				s[++tp]=tmp[j];
				continue;
			}
			int x=lca(s[tp],tmp[j]);
			if (x==s[tp]) s[++tp]=tmp[j];
			else {
				while (tp>1 && t[s[tp-1]].len>t[x].len) //cout<<s[tp-1]<<" -> "<<s[tp]<<"\n",
				g[s[tp-1]].pb(s[tp]),tp--;
				if (t[s[tp]].len>t[x].len) g[x].pb(s[tp--]);
				if (x^s[tp]) s[++tp]=x;
				s[++tp]=tmp[j];
			}
		}
		while (tp>1) //cout<<s[tp-1]<<" -> "<<s[tp]<<"\n",
		g[s[tp-1]].pb(s[tp]),tp--; 
		ans=0; dfs2(1);
		cout<<ans<<"\n";
		F(j,1,o){
			A[tmp[j]]=B[tmp[j]]=0;
		}
	}
	return 0;
}