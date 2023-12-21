//-----------------------------------------------------------------------------
// Mika Peer Shalem, mpeersha
// 2023 Winter CSE101, PA6
// BigIntegerTest.cpp
// A Test that uses all manipulation and access functions.
//-----------------------------------------------------------------------------

#include "BigInteger.h"
using namespace std;

int main() {
    printf("---BASIC TESTS---\n");
    string s = "1";    BigInteger BI = BigInteger(s);
    string s1 = "3";   BigInteger BI1 = BigInteger(s1);
    cout << "Are " << BI << " and " << BI1 << " equal: " << BI.compare(BI1) << "\n" << endl;
    string s2 = "2";    BigInteger BI2 = BigInteger(s2);
    string s3 = "2";   BigInteger BI3 = BigInteger(s3);
    BI2 += BI1;
    cout << "s2 + s1 = " << BI2 << endl;
    cout << "Are " << BI2 << " and " << BI3 << " equal: " << BI2.compare(BI3) << "\n" << endl;
    BI2.makeZero();
    cout << "BI2 = " << BI2 << endl;
    string s4 = "3";    BigInteger BI4 = BigInteger(s4);
    string s5 = "1";   BigInteger BI5 = BigInteger(s5);
    cout << "Are " << BI4 << " and " << BI5 << " equal: " << BI4.compare(BI5) << "\n" << endl;
    bool test = BI1<=BI2;
    cout << "Is " << BI1 << " <= " << BI2 << ": " << test << endl;
    test = BI1>=BI2;
    cout << "Is " << BI1 << " >= " << BI2 << ": " << test << endl;
    test = BI1==BI2;
    cout << "Is " << BI1 << " == " << BI2 << ": " << test << endl;
    test = BI1<BI2;
    cout << "Is " << BI1 << " < " << BI2 << ": " << test << endl;
    test = BI1>BI2;
    cout << "Is " << BI1 << " > " << BI2 << ": " << test << endl;
    string s6 = "000000000040000000000022";
    BigInteger BI6 = BigInteger(s6);
    cout << "New BI = " << BI6 << endl;
    printf("---COMPARE---\n");
    s6 = "-325861875496867109579356892360271";    BI6 = BigInteger(s6);
    s5 = "-65234856307582340074883928579823745234876123"; BI5 = BigInteger(s5);
    cout << "Numbers are: " << BI5.to_string() <<", " << BI6.to_string() << endl;
    cout << "Compare s5 and s6: " << BI5.compare(BI6) << endl;
    s6 = "325861875496867109579356892360271";    BI6 = BigInteger(s6);
    s5 = "-65234856307582340074883928579823745234876123"; BI5 = BigInteger(s5);
    cout << "Numbers are: " << BI5.to_string() <<", " << BI6.to_string() << endl;
    cout << "Compare s5 and s6: " << BI5.compare(BI6) << endl;
    s6 = "-325861875496867109579356892360271";    BI6 = BigInteger(s6);
    s5 = "65234856307582340074883928579823745234876123"; BI5 = BigInteger(s5);
    cout << "Numbers are: " << BI5.to_string() <<", " << BI6.to_string() << endl;
    cout << "Compare s5 and s6: " << BI5.compare(BI6) << endl;
    s6 = "-325861875496867109579356892360271";    BI6 = BigInteger(s6);
    s5 = "-325861875496867109579356892360271"; BI5 = BigInteger(s5);
    cout << "Numbers are: " << BI5.to_string() <<", " << BI6.to_string() << endl;
    cout << "Compare s5 and s6: " << BI5.compare(BI6) << endl;
    s6 = "-6573875190";    BI6 = BigInteger(s6);
    s5 = "-5471540863"; BI5 = BigInteger(s5);
    cout << "Numbers are: " << BI5.to_string() <<", " << BI6.to_string() << endl;
    cout << "Compare s5 and s6: " << BI5.compare(BI6) << endl;
    s6 = "6573875190";    BI6 = BigInteger(s6);
    s5 = "5471540863"; BI5 = BigInteger(s5);
    cout << "Numbers are: " << BI5.to_string() <<", " << BI6.to_string() << endl;
    cout << "Compare s5 and s6: " << BI5.compare(BI6) << endl;
    s6 = "-6573875190";    BI6 = BigInteger(s6);
    s5 = "5471540863"; BI5 = BigInteger(s5);
    cout << "Numbers are: " << BI5.to_string() <<", " << BI6.to_string() << endl;
    cout << "Compare s5 and s6: " << BI5.compare(BI6) << endl;
    s6 = "6573875190";    BI6 = BigInteger(s6);
    s5 = "-5471540863"; BI5 = BigInteger(s5);
    cout << "Numbers are: " << BI5.to_string() <<", " << BI6.to_string() << endl;
    cout << "Compare s5 and s6: " << BI5.compare(BI6) << endl;

    printf("\n---TEST SUM---\n");
    // pos + pos = pos
    string s7 = "532985701982235981";    BigInteger BI7 = BigInteger(s7);
    string s8 = "1245000000089532718000005932517";   BigInteger BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    BigInteger sum = BI7+(BI8); 
    cout << "Sum = " << sum << endl; // 1,245,000,000,090,065,703,701,988,168,498
    // pos + neg = neg
    s7 = "532985701982235981";     BI7 = BigInteger(s7);
    s8 = "-1245000000089532718000005932517";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    sum = BI7.add(BI8);
    cout << "Sum = " << sum << endl; // -1,245,000,000,088,999,732,298,023,696,536
    // pos + neg = 0
    s7 = "1245000000089532718000005932517";     BI7 = BigInteger(s7);
    s8 = "-1245000000089532718000005932517";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    sum = BI7.add(BI8);
    cout << "Sum = " << sum << endl; // 0
    // neg + pos = pos
    s7 = "-532985701982235981";     BI7 = BigInteger(s7);
    s8 = "1245000000089532718000005932517";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    sum = BI7.add(BI8);
    cout << "Sum = " << sum << endl; // 1,245,000,000,088,999,732,298,023,696,536
    // neg + pos = neg
    s7 = "-1245000000089532718000005932517";     BI7 = BigInteger(s7);
    s8 = "532985701982235981";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    sum = BI7.add(BI8);
    cout << "Sum = " << sum << endl; // -1,245,000,000,088,999,732,298,023,696,536
    // neg + pos = 0
    s7 = "-532985701982235981";     BI7 = BigInteger(s7);
    s8 = "532985701982235981";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    sum = BI7.add(BI8);
    cout << "Sum = " << sum << endl; // 0
    // neg + neg = neg
    s7 = "-532985701982235981";     BI7 = BigInteger(s7);
    s8 = "-1245000000089532718000005932517";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    sum = BI7.add(BI8); 
    cout << "Sum = " << sum << endl; // -1,245,000,000,090,065,703,701,988,168,498
    // pos - pos = pos
    s7 = "121211";     BI7 = BigInteger(s7);
    s8 = "-121200";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    sum = BI7.add(BI8); 
    cout << "Sum = " << sum << endl; // 11

    printf("\n---TEST DIFF---\n");
    // pos - pos = pos
    s7 = "0000234560000000007887654567654321";     BI7 = BigInteger(s7);
    s8 = "23752711082401929152";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    BigInteger diff = BI7-BI8;
    cout << "Diff = " << diff << endl; // 234,559,999,976,255,176,572,165,725,169
    // pos - pos = neg
    s7 = "23752711082401929152";     BI7 = BigInteger(s7);
    s8 = "0000234560000000007887654567654321";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    diff = BI7.sub(BI8); 
    cout << "Diff = " << diff << endl; // -234,559,999,976,255,176,572,165,725,169
    // pos - pos = 0
    s7 = "0000234560000000007887654567654321";     BI7 = BigInteger(s7);
    s8 = "0000234560000000007887654567654321";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    diff = BI7.sub(BI8); 
    cout << "Diff = " << diff << endl; // 0 
    // pos - neg = pos
    s7 = "23752711082401929152";     BI7 = BigInteger(s7);
    s8 = "-0000234560000000007887654567654321";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    diff = BI7.sub(BI8);
    cout << "Diff = " << diff << endl; // 234,560,000,023,760,598,736,969,583,473
    // neg - pos = neg
    s7 = "-23752711082401929152";     BI7 = BigInteger(s7);
    s8 = "0000234560000000007887654567654321";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    diff = BI7.sub(BI8); 
    cout << "Diff = " << diff << endl; // -234,560,000,023,760,598,736,969,583,473
    // neg - neg = pos
    s7 = "-23752711082401929152";     BI7 = BigInteger(s7);
    s8 = "-0000234560000000007887654567654321";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    diff = BI7.sub(BI8); 
    cout << "Diff = " << diff << endl; // 234,559,999,976,255,176,572,165,725,169
    // neg - neg = neg
    s7 = "-0000234560000000007887654567654321";     BI7 = BigInteger(s7);
    s8 = "-23752711082401929152";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    diff = BI7.sub(BI8); 
    cout << "Diff = " << diff << endl; // -234,559,999,976,255,176,572,165,725,169
    // neg - neg = 0
    s7 = "-0000234560000000007887654567654321";     BI7 = BigInteger(s7);
    s8 = "-0000234560000000007887654567654321";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    diff = BI7.sub(BI8); 
    cout << "Diff = " << diff << endl; // 0
    // pos - pos = pos
    s7 = "121211";     BI7 = BigInteger(s7);
    s8 = "121200";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    diff = BI7.sub(BI8); 
    cout << "Diff = " << diff << endl; // 11

    printf("\n---TEST MULT---\n");
    // pos * pos = pos
    s7 = "537289081452000002384793200100";     BI7 = BigInteger(s7);
    s8 = "01085130801943862";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    BigInteger mult = BI7*BI8; 
    cout << "Mult = " << mult << endl; // 583,028,931,831,689,752,637,260,181,694,781,959,532,786,200
    // pos * neg = neg
    s7 = "537289081452000002384793200100";     BI7 = BigInteger(s7);
    s8 = "-01085130801943862";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    mult = BI7.mult(BI8);
    cout << "Mult = " << mult << endl; // -583,028,931,831,689,752,637,260,181,694,781,959,532,786,200
    // neg * pos = neg
    s7 = "-537289081452000002384793200100";     BI7 = BigInteger(s7);
    s8 = "01085130801943862";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    mult = BI7.mult(BI8);
    cout << "Mult = " << mult << endl; // -583,028,931,831,689,752,637,260,181,694,781,959,532,786,200
    // neg * neg = pos
    s7 = "-537289081452000002384793200100";     BI7 = BigInteger(s7);
    s8 = "-01085130801943862";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    mult = BI7.mult(BI8);
    cout << "Mult = " << mult << endl; // 583,028,931,831,689,752,637,260,181,694,781,959,532,786,200
    // pos * 0 = 0
    s7 = "537289081452000002384793200100";     BI7 = BigInteger(s7);
    s8 = "0";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    mult = BI7.mult(BI8);
    cout << "Mult = " << mult << endl; // 0
    // neg * 0 = 0
    s7 = "-537289081452000002384793200100";     BI7 = BigInteger(s7);
    s8 = "0";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    mult = BI7.mult(BI8);
    cout << "Mult = " << mult << endl; // 0

    printf("\n---MORE ARITHMETRIC TESTS---\n");
    s7 = "999";     BI7 = BigInteger(s7);
    s8 = "999";     BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    sum = BI7.add(BI8);
    cout << "Sum = " << sum << endl;
    mult = BI7.mult(BI8);
    cout << "Mult = " << mult << endl;
    s7 = "659179";    BI7 = BigInteger(s7);
    s8 = "882133";    BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    sum = BI7.add(BI8); cout << "Sum = " << sum << endl;
    diff = BI7.sub(BI8); cout << "Diff = " << diff << endl;
    mult = BI7.mult(BI8); cout << "Mult = " << mult << endl;
    s7 = "653";      BI7 = BigInteger(s7);
    s8 = "-98273";   BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    sum = BI7.add(BI8); cout << "Sum = " << sum << endl;
    mult = BI7.mult(BI8); cout << "Mult = " << mult << endl;
    s7 = "4826780200032";    BI7 = BigInteger(s7);
    s8 = "3290000035220001";    BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    sum = BI7.add(BI8); cout << "Sum = " << sum << endl;
    diff = BI7.sub(BI8); cout << "Diff = " << diff << endl;
    mult = BI7.mult(BI8); cout << "Mult = " << mult << endl; // 15,880,107,028,104,483,471,907,240,032
    s7 = "0";      BI7 = BigInteger(s7);
    s8 = "-98273";   BI8 = BigInteger(s8);
    cout << "Numbers are: " << BI7.to_string() <<", " << BI8.to_string() << endl;
    sum = BI7.add(BI8); cout << "Sum = " << sum << endl;
    mult = BI7.mult(BI8); cout << "Mult = " << mult << endl; // 0
    return 0;
}