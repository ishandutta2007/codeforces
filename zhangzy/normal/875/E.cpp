#include<bits/stdc++.h>
using namespace std;

int n,a[101000],l,r,now;
int st,en,fl=0;

bool check(){
	fl=0;
	for (int i=n-1;i>0;i--){
		if (!fl){
			if (abs(a[i]-a[i+1])<=now){
				continue;
			}
			if (abs(a[i]-a[i+1])<=now*2){
				fl=1;
				st=max(a[i]-now,a[i+1]-now);
				en=min(a[i]+now,a[i+1]+now);
			}else{
				return 0;
			}
		}else{
			if (a[i]>=st&&a[i]<=en){
				fl=0;
			}else{
				st=max(st,a[i]-now);
				en=min(en,a[i]+now);
				if (st>en) return 0;
			}
		}
	}
	return !fl;
}

int main(){
	scanf("%d",&n); n+=2;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (l=abs(a[1]-a[2]),r=1e9;l<r;check()?r=now:l=now+1) now=l+r>>1;
	cout<<l;
}