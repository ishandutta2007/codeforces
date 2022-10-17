#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <deque>
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
        int n; cin >> n;
        int A[n]; for(auto &i : A) cin >> i;
        int L[n], R[n];
        for(int i = 0; i < n; ++i) L[i] = i - 1, R[i] = i + 1;
        L[0] = n - 1; R[n - 1] = 0;
        deque<int> K;
        for(int i = 0; i < n; ++i)
        {
            int j = (i + 1) % n;
            if(__gcd(A[i], A[j]) == 1) K.push_back(j);
        }
        vector<int> ans;
        while(K.size())
        {
//            #ifdef DEBUG
//                cout << endl;
//                cout << "K" << endl;
//                for(auto x : K) cout << x << ' '; cout << endl;
//                cout << endl;
//            #endif
            int x = K[0]; K.pop_front();
            ans.push_back(x);
            if(K.size() && K[0] == R[x]) K.pop_front();
            if(__gcd(A[L[x]], A[R[x]]) == 1) K.push_back(R[x]);
            L[R[x]] = L[x];
            R[L[x]] = R[x];
            if(!--n) break;
        }
        cout << (int)ans.size() << ' ';
        for(auto x : ans) cout << x + 1 << ' ';
        cout << '\n';
    }
}