#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
typedef double ldb;
typedef long long ll;
struct point{
    ll x,y;
    point(){}
    point(ll x,ll y):x(x),y(y){}
    point operator-(const point& p)const{
        return point(x-p.x,y-p.y);
    }
}p[maxn*4],sta[maxn*4];
ll cross(point a,point b){return a.x*b.y-a.y*b.x;}
ll length(point a){return a.x*a.x+a.y*a.y;}
ll dot(point a,point b){return a.x*b.x+a.y*b.y;}
int comp(const point& a,const point& b){return a.x==b.x?a.y<b.y:a.x<b.x;}
int cal(vector<ll>s, int l)  {  
	int i,j,k;
	i=0;j=1;k=0;
	while(i<l&&j<l)
	{
		k=0;
		while(s[i+k]==s[j+k]&&k<l) k++;
		if(k==l) return i;
		if(s[i+k]>s[j+k]) 
		 if(i+k+1>j) i=i+k+1;
		 else i=j+1;
		else if(j+k+1>i) j=j+k+1;
		else  j=i+1; 
	}
	if(i<l) return i;
	else return j;
} 

vector<point> get(vector<point> v){
	int n=0,tp=0;
	for(auto q:v)p[++n]=q;
    sort(p+1,p+n+1,comp);
    for(int i=1;i<=n;++i){
        while(tp>1&&cross(sta[tp-1]-sta[tp-2],p[i]-sta[tp-2])<=0)tp--;
        sta[tp++]=p[i];
    }
    int k=tp;
    for(int i=n-1;i>=1;--i){
        while(tp>k&&cross(sta[tp-1]-sta[tp-2],p[i]-sta[tp-2])<=0)tp--;
        sta[tp++]=p[i];
    }
    tp--;
    vector<point> ret;
    for(int i=1;i<=tp;++i)ret.push_back(sta[i]);
    return ret;
}
int main(){
	vector<point>A,B;
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		A.push_back(point(x,y));
	}
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		B.push_back(point(x,y));
	}
	A=get(A),B=get(B);
	vector<ll>nA,nB;
	if(A.size()!=B.size())return puts("NO"),0;
	for(int i=0;i<A.size();++i){
//		printf("[%d,%d]",A[i].x,A[i].y);
		nA.push_back(length(A[i]-A[i==A.size()-1?0:i+1]));
		nA.push_back(dot(A[i==0?A.size()-1:i-1]-A[i],A[i==A.size()-1?0:i+1]-A[i]));
	}
	for(int i=0;i<B.size();++i){
		nB.push_back(length(B[i]-B[i==B.size()-1?0:i+1]));
		nB.push_back(dot(B[i==0?B.size()-1:i-1]-B[i],B[i==B.size()-1?0:i+1]-B[i]));
	}
//	for(auto a:nA)printf("[%lld]",a);puts("");
//	for(auto a:nB)printf("[%lld]",a);puts("");
	int a=cal(nA,nA.size()),b=cal(nB,nB.size());
	for(int i=0;i<nA.size();++i){
		if(nA[a]!=nB[b])return puts("NO"),0;
		if(a==nA.size()-1)a=0;else a++;
		if(b==nB.size()-1)b=0;else b++;
	}
	puts("YES");
}