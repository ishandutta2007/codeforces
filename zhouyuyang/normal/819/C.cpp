#include<bits/stdc++.h>
#define pa pair<int,int>
#define ll long long
#define N 2000005
using namespace std;
int mn[N];
int n[3],m[3],s[3];
vector<pa> facn,facs;
ll nn,mm,ss,ans;
map<int,int> mp;
int find(pa x){
	int tmp=0;
	for (int i=0;i<facs.size();i++)
		if (facs[i].first==x.first)
			tmp=facs[i].second;
	return tmp;
}
void fact(int *n,vector<pa> &s){
	mp.clear();
	s.resize(0);
	for (int i=0;i<3;i++)
		for (int x=n[i];x>1;x/=mn[x])
			mp[mn[x]]++;
	for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
		s.push_back(pa(it->first,it->second));
}
void calc1(int n,ll x){
	if (x>nn) return;
	if (n==facs.size()){
		ans++;
		return;
	}
	for (int i=0;i<=facs[n].second;i++,x*=facs[n].first)
		calc1(n+1,x);
}
void calc2(int n,int v,ll x){
	if (!x) return;
	if (n==facn.size()){
		ans+=(v&1?-1:1)*x;
		return;
	}
	calc2(n+1,v,x);
	int tmp=find(facn[n]);
	if (tmp<facn[n].second){
		for (int i=1;i<=tmp+1;i++)
			x/=facn[n].first;
		calc2(n+1,v+1,x);
	}
}
void pre(){
	memset(mn,0,sizeof(mn));
	mn[0]=mn[1]=1;
	for (int i=2;i*i<N;i++){
		if (mn[i]) continue;
		mn[i]=i;
		for (int j=i*i;j<N;j+=i)
			if (!mn[j]) mn[j]=i;
	}
	for (int i=2;i<N;i++)
		if (!mn[i]) mn[i]=i;
}
void solve(){
	for (int i=0;i<3;i++)
		scanf("%d",&n[i]);
	for (int i=0;i<3;i++)
		scanf("%d",&m[i]);
	for (int i=0;i<3;i++)
		scanf("%d",&s[i]);
	s[0]*=2;
	nn=1ll*n[0]*n[1]*n[2];
	mm=1ll*m[0]*m[1]*m[2];
	ss=1ll*s[0]*s[1]*s[2];
	ans=0;
	fact(s,facs);
	calc1(0,1);
	fact(n,facn);
	calc2(0,0,mm);
	printf("%lld\n",ans);
}
int main(){
	pre();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}