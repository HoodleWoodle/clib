/* ################ */
/* internal utility */
/* ################ */

// does NOT handle ll->first and ll->last
static PCHI(lln_t)* PCHI(ll_emplace_between)(PCHI(ll_t)* ll, PCHI(lln_t)* prev, PCHI(lln_t)* next, ELEM_TYPE data)
{
	PCHI(lln_t)* node = (PCHI(lln_t)*)malloc(sizeof(PCHI(lln_t)));
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

static PCHI(lln_t)* PCHI(ll_get_node_at)(PCHI(ll_t)* ll, size_t index)
{
	if (index >= ll->size) return NULL;

	if (index < ll->size / 2)
	{
		PCHI(lln_t)* node = ll->first;
		for (size_t i = 0; i != index; i++)
			node = node->next;
		return node;
	}
	else
	{
		PCHI(lln_t)* node = ll->last;
		for (size_t i = ll->size - 1; i != index; i--)
			node = node->prev;
		return node;
	}
}

// DOES handle ll->first and ll->last
static ELEM_TYPE PCHI(ll_remove_node)(PCHI(ll_t)* ll, PCHI(lln_t)* node)
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

void PCHI(ll_init)(PCHI(ll_t)** ll)
{
	*ll = (PCHI(ll_t)*)malloc(sizeof(PCHI(ll_t)));
	(*ll)->first = NULL;
	(*ll)->last = NULL;
	(*ll)->size = 0;
}

void PCHI(ll_free)(PCHI(ll_t)** ll)
{
	PCHI(lln_t)* current = (*ll)->first;
	while (current)
	{
		PCHI(lln_t)* next = current->next;
		free(current);
		current = next;
	}
	free(*ll);
}

size_t PCHI(ll_size)(PCHI(ll_t)* ll)
{
	return ll->size;
}

void PCHI(ll_push_back)(PCHI(ll_t)* ll, ELEM_TYPE data)
{
	ll->last = PCHI(ll_emplace_between)(ll, ll->last, NULL, data);
	if (!ll->first)
		ll->first = ll->last;
}

void PCHI(ll_push_front)(PCHI(ll_t)* ll, ELEM_TYPE data)
{
	ll->first = PCHI(ll_emplace_between)(ll, NULL, ll->first, data);
	if (!ll->last)
		ll->last = ll->first;
}

void PCHI(ll_insert_after)(PCHI(ll_t)* ll, size_t index, ELEM_TYPE data)
{
	PCHI(lln_t)* prev = PCHI(ll_get_node_at)(ll, index);
	if (!prev) return; // define "undefined behavior" ...

	PCHI(lln_t)* next = prev->next;
	PCHI(lln_t)* node = PCHI(ll_emplace_between)(ll, prev, next, data);
	if (next == NULL)
		ll->last = node;
}

void PCHI(ll_insert_before)(PCHI(ll_t)* ll, size_t index, ELEM_TYPE data)
{
	PCHI(lln_t)* next = PCHI(ll_get_node_at)(ll, index);
	if (!next) return; // define "undefined behavior" ...

	PCHI(lln_t)* prev = next->prev;
	PCHI(lln_t)* node = PCHI(ll_emplace_between)(ll, prev, next, data);
	if (prev == NULL)
		ll->first = node;
}

ELEM_TYPE PCHI(ll_peek_back)(PCHI(ll_t)* ll)
{
	if (ll->size == 0) return VAL_DEFAULT; // define "undefined behavior" ...
	return ll->last->data;
}

ELEM_TYPE PCHI(ll_peek_front)(PCHI(ll_t)* ll)
{
	if (ll->size == 0) return VAL_DEFAULT; // define "undefined behavior" ...
	return ll->first->data;
}

ELEM_TYPE PCHI(ll_get)(PCHI(ll_t)* ll, size_t index)
{
	PCHI(lln_t)* node = PCHI(ll_get_node_at)(ll, index);
	if (!node) return VAL_DEFAULT; // define "undefined behavior" ...
	return node->data;
}

ELEM_TYPE PCHI(ll_pop_back)(PCHI(ll_t)* ll)
{
	if (ll->size == 0) return VAL_DEFAULT; // define "undefined behavior" ...

	PCHI(lln_t)* node = ll->last;
	return PCHI(ll_remove_node)(ll, node);
}

ELEM_TYPE PCHI(ll_pop_front)(PCHI(ll_t)* ll)
{
	if (ll->size == 0) return VAL_DEFAULT; // define "undefined behavior" ...

	PCHI(lln_t)* node = ll->first;
	return PCHI(ll_remove_node)(ll, node);
}

ELEM_TYPE PCHI(ll_remove)(PCHI(ll_t)* ll, size_t index)
{
	PCHI(lln_t)* node = PCHI(ll_get_node_at)(ll, index);
	if (!node) return VAL_DEFAULT; // define "undefined behavior" ...

	return PCHI(ll_remove_node)(ll, node);
}

void PCHI(ll_foreach)(PCHI(ll_t)* ll, PCHI(ll_func) func)
{
	for (PCHI(lln_t)* current = ll->first; current; current = current->next)
		func(current->data);
}