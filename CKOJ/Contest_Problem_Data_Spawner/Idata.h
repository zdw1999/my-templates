#include <bits/stdc++.h>

int main(){

    int T=200;
    printf("%d\n",T);
    while(T--){
        int n=T<10?T<2?50000:2000:200,q=n;
        printf("%d %d\n",n,q);
        for(int i=1;i<=n;++i)
            printf(i==n?"%llu\n":"%llu ",random(1,1000000));
        while(q--)
            printf("%llu %llu\n",random(1,n),random(1,1000000));
    }

	return 0;
}
