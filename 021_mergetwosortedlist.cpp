/*My approach was to combine them sort them as simple as that*/


/*Here is the code*/

class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        vector<int> values;

        while(list1 != nullptr) {

            values.push_back(list1->val);

            list1 = list1->next;
        }
      
        while(list2 != nullptr) {

            values.push_back(list2->val);

            list2 = list2->next;
        }

        sort(values.begin(), values.end());

        ListNode* dummy = new ListNode(0);

        ListNode* current = dummy;

        for(int num : values) {

            current->next = new ListNode(num);

            current = current->next;
        }

        return dummy->next;
    }
};


/*The GPT gave out two solution this time*/

/*First one is dummy nodes one*/

/*Here is the code*/

/*
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode(0);

        ListNode* current = dummy;

        while(list1 != nullptr && list2 != nullptr) {

            if(list1->val <= list2->val) {

                current->next = list1;

                list1 = list1->next;
            }

            else {

                current->next = list2;

                list2 = list2->next;
            }

            current = current->next;
        }
        
        if(list1 != nullptr) {
            current->next = list1;
        }

        if(list2 != nullptr) {
            current->next = list2;
        }

        return dummy->next;
    }
};
*/

/*The second one is via recursion*/

/*Here is the code*/

/*
class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == nullptr) {
            return list2;
        }

        if(list2 == nullptr) {
            return list1;
        }

        if(list1->val <= list2->val) {

            list1->next = mergeTwoLists(list1->next, list2);

            return list1;
        }

        else {

            list2->next = mergeTwoLists(list1, list2->next);

            return list2;
        }
    }
};
*/
