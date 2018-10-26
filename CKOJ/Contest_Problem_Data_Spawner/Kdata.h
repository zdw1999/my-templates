#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>

int main(){
    int T=40;
    printf("%d\n",T);
    while(T--){
        int n=T<10?T<4?20000:2000:200;
        printf("%d\n",n);
        for(int i=2;i<=n;++i)
            printf(T<2?"%d %d\n":"%llu %d\n",T<2?i-1:random(1,i-1),i);
        for(int i=1;i<=n;++i)
            printf("%llu %llu\n",random(1,5),random(1,1000000000));
        int q=n*3/2;
        printf("%d\n",q);
        while(q--)
            printf("%llu %llu\n",random(1,n),random(1,100000));
    }
}
