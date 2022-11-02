#include <iostream>
using namespace std;
int n, m, lnko, fdb, ldb;
bool fiu[105];
bool lany[105];
bool ossz[105];
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        fiu[i]=false;
    }
    for(int i=0; i<m; i++)
    {
        lany[i]=false;
    }
    int temp;
    int a=n;
    int b=m;
    while(b>0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    lnko=a;
    for(int i=0; i<lnko; i++)
    {
        ossz[i]=false;
    }
    cin>>fdb;
    for(int i=1; i<=fdb; i++)
    {
        int asd;
        cin>>asd;
        fiu[asd]=true;
    }
        cin>>ldb;
    for(int i=1; i<=ldb; i++)
    {
        int asd;
        cin>>asd;
        lany[asd]=true;
    }
    for(int i=0; i<n; i++)
    {
        if(fiu[i])
        {
            ossz[i%lnko]=true;
        }
    }
    for(int i=0; i<m; i++)
    {
        if(lany[i])
        {
            ossz[i%lnko]=true;
        }
    }
    bool v=true;
    for(int i=0; i<lnko; i++)
    {
        if(!ossz[i])
        {
            v=false;
        }
    }
    if(v)
    {
        cout<<"Yes";
        return 0;
    }
    cout<<"No";
    return 0;
}