#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int>v;
int n,f[101000],us[101000],t,x;
ll ans;

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&f[i]);
	for (int i=1;i<=n;i++){
		if (us[i]) continue;
		for (x=i,t=0;!us[x];x=f[x]) us[x]=1,t++;
		v.push_back(-t);
	}
	sort(v.begin(),v.end());
	v.push_back(0); v[1]+=v[0];
	for (int i=1;i<(int)v.size();i++) ans+=(ll)v[i]*v[i];
	cout<<ans;
}