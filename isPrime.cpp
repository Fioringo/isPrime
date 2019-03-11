#include <iostream>
#include <cmath>
#include <chrono>
#include <omp.h>

using namespace std;
using namespace std::chrono;

string convertToString(bool a);
// void makePrimeCache(long long a[1000]);

bool isPrimeAS(long long a);
bool isPrimeBS(long long a);
bool isPrimeCS(long long a);
// bool isPrimeDS(long long a, long long b[1000]);

bool isPrimeAM(long long a);
bool isPrimeBM(long long a);
bool isPrimeCM(long long a);
// bool isPrimeDM(long long a, long long b[1000]);

int main(){
    bool as, am, bs, bm, cs, cm, ds, dm;
    duration<double> tas, tam, tbs, tbm, tcs, tcm, tds, tdm;
    long long a;

    // long long primeCache[1000];

    // makePrimeCache(primeCache);

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

    // cout << "D: Single: " << endl;
    // start = high_resolution_clock::now();
    // ds = isPrimeDS(a, primeCache);
    // end = high_resolution_clock::now();
    // cout << convertToString(ds) << endl;
    // tds = duration_cast<duration<double>>(end - start);

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

    cout << "C: Multi: " << endl;
    start = high_resolution_clock::now();
    cm = isPrimeCM(a);
    end = high_resolution_clock::now();
    cout << convertToString(cm) << endl;
    tcm = duration_cast<duration<double>>(end - start);

    // cout << "A: Multi: " << endl;
    // start = high_resolution_clock::now();
    // dm = isPrimeDM(a, primeCache);
    // end = high_resolution_clock::now();
    // cout << convertToString(dm) << endl;
    // tdm = duration_cast<duration<double>>(end - start);

    cout << "-------------------------------" << endl;

    cout << "AS: " << convertToString(as) << " " << tas.count() << endl;
    cout << "BS: " << convertToString(bs) << " " << tbs.count() << endl;
    cout << "CS: " << convertToString(cs) << " " << tcs.count() << endl;
    // cout << "DS: " << convertToString(ds) << " " << tds.count() << endl;

    cout << "-------------------------------" << endl;

    cout << "AM: " << convertToString(am) << " " << tam.count() << endl;
    cout << "BM: " << convertToString(bm) << " " << tdm.count() << endl;
    cout << "CM: " << convertToString(cm) << " " << tcm.count() << endl;
    // cout << "DM: " << convertToString(dm) << " " << tdm.count() << endl;

    return 0;
}

// 1000th prime number = 7919
// void makePrimeCache(long long a[1000]){
//     int counter = 0;
//     for(int i = 2; i < 7920; ){
//         if(isPrimeCS){
//             a[counter] = i;
//             ++counter;
//         }
//     }
// }


string convertToString(bool a){
    if(a)
        return "|   Is Prime!   |";
    return "| Is not Prime! |";
}

//=====================================================================
// Single threaded calculations for a specific number to be prime

bool isPrimeAS(long long a){
    for(long long i = 2; i < a; ++i){
        if(a % i == 0){
            cout << "AS: i: " << i << endl;
            return false;
        }
    }
    return true;
}

bool isPrimeBS(long long a){
    if(a % 2 == 0)
        return false;
    for(long long i = 3; i < a / 2 + 1; i = i + 2){
        if(a % i == 0){
            cout << "BS: i: " << i << endl;
            return false;
        }
    }
    return true;
}

bool isPrimeCS(long long a){
    long long b = sqrt(a);
    if(a % 2 == 0 || a == b * b)
        return false;
    for(long long i = 3; i < a / 2 + 1; i = i + 2){
        if(a % i == 0){
            cout << "CS: i: " << i << endl;
            return false;
        }
    }
    return true;
}

// bool isPrimeDS(long long a, long long b[1000]){
//     long long aa = sqrt(a);
//     if(a % 2 == 0 || a == aa * aa)
//         return false;
//     if(a < 7920){
//         for(int i = 0; i < 1000; ++i){
//             if(b[i] == a)
//                 return true;
//             else
//                 return false;
//         }
//     }
//     for(int i = 7920; i < a / 2 + 1; i = i + 2){
//         if(a % i == 0)
//             return false;
//     }
//     return true;
// }

//=====================================================================
// Multi-threaded calculations for a specific number to be prime

bool isPrimeAM(long long a){
    bool result = true;

    #pragma omp parallel for
    for(long long i = 2; i < a; ++i){
        if(a % i == 0){
            cout << "AM: i: " << i << endl;
            result = false;
        }
    }
    return result;
}

bool isPrimeBM(long long a){
    bool result = true;
    if(a % 2 == 0)
        return false;
    #pragma omp parallel for
    for(long long i = 3; i < a / 2 + 1; i = i + 2){
        if(a % i == 0){
            cout << "BM: i: " << i << endl;
            result = false;
        }
    }
    return result;
}

bool isPrimeCM(long long a){
    bool result = true;
    long long b = sqrt(a);
    if(a % 2 == 0 || a == b * b)
        return false;
    #pragma omp parallel for
    for(long long i = 3; i < a / 2 + 1; i = i + 2){
        if(a % i == 0){
            cout << "CM: i: " << i << endl;
            result = false;
        }
    }
    return result;
}

// bool isPrimeDM(long long a, long long b[1000]){
//     bool result = true;
//     long long aa = sqrt(a);
//     if(a % 2 == 0 || a == aa * aa)
//         return false;
//     if(a < 7920){
//         #pragma omp parallel for
//         for(int i = 0; i < 1000; ++i){
//             if(b[i] == a)
//                 result = true;
//         }
//     } else {
//         #pragma omp parallel for
//         for(int i = 7920; i < a / 2 + 1; i = i + 2){
//             if(a % i == 0)
//                 result = false;
//         }
//     }
//     return result;
// }