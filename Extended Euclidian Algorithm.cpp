#include <iostream>
using namespace std;

/*

Extended Euclidian Algorithm :-
    
    States -> a•x + b•y = gcd(a,b);
    
    Lets do some calculations
    
    a•x + b•y = gcd(a,b)    ---> eq 1
    
    as, gcd(a,b) = gcd(b,a%b)  ---> eq 2
    
        we can replace
        a with b for some new x say (x1)
        b with a%b for some new y say (y1)
    
    putting these in eq 1
    
    b•x1 + (a%b)•y1 = gcd(b,a%b)
    
    as, the gcd will remain the same

    b•x1 + (a%b)•y1 = gcd(a,b)  ... using eq 2
    
    as,
        a%b == a - floor(a/b) * b

    b•x1 + (a - floor(a/b)•b)•y1 = gcd(a,b)
    b•x1 + a•y1 - floor(a/b)•b•y1 = gcd(a,b)
    
    separating a and b

    a•y1 + b•(x1 - floor(a/b)•y1) = gcd(a,b) ---> eq 3
    
    on comparing eq 1 & eq 3,
    we get
    
        x = y1                     ---> eq 4
        y = x1 - floor(a/b)•y1     ---> eq 5
    
    base case,
    
        when b becomes 0
        a will be gcd
        
    therefore

        a•x + b•y = gcd(a,b) = a
    
    also as b = 0
        
        y can be any real value
        but 0 is taken to make
        eq 5 work

        a•x + 0 = a
        x = 1
    
    finally
        
        what we'll return from base case
        
        -> gcd = a
        -> x = 1
        -> y = 0

*/

struct GCD {
    long long X;
    long long Y;
    long long G;
};

GCD gcdEx(int a, int b) {
    
    if (b == 0) {
        return { 1, 0, a };
    }
    
    GCD g = gcdEx(b, a%b);
    
    return { g.Y, g.X - (a/b) * g.Y, g.G };
}

/*

Input:    a = 30, b = 20
Output:   gcd = 10
          x = 1, y = -1
          
(Note that 30*1 + 20*(-1) = 10)

Input:    a = 35, b = 15
Output:   gcd = 5
          x = 1, y = -2
          
(Note that 35*1 + 15*(-2) = 5)

*/

int main() {
	
	GCD ans;
	int a, b;
	
	a = 30, b = 20;
	
	printf("For A = %d & B = %d\n", a, b);
	
	ans = gcdEx(a, b);
	
	printf("X = %lld\nY = %lld\nG = %lld\n\n\n", ans.X, ans.Y, ans.G);
	
	a = 35, b = 15;
	
	printf("For A = %d & B = %d\n", a, b);
	
	ans = gcdEx(a, b);
	
	printf("X = %lld\nY = %lld\nG = %lld\n", ans.X, ans.Y, ans.G);
	
	return 0;
}