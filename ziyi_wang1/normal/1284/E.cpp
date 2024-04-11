#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define F(x,y,z) for(re x=y;x<=z;x++)
typedef long long ll;
typedef pair<ll,ll>pii;
struct Vec{
	ll x,y;
	Vec(ll _x=0,ll _y=0){x=_x;y=_y;}
	friend Vec operator + (Vec a,Vec b){return Vec(a.x+b.x,a.y+b.y);}
	friend Vec operator - (Vec a,Vec b){return Vec(a.x-b.x,a.y-b.y);}
	friend ll operator ^ (Vec a,Vec b){return a.x*b.y-a.y*b.x;}
	friend bool operator < (Vec a,Vec b){
		pii A=make_pair(a.x,a.y),B=make_pair(b.x,b.y);
		bool c=A<make_pair(0ll,0ll),d=B<make_pair(0ll,0ll);
		return c==d?(a^b)>=0:c<d;
	}
}p[2550];
vector<Vec>v;
ll n,m,ans,cnt;
ll C(ll x,ll y){
	re res=1;
	F(i,0,y-1){res*=(x-i);res/=(i+1);}
	return res;
}
int main(){
	cin>>n;
	F(i,1,n)cin>>p[i].x>>p[i].y;
	F(i,1,n){
		v.clear();
		F(j,1,n){
			if(i==j)continue;
			v.emplace_back(p[j]-p[i]);
		}		
		sort(v.begin(),v.end());
		m=0;
		F(j,0,v.size()-1){
			while(m<j+v.size()&&(v[j]^v[m%v.size()])>=0)m++;
			cnt+=C(m-j-1,3);
		}
	}
	ans=C(n,5)*5ll-cnt;
	cout<<ans;
	return 0;
}