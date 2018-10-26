#include <bits/stdc++.h>

namespace Data_C{

	void print(){
	    int n=5,k=8,d=13;
	    printf("%d %d %d\n",n,k,d);
	    for(int i=1;i<=n*k;++i)
            printf("%llu ",random(1,30));
        puts("");
	}

};

int main(){
	Data_C::print();
	return 0;
}
