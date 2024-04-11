#include<bits/stdc++.h>
#define ll long long 
#define db long double
using namespace std;

ll t,x,y,p,q,ans;
db aim;

bool check(ll e){
	if (e<0) return 0;
	return (db)x*q<=0.5+(db)(y+e)*p&&(db)p*(y+e)<=0.5+(db)q*(x+e);
}

int main(){
	for (cin>>t;t--;){
		cin>>x>>y>>p>>q;
		if (p==q){
			if (x==y) puts("0");
			else puts("-1");
			continue;
		}
		if (p==0){
			if (x==0) puts("0");
			else puts("-1");
			continue;
		}
		aim=max( ((db)x*q-p*y)/(db)p , ((db)p*y-x*q)/(db)(q-p) );
		ans=aim-0.5; ans=(y+ans+q-1)/q*q-y;
		while (!check(ans)) ans+=q;
		printf("%lld\n",ans);
	}
}