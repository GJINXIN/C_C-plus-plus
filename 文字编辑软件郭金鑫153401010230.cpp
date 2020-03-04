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
	printf("*************************���ֱ༭���************************ \n");
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
	printf("                     �������а���%d��Ӣ����ĸ\n",wordnm);
	printf("                     �������а���%d������\n",number_num);
	printf("                     �������а���%d���ո�\n",kongnm);
	printf("                     �������а���%d������\n",chnum);
	printf("                     ����������Ϊ%d��\n",sumnum);
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
	    printf("���벻�Ϸ�����������:\n");
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
	printf("                     ����ĵ����������г��ִ���Ϊ:%d\n",strnumber);
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
	printf("��ǰ����������:\n");
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
    h = head->next;//pΪ�Ѿ������õ�����
    if ((fp = fopen("txt.txt", "ab+")) == NULL)
    {
        printf("�޷��� txt.txt!\n");
        return -1;
    }
    while (head)
    {
 
        fwrite(head, 1, 1, fp);
        head = head->next;
    }
    fclose(fp);
    return 1;
}//���������ļ�
ListNode* read_list()
{
    FILE *fp;
    char t;
    if ((fp = fopen("txt.txt", "rb")) == NULL)
    {
        printf("�޷���ȡ txt.txt\n");
        return NULL;
    }
    int sign;
    ListNode *s,*p,*h;
    h= (LinkList)malloc(sizeof(ListNode));
    if (h == NULL)
    {
        printf("��ȡʧ�ܣ��ڴ�ռ����벻�㣡\n");
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
}//��ȡ�ļ�������
void Bmenu()
{
	int a;
	char str1[20];
	char str2[20];
	do{
		printhead();
		printf("\n");
		printf("**************************���ִ���˵�*********************** \n");
	    printf("************************************************************* \n");
	    printf("                      1�����������е��ַ����ַ������ִ���\n");
	    printf("                      2��ɾ�������е��ַ����ַ���\n");
	    printf("                      3����ʾ��������\n");
	    printf("                      4���������˵�\n");
	    printf("                      5���˳�ϵͳ\n");
	    printf("��ѡ��");
	    scanf("%d",&a);
	    if((a>5)||(a<1))
		printf("�Բ���û�д�ѡ�����������:\n");
		else 
	    switch(a)
	    {
	    	case 1:system("cls");
	    	       printf("����Ҫ���ҵĵ���:\n");
	    	       getchar();
	    	       gets(str1);
	    	       search(str1);
	    	       printf("\n");
			       printf("���س������ϼ��˵�:");
				   getchar();
				   system("cls");
	    	       break;
	        case 2:system("cls");
	               printf("����Ҫɾ���ĵ���:\n");
	               getchar();
	    	       gets(str2);
	               Listdelete(str2);
	               printList();
	               printf("\n");
			       printf("���س������ϼ��˵�:");
				   getchar();
				   system("cls");
	               break;
	        case 3:system("cls");
			       printList();
			       printf("\n");
			       printf("���س������ϼ��˵�:");
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
		printf("****************************���˵�*************************** \n");
	    printf("************************************************************* \n");
     	printf("                      1��������������\n");
     	printf("                      2����ʾ��������\n");
     	printf("                      3����������ͳ��\n");
     	printf("                      4���������ݴ���˵�\n");
     	printf("                      5�������ļ�\n");
     	printf("                      6����ȡ�ѱ����ļ�\n");
     	printf("                      7���˳��༭���\n");
     	printf("************************************************************* \n");
     	printf("��ѡ��");
		scanf("%d",&t);
		if(t>7||t<1)
		printf("�Բ���û�д�ѡ�����������:");
		else
		switch(t)
		{
			case 1:system("cls");
			       printf("������:\n");
			       head=CreatList();
			       printf("\n");
			       printf("����ɹ����س�����:");
				   getchar();
				   system("cls");
			       break;
			case 2:system("cls");
			       printList();
			       printf("\n");
			       printf("���س������ϼ��˵�:");
				   getchar();
				   getchar();
				   system("cls"); 
			       break;
			case 3:system("cls");
			       numchar();
			       printf("\n");
			       printf("���س������ϼ��˵�:");
				   getchar();
				   getchar();
				   system("cls");
			       break;
			case 4:system("cls");
			       Bmenu();
			       break;
			case 5:system("cls");
			       printf("����ɹ�\n");
			       save_ListNode();
			       printf("\n");
			       printf("���س������ϼ��˵�:");
				   getchar();
				   getchar();
				   system("cls");
			       break;
			case 6:system("cls");
			       printf("��ȡ�ɹ�");
			       head=read_list();
			       printf("\n");
				   printList();
				   printf("\n");
			       printf("���س������ϼ��˵�:");
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
