#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, u, v; cin >> n >> v >> u;
        int A[n]; for(auto &i : A) cin >> i;

        bool flag = true;
        for(int i = 0; i < n - 1; ++i) if(A[i] != A[i + 1]) flag = false;
        if(flag)
        {
            cout << min(u + v, 2 * u) << '\n';
            continue;
        }

        flag = true;
        for(int i = 0; i < n - 1; ++i) if(abs(A[i] - A[i + 1]) > 1) flag = false;
        if(!flag)
        {
            cout << "0\n";
            continue;
        }

        cout << min(v, u) << '\n';
    }
}