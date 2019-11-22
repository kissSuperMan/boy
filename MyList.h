#pragma once
//#include "MapUnit.h"
//	链表最底层的实现
// 节点类
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

//链表类
class MyList
{
public:
	MyNode* firstNode = new MyNode(nullptr);
	MyNode* LastNode = new MyNode(nullptr);

public:
							
	~MyList()																							//析构链表
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
		firstNode->node = nullptr;		//		他的node节点对于我无用
		LastNode->node = nullptr;
		firstNode->prePtr = LastNode;
		firstNode->nextPtr = LastNode;
		LastNode->nextPtr = firstNode;
		LastNode->prePtr = firstNode;	//对最后的两个节点处理
	}

	MyNode* add(MapUnit* getMap)		//add的操作是在last的前一个插入,返回值是该节点的指针
	{
		MyNode* one =new MyNode(getMap);
		one->nextPtr = LastNode;
		one->prePtr = LastNode->prePtr;
		LastNode->prePtr->nextPtr = one;
		LastNode->prePtr = one;
		
		return one;						//为了防止要用，现在没用
	}
	bool deleteNode(MapUnit* whichNode)
	{
		for (MyNode* one = this->firstNode->nextPtr; one !=this->LastNode ;one =one->nextPtr )
		{
			if (one->node == whichNode)
			{
				one->nextPtr->prePtr = one->prePtr;					//删除节点，把下一个的前一个改成自己的前一个
				one->prePtr->nextPtr = one->nextPtr;				//自己前一个的下一个改成自己的下一个
				
				delete one;
				return true;
			}
		}
		return false;									//没找到
	}
	void clear()													//保留清除所有节点，但是保留first和last
	{
		MyNode* prePtr = nullptr;
		for (MyNode* one = this->firstNode->nextPtr; one != this->LastNode; one = one->nextPtr)
		{
			prePtr = one->prePtr;
			one->nextPtr->prePtr = one->prePtr;					//删除节点，把下一个的前一个改成自己的前一个
			one->prePtr->nextPtr = one->nextPtr;				//自己前一个的下一个改成自己的下一个
//			one->node->destoryMe();
			delete one;
			one = prePtr;
		}
	}
};









