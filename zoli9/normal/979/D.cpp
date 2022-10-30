#include <bits/stdc++.h>
using namespace std;
set<int> s[100009];
bool volt[100009];
int q;
vector<int> osztok[100009];
int main()
{
    ios::sync_with_stdio(false);
    for(int d=1; d<=100000; d++)
    {
        for(int l=d; l<=100000; l+=d)
        {
            osztok[l].push_back(d);
        }
    }
    cin>>q;
    for(int tt=1; tt<=q; tt++)
    {
        int ty;
        cin>>ty;
        if(ty==1)
        {
            int szam;
            cin>>szam;
            if(!volt[szam])
            {
                for(int w=0; w<osztok[szam].size(); w++)
                {
                    s[osztok[szam][w]].insert(szam);
                }
                volt[szam]=true;
            }
        }
        else
        {
            int xx, kk, ss;
            cin>>xx>>kk>>ss;
            int hmax=ss-xx;
            if(xx%kk!=0)
            {
                cout<<-1<<endl;
                continue;
            }
            int ertek=0;
            vector<int> je;
            int x2=xx;
            for(int i=0; i<17; i++)
            {
                je.push_back(x2%2);
                x2/=2;
            }
            bool ok=true;
            for(int i=16; i>=0; i--)
            {
                if(je[i]==0)
                {
                    auto it=s[kk].lower_bound(ertek+(1<<i));
                    /*if(i==1)
                    {
                        if(it==s[kk].end()) cout<<"jajj";
                        cout<<*it<<endl;
                    }*/
                    if(it!=s[kk].end() && *it<ertek+(1<<(i+1)) && *it<=hmax)
                    {
                        ertek+=(1<<i);
                        continue;
                    }
                    else
                    {
                        auto it2=s[kk].lower_bound(ertek);
                        if(it2!=s[kk].end() && *it2<ertek+(1<<(i)) && *it2<=hmax)
                        {
                            continue;
                        }
                        else
                        {
                            ok=false;
                            break;
                        }
                    }
                }
                else
                {
                    auto it=s[kk].lower_bound(ertek);
                    if(it!=s[kk].end() && *it<ertek+(1<<(i)) && *it<=hmax)
                    {
                        continue;
                    }
                    else
                    {
                        auto it2=s[kk].lower_bound(ertek+(1<<i));
                        if(it2!=s[kk].end() && *it2<ertek+(1<<(i+1)) && *it2<=hmax)
                        {
                            ertek+=(1<<i);
                            continue;
                        }
                        else
                        {
                            ok=false;
                            break;
                        }
                    }
                }
            }
            if(ok)
            {
                cout<<ertek<<endl;
            }
            else cout<<-1<<endl;
        }
    }
    return 0;
}