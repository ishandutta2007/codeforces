#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int n;
vector<pii> edges;

const int maxn=(1<<20);
vector<int> G[maxn+1];
vector<bool> bejar[maxn+1];
vector<int> hanyadik[maxn+1];
vector<int> ans[maxn+1];
vector<int> selfedges[maxn+1];
int edgecnt[maxn+1];
bool selfe[maxn+1];
int normaledge;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    edges.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>edges[i].F>>edges[i].S;
    }
    for(int k=20; k>=0; k--)
    {
        for(int i=0; i<(1<<k); i++)
        {
            G[i].clear();
            bejar[i].clear();
            hanyadik[i].clear();
            ans[i].clear();
            selfedges[i].clear();
            selfe[i]=false;
            edgecnt[i]=0;
        }
        normaledge=0;
        int selfloop1=-1;
        int selfloop2=-1;
        for(int ec=0; ec<n; ec++)
        {
            int v1=edges[ec].F%(1<<k);
            int v2=edges[ec].S%(1<<k);
            if(v1==v2)
            {
                selfedges[v1].push_back(2*ec+1);
                selfedges[v1].push_back(2*ec+2);
                if(selfloop1==-1) selfloop1=v1;
                else if(v1!=selfloop1) selfloop2=v1;
                continue;
            }
            normaledge++;
            hanyadik[v1].push_back(G[v2].size());
            hanyadik[v2].push_back(G[v1].size());
            G[v1].push_back(v2);
            G[v2].push_back(v1);
            bejar[v1].push_back(false);
            bejar[v2].push_back(false);
            ans[v1].push_back(2*ec+1);
            ans[v2].push_back(2*ec+2);
        }
        bool okparity=true;
        for(int i=0; i<(1<<k); i++)
        {
            if(G[i].size()%2)
            {
                okparity=false;
                break;
            }
        }
        if(!okparity)
        {
            continue;
        }
        vi v;
        vi kor;
        vi ansv;
        v.push_back(edges[0].F%(1<<k));
        ansv.push_back(0);
        while(v.size()>0)
        {
            int akt=v[v.size()-1];
            while(edgecnt[akt]<G[akt].size() && bejar[akt][edgecnt[akt]])
            {
                edgecnt[akt]++;
            }
            if(edgecnt[akt]<G[akt].size())
            {
                int aktuj=G[akt][edgecnt[akt]];
                int ansaktuj=ans[akt][edgecnt[akt]];
                bejar[akt][edgecnt[akt]]=true;
                bejar[aktuj][hanyadik[akt][edgecnt[akt]]]=true;
                while(aktuj!=akt)
                {
                    v.push_back(aktuj);
                    ansv.push_back(ansaktuj);
                    while(edgecnt[aktuj]<G[aktuj].size() && bejar[aktuj][edgecnt[aktuj]]) edgecnt[aktuj]++;
                    int szom=G[aktuj][edgecnt[aktuj]];
                    bejar[aktuj][edgecnt[aktuj]]=true;
                    bejar[szom][hanyadik[aktuj][edgecnt[aktuj]]]=true;
                    ansaktuj=ans[aktuj][edgecnt[aktuj]];
                    aktuj=szom;
                }
                v.push_back(akt);
                ansv.push_back(ansaktuj);
            }
            else
            {
                kor.push_back(ansv.back());
                v.pop_back();
                ansv.pop_back();
            }
        }
        int sii=kor.size();
        sii--;
        if(sii!=normaledge) continue;
        if(sii==0 && selfloop2==-1)
        {
            cout<<k<<'\n';
            for(int i=1; i<=2*n; i++)
            {
                cout<<i<<" ";
            }
            cout<<'\n';
            return 0;
        }
        vi answer;
        for(int i=sii-1; i>=0; i--)
        {
            int vv;
            if(kor[i]%2==0) vv=edges[(kor[i]-2)/2].S%(1<<k);
            else vv=edges[(kor[i]-1)/2].F%(1<<k);
            if(!selfe[vv])
            {
                for(int u: selfedges[vv]) answer.push_back(u);
                selfe[vv]=true;
            }
            answer.push_back(kor[i]);
            if(kor[i]%2) answer.push_back(kor[i]+1);
            else answer.push_back(kor[i]-1);
        }
        if(answer.size()==2*n)
        {
            cout<<k<<'\n';
            for(int i: answer)
            {
                cout<<i<<" ";
            }
            cout<<'\n';
            return 0;
        }
    }




    return 0;
}