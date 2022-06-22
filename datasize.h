#ifndef __DATASIZE_H__
#define __DATASIZE_H__

// #define #D64

#ifdef D64
	typedef unsigned long long size_d; 
#else
	typedef unsigned size_d;
#endif

#endif
