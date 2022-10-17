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
const int M=3e5+10;
int n,a[M],p[M];
bool cmp(int x,int y){
	return a[x]<a[y];
}
int ct[10];
const LL inf=1e16;
int main(){
	n=read();
	LL temp=0;
	F(i,1,n){
		a[i]=read();
		p[i]=i;
		temp+=abs(a[i]);
	}
	//cout<<temp<<"\n";
	sort(p+1,p+n+1,cmp);
	LL ans=-inf,now=0;
	F(i,1,n) now+=a[i],ct[3]+=(i&1),ct[2]+=!(i&1);
	if (n%3==1) ans=now;
	F(i,1,n){
		ct[p[i]&1]++;
		now-=2*a[p[i]];
		if ((n+i)%3==1){
			if ((abs(2*i-n)<=1 && (ct[0]==ct[2] || ct[1]==ct[3]))){
				now+=2*a[p[i]];
				now-=2*a[p[i+1]];
				//cout<<"    gg \n";
				ans=max(ans,now);
				//break;
				now-=2*a[p[i]];
				now+=2*a[p[i+1]];
			}
			else ans=max(ans,now);
		}
		//cout<<now<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}