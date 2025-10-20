#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

static void print(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

class Solution {
    int length(ListNode* head) {
        int counter = 0;
        while (head != nullptr) {
            head = head->next;
            counter++;
        }

        return counter;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        cout << "Processing list = ";
        print(head);
        cout << "Length = " << length(head) << endl;

        int rotations = k % length(head);
        cout << "For " << k << " rotations, actions required = " << rotations << endl;

        ListNode* rotated = head;
        for (int i = 0; i < rotated; i++) {
            ListNode* first = rotated;
            ListNode* nextToLast = nullptr;
            ListNode* last = nullptr;

            // take last element of current 'rotated'
            ListNode* current = rotated;
            while (current != nullptr) {
                last = current;
                if (current->next != nullptr && current->next->next == nullptr) {
                    nextToLast = current;
                }
                current = current->next;
            }
            
            if (nextToLast == nullptr) return rotated;

            // make its next point to current 'first' in rotated
            nextToLast->next = nullptr;
            last->next = first;
            
            rotated = last;
        }

        return rotated;
    }
};

static void test1() {
    Solution s;
    ListNode* head = new ListNode(1);
    if (head == nullptr) return;
    head->val = 1;
    ListNode* current = head;
    for (int i = 1; i < 5; i++) {
        ListNode* next = new ListNode(i + 1);
        if (next == nullptr) return;
        current->next = next;
        current = next;
    }
    print(head);

    ListNode* rotated = s.rotateRight(head, 1);
    rotated = s.rotateRight(rotated, 2);
    rotated = s.rotateRight(rotated, 3);
    rotated = s.rotateRight(rotated, 4);
    rotated = s.rotateRight(rotated, 5);
    rotated = s.rotateRight(rotated, 6);
    rotated = s.rotateRight(rotated, 10);
    rotated = s.rotateRight(rotated, 100);
    print(rotated);

    printf("end\n");
}

static void runTests() {
    test1();
}

int main() {
    runTests();
    return 0;
}