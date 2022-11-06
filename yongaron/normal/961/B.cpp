#include <iostream>

using namespace std;

int n, k, a[100005], p[100005], s;

int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    for(int i = 1; i <= n; i++)
    {
        int t;
        cin>>t;
        s += t*a[i];
        if(t == 0)
            t = 1;
        else
            t = 0;
        p[i] = p[i-1]+t*a[i];
    }
    int ma = s;
    for(int i = 1; i <= n-k+1; i++)
        ma = max(ma, s+p[i+k-1]-p[i-1]);
    cout<<ma<<endl;
    return 0;
}