#include <iostream>

using namespace std;

int A[101010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        for(int i = 0; i < n; ++i) cin >> A[i];
        {
            int x = 0, mx = 0;
            for(int i = 0; i < n; ++i) x += A[i], mx = max(mx, A[i]);
            if(x < mx * 2) cout << "T\n";
            else if(x & 1) cout << "T\n";
            else cout << "HL\n";
        }
    }
}