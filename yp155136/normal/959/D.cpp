#include <bits/stdc++.h>
using namespace std;

const int N = 100006;
const int NN = 20*N;

int p[NN];

void build()
{
    p[0] = p[1] = 1;
    for (int i=2;NN>i;i++)
    {
        if (!p[i])
        {
            p[i] = i;
            for (long long j = i*1LL*i;NN>j;j+=i)
            {
                p[j] = i;
            }
        }
    }
}

vector<int> get_p(int x)
{
    set<int> st;
    while (x != 1)
    {
        st.insert(p[x]);
        x/=p[x];
    }
    vector<int> v;
    for (int i:st) v.push_back(i);
    return v;
}

bool used[NN];

void kirino(int prime)
{
    for (int i=prime;NN>i;i+=prime)
    {
        used[i] = true;
    }
}

int _=2;

int sagiri()
{
    while (used[_]) ++_;
    return _;
}

int __(int x)
{
    int ___ = x;
    while (used[___]) ++___;
    return ___;
}

int main ()
{
    build();
    int n;
    scanf("%d",&n);
    vector<int> ans;
    bool meruru = false;
    for (int i=1;n>=i;i++)
    {
        int x;
        scanf("%d",&x);
        if (used[x] && !meruru)
        {
            meruru = true;
            int nxt = __(x);
            //int nxt = sagiri();
            ans.push_back(nxt);
            vector<int> ret = get_p(nxt);
            for (int i:ret) kirino(i);
        }
        else if (meruru)
        {
            int nxt = sagiri();
            ans.push_back(nxt);
            vector<int> ret = get_p(nxt);
            for (int i:ret) kirino(i);
        }
        else
        {
            ans.push_back(x);
            vector<int> ret = get_p(x);
            for (int i:ret) kirino(i);
        }
    }
    for (int i=0;ans.size()>i;i++)
    {
        if (i) printf(" ");
        printf("%d",ans[i]);
    }
    puts("");
}