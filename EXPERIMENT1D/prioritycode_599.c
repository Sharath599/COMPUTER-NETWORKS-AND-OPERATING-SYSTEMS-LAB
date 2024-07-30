def priority_scheduling(n, execution_time, priority):
    waiting_time = [0] * n
    turn_around_time = [0] * n
    process = list(range(n))
    
    process.sort(key=lambda i: priority[i])
    
    for i in range(n):
        if i == 0:
            waiting_time[process[i]] = 0
        else:
            waiting_time[process[i]] = waiting_time[process[i - 1]] + execution_time[process[i - 1]]
    
    for i in range(n):
        turn_around_time[process[i]] = execution_time[process[i]] + waiting_time[process[i]]
    
    total_waiting_time = sum(waiting_time)
    total_turnaround_time = sum(turn_around_time)
    avg_waiting_time = total_waiting_time / n
    avg_turnaround_time = total_turnaround_time / n
    
    print("Process\tExecution Time\tPriority\tWaiting Time\tTurnaround Time")
    for i in range(n):
        print(f"{i+1}\t{execution_time[i]}\t\t{priority[i]}\t\t{waiting_time[i]}\t\t{turn_around_time[i]}")
    print(f"\nTotal Waiting Time = {total_waiting_time}")
    print(f"Total Turnaround Time = {total_turnaround_time}")
    print(f"\nAverage Waiting Time = {avg_waiting_time:.2f}")
    print(f"Average Turnaround Time = {avg_turnaround_time:.2f}")

if __name__ == "__main__":
    n = int(input("Enter number of processes: "))
    execution_time = [int(input(f"Enter execution time for process {i+1}: ")) for i in range(n)]
    priority = [int(input(f"Enter priority for process {i+1}: ")) for i in range(n)]
    priority_scheduling(n, execution_time, priority)
