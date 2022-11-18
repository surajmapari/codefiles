import java.util.*;

public class myoptimal {
    public static void pageReplacement(int numberOfFrames, int pages[]) {
        HashSet<Integer> frames = new HashSet<>(numberOfFrames);
        HashMap<Integer, Integer> index = new HashMap<>();
        int pagefaults = 0, hits = 0;
        for (int i = 0; i < pages.length; i++) {
            if (frames.size() < numberOfFrames) {
                if (!frames.contains(pages[i])) {
                    frames.add(pages[i]);
                    index.put(pages[i], nextIndex(pages, i));
                    pagefaults++;
                } else {
                    hits++;
                    index.put(pages[i], nextIndex(pages, i));
                }
            } else {
                if (!frames.contains(pages[i])) {
                    int farthest = Integer.MIN_VALUE;
                    int val = Integer.MIN_VALUE;
                    Iterator<Integer> itr = frames.iterator();
                    while (itr.hasNext()) {
                        int temp = itr.next();
                        if (index.get(temp) > farthest) {
                            farthest = index.get(temp);
                            val = temp;
                        }
                    }
                    frames.remove(val);
                    frames.add(pages[i]);
                    pagefaults++;
                    // index.remove(farthest);
                    index.put(pages[i], nextIndex(pages, i));
                } else {
                    hits++;
                    index.put(pages[i], nextIndex(pages, i));
                }
            }
            System.out.println("Iterating Hashmap...");
            System.out.println("Current frame is: " + frames);
        }
        System.out.println("Number of Page Faults : " + pagefaults);
        System.out.println("Hits:\t" + hits);
        System.out.println("Hit Percentage: " + ((double) hits / (double) pages.length) * 100 + "%");
    }

    public static int nextIndex(int pages[], int curIndex) {
        for (int i = curIndex + 1; i < pages.length; i++) {
            if (pages[curIndex] == pages[i]) {
                return i;
            }
        }
        return Integer.MAX_VALUE;
    }

    public static void main(String[] args) {
        int numberOfFrames = 3;
        int pages[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3 };
        // System.out.print("Enter the size of frame: ");
        // Scanner scanner = new Scanner(System.in);
        // int numberOfFrames = scanner.nextInt();
        // System.out.print("Enter the total number of pages: ");
        // int numberOfPages = scanner.nextInt();
        // int pages[] = new int[numberOfPages];
        // for (int i = 0; i < numberOfPages; i++) {
        // pages[i] = scanner.nextInt();
        // }
        // scanner.close();
        pageReplacement(numberOfFrames, pages);
    }
}
