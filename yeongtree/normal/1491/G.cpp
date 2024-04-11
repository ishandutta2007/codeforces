#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define piii pair<int, pii>
#define plll pair<long long, pll>
#define ff first
#define ss second
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define tlll tuple<long long, long long, long long>
#define tllll tuple<long long, long long, long long, long long>
#define DEBUG

using namespace std;

int A[202020];
bool chc[202020];
int col[202020];
vector<vector<int>> B;
vector<pii> ans;

void dfs(int x)
{
    if(chc[x]) return;
    chc[x] = true;
    B.back().push_back(x);
    dfs(A[x]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i = 0; i < n; ++i) cin >> A[i], --A[i];

    int pt = 0;
    for(int i = 0; i < n; ++i) if(!chc[i])
    {
        B.push_back(vector<int>());
        dfs(i);
        if(B.back().size() == 1) pt = B.back()[0], B.pop_back();
    }

    for(int i = 0; i + 1 < (int)B.size(); i += 2)
    {
        vector<int> C = B[i], D = B[i + 1];
        int c = C.size(), d = D.size();
        ans.push_back({C[c - 1], D[d - 1]});

        for(int j = 0; j < c - 1; ++j) ans.push_back({C[j], D[d - 1]});
        for(int j = 0; j < d - 1; ++j) ans.push_back({D[j], C[c - 1]});

        ans.push_back({C[c - 1], D[d - 1]});
    }

    if((int)B.size() & 1)
    {
        vector<int> C = B.back();
        if(C.size() == 2)
        {
            ans.push_back({pt, C[1]});
            ans.push_back({pt, C[0]});
            ans.push_back({pt, C[1]});
        }
        else
        {
            int c = C.size();
            ans.push_back({C[c - 2], C[c - 1]});
            ans.push_back({C[0], C[c - 1]});
            ans.push_back({C[0], C[c - 2]});
            for(int j = 1; j < c - 1; ++j) ans.push_back({C[j], C[c - 1]});
        }
    }

    cout << ans.size() << '\n';
    for(auto i : ans) cout << i.ff + 1 << ' ' << i.ss + 1 << '\n';
}