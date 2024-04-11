#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
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
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=200005,M=400005,MM=20000005;
int last=1,tot=1,nodecnt,n,dp[M],len[M],go[M][26],pre[M],rig[M],rt[M];
vector<int> v[M];
char ch[N];
int lson[MM],rson[MM];
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
bool ask(int l,int r,int i,int j,int nod){
	if(!nod)return 0;
	if(l==i&&r==j)return 1;
	int mid=(l+r)>>1;
	if(j<=mid)return ask(l,mid,i,j,lson[nod]); else if(i>mid)return ask(mid+1,r,i,j,rson[nod]);
	else if(ask(mid+1,r,mid+1,j,rson[nod]))return 1; else return ask(l,mid,i,mid,lson[nod]);
}
inline int merge(int a,int b){
	if(a==0||b==0)return a|b;
	int k=++nodecnt;
	lson[k]=merge(lson[a],lson[b]);
	rson[k]=merge(rson[a],rson[b]);
	return k;
}
void insert(int l,int r,int pos,int &nod){
	if(!nod)nod=++nodecnt;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(pos<=mid)insert(l,mid,pos,lson[nod]); else insert(mid+1,r,pos,rson[nod]);
}
void init(int p){
	if(rig[p])insert(1,n,rig[p],rt[p]);
	for(unsigned i=0;i<v[p].size();i++){
		init(v[p][i]); if(!rig[p])rig[p]=rig[v[p][i]];
		rt[p]=merge(rt[p],rt[v[p][i]]);
	}
}
int ans;
void solve(int p,int dq){
	if(dq==0){dp[p]=1; dq=p;}else{
		if(ask(1,n,rig[p]-(len[p]-len[dq]),rig[p]-1,rt[dq])){dp[p]=dp[dq]+1; dq=p;}
		else dp[p]=dp[dq];
	}
	ans=max(ans,dp[p]);
	for(unsigned i=0;i<v[p].size();i++){
		solve(v[p][i],dq);
	}
}
signed main(){
	n=read();
	scanf("%s",ch+1);
	for(int i=1;i<=n;i++){
		add(ch[i]-'a'); rig[last]=i;
	}
	for(int i=2;i<=tot;i++)v[pre[i]].push_back(i);
	init(1);
	for(unsigned i=0;i<v[1].size();i++){solve(v[1][i],0); }
	cout<<ans<<endl;
}