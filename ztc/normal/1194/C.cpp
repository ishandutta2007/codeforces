#include<stdio.h>
int cnt[26],f;
int t,p,q;char a[1000002],b[1000002],c;
int main(){
	scanf("%d",&t);
	while(t--){
		for(int i=0;i<=25;i++)cnt[i]=0;f=0;p=0;q=0;
		while((a[0]=getchar())<'!');cnt[a[0]-'a']++;
		while((a[++p]=getchar())>='!')cnt[a[p]-'a']++;
		while((b[0]=getchar())<'!');cnt[b[0]-'a']--;
		while((b[++q]=getchar())>='!')cnt[b[q]-'a']--;
		int z=0;
		for(int i=0;i<=p;i++){
			while(z<=q+1&&b[z]!=a[i])z++;
			if(z<=q+1)z++;
		}f=z>=q+2;
		while((c=getchar())<'!');cnt[c-'a']++;
		while((c=getchar())>='!')cnt[c-'a']++;
		for(int i=0;i<=25;i++)f|=cnt[i]<0;
		printf("%s\n",f?"NO":"YES");
	}
}