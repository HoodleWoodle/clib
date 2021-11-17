#ifndef ELEM_TYPE_ASSIGN
#define ELEM_TYPE_ASSIGN(x, y) x = y
#endif // ELEM_TYPE_ASSIGN

// list iteration function pointer
typedef void(*PCHI(ll_func))(ELEM_TYPE data);

// contains the information for an element in a doubly linked list
typedef struct PCHI(lln)
{
	struct PCHI(lln)* prev;
	struct PCHI(lln)* next;
	ELEM_TYPE data;
} PCHI(lln_t);

// contains the information to manage a doubly linked list
typedef struct PCHI(ll)
{
	PCHI(lln_t)* first;
	PCHI(lln_t)* last;
	size_t size;
} PCHI(ll_t);

// used to initialize a list
void PCHI(ll_init)(PCHI(ll_t)**);

// used to free a list (the data of the list is NOT freed)
void PCHI(ll_free)(PCHI(ll_t)**);

// returns the number of elements in the list
size_t PCHI(ll_size)(PCHI(ll_t)* ll);

// insert an element at the end of the list
void PCHI(ll_push_back)(PCHI(ll_t)*, ELEM_TYPE data);

// insert an element at the beginning of the list
void PCHI(ll_push_front)(PCHI(ll_t)*, ELEM_TYPE data);

// insert an element after the element with the specified index
// if no element with the specified index exists - the behavior is UNDEFINED
void PCHI(ll_insert_after)(PCHI(ll_t)*, size_t index, ELEM_TYPE data);

// insert an element before the element with the specified index
// if no element with the specified index exists - the behavior is UNDEFINED
void PCHI(ll_insert_before)(PCHI(ll_t)*, size_t index, ELEM_TYPE data);

// return the element at the end of the list without removing it from the list
// if no element exists - the behavior is UNDEFINED
ELEM_TYPE PCHI(ll_peek_back)(PCHI(ll_t)*);

// return the element at the beginning of the list without removing it from the list
// if no element exists - the behavior is UNDEFINED
ELEM_TYPE PCHI(ll_peek_front)(PCHI(ll_t)*);

// return the element at the a specified index without removing it from the list
// if the element with the specified index does not exists - the behavior is UNDEFINED
ELEM_TYPE PCHI(ll_get)(PCHI(ll_t)*, size_t index);

// remove and return the element at the end of the list
// if no element exists - the behavior is UNDEFINED
ELEM_TYPE PCHI(ll_pop_back)(PCHI(ll_t)*);

// remove and return the element at the beginning of the list
// if no element exists - the behavior is UNDEFINED
ELEM_TYPE PCHI(ll_pop_front)(PCHI(ll_t)*);

// remove and return the element at a specified index
// if the element with the specified index does not exists - the behavior is UNDEFINED
ELEM_TYPE PCHI(ll_remove)(PCHI(ll_t)*, size_t index);

// calls for each element in the list (from first to last) the function
void PCHI(ll_foreach)(PCHI(ll_t)*, PCHI(ll_func) func);

// TODO: sort_by