#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;


void solve(int test_ind){
    long long n, r1, r2, r3, tel;
    cin >> n >> r1 >> r2 >> r3 >> tel;
    vector<long long> a(n);
    for(int i=0;i<n;++i)
        cin >> a[i];
    // damage = min((a[i] + 1) * r1, r2)
    // kill   = a[i] * r1 + r3
    vector<pair<long long, pair<long long, long long> > > d(n);
    // kill, damage + go back, damage all prev killed
    for (int i=0;i<n;++i){
        long long kill = a[i] * r1 + r3;
        long long damage = min((a[i] + 1) * r1, r2);
        if (i==0)
            d[0] = make_pair(kill,
                             make_pair(damage + r1,
                                       damage + r1));
        else if (i != n-1){
            d[i].first = min(d[i - 1].first + tel + kill,
                             d[i - 1].second.second + 3 * tel + min(kill, damage + r1));
            d[i].second.second = d[i - 1].first + tel + damage + r1;
            d[i].second.first  = min(d[i - 1].first + tel + damage + r1,
                                 min(d[i - 1].second.second + tel * 2 + min(kill, damage + r1),
                                     d[i - 1].second.first + tel * 2 + min(kill, damage + r1)));
        }
        else {
            d[i].first = min(d[i - 1].first + tel + kill,
                             d[i - 1].second.second + 3 * tel + min(kill, damage + r1));
            d[i].second.second = d[i - 1].first + tel * 3 + damage + r1;
            d[i].second.first  = min(d[i - 1].first + 3 * tel + damage + r1,
                                 min(d[i - 1].second.second + tel * 2 + min(kill, damage+r1+tel),
                                     d[i - 1].second.first + tel * 2 + min(kill, damage+r1+2*tel)));
            /*
            cout<< "hey\n";
            for (int j=0;j<n;++j)
                cout << d[j].first << " " << d[j].second.first << " " << d[j].second.second << endl;
            cout<< "hey\n";
            */
            cout << min(d[i].first, min(d[i].second.first, d[i].second.second)) << endl;
            return;
        }
    }
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}