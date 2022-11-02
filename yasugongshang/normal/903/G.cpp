#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define mp make_pair
#define int long long
const int N=200005;
int n,q,a[N],b[N],m;
int tree[N<<2],zs[N],sum[N];
vector<pair<int,int> > v[N];
int lazy[N<<2];
inline void cao(int nod,int x){
	tree[nod]+=x;
}
inline void pushdown(int p){
	if(!lazy[p])return;
	lazy[p<<1]+=lazy[p]; lazy[p<<1|1]+=lazy[p]; cao(p<<1,lazy[p]); cao(p<<1|1,lazy[p]); lazy[p]=0;
}
inline int ask(int l,int r,int i,int j,int nod){
	if (l==i&&j==r) return tree[nod];  
	pushdown(nod); int mid=(l+r)>>1;
	if (j<=mid) return ask(l,mid,i,j,nod<<1);
	else if(i>mid) return ask(mid+1,r,i,j,nod<<1|1);
	int left=ask(l,mid,i,mid,nod<<1);
	int right=ask(mid+1,r,mid+1,j,nod<<1|1);
	return min(left,right);
}
inline void insert(int l,int r,int i,int j,int s,int nod){
	if(l==i&&r==j){
		lazy[nod]+=s; cao(nod,s); return;
	}
    pushdown(nod); int mid=(l+r)>>1;
    if(j<=mid)insert(l,mid,i,j,s,nod<<1); else
    if(i>mid)insert(mid+1,r,i,j,s,nod<<1|1); else{
    	insert(l,mid,i,mid,s,nod<<1); insert(mid+1,r,mid+1,j,s,nod<<1|1);
	}
	tree[nod]=min(tree[nod<<1],tree[nod<<1|1]);
}
inline void build(int l,int r,int nod){
	if (l==r) {tree[nod]=b[l]; return;} int mid=(l+r)>>1; lazy[nod]=0;
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
	tree[nod]=min(tree[nod<<1],tree[nod<<1|1]);
}
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define getchar gc
inline int read(){
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void change(int l,int r,int pos,int s,int nod){
	if(l==r){
		tree[nod]=s; return;
	}
    int mid=(l+r)>>1;
    if(pos<=mid)change(l,mid,pos,s,nod<<1); else change(mid+1,r,pos,s,nod<<1|1);
	tree[nod]=min(tree[nod<<1],tree[nod<<1|1]);
}
inline int query(int l,int r,int k,int nod){
	if(l==r)return tree[nod]; int mid=(l+r)>>1;
	if(k<=mid)return query(l,mid,k,nod<<1); else return min(tree[nod<<1],query(mid+1,r,k,nod<<1|1));
}
void calc(){
	build(1,n,1); 
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			int t=min(ask(1,n,v[i][j].first,n,1),v[i][j].second); //cout<<f[i]<<" "<<v[i][j].second<<" "<<ask(1,n,v[i][j].first,n,1)<<" "<<t<<endl;
			//cout<<v[i][j].first<<" "<<n<<" "<<t<<" "<<f[i]<<" "<<ask(1,n,3,3,1)<<endl;
			insert(1,n,v[i][j].first,n,-t,1); zs[i]+=t; 
		}
	}
}
int op(){
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1; mid++;
		if(query(1,n,mid,1)-sum[mid]>=0)l=mid; else r=mid-1;
	}
	return sum[l]+min(query(1,n,l,1)-sum[l],zs[l+1]);
}
/*inline int query(){
	int ans=0,dq=2e9;
	for(int i=1;i<=n;i++){
		ans+=min(dq,zs[i]); dq-=min(dq,zs[i]); dq=min(dq,(int)a[i]); if(!dq)break;
	}
	return ans;
}*/
signed main(){
	n=read(); m=read(); q=read();
	for(int i=1;i<n;i++){a[i]=read(); b[i]=read();} b[n]=2e18;
	build(1,n,1);
	for(int i=1;i<=m;i++){
		int s=read(),t=read(),e=read();
		v[s].push_back(mp(t,e));
	}
	calc();
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+zs[i];
	for(int i=1;i<=n;i++){
		b[i]=a[i]+sum[i];
	}
	build(1,n,1);
	writeln(op());
	while(q--){
		int x=read(),w=read(); a[x]=w;
		change(1,n,x,w+sum[x],1); 
		writeln(op());
	}
}
/*
4 3 2
1 2
3 4
5 6
2 2 7
1 4 8
4 3 9
1 100
2 100
ycl[i]=min(a[k]+sum[k])
b[i]=min(b[i-1]-zs[i],a[i])
b[i]=min(a[k]-(sum[i]-sum[k]))
b[i]=min(a[k]+sum[k])-sum[i]
*/