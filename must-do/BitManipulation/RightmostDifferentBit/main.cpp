#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int m,n;
	    cin>>m>>n;
	    int num = m^n;
	    if(num == 0) {
	        cout<<-1<<"\n";
	    } else {
	        num = num&(-num);
	        int count = 0;
	        while(num!=0){
	            count++;
	            num>>=1;
	        }
	        cout<<count<<"\n";
	    }
	}
	return 0;
}
