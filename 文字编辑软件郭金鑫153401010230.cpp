#include<stdio.h> 
#include<stdlib.h>
#include<malloc.h> 
#include<string.h>
typedef struct LNode
{
	char data;
	struct LNode *next;
}ListNode,*LinkList;
LinkList head;
LinkList CreatList()
{
	char ch;
	ListNode *p,*L;  
    head->next=NULL; 
    L=head;
    scanf("%c",&ch);
    while((ch=getchar())!='\n') 
	{ 
        p=(LinkList)malloc(sizeof(ListNode)); 
        p->data=ch; 
        L->next=p;    
        L=p;  
    } 
    L->next=NULL;
    return(head);
}
void printhead()
{
	printf("*************************文字编辑软件************************ \n");
	printf("************************************************************* \n");
}
void numchar()
{
	int wordnm=0,number_num=0,kongnm=0,chnum=0,sumnum=0;
	LinkList p;
	p=head->next;
	while(p)
	{
	    if((p->data>='A'&&p->data<='Z')||(p->data>='a'&&p->data<='z')) 
	    wordnm+=1;
	    else if(p->data>='0'&&p->data<='9')
	    number_num+=1;
	    else if(p->data==' ')
	    kongnm+=1;
	    else if(p->data==','||p->data=='.'||p->data==';'||p->data==':'||p->data=='!'||p->data=='?'||p->data=='"')
	    chnum+=1;
	    p=p->next;
	}
	sumnum=wordnm+number_num+chnum;
	printf("\n");
	printf("                     该文章中包含%d个英文字母\n",wordnm);
	printf("                     该文章中包含%d个数字\n",number_num);
	printf("                     该文章中包含%d个空格\n",kongnm);
	printf("                     该文章中包含%d个符号\n",chnum);
	printf("                     文章总字数为%d字\n",sumnum);
	printf("************************************************************* \n\n");
}
void search(char *str1)
{ 
	LinkList p;
	p=head->next;
	int strnumber=0,i=0;
	char childchar[20];
	strcpy(childchar,str1);
	if(childchar[0]==NULL)
	{
	    printf("输入不合法请重新输入:\n");
	    gets(childchar);
	}
	int length=strlen(childchar);
	while(p)
	{
		if(p->data==childchar[i])
		{
			if(i+1==length)
			{strnumber+=1;}
		    i+=1;
			p=p->next;
		} 
		else
		{
			i=0;
			if(p->data!=childchar[i])
		    p=p->next;
		}
	}
	printf("\n");
	printf("                     输入的单词在文章中出现次数为:%d\n",strnumber);
}
void Listdelete(char *str2)
{
	ListNode *p,*q;
	int i=0,j=0;
	p=head->next;
	q=head;
	char dechar[20];
	strcpy(dechar,str2);
	int length=strlen(dechar);
	while(p)
	{
		if(p->data==dechar[i])
		{
			if(i+1==length)
			{
			    if(p->next==NULL)
					q->next=NULL;
				else if(p==head->next)
					head->next=p->next;
				else
					q->next=p->next; }
		    i+=1;
			p=p->next;
		} 
		else
		{
			i=0;
			if(p->data!=dechar[i])
			{q=p;
		    p=p->next;}
		}
	}    
}
void printList()
{
	LinkList p;
	p=head->next;
	printf("当前文章内容是:\n");
	while(p)
	{
		printf("%c",p->data);
		p=p->next;
	}
}
int save_ListNode()
{
    FILE *fp;
    ListNode *h;
    h = head->next;//p为已经构建好的链表
    if ((fp = fopen("txt.txt", "ab+")) == NULL)
    {
        printf("无法打开 txt.txt!\n");
        return -1;
    }
    while (head)
    {
 
        fwrite(head, 1, 1, fp);
        head = head->next;
    }
    fclose(fp);
    return 1;
}//储存链表到文件
ListNode* read_list()
{
    FILE *fp;
    char t;
    if ((fp = fopen("txt.txt", "rb")) == NULL)
    {
        printf("无法读取 txt.txt\n");
        return NULL;
    }
    int sign;
    ListNode *s,*p,*h;
    h= (LinkList)malloc(sizeof(ListNode));
    if (h == NULL)
    {
        printf("读取失败！内存空间申请不足！\n");
        return NULL;
    }
    p = h;
    p->next = NULL;
    while (!feof(fp))
    {
        s = (LinkList)malloc(sizeof(ListNode));
        fscanf(fp,"%c",&p->data);
        p->next = s;
        p = s;
    }
    s->next=NULL;
    fclose(fp);
    return h;
}//读取文件到链表
void Bmenu()
{
	int a;
	char str1[20];
	char str2[20];
	do{
		printhead();
		printf("\n");
		printf("**************************文字处理菜单*********************** \n");
	    printf("************************************************************* \n");
	    printf("                      1、查找文章中的字符或字符串出现次数\n");
	    printf("                      2、删除文章中的字符或字符串\n");
	    printf("                      3、显示文章内容\n");
	    printf("                      4、返回主菜单\n");
	    printf("                      5、退出系统\n");
	    printf("请选择：");
	    scanf("%d",&a);
	    if((a>5)||(a<1))
		printf("对不起，没有此选项，请重新输入:\n");
		else 
	    switch(a)
	    {
	    	case 1:system("cls");
	    	       printf("输入要查找的单词:\n");
	    	       getchar();
	    	       gets(str1);
	    	       search(str1);
	    	       printf("\n");
			       printf("按回车返回上级菜单:");
				   getchar();
				   system("cls");
	    	       break;
	        case 2:system("cls");
	               printf("输入要删除的单词:\n");
	               getchar();
	    	       gets(str2);
	               Listdelete(str2);
	               printList();
	               printf("\n");
			       printf("按回车返回上级菜单:");
				   getchar();
				   system("cls");
	               break;
	        case 3:system("cls");
			       printList();
			       printf("\n");
			       printf("按回车返回上级菜单:");
				   getchar();
				   getchar();
				   system("cls"); 
			       break;
		}
		if(a==4)
		{
			system("cls");
			break;
		}
		if(a==5) exit(0);
	}while(1);
}
void menu()
{
	head=head->next;
	int t;
	do{
		printhead();
		printf("\n");
		printf("****************************主菜单*************************** \n");
	    printf("************************************************************* \n");
     	printf("                      1、输入文章内容\n");
     	printf("                      2、显示文章内容\n");
     	printf("                      3、文章内容统计\n");
     	printf("                      4、文章内容处理菜单\n");
     	printf("                      5、保存文件\n");
     	printf("                      6、读取已保存文件\n");
     	printf("                      7、退出编辑软件\n");
     	printf("************************************************************* \n");
     	printf("请选择：");
		scanf("%d",&t);
		if(t>7||t<1)
		printf("对不起，没有此选项，请重新输入:");
		else
		switch(t)
		{
			case 1:system("cls");
			       printf("请输入:\n");
			       head=CreatList();
			       printf("\n");
			       printf("输入成功按回车继续:");
				   getchar();
				   system("cls");
			       break;
			case 2:system("cls");
			       printList();
			       printf("\n");
			       printf("按回车返回上级菜单:");
				   getchar();
				   getchar();
				   system("cls"); 
			       break;
			case 3:system("cls");
			       numchar();
			       printf("\n");
			       printf("按回车返回上级菜单:");
				   getchar();
				   getchar();
				   system("cls");
			       break;
			case 4:system("cls");
			       Bmenu();
			       break;
			case 5:system("cls");
			       printf("保存成功\n");
			       save_ListNode();
			       printf("\n");
			       printf("按回车返回上级菜单:");
				   getchar();
				   getchar();
				   system("cls");
			       break;
			case 6:system("cls");
			       printf("读取成功");
			       head=read_list();
			       printf("\n");
				   printList();
				   printf("\n");
			       printf("按回车返回上级菜单:");
				   getchar();
				   getchar();
				   system("cls");
			       break;
		} 
		if(t==7) exit(0);
	}while(1);
}
int main()
{
	
	head=(LinkList)malloc(sizeof(ListNode));
	menu();
}
