#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

const int N = 10006;

int x[N],y[N];
int n,m,k;

vector<int> vx,vy;

struct Event
{
    int L,R;
    int type;
    Event(){}
    Event(int _L,int _R,int _type) : L(_L),R(_R),type(_type){}
};

vector<Event> e[N];

struct Rec
{
    int x1,x2,y1,y2;
    Rec(){}
    Rec(int _x1,int _x2,int _y1,int _y2) : x1(_x1),x2(_x2),y1(_y1),y2(_y2){}
    void gee()
    {
        vx.push_back(x1);vx.push_back(max(1,x1-1));vx.push_back(min(n,x1+1));
        vx.push_back(x2);vx.push_back(max(1,x2-1));vx.push_back(min(n,x2+1));
        vy.push_back(y1);vy.push_back(max(1,y1-1));vx.push_back(min(m,y1+1));
        vy.push_back(y2);vy.push_back(max(1,y2-1));vx.push_back(min(m,y2+1));
    }
    void gao()
    {
        x1 = lower_bound(vx.begin(),vx.end(),x1) - vx.begin();
        x2 = lower_bound(vx.begin(),vx.end(),x2) - vx.begin();
        y1 = lower_bound(vy.begin(),vy.end(),y1) - vy.begin();
        y2 = lower_bound(vy.begin(),vy.end(),y2) - vy.begin();
        e[x1].push_back(Event(y1,y2,1));
        if (vx[x2] + 1 <= n) e[x2+1].push_back(Event(y1,y2,-1));
    }
} rec[N];

const int INF = 0x3f3f3f3f;

struct Node
{
    Node *lc,*rc;
    int sum,cnt;
    int L,R;
    int mn,mx;
    Node(int _L,int _R):lc(NULL),rc(NULL),sum(0),cnt(0),L(_L),R(_R),mn(INF),mx(-INF) {}
    void pull()
    {
        if (cnt)
        {
            sum = R-L + 1;
            mn = INF;
            mx = -INF;
        }
        else if (L == R)
        {
            assert(L==R);
            mn = L;
            mx = R;
        }
        else
        {
            sum = lc->sum + rc->sum;
            mn = min(lc->mn,rc->mn);
            mx = max(lc->mx,rc->mx);
        }
    }
};

Node* Build(int L,int R)
{
    Node* node = new Node(L,R);
    if (L==R)
    {
        node->pull();
        return node;
    }
    int mid=(L+R)>>1;
    node->lc = Build(L,mid);
    node->rc = Build(mid+1,R);
    node->pull();
    return node;
}

void modify(Node* node,int L,int R,int l,int r,int type)
{
    if (l > R || L > r) return;
    else if (l <= L && R <= r)
    {
        node->cnt += type;
        node->pull();
        return;
    }
    int mid=(L+R)>>1;
    modify(node->lc,L,mid,l,r,type);
    modify(node->rc,mid+1,R,l,r,type);
    node->pull();
    return;
}

int query_sum(Node* node,int L,int R,int l,int r)
{
    if (L>r || l>R) return 0;
    else if (l <= L && R <= r) return node->sum;
    int mid=(L+R)>>1;
    return query_sum(node->lc,L,mid,l,r) + query_sum(node->rc,mid+1,R,l,r);
}

int query_max(Node* node,int L,int R,int l,int r)
{
    if (L>r || l>R) return -INF;
    else if (l<=L && R<=r) return node->mx;
    int mid=(L+R)>>1;
    return max(query_max(node->lc,L,mid,l,r),query_max(node->rc,mid+1,R,l,r));
}

int query_min(Node* node,int L,int R,int l,int r)
{
    if (L>r || l>R) return INF;
    else if (l<=L && R<=r) return node->mn;
    int mid=(L+R)>>1;
    return min(query_min(node->lc,L,mid,l,r),query_min(node->rc,mid+1,R,l,r));
}

bool can(int mid)
{
    //cout << "mid = "<<mid<<endl;
    for (int i=0;N>i;i++)
    {
        e[i].clear();
    }
    vx.clear(); vx.push_back(-1);  //index start from 1
    vy.clear(); vy.push_back(-1);
    vx.push_back(1); vx.push_back(n);
    vy.push_back(1); vy.push_back(m);
    for (int i=1;k>=i;i++)
    {
        rec[i] = Rec( max(1,x[i]-mid),min(n,x[i]+mid),max(1,y[i]-mid),min(m,y[i]+mid) );
        rec[i].gee();
        //cout << "x1 = "<<rec[i].x1<<" , x2 = "<<rec[i].x2<<" , y1 = "<<rec[i].y1<<" , y2 = "<<rec[i].y2<<endl;
    }
    //cout << "finish gee"<<endl;
    sort(vx.begin(),vx.end()); vx.resize(unique(vx.begin(),vx.end()) - vx.begin());
    sort(vy.begin(),vy.end()); vy.resize(unique(vy.begin(),vy.end()) - vy.begin());
    for (int i=1;k>=i;i++)
    {
        rec[i].gao();
    }
    //cout << "finish gao"<<endl;
    int min_x = INF, max_x = -INF,min_y = INF,max_y = -INF;
    int n = vx.size()-1,m=vy.size()-1;
    Node* root = Build(1,m);
    //cout << "ori root->mn = "<<root->mn<<" , root->mx = "<<root->mx<<endl;
    //cout << "finish build"<<endl;
    //cout << "n = "<<n<<" , m = "<<m<<endl;
    for (int i=1;n>=i;i++)
    {
        //cout << "i = "<<i<<endl;
        for (Event ee:e[i])
        {
            //cout << "L = "<<ee.L<<" , R = "<<ee.R<<" , type = "<<ee.type<<endl;
            modify(root,1,m,ee.L,ee.R,ee.type);
        }
        //cout << "finish events"<<endl;
        if (root->sum == m) continue;
        min_x = min(min_x,vx[i]);
        max_x = max(max_x,vx[i]);
        int mn = root->mn, mx = root->mx;
        //cout << "mn = "<<mn<<" , mx = "<<mx<<endl;
        min_y = min(min_y,vy[mn]);
        max_y = max(max_y,vy[mx]);
    }
    //cout << "max_x = "<<max_x<<" , min_x = "<<min_x<<" , max_y = "<<max_y<<" , min_y = "<<min_y<<endl;
    if (max_x - min_x <= 2*mid && max_y - min_y <= 2*mid) return true;
    else return false;
}

int main ()
{
    scanf("%d %d %d",&n,&m,&k);
    for (int i=1;k>=i;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
    if (k+1 == n*m)
    {
        puts("0");
        return 0;
    }
    int L=0,R=1e9 + 7;
    //R is the answer
    while (R-L != 1)
    {
        int mid = (L+R)>>1;
        if (can(mid)) R=mid;
        else L=mid;
    }
    printf("%d\n",R);
}