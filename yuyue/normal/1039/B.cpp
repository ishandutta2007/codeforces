#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
bool qry(LL x,LL y){
	cout<<x<<" "<<y<<endl;
	string O; cin>>O;
	return O=="Yes";
}
int main(){
	LL n,k; cin>>n>>k;
	LL l=1,r=n; srand(time(0));
	while (l<=r){
		if (r-l<=50){
			LL o=rand()%(r-l+1)+l;
			bool ret=qry(o,o);
			if (ret) exit(0);
			else l=max(1ll,l-k),r=min(r+k,n);
		}
		else{
			LL mid=(l+r>>1);
			if (qry(l,mid)){
				l=max(1ll,l-k);
				r=min(mid+k,n);
			}
			else{
				l=max(1ll,mid+1-k);
				r=min(r+k,n);
			}
		}
	}
    return 0;
}