#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N = 100006;
const int SIGMA = 26;

int ch[N][SIGMA];
int sz=1;

#define SZ(x) ((int)(x).size())

#define F first
#define S second

int idx(char c)
{
    return c-'a';
}

string kirino;

bool is_end[N];

void dfs(int now,int nxt_id)
{
    if (nxt_id == SZ(kirino))
    {
        is_end[now] = true;
        return;
    }
    int nxt = idx(kirino[nxt_id]);
    if (ch[now][nxt]) dfs(ch[now][nxt],nxt_id + 1);
    else
    {
        ch[now][nxt] = sz++;
        dfs(ch[now][nxt],nxt_id+1);
    }
}

void add(string s)
{
    kirino = s;
    dfs(0,0);
}

int cnt[N];
int vis[N];
int vis_id = 880301;

vector<pii> v[N];

vector<int> all_num;

void add_num(int num,int times)
{
    if (!times) return;
    if (vis[num] == vis_id)
    {
        cnt[num] += times;
    }
    else
    {
        cnt[num] = times;
        all_num.push_back(num);
        vis[num] = vis_id;
    }
}

void get_ans(int now,int cur_depth)
{
    for (int i=0;SIGMA>i;i++)
    {
        if (ch[now][i])
        {
            //cout << "now = " << now << " , i = " << i << endl;
            get_ans(ch[now][i],cur_depth + 1);
        }
    }
    if (is_end[now])
    {
        v[now].push_back(make_pair(cur_depth,1));
        vis_id++;
        all_num.clear();
        for (int i=0;SIGMA>i;i++)
        {
            if (ch[now][i])
            {
                for (pii p:v[ ch[now][i] ])
                {
                    add_num(p.F,p.S);
                }
                vector<pii> ().swap(v[ ch[now][i] ]);
            }
        }
        for (int i:all_num)
        {
            v[now].push_back(make_pair(i,cnt[i]));
        }
        //return;
    }
    else if (now == 0)
    {
        int ans=0;
        for (int i=0;SIGMA>i;i++)
        {
            if (ch[now][i])
            {
                for (pii p:v[ ch[now][i] ])
                {
                    ans += p.F * p.S;
                }
            }
        }
        cout << ans << endl;
        //printf("%d\n",ans);
        //return;
    }
    else
    {
        //select one with most different counts
        int mx = 0;
        int mx_id = -1;
        for (int i=0;SIGMA>i;i++)
        {
            if (ch[now][i])
            {
                if (SZ( v[ ch[ now ][i] ] ) > mx)
                {
                    mx = SZ(v[ ch[ now ][i] ]);
                    mx_id = i;
                }
            }
        }
        vis_id++;
        all_num.clear();
        for (int i=0;SIGMA>i;i++)
        {
            if (i == mx_id)
            {
                for (pii p:v[ ch[now][i] ])
                {
                    add_num(p.F-1,1);
                    add_num(p.F,p.S-1);
                }
            }
            else if (ch[now][i])
            {
                for (pii p:v[ ch[now][i] ])
                {
                    add_num(p.F,p.S);
                }
            }
            vector<pii> ().swap( v[ ch[now][i] ] );
        }
        for (int i:all_num)
        {
            v[now].push_back(make_pair(i,cnt[i]));
        }
    }
    /*cout << "now = " << now << " , cur_depth = " << cur_depth << endl;
    for (pii p:v[now])
    {
        cout << "( " << p.F << " , " << p.S << " ) " << endl;
    }
    cout << endl << endl;*/
}

int main ()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=0;n>i;i++)
    {
        string s;
        cin >> s;
        add(s);
    }
    //cout << "sz = " << sz << endl;
    get_ans(0,0);
}