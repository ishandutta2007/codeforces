#include <iostream>
using namespace std;

const int N = 55;
int A[N];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (A[i] >= A[k - 1] && A[i] > 0)
            ans++;
    cout << ans;
}