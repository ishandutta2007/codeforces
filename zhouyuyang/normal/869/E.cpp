#include<bits/stdc++.h>
#define mk make_pair
#define ull unsigned long long
using namespace std;
map<pair<pair<int,int>,pair<int,int> >,pair<ull,ull> > mp;
pair<ull,ull> t[2505][2505];
int n,m,q;
ull rnd(){
	ull x=0;
	for (int i=1;i<=10;i++)
		x=x*23333+rand();
	return x;
}
void add(int x,int y,pair<ull,ull> v){
	for (int i=x;i<=n;i+=i&(-i))
		for (int j=y;j<=m;j+=j&(-j))
			t[i][j].first+=v.first,
			t[i][j].second+=v.second;
}
pair<ull,ull> ask(int x,int y){
	pair<ull,ull> s;
	for (int i=x;i;i-=i&(-i))
		for (int j=y;j;j-=y&(-j))
			s.first+=t[i][j].first,
			s.second+=t[i][j].second;
	return s;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	srand(time(NULL));
	while (q--){
		int fl,x,y,X,Y;
		scanf("%d%d%d%d%d",&fl,&x,&y,&X,&Y);
		pair<ull,ull> a,b;
		if (fl==1){
			a.first=rnd(); a.second=rnd();
			b=mk(-a.first,-a.second);
			mp[mk(mk(x,y),mk(X,Y))]=a;
			add(x,y,a); add(X+1,Y+1,a);
			add(x,Y+1,b); add(X+1,y,b);
		}
		else if (fl==2){
			a=mp[mk(mk(x,y),mk(X,Y))];
			b=mk(-a.first,-a.second);
			add(x,y,b); add(X+1,Y+1,b);
			add(x,Y+1,a); add(X+1,y,a);
		}
		else{
			a=ask(x,y); b=ask(X,Y);
			puts(a==b?"Yes":"No");
		}
	}
}