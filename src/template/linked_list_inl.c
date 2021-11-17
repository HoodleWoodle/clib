/* ################ */
/* internal utility */
/* ################ */

// does NOT handle list's first and last
static PCHS(NAME_NODE_T)* PCHF(NAME, emplace_between)(PCHS(NAME_T)* list, PCHS(NAME_NODE_T)* prev, PCHS(NAME_NODE_T)* next, ELEM_TYPE data)
{
	PCHS(NAME_NODE_T)* node = (PCHS(NAME_NODE_T)*)malloc(sizeof(PCHS(NAME_NODE_T)));
	node->prev = prev;
	node->next = next;
	node->data = data;

	if (node->prev)
		node->prev->next = node;
	if (node->next)
		node->next->prev = node;

	list->size++;

	return node;
}

static PCHS(NAME_NODE_T)* PCHF(NAME, get_node_at)(PCHS(NAME_T)* list, size_t index)
{
	if (index >= list->size) return NULL;

	if (index < list->size / 2)
	{
		PCHS(NAME_NODE_T)* node = list->first;
		for (size_t i = 0; i != index; i++)
			node = node->next;
		return node;
	}
	else
	{
		PCHS(NAME_NODE_T)* node = list->last;
		for (size_t i = list->size - 1; i != index; i--)
			node = node->prev;
		return node;
	}
}

// DOES handle list's first and last
static ELEM_TYPE PCHF(NAME, remove_node)(PCHS(NAME_T)* list, PCHS(NAME_NODE_T)* node)
{
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;

	if (list->first == list->last)
		list->first = list->last = NULL;
	else if (list->first == node)
		list->first = node->next;
	else if (list->last == node)
		list->last = node->prev;

	ELEM_TYPE data = node->data;
	free(node);

	list->size--;
	return data;
}

/* ############## */
/* implementation */
/* ############## */

void PCHF(NAME, new)(PCHS(NAME_T)** list)
{
	*list = (PCHS(NAME_T)*)malloc(sizeof(PCHS(NAME_T)));
	(*list)->first = NULL;
	(*list)->last = NULL;
	(*list)->size = 0;
}

void PCHF(NAME, destroy)(PCHS(NAME_T)** list)
{
	PCHS(NAME_NODE_T)* current = (*list)->first;
	while (current)
	{
		PCHS(NAME_NODE_T)* next = current->next;
		free(current);
		current = next;
	}
	free(*list);
}

size_t PCHF(NAME, size)(PCHS(NAME_T)* list)
{
	return list->size;
}

void PCHF(NAME, push_back)(PCHS(NAME_T)* list, ELEM_TYPE data)
{
	list->last = PCHF(NAME, emplace_between)(list, list->last, NULL, data);
	if (!list->first)
		list->first = list->last;
}

void PCHF(NAME, push_front)(PCHS(NAME_T)* list, ELEM_TYPE data)
{
	list->first = PCHF(NAME, emplace_between)(list, NULL, list->first, data);
	if (!list->last)
		list->last = list->first;
}

void PCHF(NAME, insert_after)(PCHS(NAME_T)* list, size_t index, ELEM_TYPE data)
{
	PCHS(NAME_NODE_T)* prev = PCHF(NAME, get_node_at)(list, index);
	if (!prev) return; // define "undefined behavior" ...

	PCHS(NAME_NODE_T)* next = prev->next;
	PCHS(NAME_NODE_T)* node = PCHF(NAME, emplace_between)(list, prev, next, data);
	if (next == NULL)
		list->last = node;
}

void PCHF(NAME, insert_before)(PCHS(NAME_T)* list, size_t index, ELEM_TYPE data)
{
	PCHS(NAME_NODE_T)* next = PCHF(NAME, get_node_at)(list, index);
	if (!next) return; // define "undefined behavior" ...

	PCHS(NAME_NODE_T)* prev = next->prev;
	PCHS(NAME_NODE_T)* node = PCHF(NAME, emplace_between)(list, prev, next, data);
	if (prev == NULL)
		list->first = node;
}

ELEM_TYPE PCHF(NAME, peek_back)(PCHS(NAME_T)* list)
{
	if (list->size == 0) return VAL_DEFAULT; // define "undefined behavior" ...
	return list->last->data;
}

ELEM_TYPE PCHF(NAME, peek_front)(PCHS(NAME_T)* list)
{
	if (list->size == 0) return VAL_DEFAULT; // define "undefined behavior" ...
	return list->first->data;
}

ELEM_TYPE PCHF(NAME, get)(PCHS(NAME_T)* list, size_t index)
{
	PCHS(NAME_NODE_T)* node = PCHF(NAME, get_node_at)(list, index);
	if (!node) return VAL_DEFAULT; // define "undefined behavior" ...
	return node->data;
}

ELEM_TYPE PCHF(NAME, pop_back)(PCHS(NAME_T)* list)
{
	if (list->size == 0) return VAL_DEFAULT; // define "undefined behavior" ...

	PCHS(NAME_NODE_T)* node = list->last;
	return PCHF(NAME, remove_node)(list, node);
}

ELEM_TYPE PCHF(NAME, pop_front)(PCHS(NAME_T)* list)
{
	if (list->size == 0) return VAL_DEFAULT; // define "undefined behavior" ...

	PCHS(NAME_NODE_T)* node = list->first;
	return PCHF(NAME, remove_node)(list, node);
}

ELEM_TYPE PCHF(NAME, remove)(PCHS(NAME_T)* list, size_t index)
{
	PCHS(NAME_NODE_T)* node = PCHF(NAME, get_node_at)(list, index);
	if (!node) return VAL_DEFAULT; // define "undefined behavior" ...

	return PCHF(NAME, remove_node)(list, node);
}

void PCHF(NAME, foreach)(PCHS(NAME_T)* list, PCHF(NAME, func) func)
{
	for (PCHS(NAME_NODE_T)* current = list->first; current; current = current->next)
		func(current->data);
}