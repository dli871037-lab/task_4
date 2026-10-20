/*******************************
* Автор: Ли Даниил             *
* Задание: Циклы с ветвлениями *
* Вариант: 13                  *
*******************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  constexpr int countOfDigitsAfterPoint = 3;
  constexpr int countOfEmptyPlace = 60;
  constexpr int finishStep = 4;

  double t1, t2, wide1, wide2, lambda1, lambda2,
         wallCoord, thermalCond1, thermalCond2, t_c;

  cout << "Inner wall temperature, C: ";
  cin >> t1;
  cout << "Outer wall temperature, C: ";
  cin >> t2;
  cout << "Inner layer thickness, centimeters: ";
  cin >> wide1;
  cout << "Outer layer thickness, centimeters: ";
  cin >> wide2;
  cout << "Inner layer thermal conductivity: ";
  cin >> lambda1;
  cout << "Outer layer thermal conductivity: ";
  cin >> lambda2;

  thermalCond1 = lambda1 / wide1;
  thermalCond2 = lambda2 / wide2;
  t_c = (thermalCond1 * t1 + thermalCond2 * t2) / (thermalCond1 + thermalCond2);

  cout << endl
       << setprecision(countOfDigitsAfterPoint)
       << "Temperature at the layer interface: " << t_c << endl
       << setw(countOfEmptyPlace) << "x" << endl;

  for (int iterations = 0; iterations < finishStep; ++iterations) {

    double tempCoord;

    cout << "The temperature of the wall at the location: ";
    cin >> tempCoord;

    if (tempCoord > t_c) {
      wallCoord = (tempCoord - t1) / (t_c - t1) * wide1;
    } else {
      wallCoord = (tempCoord - t_c) / (t2 - t_c) * wide2 + wide1;
    }

    cout << setw(countOfEmptyPlace) << wallCoord / 100.0 << endl;
  }
  
  return 0;
}
