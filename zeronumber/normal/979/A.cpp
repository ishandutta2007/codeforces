#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main()
{
    cin>>n;
    if (n==0) cout << 0 << endl;
    else if (n&1) cout << (n+1)/2 << endl;
    else cout << n+1 << endl;
    return 0;
}