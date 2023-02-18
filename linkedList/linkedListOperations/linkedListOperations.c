#include<stdio.h>
#include<stdlib.h>
struct linkedList
{
    int x;
    struct linkedList* next;
}typedef node;
node* ekle(node* root, int x) {
    node* temp = malloc(sizeof(node));
    temp->x = x;
    temp->next = root;
    root=temp;
    return root;
}
node* arayaEkle(node* root, int x, int n) {
    node* temp1 = malloc(sizeof(node));
    temp1->x = x;
    temp1->next = NULL;
    if (n==1)
    {
        temp1->next = root;
        root = temp1;
        return;
    }
    else
    {
        node* temp2 = root;
        for (int i = 0; i < n-2; i++)
        {
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
    }

}

node* siraliEkle(node* root, int x) {
    if (root==NULL)
    {
        root = malloc(sizeof(node));
        root->next = NULL;
        root->x = x;
        return root;
    }
    if (root->x>x)
    {
        node* temp = malloc(sizeof(node));
        temp->next = root;
        temp->x = x;
        return temp;
    }
    else
    {
        node* iter = root;
        while (iter->next != NULL && iter->next->x < x)
        {
            iter = iter->next;
        }
        node* temp = malloc(sizeof(node));
        temp->next = iter->next;
        iter->next = temp;
        temp->x = x;
        return root;
    }
}
node* sil(node* root, int n) {
    node* temp1 = root;
    if (n==1)
    {
        return root->next;
    }
    for (int i = 0; i < n-2; i++)
    {
        temp1 = temp1->next;
    }
    node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
    return root;

}
node* reverse(node* root) {
    node* current, * next, * prev;
    current = root;
    prev = NULL;
    while (current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    root = prev;
    return root;
}
void yazdir(node* root) {
    while (root != NULL)
    {
        printf("%d---->", root->x);
            root = root->next;
    }

}

void main() {
    node* head;
    head = NULL;
    head=ekle(head, 5);
    head=ekle(head, 9);
    head=ekle(head, 10);
    head = ekle(head, 7);
    head = ekle(head, 11);
    head = ekle(head, 15);
    head=sil(head, 3);
    printf("reverse order\n");
    head=reverse(head);
    yazdir(head);
    printf("\ntrue order\n");
    head = reverse(head);
    yazdir(head);
   /* head=  siraliEkle(head, 400);
    head = siraliEkle(head, 40);
    head = siraliEkle(head, 4);
    head = siraliEkle(head, 450);  
    head = siraliEkle(head, 50);
    yazdir(head);*/
}