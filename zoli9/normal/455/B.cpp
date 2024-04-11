#include <bits/stdc++.h>
using namespace std;
int n, k;
class pont
{
    public:
    map<char, pont*> irany;
    bool nyero=true;
    bool tudveszteni=true;
    void be(string &s, int index)
    {
        if(index==s.size()) return;
        if(irany[s[index]]!=NULL)
        {
            irany[s[index]]->be(s, index+1);
            return;
        }
        irany[s[index]]=new pont();
        irany[s[index]]->be(s, index+1);
    }
    void kitolt()
    {
        auto it=irany.begin();
        while(it!=irany.end())
        {
            it->second->kitolt();
            if(it->second->nyero) nyero=false;
            if(it->second->tudveszteni) tudveszteni=false;
            it++;
        }
        if(irany.size()==0) tudveszteni=false;
    }
};
pont gyoker;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        gyoker.be(s, 0);
    }
    gyoker.kitolt();
    bool kezdonyer=!gyoker.nyero;
    bool kezdoveszt=!gyoker.tudveszteni;
    if(kezdonyer && kezdoveszt) cout<<"First"<<endl;
    else if(kezdonyer && !kezdoveszt)
    {
        if(k%2) cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
    else cout<<"Second"<<endl;
    return 0;
}