/*************************************************************************
	> File Name: main.c
	> Author: xjz
	> Mail: xjz8053@gmail.com 
	> Created Time: 2022年06月22日 星期三 13时03分58秒
 ************************************************************************/

#include <stdio.h>
#include "bitmap.h"


int main()
{
	bitmap map;
	map.data = NULL;
	Bitmap_run(map);
	Bitmap_run_obj.init(10);
	Bitmap_run_obj.reall();
	for(int i=0;i<10;i++)
	{
		Bitmap_run_obj.reset(i);
	}
	printf("%d\n",Bitmap_run_obj.count());
/*	Bitmap_run_obj.reall();
	printf("%d\n",Bitmap_run_obj.count());

	Bitmap_run_obj.reset(1);
	printf("%d\n",Bitmap_run_obj.count());
	printf("%d\n",Bitmap_run_obj.lookAt(1));	
	printf("%d\n",Bitmap_run_obj.lookAt(9));
	*/
	return 0;
}
