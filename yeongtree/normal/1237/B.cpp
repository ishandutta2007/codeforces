#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int A[n], B[n];
    for(auto &i : A) {cin >> i; --i;}
    for(auto &i : B) {cin >> i; --i;}

    bool flag[n]{};
    int p = 0;
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        while(p < n && flag[A[p]]) ++p;
        if(p == n || A[p] != B[i])
        {
            flag[B[i]] = true;
            ++ans;
        }
        else ++p;
    }

    cout << ans;
    return 0;
}