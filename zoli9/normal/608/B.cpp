#include <bits/stdc++.h>
using namespace std;
string a, b;
int aa[200009];
int bb[200009];
int da[200009];
int db[200009];
long long ans;
int h1, h2;
int main()
{
    cin>>a>>b;
    for(int i=0; i<a.size(); i++)
    {
        aa[i+1]=a[i]-'0';
    }
    for(int i=0; i<b.size(); i++)
    {
        bb[i+1]=b[i]-'0';
    }
    da[0]=0;
    db[0]=0;
    for(int i=1; i<=a.size(); i++)
    {
        da[i]=aa[i]+da[i-1];
    }
    for(int i=1; i<=b.size(); i++)
    {
        db[i]=bb[i]+db[i-1];
    }
    h1=a.size();
    h2=b.size();
    ans=0;
    for(int i=1; i<=b.size()-a.size(); i++)
    {
        if(bb[i]==0)
        {
            ans+=da[min(i, h1)];
        }
        else
        {
            ans+=(min(i, h1)-da[min(i, h1)]);
        }
        //cout<<ans<<endl;
    }

    for(int i=b.size()-a.size()+1; i<=b.size(); i++)
    {
        int kezd=max(1, h1-(h2-i));
        int veg=min(h1, i);
        int hozza=da[veg]-da[kezd-1];
        if(bb[i]==0) ans+=hozza;
        else ans+=((veg-kezd+1)-hozza);
        //cout<<ans<<endl;
    }
    cout<<ans;
    return 0;
}