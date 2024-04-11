#include <bits/stdc++.h>
using namespace std;
long long hat[100];
int main()
{
    hat[0]=1;
    for(long long i=1; i<=80; i++)
    {
        hat[i]=hat[i-1]*2;
    }
    int n;
    cin>>n;
    cout<<hat[n+1]-2;
    return 0;
}