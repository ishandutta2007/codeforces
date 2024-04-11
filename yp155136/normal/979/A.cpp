#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define IOS ios:sync_with_stdio(0); cin.tie(0);
typedef long long LL;

const int N = 1e5 + 6;
int a[N];

int main ()
{
    int kirino,meruru;
    LL n;
    cin >> n;
    if (n == 0) cout << 0 << endl;
    else if (n%2 == 0) cout << n+1 << endl;
    else cout << (n+1)/2 <<endl;
}