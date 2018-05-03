#include <cstdio>
#include <cstring>
#include <cstdlib>

namespace Data_D{
	
	const int MXT=3;
	const int MXN[3]={2000,100000,200000};
	const int MXM[3]={2000,200000,2000000};
	
	void print(int nd){
		int t=nd>2?nd>5?2:1:0;
		int n=MXN[t],m=MXM[t];
		printf("%d %d\n",n,m);
		for(int i=2;i<=n/3;++i)
			printf("%llu\n",random(1,i-1));
		int k=6,l=(n-n/3)/(k+1);
		for(int p=0,i=n/3+1;p<k;++p){
			printf("%llu\n",random(1,n/3));
			for(int q=1;q<l;++q)
				printf("%d\n",i+p*l+q-1);
		}for(int p=n/3+k*l+1;p<=n;++p)
			printf("%llu\n",random(1,p-1));
		for(int i=1;i<=m/2;++i)
			printf("%llu %llu\n",random(1,n),random(1,n));
		for(int i=m/2+1;i<=m;++i){
			int rl1=random(1,k),rl2=random(1,k),d1=random(3,l-100),d2=random(3,l-100);
			printf("%llu %llu\n",random(n/3+rl1*l-d1,n/3+rl1*l-2),random(n/3+rl2*l-d2,n/3+rl2*l-2));
		}
	}
	
};

int main(){
	
	int T=Data_D::MXT; printf("%d\n",T);
	if(now_data_num>5&&T>=2){
		int n=Data_D::MXN[2];
		int m=Data_D::MXM[2];
		//link
		printf("%d %d\n",n,n);
		for(int i=2;i<=n;++i)
			printf("%d\n",i-1);
		for(int i=1;i<=n;++i)
			printf("%d %d\n",i,n);
		//heap
		printf("%d %d\n",n,m);
		for(int i=2;i<=n;++i)
			printf("%d\n",i>>1);
		for(int i=1;i<=m;++i)
			printf("%llu %llu\n",random(1,n),random(1,n));
		T-=2;
	}else if(now_data_num>2&&T>=2){
		int n=Data_D::MXN[1];
		int m=Data_D::MXM[1];
		//link
		printf("%d %d\n",n,n);
		for(int i=2;i<=n;++i)
			printf("%d\n",i-1);
		for(int i=1;i<=n;++i)
			printf("%d %d\n",i,n);
		//heap
		printf("%d %d\n",n,m);
		for(int i=2;i<=n;++i)
			printf("%d\n",i>>1);
		for(int i=1;i<=m;++i)
			printf("%llu %llu\n",random(1,n),random(1,n));
		T-=2;
	}while(T-->0)Data_D::print(now_data_num);
	return 0;
}
