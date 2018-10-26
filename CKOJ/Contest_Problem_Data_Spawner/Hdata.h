#include <bits/stdc++.h>

int main(){
    int T=20;
    printf("%d\n",T);
    printf("10\n");
    printf("PUSH 1\n");
    printf("QUERY\n");
    printf("PUSH 0\n");
    printf("QUERY\n");
    printf("REVERSE\n");
    printf("QUERY\n");
    printf("POP\n");
    printf("POP\n");
    printf("REVERSE\n");
    printf("QUERY\n");
    T--;
    while(T--){
        int n=200000,cnt=0;
        printf("%d\n",n);
        while(n--){
            ll op=random(1,199)/25+1;
            while((op==2)&&!cnt)op=random(1,99)/25+1;
            if(op<6)//push
                printf("PUSH %llu\n",random(1,99)/50),++cnt;
            if(op==6)//pop
                printf("POP\n"),--cnt;
            if(op==7)//reverse
                printf("REVERSE\n");
            if(op==8)//query
                printf("QUERY\n");
        }
    }return 0;
}
