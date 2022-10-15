#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
int n,sum,lst;
inline int query(int c){
	if(!c)return 0;
	if(c==n)return 1;
	sum+=c;
	cout<<"+ "<<c<<endl;
	int x=read();swap(lst,x);
	return lst-x;
}
int main(){
	n=read();
	int l=1,r=n-1,pre=0;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(query(!pre?r-mid+1:n-(mid-l)))l=mid,pre=1;
		else r=mid-1,pre=0;
	}
	printf("! %d\n",r+sum);
	return 0;
}