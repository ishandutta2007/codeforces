#include<bits/stdc++.h>
using namespace std;

int n,k;

int main()
{
    string s;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
    {
        s+=i+'a'-1;
        for(int j=i+1;j<=k;j++)
            s+=i+'a'-1,s+=j+'a'-1;
    }
    while(s.size()<n)
        s+=s;
    s.resize(n);
    cout<<s;
}