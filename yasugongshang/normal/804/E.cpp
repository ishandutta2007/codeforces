#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int,int>
#define mp make_pair
inline ll read(){
	bool pos=1; ll x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')pos=0;
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	return pos?x:-x;
}
void write(ll x){
	if(x<0){
		x=-x; putchar('-');
	}
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
void writeln(ll x){
	write(x); puts("");
}
vector<PI > y44,y4,y5,y45,ans;
void huan(int l1,int r1,int l2,int r2){
	for(unsigned i=0;i<y44.size();i++){
		ans.push_back(mp(y44[i].first+l1,y44[i].second-4+l2));
	}
}
void alb(int l1,int r1,int l2,int r2){
	for(unsigned i=0;i<y45.size();i++){
		ans.push_back(mp(y45[i].first+l1,y45[i].second-5+l2));
	}
}
void bao(int l,int r){
	for(unsigned i=0;i<y4.size();i++)ans.push_back(mp(y4[i].first+l,y4[i].second+l));
}
void solve(int n){
	if(n==4){
		for(unsigned i=0;i<y4.size();i++)ans.push_back(y4[i]);
		return;
	}else if(n==5){
		for(unsigned i=0;i<y5.size();i++)ans.push_back(y5[i]);
		return;
	}
	if(n%4==0)for(int i=4;i<n;i+=4)huan(i-4,i,n-4,n);
	else for(int i=5;i<n;i+=4)if(i==5)alb(i-5,i,n-4,n); else huan(i-4,i,n-4,n);
}
void GG(){
	puts("NO"); exit(0);
}
int main(){
	y44.push_back(mp(4,7));
	y44.push_back(mp(1,5));
	y44.push_back(mp(3,7));
	y44.push_back(mp(1,8));
	y44.push_back(mp(2,5));
	y44.push_back(mp(3,5));
	y44.push_back(mp(4,6));
	y44.push_back(mp(1,6));
	y44.push_back(mp(4,8));
	y44.push_back(mp(2,7));
	y44.push_back(mp(1,7));
	y44.push_back(mp(2,8));
	y44.push_back(mp(3,6));
	y44.push_back(mp(2,6));
	y44.push_back(mp(3,8));
	y44.push_back(mp(4,5));
	y4.push_back(mp(2,3));
	y4.push_back(mp(3,4));
	y4.push_back(mp(1,2));
	y4.push_back(mp(1,3));
	y4.push_back(mp(2,4));
	y4.push_back(mp(1,4));
	y5.push_back(mp(1,2));
	y5.push_back(mp(2,5));
	y5.push_back(mp(1,4));
	y5.push_back(mp(1,3));
	y5.push_back(mp(3,4));
	y5.push_back(mp(2,4));
	y5.push_back(mp(2,3));
	y5.push_back(mp(1,5));
	y5.push_back(mp(3,5));
	y5.push_back(mp(4,5));
	y45.push_back(mp(4,9));
	y45.push_back(mp(1,6));
	y45.push_back(mp(1,9));
	y45.push_back(mp(4,6));
	y45.push_back(mp(3,6));
	y45.push_back(mp(5,9));
	y45.push_back(mp(2,6));
	y45.push_back(mp(1,7));
	y45.push_back(mp(2,9));
	y45.push_back(mp(3,8));
	y45.push_back(mp(4,8));
	y45.push_back(mp(4,7));
	y45.push_back(mp(1,8));
	y45.push_back(mp(5,6));
	y45.push_back(mp(3,7));
	y45.push_back(mp(2,7));
	y45.push_back(mp(5,8));
	y45.push_back(mp(3,9));
	y45.push_back(mp(5,7));
	y45.push_back(mp(2,8));
	int n=read();
	if(n%4>1){
		GG();
	}
	puts("YES");
	if(n==1)return 0;
	//for(int i=1;i<=n;i++)a[i]=i;
	for(int i=4+n%4;i<=n;i+=4){if(i>5)bao(i-4,i); solve(i); }
	//for(int i=1;i<=n;i++)a[i]=i;
	for(unsigned i=0;i<ans.size();i++){
		//swap(a[ans[i].first],a[ans[i].second]);
		write(ans[i].first); putchar(' '); writeln(ans[i].second);
	}
	//cout<<ans.size()<<" "<<y44.size()<<" "<<y4.size()<<endl;
	//for(int i=1;i<=n;i++)if(a[i]!=i)puts("GG");
}