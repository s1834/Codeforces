#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		string temp = "";
		temp += s[0];
		temp += s[1];
		int num = stoi(temp);
		temp = "";
		if(num >= 12 || num == 0) {
		    if(num == 12 && (s[3] > 0 || s[4] > 0)) {
		        cout << s + " PM"<< endl;
		        continue;
		    } else if (num == 0) {
		        temp += "12";
		        temp += s[2];
			    temp += s[3];
			    temp += s[4];
			    temp += " AM";
			    cout << temp << endl;
			    continue;
		    } else if(num - 12 < 10) {
		        temp += '0';
		    }
			temp += to_string(num - 12);
			temp += s[2];
			temp += s[3];
			temp += s[4];
			temp += " PM";
			cout << temp << endl;
		} else {
			cout << s + " AM"<< endl;
		}
	}

	return 0;
}