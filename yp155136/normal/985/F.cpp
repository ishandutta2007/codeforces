#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;

#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())

pii base = make_pair(991,880301);
pii mod  = make_pair(1000000009,1000000087);

pii operator+(const pii &p1,const pii &p2)
{
    return make_pair((p1.F+p2.F)%mod.F,(p1.S+p2.S)%mod.S);
}

pii operator-(const pii &p1,const pii &p2)
{
    return make_pair((p1.F-p2.F%mod.F+mod.F)%mod.F,(p1.S-p2.S%mod.S+mod.S)%mod.S);
}

pii operator*(const pii &p1,const pii &p2)
{
    return make_pair(p1.F*p2.F%mod.F,p1.S*p2.S%mod.S);
}

pii Val(pii p)
{
    return make_pair(p.F%mod.F,p.S%mod.S);
}

const int N = 200006;
const int SIGMA = 26;

pii ppow[N];

int idx(char c)
{
    return c-'a'+1;
}

int myRnd()
{
    return ((rand()<<14)^rand());
}

pii rnd[N];

void build()
{
    rnd[0] = make_pair(0,0);
    for (int i=1;N>i;i++)
    {
        rnd[i] = Val(make_pair(myRnd(),myRnd()));
    }
    ppow[0] = make_pair(1,1);
    for (int i=1;N>i;i++)
    {
        ppow[i] = ppow[i-1]*base;
    }
}

int a[N];
pii pre[N];
int nxt_same[N];
int pre_same[N][SIGMA];

pii get_val(int L,int R)
{
    pii ret = (pre[R] - pre[L-1]);
    for (int j=0;SIGMA>j;j++)
    {
        int _ = pre_same[R][j];
        if (_ == 0 || _ < L) continue;
        ret = (ret - (ppow[_]*rnd[ nxt_same[_] ]));
    }
    return (ret * ppow[N-L]);
}

int main ()
{
    srand(time(NULL));
    ios::sync_with_stdio(0); cin.tie(0);
    build();
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i=0;n>i;i++)
    {
        a[i+1] = idx(s[i]);
    }
    for (int i=1;n>=i;i++)
    {
        for (int j=0;SIGMA>j;j++)
        {
            if (j == a[i])
            {
                if (pre_same[i-1][j])
                {
                    nxt_same[ pre_same[i-1][j] ] = i-pre_same[i-1][j]+1;
                }
                pre_same[i][j] = i;
            }
            else
            {
                pre_same[i][j] = pre_same[i-1][j];
            }
        }
    }
    for (int i=1;n>=i;i++)
    {
        pre[i] = (pre[i-1] + (ppow[i]*rnd[ nxt_same[i] ]) );
    }
    while (q--)
    {
        int l1,l2,len;
        cin >> l1 >> l2 >> len;
        if (get_val(l1,l1+len-1) == get_val(l2,l2+len-1)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}