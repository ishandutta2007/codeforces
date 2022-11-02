#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int test;
int n, m;
char t[2009][2009];
char ans[2009][2009];
vector<pair<pii, pii> > answer;
int mx=1, my=1;
int miny[30];
int maxy[30];
int kicsix[30];
int kicsiy[30];
int nagyx[30];
int nagyy[30];
int g(char c)
{
    if(c=='.') return 0;
    return c-'a'+1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        mx=1;
        my=1;
        cin>>n>>m;
        for(int i=1; i<=26; i++)
        {
            miny[i]=-1;
            maxy[i]=-1;
            kicsix[i]=-1;
            kicsiy[i]=-1;
            nagyx[i]=-1;
            nagyy[i]=-1;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin>>t[i][j];
                ans[i][j]='.';
                int id=g(t[i][j]);
                if(id>g(t[mx][my]))
                {
                    mx=i;
                    my=j;
                }
                if(id==0) continue;
                if(miny[id]==-1 || j<miny[id]) miny[id]=j;
                if(maxy[id]==-1 || j>maxy[id]) maxy[id]=j;
                if(kicsix[id]==-1)
                {
                    kicsix[id]=i;
                    kicsiy[id]=j;
                    nagyx[id]=i;
                    nagyy[id]=j;
                }
                else
                {
                    if(i<kicsix[id] || (i==kicsix[id] && j<kicsiy[id]))
                    {
                        kicsix[id]=i;
                        kicsiy[id]=j;
                    }
                    if(i>nagyx[id] || (i==nagyx[id] && j>nagyy[id]))
                    {
                        nagyx[id]=i;
                        nagyy[id]=j;
                    }
                }
            }
        }
        answer.clear();
        bool lehetseges=true;
        for(int i=1; i<=g(t[mx][my]); i++)
        {
            if(kicsix[i]==-1)
            {
                answer.push_back({{mx, my}, {mx, my}});
                continue;
            }
            if(kicsix[i]==nagyx[i])
            {
                for(int j=kicsiy[i]; j<=nagyy[i]; j++)
                {
                    ans[kicsix[i]][j]=(char)(i-1+'a');
                }
                answer.push_back({{kicsix[i], kicsiy[i]}, {kicsix[i], nagyy[i]}});
            }
            else
            {
                if(miny[i]!=maxy[i])
                {
                    lehetseges=false;
                    break;
                }
                for(int j=kicsix[i]; j<=nagyx[i]; j++)
                {
                    ans[j][miny[i]]=(char)(i-1+'a');
                }
                answer.push_back({{kicsix[i], miny[i]}, {nagyx[i], miny[i]}});
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(!lehetseges) break;
            for(int j=1; j<=m; j++)
            {
                if(t[i][j]!=ans[i][j])
                {
                    lehetseges=false;
                    break;
                }
            }
        }
        if(lehetseges)
        {
            cout<<"YES"<<endl;
            cout<<answer.size()<<endl;
            for(pair<pii, pii> p: answer)
            {
                cout<<p.F.F<<" "<<p.F.S<<" "<<p.S.F<<" "<<p.S.S<<endl;
            }
        }
        else cout<<"NO"<<endl;
    }

    return 0;
}