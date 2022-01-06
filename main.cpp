#include <iostream>
#include <string>
#include <vector>

#include <adjacency_list.h>

int main()
{
    std::cout << "Hello World!\n";

    std::vector<int> numbers{ 1,2,3 };
    std::vector<std::string> strings{ "hello","world" };

    std::string hi{ "hi" };
    std::string yo{ "yo" };
    std::string foo{ "foo" };

    Graph::AdjacencyList adj_list(hi, hi);
    adj_list.add_vertex(hi);
    adj_list.add_vertex(yo);
    //adj_list.find_vertex(foo);
    //adj_list.find_vertex(hi);
    adj_list.add_edge(hi, std::string{ "insert" });
    adj_list.add_edge(foo, std::string{ "insert" });

    auto v = adj_list.get_vertex(hi);

    std::cout << "";

}
