#include "array_list.h"

#include <stdlib.h>
#include <memory.h>

// void*
#undef ELEM_TYPE
#define ELEM_TYPE void*

#undef VAL_DEFAULT
#define VAL_DEFAULT NULL

#undef PREFIX
#define PREFIX v

#include "template/array_list_inl.c"

// int
#undef ELEM_TYPE
#define ELEM_TYPE int

#undef VAL_DEFAULT
#define VAL_DEFAULT 0

#undef PREFIX
#define PREFIX int

#include "template/array_list_inl.c"