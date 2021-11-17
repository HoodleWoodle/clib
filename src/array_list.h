#ifndef HW_ARRAY_LIST_H
#define HW_ARRAY_LIST_H

#include "common.h"

#define NAME array
#define NAME_T JOIN(NAME, _t)

// void*
#undef ELEM_TYPE
#define ELEM_TYPE void*

#undef PREFIX
#define PREFIX v

#include "template/array_list_inl.h"

// int
#undef ELEM_TYPE
#define ELEM_TYPE int

#undef PREFIX
#define PREFIX int

#include "template/array_list_inl.h"

#endif // HW_ARRAY_LIST_H