#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n;
double f,l;
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		double a;scanf("%lf",&a);
		f+=(2*l+1)*a,l=(l+1)*a;
	}
	printf("%.15lf\n",f);
	return 0;
}