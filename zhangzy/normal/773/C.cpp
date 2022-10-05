#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,a,pos,b[233],c[233],d[233],las;

int C(ll x){
	int t=0;
	for (;x>1;x>>=1) t++;
	return t;
}
int check(ll x){
	return (x==(x&-x));
}

bool pd(){
	int t=0;
	for (int i=44;i>0;i--){
		t-=d[i];
		t+=c[i]+b[i];
		if (t>0) return 0;
	}
	return 1;
}

ll x;

int main(){
	cin>>n;
	int t;
	for (int i=1;i<=n;i++){
		cin>>x;
		if (x==1){
			a++;
		}else if (check(x)){
			b[C(x)]++;
		}else{
			c[C(x)]++;
		}
	}
	las=n;
	for (int i=1;i<=a;i++){
		las--;
		for (pos=0;b[pos+1];) pos++,b[pos]--,las--;
		d[pos]++;
		if (las<=i&&pd()){
			for (int j=i;j<=a;j++) printf("%d ",j);
			return 0;
		}
	}
	printf("-1");
}