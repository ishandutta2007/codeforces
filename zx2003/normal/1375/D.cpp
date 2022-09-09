#include<bits/stdc++.h>
const int N=1005;
int T,n,a[N],i,j,k,b[N];
std::vector<int>ans;
inline int mex(){int j=0;for(;b[j];++j);return j;}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);memset(b,0,n+1<<2);ans.clear();
		for(i=1;i<=n;++i)scanf("%d",a+i),++b[a[i]];
		for(;;){
			j=mex();if(j==n)break;
			--b[a[j+1]];ans.push_back(j+1);a[j+1]=j;++b[j];
		}
		for(i=1;i<=n;++i)if(a[i]>i-1){
			for(j=i;j<=n;++j)if(a[j]==i-1){a[j]=n;ans.push_back(j);break;}
			for(j=i;;){
				int t=a[j];
				ans.push_back(j);a[j]=j-1;j=t+1;if(t==n)break;
			}
		}
		printf("%d\n",(int)ans.size());for(int x:ans)printf("%d ",x);puts("");
	}
}