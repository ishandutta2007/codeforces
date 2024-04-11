#include<bits/stdc++.h>
using namespace std;

const int N=4e5+1e3+7;

int n,l[N],r[N],t[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<pii>op[N];

multiset<int>s[2];

vector<int>X;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&l[i],&r[i],&t[i]),X.push_back(l[i]),X.push_back(r[i]);
    sort(X.begin(),X.end());
    for(int i=1;i<=n;i++)
    {
        l[i]=lower_bound(X.begin(),X.end(),l[i])-X.begin()+1;
        r[i]=lower_bound(X.begin(),X.end(),r[i])-X.begin()+1;
        op[l[i]].push_back(mp(r[i],t[i]-1));
    }
    int ans=0;
    for(int i=1;i<=n*2;i++)
    {
        for(auto [x,y]:op[i])
            s[y].insert(x);
        int p=s[0].count(i),q=s[1].count(i);
        int t=min(p,q);
        p-=t,q-=t;
        s[0].erase(i);
        s[1].erase(i);
        ans+=t;
        int id=p?1:0,ct=p+q;
        while(s[id].size()&&ct)
        {
            s[id].erase(s[id].begin());
            ct--;
            ans++;
        }
    }
    printf("%d\n",n-ans);
}