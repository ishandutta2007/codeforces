#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

#define y1 kirino
#define y2 sagiri

ld ppow(ld a,int n)
{
    ld ret=1;
    while (n--) ret*=a;
    return ret;
}

ld get_dis(ld x1,ld y1,ld z1,ld x2,ld y2,ld z2)
{
    return sqrtl( ppow(x1-x2,2)+ppow(y1-y2,2)+ppow(z1-z2,2) );
}

const int N = 10006;
const ld eps = 1e-9;

ld x[N],y[N],z[N];
ld pre[N];

ld vp,vs;

void get_pos(ld t,ld vs,ld &ansx,ld &ansy,ld &ansz,int n)
{
    int pos=upper_bound(pre+1,pre+n+1,t+eps)-pre - 1;
    ld t_left = t-pre[pos];
    //cout << "pos = " << pos << endl;
    ansx = x[pos]+(x[pos+1]-x[pos])*(t_left)/(pre[pos+1]-pre[pos]);
    ansy = y[pos]+(y[pos+1]-y[pos])*(t_left)/(pre[pos+1]-pre[pos]);
    ansz = z[pos]+(z[pos+1]-z[pos])*(t_left)/(pre[pos+1]-pre[pos]);
}

typedef long long LL;

LL xx[N],yy[N],zz[N];

LL ppow(LL a,LL n)
{
    LL ret=1;
    while (n--) ret*=a;
    return ret;
}

int main ()
{
    int n;
    cin >> n;
    ++n;
    for (int i=1;n>=i;i++)
    {
        cin >> xx[i] >> yy[i] >> zz[i];
        x[i] = xx[i];
        y[i] = yy[i];
        z[i] = zz[i];
        //cin >> x[i]>>y[i]>>z[i];
        /*if (i>1)
        {
            pre[i] = pre[i-1] + get_dis(x[i-1],y[i-1],z[i-1],x[i],y[i],z[i]);
        }*/
    }
    LL vvp,vvs;
    cin >> vvp >> vvs;
    vp = vvp;
    vs = vvs;
    //cin >> vp >> vs;
    for (int i=1;n>=i;i++)
    {
        //cin >> x[i]>>y[i]>>z[i];
        if (i>1)
        {
            pre[i] = pre[i-1] + get_dis(x[i-1],y[i-1],z[i-1],x[i],y[i],z[i])/vs;
        }
        //cout << "i = "<< i << " , pre = " << pre[i] <<endl;
    }
    ld px,py,pz;
    LL ppx,ppy,ppz;
    cin >> ppx >> ppy >> ppz;
    px = ppx;
    py = ppy;
    pz = ppz;
    //cin >> px >> py >> pz;
    //if ( (ppow(xx[i]-ppx) + ppow(yy[i]-ppx) + ) )
    if (get_dis(px,py,pz,x[n],y[n],z[n])/vp >= pre[n]+eps)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    ld l=0-eps,r = pre[n];
    //cout << "l = " << l << " r = " << r <<endl;
    int cnt = 300;
    while (cnt--)
    {
        ld mid=(l+r)/2;
        //see when on time mid
        ld x,y,z;
        get_pos(mid,vs,x,y,z,n);
        //cout << "mid = " << mid << " , x = " << x << " , y = " <<y << " , z = " << z <<endl;
        //cout << "times = " << get_dis(x,y,z,px,py,pz)/vp << endl;
        if (get_dis(x,y,z,px,py,pz)/vp <= mid)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << fixed << setprecision(12) << (long double)r << endl;
    ld x,y,z;
    get_pos((l+r)/2,vs,x,y,z,n);
    cout << fixed << setprecision(12) << (long double)x << ' ' << (long double)y << ' ' << (long double)z <<endl;
}