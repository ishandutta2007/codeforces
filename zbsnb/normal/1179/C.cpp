#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct SeTree_max{
    #define ls rt<<1
    #define rs rt<<1|1
    #define mid (l+r)/2
    int t[1000010<<2],laz[1000010<<2];
    void php(int rt){t[rt]=max(t[ls],t[rs]);}
    void phd(int rt){
        t[ls]+=laz[rt];laz[ls]+=laz[rt];
        t[rs]+=laz[rt];laz[rs]+=laz[rt];
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
        int ret=-1<<30;
        if(x<=mid)ret=max(ret,que(ls,l,mid,x,y));
        if(y>mid)ret=max(ret,que(rs,mid+1,r,x,y));
        return ret;
    }
    void build(int rt,int l,int r,int a[]){
        if(l==r){
            t[rt]=a[l];
            return;
        } 
        build(ls,l,mid,a);
        build(rs,mid+1,r,a);
        php(rt);
    }
} tr;
void upd(int x,int y){
	tr.upd(1,1,1000000,x,1000000,y);
}
int a[1000010],b[1000010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		int tmp;cin>>tmp;tmp=1000001-tmp;
		upd(tmp,1);a[i]=tmp;
	}
	for(int i=1;i<=m;i++){
		int tmp;cin>>tmp;tmp=1000001-tmp;
		upd(tmp,-1);b[i]=tmp;
	}
	int q;cin>>q;
	while(q--){
		int x,y,z;cin>>x>>y>>z;z=1000001-z;
		if(x==1){
			upd(a[y],-1);
			upd(z,1);
			a[y]=z;
		}
		else{
			upd(b[y],1);
			upd(z,-1);
			b[y]=z;
		}
		int l=1,r=1000000,ans=1000002;
		while(l<=r){
			int m=(l+r)>>1;
			int tmp=tr.que(1,1,1000000,1,m);
			// cout<<l<<" "<<r<<" "<<tmp<<endl;
			if(tmp>0){
				ans=min(ans,m);
				r=m-1;
			}
			else l=m+1;
		}
		cout<<1000001-ans<<endl;
	}
	
}