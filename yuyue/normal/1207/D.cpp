#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int mod=998244353,M=3e5+10;
struct node{
	int x,y;
}a[M];
bool cmp1(node A,node B){
	return A.x<B.x;
}
bool cmp2(node A,node B){
	return A.y<B.y;
}
LL ans,f[M];
int n;
map<int,int> mp[M]; 
int main(){
	n=read(); 
	f[0]=1; 
	F(i,1,n) f[i]=f[i-1]*i%mod;
	F(i,1,n){
		a[i].x=read(); a[i].y=read();
	}
	sort(a+1,a+n+1,cmp1);
	int len=0,lst=0;
	LL tmp=1,tp=1; bool flag=0;
	F(i,1,n){
		len++;
		mp[a[i].x][a[i].y]++;
		if (a[i].x!=a[i+1].x){
			tmp*=f[len]; tmp%=mod; len=0;
			if (lst) {
//				cout<<mp[a[i].x].begin()->first<<" "<<(--mp[a[lst].x].end())->first<<"    HH\n";
				if (mp[a[i].x].begin()->first < (--mp[a[lst].x].end())->first) flag=1;
				else {
					map<int,int> :: iterator it;
					for (it=mp[a[i].x].begin();it!=mp[a[i].x].end();it++){
						tp*=f[it->second];
						tp%=mod;
					}
				}
			}	
			lst=i;

		}
	}
//	cout<<tmp<<" "
//	cout<<flag<<"\n";
	ans=tmp;
	if (!flag){
		map<int,int> :: iterator it;
		for (it=mp[a[1].x].begin();it!=mp[a[1].x].end();it++){
			tp*=f[it->second];
			tp%=mod;
		}
		ans=(ans-tp+mod)%mod;
	}
	sort(a+1,a+n+1,cmp2);
	len=0;
	tmp=1;
	F(i,1,n){
		len++;
		if (a[i].y!=a[i+1].y){
			tmp*=f[len]; tmp%=mod;
			len=0;
		}
	}
	cout<<(f[n]-(ans+tmp)%mod+mod)%mod<<"\n";
	return 0;
}