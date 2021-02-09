/*
 * BellmanFord algorithm implementation to find shortest path from a source vertex to all other vertices
 * Algorithm:-
 * for i = 1 to |v| - 1
 * 	for each edges
 * 		relax(u, v, w)
 * 
 * Explanation:-
 * 1. For 1st iteration, we would move one step ahead since shortest path will definitely contain one of the edges from the source
 * 2. For next iteration, we would move another step ahead... and so on
 * 3. This can go at most |v| - 1 times
 *
 * Detect negative weight cycle
 * 1. Iterate one more time, if any vertices get relaxed, then negative weight cycle
 *
 * To remove all negative weight cycles
 * 1. Run the algo one more time, if a vertex gets reduced, then mark it as infinity
 *
 * Works with:-
 * Undirected/Directed/Positive Weights/Negative Weights
 *
 * Time complexity:-
 * O(VE) worst cast E can go to V^2 so O(V^3)
 *
 * @author: Rohit Chakraborty (rohchakr.github.io)
 *
 */


 
