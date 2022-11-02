#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
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
inline void write(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
inline int rnd(int x){
	return (rand()<<16|rand())%x;
}
const int N=300005;
int n,tx,ty,ans,a[N],b[N],c[N],d[N],qx[N<<1],qy[N<<1],vis[N<<2];
int mx[N<<4],mn[N<<4];
vector<int> v[N<<1];
set<int> s[N<<3];
void push_up(int nod){
	mx[nod]=max(mx[nod<<1],mx[nod<<1|1]);
	mn[nod]=min(mn[nod<<1],mn[nod<<1|1]);
	if(s[nod].size()){if(vis[*s[nod].rbegin()])mn[nod]=max(mn[nod],*s[nod].rbegin());
	else mx[nod]=max(mx[nod],*s[nod].rbegin());}
	if(mx[nod]<mn[nod])mx[nod]=0;
}
void insert(int l,int r,int i,int j,int x,int nod){
	if(l==i&&r==j){
		if(x){
			if(x>0)s[nod].insert(x);
			else s[nod].erase(-x);
		}
		push_up(nod); return;
	}
	int mid=(l+r)>>1;
	if(j<=mid)insert(l,mid,i,j,x,nod<<1); else if(i>mid)insert(mid+1,r,i,j,x,nod<<1|1);
	else {insert(l,mid,i,mid,x,nod<<1); insert(mid+1,r,mid+1,j,x,nod<<1|1);}
	push_up(nod);
}

int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read(); b[i]=read(); c[i]=read(); d[i]=read()-1;
		qx[++tx]=a[i]; qx[++tx]=c[i]; for(int j=-1;j<=1;j++)qy[++ty]=b[i]+j; for(int j=-1;j<=1;j++)qy[++ty]=d[i]+j;
	}
	sort(&qx[1],&qx[tx+1]); sort(&qy[1],&qy[ty+1]); tx=unique(&qx[1],&qx[tx+1])-qx-1; ty=unique(&qy[1],&qy[ty+1])-qy-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(&qx[1],&qx[tx+1],a[i])-qx; c[i]=lower_bound(&qx[1],&qx[tx+1],c[i])-qx;
		b[i]=lower_bound(&qy[1],&qy[ty+1],b[i])-qy; d[i]=lower_bound(&qy[1],&qy[ty+1],d[i])-qy;
		v[a[i]].push_back(i); v[c[i]].push_back(-i);
	}
	for(int i=1;i<=tx;i++){
		for(unsigned j=0;j<v[i].size();j++)insert(1,ty,b[abs(v[i][j])],d[abs(v[i][j])],v[i][j],1);
		while(mx[1]){
			vis[mx[1]]=1; ans++;
			insert(1,ty,b[mx[1]],d[mx[1]],0,1);
		}
	}
	writeln(ans+1);
}