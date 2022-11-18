import java.util.*;

public class myroundrobin {
    public static void main(String args[]) {
        int TimeQuantum = 0, Pno = 0, totalsum = -1;
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter the total number of processes: ");
        Pno = sc.nextInt();

        int Burst_time[] = new int[Pno];
        int remBurst_time[] = new int[Pno];
        int WT[] = new int[Pno];
        int TAT[] = new int[Pno];
        
        for (int i = 0; i < Pno; i++) {
            System.out.print("Enter Process[" + (i + 1) + "] Burst time: ");
            Burst_time[i] = sc.nextInt();
            remBurst_time[i] = Burst_time[i];
        }

        System.out.print("\nEnter the Time Quantum: ");
        TimeQuantum = sc.nextInt();
        do {
            for (int i = 0; i < Pno; i++) {
                if (remBurst_time[i] > TimeQuantum) {
                    remBurst_time[i] -= TimeQuantum;
                    for (int j = 0; j < Pno; j++) {
                        if ((j != i) && (remBurst_time[j] != 0))
                            WT[j] += TimeQuantum;
                    }
                } else {
                    for (int j = 0; j < Pno; j++) {
                        if ((j != i) && (remBurst_time[j] != 0))
                            WT[j] += remBurst_time[i];
                    }
                    remBurst_time[i] = 0;
                }
                System.out.println("Process[" + (i + 1) + "] remaining time: " + remBurst_time[i]);
            }
            int sum = 0;
            for (int i = 0; i < Pno; i++){
                sum = sum + remBurst_time[i];
            }
            totalsum = sum;
            System.out.println("------------------------------------------");
        } while (totalsum != 0);

        for (int i = 0; i < Pno; i++){
            TAT[i] = WT[i] + Burst_time[i];
        }
        System.out.println("Process\tBT\tWT\tTAT");
        for (int i = 0; i < Pno; i++) {
            System.out.println((i+1) + "\t" + Burst_time[i] + "\t" + WT[i] + "\t" + TAT[i]);
        }
        float avg_wt = 0, avg_tat = 0;
        for (int j = 0; j < Pno; j++) {
            avg_wt += WT[j];
        }
        for (int j = 0; j < Pno; j++) {
            avg_tat += TAT[j];
        }
        System.out.println("Average waiting time " + (avg_wt / Pno));
        System.out.println("Average turn around time " + (avg_tat / Pno));
        sc.close();
    }
}