#include "TPair.h"

int main()
{
	TPair<int, int> cii(1, 2);
	TPair<float, float> cff(5.43, 3.);
	TPair<double, double> cdd(4.5325, 65.324);
	TPair<int, float> cif(23, 23.);
	TPair<int, double> cid;
	TPair<float, int> cfi;
	TPair<float, double> cfd;
	TPair<double, int> cdi;
	TPair<double, float> cdf;

	cout << "cii: " << cii;
	cout << "cff: " << cff;
	cout << "cdd: " << cdd;
	cout << "cif: " << cif;
	cout << "cdf: " << cdf;

	cii = cii + cii;
	cout << "(cii + cii) cii: " << cii << endl;
	cii.swap();
	cout << "(SWAP) cii:  " << cii;
	cout << cff + cff << endl;
	cif.print();
}