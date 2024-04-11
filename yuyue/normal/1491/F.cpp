#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
#pragma GCC optimize(2)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
int n,tt=0;
void work(){
	tt++;
	n=read();
//	if (n==6 && tt==33){
//		
//		exit(0);
//	}
	int pos=0;
	F(i,2,n){
		printf("? 1 %d\n",i-1);
		printf("%d\n",i);
		F(j,1,i-1){
			if (j^i) printf("%d ",j);
		}
		printf("\n");
		fflush(stdout);
		int tmp=read();
		if (tmp){
			pos=i;
			break;
		}
	}
	vector<int> ans;
	F(i,pos+1,n){
		printf("? 1 1\n");
		printf("%d\n%d\n",pos,i);
//		cout<<pos<<"\n"<<i<<"\n";
		fflush(stdout);
		int tmp=read();
		if (!tmp) ans.pb(i);
	}
	int l=1,r=pos-1,ta=pos;
	while (l<=r){
		int mid=(l+r>>1);
		printf("? %d 1\n",mid);
//		cout<<"? "<<mid<<" "<<1<<"\n";
		F(i,1,mid) printf("%d ",i); 
		printf("\n%d\n",pos);
		fflush(stdout);
		int tmp=0; cin>>tmp;
		if (tmp==0) l=mid+1;
		else ta=mid,r=mid-1; 
	}
	F(i,1,pos-1) if (i^ta) ans.pb(i);
	printf("! %d ",SZ(ans)+1);
	F(i,0,SZ(ans)){
		printf("%d ",ans[i]);
	}
	printf("\n");
	fflush(stdout);
}
int main(){
	int T=read();
	while (T--){
		work();
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
2
6
----NN
6
-NNNSN

*/