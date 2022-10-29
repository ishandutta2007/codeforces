#include<bits/stdc++.h>
using namespace std;
bitset<100100>bs[30],ans,rt;
char b[100100],a[100100];
int n,m,k;
int main(){
	scanf("%s",a);
	n=strlen(a);
	for(int i=0;i<n;++i)bs[a[i]-'a'][i]=1,rt[i]=1;
	scanf("%d",&m);
	for(int i=1,l,r,op;i<=m;++i){
		scanf("%d",&op);
		if(op==2){
			ans=rt;
			scanf("%d%d%s",&l,&r,b);
			k=strlen(b);
			l--,r--;
			r=r-k+1;
			if(r<l){
				puts("0");
				continue;
			}
			for(int i=0;i<k;++i)ans&=bs[b[i]-'a']>>(i);
			ans>>=l;
			int sum=ans.count();
			ans>>=r-l+1;
			sum-=ans.count();
			printf("%d\n",sum);
		} else {
			scanf("%d%s",&l,b+1);
			l--;
			bs[a[l]-'a'][l]=0;
			a[l]=b[1];
			bs[a[l]-'a'][l]=1;
		}
	}
}