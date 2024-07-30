def round_robin(n, execution_time, timer):
    waiting_time = [0] * n
    remaining_time = execution_time[:]
    t = 0

    while True:
        done = True
        for i in range(n):
            if remaining_time[i] > 0:
                done = False
                if remaining_time[i] > timer:
                    t += timer
                    remaining_time[i] -= timer
                else:
                    t += remaining_time[i]
                    waiting_time[i] = t - execution_time[i]
                    remaining_time[i] = 0
        if done:
            break

    turnaround_time = [execution_time[i] + waiting_time[i] for i in range(n)]
    total_waiting_time = sum(waiting_time)
    total_turnaround_time = sum(turnaround_time)
    avg_waiting_time = total_waiting_time / n
    avg_turnaround_time = total_turnaround_time / n

    print("Process\tExecution Time\tWaiting Time\tTurnaround Time")
    for i in range(n):
        print(f"{i+1}\t{execution_time[i]}\t\t{waiting_time[i]}\t\t{turnaround_time[i]}")
    print(f"\nTotal Waiting Time = {total_waiting_time}")
    print(f"Total Turnaround Time = {total_turnaround_time}")
    print(f"\nAverage Waiting Time = {avg_waiting_time:.2f}")
    print(f"Average Turnaround Time = {avg_turnaround_time:.2f}")

if __name__ == "__main__":
    n = int(input("Enter number of processes: "))
    execution_time = [int(input(f"Enter execution time for process {i+1}: ")) for i in range(n)]
    timer = int(input("Enter time timer: "))
    round_robin(n, execution_time, timer)
