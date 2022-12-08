#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define forn(a,n) for(int a = 0; a<n; ++a)

long long arr[100500];

int main()
{
    int n;
    cin >> n;
    long long sum=0;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        sum+=arr[i];
    }
    
    long long ans=0;
    if(abs(sum)%3==0)
    {
        long long s=sum/3;
        long long p=0, cs=0;
        
        for(int i=0; i<n-1; i++)
        {
            p+=arr[i];
            if(p==2LL*s)
                ans+=cs;
            if(p==s)
                cs++;
        }
    }
    
    cout << ans << endl;
}