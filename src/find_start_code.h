/*
 * find_start_code.h
 *
 *  Created on: 2013-4-22
 *      Author: keym
 */

#ifndef FIND_START_CODE_H_
#define FIND_START_CODE_H_

#include"libavcodec/avcodec.h"
#include<assert.h>

int find_start_code(AVPacket *pkt);

#endif /* FIND_START_CODE_H_ */
