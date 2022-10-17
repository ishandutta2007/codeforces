#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> V(n); for(auto &i : V) cin >> i;
    vector<int> A, B;
    int ans = 0; long long inv = 0;
    for(int k = 30; k >= 0; --k)
    {
        A.clear(); B.clear();
        int cnt1 = 0, cnt2 = 0; long long cl1 = 0, cl2 = 0;
        for(int i = 0; i < n; ++i)
        {
            if(i && V[i - 1] >> (k + 1) != V[i] >> (k + 1)) cnt1 = 0, cnt2 = 0;
            if(V[i] >> k & 1) ++cnt1, cl2 += cnt2, B.push_back(V[i]);
            else cl1 += cnt1, ++cnt2, A.push_back(V[i]);
        }
        if(cl2 < cl1) swap(cl1, cl2), ans += (1 << k);
        inv += cl1;
        V.clear();
        for(auto i : A) V.push_back(i);
        for(auto i : B) V.push_back(i);
    }

    cout << inv << ' ' << ans;
}