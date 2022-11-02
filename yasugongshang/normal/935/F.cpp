#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<ctime>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define int long long
#define mp make_pair
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
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}
const int N=100005;
int c[N],tree[N<<2],p1[N<<2],p2[N<<2],q[N],tot,n,qq,a[N],sum;
#define lowbit(i) i&-i
inline void update(int pos,int de){
	for(int i=pos;i;i-=lowbit(i))c[i]+=de;
}
inline int get(int pos){
	int ans=0; if(!pos)return 0;
	for(int i=pos;i<N;i+=lowbit(i))ans+=c[i];
	return ans;
}
inline int ggg(int pos){
	return get(pos)-get(pos-1);
}
void insert(int l,int r,int pos,int nod){
	if(l==r){
		tree[nod]=abs(get(pos)-get(pos-1));
		if(ggg(l)>=0&&ggg(l+1)<=0)p1[nod]=pos; else p1[nod]=0;
		if(ggg(l)<=0&&ggg(l+1)>=0)p2[nod]=pos; else p2[nod]=0;
		//if(l==6)cout<<l<<" "<<"nfokangs"<<" "<<pos<<" "<<p2[nod]<<endl;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)insert(l,mid,pos,nod<<1); else insert(mid+1,r,pos,nod<<1|1);
	tree[nod]=min(tree[nod<<1],tree[nod<<1|1]);
	p1[nod]=max(p1[nod<<1],p1[nod<<1|1]);
	p2[nod]=max(p2[nod<<1],p2[nod<<1|1]);
}
void ask(int l,int r,int i,int j,int nod){
	if(i>j)return;
	if(l==i&&r==j){
		q[++tot]=nod; return;
	}
	int mid=(l+r)>>1;
	if(j<=mid)ask(l,mid,i,j,nod<<1); else if(i>mid)ask(mid+1,r,i,j,nod<<1|1);
	else{
		ask(l,mid,i,mid,nod<<1); ask(mid+1,r,mid+1,j,nod<<1|1);
	}
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read(); if(i>1)sum+=abs(a[i]-a[i-1]); update(i,a[i]); update(i-1,-a[i]);
	}
	qq=read();// writeln(sum);
	for(int i=1;i<=n;i++)insert(1,n,i,1);
	for(int i=1;i<=qq;i++){
		int t=read(),l=read(),r=read(),x=read();
		if(t==2){
			sum+=abs(get(l)+x-get(l-1))-abs(get(l)-get(l-1)); 
			sum+=abs(get(r+1)-get(r)-x)-abs(get(r+1)-get(r));
			//writeln(abs(get(r+1)-get));
			update(l-1,-x); update(r,x);
			
			//for(int i=1;i<=n;i++)cout<<get(i)<<" "; puts("");
			insert(1,n,l-1,1); insert(1,n,l,1); insert(1,n,l+1,1);
			insert(1,n,r-1,1); insert(1,n,r,1); insert(1,n,r+1,1);
		}else{
			int ans=-4e18;
			tot=0;
			ask(1,n,l,r,1); int t=0;
			for(int i=1;i<=tot;i++)t=max(t,p1[q[i]]);
			if(t){writeln(sum+2*x); continue;}
			for(int i=1;i<=tot;i++)t=max(t,p2[q[i]]); 
			if(t){
				tot=0; ask(1,n,l,t-1,1);
				for(int i=1;i<=tot;i++)ans=max(ans,sum+x+abs(tree[q[i]]-x)-abs(tree[q[i]]));
				ans=max(ans,sum+abs(get(t)-get(t-1)+x)-abs(get(t)-get(t-1))+abs(get(t+1)-get(t)-x)-abs(get(t+1)-get(t)));
				tot=0; ask(1,n,t+2,r+1,1);
				for(int i=1;i<=tot;i++)ans=max(ans,sum+x+abs(tree[q[i]]-x)-abs(tree[q[i]]));
			}else{
				tot=0; if(ggg(l)>=0)ask(1,n,l+1,r+1,1); else ask(1,n,l,r,1);
				for(int i=1;i<=tot;i++)ans=max(ans,sum+x+abs(tree[q[i]]-x)-abs(tree[q[i]]));
			}
			writeln(ans);
		}
	}
	//for(int i=1;i<=n;i++)cout<<get(i)<<" ";
}
/*
10
8 8 27 10 12 6 13 16 21 3 
1
1 6 7 4


*/