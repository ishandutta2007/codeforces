#include <bits/stdc++.h>
using namespace std;
int n;
int a[20];
int M=360;
bool answer=false;
int sz;
void proba(int x)
{
    if(x==n)
    {
       if(sz==0) answer=true;
       return;
    }
    sz+=a[x];
    sz%=M;
    proba(x+1);
    sz-=a[x];
    sz+=M;
    sz-=a[x];
    sz+=M;
    sz%=M;
    proba(x+1);
    sz+=a[x];
    sz%=M;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    proba(0);
    if(answer) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}