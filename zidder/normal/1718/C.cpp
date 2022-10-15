#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	// max number of divisors 160
    int n;
    cin >> n;
    vector<int> divs;
    for (int i=1;i<n;++i) {
        if (n%i == 0) {
            divs.push_back(i);
        }
    }

    vector<int> divs2;
    for (int i=(int)divs.size()-1;i>=0;--i) {
        bool ok = true;
        for (int j: divs2) if (j % divs[i] == 0) {ok = false; break;}
        if (ok) divs2.push_back(divs[i]);
    }
    divs = divs2;
    // for (int i: divs) cerr << i << " ";cerr << endl;

    int q;
    cin >> q;
    vector<int> a(n);
    for (int &i: a) cin >> i;

    multiset<long long> st;
    vector<vector<long long> > v;
    for (int i: divs) {
        v.emplace_back(i);
        for (int j=0;j<i;++j) {
            long long sm = 0;
            for (int k=j;k<n;k+=i) {
                sm += a[k];
            }
            v.back()[j] = sm;
            st.insert(sm * i);
        }
    }
    
    printf("%lld\n", *st.rbegin());
    for (int i=0;i<q;++i) {
        int ind, val;
        cin >> ind >> val;
        ind--;

        for (int dind=0;dind<divs.size();++dind) {
            int d = divs[dind];
            st.erase(st.find(v[dind][ind % d] * d));
            v[dind][ind%d] -= a[ind];
            v[dind][ind%d] += val;
            st.insert(v[dind][ind % d] * d);
        }
        a[ind] = val;
        printf("%lld\n", *st.rbegin());
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}