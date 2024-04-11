#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <iostream>
#define INF 1<<30

using namespace std;
int in[100005];

int main()
{
    int n,d;
    cin>>n>>d;
    
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }
    in[n]=INF;
    
    long long ans=0;
    for(int i = 0, j = 0; i < n; i++)
    {
        while(j < n && in[j] - in[i] <= d) j++;
        ans += max(0ll, (j - i - 1) * (j - i - 2ll) / 2);
    }
    
    cout<<ans<<endl;
    return 0;
}