#include <bits/stdc++.h>
using namespace std;
int n;
int tipus;
class pont
{
    public:
    map<char, pont*> irany;
    int tip=0;
    void be(string &s, int index)
    {
        if(tip==0) tip=tipus;
        else if(tip!=tipus) tip=-1;
        if(index==s.size()) return;
        if(irany[s[index]]!=NULL)
        {
            irany[s[index]]->be(s, index+1);
            return;
        }
        irany[s[index]]=new pont();
        irany[s[index]]->be(s, index+1);
    }
    int keres(string &s, int index)
    {
        //cout<<": "<<tip<<endl;
        if(tip>0) return index;
        if(index==s.size()) return 0;
        return irany[s[index]]->keres(s, index+1);
    }
};
pont gyoker;
string zz[70009];
int maxihonnan[70009];
int maxihany[70009];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        maxihany[i]=9;
        maxihonnan[i]=0;
        tipus=i;
        cin>>zz[i];
        string ss;
        ss="";
        for(int u=8; u>=0; u--)
        {
            ss=zz[i][u]+ss;
            gyoker.be(ss, 0);
        }
    }
    for(int i=1; i<=n; i++)
    {
        string ss;
        ss="";
        for(int u=8; u>=0; u--)
        {
            ss=zz[i][u]+ss;
            int ind=gyoker.keres(ss, 0);
            if(ind==0) continue;
            //cout<<ss<<" ** "<<ind<<endl;
            if(ind<maxihany[i])
            {
                maxihany[i]=ind;
                maxihonnan[i]=u;
            }
        }
    }
    if(n==1)
    {
        cout<<zz[1][0]<<endl;
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=maxihonnan[i]; j<maxihonnan[i]+maxihany[i]; j++)
        {
            cout<<zz[i][j];
        }
        cout<<endl;
    }
    return 0;
}