#include<iostream>
#include<string.h>

using namespace std;

int c[20][20],size,ans=0;

class grp
{
	public:
	bool operator==(grp &t)
	{
		if(this->val==t.val)
		return true;
		else
		return false;
	}
    grp *next;
	char val;
	int dist[20];
}g[20],x;

class se
{
	public:
	bool operator==(se &h)
	{
		if(this->z==h.z)
		return true;
		else
		return false;
	}
    int z;
	grp *head;
	grp *tail;
}s[20];

int link(int i,int j)
{
	int k,r,flg;
	grp z;
	((*(s[i].tail)).next)=(s[j].head);
	(s[i].tail)=(s[j].tail);
	z=(*(s[j].head));
	for(k=1;k<=size;k++)
	{
		if(g[k]==z)
		{r=k;}
	}
	while(!((g[r])==x))
	{
		flg=0;
		s[r]=s[i];
		for(k=1;k<=size;k++)
		{
		    if(g[k]==(*(g[r].next)))
		    {
				
				r=k;
		        flg++;
		    }
		    	    
	    }
	    if(flg==0)
	    {
			g[r]=x;
	    }
	} 
	
}

int makeset(int i)
{
	
	char c;
	cout<<"\nenter the char for "<<i<<"\n";
	cin>>c;
	g[i].val=c;
	g[i].next=&x;
	s[i].head=&g[i];
	s[i].tail=&g[i];
	s[i].z=i;
	int j;
	cout<<"\nenter the dist list for "<<i<<"\n";
	for(j=1;j<=size;j++)
	{
		cin>>g[i].dist[j];
	}
	
	
}

se find(int i)
{
	return s[i];
}

int min()
{
	int l,i,j,flag=0;
    
	for(i=1;i<=size;i++)
	{
		for(j=1;j<=size;j++)
		{
			if(c[i][j]>0)
			{
				flag++;
				l=c[i][j];
				j=size+1;
				i=size+1;
			}
		}
	}


	if(flag==0)
	{
		return 0;
	}
	else
	{
		
	for(i=1;i<=size;i++)
	{
		for(j=1;j<=size;j++)
		{
			if(c[i][j]>0)
			{
				if(c[i][j]<l)
				{
					l=c[i][j];					
					
				}
			}
		}
	}
	
	return l;
    }
}
	
	
		
int kruskal()
{
	int i,j,a,b;
	se r,temp1,temp2;
	grp q;
	for(i=1;i<=size;i++)
	{
		makeset(i);
	}

	for(i=1;i<=size;i++)
    {
		
		for(j=1;j<=size;j++)
		{
			c[i][j]=g[i].dist[j];
			
		}
		
	}

	b=min();

	for(i=1;i<=size;i++)
        {
			for(j=1;j<=size;j++)
		    {
				if(c[i][j]==b)
				{
					r=s[i];
					j=size+1;
					i=size+1;
				}
			}
		}
					
	
	for(a=min();a!=0;a=min())
	{
		for(i=1;i<=size;i++)
        {
			for(j=1;j<=size;j++)
		    {
				if(c[i][j]==a)
				{if(i==ans||ans==0)
				{
					c[i][j]=-1;
					c[j][i]=-1;
					temp1=find(i);
					temp2=find(j);
					if(!(temp1==temp2))
					{
						link(i,j);
						cout<<i<<"-"<<j<<"-";
						ans=j;
					}
				}
			    }
			}
		}
	}
	
	q=(*(r.head));
	cout<<"\n";
	while(!(q==x))
	{
		cout<<q.val<<"-";
		q=(*(q.next));
		
	}
	return 0;
}
		
		
int main()
{
	cout<<"\nenter the size\n";
	cin>>size;
	kruskal();
	return 0;
}
			
		
			
	

		
	
	
	
