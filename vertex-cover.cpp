#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*
----------Primeira parte----------
*/
bool isVertexCover(vector<pair<int, int>>& I, vector<int>& S) {
    // Verifica cada aresta em I
    for (const auto& edge : I) {
        int u = edge.first;
        int v = edge.second;
        
        // Verifica se nem u nem v estão presentes em S
        if (find(S.begin(), S.end(), u) == S.end() && find(S.begin(), S.end(), v) == S.end()) {
            cout << "Está não é uma solução válida para a instância I do problema Vertex-Cover." << endl;
            return false;
        }
    }
    cout << "Está é uma solução válida para a instância I do problema Vertex-Cover." << endl;
    return true;
}

/*
----------Segunda parte----------
*/

vector<int> findIndependentSet(vector<pair<int, int>>& I) {
    unordered_set<int> independentSet; // Conjunto para armazenar os vértices independentes
    
    // Verifica cada aresta em I
    for (const auto& edge : I) {
        int u = edge.first;
        int v = edge.second;
        
        // Adiciona u e v ao conjunto se não estiverem presentes
        if (independentSet.find(u) == independentSet.end()) {
            independentSet.insert(u);
        }
        if (independentSet.find(v) == independentSet.end()) {
            independentSet.insert(v);
        }
    }
    
    vector<int> result(independentSet.begin(), independentSet.end()); // Converte o conjunto para um vetor
    
    cout << "Conjunto Independente: ";
    for (const auto& vertex : result) {
        cout << vertex << " ";
    }
    cout << endl;

    return result;
}

int main() {
    // Exemplo de uso
    vector<pair<int, int>> I = {{1, 2}, {2, 3}, {3, 4}}; // Instância do problema Vertex-Cover
    vector<int> S = {1, 3}; // Solução proposta para I (Válido)
    vector<int> S2 = {1, 4}; // Solução proposta para I (Inválido)
    
    isVertexCover(I, S);
    isVertexCover(I, S2);
    vector<int> independentSet = findIndependentSet(I); // Conjunto independente de I

    
    
    return 0;
}