#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* creatnode(int value){
    node* newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("内存分配失败");
        return NULL;
    }

    newnode -> data =value;
    newnode -> next =NULL;
    return newnode;
}
//插入节点,头插法
void insertnode(node** head,int value){
        node* newnode =creatnode(value);
        if(newnode == NULL){
            return;
        }
        newnode->next =*head;
        *head = newnode;
}
//遍历
void printlist(node* head){
    if(head == NULL){
        printf("链表为空\n");
        return;
    }

    node* curr=head;
    while(curr!=NULL){
        printf("%d\n",curr->data);
        curr= curr->next;
    }
    printf("NULL\n");
}
//释放内存
void freelist(node* head){
    while(head !=NULL){
    node* temp= head;
    head = temp->next;
    free(temp);
    }
    printf("内存已安全释放");
}
int main(){
    node* head=NULL;
    int len=0;
    printf("新增链表长度: ");
    scanf("%d",&len);
    while(len !=0){
        int x=0;
        printf("请输入链表数据: ");
        scanf("%d",&x);
        insertnode(&head,x);
        --len;
    }
    printlist(head);
    freelist(head);
}

