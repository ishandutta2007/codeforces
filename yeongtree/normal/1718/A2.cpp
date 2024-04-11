#include <iostream>
#include <set>

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
        int ans = n;
        int pr = 0;
        set<int> S; S.insert(0);
        for(int i = 0; i < n; ++i)
        {
            pr ^= A[i];
            if(S.count(pr))
            {
                --ans;
                S.clear();
            }
            S.insert(pr);
        }
        cout << ans << '\n';
    }
}