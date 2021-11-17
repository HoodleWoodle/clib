#include "linked_list.h"

#include <stdlib.h>

// void* list
#undef ELEM_TYPE
#define ELEM_TYPE void*
#undef ELEM_TYPE_ASSIGN

#undef VAL_DEFAULT
#define VAL_DEFAULT NULL

#undef PREFIX
#define PREFIX v

#include "template/linked_list_inl.c"

// int list
#undef ELEM_TYPE
#define ELEM_TYPE int
#undef ELEM_TYPE_ASSIGN

#undef VAL_DEFAULT
#define VAL_DEFAULT 0

#undef PREFIX
#define PREFIX int

#include "template/linked_list_inl.c"