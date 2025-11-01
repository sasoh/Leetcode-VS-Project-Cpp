#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> present;
        
        for (int i = 0; i < nums.size(); i++) {
            present.insert(nums[i]);
        }
        
        auto current = head;
        ListNode* modifiedHead = nullptr;
        auto currentModified = modifiedHead;
        while (current != nullptr) {
            if (present.find(current->val) == present.end()) {
                if (modifiedHead == nullptr) {
                    modifiedHead = new ListNode(current->val);
                    currentModified = modifiedHead;
                }
                else {
                    currentModified->next = new ListNode(current->val);
                    currentModified = currentModified->next;
                }
            }
            current = current->next;
        }

        return modifiedHead;
    }
};

static void test1() {
    vector<int> nums{ 1,2,3 };
    auto head = new ListNode(1);
    head->next = new ListNode(2);
    auto current = head->next;
    current->next = new ListNode(3);
    current = current->next;
    current->next = new ListNode(4);
    current = current->next;
    current->next = new ListNode(5);

    Solution s;
    auto trimmed = s.modifiedList(nums, head);

    printf("end\n");
}

static void runTests() {
    test1();
}

int main() {
    runTests();
    return 0;
}