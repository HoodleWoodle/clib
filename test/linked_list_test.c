#include <assert.h>
#include <stdio.h>

#include "linked_list.h"

#define ASSERT_LEN(len)		assert(hw_int_list_size(list) == len)
#define ASSERT_AT(idx, val)	assert(hw_int_list_get(list, idx) == val)

#define ASSERT_0				ASSERT_LEN(0)
#define ASSERT_1(a)				ASSERT_LEN(1); ASSERT_AT(0, a)
#define ASSERT_2(a, b)			ASSERT_LEN(2); ASSERT_AT(0, a); ASSERT_AT(1, b)
#define ASSERT_3(a, b, c)		ASSERT_LEN(3); ASSERT_AT(0, a); ASSERT_AT(1, b); ASSERT_AT(2, c)
#define ASSERT_4(a, b, c, d)	ASSERT_LEN(4); ASSERT_AT(0, a); ASSERT_AT(1, b); ASSERT_AT(2, c); ASSERT_AT(3, d)
#define ASSERT_5(a, b, c, d, e)	ASSERT_LEN(5); ASSERT_AT(0, a); ASSERT_AT(1, b); ASSERT_AT(2, c); ASSERT_AT(3, d); ASSERT_AT(4, e)

#define DEBUG() hw_int_list_foreach(list, print_int)

void print_int(int data) { printf("%i\n", data); }

int main(void)
{
	int idx;

	hw_int_list_t* list;
	hw_int_list_new(&list);						/* DEBUG(); */ ASSERT_LEN(0);

	hw_int_list_push_back(list, 4);				/* DEBUG(); */ ASSERT_1(4);
	hw_int_list_push_back(list, 5);				/* DEBUG(); */ ASSERT_2(4, 5);
	hw_int_list_push_back(list, 7);				/* DEBUG(); */ ASSERT_3(4, 5, 7);

	hw_int_list_push_front(list, 1);			/* DEBUG(); */ ASSERT_4(1, 4, 5, 7);
	hw_int_list_push_front(list, 6);			/* DEBUG(); */ ASSERT_5(6, 1, 4, 5, 7);

	hw_int_list_remove(list, 0);				/* DEBUG(); */ ASSERT_4(1, 4, 5, 7);
	hw_int_list_remove(list, 2);				/* DEBUG(); */ ASSERT_3(1, 4, 7);

	idx = hw_int_list_size(list) - 1;
	hw_int_list_insert_before(list, idx, 3);	/* DEBUG(); */ ASSERT_4(1, 4, 3, 7);

	idx = hw_int_list_size(list) - 1;
	hw_int_list_insert_after(list, idx, 8);		/* DEBUG(); */ ASSERT_5(1, 4, 3, 7, 8);

	hw_int_list_pop_front(list);				/* DEBUG(); */ ASSERT_4(4, 3, 7, 8);

	hw_int_list_destroy(&list);

	printf("TEST - SUCCESS\n");
	return 0;
}