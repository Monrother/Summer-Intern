#include <iostream>
#include <algorithm>

#include <iomanip>
using namespace std;


int main() {
	cout << setiosflags(ios::fixed) << setprecision(3);
	double L, R;
	cin >> L >> R;
	
	cout << R*cos(-L / R) << " " <<R* sin(-L / R) << endl;
	cout << R*cos(L / R) << " " << R*sin(L / R) << endl;

	//printf("%.3f %.3f\n", R*cos(-L / R), R*sin(-L / R));
	//printf("%.3f %.3f\n", R*cos(L / R), R*sin(L / R));
	system("pause");
	return 0;
}
