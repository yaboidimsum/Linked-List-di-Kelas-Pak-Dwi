
//SLNNC - Single Linked List non Circular Head and Tail
//Dimas Prihady Setyawan NRP: 5025211184//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct snode_t {
    int data;
    struct snode_t *next;
} SinglyListNode;

typedef struct slist_t {
    SinglyListNode *head;
    SinglyListNode *tail;
} SinglyList;

void init(SinglyList *List)
{
    List->head = NULL;
    List->tail = NULL;
}

int isEmpty(SinglyList *List)
{
	if (List->tail == NULL) return 1;
	else return 0;
}

void insert_Depan(SinglyList *List, int data_new)
{
    SinglyListNode *new = (SinglyListNode*) malloc(sizeof(SinglyListNode));
    new->data = data_new;
    new->next = NULL;

    if (isEmpty(List) == 1)
    {
        List->head = List->tail = new;
        List->tail->next = NULL;
    }

    else
    {
        new->next = List->head;
        List->head = new;
    }

    printf("Data %d masuk dari depan\n", data_new);
}

void insert_Belakang(SinglyList *List, int data_new)
{
    SinglyListNode *new = (SinglyListNode*) malloc(sizeof(SinglyListNode));
    new->data = data_new;
    new->next = NULL;

    if (isEmpty(List) == 1)
    {
        List->head = List->tail = new;
        List->tail->next = NULL;
    }

    else
    {
        List->tail->next = new;
        List->tail = new;
    }

    printf("Data %d masuk dari belakang\n", data_new);
}

void tampil(SinglyList *List)
{
    SinglyListNode *temp;
    temp = List->head;

    printf("Data tersimpan: ");

    if (isEmpty(List) == 1)
    {
        printf("Tidak ada Data\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void hapus_Depan(SinglyList *List)
{
	SinglyListNode *del;
	int d;

	if (isEmpty(List) == 1)
    {
        printf("Tidak ada Data\n");
        return;
	}

    if (List->head != List->tail)
    {
        del = List->head;
        d = del->data;
        List->head = List->head->next;
        free(del);
    }

    else
    {
        d = List->tail->data;
        List->head = List->tail= NULL;
    }

    printf("Data %d terhapus\n", d);
}

void hapus_Belakang(SinglyList *List)
{
	SinglyListNode *del, *temp;
	int d;

	if (isEmpty(List) == 1)
    {
        printf("Tidak ada Data\n");
        return;
	}

    if(List->head->next != NULL)
    {
		temp = List->head;

		while (temp->next->next != NULL)
        {
		    temp = temp->next;
		}

		del = temp->next;
		d = del->data;
      	temp->next = NULL;
		free(del);
	 }

     else
     {
		d = List->head->data;
		List->head = NULL;
	 }

	 printf("Data %d terhapus\n", d);
}

void clear(SinglyList *List)
{
	SinglyListNode *temp, *del;
	temp = List->head;

	while (temp != NULL)
    {
		del = temp;
		temp = temp->next;
		free(del);
	}

	List->head = NULL;
	List->tail = NULL;
	printf("Data terhapus semua\n");
}

void search_data(SinglyList *List, int index_data)
{
    if (isEmpty(List) == 1)
    {
        printf("Masih kosong\n");
        return;
    }

    SinglyListNode *temp = List->head;
    int i = 0;

    while (temp->next != NULL && i < index_data)
    {
        temp = temp->next;
        i++;
    }

    printf("Data pada index %d adalah %d\n", i+1, temp->data);
}

void remove_Data(SinglyList *List, int data)
{
    if (isEmpty(List) == 1)
    {
        printf("Masih kosong\n");
        return;
    }

    SinglyListNode *temp, *before;
    temp = List->head;

    if (temp->data == data)
    {
        hapus_Depan(List);
        return;
    }

    while (temp != NULL && temp->data != data)
    {
        before = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Data tidak ada\n");
        return;
    }

    before->next = temp->next;
    free(temp);
    printf("Data %d sudah terhapus \n", data);
}

void insert_After(SinglyList *List, int point, int data_new)
{
    SinglyListNode *temp = List->head;

    while (temp->next != NULL && temp->data != point)
    {
        temp = temp->next;
    }

    if (temp->next == NULL && temp->data != point)
    {
        printf("Data tidak ditemukan!\n");
    }

    SinglyListNode *new = (SinglyListNode*) malloc(sizeof(SinglyListNode));
    new->data = data_new;
    new->next = temp->next;
    temp->next = new;
    printf("Data %d masuk setelah %d\n", data_new, point);
}

void insert_Before(SinglyList *List, int point, int data_new)
{
    if (point == List->head->data)
    {
        insert_Depan(List, data_new);
        printf("Data %d masuk sebelum %d\n", data_new, point);
        return;
    }

    SinglyListNode *temp = List->head;

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
        printf("Data tidak ditemukan!\n");
    }

    SinglyListNode *new = (SinglyListNode*) malloc(sizeof(SinglyListNode));
    new->data = data_new;
    new->next = temp->next;
    temp->next = new;
    printf("Data %d masuk sebelum %d\n", data_new, point);
}


int main()
{
    SinglyList slist;
    init(&slist);

    tampil(&slist);

    insert_Depan(&slist, 10);
    insert_Depan(&slist, 20);
    insert_Depan(&slist, 30);
    insert_Depan(&slist, 200);

    remove_Data(&slist, 30);
    remove_Data(&slist, 20);
    tampil(&slist);

    insert_Belakang(&slist, 40);
    insert_Belakang(&slist, 50);
    insert_Belakang(&slist, 300);
    insert_After(&slist, 50, 60);
    insert_Before(&slist, 40, 30);

    tampil(&slist);
    search_data(&slist, 2);
    search_data(&slist, 3);

    hapus_Belakang(&slist);
    hapus_Depan(&slist);

    tampil(&slist);

    clear(&slist);

    tampil(&slist);
    printf("\nSLNNC - Single Linked List non Circular Head and Tail");
}
