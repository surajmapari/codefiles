import java.util.*;

public class allpagereplacement {
    public static void performLRUReplacement(int numberOfFrames, int page[]) {
        HashSet<Integer> frames = new HashSet<>(numberOfFrames);
        HashMap<Integer, Integer> index = new HashMap<>();
        int pageFaults = 0, hits = 0;

        for (int i = 0; i < page.length; i++) {
            if (frames.size() < numberOfFrames) {
                if (!frames.contains(page[i])) {
                    frames.add(page[i]);
                    index.put(page[i], i);
                    pageFaults++;
                } else {
                    hits++;
                    index.put(page[i], i);
                }
            } else {
                if (!frames.contains(page[i])) {
                    int lru = Integer.MAX_VALUE;
                    int val = Integer.MIN_VALUE;
                    Iterator<Integer> itr = frames.iterator();
                    while (itr.hasNext()) {
                        int temp = itr.next();
                        if (index.get(temp) < lru) {
                            lru = index.get(temp);
                            val = temp;
                        }
                    }
                    frames.remove(val);
                    frames.add(page[i]);
                    pageFaults++;
                    index.put(page[i], i);
                } else {
                    hits++;
                    index.put(page[i], i);
                }
            }
            System.out.println("Iterating Hashmap...");
            System.out.println("Current frame is: " + frames);
            Iterator<Integer> itr = frames.iterator();
            while (itr.hasNext()) {
                int temp = itr.next();
                System.out.println("Index: " + index.get(temp) + " and Value: " + temp);
            }
        }
        System.out.println("Total Number of Page Faults : " + pageFaults);
        System.out.println("Total Hits:\t" + hits);
        System.out.println("Total Hit Percentage: " + ((double) hits / (double) page.length) * 100 + "%");
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
        //     pages[i] = scanner.nextInt();
        // }
        // scanner.close();
        performLRUReplacement(numberOfFrames, pages);
    }
}

/*  
    FOR FIFO ERASE THE LINE AFTER hits++;
    index.put(page[i], i);

    FOR OPTIMAL REPLACEMENT ADD THIS FUNCTION
    public static int nextIndex(int pages[], int curIndex) {
        for (int i = curIndex + 1; i < pages.length; i++) {
            if (pages[curIndex] == pages[i]) {
                return i;
            }
        }
        return Integer.MAX_VALUE;
    }

    PUT THIS EVERYWHERE INSTEAD OF index.put(page[i], i);
    index.put(pages[i], nextIndex(pages, i));
    
    PUT THIS INSTEAD OF 
    int farthest = Integer.MIN_VALUE;
    int lru = Integer.MAX_VALUE;

*/