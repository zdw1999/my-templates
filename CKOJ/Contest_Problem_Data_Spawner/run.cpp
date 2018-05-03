#define PRIME_LIST_LIMIT 1000000

#include <zdwstd.h>

int now_data_num;
using zdw::random;
//#define TEST 'E'

#ifdef TEST
	#define DISPLAY_OUTPUT 0
#else
	//#define USE_OLD_DATA
#endif

#define LOCAL

int Adata();
int Bdata();
int Cdata();
int Ddata();
int Edata();
//int Fdata();
int Astart();
int Bstart();
int Cstart();
int Dstart();
int Estart();
//int Fstart();

int (*_data[])()={Adata,Bdata,Cdata,Ddata,Edata};
int (*_main[])()={Astart,Bstart,Cstart,Dstart,Estart};

char bufin[]="__.in",bufout[]="__.out";

int main(){
	
	//freopen(".err","w",stderr);
	
	zdw::set_rand_seed(19990630+time(0));
	srand(19990630+time(0));
	long st=clock();
#ifndef TEST
	for(char c='D';c<='D';++c){
		bufin[0]=bufout[0]=c;
#ifdef USE_OLD_DATA
		fprintf(stderr,"Data of %c skipped.\n",c);
#else
		fprintf(stderr,"Data of %c spawning...\n",c);
		for(char cc='0';cc<='9';++cc){
			now_data_num=(bufin[1]=cc)-'0';
			freopen(bufin,"w",stdout);
			_data[c-'A'](); fclose(stdout);
		}
		fprintf(stderr,"Data of %c done.\nTime used: %dms\n",c,int(clock()-st));
#endif
		fprintf(stderr,"Program %c's std is running...\n",c);
		for(char cc='0';cc<='9';++cc){
			now_data_num=(bufin[1]=bufout[1]=cc)-'0';
			freopen(bufin,"r",stdin);
			freopen(bufout,"w",stdout);
			st=clock();
			fprintf(stderr,"Test #%c: Program return: %d\n",cc,_main[c-'A']());
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

#define main Adata
	#include "Adata.h"
#undef main
#define main Bdata
	#include "Bdata.h"
#undef main
#define main Cdata
	#include "Cdata.h"
#undef main
#define main Ddata
	#include "Ddata.h"
#undef main
#define main Edata
	#include "Edata.h"
#undef main

#define main Astart
	#include "A.h"
#undef main
#define main Bstart
	#include "B.h"
#undef main
#define main Cstart
	#include "C.h"
#undef main
#define main Dstart
	#include "D.h"
#undef main
#define main Estart
	#include "E.h"
#undef main




