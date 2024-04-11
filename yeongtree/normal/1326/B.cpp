#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    long long B[n]; for(auto &i : B) cin >> i;
    long long A[n], X[n];
    for(int i = 0; i < n; ++i)
    {
        if(i == 0) A[i] = B[i], X[i] = 0;
        else
        {
            X[i] = max(X[i - 1], A[i - 1]);
            A[i] = B[i] + X[i];
        }
    }
    for(auto i : A) cout << i << ' ';
}