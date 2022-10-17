#include<bits/stdc++.h>
using namespace std;

int n,T;

vector<int>v;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        v.resize(n);
        for(int i=0;i<n;i++)
            scanf("%d",&v[i]);
        reverse(v.begin(),v.end());
        for(auto x:v)
            printf("%d ",x);
        puts("");
    }
}