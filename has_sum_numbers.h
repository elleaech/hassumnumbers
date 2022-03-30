#ifndef __HAS_SUM_NUMBERS_H__
#define __HAS_SUM_NUMBERS_H__

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int8_t vsBool;

vsBool hasSumNumbers(const int8_t *listOfNumbers, const int32_t listSize, const int8_t *sumResult);

#endif /* #ifndef __HAS_SUM_NUMBERS_H__ */
