#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define IS_EMPTY(ptr) (!(ptr)) //Empty list�� ����ִ��� �׽�Ʈ
#define IS_FULL(ptr) (!(ptr))

typedef struct listNode* list_pt;//����ü�� ����Ű�� ������
typedef struct listNode {
	int num; // �Է¹��� ���ڸ� �����ϴ� ����
	list_pt link; // ����ü ������
}listNode;

void printList(list_pt ptr);//LInked List����Լ�
void freeList(list_pt head, list_pt ptr);//�����޸� �����Լ�

void main()
{
	list_pt head = NULL;//ù��° ����� �ּҰ� ���� �����ͺ���
	list_pt temp = NULL;//���Ӱ� �ԷµǴ� ���� �����ϴ� �����ͺ���
	list_pt ptr = NULL;//��带 �̵��ϸ鼭 ����Ű�� �����ͺ���(�߰��� ������ ��)
	int n = 0, j = 0;//�Է¹��� ���ڸ� ����, ��� ���ڸ� �Է¹���������

	printf("�� ���� ���ڸ� �Է��Ͻðڽ��ϱ� : ");//�Է¹��� ������ ������ �Է¹���
	scanf_s("%d", &j);	

	for (int i = 0; i < j; i++)
	{
		printf("����%d�� �Է��ϼ��� : ", i + 1);//���ڸ� �Է¹���
		scanf_s("%d", &n);

		temp = (list_pt)malloc(sizeof(listNode));//heap������ ������ NULL��ȯ
		if (IS_FULL(temp))
		{
			fprintf(stderr, "�޸𸮰� ����á���ϴ�.\n");
			exit(1);
		}
		temp->num = n;//temp�� num�� �Է¹��� �� ����
		temp->link = NULL;//temp�� link�� NULL����

	//	ptr = head;//ù��° ����� �ּҸ� ����

		if (head == NULL)//head�� ����Ű�� ��尡 NULL�϶�(�����϶�, ù��° ��带 ����)
		{
			head = temp;//�Է¹��� ���ڸ� ptr�� ����Ű���ִ� ù��° ��忡 ����
		}
		else if (temp->num < head->num)//�Է¹��� ���� head�� ������ ������(�Ǿտ� ����)
		{
			temp->link = head;//head(ù��°���)�տ� temp�� �־ ����(�Ǿ�)
			head = temp;//temp�� ù��° ��尡 �ȴ�.
		}
		else//ù��° �Է��� �ƴϰ� ù��°��� ���� ���� Ŭ��
		{
			ptr = head;//�̵��ϴ� �����͸� ù��° ��带 ����Ű���Ѵ�.
			while (ptr->link != NULL) //ptr�� ����Ű�� �����link�� NULL�� �ƴѵ���(������ �����̵�)
			{
				if ((ptr->link)->num < temp->num)//ptr�� ����Ű�� ����� ���� ����� num�� temp�� num���� ������(ptr�� �������� �̵��ؾ���)
					ptr = ptr->link;//ptr�� �������� �̵���Ŵ
				else//ptr�� ����Ű�� ����� ���� ����� num���� temp�� num�� ������
					break;//while���� ��������
			}
			if (ptr->link != NULL)
			{
				temp->link = ptr->link;//ptr�� ����Ű�°��� temp�� �����Ѵ�.
				ptr->link = temp;//ptr�� temp�� ����
			}
			else
			{
				ptr->link = temp;//ptr�� �ڿ� temp�� ����(�ǵ�)
			}
		}
		printList(head,ptr);//LInked List����Լ�
	}
	freeList(head, ptr);//�����޸� �����Լ�

	system("PAUSE");
}

void printList(list_pt head,list_pt ptr)
{
	ptr = head;//ptr�� ó������ �̵���Ŵ

	printf("���ĵ� Linked List�� ");
	while (ptr != NULL)//ptr�� ���尡 �ƴѵ���(����������)
	{
		printf("%d ", ptr->num);//ptr�� ����Ű�� num�� ���
		ptr = ptr->link;//ptr�� �������� �̵���Ŵ
	}
	printf("�Դϴ�.\n");
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