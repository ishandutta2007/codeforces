#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
set<long long> volt;
long long hat[15];
long long legk(string z)
{
    long long leanul=0;
    int akz=0;
    while(akz<z.size() && z[akz]=='0')
    {
        leanul++;
        akz++;
    }
    long long x=0;
    for(int i=0; i<z.size(); i++)
    {
        x*=10;
        x+=(z[i]-'0');
    }
    if(x==0)
    {
        if(z.size()==1)
        {
            long long asd=0;
            while(volt.find(asd*10+1990)!=volt.end()) asd++;
            volt.insert(asd*10+1990);
            return asd*10+1990;
        }
        if(z.size()==2)
        {
            long long asd=0;
            while(volt.find(asd*100+2000)!=volt.end()) asd++;
            volt.insert(asd*100+2000);
            return asd*100+2000;
        }
        if(z.size()==3)
        {
            long long asd=0;
            while(volt.find(asd*1000+2000)!=volt.end()) asd++;
            volt.insert(asd*1000+2000);
            return asd*1000+2000;
        }
        long long ans=hat[z.size()];
        while(volt.find(ans)!=volt.end()) ans*=10;
        volt.insert(ans);
        return ans;
    }
    if(leanul>0)
    {
        long long kezdo=hat[z.size()]+x;
        while(kezdo<1989) kezdo+=hat[z.size()];
        while(volt.find(kezdo)!=volt.end()) kezdo+=hat[z.size()];
        volt.insert(kezdo);
        return kezdo;
    }
    if(x>1989)
    {
        long long meg=hat[z.size()];
        long long asd=0;
        while(volt.find(asd*meg+x)!=volt.end()) asd++;
        volt.insert(asd*meg+x);
        return asd*meg+x;
    }
    if(1000<=x)
    {
        long long asd=0;
        while(volt.find(asd*10000+10000+x)!=volt.end()) asd++;
        volt.insert(asd*10000+10000+x);
        return asd*10000+10000+x;
    }
    if(100<=x)
    {
        if(1000+x>=1989)
        {
            long long asd=0;
            while(volt.find(asd*1000+1000+x)!=volt.end()) asd++;
            volt.insert(asd*1000+1000+x);
            return asd*1000+1000+x;
        }
        long long asd=0;
        while(volt.find(asd*1000+2000+x)!=volt.end()) asd++;
        volt.insert(asd*1000+2000+x);
        return asd*1000+2000+x;
    }
    if(10<=x)
    {
        if(x>=89)
        {
            long long asd=0;
            while(volt.find(asd*100+1900+x)!=volt.end()) asd++;
            volt.insert(asd*100+1900+x);
            return asd*100+1900+x;
        }
        long long asd=0;
        while(volt.find(asd*100+2000+x)!=volt.end()) asd++;
        volt.insert(asd*100+2000+x);
        return asd*100+2000+x;
    }
    if(x==9)
    {
        long long asd=0;
        while(volt.find(asd*10+1989)!=volt.end()) asd++;
        volt.insert(asd*10+1989);
        return asd*10+1989;
    }
    long long asd=0;
    while(volt.find(asd*10+1990+x)!=volt.end()) asd++;
    volt.insert(asd*10+1990+x);
    return asd*10+1990+x;
}
int n;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    hat[0]=1;
    for(int i=1; i<=13; i++)
    {
        hat[i]=hat[i-1]*10;
    }
    for(int tt=1; tt<=n; tt++)
    {
        volt.clear();
        cin>>s;
        string q=s.substr(4);
        for(int u=q.size()-1; u>0; u--)
        {
            legk(q.substr(u));
        }
        cout<<legk(q)<<endl;
    }
    return 0;
}