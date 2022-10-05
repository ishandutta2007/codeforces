#include<bits/stdc++.h>
#define F for(int i=1;i<=n;++i)
int64_t x,n,a[555],R,p[555]={1},M=1e9+7;main(){std::cin>>n;F p[i]=p[i-1]*2%M,std::cin>>x,~x?a[x]++:0;R=p[n-1]-1;F R-=p[a[i]]-1;std::cout<<(R%M+M)%M;}