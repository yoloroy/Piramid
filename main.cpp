#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

int len(int num) {
	int count = 0;
	while ((num%1) != 0){
		num /= 10;
		count++;
	}
	return count;
}


int main() {
	int h;  // height of a fibonacci piramid
	cout << "Enter the height of fibonacci piramid: ";
	cin >> h;
	vector<vector<int> > piramid;
	
	vector<int> piramid_line(h + 2, 0);
	for (int y; y < h; y++){
        piramid.push_back(piramid_line);
	}
	piramid[0][1] = 1;
	for (int i; i < h; i++){
		piramid[i][i] = 1;
	}
	
	for (int y = 1 ; y < h; y++){
		for (int x = 1; x < (h + 2); x++)
		    piramid[y][x] = piramid[y - 1][x - 1] + piramid[y - 1][x];
	}
	
	for (int y; y < piramid.size(); y++){
		vector<char> indent((piramid.size() - y)*4, ' ');
		for (auto i: indent){
		    cout << i;
		}
		for (auto x : piramid[y]){
			if (x != 0){
			    cout << x;
			    vector<char> indent(6 - len(x), ' ');
	 	        for (auto i: indent){
		            cout << i;
		        }
		    }
			
	    }
	    cout << endl;
	}
	
	
	
	system("pause");
	return 0;
}

