#include <iostream>
using namespace std;

class neuron {
public:
	float weight = 0.5;
	float LastError;
	float Smoothing = 0.05;
	float correction;
	float actualResult;
	float ProcessInputData(float input) {
		return input * weight;
	}
	float RestoreInputData(float output) {
		return output / weight;
	}
	void Train(float input, float exprectedResult) {
		actualResult = input * weight;
		LastError = exprectedResult- actualResult;
		correction = (LastError / actualResult);
		weight += correction;
	}
};
int main() {
	float km = 5;
	float miles = 375;
	neuron hi;
	cout << hi.ProcessInputData(km)<< endl;
	int i=0;
	do {
		i++;
		hi.Train(km, miles);
		cout << "Iteration" << " " << i << " " << "Error:" << " " << hi.LastError << endl;
	} while (hi.actualResult > miles+0.01 || hi.actualResult < miles-0.01);
	cin >> km;
	cout << hi.ProcessInputData(km);
	cin >> km;
	cout << hi.ProcessInputData(km);
}