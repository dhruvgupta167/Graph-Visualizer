#include<iostream>
#include<map>
#include<vector>
#include<stdlib.h>
#include<cstring>
using namespace std;

// -------------------------------- DIRECTED GRAPH
template<typename T>
class WGraph
{
	map<T,vector<pair<T, int> > > m;
public:
	int nodes;
	int bidir;

	WGraph(int dir)
	{
		bidir = dir;

		cout<<"Enter number of edges = ";
		cin>>nodes;

		system("clear");
	}

	void addEdge(T src,T dest, int wt)
	{
		m[src].push_back(make_pair(dest, wt));
		if(bidir){
			m[dest].push_back(make_pair(src, wt));
		}
	}

	void printAdjList()
	{
		for(auto p:m)
		{
			cout<<p.first<<"->";
			for(auto node:p.second)
			{
				cout<<"("<<node.first<<","<<node.second<<")";

				cout<<", ";
			}
			cout<<endl;
		}
	}

	void InputEdges()
	{
		for(int i=1; i<=nodes; i++)
		{
			T src, dest;

			cout<<"Enter Edge number "<<i<<"\n\n";
			cout<<"Source: ";
			cin>>src;
			cout<<"Destination: ";
			cin>>dest;
			cout<<"Weighted: ";
			int wt;
			cin>>wt;
			
			addEdge(src, dest, wt);
			system("clear");
			printAdjList();
		}
	}
};

void type1()
{
	cout<<"Specify the Datatype for nodes \n";
	cout<<"Press 1: Integer \n";
	cout<<"Press 2: String\n";

	cout<<"Enter your choice: ";
	int choice;
	cin>>choice;

	if (choice==1)
	{
		cout<<endl;
		cout<<"Is your Graph directed or undirected?"<<'\n';
		cout<<"Press 1 : Undirected\n";
		cout<<"Press 2 : Directed\n";

		cout<<"Enter your choice: ";
		cin>>choice;

		if (choice==2)
		{
			choice = 0;
		}

		system("clear");
		WGraph<int> g(choice);
		
		g.InputEdges();
	}
	else 
	{
		cout<<endl;
		cout<<"Is your Graph directed or undirected?"<<'\n';
		cout<<"Press 1 : Undirected\n";
		cout<<"Press 2 : Directed\n";

		cout<<"Enter your choice: ";
		int direct;
		cin>>direct;

		if (direct==2)
		{
			direct = 0;
		}

		system("clear");
		WGraph<string> g(direct);
		
		g.InputEdges();
	}	
}


// -------------------------------- UNDIRECTED GRAPH

template<typename T>
class UWGraph
{
	map<T,vector<T> > m;
public:
	int nodes;
	int bidir;

	UWGraph(int dir)
	{
		bidir = dir;

		cout<<"Enter number of nodes= ";
		cin>>nodes;

		system("clear");
	}

	void addEdge(T src,T dest)
	{
		m[src].push_back(dest);
		if(bidir){
			m[dest].push_back(src);
		}
	}

	void printAdjList()
	{
		for(auto p:m)
		{
			cout<<p.first<<"->";
			for(auto node:p.second)
			{
				cout<<"("<<node<<")";

				cout<<", ";
			}
			cout<<endl<<endl;
		}
	}

	void InputEdges()
	{
		for(int i=1; i<=nodes; i++)
		{
			T src, dest;

			cout<<"Enter Edge number "<<i<<"\n\n";
			cout<<"Source: ";
			cin>>src;
			cout<<"Destination: ";
			cin>>dest;
			
			addEdge(src, dest);
			system("clear");
			printAdjList();
		}
	}
};

void type2()
{
	cout<<"Specify the Datatype for nodes \n";
	cout<<"Press 1: Integer \n";
	cout<<"Press 2: String\n";

	cout<<"Enter your choice: ";
	int choice;
	cin>>choice;

	if (choice==1)
	{
		cout<<endl;
		cout<<"Is your Graph directed or undirected?"<<'\n';
		cout<<"Press 1 : Undirected\n";
		cout<<"Press 2 : Directed\n";

		cout<<"Enter your choice: ";
		int direct;
		cin>>direct;

		if (direct==2)
		{
			direct = 0;
		}

		system("clear");
		UWGraph<int> g(direct);
		
		g.InputEdges();
	}
	else 
	{
		cout<<endl;
		cout<<"Is your Graph directed or undirected?"<<'\n';
		cout<<"Press 1 : Undirected\n";
		cout<<"Press 2 : Directed\n";

		cout<<"Enter your choice: ";
		cin>>choice;

		if (choice==2)
		{
			choice = 0;
		}

		system("clear");
		UWGraph<string> g(choice);
		
		g.InputEdges();
	}	
}

int main()
{
	system("clear");
	cout<<"Is your Graph weighted?"<<'\n';
	cout<<"Press 1 : Weighted\n";
	cout<<"Press 2 : Unweighted\n";

	cout<<"Enter your choice: ";
	int choice;
	cin>>choice;

	system("clear");
	if (choice==1) {
		type1();
	}
	else {
		cout<<"You choose Unweighted";
		type2();
	}
	
	return 0;
}