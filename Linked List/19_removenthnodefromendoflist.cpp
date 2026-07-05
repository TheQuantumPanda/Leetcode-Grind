/*Well if it was a question of an array it would have been dead simple well it is a linked list one so
well first i need to reach length - n - 1 since i can't delete the node that I am one*/

/*Here is the code*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            length++;
            temp = temp->next;
        }
        if(length == n)
            return head->next;
        ListNode* current = head;
        for(int i = 0; i < length - n - 1; i++)
        {
            current = current->next;
        }
        current->next = current->next->next;
        return head;
    }
};

/*GPT suggested approach it is two pointer basically*/

/*Here is the code*/
/*
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy.next;
    }
};
*/
