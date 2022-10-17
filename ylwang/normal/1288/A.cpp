#include<bits/stdc++.h>
using namespace std;
long long int T,n,d;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>d;
        if((n-n/2)*(n/2+1)>=d)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}