#include <bits/stdc++.h>
using namespace std;
int a0[10];
int a1[10];
int n;
int com[500009]; //0 and 1 or 2 xor
int cnum[500009];
int an[10];
int xo[10];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        char c;
        int x;
        cin>>c>>x;
        if(c=='&') com[i]=0;
        else if(c=='|') com[i]=1;
        else com[i]=2;
        cnum[i]=x;
    }
    int szam0=0;
    for(int i=1; i<=n; i++)
    {
        if(com[i]==0) szam0&=cnum[i];
        else if(com[i]==1) szam0|=cnum[i];
        else szam0^=cnum[i];
    }
    int szam1=1023;
    for(int i=1; i<=n; i++)
    {
        if(com[i]==0) szam1&=cnum[i];
        else if(com[i]==1) szam1|=cnum[i];
        else szam1^=cnum[i];
        //cout<<"! "<<szam1<<endl;
    }
    for(int i=0; i<10; i++)
    {
        a0[i]=szam0%2;
        a1[i]=szam1%2;
        szam0/=2;
        szam1/=2;
    }
    //cout<<szam0<<" "<<szam1<<endl;
    for(int i=0; i<10; i++)
    {
        if(a0[i]==0 && a1[i]==1)
        {

        }
        else if(a0[i]==0 && a1[i]==0)
        {
            an[i]=1;
            xo[i]=1;
        }
        else if(a0[i]==1 && a1[i]==1)
        {
            an[i]=1;
        }
        else
        {
            xo[i]=1;
        }
    }
    int elso=0;
    int maso=0;
    for(int i=0; i<10; i++)
    {
        if(an[i]==1)
        {
            elso+=(1<<i);
        }
        if(xo[i]==1)
        {
            maso+=(1<<i);
        }
    }
    cout<<2<<endl;
    cout<<"| "<<elso<<endl;
    cout<<"^ "<<maso<<endl;
    return 0;
}