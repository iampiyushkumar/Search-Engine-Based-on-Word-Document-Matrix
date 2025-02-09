#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// ✅ Optimized Iterative Reverse Function
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// ✅ Optimized Iterative Merge Function
Node* merge(Node* r1, Node* r2) {
    Node dummy(0);
    Node* tail = &dummy;

    while (r1 && r2) {
        if (r1->data <= r2->data) {
            tail->next = r1;
            r1 = r1->next;
        } else {
            tail->next = r2;
            r2 = r2->next;
        }
        tail = tail->next;
    }

    tail->next = (r1) ? r1 : r2;
    return dummy.next;
}

// ✅ Sort Alternating Linked List
Node* sort(Node* head) {
    if (!head || !head->next) return head;

    // Split the list into two parts
    Node* ptr1 = head;
    Node* ptr2 = head->next;
    Node* head1 = head;
    Node* head2 = head->next;

    while (ptr1 && ptr1->next && ptr2 && ptr2->next) {
        ptr1->next = ptr1->next->next;
        ptr1 = ptr1->next;
        if (ptr2->next) {
            ptr2->next = ptr2->next->next;
            ptr2 = ptr2->next;
        }
    }

    // Reverse the second half
    head2 = reverse(head2);

    // Merge both sorted lists
    return merge(head1, head2);
}

// Utility function to print a linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main() {
    Node* head = new Node(1);
    head->next = new Node(9);
    head->next->next = new Node(2);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(7);

    cout << "Original List: ";
    printList(head);

    head = sort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
