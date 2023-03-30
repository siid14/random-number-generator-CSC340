/* Requirements
 * 
 * Given a set of students, S, and a set of groups, G, with 0 to 5 students NOT belonging to S,
 * assigned to each group, randomly assign the students belonging to S to the groups belonging to G so
 * that every student belongs to a group and no group has more than 5 members, and return a list of
 * student in set S and which group they have been assigned to.
 */

/* Data
 *
 * Students (S)
 *  Fields: • identifier (some integer number from 0 to n, where n is the number of students - 1)
 *          • class section identifier (11 AM or 12 PM)
 *  Structure: array, vector, or similar
 *
 * Groups (G)
 *  Fields: • identifier (some integer number from 0 to n, where n is the number of groups - 1)
 *          • class section identifier (11 AM for 12 PM)
 *          • number of members assigned to a particular group
 *  Structure: list of key, value pairs (map)
 */

/* Algorithm
 *
 * • Let s be a student from S so that S = {s0, s1, s2, ..., sn}
 * • Let g be a group from G so that G = {g0, g1, g2, ..., gn}
 *
 * Approach 1:
 * 1) Draw a random number i from the range 0 to |S|
 * • Let j be the identifier of the current group (j is initially 0)
 * 2) If gj (first group) has less than 5 members:
 *    2a) Assign si to gj
 *    2b) Remove si from S
 * 3) Else increment j and and return to step 2
 * 4) Return to step 1 until |S| = 0 (All students have been added to a group)
 *
 * Approach 2:
 * 1) Draw a random number i from the range 0 to |S|
 * 2) Draw a random number j from the range 0 to |G|
 * 3) If gj has less than 5 members:
 *    3a) Assign si to gj
 *    3b) Remove si from S 
 * 4) Else return to step 2
 * 5) Return to step 1 until |S| = 0 (All students have been added to a group)
 *
 * Approach 3:
 * 1) Draw a random number j from the range 0 to |G|
 * • Let i be the ientifier of the current student (i is initially 0)
 * 2) If gj has less than 5 members:
 *    2a) Assign si to gj
 *    2b) Increment i
 * 3) Else do nothing
 * 4) Return to step 1 while i is less than |S|
 */
