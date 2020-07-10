#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define IS_EMPTY(temp) (!(temp)) //Empty list�� ����ִ��� �׽�Ʈ
#define IS_FULL(temp) (!(temp))

typedef struct listNode* list_pt;//����ü�� ����Ű�� ������
typedef struct listNode {
	int num; // ��ȣ�� �����ϴ� ����
	char name[10];//�̸��� �����ϴ� ����
	list_pt link; // ����ü ������
}listNode;

typedef struct cirList {//�������Ḯ��Ʈ ��带 ����Ű�� ������
	list_pt head;//ù ���
	list_pt ptr;//�̵��ϴ� ���
	list_pt tail;//���� ������ ���
	int nodeNum;//��� ����
}cirList;

void printList(list_pt ptr);//Circular LInked List����Լ�
void freeList(list_pt head, list_pt ptr);//�����޸� �����Լ�

void main()
{
	int n = 0;//�Է¹��� ���ڸ� ����, ��� ���ڸ� �Է¹���������
	int skipNum = 0;//������ ��ȣ�� �����ϴ� ����
	srand(time(NULL));//rand �Լ� ������ ���� srand�Լ�

	cirList* ptList = (cirList*)malloc(sizeof(cirList));//�ʱ�ȭ
	ptList->head = NULL;
	ptList->tail = NULL;
	ptList->ptr = NULL;
	ptList->nodeNum = 0;

	for (int i = 1; i < 38; i++)//37������ linked list ����
	{
		list_pt temp = (list_pt)malloc(sizeof(listNode));
		if (IS_FULL(temp))//heap������ ������ NULL��ȯ
		{
			fprintf(stderr, "�޸𸮰� ����á���ϴ�.\n");
			exit(1);
		}

		printf("%d�� ����� �̸��� �Է��ϼ��� : ", i);//����� �̸��� �Է¹���
		gets(temp->name);//temp�� name�� �Է¹��� �̸� ����
		temp->num = i;//temp�� num�� �Է¹��� �� ����
		temp->link = NULL;//temp�� link�� NULL����

		if (temp->num==1)//head�� ����Ű�� ��尡 NULL�϶�(�����϶�, ù��° ��带 ����)
		{
			ptList->head = temp;//Head�� temp�� ����Ŵ
			ptList->tail = temp;//tail�� temp�� ����Ŵ
			temp->link = temp;//�ڱ��ڽ��� ����Ŵ
		}
		else//ù��° �Է��� �ƴҶ� �տ� ����
		{
			temp->link = ptList->head;//�̵��ϴ� �����͸� ù��° ��带 ����Ű���Ѵ�.
			ptList->tail->link = temp;//������� link�� ���ο� �Է¿� ����
			ptList->tail = temp;//tail�� ��������带 ����Ű�� �̵���Ŵ
		}
		ptList->nodeNum++;//�ο��� üũ, ��尳�� ����
		printf("������ Circular Linked List�� ");
		printList(ptList);//LInked List����Լ�
	}
	printf("���� node������%d�Դϴ�.\n", ptList->nodeNum);

	//�Ѹ� �����ϴ� �ڵ�
	ptList->ptr = ptList->head;//ptr�� ó���� ����Ű����

	while (ptList->nodeNum > 3)//3���� �ƴѵ���(3���� ���� �� ����)
	{
		skipNum = rand() % (ptList->nodeNum);//nodeNum�������� ���ڸ� ����
		printf("\n******Skip Number�� %d�Դϴ�.*******\n", skipNum);
		for (int i = 1; i < skipNum; i++)
		{
			ptList->ptr = ptList->ptr->link;//skipNum��ŭ �������̵�
		}
		printf("Ż���� ����� %d�� %s�Դϴ�.\n", ptList->ptr->link->num, ptList->ptr->link->name);
		
		if (ptList->ptr->link == ptList->head)//�����ϰ����ϴ� ��带 head�� ����Ű�� ���� ��
		{
			ptList->head = ptList->ptr->link->link;//head�� ���� head����� ���� ��带 ����Ű���Ѵ�.
			ptList->ptr->link = ptList->ptr->link->link;//���� ���� ����
			(ptList->nodeNum)--;//��� �� ����
		}
		else if (ptList->ptr->link == ptList->tail)//�����ϰ����ϴ� ��带 tail�� ����Ű�� ���� ��
		{
			ptList->tail = ptList->ptr;//tail�� ���� tail����� ���� ��带 ����Ű�� �Ѵ�.
			ptList->ptr->link = ptList->ptr->link->link;//���� ���� ����
			(ptList->nodeNum)--;//��� �� ����
		}
		else
		{
			ptList->ptr->link = ptList->ptr->link->link;//�������� ����
			(ptList->nodeNum)--;//��������
		}
		printList(ptList);//LInked List����Լ�
			
		if (ptList->nodeNum == 3)//3���� ������ ��
		{
			printf("\n-------------�����Ϸ�--------------\n");
			printf("�������ߵ� 3���� ");
			printList(ptList);//���������� ���� 3�� ���
			break;
		}
	}
	free(ptList->head, ptList->ptr);//�޸� ����
	system("PAUSE");
	return 0;
	}
	
void printList(cirList* pt)	
{
	list_pt tmp;
	tmp = pt->head;

	if (pt->head) {
		do
		{
			printf("%d��-", tmp->num);//tmp�� ����Ű�� num�� ���
			printf("%s ", tmp->name);//tmp�� ����Ű�� name�� ���
			tmp = tmp->link;
		} while (tmp != pt->head);
		printf("�Դϴ�.\n\n");
	}
}

void freeList(list_pt head, list_pt ptr)
{
	while (head != NULL)//�Ҵ���� �޸𸮸� ������Ŵ
	{
		ptr = head;
		head = ptr->link;//ù��° ��带 �ٲ�
		free(ptr);//��带 ������Ŵ
	}
}