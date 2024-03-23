#include <iostream>
#include "Header.h"

int main()
{
    srand(time(NULL));
    /// LB 3
    Set A = Set(rand() % (9 - 6+1) + 6, 10, 99, 5);
    cout << "Print A " << A.f7(',') << " len " << A.f6() << "\n";
    Set B = Set(rand() % (9 - 6+1) + 6, 10, 99, 10);
    cout << "Print B " << B.f7(',') << " len " << B.f6() <<"\n";
    cout << "B contains A " << A.f9(&B)<<"\n";
    cout << "A contains A " << A.f9(&A) << "\n";
    cout << "B is A " << A.f10(&B) << "\n";
    cout << "A is A " << A.f10(&A) << "\n";

    Set BA = A.f11(&B);
    cout << "B+A " << BA.f7(',') << " len " << BA.f6() << "\n";

    Set BCrosA = A.f12(&B);
    cout << "B crosses A " << BCrosA.f7(',') << " len " << BCrosA.f6() << "\n";

    Set BMinA = A.f13(&B);
    cout << "a - b " << BMinA.f7(',') << " len " << BMinA.f6() << "\n";
    Set AMinB = B.f13(&A);
    cout << "b - a " << AMinB.f7(',') << " len " << AMinB.f6() << "\n";

    Set BMinSimA = B.f14(&A);
    cout << "b - simmetrily a " << BMinSimA.f7(',') << " len " << BMinSimA.f6() << "\n";
}
