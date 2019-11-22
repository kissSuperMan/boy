#pragma once
//双向链链表类
template<typename Tem>
class MyDouNode
{
public:
	Tem node;
	MyDouNode<Tem>* prePtr;
	MyDouNode<Tem>* nextPtr;
public:
	MyDouNode(Tem getNode){
		this->node = getNode;
	};
		~MyDouNode();
};

template<typename Tem>
class MyDouList
{
public:
	int size = 0;		//长度
	MyDouNode<Tem>* first = nullptr;			//最开始的位置
	MyDouNode<Tem>* last = nullptr;				//最末尾的位置

public:
	MyDouList()
	{
		size = 0;
	};
	void add(Tem giveNode)											//添加节点,在最后插入，first的位置不变
	{
		if (size == 0)
		{
			size++; 
			first = new MyDouNode<Tem>(giveNode);
			last = first;
			first->nextPtr = last;
			first->prePtr = last;
			last->node = first->node;
			last->nextPtr = first;
			last->prePtr = first;
		}
		else
		{
			size++;
			MyDouNode<Tem>* one = new MyDouNode<Tem>(giveNode);
			one->nextPtr = first;
			first->prePtr = one;
			one->prePtr = last;
			last->nextPtr = one;
			last = one;
		}
	}
	~MyDouList()
	{
		
	};
};

