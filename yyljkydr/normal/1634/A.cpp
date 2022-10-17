#include<bits/stdc++.h>
using namespace std;

int T;

int n,k;

string s;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        cin>>n>>k;
        cin>>s;
        string t=s;
        reverse(t.begin(),t.end());
        if(s==t)
            cout<<1<<"\n";
        else
        {
            if(k==0)
                cout<<1<<"\n";
            else
                cout<<2<<"\n";
        }
    }
}