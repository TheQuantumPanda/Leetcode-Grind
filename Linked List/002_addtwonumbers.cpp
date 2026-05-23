/*Well opened the question the approch clicked in 3 minutes and the submission failed why 
cause i went beyond the limit of long long and turn out that if I did this in python i wouldn't
have encountered this issue the long long in C++ can take upto 19 digits max*/

/*Here is my arrpoach anyway*/

/*The linked list have the values in reverse order then I can just take the multipy it to
10 to the power the position of the number next I can add the numbers this make it easy and
I dont have to wory about the carry over next after addition is done I can go ahead take the quotient
and remainder (The divisor is 10) The remainder goes into the list and quotient becomes the dividend*/

/*The code*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long num1 = 0;
        long long num2 = 0;
        long long place = 1;
        while(l1 != nullptr) {
            num1 += l1->val * place;
            place *= 10;
            l1 = l1->next;
        }
        place = 1;
        while(l2 != nullptr) {
            num2 += l2->val * place;
            place *= 10;
            l2 = l2->next;
        }
        long long sum = num1 + num2;
        if(sum == 0) {
            return new ListNode(0);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        while(sum > 0) {
            int digit = sum % 10;
            current->next = new ListNode(digit);
            current = current->next;
            sum /= 10;
        }
        return dummy->next;
    }
};

/*Here is the GPT solution*/

/*In this solution the two linked list are traversed simultaneously and and addition is also done with that*/

/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry) {
            int sum = carry;
            if(l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }
        return dummy->next;
    }
};
*/
