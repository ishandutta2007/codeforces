#include<stdio.h>
long long a,b,c,d;
int main(){
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	printf("%lld",(a==b?d+(a<c&&c-a<d?d-c+a:0)+(a>c&&a-c<d?d-a+c:0):0)+(c==b?d+(a<b&&b-a<d?d-b+a:0)+(a>c&&a-c<d?d-a+c:0):0)+(a==c?d+(a<b&&b-a<d?d-b+a:0)+(a>b&&a-b<d?d-a+b:0):0)-(a==b&&b==c?d:0)+(a<b&&b<c?(b-a<d?d-b+a:0)+(c-b<d?d-c+b:0):0)+(a<c&&c<b?(c-a<d?d-c+a:0)+(b-c<d?d-b+c:0):0)+(b<a&&a<c?(a-b<d?d-a+b:0)+(c-a<d?d-c+a:0):0)+(b<c&&c<a?(c-b<d?d-c+b:0)+(a-c<d?d-a+c:0):0)+(c<a&&a<b?(a-c<d?d-a+c:0)+(b-a<d?d-b+a:0):0)+(c<b&&b<a?(b-c<d?d-b+c:0)+(a-b<d?d-a+b:0):0));
}