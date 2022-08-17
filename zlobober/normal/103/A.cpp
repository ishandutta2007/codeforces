#include <iostream>
using namespace std;


typedef long long llong;
const int N = 150;
int A[N];    

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    llong ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (llong)(A[i] - 1) * (i + 1);
    }
    ans += n;
    cout << ans;
    return 0;
}