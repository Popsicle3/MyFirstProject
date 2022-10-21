#include <iostream>
using namespace std;

typedef char datatype;
typedef struct lrpNode
{
	datatype data;
	lrpNode* lc, * rc;
	lrpNode() :lc(NULL), rc(NULL) {
	}
}*BTREE;

//����һ�Ŷ�����������ڵ������ֵΪdata�����Һ��ӷֱ�Ϊlc��rc
BTREE create_BTREE(datatype data, BTREE lc, BTREE rc)
{
	BTREE tmp = new lrpNode;
	tmp->data = data;
	tmp->lc = lc;
	tmp->rc = rc;
	return tmp;
}

//�ȸ�����
void preOrder(BTREE T)
{
	if (T == NULL)return;
	cout << T->data;
	preOrder(T->lc);
	preOrder(T->rc);
}

//�и�����
void midOrder(BTREE T)
{
	if (T == NULL)return;
	midOrder(T->lc);
	cout << T->data;
	midOrder(T->rc);
}

//�������
void postOrder(BTREE T)
{
	if (T == NULL)return;
	postOrder(T->lc);
	postOrder(T->rc);
	cout << T->data;
}

//ͳ�ƶ������н��ĸ���
int NodeCount(BTREE T)
{
	if (T == NULL)  return 0; //����ǿ������������Ϊ0, �ݹ������
	else return NodeCount(T->lc) + NodeCount(T->rc) + 1;
}

// ����Ҷ���ĸ��� 
int leafnum(BTREE T)
{
	if (T == NULL)  return 0;
	int cnt = 0;
	if ((!T->lc) && (!T->rc))
	{
		cnt++;//�ж�ΪҶ���
	}
	int leftcnt = leafnum(T->lc);
	int rightcnt = leafnum(T->rc);
	cnt += leftcnt + rightcnt;
	return cnt;
}

// �������������� 
int Depth(BTREE T)
{
	if (T == NULL)    return 0;
	else
	{
		int m = Depth(T->lc);
		int n = Depth(T->rc);
		return m > n ? (m + 1) : (n + 1);
	}
}

//ͳ�ƶ������Ķ�Ϊ1�Ľ������� 
int count1(BTREE T)
{
	int i = 0;
	if (T)
	{
		if ((T->lc == NULL && T->rc != NULL) || (T->lc != NULL && T->rc == NULL))
		{
			i = 1 + count1(T->lc) + count1(T->rc);
		}
		else
		{
			i = count1(T->lc) + count1(T->rc);
		}
	}
	return i;
}

//ͳ�ƶ������Ķ�Ϊ2�Ľ�����
int count2(BTREE T)
{
	int i = 0;
	if (T)
	{
		if (T->lc != NULL && T->rc != NULL)
		{
			i = 1 + count2(T->lc) + count2(T->rc);
		}
		else
		{
			i = count2(T->lc) + count2(T->rc);
		}
	}
	return i;
}

int main()
{
	//	           A
	//          /     \
	//	     B          C
	//     /   \      /
	//	 D      E     F
	//         /       \
	//        G         H
	BTREE t1, t2, t;
	t1 = create_BTREE('G', NULL, NULL), t2 = create_BTREE('E', t1, NULL);
	t1 = create_BTREE('D', NULL, NULL), t2 = create_BTREE('B', t1, t2);
	t1 = create_BTREE('H', NULL, NULL), t1 = create_BTREE('F', NULL, t1);
	t1 = create_BTREE('C', t1, NULL), t = create_BTREE('A', t2, t1);

	postOrder(t);
	int cnt2 = count2(t);
	cout << "��Ϊ2�Ľ������� " << cnt2;
	cout << endl;
	int leafNum = leafnum(t);
	cout << "Ҷ���ĸ����� " << leafNum;
	return 0;
}