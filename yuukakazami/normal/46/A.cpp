#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
    //freopen("in","r",stdin);
    int n;cin>>n;
    int at=1;
    rep(i,n-1)
    {
        at+=i+1;at=(at-1)%n+1;
        cout<<at<<" ";
    }
    cout<<endl;
}