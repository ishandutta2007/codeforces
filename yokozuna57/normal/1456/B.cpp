#include <bits/stdc++.h>
using namespace std;

const int INF=1000000000;

int n;
int a[100010];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	
	for(int i=0;i+2<n;i++){
		if((a[i]^a[i+1])>a[i+2]||a[i]>(a[i+1]^a[i+2])){
			puts("1");
			//cout<<i<<" "<<(a[i]^a[i+1])<<" "<<a[i+2]<<" "<<a[i]<<" "<<(a[i+1]^a[i+2])<<endl;
			return 0;
		}
	}
	int ret=INF;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				int x=0,y=0;
				for(int t=i;t<j;t++)x^=a[t];
				for(int t=j;t<k;t++)y^=a[t];
				if(x>y)ret=min(ret,k-i-2);
			}
		}
	}
	if(ret==INF)puts("-1");
	else cout<<ret<<endl;
}