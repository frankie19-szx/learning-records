#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[50];
    char phone[15];
} Contact_t;

#define MAX_CONTACTS 100
Contact_t contacts[MAX_CONTACTS];
int count_contact=0;

typedef struct{
    Contact_t *data;
    int size;
    int capacity;
} ContactList_t;

Contact_t add_contact(const char *name ,const char *phone)
{
    Contact_t add={0};
    snprintf(add.name, sizeof(add.name), "%s", name);
    snprintf(add.phone, sizeof(add.phone),"%s",phone);
    if(count_contact<MAX_CONTACTS)
    {
        contacts[count_contact++]=add;
    }
    return add;
}

void print_contact(const Contact_t *contact)
{
    printf("姓名：%s 电话：%s\n",contact->name,contact->phone);
}

void find_contact(char *name)
{
    int found=0;
    for(int i=0;i<count_contact;i++)
    {
        if(strcmp(contacts[i].name,name)==0)
        {
            print_contact(&contacts[i]);
            found=1;
            break;
        }
    }
    if(!found)
        printf("未知联系人\n");

}

void delet_contact(char *name)
{
    int found=0;

    for(int i=0;i<count_contact;i++)
    {
        if(strcmp(contacts[i].name, name)==0)
        {
            for(int j=i;j<count_contact-1;j++)
            {
                contacts[j]=contacts[j+1];
            }
            memset(&contacts[count_contact-1],0,sizeof(Contact_t));
            count_contact--;
            found=1;
            printf("删除成功\n");
            break;
        }
    }

    if(!found)
    {
        printf("未找到联系人\n");
    }
}

Contact_t modify_contact(char *name)
{
    int found=0;

    for(int i=0;i<count_contact;i++)
    {
        if(strcmp(contacts[i].name, name)==0)
        {
            for(int j=i;j<count_contact-1;j++)
            {
                contacts[j]=contacts[j+1];
            }
            memset(&contacts[count_contact-1],0,sizeof(Contact_t));
            count_contact--;
            found=1;
            break;
        }
    }
}

Contact_t display_all()
{

}

int main()
{
    int n;
    char name[50],phone[15];
    Contact_t t;

    while(1)
    {   
        printf("请选择业务：\n1.增加联系人\n2.查找联系人\n3.删除联系人\n4.修改联系人\n5.退出\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("请输入联系人姓名与电话号码：");
                scanf("%49s%14s",name,phone);
                t=add_contact(name,phone);
                print_contact(&t);
                break;
            case 2:
                printf("请输入要查找得联系人：");
                scanf("%49s",name);
                find_contact(name);
                break;
            case 3:
                printf("请选择要删除的联系人：");
                scanf("%49s",name);
                delet_contact(name);
                break;
            case 4:
                printf("请选择要修改的联系人：");
                scanf("%49s",name);
                modify_contact(name);
                printf("请输入要修改的内容：");
                scanf("%49s%14s",name,phone);
                add_contact(name ,phone);
                printf("修改成功\n");
                break;
            case 5:
                return 0;
            default:
                break;
        }

    }

    return 0;
}