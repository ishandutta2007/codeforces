// https://codeforces.com/problemset/problem/1091/H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>

using namespace std;

void solve(int test_ind){
	int n, f;
    cin >> n >> f;

    vector<int> primes(1, 2);
    for (int i=3;i<=200000;i+=2){
        bool is_prime = true;
        for (int j: primes){
            if (i%j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) primes.push_back(i);
    }

    set<int> double_primes;

    for (int i: primes){
        double_primes.insert(i);
        for (int j: primes){
            if (i * 1ll * j >= 200000) break;
            double_primes.emplace(i*j);
        }
    }

    vector<int> dprimes;
    for (int i: double_primes) dprimes.push_back(i);
    // cout << "Dprimes" << endl;
    bitset<200001> prevs[101], bp;
    for (int p: dprimes) bp.set(p);
    bp.set(f, 0);
    prevs[0] = bp;
    for (int i=1;i<=100;++i) prevs[i] &= 0;

    vector<int> grundy(2 * 100000, 0);

    for (int i=1;i<grundy.size();i++){
        while (prevs[grundy[i]][i]) grundy[i]++;
        prevs[grundy[i]] |= bp << i;
    }

    // int mx = 0;
    // for (int i: grundy) mx = max(mx, i);

    // cout << mx << endl;

    // cout << "Grundy done" << endl;

    int ans = 0;
    for (int i=0;i<n;++i){
        int b, w, r;
        scanf("%d%d%d", &b, &w, &r);

        ans ^= grundy[w - b - 1];
        ans ^= grundy[r - w - 1];
    }

    // cout << ans << endl;
    if (ans != 0) printf("Alice\nBob\n");
    else printf("Bob\nAlice\n");
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}