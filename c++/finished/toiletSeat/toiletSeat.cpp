#include<iostream>
using namespace std;

int main(){

  char list[1002];
  int i = 2, ans1, ans2, ans3;

  cin.getline(list, 1001);

  if(list[0]=='U'){
    ans1 = list[1]=='D' ? 2 : 0;
    ans2 = 1;
  } else {
    ans1 = 1;
    ans2 = list[1]=='U' ? 2 : 0;
  }

  ans3 = list[0] != list[1] ? 1 : 0;

  //count number of U's, D's, and alternations
  while(list[i]!='\0'){
    switch(list[i]){
      case 'U':
        ans2+=2;
        break;
      case 'D':
        ans1+=2;
        break;
    }

    if(list[i]!=list[i-1])
      ans3++;

    i++;
  }

  cout << ans1 << endl;
  cout << ans2 << endl;
  cout << ans3 << endl;

  return 0;
}
