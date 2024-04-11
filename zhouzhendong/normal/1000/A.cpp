#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int n;
struct cl{
	int M,S,L;
	int SL[4];//S
	void read(){
		M=S=L=0;
		memset(SL,0,sizeof SL);
		for (int i=1;i<=n;i++){
			char a[N];
			scanf("%s",a+1);
			int len=strlen(a+1);
			if (len==1){
				if (a[1]=='M')
					M++;
				if (a[1]=='S')
					S++;
				if (a[1]=='L')
					L++;
			}
			else {
				if (a[len]=='S')
					SL[len-1]++;
			}
		}
	}
}x,y;
int main(){
	scanf("%d",&n);
	x.read(),y.read();
	int tot=0;
	for (int i=1;i<=3;i++)
		tot+=abs(x.SL[i]-y.SL[i]);
	printf("%d",x.M+x.S+x.L-min(x.M,y.M)-min(x.S,y.S)-min(x.L,y.L)+tot);
	return 0;
}