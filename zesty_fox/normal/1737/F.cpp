// LUOGU_RID: 90486772
#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
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

const int M=17,N=1.2e6+10;

int n,m;
array<int,M> res[N];
pii b[M];
void solve(){
    m=rdi(),n=1;
    for(int i=1;i<=m;i++)
        b[i].fi=rdi(),b[i].se=i,n=n*(b[i].fi+1);
    sort(b+1,b+m+1,[&](pii a,pii b){return a.fi>b.fi||(a.fi==b.fi&&a.se<b.se);});
    if(b[1].fi>=4
        ||(m>=2&&b[1].fi==3&&b[2].fi>=2)
        ||(m>=3&&b[1].fi==2&&b[2].fi==2&&b[3].fi==2)){
        puts("-1");return;
    }
    int len,pos;
    auto append = [&](int i){
        copy(res+1,res+len+1,res+len+1);
        for(int j=2;j<=len;j+=2) res[j][i]=1;
        for(int j=1;j<=len;j+=2) res[j+len][i]=1;
        int p;
        p=find_if(res+1,res+len+1,[&](const auto &v){
            return v[1]==1&&((v[1]&&res[len+2][1])+(v[2]&&res[len+2][2])+(v[3]&&res[len+2][3])==1)
                    &&(i<4||accumulate(v.data()+4,v.data()+i,0)==0)&&(i<=2||v[i]==0);
        })-res;
        swap(res[p],res[len+1]);
        len*=2;
    };
    if(b[1].fi==2){
        if(m>=2&&b[2].fi==2){
            res[1][1]=0,res[1][2]=0;
            res[2][1]=2,res[2][2]=2;
            res[3][1]=0,res[3][2]=1;
            res[4][1]=2,res[4][2]=1;
            res[5][1]=0,res[5][2]=2;
            res[6][1]=1,res[6][2]=1;
            res[7][1]=2,res[7][2]=0;
            res[8][1]=1,res[8][2]=2;
            res[9][1]=1,res[9][2]=0;
            len=9,pos=2;
        }
        else{
            res[1][1]=0,res[2][1]=2,res[3][1]=1;
            len=3,pos=1;
        }
        if(pos+1<=m){
            int i=pos+1;
            copy(res+1,res+len+1,res+len+1);
            for(int j=3;j<=len;j+=2) res[j][i]=1;
            res[len+1][i]=1;
            for(int j=2;j<=len;j+=2) res[j+len][i]=1;
            len*=2;
        }
        for(int i=pos+2;i<=m;i++)
            append(i);
    }
    else{
        if(b[1].fi==3){
            res[1][1]=0,res[2][1]=3,res[3][1]=1,res[4][1]=2;
            len=4,pos=1;
        }
        else{
            res[1][1]=0,res[2][1]=1;
            len=2,pos=1;
        }
        for(int i=pos+1;i<=m;i++)
            append(i);
    }
    for(int i=1;i<=n;i++){
        if(*max_element(res[i].data()+1,res[i].data()+m+1)){
            static int buf[M];
            for(int j=1;j<=m;j++) 
                buf[b[j].se]=res[i][j],res[i][j]=0;
            for(int j=1;j<=m;j++) cout<<buf[j]<<' ';
            cout<<'\n';
        }
    }
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    int T=rdi();
    while(T--) solve();
    return 0;
}