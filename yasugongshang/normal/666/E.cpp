#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<int>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
#define fi first
#define se second
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}

const int N=550005,M=N*2,K=20,MM=11000005,inf=1e9;
int last=1,tot=1,jb[N],len[M],go[M][26],pre[M],mn[M];
char S[N];
void clear(){
	for(int i=1;i<=tot;i++){
		len[i]=pre[i]; mn[i]=1e9; memset(go[i],0,sizeof(go[i]));
	}
	last=tot=1; len[0]=-1;
}
void add(int c){
	int p=last,np=++tot; last=np;
	len[np]=len[p]+1;
	for(;!go[p][c]&&p;p=pre[p])go[p][c]=np;
	if(!p)pre[np]=1; else{
		int q=go[p][c];
		if(len[q]==len[p]+1)pre[np]=q; else{
			int nq=++tot;
			memcpy(go[nq],go[q],sizeof(go[q]));
			len[nq]=len[p]+1; pre[nq]=pre[q];
			pre[q]=pre[np]=nq;
			while(go[p][c]==q){
				go[p][c]=nq; p=pre[p];
			}
		}
	}
}
vector<int> v[M];
char ch[N],s[N];
int lson[MM],rson[MM],dp[M][K],rt[M],Q[M],nodecnt,n;
PI tr[MM];
PI ask(int l,int r,int i,int j,int nod){
	if(!nod||i>j)return mp(0,-i);
	if(l==i&&r==j)return tr[nod];
	int mid=(l+r)>>1;
	if(j<=mid)return ask(l,mid,i,j,lson[nod]); else if(i>mid)return ask(mid+1,r,i,j,rson[nod]);
	else return max(ask(mid+1,r,mid+1,j,rson[nod]),ask(l,mid,i,mid,lson[nod]));
}
void push_up(int nod){
	tr[nod]=max(tr[lson[nod]],tr[rson[nod]]);
}
inline int merge(int a,int b){
	if(a==0||b==0)return a|b;
	int k=++nodecnt;
	lson[k]=merge(lson[a],lson[b]);
	rson[k]=merge(rson[a],rson[b]);
	if(!lson[k]&&!rson[k])tr[k]=mp(tr[a].fi+tr[b].fi,tr[b].se); 
	else push_up(k);
	return k;
}
void insert(int l,int r,int pos,int &nod){
	if(!nod)nod=++nodecnt;
	if(l==r){tr[nod].fi++; tr[nod].se=-pos; return;}
	int mid=(l+r)>>1;
	if(pos<=mid)insert(l,mid,pos,lson[nod]); else insert(mid+1,r,pos,rson[nod]);
	push_up(nod);
}
void init(int p){
	for(unsigned i=0;i<v[p].size();i++){
		init(v[p][i]); 
		rt[p]=merge(rt[p],rt[v[p][i]]);
	}
}
int get(int l,int r){
	int x=jb[r];
	Rep(i,K-1,0)if(dp[x][i]&&len[dp[x][i]]>=r-l+1)x=dp[x][i];
	return x;
}
int main(){
	scanf("%s",S+1);
	int len=strlen(S+1);
	For(i,1,len){add(S[i]-'a'); jb[i]=last;}
	int m=read();
	For(i,1,m){
		scanf("%s",S);
		int len=strlen(S);
		last=1;
		For(j,0,len-1){add(S[j]-'a'); insert(1,m,i,rt[last]); }
	}
	For(i,2,tot)v[dp[i][0]=pre[i]].pb(i);
	For(i,1,K-1)For(j,1,tot)dp[j][i]=dp[dp[j][i-1]][i-1];
	//For(i,1,tot)cout<<i<<" "<<pre[i]<<endl;
	init(1);
	int q=read();
	For(i,1,q){
		int l=read(),r=read(),pl=read(),pr=read();
		int nod=get(pl,pr); //cout<<jb[pl]<<" "<<nod<<endl;
		PI t=ask(1,m,l,r,rt[nod]);
		wri(-t.se); writeln(t.fi);
	}
}