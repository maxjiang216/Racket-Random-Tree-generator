#include <bits/stdc++.h>
using namespace std;

string randomTree(int n) {

  if (n == 0)
    return "empty";

  int l = rand() % n;

  return "(make-node " + randomTree(l) + " " + randomTree(n - l - 1) + ")";
}

int main() {

  srand(time(NULL));

  ofstream outfile;
  outfile.open("out.txt");

  for (int i = 1; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      string temp = randomTree(i);
      cout << temp << endl;
      outfile << "(= (sub1 (node-count " + temp +
                     ")) (node-count (tree-shrink-min " + temp + ")))\n";
    }
  }
  outfile.close();
}
