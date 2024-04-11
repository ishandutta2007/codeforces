#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<unsigned int> vui;
vector<bool> digits(9);

int n;
int query;
unsigned int infi=2e9+1;
unsigned int szam;

vui ures(10, infi);
vui res(10, infi);

struct Node
{
    int cs;
    int k;
    int v;
    vui mind;
    Node* left;
    Node* right;
    unsigned int bestsum;
    Node(){};
    Node(int cscs, int kk, int vv)
    {
        cs=cscs;
        k=kk;
        v=vv;
        for(int i=0; i<9; i++) mind.push_back(infi);
        bestsum=infi;
        left=NULL;
        right=NULL;
    }
    void update(int x, unsigned int val)
    {
        if(x<k || v<x) return;
        if(k==v)
        {
            for(int i=0; i<9; i++)
            {
                mind[i]=(val%10==0)?infi:szam;
                val/=10;
            }
            bestsum=infi;
            return;
        }
        if(left==NULL) left=new Node(2*cs, k, (k+v)/2);
        if(right==NULL) right=new Node(2*cs+1, (k+v)/2+1, v);
        left->update(x, val);
        right->update(x, val);
        bestsum=infi;
        for(int i=0; i<9; i++)
        {
            mind[i]=min(left->mind[i], right->mind[i]);
            bestsum=min(bestsum, left->mind[i]+right->mind[i]);
        }
        bestsum=min(bestsum, left->bestsum);
        bestsum=min(bestsum, right->bestsum);
    }
    vui mini(int x, int y)
    {
        if(v<x || y<k) return ures;
        if(x<=k && v<=y)
        {
            vui ret(10);
            for(int i=0; i<9; i++) ret[i]=mind[i];
            ret[9]=bestsum;
            return ret;
        }
        vui p1=left->mini(x, y);
        vui p2=right->mini(x, y);

        res[9]=infi;
        for(int i=0; i<9; i++)
        {
            res[i]=min(p1[i], p2[i]);
            res[9]=min(res[9], p1[i]+p2[i]);
        }
        res[9]=min(res[9], p1[9]);
        res[9]=min(res[9], p2[9]);
        return res;
    }
};

//unsigned int tree[9][1000009];
//unsigned int bestsum[1000009];


/*void update(int cs, int k, int v, int x, unsigned int val)
{
    if(x<k || v<x) return;
    if(k==v)
    {
        for(int i=0; i<9; i++)
        {
            tree[i][cs]=(val%10==0)?infi:szam;
            val/=10;
        }
        bestsum[cs]=infi;
        return;
    }
    update(2*cs, k, (k+v)/2, x, val);
    update(2*cs+1, (k+v)/2+1, v, x, val);
    bestsum[cs]=infi;
    for(int i=0; i<9; i++)
    {
        tree[i][cs]=min(tree[i][2*cs], tree[i][2*cs+1]);
        bestsum[cs]=min(bestsum[cs], tree[i][2*cs]+tree[i][2*cs+1]);
    }
    bestsum[cs]=min(bestsum[cs], bestsum[2*cs]);
    bestsum[cs]=min(bestsum[cs], bestsum[2*cs+1]);
}
vui mini(int cs, int k, int v, int x, int y)
{
    if(v<x || y<k) return ures;
    if(x<=k && v<=y)
    {
        vui ret(10);
        for(int i=0; i<9; i++) ret[i]=tree[i][cs];
        ret[9]=bestsum[cs];
        return ret;
    }
    vui p1=mini(2*cs, k, (k+v)/2, x, y);
    vui p2=mini(2*cs+1, (k+v)/2+1, v, x, y);

    res[9]=infi;
    for(int i=0; i<9; i++)
    {
        res[i]=min(p1[i], p2[i]);
        res[9]=min(res[9], p1[i]+p2[i]);
    }
    res[9]=min(res[9], p1[9]);
    res[9]=min(res[9], p2[9]);
    return res;
}*/
/*void kiir()
{
    for(int i=1; i<=7; i++)
    {
        cout<<"Node "<<i<<endl;
        for(int j=0; j<9; j++)
        {
            cout<<tree[j][i]<<" ";
        }
        cout<<endl;
        cout<<"bs: "<<bestsum[i]<<endl;
    }
}*/

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cin>>n>>query;
    scanf("%d %d", &n, &query);
    Node root(1, 0, n-1);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &szam);
        root.update(i-1, szam);
    }
    for(int tt=1; tt<=query; tt++)
    {
        int typ, le, ri;
        //cin>>typ>>le>>ri;
        scanf("%d %d %d", &typ, &le, &ri);
        if(typ==1)
        {
            szam=ri;
            root.update(le-1, szam);
        }
        else
        {
            unsigned int answer=root.mini(le-1, ri-1)[9];
            //cout<<(answer>=infi?(-1):answer)<<'\n';
            printf("%d\n", (answer>=infi?(-1):answer));
        }
    }



    return 0;
}