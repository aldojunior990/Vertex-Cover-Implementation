#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*
----------Primeira parte----------
*/
bool isVertexCover(vector<pair<int, int>> &I, vector<int> &S)
{
    // Verifica cada aresta em I
    for (const auto &edge : I)
    {
        int u = edge.first;
        int v = edge.second;

        // Verifica se nem u nem v estão presentes em S
        if (find(S.begin(), S.end(), u) == S.end() && find(S.begin(), S.end(), v) == S.end())
        {
            cout << "Está não é uma solução válida para a instância I do problema Vertex-Cover." << endl;
            return false;
        }
    }
    cout << "Está é uma solução válida para a instância I do problema Vertex-Cover." << endl;
    return true;
}

/*
----------Segunda parte----------
/
/
    função que recebe uma instância I para o problema independet set:
*/

vector<int> findIndependentSet(vector<pair<int, int>> &I)
{
    unordered_set<int> independentSet; // Conjunto para armazenar os vértices independentes

    // Verifica cada aresta em I
    for (const auto &edge : I)
    {
        int u = edge.first;
        int v = edge.second;

        // Adiciona u e v ao conjunto se não estiverem presentes
        if (independentSet.find(u) == independentSet.end())
        {
            independentSet.insert(u);
        }
        if (independentSet.find(v) == independentSet.end())
        {
            independentSet.insert(v);
        }
    }

    vector<int> result(independentSet.begin(), independentSet.end()); // Converte o conjunto para um vetor

    cout << "Conjunto Independente: { ";
    for (const auto &vertex : result)
    {
        cout << vertex << " ";
    }
    cout << "} " << endl;

    return result;
}

/*
    função f responsável pela redução da instância I do problema Independent set para instância f(I) do problema vertex-cover:
*/

vector<pair<int, int>> reduceToVertexCover(vector<int> &I)
{
    vector<pair<int, int>> fI; // Instância f(I) do problema Vertex-Cover

    int numVertices = I.size();
    int numArestas = 0;

    // Criar vértices para representar as arestas em I
    for (int i = 0; i < numVertices; i++)
    {
        int u = i + 1;
        int v = i + 1 + numVertices;
        fI.push_back(make_pair(u, v));
        numArestas++;
    }

    // Criar arestas entre os vértices do conjunto independente I
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = i + 1; j < numVertices; j++)
        {
            if (I[i] != I[j])
            {
                int u = I[i] + numVertices;
                int v = I[j] + numVertices;
                fI.push_back(make_pair(u, v));
                numArestas++;
            }
        }
    }

    // Imprimir a instância reduzida f(I) do problema Vertex-Cover
    cout << "Instância f(I) do problema Vertex-Cover:" << endl;
    for (const auto &edge : fI)
    {
        cout << "(" << edge.first << ", " << edge.second << ")" << endl;
    }

    return fI;
}

/*
    função que recebe a instância f(I) do problema Vertex-Cover, encontra a solução e retorna a resposta S para o problema Vertex-Cover
*/

vector<int> findVertexCover(vector<pair<int, int>> &fI)
{
    unordered_set<int> vertexCover; // Conjunto para armazenar o conjunto de vértices do Vertex-Cover

    // Verifica cada aresta em fI
    for (const auto &edge : fI)
    {
        int u = edge.first;
        int v = edge.second;

        // Adiciona u e v ao conjunto Vertex-Cover
        vertexCover.insert(u);
        vertexCover.insert(v);
    }

    vector<int> result(vertexCover.begin(), vertexCover.end()); // Converte o conjunto para um vetor

    cout << "Vertex-Cover: ";
    for (const auto &vertex : vertexCover)
    {
        cout << vertex << " ";
    }
    cout << endl;

    return result;
}

vector<int> findVertexCover2(vector<pair<int, int>> &fI)
{
    vector<int> vertexCover = {}; // Conjunto para armazenar o conjunto de vértices do Vertex-Cover

    // inicializa um vetor de arestas
    vector<pair<int, int>> arestas = fI;
    // Verifica cada aresta em fI
    for (const auto &e : arestas)
    {
        int u = e.first;
        int v = e.second;

        // Se u e v forem diferentes de 0 são adicionados a resposta
        if (u != 0 && v != 0)
        {
            vertexCover.push_back(u);
            vertexCover.push_back(v);
        }

        // Remove todas as arestas adjacente a u e v do vetor de arestas
        for (auto &i : arestas)
        {
            int x = i.first;
            int y = i.second;
            if (x == u || x == v || y == u || y == v)
            {
                i.first = 0;
                i.second = 0;
            }
        }
    }

    return vertexCover;
}

/*
    implemente uma função h que recebe a resposta S do problema B′ e converta para resposta do problema A′.
    No caso da instância f(I) do problema B′ não tenha solução, diga que não existe solução para instância I.
*/

vector<int> convertAnswer(vector<pair<int, int>> &I, vector<int> &S)
{
    // Inicia um vetor vazio para a resposta
    vector<int> response;

    // Percorre todos os vertices do grafo I
    for (const auto &i : I)
    {

        int u = i.first;
        int v = i.second;

        // Se o vertice u não estiver presente na solução, e não estiver na respota, ele é adicionado ao vetor response
        if (find(S.begin(), S.end(), u) == S.end() && find(response.begin(), response.end(), u) == response.end())
        {
            response.push_back(u);
        }
        // Se o vertice v não estiver presente na solução, e não estiver na respota, ele é adicionado ao vetor response
        if (find(S.begin(), S.end(), v) == S.end() && find(response.begin(), response.end(), u) == response.end())
        {
            response.push_back(v);
        }
    }

    // Retorna a resposta
    return response;
}

int main()
{
    vector<pair<int, int>> I = {{1, 2}, {2, 3}, {3, 4}}; // Instância do problema Vertex-Cover
    vector<pair<int, int>> I2 = {
        {1, 3},
        {2, 1},
        {2, 3},
        {2, 4},
        {2, 5},
        {2, 6}};                                                  // Instância do problema Vertex-Cover
    vector<pair<int, int>> I3 = {{1, 2}, {2, 3}, {4, 1}, {3, 4}}; // Instância do problema Vertex-Cover
    vector<int> S = {1, 3};                                       // Solução proposta para I (Válido)
    vector<int> S2 = {1, 4};
    vector<int> S3 = {2, 3}; // Solução proposta para I (Inválido)
    vector<int> S4 = {2, 4};

    findVertexCover2(I2);

    isVertexCover(I, S);
    isVertexCover(I, S2);
    isVertexCover(I2, S3);
    isVertexCover(I3, S4);

    vector<int> independentSet = findIndependentSet(I); // Conjunto independente de I

    vector<pair<int, int>> fI = reduceToVertexCover(independentSet); // Instância f(I) do problema Vertex-Cover

    vector<int> vertexCover = findVertexCover(fI); // Conjunto de vértices do Vertex-Cover

    vector<int> independentSetResponse = convertAnswer(I2, S3);

    std::cout << "Resposta do independent-set: ";
    for (const auto &element : independentSetResponse)
    {
        std::cout << element << " ";
    }
    std::cout << endl;

    return 0;
}