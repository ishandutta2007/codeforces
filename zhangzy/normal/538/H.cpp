#include<bits/stdc++.h>
using namespace std;

int n, m, li[101000], ri[101000], tl, tr, gl[2], gr[2];
vector<int>G[101000], V; int vis[101000], an1, an2;

void dfs(int x,int c){
    V.push_back(x);
    gl[c]=max(gl[c],li[x]);
    gr[c]=min(gr[c],ri[x]);
    vis[x]=c;
    for (auto y:G[x])
        if (vis[y]==-1){
            dfs(y,c^1);
        }else{
            if (vis[x]==vis[y]){
                puts("IMPOSSIBLE");
                exit(0);
            }
        }
}

struct node{
    int tim, l, r, v;
};
vector<node>nd;

void fuck(int l0,int r0,int l1,int r1){
    if (l0>r0) return;
    nd.push_back({l0,l1,r1,1});
    nd.push_back({r0+1,l1,r1,-1});
}

multiset<int>rps; multiset<int,greater<int> >lps; int aim;
void shit(){
    sort(nd.begin(),nd.end(),[](node a,node b){ return a.tim<b.tim; });
    nd.push_back({(int)1e9,1,1,1});
    int las=0;
    for (auto o:nd){
        if (o.tim!=las&&rps.size()==aim){ // [las,o.tim)  (tl-o.tim,tr-las]
            int l=max(tl-o.tim+1,*lps.begin()), r=min(tr-las,*rps.begin());
            l=max(l,0); r=min(r,tr);
            if (l<=r){
                an2=r; an1=max(tl-an2,las);
                return;
            }
        }
        las=o.tim;
        if (o.v==1){
            lps.insert(o.l);
            rps.insert(o.r);
        }else{
            lps.erase(lps.find(o.l));
            rps.erase(rps.find(o.r));
        }
    }
    puts("IMPOSSIBLE");
    exit(0);
}

int main(){
    cin>>tl>>tr;
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>li[i]>>ri[i];
    }
    for (int x,y;m--;){
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    memset(vis,-1,sizeof vis);
    for (int i=1;i<=n;++i)
        if (vis[i]==-1){
            gl[0]=gl[1]=0;
            gr[0]=gr[1]=1e9;
            dfs(i,0);
            if (gl[0]>gl[1]){
                swap(gl[0],gl[1]);
                swap(gr[0],gr[1]);
            }
            if (gr[0]<=gr[1]){
                fuck(gl[0],gr[0],gl[1],gr[1]);
            }else{
                fuck(gl[0],gl[1]-1,gl[1],gr[1]);
                fuck(gl[1],gr[1],gl[1],gr[0]);
            }
            ++aim;
        }
    shit();
    memset(vis,-1,sizeof vis);
    for (int i=1;i<=n;++i)
        if (vis[i]==-1){
            V.clear();
            gl[0]=gl[1]=0;
            gr[0]=gr[1]=1e9;
            dfs(i,0);
            if (gl[0]<=an1&&an1<=gr[0]&&gl[1]<=an2&&an2<=gr[1]){

            }else{
                for (auto o:V) vis[o]^=1;
            }
        }
    puts("POSSIBLE");
    cout<<an1<<' '<<an2<<endl;
    for (int i=1;i<=n;++i){
        cout<<vis[i]+1;
    }
    cout<<endl;
}