#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define I inline void
#define IN inline int
int n,m,a[101000],b[101000],pos[101000],tr[101000];
IN lbt(int x){
	return x&(-x);
}
I modi(int x){
	while(x<=n){
		tr[x]++;
		x+=lbt(x);
	}
}
IN ques(int x){
	re res=0;
	while(x){
		res+=tr[x];
		x-=lbt(x);
	}
	return res;
}
int main(){
	cin>>n;
	F(i,1,n){
		cin>>a[i];
		pos[a[i]]=i;
	}
	F(i,1,n){
		cin>>b[i];
		b[i]=pos[b[i]];
		//cout<<b[i]<<" ";
	}
	F(i,1,n){
		pos[b[i]]=i;
	}
	m=0;
	F(i,1,n){
		if(ques(n)>ques(pos[i]))m++;
		modi(pos[i]);
	}
	cout<<m;
    return 0;
}