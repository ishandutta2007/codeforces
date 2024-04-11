#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,dam,x,y,z,rat[101000],cnt;
struct opt{
	ll tim,val;
};
vector<opt>vec,a[101000];
ll ans,sst,per;

bool cmp1(opt x,opt y){
	return x.tim==y.tim? x.val<y.val: x.tim<y.tim;
}
bool cmp2(opt x,opt y){
	return x.tim==y.tim? x.val>y.val: x.tim<y.tim;
}

#define in (st+now.tim*rat<=dam)
void doit(vector<opt>&the,ll rat){
	sort(the.begin(),the.end(),cmp1);
	ll sz=the.size(), st=dam+1, fl=0;
	opt now;
	for (ll i=0;i<sz;++i){
		now=the[i];
		if (!in){
			if (fl) vec.push_back((opt){rat?(dam-st)/rat:(ll)1e18,-1}), fl=0;
			if (!fl&&now.val<=dam) vec.push_back((opt){now.tim,1}), fl=1;
		}else{
			if (fl&&now.val>dam) vec.push_back((opt){now.tim-1,-1}), fl=0;
		}
		st=now.val-now.tim*rat;
	}
	if (fl) vec.push_back((opt){rat?(dam-st)/rat:(ll)1e18,-1}), fl=0;
}

void cg(opt now){
	if (now.tim>=1e18-1&&per) exit(0*puts("-1"));
	ans=max(ans,cnt*(now.tim*per+sst));
	cnt+=now.val;
	ans=max(ans,cnt*(now.tim*per+sst));
}

int main(){
	scanf("%I64d%I64d",&n,&m);
	cin>>sst>>per>>dam;
	for (ll i=1;i<=n;++i){
		scanf("%I64d%I64d%I64d",&x,&y,&z); rat[i]=z;
		if (x<=dam&&per) return 0*puts("-1");
		a[i].push_back((opt){0,y});
	}
	for (ll i=1;i<=m;++i){
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		a[y].push_back((opt){x,z});
	}
	for (ll i=1;i<=n;++i) doit(a[i],rat[i]);
	sort(vec.begin(),vec.end(),cmp2);
	for (ll i=0;i<vec.size();++i) cg(vec[i]);
	cout<<ans<<endl;
}