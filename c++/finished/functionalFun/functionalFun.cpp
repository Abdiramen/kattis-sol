#include<iostream>
#include<map>
#include<sstream>
#include<string>
#include<vector>

#include<iterator>
using namespace std;

vector<string> getDomain(){
  string str, ele;
  cin >> str; // throw away domain

  getline(cin, str);
  istringstream iss(str, ios_base::in);
  vector<string> vec{
    istream_iterator<string>{iss},
    istream_iterator<string>{}
  };

  return vec;
}

vector<string> getCodomain(){
  return getDomain();
}

bool isIn(const string& val, const vector<string>& vec){
  bool result = false;
  for(const auto& ele : vec){
    if(val == ele){
      result = true;
      break;
    }
  }
  return result;
}


pair<map<string, int>, map<string, int>> getMappings(const vector<string>& dom, const vector<string>& codom){
  int count;
  map <string, int> comap, domap;
  for(auto& s : dom){
    domap.insert(pair<string, int>(s, 0));
  }
  for(auto& s : codom){
    comap.insert(pair<string, int>(s, 0));
  }

  cin >> count;
  for(int i = 0; i < count; i++){
    string d, c;
    cin >> d >> c >> c;
    if(isIn(d, dom)){
      if(isIn(c, codom)){
        comap[c] += 1;
      }
      domap[d] += 1;
    }
  }
  return pair<map<string,int>,map<string,int>>(domap,comap);
}

string getSol(const pair<map<string, int>, map<string, int>>& tup){
  string result;
  bool surj = true, inj = true, bij = true, notafunc = false;
  unsigned int zeros = 0;

  for(auto& vals : tup.first){
    if(1 < vals.second) {
      notafunc = true;
    }
  }

  for(auto& vals : tup.second){
    if(0 == vals.second){
      zeros++;
      surj = false;
      bij = false;
      if(zeros == tup.second.size()){
        inj = false;
      }
    } else if(1 < vals.second){
      inj = false;
      bij = false;
    }
  }

  if(notafunc){
    result = "not a function";
  } else if(bij){
    result = "bijective";
  } else if(surj){
    result = "surjective";
  } else if(inj){
    result = "injective";
  } else {
    result = "neither injective nor surjective";
  }
  return result;
}


int main(){
  do{
    auto dom = getDomain();
    auto codom = getCodomain();
    cout << getSol(getMappings(dom, codom)) << endl;
    cin.ignore(1, '\n');
  }while(cin.peek() != EOF);
}
