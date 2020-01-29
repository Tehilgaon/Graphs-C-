#pragma once
#include <iostream>
#include <list>
#include <map>
using namespace std;

class Edge;
class Vertex;

class Vertex
{
	string Key;
	list<Edge> EdgeList;
	
public:
	bool color;
	int d; 
	int f;
	Vertex* pi;
	string getKey() { return Key; }
	list<Edge> getList() { return EdgeList; }
	void setKey(string value) { Key = value; }
	void setList(Edge edge) { EdgeList.push_back(edge); }
	Vertex(string key);
	


};
class Edge
{
	//Vertex* vSource;
	Vertex* vDestination;
	int distance;
public:
	Vertex* getvDestination() { return vDestination; }
	Edge() {}
	Edge(Vertex* v) { vDestination = v; distance = 1; }

};
class Graph
{
	map <string, Vertex*> graph;
	int timer;
public:
	Graph() {}
	void addv(string v1);
	void adde(string v1, string v2);
	list<Edge> vertexList(string v1);
	void printAll();
	void topologicalSort();
	list<int> DFS();
	void DFS_visit(Vertex* v1,list<int>);

};

