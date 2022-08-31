#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <queue>

using namespace std;
typedef signed long long ll;

ll mod = 1000000007LL;
ll pow2[50];
ll dp[100][100][2];
ll n;
ll solve(int place, int rank, int flag) {
    if (place < 0) return 1;
    if (dp[place][rank][flag] != -1) return dp[place][rank][flag];
    ll res = 0;
    ll d = (1LL << place);
    if (flag) {
        if (n & d) {
            res = solve(place-1, rank+1, 1);
            res %= mod;
            if (rank) {
                res += solve(place-1, rank, 1) * pow2[rank-1];
                res %= mod;
                res += solve(place-1, rank, 0) * pow2[rank-1];
            } else {
                res += solve(place-1, rank, 0);
            }
        } else {
            res = solve(place-1, rank, 1) * ((!rank) ? 1 : pow2[rank-1]);
        }
    } else {
        res += solve(place-1, rank+1, 0);
        res %= mod;
        res += solve(place-1, rank, 0) * pow2[rank];
    }
    res %= mod;
    dp[place][rank][flag] = res;
    return res;
}

int main() {
    cin >> n;
    ll d = 1;
    for (int i = 0; i < 50; i++) {
        pow2[i] = d;
        d *= 2;
        d %= mod;
    }
    fill_n((ll *)dp, 100*100*2, -1);
    cout << solve(40, 0, 1) << endl;
    return 0;
}