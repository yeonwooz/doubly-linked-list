//  C 이중연결리스트
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
    int Data;
    struct listNode *Next;
    struct listNode *Prev;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode -> Data = data;
    newNode -> Next = NULL;
    newNode -> Prev = NULL;

    return newNode;
}

void deleteNode(Node *Node) {
    free(Node);
}

Node *getNodeAt(Node head, int index) {  // 찾으려는 인덱스 index (몇번째로 연결된 요소인지)
    Node *horse = head;
    int count = 0;  

    while (horse != NULL) {
         if (count++ == index) {  // 후위연산이므로 현재 count 와 index를 일단비교하고, 그 다음에 증가시킴
            return horse;   // 찾으면 horse 리턴
         }

         horse = horse -> Next;  // 다음 horse
    }

    return NULL; // 노드를 찾지 못함
}

int countNode(Node *head) {
    int count = 0;
    Node *horse = head;

    while (horse != NULL) {
        horse = horse -> Next;
        count++;
    }

    return count;
}

void addNode(Node **head, Node *newNode) {  // head 자체를 업데이트해주어야 하기때문에 더블포인터로 받아왔다
    // no list exists
    if ( (*head) == NULL) {
        *head = newNode;
    }

    // list exists
    else {
        Node *horse = (*head);

        while (horse -> Next  != NULL) {
            horse = horse -> Next;
        }
        horse->Next = newNode;
        newNode->Prev = horse;
    }
}

        // // 맨 앞에 추가 
        // head -> prev = newNode;
        // newNode -> Next = head;
        // head -> Data = newNode -> Data; ???

void insertAfter(Node * Current, Node *newNode) {

    // head
    if (Current->Prev == NULL && Current->Next == NULL) {
        Current->Next = newNode;
        newNode->Prev = Current;
    }

    // not head
        // if tail
    if (Current->Next == NULL) {
        Current->Next = newNode;
        newNode->Prev = Current;
    }
    else {
        // if middle
        Current->Next->Prev = newNode;
        newNode->Prev = Current;
        newNode->Next = Current->Next;
        Current->Next = newNode;
    }
}

void removeNode(Node **head, Node *remove) {

    // if remove is head
    if (*head == remove) {
        *head = remove -> Next;
    }

    // if remove is middle (when remove has next link to go)
    if (remove->Next != NULL) {
        remove->Next->Prev = remove->Prev;
    }

    // (when remove has prev link to go)
    if (remove->Prev != NULL) {
        remove->Prev->Next = remove->Next;
    }

    deleteNode(remove);
}

// https://www.youtube.com/watch?v=iSdEHxVJ5vk