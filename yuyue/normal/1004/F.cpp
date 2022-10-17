#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
#define oo(x) fixed<<setprecision(x)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=1e5+10;
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
int pre[M<<3][22],suf[M<<3][22],o[M<<3][22],p[M<<3][22],co[M<<3],cp[M<<3],a[M],np[M<<3][22],no[M<<3][22];
int k;
LL s[M<<3];
bool cmp(int A,int B){
	return A>B;
}
void pu(int x,int l,int r){
	F(i,0,20){
		if (pre[lc][i]) pre[x][i]=pre[lc][i];
		else pre[x][i]=pre[lc][i]|pre[rc][i];
		if (suf[rc][i]) suf[x][i]=suf[rc][i];
		else suf[x][i]=suf[lc][i]|suf[rc][i];
	} co[x]=cp[x]=0; 
	F(i,0,20) if (pre[x][i]) o[x][++co[x]]=pre[x][i];
	F(i,0,20) if (suf[x][i]) p[x][++cp[x]]=suf[x][i];
	sort(o[x]+1,o[x]+co[x]+1); o[x][++co[x]]=r+1; o[x][0]=l; F(i,1,co[x]-1) no[x][i]=no[x][i-1]|a[o[x][i]];
	sort(p[x]+1,p[x]+cp[x]+1,cmp); p[x][++cp[x]]=l-1; p[x][0]=r; F(i,1,cp[x]-1) np[x][i]=np[x][i-1]|a[p[x][i]];
	s[x]=s[lc]+s[rc];
	int j=0,u; 
	DF(i,co[rc]-1,0){
		u=no[rc][i]; 
		while (j<cp[lc] && (u|np[lc][j])<k) j++;
		if ((u|np[lc][j])<k) continue;
//		cout<<u<<" "<<i<<" "<<j<<"\n";
		s[x]=(s[x]+1ll*(p[lc][j]-p[lc][cp[lc]])*(o[rc][i+1]-o[rc][i]));
	}
//	cout<<l<<" "<<r<<" "<<s[x]<<"  gg\n";
}
void build(int x,int l,int r){
	if (l==r) {
		F(i,0,20) if (a[l]>>i&1) pre[x][i]=suf[x][i]=l;
		co[x]=cp[x]=2; o[x][1]=p[x][1]=l; o[x][2]=r+1; p[x][2]=l-1; no[x][1]=np[x][1]=a[l]; o[x][0]=l; p[x][0]=l;
		if (a[l]>=k) s[x]=1;
		else s[x]=0;
		return ;
	}	
	build(lc,l,mid); 
	build(rc,mid+1,r);	
	pu(x,l,r);
}
void upd(int x,int l,int r,int p){
	if (l==r){
		ms(pre[x],0); ms(suf[x],0);
		F(i,0,20) if (a[l]>>i&1) pre[x][i]=suf[x][i]=l; no[x][1]=np[x][1]=a[l];
		if (a[l]>=k) s[x]=1;
		else s[x]=0;
		return ;
	}
	if (p<=mid) upd(lc,l,mid,p);
	else upd(rc,mid+1,r,p);
	pu(x,l,r);
}
LL qry(int x,int l,int r,int ll,int rr){
	if (l==ll && r==rr) return s[x];
	if (rr<=mid) return qry(lc,l,mid,ll,rr);
	if (ll>mid) return qry(rc,mid+1,r,ll,rr);
	int j=0,u=0; 
	LL ans=0;
	DF(i,co[rc]-1,0){
		u=no[rc][i]; 
		while (j<cp[lc] && (u|np[lc][j])<k) j++;
		if ((u|np[lc][j])<k || p[lc][j]<ll || o[rc][i]>rr) continue;
		ans=(ans+1ll*(p[lc][j]-max(p[lc][cp[lc]],ll-1))*(min(o[rc][i+1],rr+1)-o[rc][i]));
	}
	return ans+qry(lc,l,mid,ll,mid)+qry(rc,mid+1,r,mid+1,rr);
}
int n,m;
int main(){
	n=read(); m=read(); k=read();
	F(i,1,n) a[i]=read(); build(1,1,n);
	F(i,1,m){
		int x=read(),y=read(),z=read();
		if (x==1){
			a[y]=z;
			upd(1,1,n,y);
		}
		else {
			cout<<qry(1,1,n,y,z)<<"\n";
		}
//		cout<<s[3]<<"   cnm\n";
	}
    return 0;
}