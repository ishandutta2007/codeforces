#include <cstdio>
int n,num[1010];
long long a,b,ans,det,chk1,chk2,arr[1010],odd[1010],even[1010],dbl1[10][1010],dbl2[10][1010];
inline long long min(long long x,long long y){
	return x<y?x:y;
}
inline long long max(long long x,long long y){
	return x>y?x:y;
}
int main(){
	scanf("%d",&n);
	for(register int i=1;i<=1000;++i){
		num[i]=num[i-1];
		if(i==(1<<num[i-1]+1))++num[i];
	}
	for(register int i=1;i<=n;++i){
		scanf("%lld",&arr[i]);
		even[i]=even[i-1],odd[i]=odd[i-1];
		if(i%2==0)even[i]+=arr[i];
		if(i%2==1)odd[i]+=arr[i];
	}
	for(register int i=1;i<=n;++i)dbl1[0][i]=dbl2[0][i]=even[i]-odd[i];
	for(register int i=1;i<=9;++i)for(register int j=1;j<=n-(1<<i)+1;++j)dbl1[i][j]=max(dbl1[i-1][j],dbl1[i-1][j+(1<<i-1)]);
	for(register int i=1;i<=9;++i)for(register int j=1;j<=n-(1<<i)+1;++j)dbl2[i][j]=min(dbl2[i-1][j],dbl2[i-1][j+(1<<i-1)]);
	for(register int i=1;i<=n;i+=2){
		for(register int j=i+1;j<=n;j+=2){
			a=arr[i],b=arr[j];
			det=(even[j-1]-odd[j-1])-(even[i]-odd[i]);
			if(j!=i+1)chk1=max(dbl1[num[j-i-1]][i+1],dbl1[num[j-i-1]][j-(1<<num[j-i-1])])-(even[i]-odd[i]),chk2=max(dbl1[num[j-i-1]][i],dbl1[num[j-i-1]][j-(1<<num[j-i-1])-1])-(even[j-1]-odd[j-1]);
			else chk1=chk2=0;
			a-=chk1,b-=chk2,det-=chk1,det+=chk2;
			if(det>0)a-=det;
			else b+=det;
			if(a<0||b<0)continue;
			if(j!=i+1)ans+=min(a,b)+1;
			else ans+=min(a,b);//except emptyset
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
4
2 2 3 4
*/