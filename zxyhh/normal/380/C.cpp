/*
	Author: zxy_hhhh
	date: 2019/03/29
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define ll long long
using namespace std;
inline ll rd()
{
	ll _x=0;int _ch=getchar(),_f=1;
	for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
	if (_ch=='-'){_f=0;_ch=getchar();}
	for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
	return _f?_x:-_x;
}
void write(ll _x){if (_x>=10) write(_x/10),putchar(_x%10+'0'); else putchar(_x+'0'); }
inline void wrt(ll _x,char _p){if (_x<0) putchar('-'),_x=-_x; write(_x); if (_p) putchar(_p);}
#define maxn 1000005
struct data {
	int s,l,r;
};
data merge(data A,data B) {
	data ans;
	ans.s=A.s+B.s;
	int x=min(A.l,B.r);
	ans.l=A.l+B.l-x,ans.r=A.r+B.r-x;
	ans.s+=x*2;
	return ans;
}
char s[maxn];
data tr[maxn<<2];
void build(int pos,int l,int r) {
	if (l==r) {
		if (s[l]=='(') tr[pos]=(data){0,1,0};
		else tr[pos]=(data){0,0,1};
		return ;
	}
	int mid=(l+r)>>1;
	build(pos<<1,l,mid),build(pos<<1|1,mid+1,r);
	tr[pos]=merge(tr[pos<<1],tr[pos<<1|1]);
}
data query(int pos,int l,int r,int ql,int qr) {
	if (r<ql||l>qr) return data{0,0,0};
	if (ql<=l&&r<=qr) return tr[pos];
	int mid=(l+r)>>1;
	return merge(query(pos<<1,l,mid,ql,qr),query(pos<<1|1,mid+1,r,ql,qr));
}
int main()
{
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	build(1,1,n);
	int m=rd();
	rep(i,1,m) {
		int l=rd(),r=rd();
		wrt(query(1,1,n,l,r).s,'\n');
	}
}