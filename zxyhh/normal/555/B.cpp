/*
	Author: zxy_hhhh
	date: 2019/03/29
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<set>
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
#define maxn 200005
int n,m;
ll L[maxn],R[maxn],a[maxn];
ll l[maxn],r[maxn];
struct node {
	ll l,r;
	int id;
	bool operator < (const node &B) const {
		return (l<B.l);
	}
}line[maxn];
int ans[maxn],id[maxn],tot;
multiset< pair<ll,int> > st;
inline bool cmp(int A,int B){return a[A]<a[B];}
int main()
{
	n=rd(),m=rd();
	rep(i,1,n) {
		L[i]=rd(),R[i]=rd();
		if (i>1){
			//wrt(L[i]-R[i-1],' '),wrt(R[i]-L[i-1],'\n');
			line[++tot]=node{L[i]-R[i-1],R[i]-L[i-1],i};
		}
	}
	rep(i,1,m) a[i]=rd(),id[i]=i;
	sort(id+1,id+1+m,cmp);sort(line+1,line+1+tot);
	int po=1;
	rep(i,1,m) {
		int x=id[i];
		while(po<=tot&&line[po].l<=a[x]) 
			st.insert(make_pair(line[po].r,line[po].id)),po++;
		multiset< pair<ll,int> >::iterator it;
		it=st.lower_bound(make_pair(a[x],0));
		if (it==st.end()) continue;
		if (it->first>=a[x]) ans[it->second]=x,st.erase(it);
	} 
	if (!st.empty()||po<=tot) {
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	rep(i,2,n) wrt(ans[i],' ');
	return 0;
}