#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>

int main(){
	int cs=now_data_num,n=10000;
	if(cs==1){
		printf("%d\n",n=500);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=i;++j)
				putchar('A');
			puts("");
		}
	}else if(cs<5){
		printf("%d\n",n);
		for(int i=1;i<=n;++i){
			for(int j=i;j;j/=cs)
				putchar('A'+j%cs);
			puts("");
		}
	} else if(cs<7){
		printf("%d\n",5); n=100000; cs=2;
		for(int i=1;i<=5;++i,++cs){
			for(int j=1;j<=n;++j)
				putchar('A'+random(1,cs)-1);
			puts("");
		}
	} else {
		printf("%d\n",50); n=10000; cs=2;
		for(int i=1;i<=50;++i,++cs){
			if(cs>26)cs=26;
			for(int j=1;j<=n;++j)
				putchar('A'+random(1,cs)-1);
			puts("");
		}
	}

}
