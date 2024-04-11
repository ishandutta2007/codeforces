#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long calc(int n)
{
    int s=0;
    while(s*s<=n)
    s++;
    long long c[s];
    for(long long i=s-1; i>0; i--)
    {
        c[i]=n/(i*i);
        c[i]=i*i*(c[i]*(c[i]+1LL))/2LL;
        for(int j=2*i; j<s; j+=i)
        c[i]-=c[j];
    }
    long long ans=0;
    for(long long i=1; i<s; i++)
    ans+=c[i]/(i*i);
    return ans;
}

int main()
{
    int a, n;
    cin >> a >> n;

    cout << calc(a+n-1)-calc(a-1) << endl;
}