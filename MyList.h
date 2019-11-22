#pragma once
//#include "MapUnit.h"
//	������ײ��ʵ��
// �ڵ���
class MapUnit;
class MyNode
{
public:
	MapUnit* node;
	MyNode* nextPtr;
	MyNode* prePtr;
public:
	MyNode(MapUnit* nodeVal)
	{
		node = nodeVal;
		nextPtr = nullptr;
		prePtr = nullptr;
	}
	~MyNode(){};
};

//������
class MyList
{
public:
	MyNode* firstNode = new MyNode(nullptr);
	MyNode* LastNode = new MyNode(nullptr);

public:
							
	~MyList()																							//��������
	{ 
		MyNode* nextPtr = nullptr;
		for (MyNode* one = this->firstNode->nextPtr; one != this->LastNode; one = one->nextPtr)
		{
			nextPtr = one->nextPtr;
			delete one;
			one = nextPtr;
		}
		delete firstNode; delete LastNode;
	};
	MyList()
	{
		firstNode->node = nullptr;		//		����node�ڵ����������
		LastNode->node = nullptr;
		firstNode->prePtr = LastNode;
		firstNode->nextPtr = LastNode;
		LastNode->nextPtr = firstNode;
		LastNode->prePtr = firstNode;	//�����������ڵ㴦��
	}

	MyNode* add(MapUnit* getMap)		//add�Ĳ�������last��ǰһ������,����ֵ�Ǹýڵ��ָ��
	{
		MyNode* one =new MyNode(getMap);
		one->nextPtr = LastNode;
		one->prePtr = LastNode->prePtr;
		LastNode->prePtr->nextPtr = one;
		LastNode->prePtr = one;
		
		return one;						//Ϊ�˷�ֹҪ�ã�����û��
	}
	bool deleteNode(MapUnit* whichNode)
	{
		for (MyNode* one = this->firstNode->nextPtr; one !=this->LastNode ;one =one->nextPtr )
		{
			if (one->node == whichNode)
			{
				one->nextPtr->prePtr = one->prePtr;					//ɾ���ڵ㣬����һ����ǰһ���ĳ��Լ���ǰһ��
				one->prePtr->nextPtr = one->nextPtr;				//�Լ�ǰһ������һ���ĳ��Լ�����һ��
				
				delete one;
				return true;
			}
		}
		return false;									//û�ҵ�
	}
	void clear()													//����������нڵ㣬���Ǳ���first��last
	{
		MyNode* prePtr = nullptr;
		for (MyNode* one = this->firstNode->nextPtr; one != this->LastNode; one = one->nextPtr)
		{
			prePtr = one->prePtr;
			one->nextPtr->prePtr = one->prePtr;					//ɾ���ڵ㣬����һ����ǰһ���ĳ��Լ���ǰһ��
			one->prePtr->nextPtr = one->nextPtr;				//�Լ�ǰһ������һ���ĳ��Լ�����һ��
//			one->node->destoryMe();
			delete one;
			one = prePtr;
		}
	}
};









