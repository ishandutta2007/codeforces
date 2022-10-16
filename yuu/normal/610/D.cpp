#include <stdio.h>
#include <locale>
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
    if(nega)
        x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "D"
// I can't fucking do C
#include <algorithm>
#include <map>
#include <vector>
#include <deque>
using namespace std;
vector <int> cx, cy;
map <int, int> Mx, My;
int sx, sy;
long long ans=0;
struct seg{
    int l, r, a;
};
vector <seg> doc, ngang, rdoc;
seg make(int l, int r, int a){
    seg res;
    res.l=l;
    res.r=r;
    res.a=a;
    return res;
}
bool cmp(seg a, seg b){
    if(a.a!=b.a)
        return a.a<b.a;
    else if(a.l!=b.l)
        return a.l<b.l;
    return a.r>b.r;
}
bool cmp2(seg a, seg b){
    return a.l>b.l;
}
bool cmp3(seg a, seg b){
    return a.r>b.r;
}
vector <seg> init(vector <seg> x){
    vector <seg> res;
    for(seg s: x){
        if(!res.empty()){
            if(s.a==res.back().a){
                if(res.back().r>=s.l-1){
                    s.l=res.back().l;
                    s.r=max(s.r, res.back().r);
                    res.pop_back();
                }
            }
        }
        res.push_back(s);
    }
    for(seg s: res)
        ans+=s.r-s.l+1;
    return res;
}
int ft[400001];
int n, a, b, c, d;
inline int get(int u){
    int res=0;
    for(; u>0; u-=u&-u)
        res+=ft[u];
    return res;
}
inline int get(int l, int r){
    return get(r)-get(l-1);
}
inline void update(int u, int x){
    for(; u<=sx; u+=u&-u)
        ft[u]+=x;
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    FOR(i, 1, n){
        read(a);
        read(b);
        read(c);
        read(d);
        cx.push_back(a);
        cy.push_back(b);
        if(a==c){//vertical
            cy.push_back(d);
            doc.push_back(make(min(b, d), max(b, d), a));
        }
        else{//horizontal
            cx.push_back(c);
            ngang.push_back(make(min(a, c), max(a, c), b));
        }
    }
    sort(doc.begin(), doc.end(), cmp);
    doc=init(doc);
    sort(ngang.begin(), ngang.end(), cmp);
    ngang=init(ngang);
    sort(cx.begin(), cx.end());
    sort(cy.begin(), cy.end());
    for(int x: cx)
        if(Mx.find(x)==Mx.end())
            Mx[x]=++sx;
    for(int y: cy)
        if(My.find(y)==My.end())
            My[y]=++sy;
    sort(doc.begin(), doc.end(), cmp2);
    for(int i=0; i<doc.size(); i++){
        doc[i].l=My[doc[i].l];
        doc[i].r=My[doc[i].r];
        doc[i].a=Mx[doc[i].a];
    }
    for(int i=0; i<ngang.size(); i++){
        ngang[i].l=Mx[ngang[i].l];
        ngang[i].r=Mx[ngang[i].r];
        ngang[i].a=My[ngang[i].a];
    }
    rdoc=doc;
    sort(rdoc.begin(), rdoc.end(), cmp3);
    for(seg s: ngang){
        while((!doc.empty())&&(doc.back().l<=s.a)){
            update(doc.back().a, 1);
            doc.pop_back();
        }
        while((!rdoc.empty())&&(rdoc.back().r<s.a)){
            update(rdoc.back().a, -1);
            rdoc.pop_back();
        }
        ans-=get(s.l, s.r);
    }
    writeln(ans);
}