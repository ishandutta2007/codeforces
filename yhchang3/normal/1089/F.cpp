#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <complex>
#include <array>
#include <ctime>
#include <cassert>
#include <set>
#include <iomanip>
#include <random>
#include <cstdlib>
#include <chrono>

using namespace std;
const int M = 100010;
vector<int> primes;
int factors[M];
void gen() {
    for (int i = 2; i < M; i++) {
        if (factors[i] == 0) {
            factors[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (i * p >= M) break;
            factors[i * p] = p;
            if (i % p == 0) break;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    gen();
    int n;
    cin >> n;
    vector<int> ps;
    int target = n - 1;
    int Tb = n;
    for (int p: primes) {
        if (n % p == 0) ps.push_back(p);
        while (n % p == 0) n /= p;
    }
    if (n > 1) ps.push_back(n);
    if (ps.size() == 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int a = ps[ps.size() - 1];
        int b = ps[ps.size() - 2];
        vector<pair<int, int>> pb;
        for (int i = 0; i * a <= target; i++) {
            int j = (target - i * a) / b;
            if (j * b == target - i * a) {
                if (i > 0) pb.push_back({i, Tb / a});
                if (j > 0) pb.push_back({j, Tb / b});
                break;
            }
        }
        if (pb.size() > 0) {
            cout << pb.size() << endl;
            for (auto& p: pb) {
                cout << p.first << " " << p.second << endl;
            }
        } else {
            assert(false);
        }
    }
}