#include "graphs.h"

void Graph::addv(string v1)
{ 
	this->graph.insert(pair<string, Vertex*>(v1, new Vertex(v1)));

}

void Graph::adde(string v1, string v2)
{
	Vertex* ver1 =  graph.at(v1);	
	Vertex* ver2 = graph.at(v2);
	if (ver1 == nullptr||ver2==nullptr)
		return;
	auto it = ver1->getList().begin();
	for (; it != ver1->getList().end(); it++)
	{
		if (it->getvDestination()->getKey() == v2)
			return; 	 
	}
	ver1->setList(Edge(ver2));
 
}

list<Edge> Graph::vertexList(string v1)
{
	Vertex* ver1 = graph.at(v1);
	if (ver1 == NULL)
		throw exception("vertex does nor exist");
	return ver1->getList();  
}

void Graph::printAll()
{
	auto it = graph.begin();
	for (; it != graph.end(); it++)
	{
		cout << it->first << endl;
		auto itList = it->second->getList().begin();
		for (; itList != it->second->getList().end(); itList++)
		{
			cout << '\t' << itList->getvDestination()->getKey();
		}
	}

}

list<int> Graph::DFS()
{
	timer = 0;
	list<int> finishList;
	auto it = graph.begin();
	for (; it != graph.end(); it++)
	{
		it->second->color = true;
		it->second->pi = NULL;
	}
	auto it = graph.begin();
	for (; it != graph.end(); it++)
	{
		if (it->second->color)
			DFS_visit(it->second, finishList);
	}
	return finishList;
 
}

Vertex::Vertex(string key)
{
	 	this->Key = key;
		this->color = true;
		this->d = 0;
		this->f = 0;
		this->pi = nullptr;
  
}
