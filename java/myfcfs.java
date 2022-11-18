import java.util.*;

public class myfcfs {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the total number of process: ");
        int n = sc.nextInt();
        int pid[] = new int[n];
        int ar[] = new int[n];
        int bt[] = new int[n];
        int ct[] = new int[n];
        int ta[] = new int[n];
        int wt[] = new int[n];
        int temp;
        float avgwt = 0, avgta = 0;

        for (int i = 0; i < n; i++) {
            System.out.println("Enter process " + (i + 1) + " Arrival time: ");
            ar[i] = sc.nextInt();
            System.out.println("Enter process " + (i + 1) + " Burst time: ");
            bt[i] = sc.nextInt();
            pid[i] = i + 1;
        }
        // sorting according to arrival times
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - (i + 1); j++) {
                if (ar[j] > ar[j + 1]) {
                    temp = ar[j];
                    ar[j] = ar[j + 1];
                    ar[j + 1] = temp;

                    temp = bt[j];
                    bt[j] = bt[j + 1];
                    bt[j + 1] = temp;

                    temp = pid[j];
                    pid[j] = pid[j + 1];
                    pid[j + 1] = temp;
                }
            }
        }
        // finding completion times
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ct[i] = ar[i] + bt[i];
            } else {
                if (ar[i] > ct[i - 1]) {
                    ct[i] = ar[i] + bt[i];
                } else
                    ct[i] = ct[i - 1] + bt[i];
            }
            ta[i] = ct[i] - ar[i];
            wt[i] = ta[i] - bt[i];
            avgwt += wt[i];
            avgta += ta[i];
        }

        System.out.println("\nPid  Arrival  Burst  Complete TA   Waiting");
        for (int i = 0; i < n; i++) {
            System.out.println(pid[i] + "  \t " + ar[i] + "\t" + bt[i] + "\t" + ct[i] + "\t" + ta[i] + "\t" + wt[i]);
        }
        sc.close();
        System.out.println("\nAverage waiting time: " + (avgwt / n));
        System.out.println("Average turnaround time:" + (avgta / n));
    }
}