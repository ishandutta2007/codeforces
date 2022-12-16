// LUOGU_RID: 96721143
#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=long double;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back

const int N=5e5+10;

int n,k;
db deg[N];

struct Vec{
    i64 x,y;int id;
    Vec operator + (const Vec &rhs) const{
        return {x+rhs.x,y+rhs.y,0};
    }
    Vec operator - (const Vec &rhs) const{
        return {x-rhs.x,y-rhs.y,0};
    }
    db len() const{return hypotl(x,y);}
    i64 len2() const{return x*x+y*y;}
    db arg() const{return atan2((db)y,(db)x);}
};

i64 dot(Vec a,Vec b) {return a.x*b.x+a.y*b.y;}
i64 cross(Vec a,Vec b) {return a.x*b.y-a.y*b.x;}

Vec v[N];

vector<db> val[N];
int use[N];

void calc(const vector<db> &d,vector<db> &res){
    int siz=d.size();res={0};
    db s=0,sum=0;
    for(auto x:d) sum+=x;
    int c=0;
    for(c=1;c<=siz&&k-2*c+1>0;c++){
        s+=(k-2*c+1)*sum;
        res.pb(s),sum-=d[c-1];
    }
    if(c>siz) return;
    sum=0;db sum1=0;
    for(int p=d.size()-1,i=c;i<=siz;i++,p--){
        sum=sum-2*sum1+(k-2*c+1)*d[p],sum1+=d[p],s+=sum;
        res.pb(s);
    }
}

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=rdi(),k=rdi();
    for(int i=1;i<=n;i++){
        v[i].x=rdi(),v[i].y=rdi();
        v[i].id=i,deg[i]=v[i].arg();
    }
    swap(*find_if(v+1,v+n+1,[&](Vec a){return a.len2()==0;}),v[n]);
    sort(v+1,v+n,[&](Vec a,Vec b){
        if(deg[a.id]!=deg[b.id]) return deg[a.id]<deg[b.id];
        else return a.len2()<b.len2();
    });
    
    int tot=0;
    for(int i=1,j;i<n;i=j+1){
        j=i;
        while(j+1<n&&v[j+1].arg()==v[i].arg()) ++j;
        vector<db> d;Vec lst{0,0,0};
        for(int k=i;k<=j;k++)
            d.pb((v[k]-lst).len()),lst=v[k];
        reverse(d.begin(),d.end()),calc(d,val[++tot]);
    }
    val[++tot]={0,0};

    db res=0;
    priority_queue<pair<db,int>> q;
    for(int i=1;i<=tot;i++)
        q.push({val[i][1],i});
    while(k--){
        auto nw=q.top();q.pop();
        res+=nw.fi;
        int id=nw.se,cnt=++use[id];
        if(cnt+1<val[id].size())
            q.push({val[id][cnt+1]-val[id][cnt],id});
    }
    cout<<fixed<<setprecision(7)<<res<<endl;
    return 0;
}