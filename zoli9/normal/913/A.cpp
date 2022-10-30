#include <bits/stdc++.h>
using namespace std;
long long n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    if(n>=30)
    {
        cout<<m<<endl;
        return 0;
    }
    cout<<(m%((long long)(1<<n)))<<endl;
    return 0;
}