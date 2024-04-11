// https://codeforces.com/contest/1614/problem/D1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>

using namespace std;

void solve(int test_ind){
	int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    vector<int> primes;
    const int MAX = 20000001;
    vector<int> prev(MAX);
    auto eratosfen = [&](int n) {
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= n; ++i) {
            if (is_prime[i]) {
                prev[i] = i;
                primes.push_back(i);
                if (i * 1ll * i > n) continue;
                for (int j = i * i; j <= n; j += i) {
                    is_prime[j] = false;
                    prev[j] = i;
                }
            }
        }
    };

    eratosfen(MAX);

    unordered_map<int, long long > anss;
    vector<int> count(MAX);

    for (int j: a) {
        count[j]++;
        if (j > 1) count[1]++;
        for (int i=2;i*i<=j;i++){
            if (j%i == 0){
                count[i]++;
                if (i * i != j) count[j/i]++;
            }
        }
    }

    function<long long(int)> get_ans = [&](int v){
        if (count[v] == 0) return 0ll;
        if (anss.find(v) != anss.end()) return anss[v];
        long long ans = count[v];
        for (int i: primes){
            if (v * i < MAX) {
                long long nxt = get_ans(v * i);
                if (nxt == 0) continue;
                if (nxt * i + count[v] - count[v * i] > ans){
                    ans = nxt * i + count[v] - count[v * i];
                }
            }
            else
                break;
        }
        return anss[v] = ans;
    };

    cout << get_ans(1) << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}