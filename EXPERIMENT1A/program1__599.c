#include <stdio.h>
void calculateWaitingTime(int burst_time[], int n, int waiting_time[]) {
    waiting_time[0] = 0;
    for (int i = 1; i < n; i++) {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
    }
}
void calculateTurnAroundTime(int burst_time[], int n, int waiting_time[], int turn_around_time[]) {
    for (int i = 0; i < n; i++) {
        turn_around_time[i] = burst_time[i] + waiting_time[i];
    }
}
void calculateAverageTime(int burst_time[], int n) {
    int waiting_time[n], turn_around_time[n];
    int total_waiting_time = 0, total_turn_around_time = 0;
    calculateWaitingTime(burst_time, n, waiting_time);
    calculateTurnAroundTime(burst_time, n, waiting_time, turn_around_time);
    printf("Processes  Burst Time  Waiting Time  Turn Around Time\n");
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turn_around_time += turn_around_time[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turn_around_time[i]);
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
    int burst_time[n];
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }
    calculateAverageTime(burst_time, n);
    return 0;
}
