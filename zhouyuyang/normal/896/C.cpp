#include<bits/stdc++.h>
#define mo 1000000007
#define ll long long
#define N 100005
using namespace std;
ll a[N];
int n,m,seed,vmax;
set<int> s;
pair<ll,int> b[N];
int rnd(){
	int tmp=seed;
	seed=(1ll*seed*7+13)%mo;
	return tmp;
}
int power(int x,int y,int p){
	int s=1%p;
	for (;y;y/=2,x=1ll*x*x%p)
		if (y&1) s=1ll*s*x%p;
	return s;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&seed,&vmax);
	for (int i=1;i<=n;i++)
		a[i]=rnd()%vmax+1,s.insert(i);
	s.insert(n+1); s.insert(0);
	for (int i=1;i<=m;i++){
		int op=rnd()%4+1;
		int l=rnd()%n+1;
		int r=rnd()%n+1;
		if (l>r) swap(l,r);
		int x,y;
		set<int>::iterator it;
		if (op==3)
			x=rnd()%(r-l+1)+1;
		else x=rnd()%vmax+1;
		if (op==4) y=rnd()%vmax+1;
		if (op==1){
			it=--s.upper_bound(r);
			ll lav2=a[*it];
			it=--s.upper_bound(l);
			ll lav1=a[*it];
			if (*it!=l) s.insert(l);
			a[l]=lav1+x;
			it=s.upper_bound(r);
			if (*it!=r+1) s.insert(r+1),a[r+1]=lav2;
			it=s.upper_bound(l);
			for (;*it<=r;a[*it++]+=x);
		}
		else if (op==2){
			it=--s.upper_bound(r);
			ll lav2=a[*it];
			it=--s.upper_bound(l);
			if (*it!=l) s.insert(l);
			a[l]=x;
			it=s.upper_bound(r);
			if (*it!=r+1) s.insert(r+1),a[r+1]=lav2;
			it=s.upper_bound(l);
			for (;*it<=r;){
				a[*it]=x;
				s.erase(it);
				it=s.upper_bound(l);
			}
		}
		else{
			it=--s.upper_bound(l);
			int top=1;
			b[1].second=l;
			b[1].first=a[*it];
			for (it++;*it<=r;it++){
				b[++top].second=*it;
				b[top].first=a[*it];
			}
			int lav=r+1;
			for (int i=top;i;i--){
				int tmp=b[i].second;
				b[i].second=lav-b[i].second;
				lav=tmp;
			}
			if (op==3){
				sort(b+1,b+top+1);
				for (int i=1;i<=top;i++)
					if (x<=b[i].second){
						printf("%I64d\n",b[i].first);
						break;
					}
					else x-=b[i].second;
			}
			else{
				int ans=0;
				for (int i=1;i<=top;i++)
					ans=(ans+1ll*power(b[i].first%y,x,y)*b[i].second%y)%y;
				printf("%d\n",ans);
			}
		}
	}
}