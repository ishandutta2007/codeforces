#include<bits/stdc++.h>
using namespace std;

double x[100000],y[100000];
int n,cnt;

bool possible(double radius){
	double L=-1e100,R=1e100;
	for(int i=0;i<n;i++){
		if(abs(y[i]-radius)>radius)	return false;
		L=max(L,x[i]-sqrt(2*radius*y[i]-y[i]*y[i]));
		R=min(R,x[i]+sqrt(2*radius*y[i]-y[i]*y[i]));
	}
	return L<=R;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		if(y[i]>0)	cnt++;
	}
	if(cnt!=n&&cnt!=0){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)
		y[i]=abs(y[i]);
	double l=0,r=1e14;
	for(int it=0;it<200;it++){
		double mid=(l+r)/2;
		if(possible(mid))
			r=mid;
		else
			l=mid;
	}
	cout<<fixed<<setprecision(10)<<l<<endl;
}