#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, l, r;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>l>>r;
    int mini=(1<<l)-1+n-l;
    int maxi=(1<<r)-1+(n-r)*(1<<(r-1));
    cout<<mini<<" "<<maxi<<endl;
    return 0;
}