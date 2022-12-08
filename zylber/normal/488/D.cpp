#include <iostream>
#include <map>
#include <cstring>
using namespace std;
typedef long long tint;
#define forn(i,k) for(int i = 0; i < k; ++i)
#define dforn(i,k) for(int i = k-1; i >= 0; --i)
#define LVL 17
tint vec3[LVL][1<<LVL];
tint mn(int i, int j) { // intervalo [i,j)
    int p = 31-__builtin_clz(j-i);
    return min(vec3[p][i],vec3[p][j-(1<<p)]);
}

void mn_init(int n) {
    int mp = 31-__builtin_clz(n);
    forn(p, mp) forn(x, n-(1<<p)) vec3[p+1][x] = min(vec3[p][x], vec3[p][x+(1<<p)]);
}

tint vec2[LVL][1<<LVL];
tint mx(int i, int j) { // intervalo [i,j)
    int p = 31-__builtin_clz(j-i);
    return max(vec2[p][i],vec2[p][j-(1<<p)]);
}

void mx_init(int n) {
    int mp = 31-__builtin_clz(n);
    forn(p, mp) forn(x, n-(1<<p)) vec2[p+1][x] = max(vec2[p][x], vec2[p][x+(1<<p)]);
}

int izq[100010];

#define MAXN 100000
struct rmq {
    int MAX;
    tint vec[4*MAXN];
    tint* init(int n) {
        MAX = 1 << (32-__builtin_clz(n));
        fill(vec, vec+2*MAX, 0); // 0 = elemento neutro
        return vec+MAX;
    }
    
    void updall() { dforn(i, MAX) vec[i] = min(vec[2*i] , vec[2*i+1]); } // + = operacion
    
    void pset(int i, tint vl) {
        vec[i+=MAX] = vl;
        while(i) { i /= 2; vec[i] = min(vec[2*i] , vec[2*i+1]); } // + = operacion
    }
    
    tint pget(int i, int j) { return _pget(i+MAX, j+MAX); }
    
    tint _pget(int i, int j) {
        tint res = 100000000; // 0 = elemento neutro
        if (j-i <= 0) return res;
        if (i%2) res = min(res,vec[i++]); // + = operacin
        res = min(res,_pget(i/2, j/2)); // + = operacin
        if (j%2) res = min(res,vec[--j]); // + = operacin
        return res;
    }
};
rmq DP;

int main()
{
    tint n, s, l;
    //cout << "ESPLOTE" << endl;
    
    cin >> n >> s >> l;
    
    for(int i=0; i<n; i++)
    {
        cin >> vec3[0][i];
        vec2[0][i]=vec3[0][i];
    }
        
    mn_init(n);
    mx_init(n);
    
    //memset(izq,-1,sizeof(izq));
    for(int i=1; i<n; i++)
    {
        if(mn(0,i)<vec3[0][i]-s)
        {
            int bot=0, top=i;
            while(top-bot>1)
            {
                int mid=(top+bot)/2;
                if(mn(mid,i)<vec3[0][i]-s) bot=mid; else top=mid;
            }
            izq[i]=max(izq[i],top);
        }
        
        if(mx(0,i)>vec3[0][i]+s)
        {
            int bot=0, top=i;
            while(top-bot>1)
            {
                int mid=(top+bot)/2;
                if(mx(mid,i)>vec3[0][i]+s) bot=mid; else top=mid;
            }
            izq[i]=max(izq[i],top);
        }
        
    }
    for(int i=1; i<n; i++) izq[i]=max(izq[i], izq[i-1]);
    forn(i,n) izq[i]--;
    
    tint* v=DP.init(n);
    forn(i,n) v[i]=100000000;
    DP.updall();
    
    forn(i,n)
    {
        if(izq[i]==-1 && i>=l-1) DP.pset(i, 1);
        else
        {
            DP.pset(i, DP.pget(izq[i],i-l+1)+1);
        } 
    }
    
    if(DP.pget(n-1, n) <=n)
    cout << DP.pget(n-1, n) << endl;
    else
    cout << -1 << endl;
}