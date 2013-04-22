/*
 * find_start_code.c
 *
 *  Created on: 2013-4-22
 *      Author: keym
 */


#include"find_start_code.h"
#include"libavcodec/mpegvideo.h"
#include<assert.h>
#include<stdio.h>


int find_start_code(AVPacket *pkt)
{

	uint8_t pict_type_tmp;
	const uint8_t *buf_tmp = pkt->data;
	int buf_size = pkt->size;
	const uint8_t *buf_ptr_tmp = buf_tmp; //f_ptr是缓冲区的指针，很重要
	const uint8_t *buf_end_tmp = buf_tmp + buf_size;
	uint32_t start_code = -1;
	for(;;)
	{
		buf_ptr_tmp = ff_find_start_code(buf_ptr_tmp,buf_end_tmp, &start_code);
		if(start_code == 0x00000100)
		{
			//查找帧类型的标记，如果为I帧，返回1，否则返回0
			buf_ptr_tmp += 1;
			pict_type_tmp = *buf_ptr_tmp;
			pict_type_tmp &= 0x38;
			pict_type_tmp = pict_type_tmp >>3;
			break;
		}
	}
	if(pict_type_tmp == 1)
		return 1;
	else
		return 0;
}
