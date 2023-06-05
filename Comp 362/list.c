#include "list.h"

void allocate_list(LIST **list, int count)
{
   if (count == 0)
   {
      //(**list).data = NULL;
      //(**list).next = NULL;
      return;
   }

   *list = (LIST*)malloc(sizeof(LIST));
   (**list).data = NULL;
   (**list).next = NULL;
   allocate_list(&((*list)->next), --count); 

}

void free_list_iter(LIST *head)
{
   while (head != NULL)
   {
      LIST *next = head->next;
      if (head->data != NULL)
         free(head->data);
      free(head);
      head = next;
   }
}

void free_list_emb(LIST *head)
{
   LIST *curr = head;

   if (curr->next)
      free_list_emb(curr->next);

   if (head->data != NULL)
      free(curr->data);

   free(curr);
}

void free_list_tail(LIST *head)
{
   if (head == NULL)
      return;

   LIST *next = head->next;

   if (head->data != NULL)
      free(head->data);

   free(head);

   free_list_tail(next);
}

