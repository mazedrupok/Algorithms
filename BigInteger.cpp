#include<bits/stdc++.h>

using namespace std;

typedef vector<int> Integer;
const int base = 1000*1000*1000;

void printInteger(Integer num){
	printf("%d", num.empty() ? 0 : num.back());
	for(int i = (int) num.size() - 2; i >= 0; i--)
	printf("%09d", num[i]);	
}

Integer ReadInteger(){
	string str;
	Integer temp;
	getline(cin, str);
	for(int i = (int) str.length(); i > 0; i -= 9){
		if(i < 9) temp.push_back(atoi(str.substr(0, i).c_str()));
		else temp.push_back(atoi(str.substr(i - 9, 9).c_str()));
	}
	return temp;
}

void IntegerSum(Integer a, Integer b){
	int carry = 0 ;
	for(size_t i = 0; i < max(a.size(), b.size()) || carry; i++){
		if(i == a.size()) a.push_back(0);
		a[i] += carry + (i < b.size() ? b[i] : 0);
		carry = a[i] >= base;
		if(carry) a[i] -= base;
	}
	printInteger(a);
	cout << endl;
}

void IntegerSub(Integer a, Integer b){
	int carry = 0;
	for(size_t i = 0; i < max(a.size(), b.size()) || carry; i++){
		a[i] -= carry + (i < b.size() ? b[i]: 0);
		carry = a[i] < 0;
		if(carry) a[i] += base;
	}
	while(a.size() > 1 && a.back() == 0) a.pop_back();
	printInteger(a);
	cout << endl;
}

void IntegerMulti(Integer a, Integer b){
	Integer c (a.size() + b.size());
	int carry;
	for(size_t i = 0; i < a.size(); i++){
		for(int j = 0, carry = 0; j < (int) b. size() || carry; j++) {
			long long cur = c[i + j] + a[i]*1ll*(j < (int)b.size() ? b[j] : 0) + carry;
			c[i + j] = int (cur % base);
			carry = int (cur / base);
		}
	}
	while(c.size() > 1 && c.back() == 0) c.pop_back();
	printInteger(c);
}

int main(){
	Integer num1, num2;
	num1 = ReadInteger();
	num2 = ReadInteger();
	IntegerSub(num1, num2);
	return 0;
}
