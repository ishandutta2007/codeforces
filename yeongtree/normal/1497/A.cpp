#include <iostream>
#include <algorithm>

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
        sort(A, A + n);
        for(int i = 0; i < n; ++i) if(i == 0 || A[i - 1] != A[i]) cout << A[i] << ' ';
        for(int i = 0; i < n; ++i) if(i != 0 && A[i - 1] == A[i]) cout << A[i] << ' ';
        cout << '\n';
    }
}