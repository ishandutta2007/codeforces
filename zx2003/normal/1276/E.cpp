#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>P;
ll a[4],b[4],ga,gb,vv1,vv2;
int i;
namespace A{
int i,j,mx,x,y;
ll*a;
inline void upd1(int i,int j){
	if(a[j]*2-a[i]<=a[3] && a[j]-a[i]>mx)mx=a[j]-a[i],x=i,y=j;
}
inline void upd2(int i,int j){
	if(a[j]*2-a[i]>=a[0] && a[i]-a[j]>mx)mx=a[i]-a[j],x=i,y=j;
}
vector<P>work(ll*aa,int&id){
	a=aa;
	ll d=aa[3]-aa[0]<<4;
	vector<P>ret;
	for(;a[3]-a[0]<d;){
		if(a[0]!=a[3])ret.push_back({a[0],a[3]}),a[0]=2*a[3]-a[0];
		if(a[1]!=a[2])ret.push_back({a[1],a[2]}),a[1]=2*a[2]-a[1];
		std::sort(a,a+4);
	}
	for(;a[3]-a[0]>2;){
		mx=0;
		upd1(0,1);upd1(0,2);upd2(3,2);upd2(3,1);
		ret.push_back({a[x],a[y]});
		a[x]=2*a[y]-a[x];
		std::sort(a,a+4);
	}
	static P p[3];
	if(a[0]==a[1])p[0]={a[0],2},p[1]={a[2],1},p[2]={a[3],1};
	if(a[1]==a[2])p[0]={a[0],1},p[1]={a[1],2},p[2]={a[3],1};
	if(a[2]==a[3])p[0]={a[0],1},p[1]={a[1],1},p[2]={a[2],2};
	int o;
	for(;;){
		if(p[2].first<2)o=2;
			else if(p[0].first>0)o=0;
					else break;
		P t={2*p[o].first-p[2^o].first,p[2^o].second};
		for(i=0;i<t.second;++i)ret.push_back({p[2^o].first,p[o].first});
		p[2^o]=t;
		sort(p,p+3);
	}
++o,--o;
	for(;p[0].first<0 || p[2].first>2;){
if(ret.size()==40)
++i,--i;
		if(p[1].first<=0)o=0;else o=2;
		P t={2*p[1].first-p[o].first,p[o].second};
		for(i=0;i<t.second;++i)ret.push_back({p[o].first,p[1].first});
		p[o]=t;
		sort(p,p+3);
	}
	if(p[2].first==1){
		id=1;
		ret.push_back({0,1});
	}else for(i=0;i<3;++i)if(p[i].second==2)id=i;
	return ret;
}
}
int main(){
//	freopen("1","r",stdin);
	//freopen("2","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	for(i=0;i<4;++i)cin>>a[i];sort(a,a+4);
	ga=__gcd(__gcd(a[1]-a[0],a[2]-a[1]),a[3]-a[2]);
	for(i=0;i<4;++i)cin>>b[i];sort(b,b+4);
	gb=__gcd(__gcd(b[1]-b[0],b[2]-b[1]),b[3]-b[2]);	
	if(!ga && !gb){puts(a[0]==b[0]?"0":"-1");return 0;}
	if(ga!=gb || a[0]%ga!=b[0]%ga){puts("-1");return 0;}
	vv1=ga;vv2=a[0];
	for(i=0;i<4;++i)a[i]=(a[i]-vv2)/vv1,b[i]=(b[i]-vv2)/vv1;
	int ca=0,cb=0;
	for(i=0;i<4;++i)ca+=a[i]&1,cb+=b[i]&1;
	if(ca!=cb){puts("-1");return 0;}
	int ia,ib;
	auto v1=A::work(a,ia),v2=A::work(b,ib);
	reverse(v2.begin(),v2.end());for(P&u:v2)u.first=2*u.second-u.first;
	if(ia!=ib)v1.push_back({ia,1});
	v1.insert(v1.end(),v2.begin(),v2.end());
/*
	for(;;){
		for(i=0;i<v1.size() && v1[i].first!=v1[i].second;++i);
		if(i==v1.size())break;
		v1.erase(v1.begin()+i);
	}
*/
	cout<<v1.size()<<'\n';
	for(P u:v1)cout<<u.first*vv1+vv2<<' '<<u.second*vv1+vv2<<'\n';
	return 0;
}