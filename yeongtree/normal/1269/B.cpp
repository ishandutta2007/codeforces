#include <iostream>
#include <algorithm>
#define f(x, y) ((y) < (x) ? (y) + m - (x) : (y) - (x))

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    int A[n], B[n];
    for(auto &i : A) cin >> i;
    for(auto &i : B) cin >> i;
    sort(A, A + n);
    sort(B, B + n);

    for(int i = 0; i < n; ++i)
    {
        bool flag = true;
        int tmp = f(A[0], B[i]);
        for(int j = 1; j < n; ++j)
            if(tmp != f(A[j], B[(i + j) % n]))
            {
                flag = false;
                break;
            }
        if(flag) {cout << tmp; break;}
    }
}