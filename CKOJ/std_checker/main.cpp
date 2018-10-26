#include <bits/stdc++.h>
#include <zdwstd.h>
using zdw::random;

std::string to_string(int t){
	char s[15];
	sprintf(s,"%d",t);
	std::string ss(s);
	return ss;
}

int now_data_num;

#define fin ".in"
#define fout ".out"
#define fans ".ans"
#define errmsg(...) fprintf(stderr,__VA_ARGS__)
#define Set0(x) memset(x,0,sizeof(x))

#define main data
#include "data.h"
#undef main
namespace STD{
#define main pstd
#include "std.h"
#undef main
}namespace sv{
#define main solve
#include "solve.h"
#undef main
}
#define _TESTS_ 10000

namespace __checker{

	const int BUF_SIZE=1<<18;

	void init_tail(char *ed){
		while(!*ed||*ed=='\r'||*ed=='\n'||*ed==' ')--ed;
		*++ed=0;//avoid space before endl.
	}

	int check(FILE *A,FILE *B){

		char buf1[BUF_SIZE+1],*t1;
		char buf2[BUF_SIZE+1],*t2;
		int now_line=0,t;

		while(++now_line){
			t1=fgets(buf1,BUF_SIZE,A);
			t2=fgets(buf2,BUF_SIZE,B);
			if(!t1&&!t2)return 0;
			if(!t1||!t2)return now_line;
			t=strlen(t1); init_tail(t1+t);
			t=strlen(t2); init_tail(t2+t);
			while((*t1||*t2))if(*t1++!=*t2++)return now_line;
		}

		//error
		return -1;

	}

};

int main(){

	zdw::set_rand_seed(time(0)+19990630);

	int st=clock();

	for(int i=1,st,res;i<=_TESTS_;++i){

		now_data_num=i;

		//Data
		freopen(fin,"w",stdout);
		errmsg("Data #%d Spawning...\n",i);
		st=clock(); res=data();
		errmsg("Data #%d Spawned Successfully.\n",i);
		errmsg("Spawner Returned %d.\n",res);
		errmsg("Time Used: %dms.\n",clock()-st);
		fclose(stdout);

		//std
		freopen(fin,"r",stdin);
		freopen(fans,"w",stdout);
		errmsg("std Running on Test #%d...\n",i);
		st=clock(); res=STD::pstd();
		errmsg("std Running Done on Data #%d.\n",i);
		errmsg("std Returned %d.\n",res);
		errmsg("Time Used: %dms.\n",clock()-st);
		fclose(stdin); fclose(stdout);

		//Solve
		freopen(fin,"r",stdin);
		freopen(fout,"w",stdout);
		errmsg("Solve Running on Test #%d...\n",i);
		st=clock(); res=sv::solve();
		errmsg("Solve Running Done on Data #%d.\n",i);
		errmsg("Solve Returned %d.\n",res);
		errmsg("Time Used: %dms.\n",clock()-st);
		fclose(stdin); fclose(stdout);

		//Checker
		FILE *ans=fopen(fans,"r");
		FILE *out=fopen(fout,"r");
		errmsg("Checking Test #%d...\n",i);
		st=clock(); res=__checker::check(ans,out);
		//errmsg("Checker Running Done on Data #%d.\n",i);
		//errmsg("Time Used: %dms.\n",clock()-st);
		fclose(stdin); fclose(stdout);
		if(res)return !errmsg("WA on Test #%d on Line #%d.\n",i,res);
		errmsg("Test #%d Passed.\n",i);

		errmsg("\n\n\n");

	}

	errmsg("All %d Tests Passed.\nTime Used: %dms\n",_TESTS_,clock()-st);
	return 0;

}
