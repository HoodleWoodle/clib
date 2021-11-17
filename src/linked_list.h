#ifndef HW_LINKED_LIST_H
#define HW_LINKED_LIST_H

#include "common.h"

#define NAME list
#define NAME_T JOIN(NAME, _t)

#define NAME_NODE JOIN(NAME, n)
#define NAME_NODE_T JOIN(NAME_NODE, _t)

// void*
#undef ELEM_TYPE
#define ELEM_TYPE void*

#undef PREFIX
#define PREFIX v

#include "template/linked_list_inl.h"

// int
#undef ELEM_TYPE
#define ELEM_TYPE int

#undef PREFIX
#define PREFIX int

#include "template/linked_list_inl.h"

#endif // HW_LINKED_LIST_H