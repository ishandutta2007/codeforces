#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, k; cin >> n >> k;
        bool flag = false;
        int A[n]; for(auto &i : A) cin >> i, flag = flag || i;
        cout << (flag ? "YES" : "NO") << '\n';
    }
}