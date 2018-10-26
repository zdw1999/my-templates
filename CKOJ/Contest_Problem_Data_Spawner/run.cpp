#define PRIME_LIST_LIMIT 1000000
#include <bits/stdc++.h>
//#include <bits/extc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <zdwstd.h>
//#include <My_Random.h>
//#define TEST 'D'
#ifdef TEST
	#define DISPLAY_OUTPUT 1
#else
	//#define USE_OLD_DATA
#endif
#define LOCAL
int now_data_num;
using zdw::random;
#include "spawn_system.h"
char bufin[]="___.in",bufout[]="___.out";

int main(){
	//freopen(".err","w",stderr);

	zdw::set_rand_seed(19990630+time(0));
	srand(19990630+time(0));
	long st=clock();
#ifndef TEST
	for(char c='E';c<='E';++c){
		bufin[0]=bufout[0]=c;
#ifdef USE_OLD_DATA
		fprintf(stderr,"Data of %c skipped.\n",c);
#else
		fprintf(stderr,"Data of %c spawning...\n",c);
		for(int cc=0;cc<=9;++cc){
			now_data_num=cc;
			bufin[1]=cc/10+'0';
			bufin[2]=cc%10+'0';
			freopen(bufin,"w",stdout);
			_data[c-'A'](); fclose(stdout);
		}
		fprintf(stderr,"Data of %c done.\nTime used: %dms\n",c,int(clock()-st));
#endif
		fprintf(stderr,"Program %c's std is running...\n",c);
		for(int cc=0;cc<=9;++cc){
			now_data_num=c;
			bufin[1]=bufout[1]=cc/10+'0';
			bufin[2]=bufout[2]=cc%10+'0';
			freopen(bufin,"r",stdin);
			freopen(bufout,"w",stdout);
			st=clock();
			fprintf(stderr,"Test #%d: Program return: %d\n",cc,_main[c-'A']());
			fprintf(stderr,"Program done.\nTime used: %dms\n",int(clock()-st));
			fclose(stdin); fclose(stdout);
		}
	}
#else
	//freopen(".in","r",stdin);
	if(!DISPLAY_OUTPUT)freopen(".out","w",stdout); st=clock();
	fprintf(stderr,"Program return: %d\n",_main[TEST-'A']());
	fprintf(stderr,"Program done.\nTime used: %dms\n",int(clock()-st));
#endif
	return 0;
}




