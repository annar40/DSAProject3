
#include <string>
#include <sstream>
#include <iostream>
#include <list>
#include <ostream>
#include <vector>
using namespace std;

class unordered_map{
  private:
    list <pair<int,string>> *buckets;
    int bucket_size;
    int total_elements;
    float max_load_factor;

    int hash(int key){
      return key % 10;
    }

public: 

unordered_map(int n){
  bucket_size = n;
  buckets = new list<pair<int,string>>[bucket_size];
  total_elements = 0;
  max_load_factor =0.75;
}

void insert(int key, string val){
  buckets[hash(key)].push_back({key,val});
  total_elements++;
  rehash();


}


void rehash(){
  if(total_elements/bucket_size <= max_load_factor){
    return;
  }
  bucket_size *= 2;
  auto new_buckets = new list<pair<int,string>>[bucket_size];
  for(int i = 0; i < bucket_size/2; i++){
    for(auto& itr: buckets[i]){
      new_buckets[hash(itr.first)].push_back(itr);
    }
  }
  delete[] buckets;
  buckets = new_buckets;
}

 vector <pair<int,string>> find(int key){
  pair<int,string> prev1;
  pair<int,string> prev2;
  vector <pair<int,string>> ans;

  int x = hash(key);
   for(auto& i : *buckets){
     if (prev1.first < key){
      prev1 = i;

     }else if (prev1.first >= key){
      ans.push_back(prev1);
      ans.push_back(prev2);
      break;
     
     } if(prev2.first < key){
      prev2 =i;
     }
     
   }
  return ans;
 }



};

int main()
{
  vector <pair<int,string>> answer;
  unordered_map map(3);
    map.insert(0,"caleb");
    map.insert(1,"anna");
    map.insert(2,"chandler");
    answer = map.find(3);
    for(int i=0; i <=answer.size()-1; i++){
      cout << answer[i].second <<endl;
    }


    
    
    
    return 0;



}