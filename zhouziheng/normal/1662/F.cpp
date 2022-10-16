#include<bits/stdc++.h>
using namespace std;
int T,n,a,b,p[200010],dis[200010];
struct Cmp1{
	bool operator() (const int &a, const int &b) const{
        if(a-p[a]!=b-p[b]) return a-p[a]<b-p[b];
        else return a<b;
	}
};
struct Cmp2{
	bool operator() (const int &a, const int &b) const{
        if(a+p[a]!=b+p[b]) return a+p[a]<b+p[b];
        else return a<b;
	}
};
set<int,Cmp1> S1[800010];
set<int,Cmp2> S2[800010];
bool vis[200010];
void Insert(set<int,Cmp1> *S,int k,int l,int r,int x){
    // printf("I1 %d %d\n",k,x);
    S[k].insert(x);
    if(r-l<20) return;
    int mid=(l+r)>>1;
    if(x<=mid) Insert(S,k<<1,l,mid,x);
    else Insert(S,k<<1|1,mid+1,r,x);
}
void Insert(set<int,Cmp2> *S,int k,int l,int r,int x){
    S[k].insert(x);
    if(r-l<20) return;
    int mid=(l+r)>>1;
    if(x<=mid) Insert(S,k<<1,l,mid,x);
    else Insert(S,k<<1|1,mid+1,r,x);
}
vector<int> tmp;
void Find(set<int,Cmp1> *S,int k,int l,int r,int x,int y,int g,int q){
    if(x>y||g>q) return;
    if(r-l<20){
        for(auto t:S[k]){
            if(t>=x&&t<=y&&t-p[t]>=g&&t-p[t]<=q){
                tmp.push_back(t);
            }
        }
        return;
    }
    if(x<=l&&r<=y){
        p[0]=-g;auto it=S[k].lower_bound(0);
        for(;it!=S[k].end()&&*it-p[*it]<=q;++it){
            tmp.push_back(*it);
            // printf("1 %d %d %d %d\n",*it,*it-p[*it],g,q);
            // printf("%d %d %d %d %d\n",k,x,y,g,q);
            // for(auto x:S[k]) printf("%d ",x);puts("");
        }
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) Find(S,k<<1,l,mid,x,y,g,q);
    if(mid<y) Find(S,k<<1|1,mid+1,r,x,y,g,q);
}
void Find(set<int,Cmp2> *S,int k,int l,int r,int x,int y,int g,int q){
    if(x>y||g>q) return;
    if(r-l<20){
        for(auto t:S[k]){
            if(t>=x&&t<=y&&t+p[t]>=g&&t+p[t]<=q){
                tmp.push_back(t);
            }
        }
        return;
    }
    if(x<=l&&r<=y){
        p[0]=g;auto it=S[k].lower_bound(0);
        for(;it!=S[k].end()&&*it+p[*it]<=q;++it){
            tmp.push_back(*it);
            // printf("2 %d %d %d %d\n",*it,*it+p[*it],g,q);
        }
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) Find(S,k<<1,l,mid,x,y,g,q);
    if(mid<y) Find(S,k<<1|1,mid+1,r,x,y,g,q);
}
void Erase(set<int,Cmp1> *S,int k,int l,int r,int x){
    S[k].erase(x);
    if(r-l<20) return;
    int mid=(l+r)>>1;
    if(x<=mid) Erase(S,k<<1,l,mid,x);
    else Erase(S,k<<1|1,mid+1,r,x);
}
void Erase(set<int,Cmp2> *S,int k,int l,int r,int x){
    S[k].erase(x);
    if(r-l<20) return;
    int mid=(l+r)>>1;
    if(x<=mid) Erase(S,k<<1,l,mid,x);
    else Erase(S,k<<1|1,mid+1,r,x);
}
void solve(){
    scanf("%d %d %d",&n,&a,&b);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=0;i<=(n<<2);i++) S1[i].clear(),S2[i].clear();
    for(int i=1;i<=n;i++){
        Insert(S1,1,1,n,i);
        Insert(S2,1,1,n,i);
    }
    for(int i=1;i<=n;i++) dis[i]=-1,vis[i]=0;
    queue<int> Q;
    Q.push(a);vis[a]=1;dis[a]=0;
    Erase(S1,1,1,n,a);
    Erase(S2,1,1,n,a);
    while(!Q.empty()){
        int x=Q.front();
        // printf("%d\n",x);
        Q.pop();tmp.clear();
        Find(S2,1,1,n,max(1,x-p[x]),x-1,x,1e9);
        Find(S1,1,1,n,x+1,min(n,x+p[x]),-1e9,x);
        for(auto to:tmp){
            // printf("%d %d %d\n",tot,x,to);
            dis[to]=dis[x]+1;vis[to]=1;Q.push(to);
            Erase(S1,1,1,n,to);
            Erase(S2,1,1,n,to);
        }
        if(vis[b]) break;
    }
    printf("%d\n",dis[b]);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}