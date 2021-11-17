/* ################ */
/* internal utility */
/* ################ */

static void PCHF(NAME, adjust_size)(PCHS(NAME_T)* list, size_t new_size)
{
	if (new_size >= list->capacity)
	{
		do {
			list->capacity = list->capacity * 2;

			ELEM_TYPE* new_data = (ELEM_TYPE*)malloc(list->capacity * sizeof(ELEM_TYPE));
			memcpy(new_data, list->data, list->size * sizeof(ELEM_TYPE));
			free(list->data);

			list->data = new_data;
		} while (new_size >= list->capacity);
	}

	// TODO: reduce size
}

/* ############## */
/* implementation */
/* ############## */

void PCHF(NAME, new)(PCHS(NAME_T)** list, size_t capacity)
{
	if (capacity == 0) return; // define "undefined behavior" ...

	*list = (PCHS(NAME_T)*)malloc(sizeof(PCHS(NAME_T)));
	(*list)->capacity = capacity;
	(*list)->size = 0;
	(*list)->data = (ELEM_TYPE*)malloc((*list)->capacity * sizeof(ELEM_TYPE));
}

void PCHF(NAME, destroy)(PCHS(NAME_T)** list)
{
	free((*list)->data);
	free(*list);
}

size_t PCHF(NAME, capacity)(PCHS(NAME_T)* list)
{
	return list->capacity;
}

size_t PCHF(NAME, size)(PCHS(NAME_T)* list)
{
	return list->size;
}

void PCHF(NAME, push)(PCHS(NAME_T)* list, ELEM_TYPE data)
{
	PCHF(NAME, adjust_size)(list, list->size + 1);

	list->data[list->size++] = data;
}

ELEM_TYPE PCHF(NAME, peek)(PCHS(NAME_T)* list)
{
	if (list->size == 0) return VAL_DEFAULT; // define "undefined behavior" ...

	return list->data[list->size - 1];
}

ELEM_TYPE PCHF(NAME, get)(PCHS(NAME_T)* list, size_t index)
{
	if (list->size <= index) return VAL_DEFAULT; // define "undefined behavior" ...

	return list->data[index];
}

ELEM_TYPE PCHF(NAME, pop)(PCHS(NAME_T)* list)
{
	if (list->size == 0) return VAL_DEFAULT; // define "undefined behavior" ...

	ELEM_TYPE result = list->data[--list->size];

	PCHF(NAME, adjust_size)(list, list->size);

	return result;
}

void PCHF(NAME, foreach)(PCHS(NAME_T)* list, PCHF(NAME, func) func)
{
	for (size_t i = 0; i < list->size; i++)
		func(list->data[i]);
}