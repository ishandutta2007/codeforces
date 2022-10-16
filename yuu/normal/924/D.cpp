#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll w;
class fraction{
public:
	ll x, y;
	void fix(){
		if(y<0){
			y=-y;
			x=-x;
		}
		ll d=__gcd(abs(x), y);
		x/=d;
		y/=d;
	}
	fraction(ll _x=0, ll _y=1){
		x=_x;
		y=_y;
		fix();
	}
	friend bool operator <(const fraction e, const fraction f){
		return e.x*f.y<e.y*f.x;
	}
	friend bool operator <=(const fraction e, const fraction f){
		return e.x*f.y<=e.y*f.x;
	}
	friend bool operator ==(const fraction e, const fraction f){
		return e.x*f.y==e.y*f.x;
	}
	friend bool operator !=(const fraction e, const fraction f){
		return e.x*f.y!=e.y*f.x;
	}
	friend bool operator >(const fraction e, const fraction f){
		return e.x*f.y>e.y*f.x;
	}
	friend bool operator >=(const fraction e, const fraction f){
		return e.x*f.y>=e.y*f.x;
	}
	friend ostream& operator <<(ostream& out, fraction f){
		out<<setprecision(6)<<fixed<<((double)f.x)/f.y;
		return out;
	}
};
vector <pair<fraction, fraction>> f;
void input(){
	///(v[i]+w)/x[i]=(v[j]+w)/x[j]
	ll x, v;
	cin>>x>>v;
	f.push_back(make_pair(fraction(x, v-w), fraction(x, v+w))); 
}
class dumbclass{
public:
	vector <fraction> f[20];
	int sz;
	void insert(fraction A){
		// f[0].push_back(A);
		sz++;
		vector <fraction> temp;
		temp.push_back(A);
		for(int i=0; i<20; i++){
			if(f[i].empty()){
				swap(f[i], temp);
				return;
			}
			vector <fraction> next;
			next.resize(temp.size()+f[i].size());
			merge(temp.begin(), temp.end(), f[i].begin(), f[i].end(), next.begin());
			swap(temp, next);
			f[i].clear();
		}
	}
	int get(fraction p){
		int ans=0;
		for(int i=0; i<20; i++) if(!f[i].empty()){
			if(f[i].back()<=p) ans+=f[i].size();
			else ans+=upper_bound(f[i].begin(), f[i].end(), p)-f[i].begin();
		}
		// for(auto x: f[0]) ans+=p>=x;
		return ans;
	}
	void clear(){
		for(int i=0; i<20; i++) f[i].clear();
		sz=0;
	}
} dc;
map <fraction, int> s;
int main(){
	cin>>n>>w;
	for(int i=1; i<=n; i++) input();
	sort(f.begin(), f.end(), [](pair <fraction, fraction> A, pair <fraction, fraction> B){
		if(A.first!=B.first) return A.first>B.first; else return A.second<B.second;
	});
	long long ans=0;
	int i=0;
	// ans-=n;
	// for(auto p: f) ans+=s[p.first];
	for(auto p: f){
		// while(i<f.size()){
			// if(f[i]>p){
				// dc.insert(f[i].second);
				// i++;
			// }
			// else break;
		// }
		ans+=dc.get(p.second);
		dc.insert(p.second);
	}
	// for(auto p:f[0]) for(auto q: f[1]){
		// if(p.first<=q.first) ans+=p.second>=q.second; else ans+=p.second<=q.second;
		// cerr<<ans<<'\n';
		// cerr<<p.first<<' '<<p.second<<'\n';
		// cerr<<q.first<<' '<<q.second<<'\n';
	// }
	cout<<ans<<'\n';
}