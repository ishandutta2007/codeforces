#include<iostream>
using namespace std;
#define ll long long
ll ans;
int a[400010];
inline bool pd(int x,int d){
	return x&(1<<d);
}
int sort(int L,int R,int d){
	int l=L,r=R;
	while(l<r){
		while(l<r&&!pd(a[l],d))l++;
		while(l<r&&pd(a[r],d))r--;
		swap(a[l],a[r]);l++,r--;
	}
	int m=L-1;
	while(m<R&&!pd(a[m+1],d))m++;
	return m;
}
inline bool pd2(int x,int d){
	return bool(x&(1<<d))^bool(x&(1<<(d+1)));
}
int sort2(int L,int R,int d){
	int l=L,r=R;
	while(l<r){
		while(l<r&&!pd2(a[l],d))l++;
		while(l<r&&pd2(a[r],d))r--;
		swap(a[l],a[r]);l++,r--;
	}
	int m=L-1;
	while(m<R&&!pd2(a[m+1],d))m++;
	return m;
}
void work(int l,int r,int d){
	// cout<<"work:"<<l<<" "<<r<<" "<<d<<" "<<a[l]<<" "<<a[r]<<endl;
	if(l>=r) return;
	int m=sort(l,r,d);
	ll cnt=1ll*(m-l+1)*(r-m);
	// cout<<"m:"<<m<<endl;
	if(cnt==0) return;
	if(cnt%2){
		ans^=1<<(d+1);
		// cout<<"add"<<l<<" "<<r<<" "<<d<<endl;
	}
	int m2=sort2(l,r,d);
	work(l,m2,d+1);
	work(m2+1,r,d+1);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(n%2==0)ans^=a[i];
	}
	for(int i=0;i<24;i++){
		// cout<<"in"<<endl;
		int m=sort(1,n,i);
		if(1ll*(n-m)*(n-m-1)/2%2){
			ans^=1<<(i+1);
			// cout<<"add"<<i<<endl;
		}
		work(m+1,n,i+1);
		// cout<<"out"<<endl;
	}
	cout<<ans<<endl;
}