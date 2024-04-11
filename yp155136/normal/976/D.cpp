#include <bits/stdc++.h>
using namespace std;

const int N = 1006;

bool adj[N][N];

int find_biggest(set<int> st)
{
    return (*(--st.end()));
}

int find_smallest(set<int> st)
{
    return (*st.begin());
}

void solve(set<int> st,vector<int> v,int num)
{
    if (st.empty() || v.empty()) return;
    //num --> all v is num
    if (find_smallest(st) == 0)
    {
        while (num != find_biggest(st))
        {
            int _ = v[0];
            for (int i:v)
            {
                adj[_][i] = adj[i][_] = false;
            }
            v.erase(v.begin());
            --num;
        }
        st.erase(0);
        solve(st,v,num);
    }
    else
    {
        set<int> new_st;
        int get_num = find_smallest(st);
        for (int i:st)
        {
            if (i != num) new_st.insert(i - get_num);
        }
        num -= get_num;
        while (get_num--) v.pop_back();
        solve(new_st,v,num);
    }
}

int main ()
{
    int n;
    scanf("%d",&n);
    set<int> st;
    int nn = 0;
    for (int i=1;n>=i;i++)
    {
        int x;
        scanf("%d",&x);
        st.insert(x);
        nn = x;
    }
    ++nn;
    vector<int> v;
    for (int i=1;nn>=i;i++)
    {
        v.push_back(i);
        for (int j=1;nn>=j;j++)
        {
            adj[i][j] = adj[j][i] = true;
            if (i == j) adj[i][j] = false;
        }
    }
    solve(st,v,nn-1);
    vector< pair<int,int> > vv;
    for (int i=1;nn>=i;i++)
    {
        for (int j=i+1;nn>=j;j++)
        {
            if (adj[i][j])
            {
                vv.push_back(make_pair(i,j));
            }
        }
    }
    printf("%d\n",(int)vv.size());
    for (pair<int,int> p:vv)
    {
        printf("%d %d\n",p.first,p.second);
    }
}