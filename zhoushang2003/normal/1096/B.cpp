#include<iostream>
using namespace std;
const int N=2e5;
const long long P=998244353;
char s[N];
int n;
long long l,r;
int main()
{
    cin>>n>>s;
    for(int i=0;i<n;i++)
        if(s[i]!=s[0])
            l=i,i=n;
    for(int i=n-1;i>=0;i--)
        if(s[i]!=s[n-1])
            r=n-1-i,i=0;
    cout<<(l+r+1+(s[0]==s[n-1])*l*r)%P;
    return 0;
}