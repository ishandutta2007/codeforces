#include <bits/stdc++.h>
using namespace std;
int n;
int pos[100001];
int b[100001];
bool done[100002];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1, a; i<=n; i++){
		cin>>a;
		pos[a]=i;
	}
	for(int i=1; i<=n; i++){
		cin>>b[i];
		b[i]=pos[b[i]];
	}
	int mi=n+1;
	int ans=0;
	int now=1;
	for(int i=1; i<=n; i++){
		if(now!=b[i]) ans++;
		done[b[i]]=1;
		while(done[now]) now++;
	}
	cout<<ans<<'\n';
}