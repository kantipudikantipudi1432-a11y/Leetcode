class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Base case: if list is empty or has only one node
        if (!head || !head->next) {
            return head;
        }

        // Nodes to be swapped
        ListNode* firstNode = head;
        ListNode* secondNode = head->next;

        // Swapping
        firstNode->next = swapPairs(secondNode->next);
        secondNode->next = firstNode;

        // secondNode is now the new head of this pair
        return secondNode;
    }
};
