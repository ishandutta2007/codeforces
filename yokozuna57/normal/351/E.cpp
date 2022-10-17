#include<iostream>
#include<vector>
using namespace std;

int z(int x){
	if(x<0)return -x;
	return x;
}

int main(){
	int n,a[2002],ans=0,p,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){int in; scanf("%d",&in); a[i]=z(in);}
	for(int i=0;i<n;i++){
		p=0; m=0;
		for(int j=0;j<n;j++){
			if(a[i]>a[j]){
				if(i<j)p++;
				else m++;
			}
		}
		//cout<<p<<" "<<m<<endl;
		ans+=min(p,m);
	}
	printf("%d\n",ans);
}