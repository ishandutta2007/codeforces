#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll a, b, c;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>b>>c;
    if(a==b) cout<<(a+b+2*c)<<endl;
    else cout<<(2*min(a, b)+2*c+1)<<endl;
    return 0;
}