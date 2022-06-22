#ifndef __BITMAP_H__
#define __BITMAP_H__
#include "datasize.h"
#define Bitmap_run(object) ({Bitmap_run_obj.obj = &object;Bitmap_run_obj;})
typedef struct bitmap bitmap;
struct bitmap{
	unsigned char *data;
	size_d size;
	size_d n;
};

typedef struct Bitmap{
	bitmap *obj;
	void (*init)(size_d n);
	size_d (*count)();
	void (*set)(size_d id);
	_Bool (*lookAt)(size_d id);
	void (*reset)(size_d id);
	void (*reall)();
}Bitmap;

extern Bitmap Bitmap_run_obj;

#endif
