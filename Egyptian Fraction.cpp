#include "/storage/emulated/0/Documents/Cxxdroid/headers"
// #include <bits/stdc++.h>
using namespace std;

static const bool ___ = []() {
    ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	return 0;
}();

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

struct Fraction {
    
    int numerator;
    int denominator;
    
    Fraction(int numerator = 0, int denominator = 1) 
    : numerator(numerator),
      denominator(denominator) {
        if (denominator == 0) {
            throw "Denominator can't be Zero!";
        }
    }
    
    vector<Fraction> getEgyptianFraction() const {
        
        Fraction fraction = *this;
        
        vector<Fraction> ans;
        
        if (numerator > denominator) {
            ans.push_back(Fraction(getValue()));
            fraction -= ans.back();
        }
        
        while (fraction.numerator > 1) {
            
            Fraction temp(1, fraction.denominator / fraction.numerator + 1);
            
            ans.push_back(temp);
            
            fraction -= temp;
        }
        
        ans.push_back(fraction);
        
        return ans;
    }
    
    double getValue() const {
        return (double) numerator / denominator;
    }
    
    bool operator> (const Fraction &that) const {
        return getValue() > that.getValue();
    }
    
    Fraction& operator-= (const Fraction &that) {
        
        numerator = numerator * that.denominator - that.numerator * denominator;
        denominator *= that.denominator;
        
        int g = gcd(numerator, denominator);
        
        numerator /= g;
        denominator /= g;
        
        return *this;
    }
};

void solve() {
    
    auto ans = Fraction(22).getEgyptianFraction();
    
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].numerator << "/" << ans[i].denominator;
        if (i+1 != ans.size()) {
            cout << " + ";
        }
    }
    
    cout << '\n';
}

int main() {
	
	int t = 1;
	// cin >> t;
	
	while (t--) solve();
	
	return 0;
}