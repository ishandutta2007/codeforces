#include <iostream>
#include <cstring>
#include <cstdio>
#define MOD 1000000007
using namespace std;

int DP[2048];
int n, k;
long long a[2048];

long long abs(long long x)
{
    return x<0?-x:x;
}

long long d(int i, int j)
{
    long long asd=abs(a[i]-a[j]);
    return (asd+i-j-1)/(i-j);
}

bool can(long long D)
{
    memset(DP,0,sizeof(DP));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
            if(d(i,j)<=D)
                DP[i]=max(DP[i], DP[j]+1);
        
        if(DP[i]>=n-k-1) return true;
    }
    return false;
}

int main()
{
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> a[i];
    
    long long top=3000000000, bot=-1;
    while(top-bot>1)
    {
        long long mid=(top+bot)/2;
        if(can(mid))
        {
            top=mid;
        }
        else
        {
            bot=mid;
        }
    }
    
    cout << top << endl;
}