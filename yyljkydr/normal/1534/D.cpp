#include<bits/stdc++.h>
using namespace std;

const int N=2e3+1e2+7;

int n,d[N][N];

void ask(int x)
{
    printf("? %d\n",x);
    fflush(stdout);
    for(int i=1;i<=n;i++)
        scanf("%d",&d[x][i]);
}

vector<int>v[2];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<pii>ans;

int main()
{
    scanf("%d",&n);
    ask(1);
    for(int i=1;i<=n;i++)
        v[d[1][i]&1].push_back(i);
    if(v[0].size()>v[1].size())
        swap(v[0],v[1]);
    for(auto x:v[0])
    {
        if(x!=1)
            ask(x);
        for(int i=1;i<=n;i++)
            if(d[x][i]==1)
                ans.push_back(mp(x,i));
    }
    assert(ans.size()==n-1);
    puts("!");
    for(auto [x,y]:ans)
        printf("%d %d\n",x,y);
    fflush(stdout);
}