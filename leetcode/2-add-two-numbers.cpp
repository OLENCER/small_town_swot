#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *p = nullptr;
        ListNode *head = nullptr;
        int carry = 0, sum = 0;

        while (l1 || l2)
        {
            sum = ((l1 != nullptr) ? l1->val : 0) + ((l2 != nullptr) ? l2->val : 0) + carry;
            carry = sum / 10;

            if(head == nullptr)
            {
                head = p = new ListNode(sum % 10);
            }
            else
            {
                p->next = new ListNode(sum % 10);
                p = p->next;
            }

            if(l1 != nullptr)
            {
                l1 = l1->next;
            }
            if(l2 != nullptr)
            {
                l2 = l2->next;
            }
        }

        if(carry > 0)
        {
            p->next = new ListNode(carry);
        }

        return head;
    }
};

int main()
{
    ListNode *a = new ListNode(9);
    a->next = new ListNode(9);

    ListNode *b = new ListNode(9);
    b->next = new ListNode(9);
    b->next->next = new ListNode(9);

    Solution solution;
    ListNode* p = solution.addTwoNumbers(a, b);

    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }

}
