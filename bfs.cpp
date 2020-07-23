#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
char V[5];
int indexof(char ch)
{	for(int i =0;i<5;i++)
	{
		if(ch==V[i])
		return i;	
	}
	cout<<"\nVertex not found !!!";
	return -1;
}

struct nodelist{
	int dest;
	nodelist *next;
	};
nodelist *E[5]={NULL,NULL,NULL,NULL,NULL};
void addedge(int a,int b)
{	
	nodelist *newnode = new nodelist;
	newnode->dest=b;
	if(E[a]==NULL)
	{ 
	E[a]=newnode;
	newnode->next=NULL;
	}
	else{
		nodelist *ptr=E[a];
		while(ptr->next!=NULL)
		ptr=ptr->next;
		ptr->next=newnode;
		newnode->next=NULL;
	}

}
void display()
{
	for(int i=0;i<5;i++)
	{
		cout<<"\nconnected edges of the vertex "<<V[i]<<" are :";
		nodelist *ptr=E[i];
		while(ptr!=NULL)
		{
			cout<<"->"<<V[ptr->dest];
			ptr=ptr->next;
		}

	}

}

bool visited[]={false,false,false,false,false};
bool allvisited()
{
	for(int i=0;i<5;i++)
	{
		if(visited[i]==false)
		return false;
	}
	return true;
}
queue<int> Q;
void BFS2(char a)
{//	cout<<"\nINIT";
	if(allvisited())
	{	while(!Q.empty())
		{
			cout<<" "<<V[Q.front()];
			Q.pop();
		}
		return;
	}
	if(!visited[indexof(a)])
	Q.push(indexof(a));
	visited[indexof(a)]=true;
	 nodelist *temp=E[indexof(a)];
        while(temp!=NULL)
        {       if(!visited[temp->dest])
                {
                Q.push(temp->dest);
//                cout<<" "<<temp->dest;
		visited[temp->dest]=true;
                }
                temp=temp->next;
        }
	cout<<" "<<V[Q.front()];
	Q.pop();
	BFS2(V[Q.front()]);

}
int main()
{	cout<<"Enter the vertices of the list :";
	for(int i=0;i<5;i++)
	{
		cin>>V[i];
	}
	 int x=1;
	 char p,q;
	while(x==1){
		cout<<"\nEnter the vertices to connect :";
		cin>>p>>q;
		addedge(indexof(p),indexof(q));
		addedge(indexof(q),indexof(p));
		cout<<"\nEnter 1 to connect :";
		cin>>x;

	}
	 display();
	char a;
	cout<<"\nENTER THE STARTING NODE :";
	cin>>a;
	cout<<"The BFS sequence of the graph starting from "<<a<<"is :";
	 BFS2(a);
	return 0;
}
