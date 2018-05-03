#include <cstdio>
#include <cstring>
#include <cstdlib>


namespace Data_B{
	
	const int MXT=10000;
	const int MXN[2]={233,1000000};
	
	void print_data(int nd){
		int T=MXT;
		printf("%d\n",T);
		while(T--){
			
			int a=random(1,MXN[nd<8?0:1]);
			int b=random(1,MXN[nd<8?0:1]);
			int c=random(1,MXN[nd<8?0:1]);
			int d=random(1,MXN[nd<8?0:1]);
			int e=random(1,MXN[nd<8?0:1]);
			int f=random(1,MXN[nd<8?0:1]);
			if(nd<3)c=d=0;
			if(nd<6)e=f=0;
			
			printf("%d %d %d %d %d %d\n",a,b,c,d,e,f);
		}
	}
	
}

int main(){
	Data_B::print_data(now_data_num);
	return 0;
}
