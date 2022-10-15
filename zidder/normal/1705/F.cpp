#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <random>
#include <set>
#include <chrono>
#include <functional>

using namespace std;
mt19937 myrand(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<bool> msk;
int Q = 0;
int ask(vector<bool> b){
    cerr << Q << endl;
    Q++;
    string s="";
    for (int i=0;i<n;++i) s+=(b[i]==msk[i]?'T':'F');
    cerr << "send " << endl;
    cout << s << endl;
    fflush(stdout);
    int x;
    cin >> x;
    cerr << "get " << x << endl;
    if (x == -1) throw "error";
    if (x == n) exit(0);
    return x;
}

void solve(int test_ind) {
    map<int, map<vector<int>, pair<int, long double> > > mp; // l -> h -> move
    auto get_ans = [&](int a, int b, int l) {
        int c = 0;
        for (int i=0;i<l;++i) if ((a^b)&(1<<i)) c++;
        return l-c;
    };
    for (int l=1;l<=5;l++){
        map<vector<int>, pair<int, long double> > hp;
        vector<int> alll;
        for (int i=0;i<(1<<l);++i) alll.push_back(i);
        function<pair<int, long double>(vector<int>)> slvv = [&](vector<int> subs) -> pair<int, long double> {
            if (subs.size() < 2) return {0, 0};
            if (hp.find(subs) != hp.end()) {
                return hp[subs];
            }
            long double ans = 1000;
            int prev = 0;
            for (int q=0;q<(1<<l);++q) {
                map<int, vector<int> > anss;
                for (int s: subs) {
                    anss[get_ans(q, s, l) - get_ans(0, s, l)].push_back(s);
                }
                if (anss.size() == 1) continue;
                long double cur = 0;
                for (auto &p: anss) cur += slvv(p.second).second * p.second.size();
                cur /= subs.size();
                cur += 1;
                if (cur < ans) {
                    ans = cur;
                    prev = q;
                }
            }
            return hp[subs] = {prev, ans};
        };
        cerr << l << " " << slvv(alll).second << endl;
        mp[l] = hp;
    }
    

    // 4 -> 2.5
    cin >> n;
    msk = vector<bool>(n, true);
    // for (int i=0;i<n;++i) msk[i] = myrand() % 2;
    vector<bool> b(n);
    vector<bool> ans(n);
    int cf = ask(b);
    auto slv = [&](int l, int r) {
        vector<int> subs;
        for (int i=0;i<1<<(r-l);++i) subs.push_back(i);
        while (subs.size() > 1) {
            int q = mp[r-l][subs].first;
            for (int j=0;j<r-l;++j) b[l+j] = q&(1<<j);
            cerr << "query " << q << endl;
            int rs = ask(b) - cf;
            vector<int> subs2;
            for (int s: subs) {
                if (get_ans(q, s, r-l) - get_ans(0, s, r-l) == rs) subs2.push_back(s);
            }
            subs = subs2;
            // cout << "subs: "; for (int i: subs) cout << i << " "; cout << endl;
        }
        for (int j=0;j<r-l;++j) ans[l+j] = subs[0]&(1<<j);
    };
    for (int i=0;i<n;i+=5) {
        cerr << "cur " << i << endl;
        slv(i, min(i+5, n));
        // if (i > 500 && 8*Q>5*i) {cerr << "oops" << i/4 << " " << Q << endl;break;}
        // if (i < 500 && Q>600) {cout << 123 << endl;return;}
        for (int j=i;j<i+5;++j) b[j] = false;
    }
    cerr << "end" << endl;
    ask(ans);
    throw "error";
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}