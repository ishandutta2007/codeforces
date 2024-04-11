#include<cstdio>
#include<cstring>
const int N=100005;
int a[26],n,i,ans;
char c[N],o[5];//-1,0,1 
bool flag,b[26];
inline bool check(){
	int s=0;
	for(int i=0;i<26;++i){
		if(a[i]==1)return 1;
		s+=a[i]==0;
	}
	return s==25;
}
int main(){
	scanf("%d",&n);memset(a,-1,104);
	while(n--){
		scanf("%s%s",o,c+1);
		if(*o=='!'){
			memset(b,0,sizeof b);
			for(i=1;c[i];++i)b[c[i]-'a']=1;
			for(i=0;i<26;++i)if(!b[i])a[i]=0;
		}
		if(*o=='.'){
			for(i=1;c[i];++i)a[c[i]-'a']=0;
		}
		if(*o=='?'){
			if(n)a[c[1]-'a']=0;
				else a[c[1]-'a']=1;
		}
		if(flag && (*o=='!' || (*o=='?' && n)))++ans;
		if(check())flag=1;
	}
	return printf("%d\n",ans),0;
}