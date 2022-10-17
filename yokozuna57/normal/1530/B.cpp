#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

int h,w;
int ret,ret_x;
int a[22][22];
void solve(){
	ret=0;
	for(int i=0;i<h;i++)for(int j=0;j<w;j++)a[i][j]=0;
	for(int x=0;x<(1<<12);x++){
		bool ok=true;
		int cnt[4]={};
		for(int i=0;i<4;i++){
			for(int j=0;j<3;j++)if((x>>(3*i+j))&1)cnt[i]++;
			if(cnt[i]>1)ok=false;
		}
		if(!ok)continue;
		if(h==3&&((x>>2)&1)!=((x>>10)&1))continue;
		if(h==3&&((x>>4)&1)!=((x>>8)&1))continue;
		if(h==4&&((x>>2)&1)&&((x>>10)&1))continue;
		if(h==4&&((x>>4)&1)&&((x>>8)&1))continue;
		if(w==3&&((x>>1)&1)!=((x>>5)&1))continue;
		if(w==3&&((x>>7)&1)!=((x>>11)&1))continue;
		if(w==4&&((x>>1)&1)&&((x>>5)&1))continue;
		if(w==4&&((x>>7)&1)&&((x>>11)&1))continue;
		int ret_=0;
		for(int i=0;i<4;i++)ret_+=cnt[i];
		int z;
		z=h; if((x>>1)&1)z--; if((x>>5)&1)z--; ret_+=(z+1)/2;
		z=h; if((x>>7)&1)z--; if((x>>11)&1)z--; ret_+=(z+1)/2;
		z=w; if((x>>4)&1)z--; if((x>>8)&1)z--; ret_+=(z+1)/2;
		z=w; if((x>>2)&1)z--; if((x>>10)&1)z--; ret_+=(z+1)/2;
		if(ret_>ret){
			ret=ret_;
			ret_x=x;
		}
	}
	int x=ret_x;
	a[0][0]=(x>>0)&1;
	a[0][1]=(x>>1)&1;
	a[1][0]=(x>>2)&1;
	a[0][w-1]=(x>>3)&1;
	a[1][w-1]=(x>>4)&1;
	a[0][w-2]=(x>>5)&1;
	a[h-1][w-1]=(x>>6)&1;
	a[h-1][w-2]=(x>>7)&1;
	a[h-2][w-1]=(x>>8)&1;
	a[h-1][0]=(x>>9)&1;
	a[h-2][0]=(x>>10)&1;
	a[h-1][1]=(x>>11)&1;
	for(int j=2;j<w-2;j++){
		a[0][j]=1-a[0][j-1];
		a[h-1][j]=1-a[h-1][j-1];
	}
	for(int i=2;i<h-2;i++){
		a[i][0]=1-a[i-1][0];
		a[i][w-1]=1-a[i-1][w-1];
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++)printf("%d",a[i][j]);
		puts("");
	}
	puts("");
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%d%d",&h,&w);
		solve();
	}
}