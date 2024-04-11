#include <bits/stdc++.h>
using namespace std;

//using ll=long long;

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define repn(i,n) rng(i, 1, n+1)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define eb emplace_back
#define mp make_pair
#define si(x) int(x.size())
#define a first
#define b second
using P=pair<int,int>;
constexpr int INF = 1000000000;

template<class t>using vc=vector<t>;

using pi=pair<int,int>;
using vi=vc<int>;

int len, n, c[100005];
int a[100005], b[100005], tmp[100005];
P rng[100005];
int need[100005][2];
void slv(){
	cin>>len>>n;
	repn(i,n)cin>>c[i];
	if(n == 1){
		cout << 0 << " " << len << endl;
		return;
	}
	repn(i,n){
		a[i] = b[i] = 0;
	}
	a[1] = c[1], a[n] = len-c[n];
	for(int i=1;i<n;i++) b[i] = c[i+1]-c[i];
	
	int lb=0,ub=1000000000;
	while(ub-lb>1){
		int mid=(lb+ub)/2;
		repn(i, n) tmp[i] = a[i];
		int carry = 0;
		repn(i, n){
			if(tmp[i]+carry > mid) goto fail;
			tmp[i] += carry;
			if(i == n) break;
			int use = min(b[i], mid-tmp[i]);
			carry = b[i]-use;
		}
		ub = mid; continue;
		fail:; lb = mid;
	}
	P p = mp(-INF, INF);
	for(int mx=ub;mx<=ub+4;mx++){
		int lb=1, ub=mx+1;
		while(ub-lb>1){
			int mid=(lb+ub)/2;
			repn(i, n) rng[i] = mp(a[i], a[i]);
			repn(i, n){
				if(rng[i].a > rng[i].b or rng[i].a > mx) goto fail2;
				if(i == n){
					if(rng[i].b < mid) goto fail2;
					break;
				}
				
				int ll = mid-rng[i].b;
				int uu = mx-rng[i].a;
				if(ll < 0) ll = 0;
				if(uu > b[i]) uu = b[i];
				if(ll > uu) goto fail2;
				rng[i+1].a += b[i]-uu;
				rng[i+1].b += b[i]-ll;
			}
			lb = mid; continue;
			fail2:; ub = mid;
		}
		//cout << lb << " " << mx << endl;
		if(p.b-p.a > mx-lb) p = mp(lb, mx);
	}
	int mn = p.a, mx = p.b;
	{
		repn(i, n) rng[i] = mp(a[i], a[i]);
		repn(i, n-1){
			int ll = mn-rng[i].b;
			int uu = mx-rng[i].a;
			if(ll < 0) ll = 0;
			if(uu > b[i]) uu = b[i];
			rng[i+1].a += b[i]-uu;
			rng[i+1].b += b[i]-ll;
			need[i+1][0] = b[i]-uu;
			need[i+1][1] = b[i]-ll;
		}
		vc<int>len;
		int carry = 0;
		for(int i=n;i>=1;i--){
			//cout << i << " " << carry << endl;
			int now = a[i] + carry;
			if(i == 1){
				assert(mn <= now and now <= mx);
				len.eb(now);
				break;
			}
			//now+need[i][0] now+need[i][1]
			//mn mx
			int valmin = max(now+need[i][0], mn);
			int valmax = min(now+need[i][1], mx);
			int use=0;
			assert(valmax >= now);
			if(valmin <= now); 
			else{
				use = valmin-now;
				now = valmin;
			}
			len.eb(now);
			carry = b[i-1] - use;
		}
		reverse(len.begin(), len.end());
		//rep(i, len.size()) cout << len[i] << endl;
		int pre = 0;
		rep(i, len.size()){
			cout << pre << " " << pre+len[i] << '\n';
			assert(pre <= c[i+1] and c[i+1] <= pre+len[i]);
			pre += len[i];
		}
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t;t=1;//cin>>t;
	rep(_,t)slv();
}