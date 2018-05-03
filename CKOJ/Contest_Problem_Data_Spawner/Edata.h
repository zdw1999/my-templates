#include <cstdio>
#include <cstring>
#include <cstdlib>

namespace Data_E{
	
	const int MXT=6;
	const int MXN=10000;
	const int MXM[]={100,2000,4};
	
	void print(int nd){
		int n=random(MXN*4/5,MXN),m=(rand()&1?nd<6?random(MXM[0]*5/6,MXM[0]):random(MXM[1]*3/4,MXM[1]):random(1,MXM[2]));
		printf("%d %d\n%llu 0\n",n,m,random(1,1<<30));
		for(int i=2;i<=n;++i)
			printf("%llu %llu\n",random(1,1<<30),random(1,i-1));
	}
	
};

int main(){
	
	int T=Data_E::MXT;
	
	printf("%d\n",T);
	while(T--)
		Data_E::print(now_data_num);
	
	return 0;
}
