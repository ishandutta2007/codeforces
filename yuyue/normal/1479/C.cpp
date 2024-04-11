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
const int M=1e5+10;
int tot=32,L,R,n,m;
int r[M][2];
int nn(){
	return --tot;
}
struct edge{
	int x,y,z;
};
vector<edge> ans;
void out(int x,int y,int z){
//	assert(x<y);
	ans.pb((edge){x,y,z});
}
int main(){
	L=read(); R=read();
	n=32;
	F(i,0,19){
		int id=nn();
		r[i][0]=id;
		if (i==0){
			out(id,n,1);
//			cout<<id<<" "<<n<<" "<<1<<"\n";
		}
		else{
			if (i&1){
				if (i==1){
					out(id,r[0][0],1);
					out(id,n,1);
					r[i][1]=nn();
					out(r[i][1],r[0][0],1);
				}
				else{
					r[i][1]=nn();
					out(id,r[i-2][0],1);
					out(id,r[i-2][1],(1<<i-2));
					out(id,r[i-1][0],(1<<i-1));
					out(id,n,1);
//					cout<<id<<" "<<r[i-2][0]<<" "<<1<<"\n";
//					cout<<id<<" "<<r[i-2][1]<<" "<<(1<<i-2)-1<<"\n";
//					cout<<id<<" "<<r[i-1][0]<<" "<<(1<<i-1)<<"\n";
//					cout<<id<<" "<<n<<" "<<1<<"\n";
					out(r[i][1],r[i-2][0],1);
					out(r[i][1],r[i-2][1],(1<<i-2));
					out(r[i][1],r[i-1][0],(1<<i-1));
//					cout<<r[i][1]<<" "<<r[i-2][0]<<" "<<1<<"\n";
//					cout<<r[i][1]<<" "<<r[i-2][1]<<" "<<(1<<i-2)-1<<"\n";
//					cout<<r[i][1]<<" "<<r[i-1][0]<<" "<<(1<<i-1)<<"\n";
				}
			}
			else{
				out(r[i][0],r[i-1][0],1);
				out(r[i][0],r[i-1][1],(1<<i-1));
				out(r[i][0],n,1);
//				cout<<r[i][0]<<" "<<r[i-1][0]<<" "<<1<<"\n";
//				cout<<r[i][0]<<" "<<r[i-1][1]<<" "<<(1<<i-1)-1<<"\n";
//				cout<<r[i][0]<<" "<<n<<" "<<1<<"\n";//
			}
		}
	}
//	cout<<"\n";
	int pos=1;
	out(pos,n,L);
//	cout<<pos<<" "<<n<<" "<<1<<"\n";
	int lp=L+1,rp=R;
	DF(i,20,0){
		if (lp+(1<<i)-1<=rp){
			out(pos,r[i][0],lp-1);
			lp+=(1<<i);
//			cout<<pos<<" "<<r[i][0]<<" "<<lp-1<<"\n";
		}
	}
	cout<<"YES\n";
	cout<<n<<" "<<SZ(ans)+1<<"\n";
	F(i,0,SZ(ans)){ 
		cout<<ans[i].x<<" "<<ans[i].y<<" "<<ans[i].z<<"\n";
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/