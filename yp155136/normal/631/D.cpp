#include <iostream>
#include <stdio.h>
#include <utility>
using namespace std;

#define int long long
typedef long long LL;
typedef pair<LL,LL> pii;
const int MAX_N = 2e5 + 6;
const int MAX_P = 1;
const int MAX_M = 31;
const LL mod[MAX_P] = { 1000000007 } ;

LL pow(LL a,LL n,LL mod) {
    //cout<<"a = "<<a<<" , n = "<<n<<endl;
	if (n==0) return 1;
	else if (n==1) return a;
	LL ret=pow(a,n/2,mod);
	ret *= ret;
	ret %= mod;
	if (n%2==1) ret *= a;
	return ret%mod;
}

LL ff(LL i) {
    return i*i-i+1;
}

LL f(LL c,LL t,int i,LL m) {
	return ((c*c*ff(c)+t)%mod[i])*pow(MAX_M,m,mod[i])%mod[i];
}

pii a[MAX_N];
LL pre[MAX_P][MAX_N];
pii q[MAX_N];

main () {
	int n,m;
	while (scanf("%I64d %I64d",&n,&m) != EOF) {
		int id=1;
		a[0]=make_pair(0,0);
		for (int x=1;n>=x;x++) {
			int l;
			char c;
			scanf("%I64d-%c",&l,&c);
			if (c==a[id-1].first) {
				a[id-1].second += l;
			}
			else {
				a[id++] = make_pair(c,l);
			}
		}
		int sz=0;
		for (int x=1;m>=x;x++) {
			int l;
			char c;
			scanf("%I64d-%c",&l,&c);
			if (sz == 0) {
				q[sz++] = make_pair(c,l);
			}
			else if (c==q[sz-1].first) {
				q[sz-1].second += l;
			}
			else {
				q[sz++] = make_pair(c,l);
			}
		}
		//cout<<"sz = "<<sz<<" , id = "<<id<<endl;
		if (sz == 1) {
			LL ans=0;
			for (int i=1;id>i;i++) {
				if (a[i].first==q[0].first&&a[i].second>=q[0].second) {
					ans += (a[i].second - q[0].second + 1);
				}
			}
			printf("%I64d\n",ans);
		}
		else {
            //build prefix
            for (int i=1;id>i;i++) {
                for (int j=0;MAX_P>j;j++) {
                    //if (!j) cout<<"hash["<<j<<"]["<<i<<"] = "<<LL(f(a[i].first,a[i].second,j,i) )<<endl;
                    pre[j][i] = pre[j][i-1] + f(a[i].first,a[i].second,j,i);
                    pre[j][i] %= mod[j];
                }
                //cout<<"i = "<<i<<" , pre = "<<pre[0][i]<<endl;
            }
            //get ans
            LL ans[MAX_P];
            for (int x=0;MAX_P>x;x++) {
                ans[x] = 0;
            }
            for (int i=1;sz-1>i;i++) {
                for (int j=0;MAX_P>j;j++) {
                    //if (!j) cout<<"hash[0]["<<i<<"] = "<<f(q[i].first,q[i].second,j,i)*31%mod[j]<<endl;
                    ans[j] += f(q[i].first,q[i].second,j,i);
                    ans[j] %= mod[j];
                }
            }
            LL cnt=0;
            //get all the segments
            //segment i-1 ~ i
            for (int i=2;id>i;i++) {
                if (i-1 + sz - 1 >= id) break;
                //okay range
                #define S second
                #define F first
                //cout<<"i = "<<i<<" , sz = "<<sz<<" ans = "<<ans<<" , pre = "<<pre[i+sz-3] - pre[i-1]<<endl;
                if (q[0].F==a[i-1].F&&q[0].S<=a[i-1].S&&q[sz-1].F==a[i+sz-2].F&&q[sz-1].S<=a[i+sz-2].S) {
                    bool check=true;
                    for (int j=0;MAX_P>j;j++) {
                        if ((pre[j][i+sz-3]-pre[j][i-1]+mod[j])%mod[j]!=(ans[j]*pow(MAX_M,i-1,mod[j]))%mod[j]) check=false;
                    }
                    /*if (!check) {
                        cout<<"i = "<<i<<endl;
                        cout<<"pre = "<<(pre[0][i+sz-3]-pre[0][i-1]+mod[0])%mod[0]<<endl;
                        cout<<"ans = "<<(ans[0]*pow(MAX_P,i-1,mod[0]))%mod[0]<<endl;
                    }*/
                    cnt += check;
                }
            }
            printf("%I64d\n",cnt);
		}
	}
}