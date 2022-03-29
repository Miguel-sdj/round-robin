#include <iostream>
#include <queue> 
#include <cstring>

using namespace std;

struct process {
        int arrivalTime;
        int burstTime;
        int startTime;
        int completionTime;
        int turnaroundTime;
        int waitingTime;
        int responseTime;
};


int main(){
        int processAmount;
        int quantumValue;
        int burst_remaining[100];
        struct process processObject[10];

        cout <<"numero de processos: ";
        cin >> processAmount;

        cout << "valor de quantum: ";
        cin >> quantumValue;
        

        for (int i = 0; i < processAmount; i++){
                cin >> processObject[i].arrivalTime;
                cin >> processObject[i].burstTime;

                burst_remaining[i] = processObject[i].burstTime;
                
        }

        int total_turnaround_time = 0;
        int total_waiting_time = 0;
        int total_response_time = 0;
        int total_idle_time = 0;
        int indexArray;


        queue<int> fila_cpp;
        int currentTime = 0;
        fila_cpp.push(0);
        int finished = 0;
        int dummy[100];
        memset(dummy, 0, sizeof(dummy));
        dummy[0] = 1;

        while(finished != processAmount){
                indexArray = fila_cpp.front();
                fila_cpp.pop();

                if (burst_remaining[indexArray] == processObject[indexArray].burstTime){
                        processObject[indexArray].startTime = max(currentTime,processObject[indexArray].arrivalTime);
                        total_idle_time += processObject[indexArray].startTime - currentTime;
                        currentTime = processObject[indexArray].startTime;
                }

                if (burst_remaining[indexArray]-quantumValue > 0){
                        burst_remaining[indexArray] -= quantumValue;
                        currentTime += quantumValue;
                }
                else{
                        currentTime += burst_remaining[indexArray];
                        burst_remaining[indexArray] = 0;
                        finished++;

                        processObject[indexArray].completionTime = currentTime;
                        processObject[indexArray].turnaroundTime = processObject[indexArray].completionTime - processObject[indexArray].arrivalTime;
                        processObject[indexArray].waitingTime = processObject[indexArray].turnaroundTime - processObject[indexArray].burstTime;
                        processObject[indexArray].responseTime = processObject[indexArray].startTime - processObject[indexArray].arrivalTime;

                        total_turnaround_time += processObject[indexArray].turnaroundTime;
                        total_waiting_time += processObject[indexArray].waitingTime;
                        total_response_time += processObject[indexArray].responseTime;
                }

                for(int i = 1; i < processAmount; i++){
                        if (burst_remaining[i] > 0 && processObject[i].arrivalTime <= currentTime && dummy[i] == 0){
                                fila_cpp.push(i);
                                dummy[i] = i;
                        }
                }

                if(burst_remaining[indexArray] > 0){
                        fila_cpp.push(indexArray);
                }

                if(fila_cpp.empty()) {
                        for (int i = 1; i < processAmount; i++){
                                if(burst_remaining[i] > 0){
                                        fila_cpp.push(i);
                                        dummy[i] = 1;
                                        break;
                                }
                        }
                }


        }

        float mediaTurnaroundTime;
        float mediaWaitingTime;
        float mediaResponseTime;

        mediaTurnaroundTime = (float) total_turnaround_time / processAmount;
        mediaWaitingTime = (float) total_waiting_time / processAmount;
        mediaResponseTime = (float) total_response_time / processAmount;

        cout << "RR "<< mediaTurnaroundTime << " " <<  mediaResponseTime << " "  << mediaWaitingTime;
}