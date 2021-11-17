#ifndef ELEM_TYPE_ASSIGN
#define ELEM_TYPE_ASSIGN(x, y) x = y
#endif // ELEM_TYPE_ASSIGN

// list iteration function pointer
typedef void(*PCHF(NAME, func))(ELEM_TYPE data);

// contains the information for an element in a doubly linked list
typedef struct PCHS(NAME_NODE)
{
	struct PCHS(NAME_NODE)* prev;
	struct PCHS(NAME_NODE)* next;
	ELEM_TYPE data;
} PCHS(NAME_NODE_T);

// contains the information to manage a doubly linked list
typedef struct PCHS(NAME)
{
	PCHS(NAME_NODE_T)* first;
	PCHS(NAME_NODE_T)* last;
	size_t size;
} PCHS(NAME_T);

// used to initialize a list
void PCHF(NAME, init)(PCHS(NAME_T)**);

// used to destroy a list (the data of the list is NOT freed)
void PCHF(NAME, destroy)(PCHS(NAME_T)**);

// returns the number of elements in the list
size_t PCHF(NAME, size)(PCHS(NAME_T)* NAME);

// insert an element at the end of the list
void PCHF(NAME, push_back)(PCHS(NAME_T)*, ELEM_TYPE data);

// insert an element at the beginning of the list
void PCHF(NAME, push_front)(PCHS(NAME_T)*, ELEM_TYPE data);

// insert an element after the element with the specified index
// if no element with the specified index exists - the behavior is UNDEFINED
void PCHF(NAME, insert_after)(PCHS(NAME_T)*, size_t index, ELEM_TYPE data);

// insert an element before the element with the specified index
// if no element with the specified index exists - the behavior is UNDEFINED
void PCHF(NAME, insert_before)(PCHS(NAME_T)*, size_t index, ELEM_TYPE data);

// return the element at the end of the list without removing it from the list
// if no element exists - the behavior is UNDEFINED
ELEM_TYPE PCHF(NAME, peek_back)(PCHS(NAME_T)*);

// return the element at the beginning of the list without removing it from the list
// if no element exists - the behavior is UNDEFINED
ELEM_TYPE PCHF(NAME, peek_front)(PCHS(NAME_T)*);

// return the element at the a specified index without removing it from the list
// if the element with the specified index does not exists - the behavior is UNDEFINED
ELEM_TYPE PCHF(NAME, get)(PCHS(NAME_T)*, size_t index);

// remove and return the element at the end of the list
// if no element exists - the behavior is UNDEFINED
ELEM_TYPE PCHF(NAME, pop_back)(PCHS(NAME_T)*);

// remove and return the element at the beginning of the list
// if no element exists - the behavior is UNDEFINED
ELEM_TYPE PCHF(NAME, pop_front)(PCHS(NAME_T)*);

// remove and return the element at a specified index
// if the element with the specified index does not exists - the behavior is UNDEFINED
ELEM_TYPE PCHF(NAME, remove)(PCHS(NAME_T)*, size_t index);

// caNAMEs for each element in the list (from first to last) the function
void PCHF(NAME, foreach)(PCHS(NAME_T)*, PCHF(NAME, func) func);

// TODO: sort_by