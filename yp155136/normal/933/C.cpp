#include <bits/stdc++.h>
using namespace std;

typedef double D;  //maybe long double
typedef pair<D,D> pdd;
const D eps = 1e-9;

struct Circle
{
    D x,y,r;
    pdd cen;
    Circle(){}
    Circle(D _x,D _y,D _r) : x(_x),y(_y),r(_r),cen(make_pair(_x,_y)){}
} cir[3];

struct Cir_inter_type
{
    int type;
    vector<pdd> pts;
    Cir_inter_type(){}
    Cir_inter_type(int _type,vector<pdd> _pts) : type(_type),pts(_pts){}
};

#define F first
#define S second

D get_dis(pdd a,pdd b)
{
    return sqrt(pow(a.F-b.F,2) + pow(a.S-b.S,2));
}

bool eq(D a,D b)
{
    return fabs(a-b) <= eps;
}

bool les(D a,D b)
{
    return !eq(a,b) && a<b;
}

bool leq(D a,D b)
{
    return les(a,b) || eq(a,b);
}

Cir_inter_type circle_inter(Circle a, Circle b)
{
    Cir_inter_type ret;
    D dis=get_dis(a.cen,b.cen);
    if (eq(a.r+b.r,dis)) {
        //outside cut --> type 1
        D x=a.x + (b.x-a.x)*(a.r)/(a.r + b.r);
        D y=a.y + (b.y-a.y)*(a.r)/(a.r + b.r);
        vector<pdd> pts;
        pts.push_back(make_pair(x,y));
        ret = Cir_inter_type(1,pts);
    }
    else if (eq( max(a.r,b.r),min(a.r,b.r) + dis )) {
        //inside cut --> type 2
        if (a.r < b.r) swap(a,b);
        D x=a.x + (b.x - a.x)*a.r/(a.r - b.r);
        D y=a.y + (b.y - a.y)*a.r/(a.r - b.r);
        vector<pdd> pts;
        pts.push_back(make_pair(x,y));
        ret = Cir_inter_type(2,pts);
    }
    else if (les(a.r+b.r,dis)) {
        //no intersection --> type 3
        vector<pdd> pts;
        ret = Cir_inter_type(3,pts);
    }
    else if (les(min(a.r,b.r)+dis,max(a.r,b.r))) {
        //fully inside
        //if a is fully contain b, return type 4
        //if b is fully contain a, return type 5
        vector<pdd> pts;
        if (les(b.r,a.r))
        {
            ret = Cir_inter_type(4,pts);
        }
        else if (les(a.r,b.r))
        {
            ret = Cir_inter_type(5,pts);
        }
    }
    else if (les(dis,a.r + b.r)) {
        //two intersections --> type 6
        D c1=2*(b.x-a.x)*b.r;
        D c2=2*(b.y-a.y)*b.r;
        D c3=a.r*a.r-b.r*b.r-(b.x-a.x)*(b.x-a.x)-(b.y-a.y)*(b.y-a.y);
        D aa = c1*c1 + c2*c2;
        D bb = -2*c2*c3;
        D cc = c3*c3 - c1*c1;
        D sin1 = (-bb + sqrtl(bb*bb-4*aa*cc))/(2*aa);
        D sin2 = (-bb - sqrtl(bb*bb-4*aa*cc))/(2*aa);
        D aaa = c1*c1 + c2*c2;
        D bbb = -2*c1*c3;
        D ccc = c3*c3 - c2*c2;
        D cos1=(-bbb+sqrtl(bbb*bbb-4*aaa*ccc))/(aaa*2);
        D cos2=(-bbb-sqrtl(bbb*bbb-4*aaa*ccc))/(aaa*2);
        vector<pdd> pts;
        if (eq(sin1*sin1 + cos1*cos1,1.))
        {
            pts.push_back(make_pair(b.x + b.r*cos1,b.y + b.r*(sin1)));
            pts.push_back(make_pair(b.x + b.r*cos2,b.y + b.r*(sin2)));
        }
        else {
            pts.push_back(make_pair(b.x + b.r*cos1,b.y + b.r*(sin2)));
            pts.push_back(make_pair(b.x + b.r*cos2,b.y + b.r*(sin1)));
        }
        ret = Cir_inter_type(6,pts);
    }
    return ret;
}

bool on_cir(pdd pts,Circle cir)
{
    return eq(pow(pts.F-cir.x,2) + pow(pts.S-cir.y,2),pow(cir.r,2));
}

bool equ(pdd a,pdd b)
{
    return eq(a.F,b.F) && eq(a.S,b.S);
}

struct DisjointSet
{
    static const int N = 106;
    int p[N];
    void init(int n)
    {
        for (int i=0;n>=i;i++)
        {
            p[i] = i;
        }
    }
    int Find(int x)
    {
        return p[x] == x ? x : p[x] = Find(p[x]);
    }
    void Union(int x,int y)
    {
        p[Find(x)] = Find(y);
    }
} djs,djs2;

const int N = 56;

vector<int> v[N];
bool vis[N];

int main ()
{
    int n;
    cin >> n;
    if (n==1)
    {
        cout << 2 << endl;
        return 0;
    }
    for (int i=0;n>i;i++)
    {
        D x,y,r;
        cin >>x >> y>>r;
        cir[i] = Circle(x,y,r);
    }
    if (n==2)
    {
        Cir_inter_type ret = circle_inter(cir[0],cir[1]);
        if (ret.type == 6) cout << 4 <<endl;
        else cout << 3 <<endl;
        return 0;
    }
    vector<pdd> ptss;
    for (int i=0;n>i;i++)
    {
        for (int j=i+1;n>j;j++)
        {
            Cir_inter_type ret = circle_inter(cir[i],cir[j]);
            for (pdd p:ret.pts)
            {
                ptss.push_back(p);
            }
        }
    }
    //unique the points
    vector<pdd> pts;
    for (pdd p:ptss)
    {
        bool can=true;
        for (pdd pp:pts)
        {
            if (equ(p,pp))
            {
                can=false;
                break;
            }
        }
        if (can)
        {
            pts.push_back(p);
        }
    }
    map<pdd,int> mp;
    int e=0;
    int nn=0;
    for (pdd p:pts)
    {
        mp[p] = (++nn);
    }
    memset(vis,0,sizeof(vis));
    djs.init(nn);
    for (int i=0;n>i;i++)
    {
        for (pdd p:pts)
        {
            if (on_cir(p,cir[i]))
            {
                e++;
                vis[i] = 1;
            }
        }
    }
    int non_vis = 0;
    for (int i=0;n>i;i++)
    {
        non_vis += (!vis[i]);
    }
    int v = pts.size();
    int c=non_vis;
    if (non_vis != 3) c++;
    //v - e + f = c + 1
    cout << c+1-v+e << endl;
}