#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#include <deque>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define piii pair<int, pii>
#define plll pair<long long, pll>
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        deque<int> A(n); for(auto &i : A) cin >> i;
        int ans = 0;
        while(A.size())
        {
            while(A.size() && A.front() == 0) A.pop_front();
            while(A.size() && A.back() == 1) A.pop_back();
            if(A.size()) A.pop_front(), A.pop_back(), ++ans;
        }
        cout << ans << '\n';
    }
}