#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,mo=1e9+7;
struct node{int l,r,m,s1,s2,s3,t1,t2;}t[N*3];
inline void upd(int i){	
	t[i].s1=(t[i<<1].s1+t[i<<1|1].s1)%mo;
	t[i].s2=(t[i<<1].s2+t[i<<1|1].s2)%mo;
	t[i].s3=(t[i<<1].s3+t[i<<1|1].s3)%mo;
}
inline void addtag(int i,int v,int o){
	if(o==1){
		t[i].t1=(t[i].t1+v)%mo;
		t[i].s1=(t[i].s1+1ll*v*(t[i].r-t[i].l+1))%mo;
		t[i].s3=(t[i].s3+1ll*v*t[i].s2)%mo;
	}else{
		t[i].t2=(t[i].t2+v)%mo;
		t[i].s2=(t[i].s2+1ll*v*(t[i].r-t[i].l+1))%mo;
		t[i].s3=(t[i].s3+1ll*v*t[i].s1)%mo;
	}
}
inline void pushdown(int i){
	if(t[i].t1)addtag(i<<1,t[i].t1,1),addtag(i<<1|1,t[i].t1,1),t[i].t1=0;
	if(t[i].t2)addtag(i<<1,t[i].t2,2),addtag(i<<1|1,t[i].t2,2),t[i].t2=0;
}
void build(int i,int l,int r){
	t[i]=(node){l,r,l+r>>1,0,0,0,0,0};if(l==r){t[i].s1=l-1;return;}
	build(i<<1,l,t[i].m);build(i<<1|1,t[i].m+1,r);upd(i);
}
void mdy(int i,int L,int R,int c,int o){
	if(L<=t[i].l && t[i].r<=R)return addtag(i,c,o);
	pushdown(i);if(L<=t[i].m)mdy(i<<1,L,R,c,o);if(t[i].m<R)mdy(i<<1|1,L,R,c,o);upd(i);
}
int ask(int i,int L,int R,int c){
	if(L<=t[i].l && t[i].r<=R)return (t[i].s3+1ll*c*t[i].s1)%mo;
	pushdown(i);return ((L<=t[i].m?ask(i<<1,L,R,c):0)+(t[i].m<R?ask(i<<1|1,L,R,c):0))%mo;
}
int getv(int i,int k){
	if(k==t[i].l && k==t[i].r)return printf("%d %d\n",t[i].s1,t[i].s2),0;
	pushdown(i);if(k<=t[i].m)getv(i<<1,k);else getv(i<<1|1,k);
}
int n,aa[N],a[N],b[N],i,j,p1,p2,st1[N],w1,st2[N],w2,ans;
unordered_map<int,int>mp;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;for(i=1;i<=n;++i)cin>>aa[i],a[i]=mp[aa[i]],mp[aa[i]]=i;
	for(auto&u:mp)u.second=n+1;for(i=n;i;--i)b[i]=mp[aa[i]],mp[aa[i]]=i;
	build(1,1,n);
	for(i=j=p1=p2=1;i<=n;++i){
		for(;w1 && a[st1[w1]]<a[i];--w1)mdy(1,st1[w1-1]+1,st1[w1],a[st1[w1]],1);
		mdy(1,st1[w1]+1,i,mo-a[i],1);st1[++w1]=i;p1=min(p1,w1);
		for(;w2 && b[st2[w2]]>b[i];--w2)mdy(1,st2[w2-1]+1,st2[w2],mo-b[st2[w2]],2);
		mdy(1,st2[w2]+1,i,b[i],2);st2[++w2]=i;p2=min(p2,w2);
		for(;j<=i;++j){
			for(;st1[p1]<j;++p1);for(;st2[p2]<j;++p2);
			if(a[st1[p1]]<j-1 && i+1<b[st2[p2]])break;
		}
		if(j<=i)ans=(ans+ask(1,j,i,mo-i-1))%mo;
	}
	cout<<ans<<endl;
	return 0;
}