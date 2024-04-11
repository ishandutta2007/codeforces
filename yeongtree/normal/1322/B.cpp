#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> A;
    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        A.push_back(x);
    }

    int p = 0;
    int ans = 0;
    for(int T = 0; T < 25; ++T)
    {
        int k = (1 << T) - 1;
        int j = n - 1;
        for(int i = 0; i < n; ++i)
        {
            while(j >= 0 && (A[i] & k) + (A[j] & k) > k) --j;
            p += n - max(i, j) - 1;
            p = p & 1;
        }
        vector<int> B;
        for(auto i : A)
            if(!(i >> T & 1)) B.push_back(i);
        for(auto i : A)
            if((i >> T & 1)) {B.push_back(i); if(!(n & 1)) ++p;}
        A = B;

        if(p & 1) ans += (1 << T);
        p = 0;
    }

    cout << ans;
    return 0;
}