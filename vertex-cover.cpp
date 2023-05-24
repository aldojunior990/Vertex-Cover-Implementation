#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*
---------- PRIMEIRA PARTE ----------
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
---------- SEGUNDA PARTE ----------
*/

/*
 * função f responsável pela redução da instância I do problema 
 * Independent set para instância f(I) do problema vertex-cover:
*/


/*
 * função que recebe a instância f(I) do problema Vertex-Cover, 
 * encontra a solução e retorna a resposta S para o problema Vertex-Cover
*/

// Função que recebe B ( Vertex-Cover ) e retorna a sua solução
vector<int> findVertexCover(vector<pair<int, int>> &fI)
{
    // Conjunto para armazenar o conjunto de vértices do Vertex-Cover
    vector<int> vertexCover = {};

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

        // Remove todas as arestas adjacentes a u e v do vetor de arestas
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

    cout
        << "Solução Vertex-Cover: ";
    for (const auto &vertex : vertexCover)
    {
        cout << vertex << " ";
    }
    cout << endl;

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
        if (find(S.begin(), S.end(), v) == S.end() && find(response.begin(), response.end(), v) == response.end())
        {
            response.push_back(v);
        }
    }

    // Retorna a resposta
    return response;
}

vector<int> SolucionaA(vector<pair<int, int>> &I) {
    vector<int> resultado = {NULL};
    vector<int> solucao_B = findVertexCover(I);
    
    if (solucao_B.size() != 0) {
        vector<int> solucao_A = convertAnswer(I, solucao_B);
        resultado = solucao_A;
    }
    
    return resultado;
}

int main()
{
    // Instância 1 do problema Vertex-Cover
    vector<pair<int, int>> I = {{1, 2}, {2, 3}, {3, 4}};

    // Instância 2 do problema Vertex-Cover
    vector<pair<int, int>> I2 = {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {2, 5}, {2, 6}};
    
    // Instância 3 do problema Vertex-Cover
    vector<pair<int, int>> I3 = {{1, 2}, {1, 4}, {2, 3}, {2, 4}};
    
    vector<int> S = {1, 3}; // Solução proposta para I (Válido)
    vector<int> S2 = {1, 4}; // Solução proposta para I (Inválido)
    vector<int> S3 = {2, 3}; // Solução proposta para I2 (Válido)
    vector<int> S4 = {2, 4}; // Solução proposta para I3 (Válido)

    // Achando uma solução ótima para a instancia 1
    findVertexCover(I);

    // Achando uma solução ótima para a instancia 2
    findVertexCover(I2);

    // Achando uma solução ótima para a instancia 3
    findVertexCover(I3);

    // Verificando se as soluções são válidas
    isVertexCover(I, S);
    isVertexCover(I, S2);
    isVertexCover(I2, S3);
    isVertexCover(I3, S4);

    // Conversão de S(vertex-cover) -> S(independent-set):
    vector<int> independentSetResponse = SolucionaA(I2);

    if (independentSetResponse.size() != 0 ) {
        cout << "Conversão de S(vertex-cover) -> S(independent-set): ";
        for (const auto &element : independentSetResponse)
        {
            cout << element << " ";
        }
        cout << endl;
    } else {
        cout << "Não existe solução para o grafo dado" << endl;
    }

    return 0;
}