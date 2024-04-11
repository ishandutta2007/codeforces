#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long p, q;
long long prim[1200009];
long long pali[1200009];
bool os[1200009];
int leg;
int main()
{
    cin>>p>>q;
    os[1]=true;
    int cnt=2;
    while(cnt<=1200000)
    {
        for(int i=2*cnt; i<=1200000; i+=cnt)
        {
            os[i]=true;
        }
        cnt++;
        while(os[cnt])
        {
            cnt++;
        }
    }
    prim[1]=0;
    pali[1]=1;
    for(int i=2; i<=1200000; i++)
    {
        if(os[i]) prim[i]=prim[i-1];
        else prim[i]=prim[i-1]+1;
        vector<int> dig;
        int z=i;
        bool v=true;
        while(z>0)
        {
            dig.push_back(z%10);
            z/=10;
        }
        for(int j=0; j<dig.size(); j++)
        {
            if(dig[j]!=dig[dig.size()-j-1]) v=false;
        }
        if(v) pali[i]=pali[i-1]+1;
        else pali[i]=pali[i-1];
    }
    /*for(int i=1; i<=30; i++)
    {
        cout<<prim[i]<<" "<<pali[i]<<endl;
    }*/
    leg=0;
    for(int i=1; i<=1199999; i++)
    {
        if(q*prim[i]<=p*pali[i]) leg=i;
    }
    //cout<<prim[1199999]<<" "<<pali[1199999]<<endl;
    if(leg>0 && leg!=1199999)
    {
        cout<<leg;
        return 0;
    }
    else
    {
        cout<<"Palindromic tree is better than splay tree";
    }
    return 0;
}