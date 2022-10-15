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
char s[101000],t[101000];
int n,m,T,a[101000],b[101000],sn,ans;
int main(){
	read(T);
	while(T--){
		read(n);cin>>s+1>>t+1;sn=1;
		F(i,1,n)a[i]=s[i]-'a'+1,b[i]=t[i]-'a'+1;
		F(i,1,n)if(a[i]>b[i])sn=0;
		if(!sn){
			cout<<"-1"<<endl;
			continue;
		}
		ans=0;
		F(i,1,26){
			sn=30;
			F(j,1,n)if(a[j]==i&&b[j]>i)sn=min(sn,b[j]);
			if(sn==30)continue;
			ans++;
			F(j,1,n)if(a[j]==i&&b[j]>i)a[j]=sn;
		}
		cout<<ans<<endl;
//		F(i,1,n)cout<<a[i]<<" ";cout<<endl;
	}
	return 0;
}