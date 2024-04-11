#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
typedef long long ll;
int main(){
	int Xo;
	cin>>Xo;
	for(int N=4;N<=7;N++){
		int X = Xo;
		vector<int> vs;
		vector<ll> a(N+1);
		a[0] = 1;
		rep(i,100){
			rep(j,N) a[j+1] += a[j];
			if(a[N]>1e6) break;
			vs.pb(a[N]);
		}
		int K = vs.size();
		string pat;
		rep(i,N+1) pat += 'a'+i;
		string ans;
		for(int i=K-1;i>=0;i--){
			int v = vs[i];
			int q = X/v;
			X%=v;
			ans += string(q,pat[N]);
			if(ans.empty()) continue;
			for(int j=N-1;j>=0;j--) ans += pat[j];
		}
		if(ans.size()>200) continue;
		reverse(all(ans));
		cout<<ans<<" "<<pat<<endl;
		return 0;
	}

}