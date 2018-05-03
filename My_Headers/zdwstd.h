/****************************************

	This file only uses with zdw's
	private lib.
	
	Last_update: 2018-01-03 02:35

*****************************************/

#ifndef __ZDWSTD_H__
#define __ZDWSTD_H__

	#define __ZDW_LIB_VER__ 0.11
	
	#pragma comment(linker, "/STACK:268435456")
	
	#ifndef __NO_STD_HEADER__

		#include <cmath>
		#include <ctime>
		#include <cstdio>
		#include <cstring>
		#include <cstdlib>
		#include <iostream>
		#include <algorithm>

	#endif
	
	#include <My_Std.h>

	//zdw lib
	#include <My_Random.h>
	#include <My_Hash.h>
	#include <My_Math.h>
	#include <My_UFind.h>
	#include <My_Treap.h>
	#include <My_String.h>
	#include <My_Console.h>
	//#include <My_GameEngine.h> //Not done yet.
	#include <My_Set.h>
	#include <My_Heap.h>

#endif
