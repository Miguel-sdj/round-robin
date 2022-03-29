#include<iostream>
#include <queue>
using namespace std;

int main(){

        const int MAX_VECTOR = 100;
        int qtdProcess;
        int valueQuantum;

        cout << "Digite a quantidade de processos: ";
        cin >> qtdProcess;

        cout << "Digite o valor de quantum: ";
        cin >> valueQuantum;


        int arrivalTime[MAX_VECTOR];
        int burstTime[MAX_VECTOR];
        int burstRemaining[MAX_VECTOR];

        for(int i = 0; i < qtdProcess; i++){
                cin >> arrivalTime[i];
                cin >> burstTime[i];
                burstRemaining[i] = burstTime[i];
        }



        cout << "RR \n";
        return 0;
}