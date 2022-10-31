#include "list.c"

int main() {
    // printf("%d", TEST);
    int         i = 0;
    int     count = 0;

    Node *List= NULL;
    Node *newNode = NULL;
    Node *Curr =NULL;

    for (i = 0; i < 5; i++) {
        newNode = createNode(i);
        addNode( &List, newNode );
    }

    count = countNode(List);
    for (i = 0; i < count; i++) {
        Curr = getNodeAt(List, i);
        printf("List[%d] = %d\n",  i, Curr->Data);
    }
    printf("===== 5 Nodes Created \n");

    newNode = createNode(99);
    Curr = getNodeAt(List, 0);
    insertAfter(Curr, newNode);
    
    newNode = createNode(444);
    Curr = getNodeAt(List, 4);
    insertAfter(Curr, newNode);

    count = countNode(List);
    for (i = 0; i < count; i++) {
        Curr = getNodeAt(List, i);
        printf("List[%d] = %d\n",  i, Curr->Data);
    }
    
    printf("===== After 2 Node Inserted ==== \n");

    newNode = getNodeAt(List, 1);
    removeNode(&List, newNode);
    newNode = getNodeAt(List, 0);
    removeNode(&List, newNode);

    count = countNode(List);
    for (i = 0; i < count; i++) {
        Curr = getNodeAt(List, i);
        printf("List[%d] =  %d\n", i, Curr ->Data );  
    }

    printf("===== After Node with index 0,1 removed ==== \n");

    return 0;
}   