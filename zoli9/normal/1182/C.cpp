#include <bits/stdc++.h>
using namespace std;

int n;
string s[100009];
vector<int> V[1000009][5];
int szam(char ccc)
{
    if(ccc=='a') return 0;
    if(ccc=='e') return 1;
    if(ccc=='o') return 2;
    if(ccc=='i') return 3;
    if(ccc=='u') return 4;
    return -1;
}
vector<pair<int, int> > jo;
vector<pair<int, int> > rossz;
int maxi=0;
vector<int> ans1, ans2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>s[i];
        int vdb=0;
        int last=0;
        for(int j=0; j<s[i].size(); j++)
        {
            int szsz=szam(s[i][j]);
            if(szsz>=0)
            {
                vdb++;
                last=szsz;
            }
        }
        V[vdb][last].push_back(i);
        maxi=max(maxi, vdb);
    }

    /*for(int i=1; i<=4; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout<<V[i][j].size()<<" ";
        }
        cout<<endl;
    }*/

    for(int i=1; i<=maxi; i++)
    {
        vector<int> selejt;
        for(int j=0; j<5; j++)
        {
            while(V[i][j].size()>1)
            {
                int elso=V[i][j].back();
                V[i][j].pop_back();
                int masodik=V[i][j].back();
                V[i][j].pop_back();
                jo.push_back({elso, masodik});
            }
            if(V[i][j].size()>0)
            {
                selejt.push_back(V[i][j][0]);
            }
        }
        while(selejt.size()>1)
        {
            int elso=selejt.back();
            selejt.pop_back();
            int masodik=selejt.back();
            selejt.pop_back();
            rossz.push_back({elso, masodik});
        }
        //cout<<"after "<<i<<" "<<jo.size()<<" "<<rossz.size()<<endl;
    }
    int J=jo.size();
    int R=rossz.size();
    //cout<<J<<" "<<R<<endl;
    int valasz=min(J, (J+R)/2);
    for(int i=0; i<valasz; i++)
    {
        pair<int, int> ppp=jo.back();
        jo.pop_back();
        ans2.push_back(ppp.first);
        ans2.push_back(ppp.second);
    }
    while(jo.size()>0)
    {
        pair<int, int> ppp=jo.back();
        jo.pop_back();
        ans1.push_back(ppp.first);
        ans1.push_back(ppp.second);
    }
    while(rossz.size()>0)
    {
        pair<int, int> ppp=rossz.back();
        rossz.pop_back();
        ans1.push_back(ppp.first);
        ans1.push_back(ppp.second);
    }
    cout<<valasz<<endl;
    for(int i=0; i<2*valasz; i++)
    {
        cout<<s[ans1[i]]<<" "<<s[ans2[i]]<<endl;
    }

    return 0;
}