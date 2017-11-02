#ifndef HEADERS_H_
#define HEADERS_H_

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cfloat>
#include <unistd.h>
#include <iterator>
#include <vector>

static inline void full_delete(void *&ptr)
{
	free(ptr);
	ptr = 0;
}

using namespace std;

#endif
