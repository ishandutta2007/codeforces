#include <bits/stdc++.h>
using namespace std;
int n;
int a[1001];
void solve(){
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	int cur=0;
	for(int turn=1; turn<=n; turn++){
		int	id=0;
		int best=0;
		for(int i=1; i<=n; i++) if(a[i]){
			int temp=__gcd(cur, a[i]);
			if(temp>best){
				best=temp;
				id=i;
			}
		}
		cur=best;
		cout<<a[id]<<" \n"[turn==n];
		a[id]=0;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}