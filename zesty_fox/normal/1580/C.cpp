#include <bits/stdc++.h>

using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=200010,BL=451;

struct Train{int x,y,id;}t[N];
int n,m,lim,st[N];

int sum[N],buc[BL+5][BL+5],tot;

void add(int day,Train t){
    int lp=t.x+t.y;
    if(lp>lim) for(int i=day;i<=m;i+=lp) sum[i]++,sum[min(i+t.x,m+1)]--;
    else for(int i=1,cur=day%lp;i<=t.x;i++,cur=(cur+1)%lp) buc[lp][cur]++;
    st[t.id]=day,tot++;
}

void del(int day,Train t){
    int now=st[t.id],lp=t.x+t.y;
    if(lp>lim){
        for(int i=now;i<=m;i+=lp){
            int l=i,r=min(i+t.x,m+1);
            sum[l<day?day-1:l]--;
            sum[r<day?day-1:r]++;
        }
    }
    else for(int i=1,cur=now%lp;i<=t.x;i++,cur=(cur+1)%lp) buc[lp][cur]--;
    tot--;
}

int main(){
    n=rdi(),m=rdi();lim=min((int)sqrt(m),BL);
    for(int i=1;i<=n;i++) t[i].x=rdi(),t[i].y=rdi(),t[i].id=i;
    for(int d=1;d<=m;d++){
        int op=rdi(),k=rdi();
        op==1?add(d,t[k]):del(d,t[k]);
        int res=tot;
        for(int i=1;i<=lim;i++) res-=buc[i][d%i];
        res-=(sum[d]+=sum[d-1]);
        printf("%d\n",res);
    }
    return 0;
}