#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cout<<(n+2)/2<<endl;
    int x=1;
    int y=1;
    for(int i=1; i<=n; i++)
    {
        cout<<x<<" "<<y<<endl;
        if(i%2) x++;
        else y++;
    }
    return 0;
}