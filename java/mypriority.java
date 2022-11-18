import java.util.Scanner;

public class mypriority {
    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the total number of Process: ");
        int n = sc.nextInt();
        int pp[] = new int[n];
        int pid[] = new int[n];
        int bt[] = new int[n];
        int ta[] = new int[n];
        int wt[] = new int[n];
        int temp = 0;
        float avgwt = 0, avgta = 0;

        for (int i = 0; i < n; i++) {
            System.out.print("Process[" + (i + 1) + "] Burst Time: ");
            bt[i] = sc.nextInt();
            System.out.print("Process[" + (i + 1) + "] Priority: ");
            pp[i] = sc.nextInt();
            pid[i] = i + 1;
        }
        sc.close();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - (i + 1); j++) {
                if (pp[j] > pp[j + 1]) {
                    temp = pp[j];
                    pp[j] = pp[j + 1];
                    pp[j + 1] = temp;

                    temp = bt[j];
                    bt[j] = bt[j + 1];
                    bt[j + 1] = temp;

                    temp = pid[j];
                    pid[j] = pid[j + 1];
                    pid[j + 1] = temp;
                }
            }
        }

        wt[0] = 0;
        ta[0] = bt[0];
        avgta = ta[0];
        for (int i = 1; i < n; i++) {
            wt[i] = ta[i - 1];
            ta[i] = wt[i] + bt[i];
            avgwt += wt[i];
            avgta += ta[i];
        }

        System.out.println("\nPid\tPriority\tBT\tTAT\tWT");
        for (int i = 0; i < n; i++) {
            System.out.println(
                    pid[i] + "\t" + pp[i] + "\t\t" + bt[i] + "\t" + ta[i] + "\t" + wt[i]);
        }
        System.out.println("Average Turn Around Time : " + (float) (avgta / n));
        System.out.println("Average Wait Time : " + (float) (avgwt / n));
    }
}