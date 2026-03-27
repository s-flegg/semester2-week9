
#include <stdio.h>
#include <stdlib.h>

#include "node_structures.h"
#include "node.h"
#include "list_structures.h"
#include "list.h"

int main( void ) {

    // create an empty list
    List *list = createList();

    // add some nodes
    addNode(list,(Node *)NULL,1); // add at head - special case - pass NULL
    addNode(list, list->head, 2);
    addNode(list, list->head->next, 3);

    // display the list
    traverseI(list->head);

    // add and delete more nodes with addNode() and deleteNode()
    addNode(list, list->head, 4);
    addNode(list, (Node *)NULL, 5);
    traverseI(list->head);

    Node *d1 = removeNode(list, (Node *)NULL);
    printf("%d\n", d1->data->value);
    // deallocate deleted nodes - test with valgrind to check this
    freeNode(d1);

    // free list memory
    freeNodes( list->head );

    // free list
    free(list);

    return 0;
}
