#include <iostream>
#include <vector>
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
const int INF = (int)1e9 + 7;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        piii A[n];
        for(auto &i : A) cin >> i.ff >> i.ee >> i.rr;
        int a = 0, b = 0, c = 0;
        cout << A[0].rr << '\n';
        for(int i = 1; i < n; ++i)
        {
            if(A[a].ff > A[i].ff || (A[a].ff == A[i].ff && A[a].rr > A[i].rr)) a = i;
            if(A[b].ee < A[i].ee || (A[b].ee == A[i].ee && A[b].rr > A[i].rr)) b = i;
            if(A[c].ee - A[c].ff < A[i].ee - A[i].ff || (A[c].ee - A[c].ff == A[i].ee - A[i].ff && A[c].rr > A[i].rr)) c = i;
            if(A[c].ee - A[c].ff == A[b].ee - A[a].ff) cout << min(A[c].rr, A[a].rr + A[b].rr) << '\n';
            else cout << A[a].rr + A[b].rr << '\n';
        }
    }
}