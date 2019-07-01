#include <bits/stdc++.h>
char cc[]="+-*/";

int main(){

	int n;

	if(now_data_num==1){
		puts("113");
		for(int i=1;i<=100;++i)printf("10 ");//1000
		puts("-1 5 -1000 1002 -1 -999 -1 1000 -1 -1 29 -1020 50");
	}

	if(now_data_num==2){
		puts("1");
		puts("1");
	}

	if(now_data_num==3){
		puts("1");
		puts("-1");
	}

	if(now_data_num==4){
		puts("3");
		puts("1 -1 1");
	}

	if(now_data_num==5){
		puts("3");
		puts("-1 1 -1");
	}

	if(now_data_num==6){
		puts("1000");
		for(int i=1;i<=999;++i)printf("1 ");//1000
		puts("1");
	}

	if(now_data_num==7){
		puts("1000");
		for(int i=1;i<=999;++i)printf("-1 ");//1000
		puts("-1");
	}

	if(now_data_num==8){
		puts("100000");
		for(int i=1;i<=9999;++i)printf("1 ");//9999
		printf("-99999");
		for(int i=1;i<=80000;++i)printf(" 1");
		printf(" -99999");
		for(int i=1;i<=9999;++i)printf(" 1");//9999
		puts("");
	}

	if(now_data_num==9){
		puts("100000");
		printf("-5 ");
		for(int i=2;i<=9999;++i)printf(random(0,10)?"-5 ":"1 ");//-9999
		for(int i=1;i<=10;++i)printf("99999 -9 ");//10*99990 (20)
		for(int i=1;i<=79962;++i)printf(random(0,10)?"-100 ":"1 ");
		for(int i=1;i<=10;++i)printf("99999 -9 ");//10*99990 (20)
		for(int i=1;i<=9998;++i)printf(random(0,10)?"-5 ":"1 ");//-9999
		puts("-5");//-9999
	}

	if(now_data_num==10){
		puts("100000");
		for(int i=1;i<=100000;++i)
			printf(i==n?"%d\n":"%d ",(int)-1e9);
	}

	if(now_data_num==11){
		puts("100000");
		for(int i=1;i<=100000;++i)
			printf(i==n?"%d\n":"%d ",(int)1e9);
	}

	if(now_data_num>11){
		int n=100000;
		puts("100000");
		for(int i=1;i<=n;++i){
			printf(i==n?"%d\n":"%d ",(int)(random(0,2e9)-1e9));
		}
	}
}
