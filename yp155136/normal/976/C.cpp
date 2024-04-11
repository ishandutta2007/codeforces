#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int N = 300006;

int l[N],r[N];

bool cmp(const int &a,const int &b)
{
    return l[a] < l[b] || l[a] == l[b] && r[a] > r[b];
}

int main ()
{
    int n;
    scanf("%d",&n);
    vector<int> v;
    set<pii> st;
    for (int i=1;n>=i;i++)
    {
        scanf("%d %d",&l[i],&r[i]);
        st.insert(make_pair(r[i],i));
        v.push_back(i);
    }
    sort(v.begin(),v.end(),cmp);
    for (int i:v)
    {
        st.erase(st.find( make_pair(r[i],i) ));
        if (st.empty()) continue;
        pii p = (*st.begin());
        if (p.first <= r[i])
        {
            printf("%d %d\n",p.second,i);
            return 0;
        }
    }
    puts("-1 -1");
}