nclude <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    int ans = (n&(-n));
	    int count = 0;
	    while (ans != 0) {
	        ans = ans >> 1;
	        count ++;
	    }
	    cout<<count<<"\n";
	}
	return 0;
}
