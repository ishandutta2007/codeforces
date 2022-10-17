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
const int M=5e5+10;
int n,m,a[M],b[M];
#define mp make_pair
#define pii pair<LL,int>
int main(){
    n=read(); m=read();
    F(i,1,n) a[i]=read();
    F(i,1,n) b[i]=read();
    LL l=0,r=2e9;
    LL ans=0;
    while (l<=r){
        LL mid=(l+r>>1);
        priority_queue<pii,vector<pii>,greater<pii> > q;
        int cnt=0;
        LL ta=0;
        F(i,1,n){
            q.push(mp(a[i],1));
            if (q.top().first+b[i]-mid<=0){
                cnt+=q.top().second;
                ta+=b[i]+q.top().first-mid;
                q.pop();
                q.push(mp(mid-b[i],0));
            }
        }
//        cerr<<mid<<" "<<cnt<<"\n";
        if (cnt>=m) ans=ta+mid*cnt,r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<"\n";
	return 0;
}
/*

*/