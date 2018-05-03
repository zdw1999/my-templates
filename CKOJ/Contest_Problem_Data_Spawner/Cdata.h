#include <cstdio>
#include <cstring>
#include <cstdlib>

namespace Data_C{
	
	const int MXN[3]={50,1000,2000};
	const int MXM[3]={1000,10000,300000};
	
	void print(int nd){
		int n,m;
		n=nd<7?nd<4?MXN[0]:MXN[1]:MXN[2];
		m=nd<7?nd<4?MXM[0]:MXM[1]:MXM[2];
		printf("%d %d\n",n,m);
		while(m--)printf("%llu %llu %llu %llu %s%llu\n",random(1,n),random(1,n),random(1,n),random(1,n),random(0,1)?"-":"",random()&0x7fLLU);
		
	}
	
};

int main(){
	Data_C::print(now_data_num);
	return 0;
}
