#include<bits/stdc++.h>
#define db double
#define eps (1e-6)
using namespace std;
int n;
db r,x,pos[1010],ans[1010],mx;

int main(){
	cin>>n>>r;
	for (int i=1;i<=n;++i){
		cin>>x; pos[i]=x; mx=r;
		for (int j=1;j<i;++j){
			if (abs(x-pos[j])<=2*r+eps){
				mx=max(mx,ans[j]+sqrt(abs(pow(2*r,2)-pow(x-pos[j],2))));
			}
		}
		printf("%.10lf ",ans[i]=mx);
	}
}