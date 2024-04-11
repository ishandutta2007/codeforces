#include<bits/stdc++.h>
using namespace std;

int n,m,x,now,t,p[20],ans=1;
vector<int>v;
bool P(int x){
	for (t=1;;) if (x%++t==0) return x==t;
}
int main(){
	for (int i=2;i<70;i++) if (P(i)) p[n++]=i;
	for (cin>>n,m=n;n--;){
		scanf("%d",&x), now=0;
		for (int i=0;i<19;i++){
			for (t=0;x%p[i]==0;x/=p[i]) t^=1;
			now|=t<<i;
		}
		for (auto o:v) now=min(now,now^o);
		if (now) v.push_back(now);
	}
	for (int i=m-v.size();i--;) ans=ans*2%1000000007;
	cout<<ans-1;
}