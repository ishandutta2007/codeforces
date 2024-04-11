#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=100005,mod=1e9+7;
int n,h,w;
struct Node{
	int L,R,h,m,ans;
}a[N];
bool cmph(Node a,Node b){
	return a.h<b.h;
}
vector <int> s[N<<2];
void build(int rt,int L,int R){
	s[rt].push_back(1);
	if (L==R)
		return;
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	build(ls,L,mid);
	build(rs,mid+1,R);
}
void Push(vector <int> &s,int x){
	while (a[s.back()].m<a[x].m)
		s.pop_back();
	s.push_back(x);
}
void update(int rt,int L,int R,int xL,int xR,int d){
	if (L>xR||R<xL)
		return;
	if (xL<=L&&R<=xR){
		Push(s[rt],d);
		return;
	}
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	update(ls,L,mid,xL,xR,d);
	update(rs,mid+1,R,xL,xR,d);
}
int query(vector <int> &s,int h){
	while (a[s.back()].m<h)
		s.pop_back();
	return s.back();
}
int query(int rt,int L,int R,int x,int d){
	int ans=query(s[rt],d);
	if (L==R)
		return ans;
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	if (x<=mid)
		return max(ans,query(ls,L,mid,x,d));
	else
		return max(ans,query(rs,mid+1,R,x,d));
}
int main(){
	h=read(),w=read(),n=read();
	for (int i=1;i<=n;i++){
		a[i].h=read(),a[i].L=read(),a[i].R=read();
		a[i].m=min(a[i].h+read(),(LL)h+1);
	}
	n++;
	a[n].h=0,a[n].L=1,a[n].R=w,a[n].m=1.05e9;
	sort(a+1,a+n+1,cmph);
	a[1].ans=1;
	for (int i=0;i<(N<<2);i++)
		s[i].clear();
	build(1,1,w);
	for (int i=2;i<=n;i++){
		if (a[i].L==1)
			a[i].ans=2*a[query(1,1,w,a[i].R+1,a[i].h)].ans%mod;
		else if (a[i].R==w)
			a[i].ans=2*a[query(1,1,w,a[i].L-1,a[i].h)].ans%mod;
		else
			a[i].ans=(a[query(1,1,w,a[i].L-1,a[i].h)].ans
					 +a[query(1,1,w,a[i].R+1,a[i].h)].ans)%mod;
		update(1,1,w,a[i].L,a[i].R,i);
	}
	int ans=0;
	for (int i=1;i<=w;i++)
		ans=(ans+a[query(1,1,w,i,h+1)].ans)%mod;
	printf("%d",ans);
	return 0;
}