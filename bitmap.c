/*************************************************************************
	> File Name: bitmap.c
	> Author: xjz
	> Mail: xjz8053@gmail.com 
	> Created Time: 2022年06月22日 星期三 12时32分49秒
 ************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "bitmap.h"
#include "datasize.h"

static inline void look(bitmap *obj)
{
	assert(obj&&obj->data);
}

static void init(size_d n)
{
	size_d sum = n/8;
	sum += !!(n%8);
	bitmap *obj = Bitmap_run_obj.obj;
	assert(obj);
	obj->size = sum;
	obj->n = n;
	obj->data = calloc(sum,1);
}
static size_d count()
{
	bitmap *obj = Bitmap_run_obj.obj;
	look(obj);
	size_d sum = 0;
	char bit;
	for(size_d i=0;i<obj->size;i++)
	{
		bit = 0x01;
		for(char j=0;j<8;j++)
		{
			sum += (obj->data[i]&bit)?1:0;
			bit <<= 1;
		}
	}
	size_d offset = obj->size*8;
	bit = 0x01<<(obj->n%8);
	for(size_d i = obj->n;i<offset;i++)
	{
		sum -= (obj->data[obj->size-1]&bit)?1:0;
		bit = bit<<1;
	}
	return sum;
}
static void set(size_d id)
{
	bitmap *obj = Bitmap_run_obj.obj;
	look(obj);
	assert(id<obj->n);
	char bit = 0x01;
	obj->data[id/8] |= bit << (id%8);
}
static _Bool lookAt(size_d id)
{
	bitmap *obj = Bitmap_run_obj.obj;
	look(obj);
	assert(id<obj->n);
	char bit = 0x01;
	return obj->data[id/8]&bit<<(id%8);
}
static void reset(size_d id)
{
	bitmap *obj = Bitmap_run_obj.obj;
	look(obj);
	assert(id<obj->n);
	char bit = 0x01;
	bit <<= id%8;
	char temp = obj->data[id/8]&bit;
	if(temp)
		obj->data[id/8] ^= bit;
	else
		obj->data[id/8] |= bit;
}

static void reall()
{
	bitmap *obj = Bitmap_run_obj.obj;
	look(obj);
	for(int i=0;i<obj->size;i++)
		obj->data[i] = ~obj->data[i];
}

Bitmap Bitmap_run_obj = {
	.obj = NULL,
	.init = init,
	.count = count,
	.set = set,
	.lookAt = lookAt,
	.reset = reset,
	.reall = reall
};
