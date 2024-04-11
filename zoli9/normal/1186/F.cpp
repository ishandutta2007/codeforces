#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> G[1000009];
vector<int> hol[1000009];
vector<int> bejar[1000009];
int deg[1000009];
int mutato[1000009];
int groupCnt=0;
vector<pair<int, int> > elek[1000009];
vector<pair<int, int> > answer;
bool virtualis(pair<int, int> pp)
{
    return (pp.first==0 || pp.second==0);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    //scanf("%d%d", &n, &m);
    for(int i=1; i<=m; i++)
    {
        int aa, bb;
        cin>>aa>>bb;
        //scanf("%d%d", &aa, &bb);
        hol[aa].push_back(G[bb].size());
        hol[bb].push_back(G[aa].size());
        bejar[aa].push_back(false);
        bejar[bb].push_back(false);
        G[aa].push_back(bb);
        G[bb].push_back(aa);
        deg[aa]++;
        deg[bb]++;
    }
    for(int i=1; i<=n; i++)
    {
        if(deg[i]%2)
        {
            hol[i].push_back(G[0].size());
            hol[0].push_back(G[i].size());
            bejar[i].push_back(false);
            bejar[0].push_back(false);
            G[i].push_back(0);
            G[0].push_back(i);
            deg[i]++;
            deg[0]++;
        }
    }
    vector<int> w;
    for(int i=1; i<=n; i++)
    {
        if(mutato[i]<G[i].size())
        {
            w.push_back(i);
            while(w.size()>0)
            {
                int last=w.back();
                bool talal=false;
                while(mutato[last]<G[last].size())
                {
                    int sz=G[last][mutato[last]];
                    if(!bejar[last][mutato[last]])
                    {
                        w.push_back(sz);
                        bejar[last][mutato[last]]=true;
                        bejar[sz][hol[last][mutato[last]]]=true;
                        mutato[last]++;
                        talal=true;
                        break;
                    }
                    mutato[last]++;
                }
                if(!talal)
                {
                    w.pop_back();
                    if(w.size()>0)
                    {
                        elek[groupCnt].push_back({last, w.back()});
                    }
                }
            }
            groupCnt++;
        }
    }
    for(int i=0; i<groupCnt; i++)
    {
        for(int j=0; j<elek[i].size(); j++)
        {
            if(virtualis(elek[i][j])) continue;
            if(j%2==0)
            {
                answer.push_back(elek[i][j]);
            }
            else
            {
                if(virtualis(elek[i][(j+1)%elek[i].size()]) || virtualis(elek[i][(j-1+elek[i].size())%elek[i].size()]))
                {
                    answer.push_back(elek[i][j]);
                }
            }
        }
    }
    cout<<answer.size()<<'\n';
    //printf("%d\n", answer.size());
    for(pair<int, int> pp: answer)
    {
        cout<<pp.first<<" "<<pp.second<<'\n';
        //printf("%d %d\n", pp.first, pp.second);
    }

    return 0;
}