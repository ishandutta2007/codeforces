#include<bits/stdc++.h>
using namespace std;

int T;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        long long n;
        cin>>n;
        while(n%2==0)
            n/=2;
        puts(n==1?"NO":"YES");
    }
}