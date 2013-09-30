#include<iostream>
using namespace std;
int q[20];
int front=0;
int rear=0;
int size;
int a[20][20];

class graph
{
	private:
	  char color[10];
	  int par[10];
	  int dist[10];
	public:
	  int adjalist(int);
	  int bfs(int);
};

int graph::adjalist(int n)
{
	int i,j;
	for(i=0;i<size;i++)
	{
		if(i==n)
		{
			for(j=0;j<size;j++)
			{
				if(a[i][j]==1)
				{
					if(color[j]=='w')
					{
						return j;
					}
				}
			}
			return '\0';
		}
	}
}

void enqueue(int s)
{
	q[rear]=s;
	
	if(rear==20)
	{
		rear=0;
	}
	else
	{
	    rear++;
    }
	
}

int dequeue()
{
	int omit;
	omit=q[front];
	if(front==20)
	{
		front=0;
	}
	else
	{
		front++;
	}
	return omit;
}

int graph::bfs(int s)
{
	int u,v,i,temp;

	
	for(i=0;i<size;i++)
	{
		if(i==s)
		{
			dist[i]=0;
			color[i]='g';
			par[i]='\0';
		}
		else
		{
			dist[i]=100;
		    color[i]='w';
		    par[i]='\0';
			
		}
	}
	enqueue(s);
	while(front!=rear)
	{
		u=dequeue();
		for(v=adjalist(u);v!='\0';v=adjalist(u))
		        {
					color[v]='g';
					temp=u+1;
					par[v]=temp;
					dist[v]=dist[u]+1;
					enqueue(v);
				}
		color[u]='b';
	}		
	
cout<<"the dist of vertices are\n";
for(i=0;i<size;i++)
{
	cout<<"vertex "<<i+1<<":"<<"dist -"<<dist[i]<<" parent -"<<par[i]<<"\n";
}
}	
		
	
		
int main()
{
	int i,j,s;
	cout<<"enter the number of vertices";
	cin>>size;
	for(i=0;i<size;i++)
	{
		cout<<"enter the adjacency list for "<<i+1<<"\n";
		for(j=0;j<size;j++)
		{
			cin>>a[i][j];
		}
	}
	graph grp;
	cout<<"enter the source"<<"\n";
	cin>>s;
	s=s-1;
	grp.bfs(s);
		
    
}
