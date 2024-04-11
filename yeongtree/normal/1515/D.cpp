#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <tuple>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss
#define DEBUG

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, l, r; cin >> n >> l >> r;
        vector<int> A(l), B(r);
        for(auto &i : A) cin >> i;
        for(auto &i : B) cin >> i;
        if(l < r) swap(l, r), swap(A, B);
        map<int, int> M;
        int x = 0, y = 0, z = (l - r) / 2;
        for(auto i : A) ++M[i];
        for(auto i : B)
        {
            if(M[i] > 0) ++x, --M[i];
        }
        for(auto i : M) y += i.ss / 2;
        cout << z + (n / 2 - x - min(y, z)) << '\n';
    }
}