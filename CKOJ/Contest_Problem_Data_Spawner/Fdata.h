#include <bits/stdc++.h>
using namespace std;

void make_data(int n,int q,int len,int cs_sz,int w=0){
	if(cs_sz<1)cs_sz=1;
	printf("%d %d\n",n,q);
	for(int i=1;i<=n;++i){
		int l=len;
		while(l--){
			int c=random(1,cs_sz);
			if(c>26)c+='a'-27;
			else c+='A'-1;
			putchar(c);
		}
		puts("");
	}
	while(q--){
		int a=random(1,n),b=random(1,n),x=w?random(1,w):random(1,len),y=w?random(1,w):random(1,len);
		printf("%d %d %d %d\n",a,x,b,y);
	}
}

void hand(){
	printf("%d %d\n",2,200000);
	printf("qwq"); for(int i=2;i<=200000;++i)printf("ab"); puts("qxq");
	printf("qxq"); for(int i=2;i<=200000;++i)printf("ab"); puts("qvqa");
	puts("1 1 2 1");
	puts("1 3 2 3");
	puts("1 400004 2 1");
	puts("1 4 2 6");
	for(int i=5;i<=200000;++i)
		printf("%d %d %d %d\n",(i&1)+1,i/2+2,(~i&1)+1,i/2+random(2,1000)*2);
}

int main(){
	if(now_data_num<=6){
		int n=50,q=1000;
		if(now_data_num<=2){
			make_data(n,q,50,52);
		} else if(now_data_num==6){
			make_data(2000,2000,1,52);
		} else if(now_data_num==5){
			make_data(2,2000,1000,52);
		} else {
			make_data(n,q,50,now_data_num-2);
		}
	} else {
		if(now_data_num<=8){
			if(now_data_num==8)hand();
			else {
				int n=5e4,q=2e5;
				make_data(n,q,10,1,now_data_num-7);
			}
		}else if(now_data_num<=10){
			int n=5e4,q=2e5;
			make_data(n,q,10,now_data_num-8,now_data_num-7);
		}else if(now_data_num<=12){
			int n=10,q=2e5;
			make_data(n,q,5e4,now_data_num-10,now_data_num-7);
		}else if(now_data_num<=16) {
			int n=10,q=2e5;
			make_data(n,q,5e4,52);
		}else if(now_data_num<=18) {
			int n=2,q=2e5;
			make_data(n,q,250000,52);
		}else if(now_data_num<=19) {
			int n=5e5,q=2e5;
			make_data(n,q,1,52);
		} else {
			int n=250000,q=2e5;
			make_data(n,q,2,52);
		}
	}
}
