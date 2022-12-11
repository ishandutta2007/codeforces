/*
	Author: zxy_hhhh
	date: 2019/03/29
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<set>
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
set<int> st;
multiset<int> num;
int n,a[200005],id[200005];
int mx[200005];
inline bool cmp(int A,int B) {return a[A]<a[B];}
int main()
{
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	n=rd();
	rep(i,1,n) a[i]=rd(),id[i]=i;
	sort(id+1,id+1+n,cmp);
	st.insert(0);st.insert(n+1);
	num.insert(n);
	rep(i,1,n) {
		mx[*num.rbegin()]=a[id[i]];
		int x=id[i];
		set<int>::iterator it=st.lower_bound(x);
		int p=*it;
		--it;
		int p1=*it;
		st.insert(x);
		num.erase(num.find(p-p1-1));
		num.insert(x-p1-1),num.insert(p-x-1);
	}
	drp(i,n,1) mx[i]=max(mx[i+1],mx[i]);
	rep(i,1,n) wrt(mx[i],' ');
	putchar('\n');
}