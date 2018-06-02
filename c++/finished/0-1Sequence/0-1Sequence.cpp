#include<vector>
#include<iostream>
#include<cmath>

int main(){

  std::vector<char> list;
  const unsigned long MOD_NUM = 1000000007;
  unsigned long long invariant = 0; 
  unsigned long long num_zextra = 0;
  unsigned long long pow_2 = 0;
  unsigned long num_0 = 0;
  unsigned long num_Q = 0;
  unsigned long long total = 0;
  unsigned long long output = 0;

  char ele = 0;
  char current_ele = 0;


  //filling list
  std::cin.get(ele);
  while(ele!= '\n'){
    list.push_back(ele);
    std::cin.get(ele);
  }

  //counting number of inversions
  while(!list.empty()){
    current_ele = list.back();
    switch(current_ele){
        case '0':
          num_0++;
            break;

        case '?':
            pow_2>0?pow_2*=2:pow_2=1;
            total+=total+invariant + pow_2*(num_0);
            //std::cout<<pow(2,num_Q)<<std::endl;
            //std::cout<<total<<std::endl;
            invariant+=invariant + pow_2;//update invariant to K of n+1. we use num_Q - 1 since we haven't seen the next ?
            //std::cout<<invariant<<'I'<< pow_2<< 'P'<<std::endl;
            break;

        case '1':
            if(pow_2 > 0){
                total+=invariant+num_0*pow_2*2;
            }
            else{ 
                 total+=num_0;
            }
            break;
    }
    if(total > MOD_NUM){
        total = total % MOD_NUM;
        invariant = invariant % MOD_NUM;
        num_0 = num_0 % MOD_NUM;
        pow_2 = pow_2 % MOD_NUM;
        num_Q=num_Q%MOD_NUM;
    }
    list.pop_back();
  }
  //output= total%(1000000007*(pow(10,9)+7));
  std::cout<<total;
  return 0;
}
