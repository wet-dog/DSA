#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <iostream>
#include <vector>
#include <optional>

namespace Graph {

template<typename VertexProperty, typename EdgeList>
struct Vertex {
	VertexProperty value;
	EdgeList edge_list;
};

template<typename T, typename U>
class AdjacencyList {
	using EdgeProperty = typename T;
	using VertexProperty = typename U;
	using EdgeList = typename std::vector<EdgeProperty>;
	using Vertex = typename Vertex<VertexProperty, EdgeList>;
	using VertexList = typename std::vector<Vertex>;

public:
	VertexList vertices;

	AdjacencyList(EdgeProperty e, VertexProperty v)
	{
	}

	AdjacencyList(VertexList vertex_list)
	{
		vertices = vertex_list;
	}

	// Add unique vertex
	void add_vertex(VertexProperty v)
	{	
		auto vertex = find_vertex(v);
		if (vertex == vertices.end())
			vertices.push_back(Vertex{ v, {} });
	}

	// Add directed edge from vertex u -> v
	void add_edge(VertexProperty u, VertexProperty v)
	{
		auto vertex = find_vertex(u);
		if (vertex != vertices.end()) {
			(*vertex).edge_list.push_back(v);	// Add v to edge list of u
		} else {
			std::cout << "Initial vertex does not exist." << "\n";
		}
	}

	auto find_vertex(VertexProperty v)
	{
		auto is_equal = [v](const Vertex& x) { return v == x.value; };
		auto result = std::find_if(vertices.begin(), vertices.end(), is_equal);
		return result;
	}

	Vertex get_vertex(VertexProperty v)
	{
		auto vertex = find_vertex(v);
		return *vertex;
	}
};

//template<typename T>
//std::ostream& operator<<(std::ostream& os, const AdjacencyList<T>& adj)
//{
//	os << "{ ";	
//	for (const auto& x : adj.edges) {
//		if (x == adj.edges.back())
//			os << x;
//		else
//			os << x << ", ";
//	}	
//	os << " }";
//
//	return os;
//}

}

#endif
