#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
#define I inline void
#define IN inline ll
typedef long long ll;
I read(ll &res){
    re g=1;register char ch=getchar();res=0;
    while(!isdigit(ch)){
        if(ch=='-')g=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        res=(res<<3)+(res<<1)+(ch^48);
        ch=getchar();
    }
    res*=g;
}
const ll INF=1e9+7;
#define all 1,1,n
#define lt k<<1,l,mid
#define rt k<<1|1,mid+1,r
ll n,m,a[303000],tr[808000],laz[808000],b[303000],ans[303000],maxi,mini,L,R,pos;
I push_down(ll k){
	laz[k<<1]=max(laz[k<<1],laz[k]);
	laz[k<<1|1]=max(laz[k<<1|1],laz[k]);
	tr[k<<1]=max(tr[k<<1],laz[k]);
	tr[k<<1|1]=max(tr[k<<1|1],laz[k]);
	laz[k]=0;
}
I modi(ll k,ll l,ll r,ll x,ll y,ll w){
	if(x>r||y<l)return;
	if(x<=l&&r<=y){
		tr[k]=max(tr[k],w);
		laz[k]=max(laz[k],w);
		return;
	}
	if(laz[k])push_down(k);
	re mid=(l+r)>>1;
	modi(lt,x,y,w);
	modi(rt,x,y,w);
	tr[k]=max(tr[k<<1],tr[k<<1|1]);
}
IN ques(ll k,ll l,ll r,ll x){
	if(l==r&&l==x)return tr[k];
	re mid=(l+r)>>1;
	if(laz[k])push_down(k);
	if(x<=mid)return ques(lt,x);
	else return ques(rt,x);
}
IN divided(ll w,ll x,ll y){
	if(x==y)return x;
	re mid=(x+y+1)>>1;
	if(w<=ques(all,mid))x=mid;
	else y=mid-1;
	return divided(w,x,y);
}
int main(){
	read(n);maxi=-1;mini=INF;
	F(i,1,n){
		read(a[i]);
		maxi=max(maxi,a[i]);
		mini=min(mini,a[i]);
	}
	if(((maxi-1)>>1)<mini){
		F(i,1,n){
			cout<<"-1 ";
		}
		return 0;
	}
	F(i,n+1,n*3){
		a[i]=a[i-n];
	}
	L=1;
	F(i,1,n){
		b[i]=(a[i]-1)>>1;
		if(a[i]<=ques(all,L)){
			pos=divided(a[i],L,i-1);
			F(j,L,pos){
				ans[j]=i-j;
			}
			L=pos+1;
		}
		modi(all,L,i,b[i]);
	}
	F(i,n+1,n*3){
		b[i]=(a[i]-1)>>1;
		if(a[i]<=ques(all,L)){
			pos=divided(a[i],L,n);
			F(j,L,pos){
				ans[j]=i-j;
			}
			L=pos+1;
			if(L>n)break;
		}
		modi(all,L,n,b[i]);
	}
	F(i,1,n){
		cout<<ans[i]<<" ";
	}
    return 0;
}