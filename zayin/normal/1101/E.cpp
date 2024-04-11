#include<bits/stdc++.h>
#define ALL(A)  A.begin(),A.end()
#define maxn 500050
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;

int n;
char op[maxn][5];
int x[maxn],y[maxn];

vector<int> D,T;

void init()
{
    scanf("%d",&n);
    D.push_back(0);
    for (int i=0;i<n;++i)
    {
        scanf("%s%d%d",op[i],&x[i],&y[i]);
        if (x[i]<y[i])
            swap(x[i],y[i]);
        D.push_back(x[i]);
        D.push_back(y[i]);
    }
    sort(ALL(D));
    D.resize(unique(ALL(D))-D.begin());
    T.resize(D.size());
}

int pos(int x)
{
    return lower_bound(ALL(D),x)-D.begin();
}

int lowbit(int i)
{
    return i&(-i);
}

void change(int i,int d)
{
    // cout<<"change:"<<i<<" "<<d<<endl;
    for (;i;i-=lowbit(i))
        T[i]=max(T[i],d);
}

int query(int i)
{
    int ans=0;
    for (;i<T.size();i+=lowbit(i))
        ans=max(ans,T[i]);
    return ans;
}

void solve()
{
    for (int i=0;i<n;++i)
    {
        if (*op[i]=='+')
        {
            int p=pos(x[i]);
            change(pos(y[i])-1,inf);
            change(p-1,x[i]);
            change(T.size()-1,y[i]);
        } else
        {
            int w=query(pos(x[i]));
            // cout<<i<<" "<<x[i]<<" "<<y[i]<<" "<<w<<endl;
            puts(w<=y[i]?"YES":"NO");
        }
    }
}

int main()
{
    init();
    solve();
    return 0;
}