#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
#define PI pair<int,int>
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
const int N=100005,M=1<<18|3;
const ll inf=1e18;
int n,ans,w[N],g[N],h[N];
ll lim,pre[N],suf[N],max_p[M],lazy[M],max_suf[M],sp[M];
vector<int> v[N];
stack<int> q;
inline void cao(int nod,ll de){
	lazy[nod]+=de; max_suf[nod]+=de; sp[nod]+=de;
}
inline void pushdown(int nod){
	if(lazy[nod]){
		cao(nod<<1,lazy[nod]); 
		cao(nod<<1|1,lazy[nod]);
		lazy[nod]=0;
	}
}
ll calc(int l,int r,ll dq,int nod){
	if(l==r)return dq-max_p[nod];
	pushdown(nod);
	int mid=(l+r)>>1;
	return dq>max_suf[nod<<1]?min(dq-max_p[nod<<1],calc(mid+1,r,dq,nod<<1|1)):
	min(sp[nod],calc(l,mid,dq,nod<<1));
}
#define push_up max_suf[nod]=max(max_suf[nod<<1],max_suf[nod<<1|1]),sp[nod]=calc(mid+1,r,max_suf[nod<<1],nod<<1|1)
void build(int l,int r,int nod){
	if(l==r){
		max_suf[nod]=max_p[nod]=suf[l]; return;
	}
	int mid=(l+r)>>1;
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
	max_p[nod]=max(max_p[nod<<1],max_p[nod<<1|1]);
	push_up; 
}
void insert(int l,int r,int i,int j,ll de,int nod){
	if(i>j)return;
	if(l==i&&r==j){
		cao(nod,de); return;
	}
	pushdown(nod);
	int mid=(l+r)>>1;
	if(j<=mid)insert(l,mid,i,j,de,nod<<1);
	else if(i>mid)insert(mid+1,r,i,j,de,nod<<1|1);
	else{
		insert(l,mid,i,mid,de,nod<<1);
		insert(mid+1,r,mid+1,j,de,nod<<1|1);
	}
	push_up;
}
int solve(int l,int r,ll dq,int nod){
	if(l==r)return dq-max_p[nod]>lim?0:l;
	pushdown(nod);
	int mid=(l+r)>>1;
	if(dq-max_p[nod<<1|1]<=lim)return solve(mid+1,r,dq,nod<<1|1);
	else return solve(l,mid,dq,nod<<1);
}
int ask(int l,int r,ll dq,int nod){
	if(l==r)return dq-max_p[nod]>lim?0:l;
	pushdown(nod);
	int mid=(l+r)>>1;
	if(sp[nod]>lim&&dq<=max_suf[nod<<1])return ask(l,mid,dq,nod<<1);
	int ans=ask(mid+1,r,max(dq,max_suf[nod<<1]),nod<<1|1);
	return ans?ans:solve(l,mid,dq,nod<<1);
}
void solve(int x){
	h[++*h]=x;
	int l=0,r=*h;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(pre[x]-pre[h[mid]]<=lim)r=mid-1; else l=mid;
	}
	insert(1,n,1,x-1,-inf,1);
	if(l)insert(1,n,h[l],n,inf,1);
	ans=max(ans,ask(1,n,-inf,1)-x+1);
	if(l)insert(1,n,h[l],n,-inf,1);
	insert(1,n,1,x-1,inf,1);
	for(auto i:v[x]){
		insert(1,n,x-1,n,pre[i]-pre[x],1); 
		solve(i); 
		insert(1,n,x-1,n,pre[x]-pre[i],1);
	}
	(*h)--;
}
int main(){
	n=read(); lim=read();
	for(int i=1;i<n;i++)w[i]=read();
	for(int i=1;i<=n;i++)g[i]=read();
	for(int i=1;i<n;i++){
		pre[i+1]=pre[i]-w[i]+g[i];
		suf[i+1]=suf[i]-w[i]+g[i+1];
	}
	build(1,n,1);
	for(int i=1;i<=n;i++){
		while(q.size()&&pre[i]<pre[q.top()]){
			v[i].push_back(q.top()); q.pop();
		}
		q.push(i);
	}
	while(q.size()){
		solve(q.top()); q.pop();
	}
	cout<<ans<<endl;
}