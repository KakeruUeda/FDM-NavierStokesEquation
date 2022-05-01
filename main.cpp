#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

int main()
{
  int xn = 64;
  int yn = 64;
  double u[xn + 2][yn + 1], v[xn + 1][yn + 2], p[xn + 1][yn + 1];
  double u_top = 10;
  int L[10][10] = {};

  for (int j = 1; j <= 3; j++)
  {
    for (int i = 1; i <= 3; i++)
    {
      L[i + (j - 1) * 3][i + (j - 1) * 3] = 10;
      for (int ii = i - 1; ii <= i + 1; ii = ii + 2)
      {
        if (ii > 0 && ii <= 3)
        {
          L[i + (j - 1) * 3][ii + (j - 1) * 3] = 1;
        }
        else
        {
          L[i + (j - 1) * 3][i + (j - 1) * 3] = L[i + (j - 1) * 3][i + (j - 1) * 3] + 1;
        }
      }
      for (int jj = j - 1; jj <= j + 1; jj = jj + 2)
      {
        if (jj > 0 && jj <= 3)
        {
          L[i + (j - 1) * 3][i + (jj - 1) * 3] = 2;
        }
        else
        {
          L[i + (j - 1) * 3][i + (j - 1) * 3] = L[i + (j - 1) * 3][i + (j - 1) * 3] + 2;
        }
      }
    }
  }
  for (int i = 1; i < 10; i++)
  {
    L[1][i] = 0;
  }
  L[1][1] = 1;

  for (int j = 1; j < 10; j++)
  {
    for (int i = 1; i < 10; i++)
    {
      cout << L[j][i] << "   ";
    }
    cout << "\n";
    cout << "\n";
  }
  return 0;
}