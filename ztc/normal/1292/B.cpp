#include<stdio.h>
long long x,y,pos[102][2],a1,a2,b1,b2,t,n=1,ans=0;
inline long long Abs(long long p){return p<0?-p:p;}
int main(){
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&pos[0][0],&pos[0][1],&a1,&a2,&b1,&b2,&x,&y,&t);
	while(1){
		pos[n][0]=pos[n-1][0]*a1+b1;
		pos[n][1]=pos[n-1][1]*a2+b2;
		if(pos[n][0]+pos[n][1]>=4e16)break;
		n++;
	}for(int i=0;i<n;i++){
		long long cnt=0,val=0;
		cnt+=Abs(pos[i][0]-x)+Abs(pos[i][1]-y);
		if(cnt<=t){
			val=1;
			long long cntt=cnt;
			for(int j=i-1;j>=0;j--){
				cntt+=Abs(pos[j+1][0]-pos[j][0])+Abs(pos[j+1][1]-pos[j][1]);
				if(cntt>t)break;
				val++;
			}if(val>ans)ans=val;val=1;cntt=cnt;
			for(int j=i+1;j<n;j++){
				cntt+=Abs(pos[j-1][0]-pos[j][0])+Abs(pos[j-1][1]-pos[j][1]);
				if(cntt>t)break;
				val++;
			}if(val>ans)ans=val;
		}
	}printf("%lld",ans);
}