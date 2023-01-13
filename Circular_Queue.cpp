#include<iostream>
using namespace std;
int front=-1;
int rear=-1;
int queue[5];
void enque(int x)
{
	if(((rear+1)%5)==front)
	{
		cout<<"Queue Overflow :("<<endl;
	}
	else if((front == -1 )&& (rear == -1))
	{
		front=0;
		rear=0;
		queue[front]=x;
	}
	else
	{
		rear = (rear+1)%5;
		queue[rear] = x;
	}
}
void deque()
{
	if(front==-1 && rear==-1)
	{
		cout<<"Queue Underflow :)"<<endl;
	}
	else if(front==rear)
	{
		cout<<queue[front]<<endl;
		front=-1;
		rear=-1;
	}
	else
	{
		cout<<queue[front]<<endl;
		front =(front+1)%5;
	}
}
void display()
{
	int i = front;
	if(front==-1 && rear==-1)
	{
		cout<<"Queue Is Empty :("<<endl;
	}
	cout<<"Queue Elements : ";
	while(i!=rear)
	{
		cout<<queue[i]<<" ";
		i = (i+1)%5;
	}
	cout<<queue[rear]<<endl;
}
int main()
{
	
	// 0   1   2   3   4
	// 5  10   15
    //     f
    //          r
	enque(5);
	enque(10);
	enque(15);
	deque();
	deque();
	enque(20);
	enque(25);
	enque(30);
	enque(35);
	display();
	
}
