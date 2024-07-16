#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    /* your code here */
    if (head == NULL)
        return 0;
    node *tortoise = head;
    node *hare = head;
    do{
        hare = hare->next;
        hare = hare->next;
        tortoise = tortoise->next;
        if(hare != NULL && hare == tortoise )
            return 1;
    } while(hare != NULL && hare->next != NULL && hare->next->next != NULL);
    return 0;
};
