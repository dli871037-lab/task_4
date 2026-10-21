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

  double t1, t2, wide1, wide2, lambda1, lambda2, tempCoord,
         wallCoord, thermalConductance1, thermalConductance2, tc;
  int temperatureCount;

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
  cout << "Count of temperatures: ";
  cin >> temperatureCount;
  cout << "1 temperature in coordinate: ";

  thermalConductance1 = lambda1 / wide1;
  thermalConductance2 = lambda2 / wide2;
  tc = (thermalConductance1 * t1 + thermalConductance2 * t2) / (thermalConductance1 + thermalConductance2);

  cout << endl
       << setprecision(countOfDigitsAfterPoint)
       << "Temperature at the layer interface: " << tc << endl
       << setw(countOfEmptyPlace) << "x" << endl;

  for (int temperatureIndex = 0; temperatureIndex < temperatureCount; ++temperatureIndex) {

    cout << "The temperature of the wall at the location: ";
    cin >> tempCoord;

    if (tempCoord > tc) {
      wallCoord = (tempCoord - t1) / (tc - t1) * wide1;
    } else {
      wallCoord = (tempCoord - tc) / (t2 - tc) * wide2 + wide1;
    }

    cout << setw(countOfEmptyPlace) << wallCoord / 100.0 << endl;
  }
  
  return 0;
}
