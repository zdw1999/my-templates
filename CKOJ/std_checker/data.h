#include <bits/stdc++.h>

namespace Data_C{

	void print(){
	    int n=200000,a=random(100000000,1000000000),b=random(100000000,1000000001)-1;
		printf("%d %d %d\n",n,a,b);
		for(int i=1;i<=n;++i){
            int z=i,x=random(100000000,1000000001)-1,y=random(100000000,1000000001)-1;
            if(random(1,2)>1)z*=-1;
            if(random(1,2)>1)x*=-1;
            if(random(1,2)>1)y*=-1;
            printf("%d %d %d\n",z,x,y);
		}
	}

};

int main(){
	Data_C::print();
	return 0;
}
