#include <bits/stdc++.h>
char cc[]="+-*/";

int main(){

	if(now_data_num==1){
		puts("((2+3))");
	}

	if(now_data_num==2){
		puts("((2+3)(4/5))(1+3*(6+7))");
	}

	if(now_data_num==3){
		puts("((12(((233))233)))233");
	}

	if(now_data_num==4){
		puts("3");
	}

	if(now_data_num==5){
		puts("1+2*5");
	}
	if(now_data_num==6){
		for(int i=1;i<=33333;++i)
			printf("(%d)",random(0,9));
		puts("");
	}
	if(now_data_num==7){
		for(int i=1;i<=20000;++i)
			printf("((%d))",random(0,9));
		puts("");
	}
	if(now_data_num==8){
		for(int i=1;i<=20000;++i)
			printf("(%d%c%d)",random(0,9),cc[random(0,3)],random(0,9));
		puts("");
	}

}
