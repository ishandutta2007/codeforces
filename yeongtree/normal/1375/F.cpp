#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long A[3]; cin >> A[0] >> A[1] >> A[2];
    cout << "First" << endl;
    cout.flush();
    long long k = 1e11;
    cout << k << endl;
    cout.flush();
    int x; cin >> x;
    if(x == 0) return 0;
    A[x - 1] += k;
    long long B[3]; B[0] = A[0]; B[1] = A[1]; B[2] = A[2];
    sort(B, B + 3);
    long long a = B[2] - B[1];
    long long b = B[1] - B[0];
    k = 2 * a + b;
    cout << k << endl;
    cout.flush();
    cin >> x;
    if(x == 0) return 0;
    A[x - 1] += k;
    B[0] = A[0]; B[1] = A[1]; B[2] = A[2];
    sort(B, B + 3);
    cout << B[1] - B[0] << endl;
    cout.flush();
    cin >> x;
    if(x == 0) return 0;
}