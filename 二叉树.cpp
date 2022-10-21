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

//创建一颗二叉树，其根节点的数据值为data，左右孩子分别为lc和rc
BTREE create_BTREE(datatype data, BTREE lc, BTREE rc)
{
	BTREE tmp = new lrpNode;
	tmp->data = data;
	tmp->lc = lc;
	tmp->rc = rc;
	return tmp;
}

//先根遍历
void preOrder(BTREE T)
{
	if (T == NULL)return;
	cout << T->data;
	preOrder(T->lc);
	preOrder(T->rc);
}

//中根遍历
void midOrder(BTREE T)
{
	if (T == NULL)return;
	midOrder(T->lc);
	cout << T->data;
	midOrder(T->rc);
}

//后根遍历
void postOrder(BTREE T)
{
	if (T == NULL)return;
	postOrder(T->lc);
	postOrder(T->rc);
	cout << T->data;
}

//统计二叉树中结点的个数
int NodeCount(BTREE T)
{
	if (T == NULL)  return 0; //如果是空树，则结点个数为0, 递归结束。
	else return NodeCount(T->lc) + NodeCount(T->rc) + 1;
}

// 计算叶结点的个数 
int leafnum(BTREE T)
{
	if (T == NULL)  return 0;
	int cnt = 0;
	if ((!T->lc) && (!T->rc))
	{
		cnt++;//判断为叶结点
	}
	int leftcnt = leafnum(T->lc);
	int rightcnt = leafnum(T->rc);
	cnt += leftcnt + rightcnt;
	return cnt;
}

// 计算二叉树的深度 
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

//统计二叉树的度为1的结点个数； 
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

//统计二叉树的度为2的结点个数
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
	cout << "度为2的结点个数： " << cnt2;
	cout << endl;
	int leafNum = leafnum(t);
	cout << "叶结点的个数： " << leafNum;
	return 0;
}