#include <assert.h>
#include <stdio.h>

#include "linked_list.h"

#define ASSERT_LEN(len)		assert(hw_int_list_size(l) == len)
#define ASSERT_AT(idx, val)	assert(hw_int_list_get(l, idx) == val)

#define ASSERT_0				ASSERT_LEN(0)
#define ASSERT_1(a)				ASSERT_LEN(1); ASSERT_AT(0, a)
#define ASSERT_2(a, b)			ASSERT_LEN(2); ASSERT_AT(0, a); ASSERT_AT(1, b)
#define ASSERT_3(a, b, c)		ASSERT_LEN(3); ASSERT_AT(0, a); ASSERT_AT(1, b); ASSERT_AT(2, c)
#define ASSERT_4(a, b, c, d)	ASSERT_LEN(4); ASSERT_AT(0, a); ASSERT_AT(1, b); ASSERT_AT(2, c); ASSERT_AT(3, d)
#define ASSERT_5(a, b, c, d, e)	ASSERT_LEN(5); ASSERT_AT(0, a); ASSERT_AT(1, b); ASSERT_AT(2, c); ASSERT_AT(3, d); ASSERT_AT(4, e)

#define DEBUG() hw_int_ll_foreach(list, print_int)

void print_int(int data) { printf("%i\n", data); }

int main(void)
{
	int idx;

	hw_int_list_t* l;
	hw_int_list_init(&l);						/* DEBUG(); */ ASSERT_LEN(0);

	hw_int_list_push_back(l, 4);				/* DEBUG(); */ ASSERT_1(4);
	hw_int_list_push_back(l, 5);				/* DEBUG(); */ ASSERT_2(4, 5);
	hw_int_list_push_back(l, 7);				/* DEBUG(); */ ASSERT_3(4, 5, 7);

	hw_int_list_push_front(l, 1);				/* DEBUG(); */ ASSERT_4(1, 4, 5, 7);
	hw_int_list_push_front(l, 6);				/* DEBUG(); */ ASSERT_5(6, 1, 4, 5, 7);

	hw_int_list_remove(l, 0);					/* DEBUG(); */ ASSERT_4(1, 4, 5, 7);
	hw_int_list_remove(l, 2);					/* DEBUG(); */ ASSERT_3(1, 4, 7);

	idx = hw_int_list_size(l) - 1;
	hw_int_list_insert_before(l, idx, 3);		/* DEBUG(); */ ASSERT_4(1, 4, 3, 7);

	idx = hw_int_list_size(l) - 1;
	hw_int_list_insert_after(l, idx, 8);		/* DEBUG(); */ ASSERT_5(1, 4, 3, 7, 8);

	hw_int_list_pop_front(l);					/* DEBUG(); */ ASSERT_4(4, 3, 7, 8);

	hw_int_list_destroy(&l);
	return 0;
}