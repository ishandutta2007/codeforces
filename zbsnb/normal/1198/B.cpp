#include<bits/stdc++.h>
using namespace std;
int a[1000010],b[1000010];

#define ll int
struct SeTree_single{
    #define ls rt<<1
    #define rs rt<<1|1
    #define mid (l+r)/2
    ll t[1000010<<2];
    void php(int rt){t[rt]=max(t[ls],t[rs]);}
    void upd(int rt,int l,int r,int x,int y){
        if(l==r){
            t[rt]+=y;
            return;
        }
        if(x<=mid)upd(ls,l,mid,x,y);
        else upd(rs,mid+1,r,x,y);
        php(rt);
    }
    ll que(int rt,int l,int r,int x,int y){
		if(x>y) return 0;
        if(x<=l&&r<=y){
            return t[rt];
        }
        ll ret=0;
        if(x<=mid)ret=max(ret,que(ls,l,mid,x,y));
        if(y>mid)ret=max(ret,que(rs,mid+1,r,x,y));
        return ret;
    }
} tr;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int x;cin>>x;
		if(x==1){
			int p,x;cin>>p>>x;
			a[p]=x;
			b[p]=i;
		}
		else{
			int x;cin>>x;
			tr.upd(1,1,q,i,x);
		}
	}

	for(int i=1;i<=n;i++){
		int ans=max(a[i],tr.que(1,1,q,b[i],q));
		cout<<ans<<" ";
	}
	cout<<endl;
}