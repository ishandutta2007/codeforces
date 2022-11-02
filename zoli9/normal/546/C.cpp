#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
int ido=0;
int n, a, b, aakt, bakt;
int t1[15];
int t2[15];
int main()
{
    cin>>n;
    cin>>a;
    for(int i=1; i<=a; i++)
    {
        cin>>t1[i];
    }
    cin>>b;
    for(int i=1; i<=b; i++)
    {
        cin>>t2[i];
    }
    while(1)
    {
        ido++;
        aakt=t1[1];
        bakt=t2[1];
        for(int i=1; i<a; i++)
        {
            t1[i]=t1[i+1];
        }
        for(int i=1; i<b; i++)
        {
            t2[i]=t2[i+1];
        }
        a--;
        b--;
        if(aakt>bakt)
        {
            a++;
            t1[a]=bakt;
            a++;
            t1[a]=aakt;
        }
        else
        {
            b++;
            t2[b]=aakt;
            b++;
            t2[b]=bakt;
        }
        if(a==0)
        {
            cout<<ido<<" "<<2;
            return 0;
        }
        if(b==0)
        {
            cout<<ido<<" "<<1;
            return 0;
        }
        if(ido==100009)
        {
            break;
        }
    }
    cout<<-1;
    return 0;
}