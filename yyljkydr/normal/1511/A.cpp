#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int T,n,a[N];

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        int s=0;
        for(int i=1;i<=n;i++)
            cin>>a[i],s+=a[i]&1;
        printf("%d\n",s);
    }
}