/* ################ */
/* internal utility */
/* ################ */

// does NOT handle list's first and last
static PCHS(NAME_NODE_T)* PCHF(NAME, emplace_between)(PCHS(NAME_T)* ll, PCHS(NAME_NODE_T)* prev, PCHS(NAME_NODE_T)* next, ELEM_TYPE data)
{
	PCHS(NAME_NODE_T)* node = (PCHS(NAME_NODE_T)*)malloc(sizeof(PCHS(NAME_NODE_T)));
	node->prev = prev;
	node->next = next;
	node->data = data;

	if (node->prev)
		node->prev->next = node;
	if (node->next)
		node->next->prev = node;

	ll->size++;

	return node;
}

static PCHS(NAME_NODE_T)* PCHF(NAME, get_node_at)(PCHS(NAME_T)* ll, size_t index)
{
	if (index >= ll->size) return NULL;

	if (index < ll->size / 2)
	{
		PCHS(NAME_NODE_T)* node = ll->first;
		for (size_t i = 0; i != index; i++)
			node = node->next;
		return node;
	}
	else
	{
		PCHS(NAME_NODE_T)* node = ll->last;
		for (size_t i = ll->size - 1; i != index; i--)
			node = node->prev;
		return node;
	}
}

// DOES handle ll->first and ll->last
static ELEM_TYPE PCHF(NAME, remove_node)(PCHS(NAME_T)* ll, PCHS(NAME_NODE_T)* node)
{
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;

	if (ll->first == ll->last)
		ll->first = ll->last = NULL;
	else if (ll->first == node)
		ll->first = node->next;
	else if (ll->last == node)
		ll->last = node->prev;

	ELEM_TYPE data = node->data;
	free(node);

	ll->size--;
	return data;
}

/* ############## */
/* implementation */
/* ############## */

void PCHF(NAME, new)(PCHS(NAME_T)** ll)
{
	*ll = (PCHS(NAME_T)*)malloc(sizeof(PCHS(NAME_T)));
	(*ll)->first = NULL;
	(*ll)->last = NULL;
	(*ll)->size = 0;
}

void PCHF(NAME, destroy)(PCHS(NAME_T)** ll)
{
	PCHS(NAME_NODE_T)* current = (*ll)->first;
	while (current)
	{
		PCHS(NAME_NODE_T)* next = current->next;
		free(current);
		current = next;
	}
	free(*ll);
}

size_t PCHF(NAME, size)(PCHS(NAME_T)* ll)
{
	return ll->size;
}

void PCHF(NAME, push_back)(PCHS(NAME_T)* ll, ELEM_TYPE data)
{
	ll->last = PCHF(NAME, emplace_between)(ll, ll->last, NULL, data);
	if (!ll->first)
		ll->first = ll->last;
}

void PCHF(NAME, push_front)(PCHS(NAME_T)* ll, ELEM_TYPE data)
{
	ll->first = PCHF(NAME, emplace_between)(ll, NULL, ll->first, data);
	if (!ll->last)
		ll->last = ll->first;
}

void PCHF(NAME, insert_after)(PCHS(NAME_T)* ll, size_t index, ELEM_TYPE data)
{
	PCHS(NAME_NODE_T)* prev = PCHF(NAME, get_node_at)(ll, index);
	if (!prev) return; // define "undefined behavior" ...

	PCHS(NAME_NODE_T)* next = prev->next;
	PCHS(NAME_NODE_T)* node = PCHF(NAME, emplace_between)(ll, prev, next, data);
	if (next == NULL)
		ll->last = node;
}

void PCHF(NAME, insert_before)(PCHS(NAME_T)* ll, size_t index, ELEM_TYPE data)
{
	PCHS(NAME_NODE_T)* next = PCHF(NAME, get_node_at)(ll, index);
	if (!next) return; // define "undefined behavior" ...

	PCHS(NAME_NODE_T)* prev = next->prev;
	PCHS(NAME_NODE_T)* node = PCHF(NAME, emplace_between)(ll, prev, next, data);
	if (prev == NULL)
		ll->first = node;
}

ELEM_TYPE PCHF(NAME, peek_back)(PCHS(NAME_T)* ll)
{
	if (ll->size == 0) return VAL_DEFAULT; // define "undefined behavior" ...
	return ll->last->data;
}

ELEM_TYPE PCHF(NAME, peek_front)(PCHS(NAME_T)* ll)
{
	if (ll->size == 0) return VAL_DEFAULT; // define "undefined behavior" ...
	return ll->first->data;
}

ELEM_TYPE PCHF(NAME, get)(PCHS(NAME_T)* ll, size_t index)
{
	PCHS(NAME_NODE_T)* node = PCHF(NAME, get_node_at)(ll, index);
	if (!node) return VAL_DEFAULT; // define "undefined behavior" ...
	return node->data;
}

ELEM_TYPE PCHF(NAME, pop_back)(PCHS(NAME_T)* ll)
{
	if (ll->size == 0) return VAL_DEFAULT; // define "undefined behavior" ...

	PCHS(NAME_NODE_T)* node = ll->last;
	return PCHF(NAME, remove_node)(ll, node);
}

ELEM_TYPE PCHF(NAME, pop_front)(PCHS(NAME_T)* ll)
{
	if (ll->size == 0) return VAL_DEFAULT; // define "undefined behavior" ...

	PCHS(NAME_NODE_T)* node = ll->first;
	return PCHF(NAME, remove_node)(ll, node);
}

ELEM_TYPE PCHF(NAME, remove)(PCHS(NAME_T)* ll, size_t index)
{
	PCHS(NAME_NODE_T)* node = PCHF(NAME, get_node_at)(ll, index);
	if (!node) return VAL_DEFAULT; // define "undefined behavior" ...

	return PCHF(NAME, remove_node)(ll, node);
}

void PCHF(NAME, foreach)(PCHS(NAME_T)* ll, PCHF(NAME, func) func)
{
	for (PCHS(NAME_NODE_T)* current = ll->first; current; current = current->next)
		func(current->data);
}