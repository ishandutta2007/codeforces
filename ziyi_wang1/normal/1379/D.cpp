#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
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
int cnt,lc[15050000],rc[15050000],w[15050000],laz[15050000];
int n,h[101000],m[101000],k,H,M,root,ans1,ans2;
vector<int>del;
#define all root,0,M-1
#define lt lc[k],l,mid
#define rt rc[k],mid+1,r
I add(int k,int v){w[k]+=v;laz[k]+=v;}
I push_down(int k){
	if(!lc[k])lc[k]=++cnt;
	if(!rc[k])rc[k]=++cnt;
	add(lc[k],laz[k]);add(rc[k],laz[k]);
	laz[k]=0;
}
I modi(int &k,int l,int r,int x,int y){
	if(x>r||y<l)return;
	if(!k)k=++cnt;
	if(x<=l&&r<=y)return add(k,1),void();
	if(laz[k])push_down(k);
	re mid=(l+r)>>1;
	modi(lt,x,y);modi(rt,x,y);
	w[k]=min(w[lc[k]],w[rc[k]]);
}
IN getit(int k,int l,int r){
//	cout<<"!"<<k<<" "<<l<<" "<<r<<" "<<w[lc[k]]<<" "<<w[rc[k]]<<endl;
	if(l==r)return l;
	if(laz[k])push_down(k);
	re mid=(l+r)>>1;
	if(w[lc[k]]<w[rc[k]])return getit(lt);
	else return getit(rt);
}
int main(){
	read(n);read(H);read(M);M>>=1;read(k);cnt=0;
	F(i,1,n){
		read(h[i]);read(m[i]);if(m[i]>=M)m[i]-=M;
		if(m[i]+k-1<M)modi(all,m[i]+1,m[i]+k-1);
//		,cout<<"!"<<m[i]+1<<" "<<m[i]+k-1<<endl;
		else{
			modi(all,m[i]+1,M-1);//cout<<"!"<<m[i]+1<<" "<<M-1<<endl;
			modi(all,0,(m[i]+k-1)%M);//cout<<"!"<<"0 "<<(m[i]+k-1)%M<<endl;
		}
	}
	if(k==1){
		cout<<"0 0"<<endl;return 0;
	}
	ans2=getit(all);ans1=0;
	F(i,1,n){
		if(m[i]+k-1<M){
			if(m[i]+1<=ans2&&ans2<=m[i]+k-1)ans1++,del.emplace_back(i);
		}
		else{
			if(m[i]<ans2||((m[i]+k-1)%M)>=ans2)ans1++,del.emplace_back(i);
		}
	}
	cout<<ans1<<" "<<ans2<<endl;
	for(auto d:del)cout<<d<<" ";
	return 0;
}