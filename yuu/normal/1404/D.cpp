#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int n;
// void Test(){
	// vector <int> a;
	// int n=(rand())%100;;
	// (n*=2)+=1;
	// for(int i=0; i<n; i++) a.push_back(i);
// }
int p[1000001];
vector <int> pa[500001];
int pw[1000001];
bool done[1000001];
bool f[1000001];
void make(int u, bool b=0){
	if(done[u]) return;
	done[u]=1;
	f[u]=b;
	make(pw[u], !b);
	if(u<=n) make(u+n, !b);
	else make(u-n, !b);
}
void solve(){
	// for(long long n=1; n<=500000; n++){
		// if(((n-1)*(n)/2)%(n)==0){
			// if(n%2==0) cout<<n<<'\n';
		// }
	// }
	cin>>n;
	if(n%2==0){//can always win as first
		cout<<"First\n";
		cout.flush();
		for(int i=1; i<=n; i++) cout<<i<<' ';
		for(int i=1; i<=n; i++) cout<<i<<" \n"[i==n];
		cout.flush();
	}
	else{
		cout<<"Second\n";
		cout.flush();
		for(int i=1; i<=n*2; i++) cin>>p[i];
		for(int i=1; i<=n*2; i++) pa[p[i]].push_back(i);
		for(int i=1; i<=n; i++){
			pw[pa[i][0]]=pa[i][1];
			pw[pa[i][1]]=pa[i][0];
		}
		for(int i=1; i<=n*2; i++) make(i);
		int sum=0;
		for(int i=1; i<=n*2; i++) if(f[i]==1) (sum+=i)%=(n*2);
		bool good=(sum==0);
		for(int i=1; i<=n*2; i++) if(f[i]==good) cout<<i<<' ';
		cout<<'\n';
		cout.flush();
	}
	int res=0;
	cin>>res;
	assert(res==0);
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	// cin>>t;
	while(t--) solve();
}