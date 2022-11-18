import java.util.*;

public class mysjf {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Number of Process: ");
        int n = sc.nextInt();
        int pid[] = new int[n];
        int ar[] = new int[n];
        int bt[] = new int[n];
        int ct[] = new int[n];
        int ta[] = new int[n];
        int wt[] = new int[n];
        int flag[] = new int[n];
        int rem_BurstTime[] = new int[n];
        float avgwt = 0, avgta = 0;
        for (int i = 0; i < n; i++) {
            pid[i] = i + 1;
            System.out.print("Enter process " + (i + 1) + " Arrival time: ");
            ar[i] = sc.nextInt();
            System.out.print("Enter process " + (i + 1) + " Burst time: ");
            bt[i] = sc.nextInt();
            rem_BurstTime[i] = bt[i];
            flag[i] = 0;
        }
        sc.close();
        while (true) {
            int min = 99, c = n, st = 0, tot  =0;
            if (tot == n){
                break;
            }
            for (int i = 0; i < n; i++) {
                if ((ar[i] <= st) && (flag[i] == 0) && (rem_BurstTime[i] < min)) {
                    min = rem_BurstTime[i];
                    c = i;
                }
            }
            if (c == n) {
                st++;
            } else {
                rem_BurstTime[c]--;
                st++;
                if (rem_BurstTime[c] == 0) {
                    ct[c] = st;
                    flag[c] = 1;
                    tot++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            ta[i] = ct[i] - ar[i];
            wt[i] = ta[i] - bt[i];
            avgwt += wt[i];
            avgta += ta[i];
        }
        System.out.println("Pid  AT  BT  CT TAT WT");
        for (int i = 0; i < n; i++) {
            System.out.println(pid[i] + "\t" + ar[i] + "\t" + bt[i] + "\t" + ct[i] + "\t" + ta[i] + "\t" + wt[i]);
        }
        System.out.println("\nAverage tat is " + (float) (avgta / n));
        System.out.println("Average wt is " + (float) (avgwt / n));
    }
}