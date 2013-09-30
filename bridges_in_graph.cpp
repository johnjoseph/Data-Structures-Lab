#include<iostream>
using namespace std;

int t=0,temp;
int size;

class graph
{
	public:
	 int d; 
	 int l; 
	 int adj[20]; 

}grp[20];
 

 
		
int bridge(int n)
{
	int m,j;
	t++;
	grp[n].d=t;
	grp[n].l=t;
	
	
	for(j=1;j<=size;j++)
	{
		if((grp[n].adj[j]==1)&&(grp[j].d==-1))
		{
			temp=n;
			bridge(j);
			if(grp[j].l>grp[n].d)
			{
				cout<<"\n"<<n<<"-"<<j<<"\n";
			    
			}
			if(grp[j].l<grp[n].l)
			    {
					grp[n].l=grp[j].l;
				}
				else
				{
					grp[n].l=grp[n].l;
				}
			
		}
		
		    else if((grp[n].adj[j]==1)&&(j!=temp))
		    {
				if(grp[n].l>grp[j].d)
				{
					grp[n].l=grp[j].d;
				}
				else
				{
					grp[n].l=grp[n].l;
				}
			}
			
		}
		
				
	return 0;
}
	
	

	
			 

 
	 
		 
int main()
 {
	 int i,j,z;
	 cout<<"\nenter the number of vertices\n";
	 cin>>size;
	 for(i=1;i<=size;i++)
	 {
		 cout<<"the adjacency list for "<<i<<"\n";
		 for(j=1;j<=size;j++)
		 {
			cin>>grp[i].adj[j];
		 }
	 }
	 for(i=1;i<=size;i++)
	 {
		 grp[i].d=-1;
		 
	 }
	 
	 cout<<"\n the bridges are \n";
	 for(i=0;i<=size;i++)
	 {
		 bridge(i);
     }
	 
	 return 0;	 
	 
 }
			
	 
	  
	
	
