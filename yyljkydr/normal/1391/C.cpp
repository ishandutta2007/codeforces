#include<bits/stdc++.h>
using namespace std;

int T,n,m;

string s[200001];

int main()
{
    scanf("%d",&n);
    int a=1,b=1;
    int P=1e9+7;
    for(int i=1;i<=n;i++)
        a=1ll*a*i%P,b=b*(i<n?2:1)%P;
    printf("%d\n",(a-b+P)%P);
}