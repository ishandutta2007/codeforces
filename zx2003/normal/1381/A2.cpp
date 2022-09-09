#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,i;
char a[N],b[N];
int l,r,r1,r2;
vector<int>ve;
inline int back(){return r1?a[l]^r2:a[r]^r2;}
inline int front(){return r1?a[r]^r2:a[l]^r2;}
inline void rev(){r1^=1;r2^=1;}
inline void pop_back(){r1?++l:--r;}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%s%s",&n,a+1,b+1);l=1;r=n;r1=0;r2=0;ve.clear();
		for(i=1;i<=n;++i)a[i]-='0',b[i]-='0';
		for(i=n;i;--i,pop_back())if(back()!=b[i]){
			if(front()==b[i]){
				ve.push_back(1);
				r1?a[r]^=1:a[l]^=1;
			}
			if(back()!=b[i]){
				ve.push_back(i);
				rev();
			}
		}
		printf("%d ",(int)ve.size());for(int x:ve)printf("%d ",x);puts("");
	}
}