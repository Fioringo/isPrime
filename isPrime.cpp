#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

string convertToString(bool a);
bool isPrimeAS(long long a);
bool isPrimeBS(long long a);
bool isPrimeCS(long long a);
bool isPrimeDS(long long a);

bool isPrimeAM(long long a);
bool isPrimeBM(long long a);
bool isPrimeCM(long long a);
bool isPrimeDM(long long a);

int main(){
    bool as, am, bs, bm, cs, cm, ds, dm;
    duration<double> tas, tam, tbs, tbm, tcs, tcm, tds, tdm;
    long long a;

    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;

    cout << "===============================" << endl;
    cout << "=     Welcome to isPrime!     =" << endl;
    cout << "===============================" << endl;
    cout << "Please enter a number: ";
    cin >> a;

    while(a < 3){
        cout << "Please enter a number larger than 2: ";
        cin >> a;
    }

    cout << "-------------------------------" << endl;
    cout << "Number: " << a << endl;
    cout << "-------------------------------" << endl;

//=====================================================================
// Single threaded calculations for a specific number to be prime

    cout << "A: Single: " << endl;
    start = high_resolution_clock::now();
    as = isPrimeAS(a);
    end = high_resolution_clock::now();
    cout << convertToString(as) << endl;
    tas = duration_cast<duration<double>>(end - start);

    cout << "B: Single: " << endl;
    start = high_resolution_clock::now();
    bs = isPrimeBS(a);
    end = high_resolution_clock::now();
    cout << convertToString(bs) << endl;
    tbs = duration_cast<duration<double>>(end - start);

    cout << "C: Single: " << endl;
    start = high_resolution_clock::now();
    cs = isPrimeCS(a);
    end = high_resolution_clock::now();
    cout << convertToString(cs) << endl;
    tcs = duration_cast<duration<double>>(end - start);

    cout << "D: Single: " << endl;
    start = high_resolution_clock::now();
    ds = isPrimeDS(a);
    end = high_resolution_clock::now();
    cout << convertToString(ds) << endl;
    tds = duration_cast<duration<double>>(end - start);

//=====================================================================
// Multi-threaded calculations for a specific number to be prime

    cout << "A: Multi: " << endl;
    start = high_resolution_clock::now();
    am = isPrimeAM(a);
    end = high_resolution_clock::now();
    cout << convertToString(am) << endl;
    tam = duration_cast<duration<double>>(end - start);

    cout << "B: Multi: " << endl;
    start = high_resolution_clock::now();
    bm = isPrimeBM(a);
    end = high_resolution_clock::now();
    cout << convertToString(bm) << endl;
    tbm = duration_cast<duration<double>>(end - start);

    cout << "A: Multi: " << endl;
    start = high_resolution_clock::now();
    cm = isPrimeCM(a);
    end = high_resolution_clock::now();
    cout << convertToString(cm) << endl;
    tcm = duration_cast<duration<double>>(end - start);

    cout << "A: Multi: " << endl;
    start = high_resolution_clock::now();
    dm = isPrimeDM(a);
    end = high_resolution_clock::now();
    cout << convertToString(dm) << endl;
    tdm = duration_cast<duration<double>>(end - start);

    return 0;
}

