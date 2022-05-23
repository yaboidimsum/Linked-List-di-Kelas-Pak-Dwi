//DLNNC - Double Linked List non Circular
//Dimas Prihady Setyawan NRP: 5025211184//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct dnode_t {
    int data;
    struct dnode_t      \
        *next,
        *prev;
} DoubleListNode;

typedef struct dlist_t {
    DoubleListNode           \
        *head,
        *tail;
} DoubleList;

void init(DoubleList *dList_t)
{
    dList_t->head = dList_t->tail = NULL;
}


int is_Empty(DoubleList *dList_t)
{
	if (dList_t->tail == NULL) return 1;
	else return 0;
}

void insert_Depan(DoubleList *dList_t, int data_new)
{
    DoubleListNode *new = (DoubleListNode*) malloc(sizeof(DoubleListNode));
    new->data = data_new;
    new->next = NULL;
    new->prev = NULL;

    if (is_Empty(dList_t) == 1)
    {
       dList_t->head = dList_t->tail = new;
    }

    else
    {
        new->next = dList_t->head;
        dList_t->head->prev = new;
        dList_t->head = new;
    }

    printf("Data %d masuk dari depan\n", data_new);
}

void insert_Belakang(DoubleList *dList_t, int data_new)
{
    DoubleListNode *new = (DoubleListNode*) malloc(sizeof(DoubleListNode));
    new->data = data_new;
    new->next = NULL;
    new->prev = NULL;

    if (is_Empty(dList_t) == 1)
    {
        dList_t->head = dList_t->tail = new;
    }

    else
    {
        dList_t->tail->next = new;
        new->prev = dList_t->tail;
        dList_t->tail = new;
    }

    printf("Data %d masuk dari belakang\n", data_new);
}

void tampil(DoubleList *dList_t)
{
    DoubleListNode *temp;
    temp = dList_t->head;

    printf("Data tersimpan: ");

    if (is_Empty(dList_t) == 1)
    {
        printf("Masih kosong\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void hapus_Depan(DoubleList *dList_t)
{
	DoubleListNode *del;
	int d;

	if (is_Empty(dList_t) == 1)
    {
        printf("Tidak ada Data\n");
        return;
	}

    if (dList_t->head != dList_t->tail)
    {
        del = dList_t->head;
        d = del->data;
        dList_t->head = dList_t->head->next;
        dList_t->head->prev = NULL;
        free(del);
    }

    else
    {
        d = dList_t->tail->data;
        dList_t->head = dList_t->tail = NULL;
    }

    printf("Data %d terhapus dari depan\n", d);
}

void hapus_Belakang(DoubleList *dList_t)
{
	DoubleListNode *del;
	int d;

	if (is_Empty(dList_t) == 1)
    {
        printf("Tidak ada Data\n");
        return;
	}

    if (dList_t->head != dList_t->tail)
    {
        del = dList_t->tail;
        d = del->data;
        dList_t->tail = dList_t->tail->prev;
        dList_t->tail->next = NULL;
        free(del);
	 }

     else
     {
		del = dList_t->head;
        d = del->data;
        dList_t->head = dList_t->tail = NULL;
        free(del);
	 }

	 printf("Data %d terhapus dari belakang\n", d);
}

void clear(DoubleList *dList_t)
{
	DoubleListNode *temp, *del;
	temp = dList_t->head;

	while (temp != NULL)
    {
		del = temp;
		temp = temp->next;
		free(del);
	}

	dList_t->head = NULL;
    dList_t->tail = NULL;
}

void search_data(DoubleList *dList_t, int dataIndex)
{
    if (is_Empty(dList_t) == 1)
    {
        printf("Tidak ada Data\n");
    }

    DoubleListNode *temp = dList_t->head;
    int i = 0;

    while (temp->next != NULL && i < dataIndex)
    {
        temp = temp->next;
        i++;
    }

    printf("Data pada index %d adalah %d\n", i+1, temp->data);
}

void remove_Data(DoubleList *dList_t, int data)
{
    if (is_Empty(dList_t) == 1)
    {
        printf("Masih kosong\n");
        return;
    }

    DoubleListNode *temp, *before;
    temp = dList_t->tail;

    if (temp->data == data)
    {
        hapus_Belakang(dList_t);
        printf("Data %d sudah terhapus \n", data);
        return;
    }

    temp = dList_t->head;

    if (temp->data == data)
    {
        hapus_Depan(dList_t);
        printf("Data %d sudah terhapus \n", data);
        return;
    }

    while (temp != NULL && temp->data != data)
    {
        before = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Data tidak ditemukan\n");
        return;
    }

    before->next = temp->next;
    free(temp);
    printf("Data %d berhasil dihapus!\n", data);
}

void insert_After(DoubleList *dList_t, int point, int newData)
{
    if (point == dList_t->tail->data)
    {
        insert_Belakang(dList_t, newData);
        printf("Data %d masuk sebelum %d\n", newData, point);
        return;
    }

    DoubleListNode *temp = dList_t->head;

    while (temp->next != NULL && temp->data != point)
    {
        temp = temp->next;
    }

    if (temp->next == NULL && temp->data != point)
    {
        printf("Data tidak ditemukan\n");
    }

    DoubleListNode *new = (DoubleListNode*) malloc(sizeof(DoubleListNode));
    new->data = newData;
    new->next = temp->next;
    temp->next->prev = new;
    new->prev = temp;
    temp->next = new;
    printf("Data %d masuk setelah %d\n", newData, point);
}

void insert_Before(DoubleList *dList_t, int point, int newData)
{
    if (point == dList_t->head->data)
    {
        insert_Depan(dList_t, newData);
        printf("Data %d masuk sebelum %d\n", newData, point);
        return;
    }

    DoubleListNode *temp = dList_t->head;

    while (temp->next != NULL)
    {
        if (temp->next->data == point)
        {
            break;
        }

        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        printf("Data tidak ditemukan\n");
    }

    DoubleListNode *new = (DoubleListNode*) malloc(sizeof(DoubleListNode));
    new->data = newData;
    new->next = temp->next;
    temp->next->prev = new;
    temp->next = new;
    new->prev = temp;
    printf("Data %d masuk sebelum %d\n", newData, point);
}

int main()
{
    DoubleList dlist;
    init(&dlist);

    tampil(&dlist);

    insert_Depan(&dlist, 10);
    insert_Depan(&dlist, 20);
    insert_Depan(&dlist, 30);
    insert_Depan(&dlist, 200);

    remove_Data(&dlist, 30);
    remove_Data(&dlist, 20);
    tampil(&dlist);

    insert_Belakang(&dlist, 40);
    insert_Belakang(&dlist, 50);
    insert_Belakang(&dlist, 300);
    insert_After(&dlist, 50, 60);
    insert_Before(&dlist, 40, 30);

    tampil(&dlist);
    search_data(&dlist, 2);
    search_data(&dlist, 3);

    hapus_Belakang(&dlist);
    hapus_Depan(&dlist);

    tampil(&dlist);

    clear(&dlist);

    tampil(&dlist);

    printf("\nDLNNC - Double Linked List non Circular");
}
