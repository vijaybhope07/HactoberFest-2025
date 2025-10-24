import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class GraphTraversalInteractive {

  private int vertices;
  private ArrayList<LinkedList<Integer>> adj; // Use ArrayList instead of array

  // Constructor
  GraphTraversalInteractive(int v) {
    vertices = v;
    adj = new ArrayList<>();
    for (int i = 0; i < v; i++) {
      adj.add(new LinkedList<>());
    }
  }

  // Add edge
  void addEdge(int src, int dest) {
    adj.get(src).add(dest);
    adj.get(dest).add(src); // undirected graph
  }

  // BFS
  void bfs(int start) {
    boolean[] visited = new boolean[vertices];
    Queue<Integer> queue = new LinkedList<>();
    visited[start] = true;
    queue.add(start);

    System.out.print("BFS Traversal: ");
    while (!queue.isEmpty()) {
      int node = queue.poll();
      System.out.print(node + " ");
      for (int neighbor : adj.get(node)) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          queue.add(neighbor);
        }
      }
    }
    System.out.println();
  }

  // DFS
  void dfs(int start) {
    boolean[] visited = new boolean[vertices];
    System.out.print("DFS Traversal: ");
    dfsUtil(start, visited);
    System.out.println();
  }

  void dfsUtil(int node, boolean[] visited) {
    visited[node] = true;
    System.out.print(node + " ");
    for (int neighbor : adj.get(node)) {
      if (!visited[neighbor]) {
        dfsUtil(neighbor, visited);
      }
    }
  }

  // Main method
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("Enter number of vertices: ");
    int v = sc.nextInt();
    GraphTraversalInteractive graph = new GraphTraversalInteractive(v);

    System.out.print("Enter number of edges: ");
    int e = sc.nextInt();

    System.out.println("Enter edges (source destination):");
    for (int i = 0; i < e; i++) {
      int src = sc.nextInt();
      int dest = sc.nextInt();
      graph.addEdge(src, dest);
    }

    System.out.print("Enter starting vertex: ");
    int start = sc.nextInt();

    System.out.println("Choose traversal method: 1 for BFS, 2 for DFS");
    int choice = sc.nextInt();

    if (choice == 1) graph.bfs(start);
    else if (choice == 2) graph.dfs(start);
    else System.out.println("Invalid choice!");
  }
}
