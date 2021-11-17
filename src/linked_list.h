#ifndef HW_LINKED_LIST_H
#define HW_LINKED_LIST_H

#include "common.h"

// void* list
#undef ELEM_TYPE
#define ELEM_TYPE void*

#undef PREFIX
#define PREFIX v

#include "template/linked_list_inl.h"

// int list
#undef ELEM_TYPE
#define ELEM_TYPE int

#undef PREFIX
#define PREFIX int

#include "template/linked_list_inl.h"

#endif // HW_LINKED_LIST_H