#include <bits/stdc++.h>
using namespace std;
int n, m, s, e;
int a[100001];
int b[100001];
vector <int> pos[100001];
int f[301];
int main(){
	cin>>n>>m>>s>>e;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=m; i++) cin>>b[i];
	for(int i=1; i<=m; i++) pos[b[i]].push_back(i);
	int sz=s/e;
	for(int i=1; i<=sz; i++) f[i]=1e9;
	int ans=0;
	for(int i=1; i<=n; i++){
		if(pos[a[i]].empty()) continue;
		for(int j=sz-1; j>=0; j--){
			if(f[j]>=pos[a[i]].back()) continue;
			f[j+1]=min(f[j+1], *upper_bound(pos[a[i]].begin(), pos[a[i]].end(), f[j]));
		}
		ans++;
		if((ans>sz)||(ans*e+i+f[ans]>s)) ans--;
	}
	cout<<ans<<'\n';
}