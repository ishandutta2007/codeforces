#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
struct P{
ll x,y;
inline void in(){scanf("%lld%lld",&x,&y);}
inline P operator-(const P&rhs)const{return (P){x-rhs.x,y-rhs.y};}
inline P operator+(const P&rhs)const{return (P){x+rhs.x,y+rhs.y};}
inline bool operator<(const P&rhs)const{return x==rhs.x?y<rhs.y:x<rhs.x;}
inline bool operator==(const P&rhs)const{return x==rhs.x && y==rhs.y;}
}a[N],ia[N];
typedef vector<P>V;
inline ll cross(const P&a,const P&b){return 1ll*a.x*b.y-1ll*b.x*a.y;}
int n,i;
void norm(V&a){
	rotate(a.begin(),min_element(a.begin(),a.end()),a.end());
}
int main(){
	scanf("%d",&n);
	for(i=0;i<n;++i)a[i].in(),ia[i]=(P){-a[i].x,-a[i].y};
	V a1(a,a+n),a2(ia,ia+n);
	norm(a1);norm(a2);
	for(i=a1.size()-1;i;--i)a1[i]=a1[i]-a1[i-1],a2[i]=a2[i]-a2[i-1];
	a2[0]=a1[0];
	puts(a1==a2?"YES":"NO");
	return 0;
}