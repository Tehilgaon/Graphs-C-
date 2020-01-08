#pragma once
#include <iostream>
#include <list>
using namespace std;

class Edge;
class Vertex;

class Vertex
{
	string Key;
	int color;
	int d;
	list<Edge> EdgeList;
	double f;
	Vertex* pi;
	


};
class Edge
{
	Vertex* vSource;
	Vertex* vDestination;
	int distance;

};
class graphs
{
};

