#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=4e5+10;
#define pii pair<int,int> 
#define mp make_pair
vector<pii> ans;
int tot;
map<pii,int> p;
int n,lim,bg,a[M];
void make(int x){
	F(i,1,x){
		int len=(1<<i-1);
		for (int k=bg;k<bg+(1<<x);k+=(1<<i))
		for (int j=1;j<=len;j++){
			ans.pb(mp(k+j,k+len+j));
		}
	}
}
int main(){
	n=read(); int pos=0; 
	DF(i,30,0){
		if (n>>i&1){
			lim=(1<<i);
			pos=i;
			break;
		}
	}
	int p2=-1;
	DF(i,pos-1,0){
		if (n>>i&1){
			p2=i;
			break;
		}
	}
	if (p2!=-1){
		bg=1;
		DF(i,p2-1,0){
			make(p2-i+1);
			F(j,1,bg){
				ans.pb(mp(j,j+bg));
			}
			bg*=2;
			if (n>>i&1){	
				make(p2-i+1);
				F(j,1,bg){
					ans.pb(mp(j,j+bg));
				}
				bg++;
			}
//			else {
				
//			}
		}
//		cout<<bg<<"\n";
	}
//	return 0;
	make(pos);
	cout<<SZ(ans)+1<<"\n";
//	F(i,1,n) a[i]=i; tot=n;
	F(i,0,SZ(ans)){
		int x=ans[i].first,y=ans[i].second;
		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
//		if (!p[mp(a[x],a[y])]) p[mp(a[x],a[y])]=++tot;
//		a[x]=a[y]=tot;
	}
//	int tt=0; 
//	F(i,1,n-1) tt+=(a[i]!=a[i+1]);
//	cout<<tt<<"\n";  
	return 0;
}