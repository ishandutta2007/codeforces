#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int A[n][n]{};
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            A[i][j] += n * j;
            if(j & 1) A[i][j] += i + 1;
            else A[i][j] += n - i;
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}