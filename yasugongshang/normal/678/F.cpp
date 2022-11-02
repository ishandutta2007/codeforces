#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<complex>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){
	if(a<=-4000000000000000000){
		puts("EMPTY SET"); return;
	}
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
#define PI pair<int,int>
const int N=300005;
vector<PI> v[N<<2];
PI que[N],val[N];
priority_queue<pair<PI,int> > qq;
int tong[N],n,pos[N],m,r[N],tot;
ll ans[N];
inline void insert(int l,int r,int i,int j,PI k,int nod){
	//if(nod)cout<<l<<" "<<r<<" "<<i<<" "<<j<<" "<<nod<<endl;
	if (l==i&&r==j){
		v[nod].push_back(k); return;
	}
	int mid=(l+r)>>1;
	if (j<=mid)insert(l,mid,i,j,k,nod<<1);
	else if(i>mid)insert(mid+1,r,i,j,k,nod<<1|1);
	else{
		insert(l,mid,i,mid,k,nod<<1); insert(mid+1,r,mid+1,j,k,nod<<1|1);
	}
}
inline void build(int nod){
	if(v[nod].size()<=1)return;
	int top=1;
	que[0]=v[nod][0]; que[1]=v[nod][1];
	for(int i=2;i<v[nod].size();i++){
		while(top&&(ll)(que[top].second-que[top-1].second)*(v[nod][i].first-que[top].first)<=(ll)(v[nod][i].second-que[top].second)*(que[top].first-que[top-1].first))top--;
		que[++top]=v[nod][i];
	}
	v[nod].resize(top+1);
	for(int i=0;i<=top;i++)v[nod][i]=que[top-i];
}
inline void build(int l,int r,int nod){//cout<<l<<" "<<r<<" "<<nod<<endl;
	build(nod);
	if(l==r)return;
	int mid=(l+r)>>1;
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
}
inline ll ask(int nod,int x){
	for(int i=v[nod].size()-1;i>=0;i--){
		if(i&&(ll)v[nod][i-1].first*x+v[nod][i-1].second>(ll)v[nod][i].first*x+v[nod][i].second)v[nod].pop_back(); else return (ll)v[nod][i].first*x+v[nod][i].second;
	}
	return -4e18;
}
inline ll ask(int l,int r,int pos,int q,int nod){
	if(l==r)return ask(nod,q);
	int mid=(l+r)>>1;
	if(pos<=mid)return max(ask(l,mid,pos,q,nod<<1),ask(nod,q)); else return max(ask(mid+1,r,pos,q,nod<<1|1),ask(nod,q));
}
struct data{
	int first,second,id;
}q[N];
inline bool cmp(data a,data b){
	return a.second<b.second;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		int op=read();
		if(op==1){
			int a=read(),b=read();
			val[pos[i]=++m]=mp(a,b); tong[m]=1;
		}else if(op==2){
			int t=pos[read()];
			r[t]=m++;
		}else{
			tot++; q[tot]=(data){m,read(),tot};
		}
	}
	for(int i=1;i<=m;i++)if(tong[i]){
		val[i].first=-val[i].first;qq.push(mp(val[i],i));val[i].first=-val[i].first;
	}
	while(!qq.empty()){
		int id=qq.top().second;
		insert(1,m,id,r[id]?r[id]:m,val[id],1);
		qq.pop();
	}
	if(m)build(1,m,1);
	sort(&q[1],&q[tot+1],cmp);
	for(int i=1;i<=tot;i++){
		//cout<<q[i].first<<" "<<q[i].second<<endl;
		ans[q[i].id]=m?(q[i].first?ask(1,m,q[i].first,q[i].second,1):(-4e18)):-4e18;
	}
	for(int i=1;i<=tot;i++)writeln(ans[i]);
}