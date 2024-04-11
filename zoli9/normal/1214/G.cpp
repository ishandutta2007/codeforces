#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define maxn 2000

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int n, m, q;
bitset<maxn> ones[2001];
bitset<maxn> bitek[2001];
set<pii> s;
set<int> ans;


void kivesz(int r)
{
    int cnt=bitek[r].count();
    auto it=s.find({cnt, r});
    int nagy=0;
    int kicsi=0;
    if(it!=s.begin())
    {
        it--;
        kicsi=it->S;
        it++;
    }
    it++;
    if(it!=s.end())
    {
        nagy=it->S;
    }
    it--;
    s.erase(it);
    ans.erase(r);
    ans.erase(kicsi);
    if(kicsi==0 || nagy==0) return;
    if((bitek[kicsi] | bitek[nagy]) != bitek[nagy]) ans.insert(kicsi);
}
void berak(int r)
{
    int cnt=bitek[r].count();
    s.insert({cnt, r});
    auto it=s.find({cnt, r});
    int nagy=0;
    int kicsi=0;
    if(it!=s.begin())
    {
        it--;
        kicsi=it->S;
        it++;
    }
    it++;
    if(it!=s.end())
    {
        nagy=it->S;
    }
    it--;
    ans.erase(kicsi);
    if(kicsi!=0)
    {
        if((bitek[kicsi] | bitek[r]) != bitek[r]) ans.insert(kicsi);
    }
    if(nagy!=0)
    {
        if((bitek[r] | bitek[nagy]) != bitek[nagy]) ans.insert(r);
    }
}

void kiir()
{
    cout<<"s contains:"<<endl;
    for(pii p: s)
    {
        cout<<p.F<<" : "<<p.S<<endl;
    }
}

void kiir2()
{
    cout<<"ans contains:"<<endl;
    for(int p: ans)
    {
        cout<<p<<" ---"<<endl;
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cin>>n>>m>>q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i=1; i<=maxn; i++)
    {
        ones[i]=ones[i-1];
        ones[i].set(i-1);
        if(i<=n) s.insert({0, i});
    }
    for(int tt=1; tt<=q; tt++)
    {
        int row, l, r;
        //cin>>row>>l>>r;
        scanf("%d %d %d", &row, &l, &r);
        kivesz(row);
        bitek[row]^=ones[r];
        bitek[row]^=ones[l-1];
        //cout<<row<<": "<<bitek[row]<<endl;
        berak(row);
        if(ans.size()>0)
        {
            int kicsi=*ans.begin();
            int nagy=s.lower_bound({bitek[kicsi].count(), kicsi+1})->S;
            int nn=(bitek[nagy]&(bitek[kicsi]^bitek[nagy]))._Find_first();
            int kk=(bitek[kicsi]&(bitek[kicsi]^bitek[nagy]))._Find_first();
            if(kicsi>nagy) swap(kicsi, nagy);
            if(kk>nn) swap(kk, nn);
            //cout<<kicsi<<" "<<kk+1<<" "<<nagy<<" "<<nn+1<<endl;
            printf("%d %d %d %d\n", kicsi, kk+1, nagy, nn+1);
        }
        else
        {
            //cout<<-1<<endl;
            printf("-1\n");
        }
    }
    return 0;
}