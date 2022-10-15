// Full Binary Tree Queries
#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int get_lvl(ll x){
	int c = 0;
	while(x > 1){
		c++;
		x >>= 1;
	}
	return c;
}

void shift_level(int lvl, ll cnt, vector<ll>& shifts){
	ll mod = (1ll << lvl);
	(shifts[lvl] += mod - cnt) %= mod;
}

int main(){
	vector<ll> shifts(61, 0);
	vector<ll> parshifts(61, 0);
	int q;
	cin >> q;
	for(int i=0;i<q;++i){
		int c;
		cin >> c;
		if(c == 1){
			ll x, k;
			cin >> x >> k;
			shift_level(get_lvl(x), k, shifts);		
		}
		if (c == 2){
			ll x, k;
			cin >> x >> k;
			shift_level(get_lvl(x), k, parshifts);
		}
		if (c == 3){
			ll x;
			cin >> x;
			int lvl = get_lvl(x);
			((x += (1ll << lvl) - shifts[lvl]) %= (1ll << lvl)) += (1ll << lvl);
			while(lvl){
//				cout << x << " " << shifts[lvl] << " " << parshifts[lvl] << endl;
				ll mod = (1ll << lvl);
				ll val = (x + shifts[lvl]) % mod + mod;
				x = ((x + mod - parshifts[lvl]) % mod + mod) / 2;
				cout << val << " ";
				lvl--;
			}
			cout << 1 << endl;
		}
	}
	return 0;
}