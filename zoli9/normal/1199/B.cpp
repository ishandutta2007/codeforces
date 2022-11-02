#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
long double l, h;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>h>>l;
    cout.precision(10);
    cout<<fixed;
    cout<<((l*l+h*h)/2/h)-h<<endl;
    return 0;
}