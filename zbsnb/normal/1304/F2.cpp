#include<iostream>
using namespace std;

struct ST{
    #define ls rt<<1
    #define rs rt<<1|1
    #define mid (l+r)/2
    int t[20010<<2]={},laz[20010<<2]={};
    void php(int rt){t[rt]=max(t[ls],t[rs]);}
    void phd(int rt){
        t[ls]+=laz[rt];
        laz[ls]+=laz[rt];

        t[rs]+=laz[rt];
        laz[rs]+=laz[rt];

        laz[rt]=0;
    }
    void upd(int rt,int l,int r,int x,int y,int z){
        if(x<=l&&r<=y){
            t[rt]+=z;
            laz[rt]+=z;
            return;
        }
        phd(rt);
        if(x<=mid)upd(ls,l,mid,x,y,z);
        if(y>mid)upd(rs,mid+1,r,x,y,z);
        php(rt);
    }
    int que(int rt,int l,int r,int x,int y){
        if(x<=l&&r<=y){
            return t[rt];
        }
        phd(rt);
        int ret=-1<<31;
        if(x<=mid)ret=max(ret,que(ls,l,mid,x,y));
        if(y>mid)ret=max(ret,que(rs,mid+1,r,x,y));
        return ret;
    }
};

int mp[55][20010];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    ST tr[n+2];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            tr[i].upd(1,1,m,j,min(m,j+k-1),mp[i][j]);
            tr[i+1].upd(1,1,m,j,min(m,j+k-1),mp[i][j]);
        }
    }

    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<tr[i].que(1,1,m,j,j)<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    for(int i=3;i<=n+1;i++){
        for(int j=1;j<=m;j++){
            if(j>k) tr[i-1].upd(1,1,m,j-k,j-1,mp[i-1][j-k]);
            tr[i-1].upd(1,1,m,j,min(j+k-1,m),-mp[i-1][j]);
            int tmp=tr[i-1].que(1,1,m,1,m);
            // cout<<j<<" "<<tmp<<endl;
            tr[i].upd(1,1,m,j,j,tmp);
        }
        // for(int j=1;j<=m;j++){
        //     cout<<tr[i].que(1,1,m,j,j)<<" ";
        // }
        // cout<<endl;
    }
    cout<<tr[n+1].que(1,1,m,1,m)<<endl;
}