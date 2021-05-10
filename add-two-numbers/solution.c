/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry = 0, val1 = 0, val2 = 0, sum = 0;
    struct ListNode *pl1 = l1, *pl2 = l2;
    struct ListNode *tail = NULL;
    struct ListNode *head = NULL;
    struct ListNode *pnew = NULL;

    do {
        pnew = malloc(sizeof(struct ListNode));
        pnew->next = NULL;
        val1 = val2 = 0;

        if(pl1 != NULL) {
            val1 = pl1->val;
            pl1 = pl1->next;    
        }

        if(pl2 != NULL) {
            val2 = pl2->val;
            pl2 = pl2->next;
        }

        sum = carry + val1 + val2;
        carry = sum / 10;

        pnew->val = sum % 10;

        /* First time through the loop? */
        if(tail == NULL) {
            head = tail = pnew;
            continue;
        }

        head->next = pnew;
        head = pnew;

    } while(pl1 !=NULL || pl2 != NULL);

    if(carry > 0) {
        pnew = malloc(sizeof(struct ListNode));
        pnew->next = NULL;
        head->next = pnew;
        pnew->val = carry;
    }

    return tail;
}
