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
    duration<double> as, am, bs, bm, cs, cm, ds, dm;
    long long a;

    cout << "===============================" << endl;
    cout << "=     Welcome to isPrime!     =" << endl;
    cout << "===============================" << endl;
    cout << "Please enter a number: ";
    cin >> a;

    

    return 0;
}