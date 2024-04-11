#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10;
vector<LL> p;
set<LL> t; 
LL a[M];
int n;
bool used[M];
int Rd(){
	int ret=0;
	for (int i=0;i<=21;i+=3) ret|=(rand()&7)<<i;
	return ret%n+1;
}
LL ans=1e18;
void calc(LL x){
	LL tmp=0;
	F(i,1,n)  {
		LL o=a[i]%x;
		if (o){
			if (a[i]==o) tmp+=x-o;
			else  tmp+=min(o,x-o);
		}
//		cout<<tmp<<"  op\n";
	}
//	cout<<x<<" "<<tmp<<"   o\n";
	ans=min(ans,tmp);
}
void doit(LL x){
	for (LL i=2;i*i<=x;i++){
		if (x%i==0) {
			while (x%i==0) x/=i;
			if (t.insert(i).second) {
				calc(i);
			} 
		}
	}
	if (x>1) if (t.insert(x).second) calc(x);
}
void Rdps(){
	int pos=Rd(); 
	while (used[pos]) pos=Rd();
	doit(a[pos]); doit(a[pos]-1); doit(a[pos]+1);
	used[pos]=1;
}
int main(){	
	n=read(); srand(time(0));
//	cout<<Rd()<<"\n";
	F(i,1,n) a[i]=read(); calc(2); t.insert(2);
	random_shuffle(a+1,a+n+1);
	int tms=min(30,n/2+1);
	while (tms--) Rdps();
	cout<<ans<<"\n";
	return 0;
}