#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, x = 0;
long long a[200005], be[200005];
bool don[200005];
vector<int> g[200005];
vector<long long> w[200005];
vector<pair<long long, int> > h;

void nacti()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    int b, c;
    long long d;
    for(int i = 0; i < m; i++)
    {
        cin>>b>>c>>d;
        d *= 2;
        g[b].push_back(c);
        g[c].push_back(b);
        w[b].push_back(d);
        w[c].push_back(d);
    }
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        be[i] = a[i];
    }
}
int main()
{
    nacti();
    for(int i = 1; i <= n; i++)
    {
        h.push_back(make_pair(-a[i], i));
        push_heap(h.begin(), h.end());
    }
    //cout<<"!"<<endl;
    while(x < n)
    {
        int b;
        long long d;
        b = h.front().second;
        d = -h.front().first;
        pop_heap(h.begin(), h.end());
        h.pop_back();
        if(!don[b])
            x++;
        else
            continue;
        don[b] = true;
        for(int i = 0; i < g[b].size(); i++)
        {
            if(d+w[b][i] < be[g[b][i]])
            {
                be[g[b][i]] = d+w[b][i];
                h.push_back(make_pair(-be[g[b][i]], g[b][i]));
                push_heap(h.begin(), h.end());
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout<<be[i]<<" ";
    cout<<endl;
    return 0;
}