#include<bits/stdc++.h>
#define ll long long 

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    // a => queen
    // b => king's current
    // c => king's goal

    bool Xcurrent, Ycurrent;
    
    Xcurrent = (bx > ax) ? true : false;
    Ycurrent = (by > ay) ? true : false;

    bool Xgoal, Ygoal;
    Xgoal = (cx > ax) ? true : false;
    Ygoal = (cy > ay) ? true : false;
    
    cout << ((Xcurrent == Xgoal && Ycurrent == Ygoal) ? "YES" : "NO") << "\n";
    
}