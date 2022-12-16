//This is the First TP to manipulate trees

/* some terms so you wont get confused  

racine == root
inserer == insert
afficher == display
supprimer == delete
nbrNoued == nbr node
infixe GRD= first we need to traverse the whole left subtree, then the root, then the right subtree. This rule must be followed in each subtree.


*/
#include<iostream>
using namespace std ;
struct element {
	
	int cle ;
	element *fg ;
	element *fd ;
};

// To create your own Tree 
void inserer(element *&racine, int x)
{
	if (racine==0)
	{ racine = new element ;
	racine ->fg=0; //*NULL
	racine ->fd=0;
	racine->cle=x;
	}
	else if
	(racine->cle>x)
{
inserer(racine->fg,x);
}
else
{
inserer(racine->fd,x);
}
	}
// To display the  tree
void afficher(element *racine)
{
	if(racine!=0)
	{
		cout<<" infixe GRD"<<"------------";
		afficher(racine->fg);
		cout<<racine->cle<< endl ;
		afficher(racine->fd);
	}
}/*
// to delete an element in your tree 
void supprimer(element *&p)
{
	element *l1,*l2;
	if(p->fg==0&&p->fd==0)
	{
	delete p;
	}

	else{
	element	*&pos=p;
		if(p->fd==0)
		{l1=p;
		p=p->fg;
		delete l1;
		l1=0;
		}
		else
		{
			l1=p->fg; //2 descendants
			if(l1->fd==0)
			{p->cle=l1->cle;
			supprimer(p->fg);
			}
			else
			{
				while(l1->fd!=0)
				{
					l2=l1;l1=l1->fd;
				}
				p->cle=l1->cle;
				supprimer(l1->fd);
			}
		}
	}
}*/
// to find a  numbre in a TREE
void nbrNoeud(element *racine, int &nbr)
{
	if(racine !=NULL)
	{
		nbr= nbr+1 ;
		nbrNoeud(racine->fg,nbr);
		nbrNoeud(racine->fd, nbr);
	}
	}
	//compare two TREES if they are the same or not i didnt call the founction in the main 
int compare(element *a, element *b)
{
	if(a==NULL &&b==NULL)
	{
		return 1;                //  if the trees are identical
	}
	else if(a !=NULL && b !=NULL)
	{
		return ((a->cle == b->cle) && compare( a->fg, b->fg) && compare(a->fd, b->fd));
		return 0;
	}
}
//return  node in a tree  
void trouver_noeud(element *racine, int x )
{
	if(racine==NULL)
	{
		cout<<"Tree is empty" ;
	}
	else if(racine->cle>x)
	{
		trouver_noeud(racine->fg,x);
	
	
	}
	else if(racine->cle<x)
	{
		trouver_noeud(racine->fd,x);
	}
	else if(racine->cle ==x)
	cout<<racine ;
}
// Delete arbre 
void Delete_Arb(element racine)
{
	if(racine=-NULL)
	{
		cout<<"Tree is empty " ;
	}
	else
	 {
	DeleteArb(racine->fg) ;
	DeleteArb(racine->fd);
	delete racine ;
	racine=0;	
	}
}
// founction main and all the calls of the founctions 
int main()
{
	element *racine=0;
	int a,x,n,nbr ;
	cout<<"Gives an element "<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Give a numbre :"<<endl;
		cin>>x;
		inserer(racine,x);
	}
	cout<<"Display The Tree"<<endl;
	afficher(racine); //call the function display Tree
	nbrNoeud(racine,nbr) ; // call the function of nbr of node
	//calls the  fonction trouver_noued a remainder trouver_noued == find noeud 
	cout<<"the totall number of  noeud is"<<nbr;
	cout<< "Give a  value ";
	cin>>a ;
	trouver_noeud(racine,a);
	
}
