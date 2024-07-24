#include <stdio.h>
void sortProcesses(int n, int burst_time[], int process_id[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (burst_time[i] > burst_time[j]) {
                int temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
                temp = process_id[i];
                process_id[i] = process_id[j];
                process_id[j] = temp;
            }
        }
    }
}
void calculateWaitingTime(int n, int burst_time[], int waiting_time[]) {
    waiting_time[0] = 0;
    for (int i = 1; i < n; i++) {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
    }
}
void calculateTurnAroundTime(int n, int burst_time[], int waiting_time[], int turn_around_time[])
{
    for (int i = 0; i < n; i++) {
        turn_around_time[i] = burst_time[i] + waiting_time[i];
    }
}
void calculateAverageTime(int n, int burst_time[], int process_id[]) {
    int waiting_time[n], turn_around_time[n];
    int total_waiting_time = 0, total_turn_around_time = 0;
    sortProcesses(n, burst_time, process_id);
    calculateWaitingTime(n, burst_time, waiting_time);
    calculateTurnAroundTime(n, burst_time, waiting_time, turn_around_time);
    printf("Process ID  Burst Time  Waiting Time  Turn Around Time\n");
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turn_around_time += turn_around_time[i];
        printf("    %d\t\t%d\t\t%d\t\t%d\n", process_id[i], burst_time[i], waiting_time[i], turn_around_time[i]);
    }
    printf("Total waiting time: %d",total_waiting_time);
    printf("\nTotal turn around time: %d",total_turn_around_time);
    printf("\nAverage Waiting Time = %f", (float)total_waiting_time / n);
    printf("\nAverage Turn Around Time = %f\n", (float)total_turn_around_time / n);
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int burst_time[n], process_id[n];
    for (int i = 0; i < n; i++) {
        process_id[i] = i + 1; // Assign process ID
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }
    calculateAverageTime(n, burst_time, process_id);
    return 0;
}
