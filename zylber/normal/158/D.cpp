#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

int t[20010];

int main()
{
    int n;
    cin >> n;
    
    long long ans=-1000000000000LL;
    
    for(int i=0; i<n; i++)
    {
        cin >> t[i];
    }
    
    for(int j=1; 3*j<=n; j++)
    {
        if(n%j==0)
        {
            for(int k=0; k<j; k++)
            {
                long long sum=0;
                for(int r=k; r<n; r+=j) sum+=t[r];
                ans=max(ans, sum);
            }
        }
    }
    
    cout << ans << endl;
}