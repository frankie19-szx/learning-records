#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

#define MAX_STUDENTS 100
student_t students[MAX_STUDENTS];
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

int seq_init(seq_list_t *list)
{
    if(list==NULL)
        return -1;
    list->data=malloc(MAX_STUDENTS *sizeof(*list->data));
    if(list->data==NULL) 
        return -1;
    list->length=0;
    list->capacity=MAX_STUDENTS;
    return 0;
}

void print_students(const student_t *student)
{
    printf("学号：%d 姓名：%s 5科成绩：",student->id,student->name);
    for(int i=0;i<5;i++)
        printf("%d ",student->scores[i]);
    printf("平均分：%.1f\n",student->avg);
}

int add_students(seq_list_t *list,int id,char *name,int *scores)
{
    if(list==NULL||name==NULL||scores==NULL||list->length>=list->capacity)
        return -1;

    student_t *s=&list->data[list->length];
    s->id=id;
    strncpy(s->name,name,sizeof(s->name)-1);
    s->name[sizeof(s->name) - 1] = '\0';
    float sum=0.0;
    for(int i=0;i<5;i++)
    {
        s->scores[i]=scores[i];
        sum+=s->scores[i];
    }
    s->avg=sum/5;
    print_students(s);
    list->length++;
    return 0;
}

void seq_display(const seq_list_t *list)
{
    
}

int seq_destroy(seq_list_t *list)
{
    if(list==NULL)
        return -1;
    free(list->data);
    list->data=NULL;
    list->length=0;
    list->capacity=0;
    return 0;
}

int main()
{
    seq_list_t students;
    if(seq_init(&students)!=0)
    {
        fprintf(stderr,"初始化失败\n");
        return EXIT_FAILURE;
    }
    int n;
    do{
        printf("1. 添加学生\n2. 删除学生\n3. 修改学生信息\n4. 查找学生\n5. 显示所有学生\n6. 显示补考名单\n7. 撤销上一步操作\n8. 退出\n");
        if(scanf("%d",&n)!=1)
        {
            seq_destroy(&students);
            return EXIT_FAILURE;
        }
        switch(n)
        {
            case 1:
                student_t s;
                printf("请输入学生学号与姓名：");
                if(scanf("%d%19s",&s.id,s.name)!=2)
                    break;
                printf("请输入5科成绩：");
                for(int i=0;i<5;i++)
                    scanf("%d",&s.scores[i]);
                if(add_students(&students,s.id,s.name,s.scores)!=0)
                    printf("添加失败，学生数量已达上限\n");
                break;
            //case 2:
            default:
                break;

        }
    }while(n!=8);

    seq_destroy(&students);
    return EXIT_SUCCESS;
}