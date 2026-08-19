#include <stdio.h>

typedef struct{
    int id;
    char name[20];
    int scores[5];
    float avg;
}student_t;

typedef struct{
    student_t *data;
    int length;
    int capacity;
}seq_list_t;

typedef struct fail_node{
    int student_id;
    struct fail_node *next;
}fail_node_t;

typedef struct{
    fail_node_t *head;
    int count;
}fail_list_t;

typedef enum{
    OP_ADD=1,
    OP_DEL=2,
    OP_MOD=3
}op_type_t;

typedef struct{
    op_type_t type;
    student_t old_data;
    int index;
}undo_item_t;



int main()
{


    return 0;
}