#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y);
}

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	if(a>b)swap(a,b);

	int c=gcd(a,b);


	vector<int> sq;
	for(int i=1;i<c;i++){
		sq.push_back(i*i);
	}
	int x=-1,y;
	for(int i=0;i<c-1;i++){
		if(upper_bound(sq.begin(),sq.end(),c*c-sq[i])-lower_bound(sq.begin(),sq.end(),c*c-sq[i])){ x=i+1; y=lower_bound(sq.begin(),sq.end(),c*c-sq[i])-sq.begin()+1; break; }
	}
	if(x==-1)printf("NO\n");
	else {
		if(y*a/c!=x*b/c)printf("YES\n%d %d\n%d %d\n%d %d\n",0,0,x*a/c,y*a/c,-y*b/c,x*b/c);
		else printf("YES\n%d %d\n%d %d\n%d %d\n",0,0,y*a/c,x*a/c,-x*b/c,y*b/c);
	}
}