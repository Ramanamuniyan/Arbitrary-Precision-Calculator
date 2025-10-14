#include "valid.h"

int division(Dlist **dividend_head, Dlist **dividend_tail,
             Dlist **divisor_head, Dlist **divisor_tail,
             Dlist **quot_head, Dlist **quot_tail)
{
    if (!*divisor_head || ((*divisor_head)->data == 0 && !(*divisor_head)->next))
    {
        printf("Error: Division by zero.\n");
        return FAILURE;
    }

    Dlist *partial_head = NULL, *partial_tail = NULL;
    Dlist *rem_head = NULL, *rem_tail = NULL;
    int count;

    Dlist *temp = *dividend_head;

    while (temp)
    {
        // Bring down next digit
        insert_at_last(&partial_head, &partial_tail, temp->data);
        temp = temp->next;

        // Remove leading zeros from partial dividend
        remove_leading_zeros(&partial_head, &partial_tail);

        // If partial < divisor, append 0 to quotient
        if (compare(partial_head, *divisor_head) == SMALLER)
        {
            insert_at_last(quot_head, quot_tail, 0);
            continue;
        }

        // Count how many times divisor fits in partial dividend
        count =0;
        while (compare(partial_head, *divisor_head) != SMALLER)
        {
            subtraction(&partial_head, &partial_tail,
                        divisor_head, divisor_tail,
                        &rem_head, &rem_tail);

            deletelist(&partial_head, &partial_tail);
            partial_head = rem_head;
            partial_tail = rem_tail;
            rem_head = rem_tail = NULL;
            count++;
        }
       
        insert_at_last(quot_head, quot_tail, count);
        count=0;
    }

    // Remove leading zeros in quotient
    remove_leading_zeros(quot_head, quot_tail);

    deletelist(&partial_head, &partial_tail); // cleanup

    return SUCCESS;
}
