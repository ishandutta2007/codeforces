#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define SZ(x) ((int)(x).size())

const int N = 100006;

int q[N];
string m[N];
int ans[N];
deque<int> v[N];

struct AC_Automata {
    static const int N = 100000 + 6;
    static const int SIGMA = 26;
    int ch[N][SIGMA];
    int val[N];
    int sz;
    int last[N],fail[N];
    int que[N],qs,qe;
    int cnt[N];
    void init()
    {
        sz = 1;
        memset(ch[0],0,sizeof(ch[0]));
        qs = qe  = 0;
        memset(cnt,0,sizeof(cnt));
        memset(val,0,sizeof(val));
        memset(last,0,sizeof(last));
    }
    int idx(char c)
    {
        return c-'a';
    }
    int insert(string s,int v)
    {
        int now=0;
        int n=s.size();
        for (int i=0;n>i;i++)
        {
            int c=idx(s[i]);
            if (!ch[now][c])
            {
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz] = 0;
                ch[now][c] = sz++;
            }
            now = ch[now][c];
        }
        val[now] = v;
        return now;
    }
    void print(int j,int now_idx)
    {
        //cout << "j = " << j << " , now_idx = " << now_idx << " , val = " << val[j] << endl;
        if (j)
        {
            v[ val[j] ].PB(now_idx);
            int _ = val[j];
            if (SZ(v[_]) == q[_])
            {
                if (ans[_] == -1)
                {
                    ans[_] = v[_].back() - v[_].front() + m[_].size();

                }
                else
                {
                    ans[_] = min(ans[_],v[_].back() - v[_].front() + (int)m[_].size());
                }
                v[_].pop_front();
            }
            //now we match string v[j]
            print(last[j],now_idx);  //may match multiple strings
        }
    }
    void getFail()
    {
        qs=0,qe=0;
        fail[0]=0;
        for (int c=0;SIGMA >c;c++)
        {
            int now=ch[0][c];
            if (now)
            {
                fail[now] = 0;
                que[qe++] = now;
                last[now] = 0;
            }
        }
        while (qs != qe)
        {
            int t=que[qs++];
            for (int c=0;SIGMA > c;c++)
            {
                int now=ch[t][c];
                if (!now) continue;
                que[qe++] = now;
                int v=fail[t];
                while (v && !ch[v][c]) v=fail[v];
                fail[now] = ch[v][c];
                last[now] = val[ fail[now] ]? fail[now]:last[ fail[now] ];
            }
        }
    }
    void Find(string s)
    {
        getFail();
        //cout<<"qe = "<<qe<<endl;
        int n=s.size();
        int now=0;
        for (int i=0;n>i;i++)
        {
            int c=idx(s[i]);
            while (now && !ch[now][c]) now = fail[now];
            now = ch[now][c];
            print(now,i+1);
            cnt[now]++;
        }
        for (int i=qe-1;i>=0;i--)
        {
            cnt[ fail[que[i]] ] += cnt[ que[i] ];
        }
    }
    void AC_evolution()
    {
        for (qs=1;qs!=qe;)
        {
            int now=que[qs++];
            for (int i=0;SIGMA>i;i++)
            {
                if (ch[now][i] == 0) ch[now][i] = ch[fail[now]][i];
            }
        }
    }
} ac;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> s;
    ac.init();
    cin >>n;
    for (int i=1;n>=i;i++)
    {
        cin >> q[i] >> m[i];
        ac.insert(m[i],i);
    }
    ac.getFail();
    memset(ans,-1,sizeof(ans));
    ac.Find(s);
    for (int i=1;n>=i;i++)
    {
        printf("%d\n",ans[i]);
    }
}