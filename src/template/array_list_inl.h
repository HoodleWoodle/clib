// list iteration function pointer
typedef void(*PCHF(NAME, func))(ELEM_TYPE data);

// contains the information to manage an array list
typedef struct PCHS(NAME)
{
	size_t capacity;
	size_t size;
	ELEM_TYPE* data;
} PCHS(NAME_T);

// used to create a list
// if capacity is zero - the behavior is UNDEFINED
void PCHF(NAME, new)(PCHS(NAME_T)**, size_t capacity);

// used to destroy a list (the data of the list is NOT freed)
void PCHF(NAME, destroy)(PCHS(NAME_T)**);

// returns the current capacity of the list
size_t PCHF(NAME, capacity)(PCHS(NAME_T)*);

// returns the number of elements in the list
size_t PCHF(NAME, size)(PCHS(NAME_T)*);

// insert an element at the end of the list
void PCHF(NAME, push)(PCHS(NAME_T)*, ELEM_TYPE data);

// return the element at the end of the list without removing it from the list
// if no element exists - the behavior is UNDEFINED
ELEM_TYPE PCHF(NAME, peek)(PCHS(NAME_T)*);

// return the element at the a specified index without removing it from the list
// if the element with the specified index does not exists - the behavior is UNDEFINED
ELEM_TYPE PCHF(NAME, get)(PCHS(NAME_T)*, size_t index);

// remove and return the element at the end of the list
// if no element exists - the behavior is UNDEFINED
ELEM_TYPE PCHF(NAME, pop)(PCHS(NAME_T)*);

// calls for each element in the list (from first to last) the function
void PCHF(NAME, foreach)(PCHS(NAME_T)*, PCHF(NAME, func) func);

// TODO: reserve
// TODO: sort_by