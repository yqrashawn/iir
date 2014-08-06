#include "main.h"

using namespace std;

int main(int argc, char** argv)
{
	ifstream fin;
	if (argc > 1)
		fin.open(argv[1]);
	else fin.open("factor.txt");

	ofstream fout;
	if (argc > 2)
		fout.open(argv[2]);
	else fout.open("out.csv");

	try {
		if (!fin.is_open())
			throw invalid_argument("error: Can't open the input file.");
		if (!fout.is_open())
			throw invalid_argument("error: Can't open the output file.");
	}
	catch (const invalid_argument& e) {
			cerr << "error: Invalid argument error." << endl;
			cerr << e.what() << endl;
			fin.close(); fout.close();
			exit(1);
	}

  vector<double> fa, fb;
	Freq f;
	try {
		read_factor(fin, f, fa, fb);
	}
	catch (invalid_argument& e) {
		cerr << "error: Invalid argument error." << endl;
		cerr << e.what() << endl;
		fin.close(); fout.close();
		return 1;
	}
	catch (...) {
		cerr << "error: read_factor () unknown exception." << endl;
		return 1;
	}

	cout << "factor a:" << endl;
	show(fa);
	cout << "factor b:" << endl;
	show(fb);
	cout << setprecision(8);
	cout << " begin = " << setw(8) << right << f.begin << endl;
	cout << " end   = " << setw(8) << right << f.end   << endl;
	cout << " count = " << setw(8) << right << f.count << endl;
	cout << setprecision(6);

  cout << "Press any key to continue ('q' to quit)" << endl;
  string t;
	cin >> t;
	if(t.find('q') != string::npos) {
		cerr << "quit" << endl;
		fin.close(); fout.close();
		return 1;
	}

	vector<complex<double> > v;
	iir(v, f, fa, fb);

	comp_write(fout, f, v);

	fin.close();
	fout.close();

	return 0;
}

void show(const vector<double>& v)
{
	for (decltype(v.size()) i = 0; i != v.size(); ++i)
		cout << setw(20) << right << v[i] << endl;
}

void comp_write(ostream& fout, const Freq& f, const vector<complex<double> >& v)
{
	// a: phase, d: group delay
	vector<double> a, d;

	// calculate phase and group delay
	arg_group_delay(a, d, v, f.count);

  double fr = f.begin;
	// write freq, amplitude, phase, and group delay (separated by comma)
	for (decltype(v.size()) i = 0; i != v.size(); ++i) {
		fout << fr << "," << abs(v[i]) << "," << 20.*log10(abs(v[i])) << "," << a[i] << "," << d[i] << endl;
		fr += f.count;
	}
}
