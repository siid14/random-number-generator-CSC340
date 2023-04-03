#include <iostream>

#include "part2.cpp"

int main() {
  // Generate an amount of students students
  std::vector<Student> students(10);
  int id = 0;
  for (auto& student : students) {
    student.id = id++;
  }

  // Generate 4 groups with class section identifier 11 AM
  std::unordered_map<int, int> groups_11am;
  for (int i = 0; i < 4; i++) {
    groups_11am.insert(std::make_pair(i, 0));
  }

  // Generate 4 groups with class section identifier 12 PM
  std::unordered_map<int, int> groups_12pm;
  for (int i = 0; i < 4; i++) {
    groups_12pm.insert(std::make_pair(i, 0));
  }

  // Assign students to groups
  std::vector<Student> assigned_students = AssignStudents(students, groups_11am);
  assigned_students = AssignStudents(students, groups_12pm);

  // Print results
  std::cout << "Assigned Students:\n";
  PrintStudents(assigned_students);
  std::cout << "\nGroups 11 AM:\n";
  PrintGroups(groups_11am);
  std::cout << "\nGroups 12 PM:\n";
  PrintGroups(groups_12pm);

  return 0;
}