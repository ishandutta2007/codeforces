#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f,T,t0,a1,t1,p1,a2,t2,p2,i,a,b,c,ans;
int main(){
	cin>>f>>T>>t0>>a1>>t1>>p1>>a2>>t2>>p2;
	if(min(min(t0,t1),t2)*f>T)return puts("-1"),0;
	if(t0*f<=T)return puts("0"),0;
	if(t1>=t0 || t2>=t0){
		if(t1>=t0)a1=a2,t1=t2,p1=p2;
		cout<<((f*t0-T-1)/(a1*t0-a1*t1)+1)*p1<<endl;
		return 0;
	}
	ans=1ll<<60;
	if(f*t1<=T)ans=((f-1)/a1+1)*p1;
	for(i=0;a1*i<=f;++i){
		a=f-a1*i;//result of f
		b=T-a1*t1*i;//result of T
		if(a*t2<=b){
			if(a*t0<=b)ans=min(ans,i*p1);
				else ans=min(ans,((a*t0-b-1)/(a2*t0-a2*t2)+1)*p2+i*p1);
		}
	}
	swap(a1,a2),swap(t1,t2),swap(p1,p2);
	if(f*t1<=T)ans=min(ans,((f-1)/a1+1)*p1);
	for(i=0;a1*i<=f;++i){
		a=f-a1*i;//result of f
		b=T-a1*t1*i;//result of T
		if(a*t2<=b){
			if(a*t0<=b)ans=min(ans,i*p1);
				else ans=min(ans,((a*t0-b-1)/(a2*t0-a2*t2)+1)*p2+i*p1);
		}
	}
	return cout<<ans<<endl,0;
}