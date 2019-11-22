#pragma once
//˫����������
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
	int size = 0;		//����
	MyDouNode<Tem>* first = nullptr;			//�ʼ��λ��
	MyDouNode<Tem>* last = nullptr;				//��ĩβ��λ��

public:
	MyDouList()
	{
		size = 0;
	};
	void add(Tem giveNode)											//��ӽڵ�,�������룬first��λ�ò���
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

