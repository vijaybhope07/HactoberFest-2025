import java.util.*;

public class MooresVotingAlgorithm {

    // Function to find the majority element
    public static int findMajorityElement(int[] nums) {
        int candidate = findCandidate(nums);
        if (isMajority(nums, candidate)) {
            return candidate;
        } else {
            return -1; // No majority element found
        }
    }

    // Function to find the candidate for majority element
    private static int findCandidate(int[] nums) {
        int count = 0, candidate = -1;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }

    // Function to check if the candidate is actually the majority element
    private static boolean isMajority(int[] nums, int candidate) {
        int count = 0;
        for (int num : nums) {
            if (num == candidate) {
                count++;
            }
        }
        return count > nums.length / 2;
    }

    // Main method to test the algorithm
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of elements in the array:");
        int n = scanner.nextInt();
        int[] nums = new int[n];

        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }

        int majorityElement = findMajorityElement(nums);
        if (majorityElement != -1) {
            System.out.println("The majority element is: " + majorityElement);
        } else {
            System.out.println("There is no majority element.");
        }
    }
}
