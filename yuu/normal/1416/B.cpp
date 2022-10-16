#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int n;
long long a[100001];
class query{
public:
	int i, j, x;
	query(int i, int j, int x): i(i), j(j), x(x){}
};
vector <query> ans;
void solve(){
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	long long sum=0;
	for(int i=1; i<=n; i++) sum+=a[i];
	if(sum%n){
		cout<<"-1\n";
		return;
	}
	ans.clear();
	sum/=n;
	for(int i=2; i<=n; i++){
		int rem=a[i]%i;
		if(rem){
			rem=i-rem;
			ans.push_back(query(1, i, rem));
			a[1]-=rem;
			a[i]+=rem;
		}
		if(a[i]){
			ans.push_back(query(i, 1, a[i]/i));
			a[1]+=a[i];
			a[i]=0;;
		}
	}
	for(int i=2; i<=n; i++) ans.push_back(query(1, i, sum));
	cout<<ans.size()<<'\n';
	for(query q: ans) cout<<q.i<<' '<<q.j<<' '<<q.x<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	cin>>t;
	while(t--) solve();
}