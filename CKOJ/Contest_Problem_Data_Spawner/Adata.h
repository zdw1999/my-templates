#include <cstdio>
#include <cstring>
#include <cstdlib>

namespace Data_A{
	
	const int MXT=50;
	const int MXK=999;
	
	void print_data(int nd){
		int T=MXT;
		printf("%d\n",T);
		while(T--){
			printf("%llu %llu %llu\n",random(1LL,1LL<<59),random(1LL,1LL<<59),nd<6?6LLU:random(MXK/3,MXK));
		}
	}
	
}

int main(){
	Data_A::print_data(now_data_num);
	return 0;
}
