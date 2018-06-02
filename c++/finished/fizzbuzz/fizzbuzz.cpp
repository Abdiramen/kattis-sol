#include<iostream>
using namespace std;

int main(){
    int x, y, n;
    while(cin >> x >> y >> n){
        for( int i = 1; i<=n; i++){
            if(!(i%x)){
                cout<<"Fizz";
                if(!(i%y)){
                    cout<<"Buzz";
                }
                cout<<endl;
            }
            else if(!(i%y)){
                cout<<"Buzz"<<endl;
            }
            else
                cout<<i<<endl;
        }
    }
    return 0;
}
