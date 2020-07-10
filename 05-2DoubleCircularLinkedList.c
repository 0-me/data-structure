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
	list_pt prev; // ���� ��带 ����Ű�� ������
	list_pt next; // ���� ��带 ����Ű�� ������
}listNode;

typedef struct cirList {//�������Ḯ��Ʈ ��带 ����Ű�� ������
	list_pt head;//ù ���
	list_pt ptr;//�̵��ϴ� ���
	list_pt tail;//���� ������ ���
	int nodeNum;//��� ����
}cirList;

void printList(list_pt ptr);//Circular LInked List����Լ�
void reversePrintList(list_pt ptr);//Circular Linke List ��������Լ�
void freeList(list_pt head, list_pt ptr);//�����޸� �����Լ�

void main()
{
	int n = 0;//�Է¹��� ���ڸ� ����, ��� ���ڸ� �Է¹���������
	int skipNum = 0;//������ ��ȣ�� �����ϴ� ����
	int wayNum = 1;//������ �����ϴ� ����
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
		temp->prev = NULL;//temp�� link�� NULL����
		temp->next = NULL;//temp�� link�� NULL����

		if (temp->num == 1)//head�� ����Ű�� ��尡 NULL�϶�(�����϶�, ù��° ��带 ����)
		{
			ptList->head = temp;//Head�� temp�� ����Ŵ
			ptList->tail = temp;//tail�� temp�� ����Ŵ
			temp->prev = temp;//�ڱ��ڽ��� ����Ŵ
			temp->next = temp;
		}
		else//ù��° �Է��� �ƴҶ� �տ� ����
		{
			temp->prev = ptList->tail;
			temp->next = ptList->head;//�̵��ϴ� �����͸� ù��° ��带 ����Ű���Ѵ�.
			ptList->tail->next = temp;//������� next�� ���ο� ��忡 ����
			ptList->head->prev = temp;//ù����� prev�� ���ο� ��忡 ����
			ptList->tail = temp;//tail�� ��������带 ����Ű�� �̵���Ŵ
		}
		ptList->nodeNum++;//�ο��� üũ, ��尳�� ����
		printf("������ Doubly Circular Linked List�� ");
		printList(ptList);//LInked List����Լ�void reversePrintList(list_pt ptr);
		printf("������ ���� Doubly Circular Linked List�� ");
		reversePrintList(ptList);//Linked List �������� ���
	}
	printf("���� node������%d�Դϴ�.\n", ptList->nodeNum);

	//�Ѹ� �����ϴ� �ڵ�
	ptList->ptr = ptList->head;//ptr�� ó���� ����Ű����

	while (ptList->nodeNum > 3)//3���� �ƴѵ���(3���� ���� �� ����)
	{
		skipNum = (rand() % (ptList->nodeNum))+1;//nodeNum�������� ���ڸ� ����
		printf("\n******Skip Number�� %d�Դϴ�.*******\n", skipNum);
		if (wayNum % 2 == 1)//Ȧ���̸� �������� �̵�
		{
			for (int i = 1; i < skipNum; i++)
			{
				ptList->ptr = ptList->ptr->next;//skipNum��ŭ �������̵�
			}
			printf("�������� %d��ŭ �̵��մϴ�.\n", skipNum);
			printf("Ż���� ����� %d�� %s�Դϴ�.\n", ptList->ptr->next->num, ptList->ptr->next->name);

			if (ptList->ptr->next == ptList->head)//�����ϰ����ϴ� ��带 head�� ����Ű�� ���� ��
			{
				ptList->head = ptList->ptr->next->next;//head�� ���� head����� ���� ��带 ����Ű���Ѵ�.
				ptList->ptr->next = ptList->ptr->next->next;//���� ���� ����
				ptList->ptr->next->prev = ptList->ptr;//��������� prev�� ����
				(ptList->nodeNum)--;//��� �� ����
			}
			else if (ptList->ptr->next == ptList->tail)//�����ϰ����ϴ� ��带 tail�� ����Ű�� ���� ��
			{
				ptList->tail = ptList->ptr;//tail�� ���� tail����� ���� ��带 ����Ű�� �Ѵ�.
				ptList->ptr->next = ptList->ptr->next->next;//���� ���� ����
				ptList->ptr->next->prev = ptList->ptr;//��������� prev�� ����
				(ptList->nodeNum)--;//��� �� ����
			}
			else
			{
				ptList->ptr->next = ptList->ptr->next->next;//�������� ����
				ptList->ptr->next->prev = ptList->ptr;//��������� prev�� ����
				(ptList->nodeNum)--;//��������
			}
			printList(ptList);//LInked List����Լ�
		}
		else if(wayNum % 2 ==0)
		{
			for (int i = 1; i < skipNum-1; i++)
			{
				ptList->ptr = ptList->ptr->prev;//skipNum��ŭ �������̵�
			}
			printf("�������� %d��ŭ �̵��մϴ�.\n", skipNum-1);
			printf("Ż���� ����� %d�� %s�Դϴ�.\n", ptList->ptr->prev->num, ptList->ptr->prev->name);

			if (ptList->ptr->prev == ptList->head)//�����ϰ����ϴ� ��带 head�� ����Ű�� ���� ��
			{
				ptList->head = ptList->ptr; //head�� ���� head����� ���� ��带 ����Ű���Ѵ�.
				ptList->ptr->prev = ptList->ptr->prev->prev;//���� ���� ����
				ptList->ptr->prev->next = ptList->ptr;
				(ptList->nodeNum)--;//��� �� ����
			}
			else if (ptList->ptr->prev == ptList->tail)//�����ϰ����ϴ� ��带 tail�� ����Ű�� ���� ��
			{
				ptList->tail = ptList->ptr->prev->prev;//tail�� ���� tail����� ���� ��带 ����Ű�� �Ѵ�.
				ptList->ptr->prev = ptList->ptr->prev->prev;//���� ���� ����
				ptList->ptr->prev->next = ptList->ptr;
				(ptList->nodeNum)--;//��� �� ����
			}
			else
			{
				ptList->ptr->prev = ptList->ptr->prev->prev;//���� ���� ����
				ptList->ptr->prev->next = ptList->ptr;
				(ptList->nodeNum)--;//��������
			}
			printList(ptList);//LInked List����Լ�
		}

		if (ptList->nodeNum == 3)//3���� ������ ��
		{
			printf("\n-------------�����Ϸ�--------------\n");
			printf("�������ߵ� 3���� ");
			printList(ptList);//���������� ���� 3�� ���
			break;
		}
		wayNum++;
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
			tmp = tmp->next;
		} while (tmp != pt->head);
		printf("�Դϴ�.\n");
	}
}

void reversePrintList(cirList* pt)
{
	list_pt tmp;
	tmp = pt->tail;

	if (pt->tail) {
		do
		{
			printf("%d��-", tmp->num);//tmp�� ����Ű�� num�� ���
			printf("%s ", tmp->name);//tmp�� ����Ű�� name�� ���
			tmp = tmp->prev;
		} while (tmp != pt->tail);
		printf("�Դϴ�.\n\n");
	}
}

void freeList(list_pt head, list_pt ptr)
{
	while (head != NULL)//�Ҵ���� �޸𸮸� ������Ŵ
	{
		ptr = head;
		head = ptr->next;//ù��° ��带 �ٲ�
		free(ptr);//��带 ������Ŵ
	}
}