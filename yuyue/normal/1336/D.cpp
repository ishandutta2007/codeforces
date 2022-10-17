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
int nowa,nowb;
const int M=1e5+10;
int re[M],a[M],b[M],n,ad[M],ans[M];
void ask(int x,int &dela,int &delb){
	cout<<"+ "<<x<<endl;
	ad[x]++;
	int na,nb; cin>>na>>nb;
	dela=na-nowa; delb=nb-nowb;
	nowa=na; nowb=nb;
}

int main(){
	cin>>n>>nowa>>nowb;
	F(i,0,n) re[i*(i-1)/2]=i;
	DF(i,n-1,3){
		ask(i,a[i],b[i]);
	}
	int a23,d1,d2,d3;
	ask(1,d1,a23);
	
	ask(2,d3,b[2]);
	if (!a23) ans[2]=0;
	else if (!d3) ans[2]=1;
	else ans[2]=re[d3];
	
	ask(1,d2,b[1]);
	ans[1]=d2-d1;
	F(i,3,n){
		int mul=b[i-2];
//		cout<<mul<<"  ?? \n";
		if (i-2>1) mul-=(ans[i-1]+1)*ans[i-3];
		if (i==4) mul-=(ans[i-1]+1);
		if (i-2>2) mul-=ans[i-4]*ans[i-3];
		
		ans[i]=mul/(ans[i-1]+1)-1;
		if (i==n) ans[i]++;
	}
//	ask(n-1,d1,a23);
//	a23-=(ans[n-2]+ad[n-2])*(ans[n-3]+ad[n-3]);
//	ans[n]=a23/(ans[n-2]+ad[n-2]);
	cout<<"! ";
	F(i,1,n) cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
5 1 6
4 8
5 12
5 24
8 32
8 48
*/