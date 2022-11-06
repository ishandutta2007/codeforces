#include<stdio.h>
char c[100002];int n=0,cnt=0;
int main(){
	scanf("%s",c);
	while(c[n])n++;
	for(int i=n-1;i>=0;i--){
		if(c[i]=='0')cnt=cnt>=0?-1:cnt-1;
		else{
			int j=i,k;
			while(j&&c[j]=='1')j--,cnt++;cnt+=c[j]=='1';j+=c[j]=='0';
			if(cnt>0||i==n-1)for(int h=j;h<j+cnt;h++)c[h]='0';i=j;
		}
	}puts(c);
}